//
//  DurationTree.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "DurationTree.hpp"


DurationTree::~DurationTree()
{
    // recursive destruction
    for (std::map<size_t, std::vector<DurationTree*>>::iterator i = _children.begin();
         i != _children.end(); ++i)
    {
        std::vector<DurationTree*> v = i->second;
        for (std::vector<DurationTree*>::iterator j = v.begin();
             j != v.end(); ++j)
            delete *j;
    }
    _children.clear(); //destroy the content
    // the passed segment is not deleted
}

DurationTree::DurationTree(const DurationList& d):top(d)
{ }

DurationTree* DurationTree::sub(size_t a, size_t n)
{
    assert (a > 1);
    assert (n < a);
    assert (! top.empty());
    assert (! top.single_continuation());
    assert (! top.single_event());
    assert (! top.event());
    
    //WARN("sub({},{}) of {}", a, n, top);
    
    // creates an empty vector if there is none associated to a
    //vector<DurationTree*>& v = _children[a];
    std::pair<std::map<size_t, std::vector<DurationTree*>>::iterator, bool> ret =
    _children.insert(std::pair<size_t, std::vector<DurationTree*>>(a, std::vector<DurationTree*>()));
    std::vector<DurationTree*>& v = ret.first->second;

    // newly created vector for a, fill it
    if (ret.second)    //if (v.size() == 0)
    {
        // length of each part of the division in a parts
        Rational len = top.length()/Rational(a);
        // copy
        ValueList rest(top);
        int i=1;

        while (! rest.empty())
        {
            assert (i <= a);
            // we construct duration subtree by hand
            DurationTree* dt = new DurationTree(len);
            assert (dt->top._accu.null());
            assert (dt->top._main.empty());
            assert (dt->_children.empty());
            
        
            //WARN("{}/{} : rest={}",i,a,rest);

            if (rest.cont() >= len)
            {
                dt->top.addcont(len);
                rest.popcont(len);
            }
            else //rest._continuation < len
            {
                dt->top.addcont(rest.cont());
                rest.popcont();
                assert (! rest._main.empty());
                Rational next = rest.front();
                
                while (dt->top._accu + next < len)
                {
                    dt->top.add(next);
                    rest.pop();
                    assert (! rest._main.empty());
                    next = rest.front();
                }
                if (dt->top._accu + next == len)
                {
                    dt->top.add(next);
                    rest.pop();
                }
                else // top._accu + next > len
                {
                    assert (dt->top._accu < len);
                    // the next is split in 2 parts
                    // part 1 in current sub
                    Rational part1 = len - dt->top._accu;
                    // part 2 continuation of next sub
                    Rational part2 = dt->top._accu + next - len;

                    dt->top.add(part1);
                    // part 2 as continuation in next sub
                    assert (rest.cont().null());
                    assert (! rest._main.empty());
                    rest.pop();
                    rest.addcont(part2);
                }
            }
            assert (dt->top._accu == len);
            v.push_back(dt);
            i++;
        }
        TRACE("sub({}/{}) of {}: {} [a={}:new]",
              n, a,
              *this,
              *(v[n]),
              a);
    }
    // a already exists in table
    else
    {
        TRACE("sub({}/{}) of {}: {} [a={}:known]",
              n, a,
              *this,
              *(v[n]),
              a);
        assert (v.size() == a);
    }
    assert (v.size() == a);
    
    return v[n];
}


std::ostream& operator<<(std::ostream& o, const DurationTree& t)
{
    o << t.top;
    return o;
}


/// @}
