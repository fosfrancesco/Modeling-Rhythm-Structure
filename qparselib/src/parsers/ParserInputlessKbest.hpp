//
//  ParserInputlessKbest.hpp
//  qparse
//
//  Created by Florent Jacquemard on 09/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// running environement for computing the k best trees of a WTA
// no input segment



#ifndef ParserInputlessKbest_hpp
#define ParserInputlessKbest_hpp

#include <stdio.h>
#include <iostream>

#include "init.hpp"
#include "trace.hpp"
#include "WTA.hpp"
#include "PtrSK.hpp"
#include "Record.hpp"
#include "Krecord.hpp"
#include "Table.hpp"
#include "Parser.hpp"
#include "RT.hpp"


class ParserInputlessKbest : public Parser<SKpointer>
{
public:
    Table<SKpointer, Krecord<SKpointer>, SKpointerHasher>* table;

    // ordering 0 for min, 1 for max
    ParserInputlessKbest(WTA* a, bool ordering);
    
    ~ParserInputlessKbest();
    
    virtual size_t addRuns(Atable<SKpointer>*,
                         const SKpointer&,
                         Record<SKpointer>*);
    
    // @todo TBR (mv to script)
    RhythmTree* best(size_t);
    Weight bestWeight(size_t);
    
    // print_best(o, k)
    // print best number k to stream o
    // @todo TBR (mv to script)
    virtual void printBest(std::ostream&, size_t k=1) const;
    
    size_t demo(const string schema_file, size_t k=1);
    
protected:
    
};


#endif /* ParserInputlessKbest_hpp */
