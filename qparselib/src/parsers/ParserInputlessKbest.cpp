//
//  ParserInputlessKbest.cpp
//  qparse
//
//  Created by Florent Jacquemard on 09/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "ParserInputlessKbest.hpp"


ParserInputlessKbest::ParserInputlessKbest(WTA* a, bool ordering):
Parser<SKpointer>(a),
table(new Table<SKpointer,
                Krecord<SKpointer>,
                SKpointerHasher>(this,
                          ordering?weightMin<SKpointer>:weightMax<SKpointer>))
{ }


ParserInputlessKbest::~ParserInputlessKbest()
{
    assert(table);
    delete(table);
}


size_t ParserInputlessKbest::addRuns(Atable<SKpointer>* table,
                                     const SKpointer& p,
                                     Record<SKpointer>* it)
{
    return addWTARuns(table, p, it);
}


RhythmTree* ParserInputlessKbest::best(size_t k)
{
    assert(wta);
    assert(table);
    return(table->bestTree(SKpointer(wta->initial(), k)));
}


Weight ParserInputlessKbest::bestWeight(size_t k)
{
    assert(wta);
    assert(table);
    Run<SKpointer>* r = table->best(SKpointer(wta->initial(), k));
    
    if (r)
    {
        return r->weight;
    }
    else
    {
        return Weight(); // unknown weight
    }
}


void ParserInputlessKbest::printBest(std::ostream& o, size_t k) const
{
    assert(wta);
    assert(table);
    assert(k > 0);
    
    SKpointer p(wta->initial(), k);
    printobest(o, table, p);
}


size_t ParserInputlessKbest::demo(const string _schema_file, size_t _k)
{
    assert(wta);
    assert(table);
    INFO("compute {} best trees for {}", _k, _schema_file);
    
    clock_t time_start = clock();
    
    for (size_t i = 1; i <= _k; i++)
    {
        //parser->print_best(std::cout, i);
        
        std::cout << i << "-best: ";
        this->printBest(std::cout, i);
        std::cout << std::endl;
    }
    
    INFO("time to compute {} bests : {}ms", _k, duration(time_start));
    return 0;
}


