//
//  Parser1barKbestSKIP.cpp
//  squant
//
//  Created by Florent Jacquemard on 14/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "Parser1barKbestSKIP.hpp"


Parser1barKbestSKIP::Parser1barKbestSKIP(WTA* a,
                                       InputSegment* s,
                                       bool ordering):
Parser<SKIPpointer>(a, s),
table(new Table<SKIPpointer,
       Krecord<SKIPpointer>,
       SKIPpointerHasher>(this,
                          ordering?
                          weightMin<SKIPpointer>:
                          weightMax<SKIPpointer>))
{
    assert(s);
}


Parser1barKbestSKIP::~Parser1barKbestSKIP()
{
    assert(table);
    delete(table);
    // interval heap deleted by ~Environment
}


size_t Parser1barKbestSKIP::addRuns(Atable<SKIPpointer>* table,
                                    const SKIPpointer& p,
                                    Record<SKIPpointer>* it)
{
    assert(p.has_S());
    assert(State::isWTA(p.state()));
    
    return addWTARuns(table, p, it);
}


RhythmTree* Parser1barKbestSKIP::bestTree(size_t k,
                                          pre_t pre,
                                          pre_t post) const
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);

    SKIPpointer p(input,
                  wta->initial(),
                  pre,
                  post,
                  Rational(1),
                  k);
    
    assert(segment);
    assert(p.interval());
    if (! p.interval()->aligned())
    {
        p.interval()->align(input->segment, 0);
    }
    
    return table->bestTree(p); // mdur = 1 bar
}


Run<SKIPpointer>* Parser1barKbestSKIP::bestRun(size_t k,
                                               pre_t pre,
                                               pre_t post) const
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);

    SKIPpointer p(input,
                  wta->initial(),
                  pre,
                  post,
                  Rational(1),
                  k);
    
    assert(segment);
    assert(p.interval());
    if (! p.interval()->aligned())
    {
        p.interval()->align(input->segment, 0);
    }
    
    return table->best(p);
}


Weight Parser1barKbestSKIP::bestWeight(size_t k,
                                       pre_t pre,
                                       pre_t post) const
{
    Run<SKIPpointer>* r = bestRun(k, pre, post);
    if (r)
    {
        return r->weight;
    }
    else
    {
        return Weight(); // unknown weight
    }
}


void Parser1barKbestSKIP::printBest(std::ostream& o,
                                    size_t k,
                                    pre_t pre,
                                    pre_t post) const
{
    Run<SKIPpointer>* r = bestRun(k, pre, post);
    printobestRun(o, table, r);
}


size_t Parser1barKbestSKIP::demo(const string _schema_file,
                                const string _input_file,
                                pre_t _pre,
                                pre_t _post,
                                size_t _k)
{
    assert(wta);
    assert(table);
    assert(input);
    assert(input->segment);

    INFO("compute {} best trees for {} and input in {}",
         _k, _schema_file, _input_file);
    
    clock_t time_start = clock();
    
    for (size_t i = 1; i <= _k; i++)
    {
        //parser->print_best(std::cout, i);
        
        SKIPpointer p(input,
                      this->wta->initial(),
                      _pre,
                      _post,
                      Rational(1),
                      i);
        
        assert(p.interval());
        if (! p.interval()->aligned())
        {
            p.interval()->align(input->segment, 0);
        }
        
        std::cout << i << "-best: ";
        this->printobest(std::cout, this->table, p);
    }
    
    INFO("time to compute bests : {}ms", duration(time_start));

    return 0;
}

