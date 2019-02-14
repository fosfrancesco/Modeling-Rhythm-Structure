//
//  Rune.hpp
//  squant
//
//  Created by Florent Jacquemard on 01/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{



#ifndef Rune_hpp
#define Rune_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "State.hpp"
#include "Transition.hpp"
#include "Weight.hpp"
//#include "WTA.hpp"
#include "DurationList.hpp"
//#include "Label.hpp"
#include "Environment.hpp"

//class Environment;

template<class P> class Run;

template<class P> using RunCompare =
std::function<bool(const Run<P>*, const Run<P>*)>;

/// a run is a compact representation of parse trees
/// as a tuple of pointers to subruns.
///
/// a run stores
/// - a list of children represented by pointers (template type)
///   compatible with a transition
/// - a weight (to evaluate)
/// - a temporary weight value (initialy the weight of the parent transition)
/// - a list of relative durations.
///
/// a run can be of 3 kinds:
/// - null run:
///   - unknown current weight,
///   - unknown tmp weight,
///   - no children,
///   - empty duration list.
/// - terminal (leaf) run
///   - created from terminal (length 1) parent transition:
///   - current weight unknown or current weight known (evaluated),
///   - tmp weight known,
///   - 1 child : fake pointer containing as state the transition label
///     (and rank 0 if the pointer class has a rank)
///   - duration list with single continuation or single event preceeded graces notes
/// - inner run
///   - created from inner (length > 1) parent transition:
///   - current weight unknown or current weight known (evaluated)
///   - tmpt weight known
///   - nb children = length parent transition
///   - duration list == empty (unknown) or not (evaluated).
///
/// @todo suppr. null runs
// P = pointer class
template<class P>
class Run
{
public:
    // optimisation flags
    
    /// current weight.
    /// totally evaluated when evaluated() = true.
    Weight weight;
    
    /// list of relative durations.
    DurationList duration;
    
    /// construct a null run (special)
    Run();
    
    /// Run with empty body and given weight.
    /// the run is marked as meta.
    /// the first PartialorUpdate child is 0.
    /// @param w must not be unknown weight .
    /// @warning the body must be completed with insert().
    Run(Weight w);
    
    /// WTA Run with head the given pointer.
    /// the given pointer must be a wta ptr.
    /// the body is build according to the transition t.
    /// - terminal run if t is terminal,
    ///   - the given ptr must be compatible with the transition's label.
    ///   - singleton children list with fake ptr containing only label.
    ///   - the run is complete.
    ///   - the weight of run is set to a combination of
    ///     transition's weight and a distance returned by terminalWeight.
    /// - inner run if t is inner (using states in the body of t)
    ///   - children list contains pointers of type P
    ///     to the 1-best runs for the given transition
    ///     for transition (s1,...,sn), the 1-best is (<s1,1>,...,<sn,1>).
    ///   - the ptrs in body are registered.
    ///   - the run is partial.
    ///   - the weight of run is set to innerWeight
    ///     and must be mult. by weights of subruns.
    /// - null run when it is not possible to construct one of the children.
    Run(Environment*, const P&, const Transition&);
    
    // the weight is set to given weight,
    // and must be mult. by weights of subruns.
    // the duration list is empty.
    // null run when it is not possible to construct one of the children.
    
    // @todo TBR replaced by Parser.addRuns(P)
    // inner (meta) run. depending on the direction:
    //
    // if direction is true:
    // top-down inner run with head the given pointer, and with 2 children :
    // - the first children is built with the given state (initial wta state).
    //   its real duration (double), if relevant, is computed by P.
    // - the second children is meta ptr (sub-meta of the given ptr)
    //
    // if direction is false:
    // bottom-up inner run with new head and 2 children :
    // - the first children is a meta ptr (super-meta of the given ptr)
    //   its real duration (double), if relevant, is computed by P.
    // - the second children is built with the given state (initial wta state).
    //
    // the given pointer must be a meta pointer (pointer with meta state).
    // the given state must be a wta state.
    // run is partial.
    // the duration list is empty.
    // null run when it is not possible to construct one of the children.
    //Run(Environment*, const P&, state_t, const Weight&, bool direction=true);

    /// copy.
    Run(const Run<P>&);
    
    /// copy r and increase rank of pointer number i.
    /// @param r must be inner.
    /// @param i (child) must have rank, index i must be between 0 and arity of r - 1.
    /// the run is reset (partial):
    /// @warning the weight and duration list of the run must be recomputed
    /// (the weight is reset to the weight of creator transition).
    Run(const Run<P>& r, size_t i);
    
    /// copy/update constructor
    /// @param r must be partial.
    /// @param p must be complete.
    /// copy r and replace first partialorUpdate child by p,
    Run(const Run<P>& r, const P& p);
    
    ~Run();
    
    Run<P>& operator= (const Run<P>&);
    
    bool operator==(const Run<P>& s) const;
    
    /// this run is null - constructed with Run().
    bool null() const;
    
    /// this run is terminal (leaf).
    bool terminal() const;
    
