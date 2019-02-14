//
//  ParserMultibar1bestSIPflat.hpp
//  squant
//
//  Created by Florent Jacquemard on 25/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#ifndef ParserMultibar1bestSIPflat_hpp
#define ParserMultibar1bestSIPflat_hpp

#include <stdio.h>
#include <math.h>  // ceil

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
#include "RT.hpp"

class ParserMultibar1bestSIPflat : public Parser<SIPpointer>
{
public:
    // parse table
    Table<SIPpointer, Brecord<SIPpointer>, SIPpointerHasher>* table;
    
    // top ptr = unique entry for the whole sequence of bars
    const SIPpointer endmarker_top;
    
    // ordering 0 for min, 1 for max
    ParserMultibar1bestSIPflat(WTA* a,
                               InputSegment* s,
                               double barlen,
                               bool ordering=false,
                               pre_t pre=0,
                               pre_t post=0);

    // ordering 0 for min, 1 for max
    ParserMultibar1bestSIPflat(WTA* a,
                               InputSegment* s,
                               double barlen_min,
                               double barlen_max,
                               size_t nbsteps,
                               bool ordering=false,
                               pre_t pre=0,
                               pre_t post=0);
    
    ~ParserMultibar1bestSIPflat();
    
    virtual size_t addRuns(Atable<SIPpointer>*,
                         const SIPpointer&,
                         Record<SIPpointer>*);
    
    size_t nbbars() const;
    
    // return the best sol for bar i
    Run<SIPpointer>* getBar(size_t) const;
    
    // return the target of the best sol for bar i
    SIPpointer getTarget(size_t) const;

    
    size_t demo(const std::string schema_file,
                const std::string input_file,
                const std::string output_file="",
                Rational barbeat=Rational(1));

    static double barlen(double tempo, size_t beatsperbar);

    
private:
    pre_t _pre;
    pre_t _post;
    Run<SIPpointer>* _best;
    
    // return partial meta run (flat)
    // for quantization of all bars.
    Run<SIPpointer>* parse(double barlen);
    
};


#endif /* ParserMultibar1bestSIPflat_hpp */
