//
//  Weight.hpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @defgroup weight Weight module
///
/// The `weight` module contains the definitions of several  domains
/// for weight values for tree automata.
///
/// @addtogroup weight
/// @{


#ifndef Weight_hpp
#define Weight_hpp

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>


class Weight;


/// @brief abstract class for concrete weight values.
/// Every concrete weight domain must be a derived class of LetterWeight.
class LetterWeight
{
    friend class Weight;
    
public:
    /// @warning should not happen.
    LetterWeight() {}
    
    LetterWeight(const LetterWeight&) {}
    
    /// @brief virtual destructor to ensure correct destruction
    /// of derived objects through a pointer to base Weight object.
    virtual ~LetterWeight() {}
    
    LetterWeight& operator= (const LetterWeight&) { return *this; }
    
    virtual LetterWeight* clone() const = 0;
    
    /// @brief factory.
    /// @return a weight of same type as this letter, initialized with given value.
    virtual Weight make(double v) const = 0;
    
    /// @brief return the neutral element for add (absorbing element for mult)
    /// wrapped in a Weight.
    virtual Weight get_zero() const = 0;

    /// @brief return the neutral element for mult
    /// wrapped in a Weight.
    virtual Weight get_one() const = 0;

    virtual double norm() const = 0;
    
    virtual void scalar(double) = 0;

    /// @brief multiplicative inverse, for semifields.
    virtual void invert() = 0;
    
    /// @brief this letterweight is neutral element for add
    /// (absorbing element for mult).
    virtual bool zero() const;
    
    /// @brief this letterweight is neutral element for mult.
    virtual bool one() const;
    
    virtual bool hasType(std::string) const = 0;
   
protected:

    /// @brief binary operators are defined only
    /// between descendant LetterWeights of same typeid.
    virtual bool equal(const LetterWeight*) const;

    /// @brief binary operators are defined only
    /// between descendant LetterWeights of same typeid.
    virtual bool smaller(const LetterWeight*) const;
    
    /// @brief binary operators are defined only
    /// between descendant LetterWeights of same typeid.
    virtual void add(const LetterWeight*);
    
    /// @brief binary operators are defined only
    /// between descendant LetterWeights of same typeid.
    virtual void mult(const LetterWeight*);
    
    virtual void print(std::ostream& o) const;
    
};




/// @brief A class of polymorphic weight domains for tree series.
///
/// Every concrete weight domain must be a derived class of Weight.
///
/// the type Weight is the union of an unknown weight value and different
/// weight domain.
///
/// it is implemented as an envelope, containing either
/// - a null letter. in this case, we have an unknown weight value.
/// - a non-null letter, pointing to an object of a derived weight class
/// (concrete weight). In this case, the envelope is a wrapper for the object
/// of the derived class, corresponding to an actual (known) weight value.
/// see Envelope Letter Idiom (wikibooks)
///
/// Client code only uses the Weight class (not the derived classes),
/// except for allocation of new concrete weights values by
/// Weight(new DerivedWeight(...))
class Weight
{
public:
    // @brief empty constructor for cython
    //Weight();

    /// @brief wrapper
    /// and unknown weight constructor (empty envelope, default).
    Weight(LetterWeight* w = NULL):_letter(w) {}

    /// @brief clone the letter.
    Weight(const Weight& w);
    
    ~Weight();
    
    Weight& operator= (const Weight&);
    
    // @brief peel the wrapper.
    // @return the letter if it is not null
    // @return a pointer to this object otherwise
    //const Weight* peeloff() const;

    /// @warning must not be unknown
    LetterWeight* operator->() const { assert (_letter); return _letter; }
    
    Weight* clone() const;

    /// @brief unknown weight is a Weight with NULL letter.
    bool unknown() const;
    
    /// @see LetterWeight.make
    Weight make(double v) const;
    
    /// @param code is the code of the letter weight if there is one
    /// or "UNKNOWN" otherwise.
    bool hasType(std::string code) const;
    
