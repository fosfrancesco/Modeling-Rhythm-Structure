//
//  PreWTA.hpp
//  qparse
//
//  Created by Florent Jacquemard on 02/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#ifndef PreWTA_hpp
#define PreWTA_hpp

#include <stdio.h>
#include <assert.h>
#include <array>
#include <queue>
#include <map>

#include "SerialLabel.hpp"
#include "WTA.hpp"
#include "AlignedInterval.hpp"



/// tmp state structure for construction of PreWTA from a WTA (base schema)
/// casted aka state_t after construction
///
/// label (for leaves): see WTA
///
/// states (q:int, pre:int, post:int) ou label (feuille)
/// q: state of base schema
/// pre: guess number of points aligned to right of previous segment
/// post: guess number of points aligned to right of current segment
class PreState
{
public:
    
    PreState();
    
    PreState(state_t, pre_t pre=0, pre_t post=0);
    
    /// @todo TBR
    PreState(const PreState&);
    
    ~PreState();
    
    /// state of base schema
    state_t ps_state;
    
    /// guess number of points aligned to right of previous segment
    pre_t ps_pre;
    
    /// guess number of points aligned to right of current segment
    pre_t ps_post;
    
    bool operator==(const PreState& s) const;
    
    /// lexicographic comparison on hash value (array[5])
    bool operator<(const PreState& s) const;
    
    friend std::ostream& operator<<(std::ostream&, const PreState&);
    
    /// return a state value unically associated to this PreState
    state_t serialize();
    
    bool compatible(label_t label) const;
    
    /// compatible(s, al)
    /// the serialized state value s is compatible with
    /// the content of the alignment al
    /// (sub-segment of initial input corr. to an interval)
    static bool compatible_post(state_t, const AlignedInterval*);
    
private:
    size_t _hash[3];
    
    static int const _hash_len = 3;
    
    void rehash();
};


/// extension of WTA where states are associated pre and post values.
///
/// - post is a number of points
/// - pre is the post of the previous sibling
///
/// @warning deprecated
///
/// extension of a given schema (WTA) with pre and post information in states:
/// during a computation, the current state is associated to an input segment,
/// - pre value is an abstraction of the number of points in the previous segment
///   aligned to the left of the current segment.
/// - post value is an abstraction of the number of points aligned to the right
///   of the current segment.
/// cf. Label::abstract for the abstraction domain
///
/// top-down construction of the transition table, principle:
/// - pre propagate from a node to its leftmost child
/// - post propagte from a node to it rightmost child
/// - for 2 states s1, s2 at successive siblings, it holds that s1.post = s2.pre
///
/// given q state of schema, k <= max{ n | q -> q1,...,qn | w transition of schema}
/// mright(q, k) = # point d’input dans la derniere 2k partie de p
///
/// we start with states <q0, pre0, post0> in a queue
/// q0 = initial state of the schema
/// pre0 arbitrary (input of problem = previous tree). ctypically 0.
/// post0 in [0, MAX_GRACE]
///
/// for all state <q, pre, post> taken from the queue
///
/// for all final transition q -> s | w of the schema
/// we add the transition
/// <q, pre, post> -> <s, pre, post> | w
/// such that the value of s abstracts the possible values of pre + lalign(path)
/// for any path.
///
/// for all inner transition q -> (q1,...,qk) | w  in schema (k > 1)
/// for all post in [0..MAX_GRACE]
/// we add the transitions
/// <q, pre, post> -> (<q1, pre1, post1>,..., <qk, prek, postk>) | w
/// such that
/// - postk = post
/// - pre1 = pre
/// - for all 1 <= i < k, posti = prei+1
/// we also add the states <q1, pre1, post1>,..., <qk, prek, postk> in the queue
///
class PreWTA: public WTA
{
public:
    
    /// construction from WTA (base schema)
//    PreWTA(const WTA&, pre_t pre=0);
      PreWTA(const WTA&);
    
    virtual bool hasType(std::string code) const
    { return (code == "PreWTA"); }
    
    /// access to original components of new PreWTA states
    static pre_t pre(state_t);
    static pre_t post(state_t);
    static state_t state(state_t);
    
    /// initial(pre, port) returns state representing the whole segment,
    /// with pre points of the previous segment aligned to the left
    /// and post points of the current segment aligned to the right
    /// (i.e. to the left of the next segment)
    virtual state_t initial(pre_t pre=0, pre_t post=0) const;
    
    friend std::ostream& operator<<(std::ostream&, const PreWTA&);
    
private:
    // Global variables for the PreWTA construction
    
    const WTA& _schema;
    
    /// map of PreState into their index in PreWTA
    /// tmp (only for constructor)
    ///unordered_map<cs_key, state_t, container_hasher> _statemap;
    std::map<PreState, state_t> _statemap;
        
    std::vector<vector<state_t>> _initials;
    
    /// addPreState(ps)
    /// returns the PreWTA state s associated to the PreState ps
    /// if there exists one.
    /// otherwise:
    ///     a new PreWTA state s is created,
    ///     s is associated to cs,
    ///     s is added to the table
    ///     the PreWTA transitions with head s are computed
    ///     and added to the table
    ///     s is returned
    /// moreover, the state is added to the initial state set of the PreWTA
    /// if the state component of ps is initial.
    state_t addPreState(const PreState&);
  
    // use PreState::compatible
//    bool compatible(label_t label, const PreState& ps);
    
};



#endif /* PreWTA_hpp */


/// @}
