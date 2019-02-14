//
//  Parser1bar1bestSIP.cpp
//  qparse
//
//  Created by Florent Jacquemard on 09/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "Parser1bar1bestSIP.hpp"



Parser1bar1bestSIP::Parser1bar1bestSIP(WTA* a, InputSegment* s, bool ordering):
Parser<SIPpointer>(a, s),
table(new Table<SIPpointer,
                Brecord<SIPpointer>,
                SIPpointerHasher>(this,
                                  ordering?weightMin<SIPpointer>:
                                           weightMax<SIPpointer>))
{
    assert(s);
}


Parser1bar1bestSIP::~Parser1bar1bestSIP()
{
    assert(table);
    delete(table);
    // interval heap deleted by ~Environment
}


size_t Parser1bar1bestSIP::addRuns(Atable<SIPpointer>* table,
                                   const SIPpointer& p,
                                   Record<SIPpointer>* it)
{
    assert(p.has_S());
    assert(State::isWTA(p.state()));

    return addWTARuns(table, p, it);
}


RhythmTree* Parser1bar1bestSIP::bestTree(pre_t pre, pre_t post) const
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);

    SIPpointer p(input, // Environment*
                 wta->initial(),
                 pre,
                 post,
                 Rational(1));

    assert(segment);
    assert(p.interval());
    p.interval()->align(input->segment, 0);
    
    return table->bestTree(p); // mdur = 1 bar
}


Run<SIPpointer>* Parser1bar1bestSIP::bestRun(pre_t pre,
                                             pre_t post) const
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);

    SIPpointer p(input,
                 wta->initial(),
                 pre,
                 post,
                 Rational(1));
    p.interval()->align(input->segment, 0);

    return table->best(p);
}


Weight Parser1bar1bestSIP::bestWeight(pre_t pre, pre_t post) const
{
    Run<SIPpointer>* r = bestRun(pre, post);
    if (r)
    {
        return r->weight;
    }
    else
    {
        return Weight(); // unknown weight
    }
}


void Parser1bar1bestSIP::printBest(std::ostream& o, pre_t pre, pre_t post) const
{
   
    Run<SIPpointer>* r = bestRun(pre, post);
    printobestRun(o, table, r);
}


size_t Parser1bar1bestSIP::demo(const string _schema_file,
                                const string _input_file,
                                pre_t _pre,
                                pre_t _post)
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);
    INFO("compute best tree for {} and input in {}", _schema_file, _input_file);
    
    clock_t time_start = clock();
    
    // parser->print_best(std::cout);
    
    SIPpointer p(input,
                 this->wta->initial(),
                 _pre,
                 _post,
                 Rational(1));
    
    p.interval()->align(input->segment, 0);
    this->printobest(std::cout, this->table, p);
    
    INFO("time to compute best : {}ms", duration(time_start));
    return 0;
}

