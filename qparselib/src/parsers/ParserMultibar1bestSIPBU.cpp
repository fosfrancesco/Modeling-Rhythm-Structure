//
//  ParserMultibar1bestSIPBU.cpp
//  squant
//
//  Created by Florent Jacquemard on 15/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "ParserMultibar1bestSIPBU.hpp"


//ParserMultibar1bestSIPBU::ParserMultibar1bestSIPBU(WTA* a,
//                                                   InputSegment* s,
//                                                   bool f_barsec, double _barsec,
//                                                   bool f_barbeat, Rational _barbeat,
//                                                   bool f_bars, size_t _bars,
//                                                   pre_t pre, pre_t post,
//                                                   bool ordering):
////                                                   double barlen,
////                                                   size_t nbbars):
//Parser<SIPpointer>(a, s), // does assert a
//table(new Table<SIPpointer,
//                Brecord<SIPpointer>,
//                SIPpointerHasher>(this,
//                                  ordering?
//                                  weightMin<SIPpointer>:
//                                  weightMax<SIPpointer>)),
//// adjust bar length and nb bars values
//_barsec(f_bars?(s->rduration()/_bars):_barsec),
//_bars(f_barsec?(std::ceil(s->rduration() / _barsec)):_bars),
//endmarker_bot(pre,pre),
//endmarker_top((Environment*) this,
//              State::MetaState(_bars),
//              pre, post,
//              Rational(_bars)),
//_bar(), // empty vector
//_ptr()  // empty vector
//{
//    assert(s);
//    assert(_bars > 0);
//    assert(_barsec > 0);
//    // options mutualy exclusive
//    assert(f_barsec || f_bars);
//    assert(! (f_barsec && f_bars));
//}


ParserMultibar1bestSIPBU::ParserMultibar1bestSIPBU(WTA* a,
                                                   InputSegment* s,
                                                   bool ordering,
                                                   pre_t pre, pre_t post,
                                                   double barsec,
                                                   size_t nbbars,
                                                   ScoreModel::ScoreMeter ts):
Parser<SIPpointer>(a, s), // does assert a
table(new Table<SIPpointer,
                Brecord<SIPpointer>,
                SIPpointerHasher>(this,
                                  ordering?
                                  weightMin<SIPpointer>:
                                  weightMax<SIPpointer>)),
endmarker_bot(pre,pre),
endmarker_top(input,
              State::MetaState(nbbars),
              pre, post,
              Rational(nbbars)),
// adjust bar length and nb bars values
_barsec(barsec),
_bars(nbbars),
_ts(ts),  // copy
_ptr(),   // empty vector
_bar()    // empty vector
{
    assert(input);
    assert(s);
    assert(_bars > 0);
    assert(_barsec > 0);
}


ParserMultibar1bestSIPBU::~ParserMultibar1bestSIPBU()
{
    assert(table);
    delete(table);
    // interval heap deleted by ~Environment
}


size_t ParserMultibar1bestSIPBU::addRuns(Atable<SIPpointer>* table,
                                       const SIPpointer& p,
                                       Record<SIPpointer>* it)
{
    assert(p.has_S());

    if (State::isWTA(p.state()))
    {
        TRACE("addRuns: WTAT state {}", p);
        return this->addWTARuns(table, p, it);
    }
    else
    {
        TRACE("addRuns: state is not WTA, ignore");
        // do nothing, runs computed and added manually in best loop.
        return 1;
    }
}


Run<SIPpointer>* ParserMultibar1bestSIPBU::getBar(size_t i) const
{
    assert(i < _bar.size());
    return _bar[i];
}


SIPpointer ParserMultibar1bestSIPBU::getTarget(size_t i) const
{
    assert(i < _ptr.size());
    return _ptr[i];
}


// i is ignored
ScoreModel::ScoreMeter ParserMultibar1bestSIPBU::getTimeSig(size_t i) const
{
    assert(i < _bar.size());
    return(_ts); // copy
}


