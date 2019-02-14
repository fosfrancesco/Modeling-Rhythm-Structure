//
//  ParserInputless1best.cpp
//  qparse
//
//  Created by Florent Jacquemard on 08/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "ParserInputless1best.hpp"



ParserInputless1best::ParserInputless1best(WTA* a, bool ordering):
Parser<Spointer>(a),
table(new Table<Spointer,
      Brecord<Spointer>,
      SpointerHasher>(this, ordering?weightMin<Spointer>:weightMax<Spointer>))
{ }


ParserInputless1best::~ParserInputless1best()
{
    assert(table);
    delete(table);
}


size_t ParserInputless1best::addRuns(Atable<Spointer>* table,
                                     const Spointer& p,
                                     Record<Spointer>* it)
{
    return addWTARuns(table, p, it);
}



RhythmTree* ParserInputless1best::best()
{
    assert(wta);
    assert(table);
    return(table->bestTree(Spointer(wta->initial())));
}


Weight ParserInputless1best::bestWeight()
{
    assert(wta);
    assert(table);
    Run<Spointer>* r = table->best(Spointer(wta->initial()));
    
    if (r)
    {
        return r->weight;
    }
    else
    {
        return Weight(); // unknown weight
    }
}


void ParserInputless1best::printBest(std::ostream& o) const
{
    assert(wta);
    assert(table);
    
    const Spointer p(wta->initial());
    printobest(o, this->table, p);
}


size_t ParserInputless1best::demo(const string _schema_file)
{
    assert(wta);
    assert(table);
    INFO("best tree for {}", _schema_file);
    
    clock_t time_start = clock();
    
    //this->print_best(std::cout);
    Spointer p(this->wta->initial());
    
    std::cout << "1-best: ";
    this->printobest(std::cout, this->table, p);
    
    INFO("time to compute best : {}ms", duration(time_start));
    return 0;
}


