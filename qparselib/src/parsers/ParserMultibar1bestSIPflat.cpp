//
//  ParserMultibar1bestSIPflat.cpp
//  squant
//
//  Created by Florent Jacquemard on 25/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "ParserMultibar1bestSIPflat.hpp"

ParserMultibar1bestSIPflat::ParserMultibar1bestSIPflat(WTA* a,
                                                       InputSegment* s,
                                                       double barlen,
                                                       bool ordering,
                                                       pre_t pre,
                                                       pre_t post):
Parser<SIPpointer>(a, s),
table(new Table<SIPpointer,
      Brecord<SIPpointer>,
      SIPpointerHasher>(this,
                        ordering?
                        weightMin<SIPpointer>:
                        weightMax<SIPpointer>)),
endmarker_top(), // dummy ptr
_pre(pre),
_post(post),
_best(NULL)
{
    assert(s);
    assert(0 < barlen);

    // get pointer to (unique) top ptr
    // it is a meta-ptr: no run added by this call
    TRACE("add top ptr {}", endmarker_top);
    Record<SIPpointer>* itop = table->add(endmarker_top);
    
    Run<SIPpointer>* run = parse(barlen);
    assert(run);
    TRACE("parser: add table run {} -> {} for bar length={}s",
          *run, endmarker_top, barlen);
    // we add the run manually
    table->add(endmarker_top, run, itop);
    
    _best = table->best(endmarker_top);
    assert((_best == NULL) || _best->complete());
}


ParserMultibar1bestSIPflat::ParserMultibar1bestSIPflat(WTA* a,
                                                       InputSegment* s,
                                                       double barlen_min,
                                                       double barlen_max,
                                                       size_t nbsteps,
                                                       bool ordering,
                                                       pre_t pre, pre_t post):
Parser<SIPpointer>(a, s),
table(new Table<SIPpointer,
      Brecord<SIPpointer>,
      SIPpointerHasher>(this,
                        ordering?
                        weightMin<SIPpointer>:
                        weightMax<SIPpointer>)),
endmarker_top(), // dummy ptr
_pre(pre),
_post(post)
{
    assert(s);
    assert(0 < barlen_min);
    assert(barlen_min <= barlen_max);

    assert(wta);
    assert(table);
    assert(segment);
    assert((nbsteps > 0) || (barlen_min < barlen_max));
    
    double step = (nbsteps == 0)?
        (barlen_max - barlen_min):
        ((barlen_max - barlen_min) / nbsteps);
    double barlen = barlen_min;
    
    // get pointer to (unique) top ptr
    // it is a meta-ptr: no run added by this call
    TRACE("add top ptr {}", endmarker_top);
    Record<SIPpointer>* itop = table->add(endmarker_top);
    
    // dirty: do not compare to 0 to avoid float conversion errors
    while (barlen <= barlen_max)
    {
        Run<SIPpointer>* run = parse(barlen);
        assert(run);
        TRACE("parser: add table run {} -> {} for bar length={}s",
              *run, endmarker_top, barlen);
        // we add the partial run manually. it will be completed.
        table->add(endmarker_top, run, itop);
        
        barlen += step;
    }
    
    _best = table->best(endmarker_top);
    assert((_best == NULL) || _best->complete());
}


ParserMultibar1bestSIPflat::~ParserMultibar1bestSIPflat()
{
    assert(table);
    delete(table);
    // interval heap deleted by ~Environment
}


size_t ParserMultibar1bestSIPflat::addRuns(Atable<SIPpointer>* table,
                                         const SIPpointer& p,
                                         Record<SIPpointer>* it)
{
    assert(p.has_S());
    assert(it);
    
    if (State::isWTA(p.state()))
    {
        TRACE("addRuns: WTAT state {}", p);
        return this->addWTARuns(table, p, it);
    }
    else
    {
        // otherwise, runs are added manually
        TRACE("addRuns: state is not WTA, ignore");
        return 1;
    }
}


size_t ParserMultibar1bestSIPflat::nbbars() const
{
    // 1 bar
    if ((_best != NULL) && _best->terminal())
    {
        return 1;
    }
    else if ((_best != NULL) && _best->inner())
    {
        return _best->arity();
    }
    else
    {
        return 0;
    }
}

// return the best sol for bar i
Run<SIPpointer>* ParserMultibar1bestSIPflat::getBar(size_t i) const
{
    assert(i > 0);
    if (_best)
    {
        return table->best((*_best)[i-1]);
    }
    else
    {
        return NULL;
    }
}

// return the target of the best sol for bar i
SIPpointer ParserMultibar1bestSIPflat::getTarget(size_t i) const
{
    assert(i > 0);
    if (_best)
    {
        return (*_best)[i-1];
    }
    else
    {
        return SIPpointer();
    }
}


Run<SIPpointer>* ParserMultibar1bestSIPflat::parse(double barlen)
{
    assert(wta);
    assert(table);
    assert(segment);
    
    Weight wone = wta->weight_one();
    
    size_t a = std::ceil(segment->rduration() / barlen);
    assert(a >= 1);
    double len = barlen * a;
    assert(len - barlen <= segment->rduration());
    assert(segment->rduration() <= len);
        
    INFO("parsing for {} bars, barlength={}s", a, barlen);
        
    // current top ptr covering thetotal length of the a bars
    SIPpointer top =
        SIPpointer((Environment*) this,
                   State::MetaState(a),
                   _pre,
                   _post,
                   Rational(a),
                   len - segment->rduration()); // realtime extension
        
    // build inner run of size 2
    Run<SIPpointer>* run = new Run<SIPpointer>(wone);
    for (size_t j=1; j <= a; j++)
    {
        // children of run defined as sub-ptr of top
        run->insert(SIPpointer(this,
                               top,
                               a, j,
                               wta->initial()));
    }
    assert(run->arity() == a);

    return run;
}



// tempo in bpm
double ParserMultibar1bestSIPflat::barlen(double tempo, size_t beatsperbar)
{
    return ( (60.0/tempo) * ((double) beatsperbar));
}


// @todo rewrite this member demo
size_t ParserMultibar1bestSIPflat::demo(const std::string _schema_file,
                                        const std::string _input_file,
                                        const std::string output_file,
                                        Rational barbeat)
{
    assert(wta);
    assert(table);
    assert(segment);
    
    return 0;
    
    //    // compute best tree for each bar
    //    //parser->getBestTrees(v);
    //
    //    INFO("time to compute best : {}ms", duration(time_start));
    //    assert(parser->nbbars() == _bars);
    //
    //    // print best tree for each bar
    //    for (size_t i=0; i < parser->nbbars(); i++)
    //    {
    //        SIPpointer p = parser->getTarget(i);
    //        Run<SIPpointer>* r = parser->getBar(i);
    //        std::cout << "|";
    //        std::cout << "(" << i+1 << ") ";
    //        parser->printobestRun(std::cout, parser->table, r);
    //        std::cout << " pre=" << p.pre();
    //        std::cout << " post=" << p.post();
    //        std::cout << " ";
    //        assert(p.interval());
    //        std::cout << *p.interval();
    //        std::cout << std::endl;
    //    }
    //    std::cout << "||" << std::endl;
    //
    //    delete parser; // does not delete schema and input segment
}
           

