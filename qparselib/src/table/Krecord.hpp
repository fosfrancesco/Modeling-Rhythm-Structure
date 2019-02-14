//
//  Krecord.hpp
//  squant
//
//  Created by Florent Jacquemard on 11/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef Krecord_hpp
#define Krecord_hpp

#include <stdio.h>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector

#include "Record.hpp"
#include "Rune.hpp"

/// record associated to Ptr
/// for k-best procedures.
template<class P>
class Krecord : public Record<P>
{
public:
    Krecord(const P&, RunCompare<P>);
    
    ~Krecord();
    
    /// add a run to the record.
    virtual void add(Run<P>*);
    
    /// returns the k-th best run of the record.
    /// Fill the list of best runs up to (at most) k if necessary.
    /// If less than k best can be constructed (table is complete),
    /// return an null run (weight unknown),
    /// otherwise, the weight of the returned run is known.
    virtual Run<P>* best(Atable<P>* table, size_t k=1);
    
    virtual bool empty() const;
    
protected:
    
    /// heap of candidate runs for the associated state.
    /// it is empty iff no more k-best can be added
    std::priority_queue<Run<P>*,
                        std::vector<Run<P>*>,
                        RunCompare<P>> _cand;
    
    /// ordered list of best runs for the associated state.
    std::vector<Run<P>*> _best;
    
    /// add Run r to the heap of candidates
    /// after some filtering based on optimisation flags.
    /// @param r given Run can be complete or partial (weight not fully evaluated)
    virtual void addCand(Run<P>* r);
    
    /// add Run r at the end of the list of best runs.
    /// record the given run r as one of the best runs of the record.
    /// @param r must be complete (weight fully evaluated).
    virtual void addBest(Run<P>* r);

    
    bool bestFilter(const Run<P>* r);
    
    /// add the candidates following Run r (lexico order for ranks)
    /// to the heap of candidates.
    /// @param r must be complete (weight fully evaluated).
    /// the nexts Run (new candidates) will be partial
    void addNext(Run<P>* r);
};


// separated definition of template class
#include "Krecord.tpp"


#endif /* Krecord_hpp */


/// @}
