//
//  Transition.hpp
//  qparse
//
//  Created by Florent Jacquemard on 25/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#ifndef Transition_hpp
#define Transition_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <set>
#include <string>
#include <iostream>

#include "init.hpp"
#include "trace.hpp"
#include "Label.hpp"
#include "State.hpp"
#include "SerialLabel.hpp"
#include "Weight.hpp"



// poor man's definition of iterators
typedef std::vector<state_t>::iterator Transition_iterator;
typedef std::vector<state_t>::const_iterator Transition_const_iterator;


/// @brief a Transition is defined by a sequence of antecedent states (body)
/// the weight must be not null
/// (null weight means a missing transition).
///
/// a transition can be of two kinds:
/// - inner transition:
///   the body has length > 1
///   the arity is the length of the body
/// - terminal (leaf) transition:
///   the body has length 1 and contains a leaf label
///   the arity is zero
///
/// leaf label (terminal transitions):
/// number of note + grace notes at (left of) current node
///  0 = continuation
///  1 = 1 note | rest      (au + 1 note)
///  2 = 1 grace notes + 1 note
///  3 = 2 grace notes + 1 note
/// etc
/// @see Label for the functions managing these labels
class Transition
{
public:
    
    /// transition with unknown weight and empty body.
    Transition();
    
    // to call by either
    // Transition(new XXXWeight()) where XXXWeight is class derived of Weight
    // Transition(Weight()) for UNKNOWN Weight
    
    /// Transition(w) creates a transition
    /// with weight a copy of w and empty body.
    /// @warning the letter weight in the envelop w is cloned
    Transition(const Weight&);
    
    /// Transition(lw) creates a transition
    /// with weight a wrapper of the letter lw (must be non null)
    Transition(LetterWeight*);
    
    /// Transition(v, w) creates a transition
    /// with weight a copy of w
    /// and body a copy of the vector v.
    /// @warning the letter weight in the envelop w is cloned.
    Transition(std::vector<state_t>, const Weight&);
    
    /// Transition(v, lw) creates a transition
    /// with weight a wrapper of the letter lw (must be non null)
    /// and body a copy of the vector v.
    Transition(std::vector<state_t>, LetterWeight*);
    
    /// Transition(s, w) creates a transition
    /// with weight a copy of w
    /// and body (of size 1) the singleton (s) (terminal symbol).
    /// @warning the letter weight in the envelop w is cloned.
    Transition(state_t, const Weight&);
    
    /// Transition(s, lw) creates a transition
    /// with weight a wrapper of the letter lw (must be non null)
    /// and body (of size 1) the singleton (s) (terminal symbol).
    Transition(state_t, LetterWeight*);
    
    //  @todo lesquels sont utilisés?
    
    ~Transition();
    
    bool inner() const;
    
    bool terminal() const;
    
    inline size_t id() const { return _id; }
    
    /// @warning this transition must be terminal
    label_t label() const;
    
    inline Weight weight() const { return _weight; }
    inline void setWeight(const Weight& w) { _weight = w; };  // copy
    
    /// modify weight of transition.
    void scalar(double);
    void invert();
    
    /// at(i) returns the ith state in the body.
    /// @param i must be an index of the body.
    state_t at(size_t i) const;
    
    /// add given state at the end of the body of this transition.
    void push(state_t);
    
    /// size of body.
    size_t size() const;
    
    size_t arity() const;
    
    /// constant iterator pointing to the first state in the body of the transition.
    Transition_const_iterator cbegin() const { return _body.cbegin(); }
    
    /// constant iterator pointing to the end of the body of the transition.
    Transition_const_iterator cend() const { return _body.cend(); }
    
    /// whether the given state belongs to the body of this transition.
    bool member(state_t) const;
    
    /// every state of the body is in the given set.
    bool allin(const std::set<state_t>&) const;
    
    /// no state of the body is in the given set.
    bool nonein(const std::set<state_t>&) const;
    
    // write content of body and weight to output stream
    //void dump(ostream&);
    
    /// write content of body and weight to output stream.
    friend std::ostream& operator<<(std::ostream&, const Transition&);
    
private:
    std::vector<state_t> _body;
    Weight _weight;

    /// the id of transition is rceated automatically.
    /// it reflects the order of creation.
    size_t _id;
    
    /// counter for the creation of transition's ids.
    static size_t _cpt;
};



#endif /* Transition_hpp */


/// @}
