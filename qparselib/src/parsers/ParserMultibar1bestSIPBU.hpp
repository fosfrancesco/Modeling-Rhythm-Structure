//
//  ParserMultibar1bestSIPBU.hpp
//  squant
//
//  Created by Florent Jacquemard on 15/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// Parser for multiple bars 1-best parsing
// with SIPptr
// BU construction of meta-runs for bar sequences
// assume number of bars is known
// bar size is fixed.

#ifndef ParserMultibar1bestSIPBU_hpp
#define ParserMultibar1bestSIPBU_hpp

#include <stdio.h>
#include <math.h>  // ceil

#include "init.hpp"
#include "trace.hpp"
#include "InputSegment.hpp"
#include "InputSegmentSerial.hpp"
#include "InputSegmentMIDI.hpp"
#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"
#include "WTA.hpp"
#include "PtrSIP.hpp"
#include "Record.hpp"
#include "Brecord.hpp"
#include "Table.hpp"
#include "Parser.hpp"
#include "RT.hpp"
#include "PointedRT.hpp"
#include "MEI.hpp"
#include "Score.hpp"
#include "Event.hpp"
#include "Measure.hpp"
#include "Note.hpp"


class ParserMultibar1bestSIPBU : public Parser<SIPpointer>
{
public:
    // parse table
    Table<SIPpointer, Brecord<SIPpointer>, SIPpointerHasher>* table;
    
    // dummy ptr to start sequence of bars
    const SIPpointer endmarker_bot;
    
    // top ptr = whole input segment
    const SIPpointer endmarker_top;
    

    // options parsing
    // @todo TBR
//  ParserMultibar1bestSIPBU(WTA* a,
//                             InputSegment* s,
//                             bool f_barsec, double barsec,
//                             bool f_barbeat, Rational barbeat,
//                             bool f_bars, size_t bars,
//                             pre_t pre=0,
//                             pre_t post=0,
//                             bool ordering=false);

    
    // construct parser with given
    // bar realtime length and given nb of bars
    // ordering 0 for min, 1 for max
    ParserMultibar1bestSIPBU(WTA* a,
                             InputSegment* s,
                             bool ordering=false,
                             pre_t pre=0,
                             pre_t post=0,
                             double barlen=1.0,
                             size_t nbbars=1,
                             ScoreModel::ScoreMeter ts=ScoreModel::ScoreMeter(1,4));
    
    ~ParserMultibar1bestSIPBU();
    
    virtual size_t addRuns(Atable<SIPpointer>*,
                           const SIPpointer&,
                           Record<SIPpointer>*);
    
    inline size_t nbbars() const { return _bars; }
    
    // return the best sol for bar i
    Run<SIPpointer>* getBar(size_t) const;

    // return the target of the best sol for bar i
    SIPpointer getTarget(size_t) const;

    // return the time signature for bar i
    ScoreModel::ScoreMeter getTimeSig(size_t) const;
    
    // output file can be empty (do no export output in a file)
    // otherwise it must have suffix .mid or .mei
    // barbeat = number of beats in a bar (used for MIDI file output)
    size_t demo(const std::string schema_file,
                const std::string input_file,
                const std::string output_file="",
                Rational barbeat=Rational(1));
    
private:

    // length of one bar
    double _barsec;
    
    // number of bars
    size_t _bars;
    
    // time signature
    ScoreModel::ScoreMeter _ts;
    
    std::vector<SIPpointer> _ptr;
    std::vector<Run<SIPpointer>*> _bar;
    
    // construct partial meta ptr (for bests for several bars)
    // and add runs for them.
    // the argument is the expect nb of bars for the input segment
    void parse();
    
    void store_bests();
    
    void print_bars();
    
    // return newly allocated input segment
    // which is a copy of original input segment in parser
    // with musical dates and durations updated according to parse table.
    InputSegment* update_iseg();

    void midi_output(std::string filename,
                     Rational beatsperbar,
                     InputSegment* qseg);

    void mei_output(std::string filename,
                    InputSegment* qseg);

    
    // @todo TBR (repl by getBestTrees)
    //std::vector<const RhythmTree*> bestTrees();
    
};


#endif /* ParserMultibar1bestSIPBU_hpp */
