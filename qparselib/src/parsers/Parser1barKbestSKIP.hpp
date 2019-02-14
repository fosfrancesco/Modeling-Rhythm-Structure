//
//  ParserSIP1barKbest.hpp
//  squant
//
//  Created by Florent Jacquemard on 14/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#ifndef Parser1barKbestSKIP_hpp
#define Parser1barKbestSKIP_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"
#include "PtrSKIP.hpp"
#include "Record.hpp"
#include "Krecord.hpp"
#include "Table.hpp"
#include "Parser.hpp"
#include "RT.hpp"


class Parser1barKbestSKIP : public Parser<SKIPpointer>
{
public:
    Table<SKIPpointer, Krecord<SKIPpointer>, SKIPpointerHasher>* table;

    // ordering 0 for min, 1 for max
    Parser1barKbestSKIP(WTA* a, InputSegment* s, bool ordering=false);
    
    ~Parser1barKbestSKIP();
    
    virtual size_t addRuns(Atable<SKIPpointer>*,
                           const SKIPpointer&,
                           Record<SKIPpointer>*);
    
    // @todo TBR (mv to script)
    RhythmTree* bestTree(size_t k=1,
                         pre_t pre = 0,
                         pre_t post = 0) const;
    
    // @todo TBR (mv to script)
    Run<SKIPpointer>* bestRun(size_t k=1,
                              pre_t pre = 0,
                              pre_t post = 0) const;
    
    // @todo TBR (mv to script)
    Weight bestWeight(size_t k=1,
                      pre_t pre = 0,
                      pre_t post = 0) const;
    
    // @todo TBR (mv to script)
    void printBest(std::ostream& o,
                   size_t k=1,
                   pre_t pre=0,
                   pre_t post=0) const;
    
    size_t demo(const string schema_file,
                const string input_file,
                pre_t pre=0, pre_t post=0,
                size_t k=1);

    
private:
    
};




#endif /* Parser1barKbestSKIP_hpp */
