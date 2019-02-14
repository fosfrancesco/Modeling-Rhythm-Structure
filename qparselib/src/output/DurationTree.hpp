//
//  DurationTree.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#ifndef DurationTree_hpp
#define DurationTree_hpp

#include <stdio.h>

#include "init.hpp"
#include "trace.hpp"
#include "ValueList.hpp"


/// a tree container for duration lists.
/// to avoid recomputation of division of duration lists.
class DurationTree
{
public:
    DurationTree(Rational len):top(Rational(len))
    { assert (len >= Rational(0)); };
    
    DurationTree(const DurationList& d);
    
    ~DurationTree();
    
    ValueList top;
    
    DurationTree* sub(size_t, size_t);
    
    friend std::ostream& operator<<(std::ostream&, const DurationTree&);
    
private:
    
    /// every entry in this map associate to
    /// an arity n a partition a1,...,an of this DurationList
    std::map<size_t, std::vector<DurationTree*>> _children;
    
};


#endif /* DurationTree_hpp */


/// @}
