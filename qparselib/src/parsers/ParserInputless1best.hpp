//
//  ParserInputless1best.hpp
//  qparse
//
//  Created by Florent Jacquemard on 08/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// running environement for computing the 1-best tree of a WTA
// no input segment


#ifndef ParserInputless1best_hpp
#define ParserInputless1best_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "PtrS.hpp"
#include "Record.hpp"
#include "Brecord.hpp"
#include "Table.hpp"
#include "Parser.hpp"
#include "RT.hpp"


class ParserInputless1best : public Parser<Spointer>
{
public:
    Table<Spointer, Brecord<Spointer>, SpointerHasher>* table;

    // ordering 0 for min, 1 for max
    ParserInputless1best(WTA* a, bool ordering);
    
    virtual ~ParserInputless1best();
    
//    virtual Atable<Spointer>* table() const { return _table; };
    
    virtual size_t addRuns(Atable<Spointer>*,
                         const Spointer&,
                         Record<Spointer>*);
    
    // @todo TBR (mv to script)
    RhythmTree* best();
    Weight bestWeight();

    // @todo TBR (mv to script)
    virtual void printBest(std::ostream&) const;
    
    size_t demo(const string schema_file);

protected:
    
};





#endif /* ParserInputless1best_hpp */
