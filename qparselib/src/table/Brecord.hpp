//
//  Brecord.hpp
//  squant
//
//  Created by Florent Jacquemard on 11/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef Brecord_hpp
#define Brecord_hpp

#include <stdio.h>

#include "Record.hpp"
#include "Rune.hpp"


/// record associated to Ptr
/// for one-best procedures.
template<class P>
class Brecord : public Record<P>
{
public:
    Brecord(const P&, RunCompare<P>);
    
    ~Brecord();
    
    /// add a run to the record.
    virtual void add(Run<P>*);
    
    /// returns the k-th best run of the record
    /// @param parent is ignored
    /// @param k rank (as in k-best)
    virtual Run<P>* best(Atable<P>* parent, size_t k=1);
    
    virtual bool empty() const;
    
protected:
    
    /// best run for the associated state.
    Run<P>* _best;
    
};


// separated definition of template class
#include "Brecord.tpp"


#endif /* Brecord_hpp */


/// @}