void ParserMultibar1bestSIPBU::parse()
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);
    assert(_bars > 0);
    assert(_barsec > 0);
    //assert(_barsec == segment->rduration() / _bars);

    Weight wone = wta->weight_one();

    // trick : we create an artificial run to store in table for endmarker_bot
    // in order to be able to process main runs
    assert(endmarker_bot.complete());
    Run<SIPpointer>* run1 = new Run<SIPpointer>(wone);
    run1->insert(SIPpointer((label_t) 1));
    assert(run1->complete());
    Record<SIPpointer>* it1 = table->add(endmarker_bot);
    table->add(endmarker_bot, run1, it1);
    
    // current real-time end date of ptr
    double currentrdur = _barsec;
    //Rational currentmdur = Rational(1);
    
    // first ptr is dummy
    SIPpointer currentmeta = endmarker_bot;
    
    // current bar nb
    // the current meta-state is the opposite
    size_t bar = 1;
    
    SIPpointer rest = endmarker_top;

    // dirty: do not compare to 0 to avoid float conversion errors
    while (rest.interval()->rduration() > 0.0000000001)
    {
        DEBUG("parse bar {}: currentrdur={}, currentmeta={}, rest={}",
              bar, currentrdur, currentmeta, rest);

        // split : n first bar of top
        // pre = pre of top
        // post = unknown
        SIPpointer nextmeta =
            (currentrdur < input->segment->rduration())?
            SIPpointer(input,
                       endmarker_top,
                       currentrdur,
                       Rational(bar), // currentmdur
                       0, 1,
                       State::MetaState(bar)):
            endmarker_top;

        DEBUG("parse bar {}: nextmeta={}", bar, nextmeta);
        
        // split : new 1-bar slice
        SIPpointer currentbar = SIPpointer(input,
                                           rest,
                                           _barsec,    // fixed bar length
                                           Rational(1), // 1 bar
                                           0, 1,
                                           wta->initial());
        currentbar.interval()->align(input->segment);

        DEBUG("parse bar {}: currentbar={}", bar, currentbar);

        // build inner run of size 2
        Run<SIPpointer>* run = new Run<SIPpointer>(wone);
        run->insert(currentmeta);
        run->insert(currentbar);
        // for first run: first element of body = dummy, skip it
        if (bar == 1)
        {
            run->update(wone, DurationList());
        }

        // it is a meta-ptr: no run added by this call
        DEBUG("parse bar {}: add table ptr {}", bar, nextmeta);
        Record<SIPpointer>* it = table->add(nextmeta);

        // now we add the run manually
        DEBUG("parse bar {}: try add run   {} <- {}", bar, nextmeta, *run);
        size_t ret = table->add(nextmeta, run, it);
        if (ret == 0)
        {
            DEBUG("parse bar {}: run of target {} added", bar, nextmeta);
        }
        else
        {
            ERROR("parse bar {}: run of target {} not added FAIL", bar, nextmeta);
        }

        // split : next rest
        rest = SIPpointer(input,
                          rest,
                          _barsec,      // fixed bar length
                          Rational(1),   // 1 bar
                          0, 2,
                          State::MetaState(bar)); // state is not used
        bar++;
        currentrdur += _barsec;
        //currentmdur += Rational(1);
        currentmeta = nextmeta;
    }
    DEBUG("parse: exit loop, currentrdur={}", currentrdur);
    DEBUG("parse: number of bar iterations: {}", bar-1);
}


// fill the vector v with best trees for each measure
void ParserMultibar1bestSIPBU::store_bests()
{
    size_t bar = _bars;
    assert(bar > 0);
    
    INFO("extracting best trees from parse table");

    SIPpointer ptail = endmarker_top;
    
    while (ptail != endmarker_bot)
    {
        // ptail is meta - but not endmarked
        assert(ptail.has_S());
        assert(State::isMeta(ptail.state()));
        INFO("store bar {}: {}", bar, ptail);
        Run<SIPpointer>* rtail = table->best(ptail);
        if (rtail)
        {
            assert(bar > 0);
            assert(rtail->inner());
            assert(rtail->arity() == 2);
            
            // pbar is ptr to a bar
            const SIPpointer& pbar = (*rtail)[1];
            assert(pbar.has_S());
            assert(State::isWTA(pbar.state()));
            INFO("bar {}: {}", bar, pbar);
            // store pointer to run for current bar (can be null)
            _ptr.insert(_ptr.begin(), pbar);
            _bar.insert(_bar.begin(), table->best(pbar));
            
            ptail = (*rtail)[0];
            bar--;
        }
        else
        {
            ERROR("fail to retrieve quantization results bar {} : {}",
                  bar, ptail);
            ptail = endmarker_bot; // force immediate termination
        }
    }
}