    /// @warning this Weight must not be unknown (letter != NULL)
    /// @warning not const: may need recomputations.
    double norm();
    
    /// @brief scalar multiplication.
    /// @warning this Weight must not be unknown (letter != NULL).
    void scalar(double);
    
    /// @brief this weight is neutral element for + (absorbing element for *).
    bool zero() const;
    
    /// @brief return the neutral element for add (absorbing element for mult)
    /// for the LetterWeight, if any
    /// otherwise return unknown Weight.
    Weight get_zero() const;

    /// @see add
    void operator+=(const Weight& rhs){ add(rhs); }
    
    // first arg is modified
    //inline Weight& operator+(Weight& lhs, const Weight& rhs)
    //{
    //    lhs += rhs;
    //    return lhs;
    //}

    /// @brief this weight is neutral element for *
    bool one() const;

    /// @brief return the neutral element for mult for the LetterWeight, if any
    /// otherwise return unknown Weight.
    Weight get_one() const;
    
    /// @see mult
    void operator*=(const Weight& rhs){ mult(rhs); }

    // first arg is modified
    //inline Weight& operator*(Weight& lhs, const Weight& rhs)
    //{
    //    lhs *= rhs;
    //    return lhs;
    //}

    /// @brief multiplicative inverse, for semifields
    /// @warning this Weight must not be zero
    /// @warning this Weight must not be unknown (letter != NULL)
    ///
    /// @todo TBR : replace by div with const rhs
    void invert();
    
    /// @brief delete the letter.
    /// @warning this weight becomes unknown.
    void clear();

    std::string save_to_string();


    
    // virtual friends
    
    /// @see equal
    friend inline bool operator==(const Weight&, const Weight&);

    /// @see smaller
    friend inline bool operator<(const Weight&, const Weight&);

    /// @see print
    friend inline std::ostream& operator<<(std::ostream& o, const Weight& rhs);

    // @todo TBR: NOT USED
    //    friend Weight operator+(Weight, const Weight&);
    //    friend Weight operator*(Weight, const Weight&);

    
protected:
    /// @brief letter always points to an object of one of the derived *Weight classes
    /// never to an object of the Weight base class.
    LetterWeight* _letter;
    
    /// @brief binary operators are defined only
    /// between descendant Weights of same typeid
    
    /// - two unknown Weights are equal
    /// - one unknown weight and one not unknown are not equal
    /// - equality of two not unknown weight depends on the descendant class
    bool equal(const Weight& rhs) const;
    
    /// - unknown Weight is minimal:
    /// - unknown Weight is smaller than any not unknown Weight
    /// - not unknown Weight is not smaller that unknown Weight
    /// - unknown Weight is not smaller than unknown Weight
    /// - inequality of two not unknown weight depends on the descendant class
    bool smaller(const Weight& rhs) const;
    
    /// @warning this and rhs must not be unknown
    void add(const Weight& rhs);
    
    /// @warning this and rhs must not be unknown
    void mult(const Weight& rhs);
    
    void print(std::ostream& o) const;
};


inline bool operator==(const Weight& lhs, const Weight& rhs)
{
    return (lhs.equal(rhs));
}

inline bool operator!=(const Weight& lhs, const Weight& rhs)
{
    return !operator==(lhs,rhs);
}

inline bool operator< (const Weight& lhs, const Weight& rhs)
{
    return (lhs.smaller(rhs));
}

inline bool operator> (const Weight& lhs, const Weight& rhs)
{
    return  operator< (rhs,lhs);
}

inline bool operator<=(const Weight& lhs, const Weight& rhs)
{
    return !operator> (lhs,rhs);
}

inline bool operator>=(const Weight& lhs, const Weight& rhs)
{
    return !operator< (lhs,rhs);
}

inline std::ostream& operator<<(std::ostream& o, const Weight& rhs)
{
    rhs.print(o);
    return o;
}



#endif /* Weight_hpp */


/// @}
