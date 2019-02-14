//
//  Ptr.hpp
//  squant
//
//  Created by Florent Jacquemard on 19/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef Ptr_hpp
#define Ptr_hpp

#define PTR_LPAR '('
#define PTR_RPAR ')'

#include <stdio.h>
#include <assert.h>

#include "Weight.hpp"
//#include "State.hpp"
#include "Transition.hpp"
#include "Environment.hpp"


/// abstract class
/// defining a signature for a class of pointer to best runs.
///
///
/// ####constructors
///
/// Every concrete subclass P (descendant)
/// must implement the following generic
/// constructors and class-specific operators.
/// they are called by the templates Table and Run.
/// Some use the encapsulator Environment.
///
/// @code
/// P()
/// @endcode
/// dummy ptr (unique - can not be produced by other constructors).
///
/// @code
/// P(label_t s)
/// @endcode
/// fake ptr containing only a label symbol
/// to act as (singleton) body of a terminal runs.
/// the label symbol is concrete (see Label.hpp).
/// also used for P(state_t) -> confusion types state_t & label_t
///
/// @code
/// P(Environment* env, const &P p, size_t a, size_t i, state_t s)
/// @endcode
/// sub-pointer or instance as leaf
/// s must be a wta state (e.g. initial state of wta)
/// there are 2 cases according to a:
/// 1. if a = 0 :
///    construct a copy of p instanciated as a leaf with label s.
///    i must be 0,
///    p must be partial
///    p must be compatible with s (s = leaf symbol in this case).
/// 2. if a > 0
///    i must be in [0..a]
///    p must be divisible
///    p can have a meta state (meta run with a=2) or a wta state
///    with i=0, construct the head of a run
///    (in general a copy of p but not always)
///    with 0 < i <= a, construct a pointer for the ith children of a run.
///    the details and specific pre-conditions are described in every class P.
///
/// @code
/// P(const &P p)
/// @endcode
/// copy
///
/// @code
/// P(const &P p, const &P p0, const &P p1)
/// @endcode
/// instance as parent
/// p must be partial
/// p0 must be complete
/// p1 must be complete
/// Construct a copy of p instanciated as an target node of
/// run with p0 as first child and p1 as last child.
///
/// @code
/// P(const &P p0, const &P p1)
/// @endcode
/// instance as next sibling
/// p0 must be complete
/// p1 must be partial
/// p1 must be instanciable into a successor sibling of p0.
/// Construct a copy of p1 instanciated as the next sibling of p0.
///
/// @code
/// virtual P& operator= (const P& p) = 0;
/// @endcode
///
/// @code
/// virtual bool operator==(const P& p) const;
/// @endcode
/// for using pointer as key in hash table (unordered multimap)
///
/// @code
/// virtual bool operator<(const P& p) const;
/// @endcode
/// for using pointer as key in search tree (multimap)
///
/// @code
/// bool instance(const P& p)
/// @endcode
/// return wether this ptr is an instance of p.
/// if p is complete, then it is equality.
///
/// @code
/// bool subsume(const P& p)
/// @endcode
/// inverse of instance
/// return wether p is an instance of this ptr.
/// if this ptr is complete, then it is equality.
class Pointer
{
public:
    // weight of the best run for this ptr
    // default to unknown
    // if this ptr is partial
    // or the best run was not computed
    // Weight weight;

    // Deprecated common constructors
    // @todo TBR
    // must be replaced by specific constructors
    
    // P(Environment* env, pre_t pre, pre_t post, Rational mlen, size_t k)
    // top (meta-) ptr (head of the main (meta-) Run).
    // it assumes pre notes (default 0)
    // (e.g. from another precedent segment)
    // added at the begining of this segment (as grace notes).
    // it requires solutions with post notes aligned to right bound
    // (beginning of next segment) (default 0)
    // the musical duration is mlen (number of bars).
    // the rank k must be 1 (default value) for classes without rank (1-best algo).
    // the interval heap (in environment) must be empty (first interval created).

    // P(Environment* env, const &P p)
    // next bar
    // construct a pointer to the bar after the bar pointed by p
    
    // P(Environment* env, const &P p0, const &P p1, bool direction)
    // next meta
    // construct a pointer concatenation of p0 (meta) and p1 (1 bar)
    

    virtual bool has_S() const { return false; }
    virtual bool has_K() const { return false; }
    virtual bool has_I() const { return false; }
    virtual bool has_P() const { return false; }
    
    //////////////////////////////////////////////////////////
    //// specific methods - defined in descendant classes ////
    //////////////////////////////////////////////////////////

    /// the pointer is complete
    /// i.e. all fields are set
    virtual bool complete() const = 0;
    inline  bool partial() const { return(! complete()); }
    
    /// return the rank of best (k) pointed.
    /// default is 1.
    /// redefine for classes for k-best parsing.
    virtual size_t rank() const { return 1; }

    /// return wether it is worth descending (dividing) from this pointer.
    /// the result may differ according to whether
    /// this pointer has a WTA state or a Meta state.
    /// For instance:
    /// - for WTA state:
    ///   it is not worth when this pointer corresponds to
    ///   an input sub-segment not inhabited.
    /// - for Meta state:
    ///   it is not worth if this ptr corresponds to an empty segment.
    /// default true.
    virtual bool divisible() const { return true; }
    
    virtual void incr() { }
    
//    // increment the rank (prefix)
//    // default do nothing (when Ptr class has no K)
//    virtual Pointer& operator++ ()
//    {
//        // increment K here
//        return *this;
//    }
//
//    // increment the rank (postfix)
//    // implement postfix in terms of prefix.
//    virtual Pointer operator++ (int)
//    {
//        Pointer result(*this);   // make a copy for result
//        ++(*this);              // Now use the prefix version to do the work
//        return result;          // return the copy (the old) value.
//    }
    
    /// return wether this pointer is compatible with the given label.
    /// @param abstract if flag is true (default),
    /// the label is supposed abstract (label of terminal transition).
    /// if abstract flag is false, the label is supposed concrete.
    /// @see Label.hpp for def. abstract/concrete labels
    /// @return default return true.
    virtual bool compatible(const label_t, bool abstract=true) const
    { return true; }
    
    /// return whether this pointer is a dummy pointer
    /// i.e. it was constructed with P()
    /// default false.
    virtual bool dummy() const = 0;
    
    
    /// return a concrete label value corresponding to this pointer
    /// when considered as a leaf position,
    /// using the label of the given transition.
    /// the given transition must be terminal.
    virtual label_t label(const Transition& t) const = 0;
    

    /// return the weight for a terminal Run associated to the given Transition.
    /// The transition must be terminal.
    /// This pointer must be compatible with the Transition.
    /// input segment can be NULL.
    virtual Weight terminalWeight(const InputSegment*,
                                  const Transition&) const;

    /// return the initial weight for an inner Run associated to the given Transition.
    /// the weight will have to be multiplied with all the weights of subruns.
    /// the transition must be inner.
    /// this pointer must be divisible.
    virtual Weight innerWeight(const Transition&) const;


};

#endif /* Ptr_hpp */


/// @}
