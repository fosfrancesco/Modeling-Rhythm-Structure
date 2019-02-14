//
//  Parser.hpp
//  squant
//
//  Created by Florent Jacquemard on 05/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// a Parser is in charge of the construction of runs to fill a parse table,
// using a WTA.


#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"
#include "Rune.hpp"
#include "Record.hpp"
#include "Atable.hpp"


// P = concrete pointer class (keys in table)
// R = record class (values in table)
// H = PointerHasher (for keys)
//template<class P, class R, class H>
template<class P>
class Parser : public Environment
{
public:
    // every parser uses at least one WTA for parsing
    // some other WTA's can be added in descendant classes
    WTA* wta;
    
    // input segment. can be NULL for inputless parsers.
    Environment* input;
    
    // see Environment
    Parser(WTA* a, InputSegment* s = NULL);

    // wta must be deallocated externaly
    ~Parser();

    // resolution of WTA
    // 0 by default
    size_t resolution();
    
    // addRuns(table, p, it)
    // add to the given table some run computed from p
    // it must be
    // a pointer to the record associated to p in table if p complete
    // NULL if p partial
    virtual size_t addRuns(Atable<P>*, const P&, Record<P>*) = 0;

    // print best tree for p
    virtual void printobest(std::ostream& o,
                            Atable<P>* table,
                            const P&) const;
    
    // print best tree for run r
    virtual void printobestRun(std::ostream& o,
                               Atable<P>* table,
                               Run<P>* r) const;
    
protected:
    
    // add run for the case corresponding to a WTA transition
    virtual size_t addWTARuns(Atable<P>*, const P&, Record<P>*);
    
    // resolution (defined by wta)
    // 0 if it was not computed (or no schema)
    size_t _res;
    
};


// separated definition of template class
#include "Parser.tpp"


#endif /* Parser_hpp */
