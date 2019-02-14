//
//  Atable.hpp
//  squant
//
//  Created by Florent Jacquemard on 02/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef Atable_hpp
#define Atable_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
//#include "InputSegment.hpp"
//#include "IntervalTree.hpp"
//#include "IntervalHeap.hpp"
//#include "WTA.hpp"
#include "Rune.hpp"
#include "Record.hpp"
//#include "RT.hpp"
//#include "Parser.hpp"
//#include "Environment.hpp"

//class Environment;
template<class P> class Parser;


/// abstract interface to parse table
// definition of a type table<P>
// P = concrete pointer class (keys in table)
template<class P>
class Atable
{
public:
    /// parsing environment.
    Parser<P>* parent;
    
    /// @param env environment must not be null.
    Atable(Parser<P>* env, RunCompare<P> comp);

    ~Atable();    

    /// return k-best run pointed by p
    /// or NULL if there is none.
    /// k is either included in p or the default value 1.
    /// @param p must be complete.
    virtual Run<P>* best(const P& p) = 0;
    
    /// tree corresponding to the k-best run in p.
    virtual RhythmTree* bestTree(const P& p) = 0;
    
    /// when the k-best run in p is already computed.
    /// @param p not used
    /// @todo TBR param p
    /// @warning the run must be wta.
    virtual RhythmTree* bestTree(Run<P>* p) = 0;
    
    // top wta run in the given meta-run.
    // the given run must be meta and inner.
    // the given ptr must be multiple-bar.
    // virtual Run<P>* head(const P&, Run<P>*);

    // next meta-run in the given meta-run.
    // the given run must be meta and inner.
    // the given ptr must be multiple-bar.
    // virtual Run<P>* tail(const P&, Run<P>*);
    
    // add(p, r)
    // interface for adding run r to record of p
    // when run is partially evaluated
    // for lazy k-best processing of candidates
    // p must be complete and have registered entry in table
    // (i.e. best was called)
    // r can be complete or partial
    // @todo TBR
    //virtual void add(const P&, Run<P>*) = 0;
    
    /// add possible instances of run r
    /// to the entries in table for corresp. to possible instances for p.
    /// dispatch to the four functions below according to p and r.
    /// @param p can be complete or partial.
    /// @param r can be complete or partial.
    /// @param i if p is complete, then i must be an iterator to the entry for p in table,
    ///        otherwise (p partial), i is table.end().
    virtual size_t add(const P& p, Run<P>* r, Record<P>* i) = 0;
    
    virtual size_t nb_entries() = 0;
    virtual size_t nb_runs() = 0;
    
protected:
    RunCompare<P> _comparer;
};


// separated definition of template class
#include "Atable.tpp"


#endif /* Atable_hpp */



/// @}
