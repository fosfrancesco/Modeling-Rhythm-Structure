//
//  WTA.hpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @defgroup schemata Schemata module
///
/// The `schemata` module contains classes of weighted tree automata
/// used for parsing.

/// @addtogroup schemata
/// @{


#ifndef WTA_hpp
#define WTA_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h> 

#include "init.hpp"
#include "trace.hpp"
#include "Label.hpp"
#include "State.hpp"
#include "Transition.hpp"
#include "SerialLabel.hpp"
#include "Weight.hpp"
#include "RT.hpp"


class WTA;

typedef std::list<Transition>::iterator TransitionList_iterator;
typedef std::list<Transition>::const_iterator TransitionList_const_iterator;

class TransitionList
{
    
    friend class WTA;
    
public:
    TransitionList():_cpt_size(0) {}
    
    ~TransitionList();

    /// @brief zero transition
    /// @return an empty transition
    bool empty() const;
    
    /// number of transitions.
    /// @return the number of transitions in this WTA
    size_t size() const;
    
    
    /// total size of transition table
    /// (sum of transition sizes. = number of occurences of states)
    size_t fullsize() const { return _cpt_size; }
    
    void add(const Transition&);

    /// remove the transition pointed by iterator in this transition list
    /// @return an iterator to the element that follows the last element removed
    /// or end if the last element was removed.
    TransitionList_iterator remove(TransitionList_iterator);

    /// remove all transitions of length > 1 in this transition list
    /// containing the given state in their body.
    /// do not remove length 1 transitions to terminal symbols
    void remove(state_t);
    
    void clear();

    /// constant iterator pointing to the first transition in this transition list.
    TransitionList_const_iterator cbegin() const { return _table.cbegin(); }

    /// constant iterator pointing to the end of this transition list.
    TransitionList_const_iterator cend() const { return _table.cend(); }
    
    /// iterator pointing to the first transition in this transition list.
    TransitionList_iterator begin() { return _table.begin(); }

    /// iterator pointing to the end of this transition list.
    TransitionList_iterator end() { return _table.end(); }
    
private:

    /// full size (number of occurences of states).
    size_t _cpt_size;
    
    /// transition list.
    std::list<Transition> _table;

    /// container WTA.
    WTA* _parent;
    
    ///set of all states occuring in transitions of list (in head or body).
    std::set<state_t> allStates() const;
};








/// class of schemas = weighted tree automata = weighted CFG.
///
/// state (and non-terminals): int
///
/// transition table = map
/// state -> (transition = state list), weight
///   state: head state
///   state list: see Transition.hpp
///               body states if length > 1
///               label if length = 1
///
/// in other terms transition rules have one of the forms
/// > s -> (s1,...,sk) w where k > 1, s, s1, ..., sk are states and w weight
/// > s -> (s1) w where s1 is an leaf label = int encoding
///
/// leaf label (terminals):
/// number of note + grace notes at (left of) current node
/// > 0 = continuation
/// > 1 = 1 note | rest      (au + 1 note)
/// > 2 = 1 grace notes + 1 note
/// > 3 = 2 grace notes + 1 note
/// >etc
/// @see Label for the functions managing these labels
//
/// transition table:
/// > head state -> vector of (state vector, weight)
///
/// weights are concrete weight values embedded in a Weight envelop
/// we consider 3 kinds of weights for WTA serialized in file:
/// - counting model: weight = # of subresettrees in corpus parsed by rule
///   implemented as FloatWeight
/// - penalty model: weight = penalities to sum
///   implemented as TropicalWeight
///   e.g. inverse of counting model (normalized?)
/// - probabilistic model, fulfilling stochastic condition
///   (sum of weight of transition from a state = 1)
///   implemented as ViterbiWeight
///   e.g. (# of subtrees in corpus parsed by rule) / (# of subtrees matching lhs state)
class WTA
{
    friend class TransitionList;

public:
    ///nullary constructor for cython
    WTA();

    /// empty automaton
    WTA(Weight seed, pre_t pre=0, pre_t post=0);
    
    ~WTA();
    
    virtual bool hasType(std::string code) const
    { return (code == "WTA"); }
    
    /// number of states
    size_t size() const;
    
    bool empty() const;
    
    /// the state is present in the automaton
    bool isRegistered(state_t) const;
    
    /// the state is an initial state
    /// @todo TBR
    bool isInitial(state_t) const;
    
    /// initial(pre, post)
    /// pre and post are use for quantification and ignored in this version
    /// (useless for schemas)
    virtual state_t initial(pre_t pre=0, pre_t post=0) const { return _initial; }
    
    size_t resolution() const;
    
    /// add(s, i) register state s
    /// if s was already registered, return a reference to its transition list.
    /// otherwise, create state s with an empty transition list and returns a reference to it.
    /// moreover s is set as initial if i = true.
    /// @todo suppr. flag initial
    TransitionList& add(state_t, bool initial=false);
    
    /// add(s, t) add a transition with head s and with body/weight described in t
    /// if s was not registered, it is registered
    /// the transition t is added to the transition list of s
    /// and a reference to this transition list is returned
    /// moreover s is set as initial if i = true.
    /// @todo suppr. flag initial
    TransitionList& add(state_t, const Transition&, bool initial=false);
    
    /// remove the entry for given state s in the table of the table
    /// i.e. all transitions targeted to s,
    /// and all the transitions with s in their body.
    /// if s was in the initial set, it is also removed from this set.
    /// s must be registered.
    void remove(state_t);
    
    /// cbegin(s) returns an iterator pointing to the first transition with head state s.
    /// s must be registered.
    /// not for modifying transition list of s. use add(...) methods for this.
    TransitionList_const_iterator cbegin(state_t) const;