void ParserMultibar1bestSIPBU::print_bars()
{
    // print best tree for each bar
    for (size_t i=0; i < this->nbbars(); i++)
    {
        SIPpointer p = this->getTarget(i);
        Run<SIPpointer>* r = this->getBar(i);
        std::cout << "|";
        std::cout << "(" << i+1 << ") ";
        if (r)
        {
            this->printobestRun(std::cout, this->table, r);
            std::cout << " pre=" << p.pre();
            std::cout << " post=" << p.post();
            std::cout << " ";
            assert(p.interval());
            std::cout << *p.interval();
            std::cout << std::endl;
        }
        else
        {
            std::cout << " FAIL";
        }
    }
    std::cout << "||" << std::endl;
    
    Run<SIPpointer>* rtop = this->table->best(this->endmarker_top);
    if (rtop)
    {
        std::cout << "total weight: " << rtop->weight;
        //std::cout << " " << rtop->duration << std::endl;
    }
    else
    {
        ERROR("failed to compute rtop");
    }
    std::cout << std::endl;
}


// return newly allocated input segment
// which is a copy of original input segment in parser
// with musical dates and durations updated according to parse table.
InputSegment* ParserMultibar1bestSIPBU::update_iseg()
{
    assert(input->segment);
    
    InputSegment* qseg;
    
    if (dynamic_cast<InputSegmentSerial*>(input->segment))
    {
        qseg = new InputSegmentSerial(
                *(dynamic_cast<InputSegmentSerial*>(input->segment)));
    }
    else if (dynamic_cast<InputSegmentMIDI*>(input->segment))
    {
        qseg = new InputSegmentMIDI(
                *(dynamic_cast<InputSegmentMIDI*>(input->segment)));
    }
    else
    {
        qseg = new InputSegment(*(input->segment));
    }
    
    size_t b = 0; // point number in input segment
    
    // TBC: quantize une fois (b=0) sur top ptr
    // qseg->quantize(this->table, this->endmarker_top);
    for (size_t i=0; i < this->nbbars(); i++)
    {
        b = qseg->quantizu(this->table, this->getTarget(i), b);
    }

    qseg->respell();
    
    return qseg;
}


void ParserMultibar1bestSIPBU::midi_output(std::string filename,
                                           Rational beatsperbar,
                                           InputSegment* qseg)
{
    assert(qseg);
    InputSegmentMIDI* midiseg = dynamic_cast<InputSegmentMIDI*>(qseg);
    assert(midiseg);
    // @todo
    midiseg->export_midifile(filename, beatsperbar);
    //midiseg->export_midifile_mono(filename, beatsperbar);
}


