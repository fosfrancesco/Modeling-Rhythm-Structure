//
//  PointedRT.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "PointedRT.hpp"


PointedRhythmTree::PointedRhythmTree():
RhythmTree(),
events()
{}

PointedRhythmTree::PointedRhythmTree(label_t lab):
RhythmTree(lab),
events()
{}


PointedRhythmTree::PointedRhythmTree(const RhythmTree* t,
                                     const InputSegment* is,
                                     size_t i):
RhythmTree(),
events()
{
    assert(t);
    assert(is);
    assert(i < is->size() || t->continuation());
    assert(_children.empty());

    // _label has default value
    _next = i;
    
    if (t->terminal())
    {
        _label = t->label();
        // _children is empty
        assert(Label::nbEvents(_label) >= 0);
        _next += Label::nbEvents(_label);
        assert(_next <= is->size());
        for (size_t j = i; j < _next; j++)
        {
            events.push_back(is->event(j));
            //events.push_back(is->event(j));
        }
    }
    else
    {
        for (size_t j = 0; j < t->arity(); j++)
        {
            PointedRhythmTree* pt =
                new PointedRhythmTree(t->child(j), is, _next);
            _children.push_back(pt);
            _next = pt->_next;
            // events is empty
        }
    }
}


PointedRhythmTree::~PointedRhythmTree()
{
    // recursive destruction
    for (size_t i = 0; i < _children.size(); ++i)
    {
        delete _children[i];
    }
    _children.clear(); //destroy the content
    
    // do not delete events (done at deletion of input segment)
    events.clear();
}



/// @}