    /// cend(s) returns an iterator pointing to the past-the-end transition with head state s.
    /// s must be registered.
    /// not for modifying transition list of s. use add(...) methods for this.
    TransitionList_const_iterator cend(state_t) const;
    
    /// oftarget(s) return the number of transitions of head state s.
    /// s must be registered.
    size_t oftarget(state_t) const;

    /// the WTA has no empty states
    bool isClean() const;
    
    /// returns the set of all non-inhabited (zero weight) states in wta
    std::set<state_t> emptyStates() const;
    
    /// remove states not inhabited and transitions containing these states
    void clean();
    
    /// for all state q,
    /// for all transition tr to q (in the transition list TL(q) of q).
    /// recompute weights to get a probabilistic WTA.
    ///
    /// with arg = 0, we assume the current WTA is a penalty model.
    /// the probability is then obtained by dividing (Weight.scalar)
    /// the inverse of the norm (Weight.norm) of the weight of the tr
    /// by the sum of inverses of norms of transitions in TL(q).
    ///
    /// with arg = 1, we assume the current WTA is a counting model.
    /// the probability is then obtained by dividing (Weight.scalar)
    /// the norm (Weight.norm) of the weight of the tr
    /// by the sum of norms of transitions in TL(q).
    void normalize(unsigned int flag = 0);
    
    // cast and recompute all weights values in WTA transitions
    // from one Weight model to another.
    
    /// cast weights in all transitions.
    ///
    /// @warning this WTA must have Weight Type "FloatWeight".
    /// this WTA is casted into Weight Type "ViterbiWeight"
    /// divide by sum for target state
    void CountingtoStochastic();

    /// cast weights in all transitions.
    ///
    /// @warning this WTA must have Weight Type "TropicalWeight".
    /// this WTA is casted into Weight Type "FloatWeight"
    /// inverse
    void PenaltytoCounting();

    /// cast weights in all transitions.
    ///
    /// @warning this WTA must have Weight Type "ViterbiWeight".
    /// this WTA is casted into Weight Type "TropicalWeight"
    /// -ln
    void StochastictoPenalty();
    
    /// cast weights in all transitions.
    ///
    /// @warning this WTA must have Weight Type "FloatWeight".
    /// this WTA is casted into Weight Type "TropicalWeight"
    /// composition of CountingtoStochastic and StochastictoPenalty
    void CountingtoPenalty();
    
    /// abstract the leaf label values
    /// in domain [0..MAX_GRACE]
    /// every value > MAX_GRACE is casted to MAX_GRACE
    /// the weights are summed accordingly
    ///
    /// leaf labels in domain of Label (not SerialLabel).
    /// @todo TBR unused
    void abstract(bool flag = false);
    
    /// number of states
    size_t countStates() const;
    
    /// number of transition
    size_t countTransitions() const;
    
    /// number of symbols (state occurences)
    size_t countAll() const;
    
    /// return wether the weights in transition have the type of the code
    /// (code of the letter weight if there is one or "UNKNOWN" otherwise).
    bool hasWeightType(std::string code) const;

    /// return the 0 value in the weight domain in this WTA
    virtual Weight weight_zero() const;
    
    /// return the 1 value in the weight domain in this WTA
    virtual Weight weight_one() const;
    
    /// evaluate the weight of the tree t for WTA in initial state
    virtual Weight eval(const RhythmTree& t) const;
    
    // evaluate the weight of the tree t for WTA in given state
    virtual Weight eval(const RhythmTree& t, state_t s) const;
    
    inline pre_t max_pre() const { return _max_pre; }
    
    inline pre_t max_post() const { return _max_post; }
    
    /// set of initial states
    /// @todo SUPPR
    std::set<state_t> initials;
        
    /// write table content to output stream
    friend std::ostream& operator<<(std::ostream&, const WTA&);
    
    /// print sizes to output stream
    void print(std::ostream&) const;

protected:

    /// transition table
    std::map<state_t, TransitionList> _table;

    state_t _initial;
    
    /// number of transitions
    size_t _cpt_tr;
    
    /// full size (number of occurences of states)
    size_t _cpt_size;
    
    /// used only in descendant classes
    pre_t _max_pre;
    pre_t _max_post;
    
    ///  arbitrary (polymorphic) weight value.
    /// for generation of weights in same domain with get_zero, get_one
    Weight _seed;
    
    /// step(s) returns the set of states reachable in one transition step
    /// by this WTA from the given state set s.
    /// all the states in the set s must be registered.
    std::set<state_t> step(const std::set<state_t>&);
   
    /// returns the set of all states occuring in wta (in head or body)
    std::set<state_t> allStates() const;
    
private:
    /// counter for creating transition ids
    size_t _next_id;
};





/// marking of states of a WTA
/// with informations on the depth of their occurences
/// initialized with a WTA, can be interrogated afterwards
class DepthMarking
{
public:
    DepthMarking(const WTA&);
    
    //    ~DepthMarking();
    
    /// return depth mark if given state marked
    /// return -1 otherwise
    int depth(state_t) const;

    /// return true if the given state can occur at multiple depths
    /// return false otherwise or if state not marked
    bool multiple(state_t) const;
    
    /// mark state using given depth and return new mark value
    /// can be the given depth or a greater depth with which the state
    /// had been already marked.
    int mark(state_t, int);
    
private:
    /// marks:
    /// -1 : unknown
    /// 0.. : depth
    std::map<state_t, int> _marks;
    
    /// whether the state can occur at multiuple depths
    std::map<state_t, bool> _multi;
    
    void mark_rec(state_t, int, const WTA&);
};



#endif /* WTA_hpp */


/// @}