    /// this run is inner.
    bool inner() const;
    
    /// meta run:
    /// inner, binary and second child is a meta state.
    bool meta() const;

    /// all ptr in children list are complete.
    bool allcomplete() const;
    
    /// all ptr in children list are complete
    /// and the weight of this run has been evaluated.
    bool complete() const;
    
    inline bool partial() const { return (! complete()); }
    
    // run with unevaluated weight (or partialy evaluated weight)
    //inline bool unknown() const { return partial(); }
    
    /// this run must be terminal
    label_t label() const;
    
    /// return the number of children of this Run:
    /// = 0 in the case of terminal run
    /// > 1 for inner run
    /// = 2 for meta run
    size_t arity() const;
    
    bool filter();
    
    /// return the ith subrun of this run.
    /// @param i index of subrun
    /// @warning the number of children must be at least i+1
    inline const P& operator[](size_t i) const
    {
        assert (i < _children.size());
        return _children[i];
    }
    
    /// first children.
    /// @warning this run must be inner with arity > 0
    const P& first() const;
    
    /// last children.
    /// @warning this run must be inner with arity > 0
    const P& last() const;
    
    /// index of first children which is either either
    /// - partial, or
    /// - whose weight did not contribute to run's weight
    /// or arity() if there is no such children.
    ///
    /// the index of first children is 0,
    /// the index of last children is arity - 1.
    /// @warning complete() must not hold (otherwise there is no such children).
    /// @warning this run must be inner  with arity > 0.
    const P& firstPartialorUpdate() const;
    
    /// append the given ptr at the end of body.
    /// @warning the run must be marked as meta.
    void insert(const P&);
    
    /// update the weight and duration lists of this run with given weight and duration list.
    /// @param w the given weight, must not be zero
    /// it must be the weight of best run for the first partialorupdate children (this cannot be checked!).
    /// @param dl must be the duration list of best run for the first partialorupdate children
    /// (this cannot be checked!).
    /// @warning this run must not be complete.
    /// @warning the first partialorupdate children must exist and be complete.
    ///
    /// the index to first partialorupdate children is incremented.
    void update(const Weight& w,
                const DurationList& dl=DurationList());
    
    
    friend std::ostream& operator<<(std::ostream& o, const Run<P>& r)
    {
        if (r.null())
        {
            o << "NULL_RUN";
        }
        else if (r.terminal())
        {
            assert (r._children.size() == 1);
            o << r._children[0] << " (terminal) ";
            o << "first-partial=" << r._first_partialortoupdate;
            o << " w=" << r.weight;
        }
        else if (r.inner())
        {
            o << "( ";
            for(typename std::vector<P>::const_iterator i = r._children.begin();
                i != r._children.end();
                ++i)
            {
                o << *i << " ";
            }
            
            o << ") ";
            o << "first-partial=" << r._first_partialortoupdate;
            o << " w=" << r.weight;
        }
        
        return o;
    }
    
private:
    typename std::vector<P> _children;
    
    /// transition used to create this run.
    /// null for meta runs.
    /// saved for resetting the computation of weight in inner Run.
    const Transition* _transition;
    
    /// index of first pointer in children list, either
    /// - partial, or
    /// - whose weight did not contribute to run's weight
    /// for inner run only.
    /// = arity() = size_of _children when this run is complete.
    size_t _first_partialortoupdate;

    /// meta flag.
    /// the run was build manually with Run(w) and insert.
    bool _meta;
    
    // at(i) returns the ith children of this run
    // P* at(size_t) const;
    
    void _init_duration_list(label_t);
    
    // index of the first sub-run pointer to evaluate
    // evaluate = complete partial ptr and and compute weight of best sub-run
    // size of _children if all children have been evaluated.
    // in the latter case, the weight of run is known.
    //size_t _evaluate();
    
    /// reset weight to weight of creator transition,
    /// reset duration list to 0,
    /// reset firstPartialorUpdate to first child.
    /// @warning this run must be inner.
    /// @warning run is partial after call.
    void reset();
    
};


/// one ordering for k-best to select the min weight Run
/// where partial run is considered to be the lowest.
template<class P>
RunCompare<P> weightMin =
[](const Run<P>* lhs, const Run<P>* rhs)
{
    assert (lhs);
    assert (rhs);
    if (rhs->partial())
    {
        return false;
    }
    else
    {
        if (lhs->partial()) return true;
        return (lhs->weight > rhs->weight);
    }
};


/// one ordering for k-best to select the max weight run
/// where partial run is considered to be the highest
template<class P>
RunCompare<P> weightMax =
[](const Run<P>* lhs, const Run<P>* rhs)
{
    assert (lhs);
    assert (rhs);
    if (lhs->partial())
    {
        return false;
        // if rhs == 0 then lhs == rhs
        // if rhs > 0 then lhs > rhs;
    }
    else
    {
        if (rhs->partial()) return true;
        else return (lhs->weight < rhs->weight);
    }
};


// separated definition of template class
#include "Rune.tpp"


#endif /* Rune_hpp */


/// @}