void ParserMultibar1bestSIPBU::mei_output(std::string filename,
                                          InputSegment* qseg)
{
    cout << "ParserMultibar1bestSIPBU" << std::endl;
    
    assert(qseg);
    size_t bars = this->nbbars();
    // convert best trees to best pointerTrees
    std::vector<const PointedRhythmTree*> quantizedbars =
    std::vector<const PointedRhythmTree*>();

    size_t next = 0;
    for (size_t i=0; i < bars; i++)
    {
        Run<SIPpointer>* r = this->getBar(i);
        if (r)
        {
            RhythmTree* t = this->table->bestTree(r);
            PointedRhythmTree* pt =
                new PointedRhythmTree(t, qseg, next);
            quantizedbars.push_back(pt);
            next = pt->next();
            delete t;
            if (next >= qseg->size())
            {
                WARN("PointedTree.next={} (segment size={})",
                     next, qseg->size());
                break;
            }
        }
        else
        {
            WARN("no solution for bar {}", i+1);
            quantizedbars.push_back(NULL);
        }
    }
    
    cout << "Create the symbolic score from the best tree" << std::endl;
    
    // Obtain the time signature
    ScoreModel::Score myScore = ScoreModel::Score("test", getTimeSig(1));
    
    ScoreModel::Voice* voice = myScore.getVoice("test", "test");
    
    for (const PointedRhythmTree* pointedRT : quantizedbars) {
        // First measure
        ScoreModel::Measure* measure = myScore.addMeasure();
        cout << endl <<  "Found a pointedRTree. Add measure  " << measure->getId() << " with duration " <<
        measure->getDuration().getValue() << "(CMN " << measure->getDuration().getCMN() << ")" << endl;
        voice->addFromRhythmTree(measure, pointedRT, measure->getDuration());
        
        // For test
        //break;
    }
    
    INFO("Serialize in MEI and store in {}", filename);
    
    MEI meiProcessor = MEI();
    meiProcessor.createFromScore(myScore);
    meiProcessor.writeInFile(filename);

    INFO("Serialization in MEI in {} done", filename);
}


size_t ParserMultibar1bestSIPBU::demo(const string _schema_file,
                                      const string _input_file,
                                      const std::string _output_file,
                                      Rational _barbeat)
{
    assert(wta);
    assert(input->segment);
    assert(_barbeat > Rational(0));

    INFO("parsing segment [{}-{}], rdur={}",
         input->segment->rbegin(),
         input->segment->rend(),
         input->segment->rduration());
    assert(this->nbbars() == _bars);
    INFO("fixed bar duration = {}s", _barsec);
    INFO("number of bars = {}", _bars);

    clock_t time_start = clock();
    INFO("start parsing");
    parse();
    INFO("time to parse : {}ms", duration(time_start));

    store_bests();

    
    // print result as trees
    print_bars();
    
    // record quantized date/dur in a copy of input segment
    InputSegment* qseg = update_iseg();
    
    INFO("quantized segment:");
    std::cout << *qseg;
    
    if (_output_file.size() > 0) // empty string : no output
    {
        size_t dotindex = _output_file.find_last_of(".");
        //string prefix = filename.substr(0, dotindex);
        string suffix = _output_file.substr(dotindex + 1);
        std::transform(suffix.begin(), suffix.end(), suffix.begin(), ::toupper);
        
        // export only if output file has midi suffix
        if (suffix == "MID" || suffix == "MIDI")
        {
            INFO("MIDIfile export");
            midi_output(_output_file, _barbeat, qseg);
        }
        else if (suffix == "MEI")
        {
            INFO("MEI export");
            mei_output(_output_file, qseg);
        }
        else
        {
            ERROR("unknown suffix ouput file {}", _output_file);
        }
    }
    
    delete qseg;
    
    return 0;
}


// @todo TBR old
//std::vector<const RhythmTree*> ParserMultibar1bestSIPBU::bestTrees()
//{
//    assert(wta);
//    assert(table);
//
//    std::vector<const RhythmTree*> v = std::vector<const RhythmTree*>();
//
//    SIPpointer ptail = endmarker_top;
//
//        //Run<SIPpointer>* rtail = r;
//    Run<SIPpointer>* rbar = NULL;
//        
//    while (ptail != endmarker_bot)
//    {
//        Run<SIPpointer>* rtail = table->best(ptail);
//        if (rtail)
//        {
//            assert(rtail->inner());
//            assert(rtail->arity() == 2);
//
//            const SIPpointer& pbar = (*rtail)[1];
//            assert(pbar.has_S());
//            assert(State::isWTA(pbar.state()));
//            rbar = table->best(pbar);
//            if (rbar)
//            {
//                v.insert(v.begin(), table->bestTree(rbar));
//            }
//            else
//            {
//                v.insert(v.begin(), NULL);
//            }
//            
//            ptail = (*rtail)[0];
//            assert(ptail.has_S());
//            assert(State::isMeta(ptail.state()));
//            rtail = table->best(ptail);
//        }
//        else
//        {
//            WARN("fail to quantize");
//            return v;
//        }
//    }
//    return v;
//}

