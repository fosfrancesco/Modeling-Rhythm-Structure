//
//  Parser1bar1bestSIP.hpp
//  qparse
//
//  Created by Florent Jacquemard on 09/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// running environement for computing the 1-best tree
// in a given WTA language
// for the transcription of a given input segment
// (if the WTA trees represent 1 bar, this scenario is transcription of
//  the whole segment as a single bar).



#ifndef Parser1bar1bestSIP_hpp
#define Parser1bar1bestSIP_hpp

#include <stdio.h>
#include <iostream>

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"
#include "PtrSIP.hpp"
#include "Record.hpp"
#include "Brecord.hpp"
#include "Table.hpp"
#include "Parser.hpp"


class Parser1bar1bestSIP : public Parser<SIPpointer>
{
public:
    Table<SIPpointer, Brecord<SIPpointer>, SIPpointerHasher>* table;

    // ordering 0 for min, 1 for max
    Parser1bar1bestSIP(WTA* a, InputSegment* s, bool ordering=false);
    
    ~Parser1bar1bestSIP();
    
    virtual size_t addRuns(Atable<SIPpointer>*,
                           const SIPpointer&,
                           Record<SIPpointer>*);
    
    // @todo TBR (mv to script)
    RhythmTree* bestTree(pre_t pre = 0,
                         pre_t post = 0) const;

    // @todo TBR (mv to script)
    Run<SIPpointer>* bestRun(pre_t pre = 0,
                             pre_t post = 0) const;

    // @todo TBR (mv to script)
    Weight bestWeight(pre_t pre = 0,
                      pre_t post = 0) const;
    
    // @todo TBR (mv to script)
    void printBest(std::ostream& o,
                    pre_t pre=0,
                    pre_t post=0) const;
    
    size_t demo(const string schema_file,
                const string input_file,
                pre_t pre=0, pre_t post=0);

private:
    
};



#endif /* Parser1bar1bestSIP_hpp */
