//
//  ComboWTA.hpp
//  qparse
//
//  Created by Florent Jacquemard on 11/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{



#ifndef ComboWTA_hpp
#define ComboWTA_hpp

#include <stdio.h>
#include <assert.h>
#include <array>
#include <queue>
#include <map>

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"
#include "PerformanceModel.hpp"
#include "Distance.hpp"
#include "Label.hpp"

//#include "Alignment.hpp"
//#include "AlignmentTree.hpp"



/// tmp state structure for construction of ComboWTA
/// from a WTA (base schema) and an input segment
/// casted into state_t after construction
///
/// label (for leaves): see WTA
/// = continuation or number of note + grace notes at left of the current path
///
/// states (q:int, p:Path, rp:int list, rr:int list) ou label (feuille)
/// q: state of base schema
/// p: current path (interval of points in input segment)
/// rp: guess number of points aligned to right of previous segment
/// rr: guess number of points aligned to right of current segment
class ComboState
{
public:

    ComboState(const InputSegment* s, IntervalHeap*);

    ComboState(state_t, IntervalTree*, pre_t rp=0, pre_t rr=0);

    /// @todo TBR
    ComboState(const ComboState&, pre_t rp=0, pre_t rr=0);

    ~ComboState();

    /// state of base schema.
    state_t cs_state;

    /// current augmented path (interval of points + alignment of input segment)
    /// share: in addComboState many ComboState constructed with the same cs_path.
    IntervalTree* cs_path;

    /// guess number of points aligned to right of previous segment.
    pre_t cs_pre;
    
    /// guess number of points aligned to right of current segment.
    pre_t cs_post;
    
    // cs_key const key();
    
    bool compatible(label_t label) const;

    bool operator==(const ComboState& s) const;

    /// lexicographic comparison on hash value (array[5])
    bool operator<(const ComboState& s) const;

    friend std::ostream& operator<<(std::ostream&, const ComboState&);


private:
//    cs_key _hash;
//    size_t _hash[5];
//    static int const _hash_len = 5;
//    void rehash();
};


// hash function for using as key in a unordered map
struct ComboStateHasher
{
    std::size_t operator()(const ComboState& cs) const
    {
        using std::size_t;
        using std::hash;
        
        /// @see constant.h
        size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<state_t>()(cs.cs_state);
        h = h * HASH_FACTOR + hash<double>()(cs.cs_path->rbegin);
        h = h * HASH_FACTOR + hash<double>()(cs.cs_path->rduration());
        h = h * HASH_FACTOR + hash<Rational>()(cs.cs_path->mbegin);
        h = h * HASH_FACTOR + hash<Rational>()(cs.cs_path->mduration());
        h = h * HASH_FACTOR + hash<pre_t>()(cs.cs_pre);
        h = h * HASH_FACTOR + hash<pre_t>()(cs.cs_post);
        return h;
    }
};

typedef std::unordered_map<ComboState, state_t, ComboStateHasher> Combomap;

/// WTA combo:
/// A special kind of WTA for quantization
/// constructed from
/// - a given WTA (base schema)
/// - a given input segment (Alignment)
//
/// the ComboWTA combines weights defined by the WTA schema
/// (absolute measure of quality of rhythm)
/// and a weight related to the distance of a rhythm to the given input segment.
///
/// not serializable
///
/// @warning deprecatred
///
/// table of transitions
/// top-down construction, given input and schema
///
/// principle:
/// - rp is propagated from father to leftmost child
/// - rr is propagated from father to rightmost child
/// - for every 2 states, s2 sibling and successive, s1.rr = s2.rp
///
/// given q state of schema, p path, k <= max{ n | q -> q1,...,qn | w transition of schema}
/// mright(q, p, k) = # point d’input dans la derniere 2k partie de p
///
// on commence avec les états (q0, p0, rp0, rr0) (en file d’attente)
// q0 = état initial du schema
// p0 = [0,...,RES-1]
// rp0 arbitraire (donnée du problème = arbre précédent). typiquement 0.
// rr0 in [0, mright(q, p, min{ n > 1 | q0 → q1,…,qn | w transition of schema} )
//
//        pour tout état (q, p, rp, rr)  sorti de la file d’attente
//        pour toute transition (q,q1,…,qk,w) du schema
//
//        si k=1 i.e. q1 est un label  (feuille)
//        tel que
//        - q1 = rp + lalign(p)
//        - rr = ralign(p)
//        alors on ajoute la transition
//        (q, p, rp, rr) -> q1 | weight(w, dist(input,p))
//
//        si k > 1  (inner node)
//        et rr in [0..mright(q, p, k)]
//        on ajoute les transitions
//        (q, p, rp, rr) -> (q1, p1, rp1, rr1),..., (qn, pk, rpk, rrk) | weight(w, 0)
//        tels que
//        - p1,...,pk forme une k-partition de p (qui doit être divisible par k)
//        - rrk = rr
//        - rp1 = rp
//        - pour tout 1 ≤ i < k, rri = rpi+1
//
//        on ajoute les états (q1, p1, rp1, rr1),..., (qn, pk, rpk, rrk) en file d’attente
//
//        REM: avec la distance à 0, on fait simplement la somme des distances des children
//
//  pour un interval (path) p et un input,
//        lalign(p) = # de points de input alignés à gauche de p
//        ralign(p) = # de points de input alignés à droite de p
//  évalués par des bitset operations avec des mask ?
//  (avec ll = lalign(p) et rr = ralign(p))
class ComboWTA: public WTA
{
public:

    /// construction from input segment and WTA (base schema)
    /// with given max pre value
    /// and bloc number (in input segment, for alignement).
    ComboWTA(const InputSegment*, size_t bloc,
             const WTA&, pre_t pre=0);
    
    virtual bool hasType(std::string code) const
    { return (code == "ComboWTA"); }


    /// state representing the whole segment.
    /// @param pre points of the previous segment aligned to the left
    /// @param post points of the current segment aligned to the right
    /// (i.e. to the left of the next segment).
    state_t initial(pre_t pre=0, pre_t post=0) const;

private:
    // Global variables for the ComboWTA construction

    const WTA& _schema;
    
    const InputSegment* segment;
    IntervalHeap* iheap;

    /// counter for new ComboWTA states
    state_t _cpt;

    // map of ComboState into their index in ComboWTA
    // tmp (only for constructor)
    //unordered_map<cs_key, state_t, container_hasher> _statemap;

    ///map<ComboState, state_t> _statemap;
    Combomap _statemap;
    
    /// tree of Alignments (Path with info on alignment to input segment)
    /// organized hierarchically by sub-alignments
    /// the ComboStates use the pointers stored in this tree
    IntervalTree* _tree;
    std::vector<std::vector<state_t>> _initials;


    // addComboState(cs, flag)
    /// returns the ComboWTA state s associated to the ComboState cs
    /// if there exists one.
    /// otherwise:
    /// -   a new ComboWTA state s is created,
    /// -   s is associated to cs,
    /// -   s is added to the table
    /// -   the ComboWTA transitions with head s are computed
    ///     and added to the table
    /// -   s is returned
    /// @param cs given ComboState
    /// @param initial flag: the state constructed
    /// is added to the initial state set of the ComboWTA
    /// if initial=true

    state_t addComboState(const ComboState& cs, bool initial=false);
  
    // use ComboState::compatible or static Label::compatible
//    bool compatible(label_t label, const ComboState& cs);
    
};


#endif /* ComboWTA_hpp */


/// @}
