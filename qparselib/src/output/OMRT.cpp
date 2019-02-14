//
//  OMRT.cpp
//  qparse
//
//  Created by Florent Jacquemard on 31/07/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "OMRT.hpp"

// grace note
OMRhythmTree::OMRhythmTree():
_label(Rational(0)),
_tied(false),
_children()
{ }


OMRhythmTree::OMRhythmTree(Rational dur, bool tied):
_label(dur),
_tied(tied),
_children()
{ }


OMRhythmTree::OMRhythmTree(const RhythmTree* t, Rational dur):
_children(),
_label(dur)
{
    assert (t);
    
    if (t->terminal())
    {
        // continuation = tie
        if (t->continuation())
        {
            _tied = true;
        }
        // single note
        else if (t->single_event())
        {
            _tied = false;
        }
        // grace notes are ignored
        else
        {
            WARN("grace notes not supported in OMRT");
            _tied = false;
            size_t g = t->nbgn();
            // create a non-terminal OMRT on purpose
            for (size_t i = 0; i < g; i++)
                add(new OMRhythmTree());
            // add one event after grace notes (not tied)
            add(new OMRhythmTree(Rational(1), false));
        }
    }
    else // (t->inner())
    {
        size_t a = t->arity();
        Rational len = Rational(0);
        RhythmTree* last = NULL;
        size_t state = 0;  // FSM with 4 states
        
        _tied = false;
        
        for (size_t i = 0; i < a; i++)
        {
            RhythmTree* st = t->child(i);
            assert (st);
            
            switch (state)
            {
                // starting state
                case 0:
                    assert (len.null());
                    assert (last == NULL);
                    if (st->inner())
                    {
                        add(new OMRhythmTree(st));
                        state = 0;
                    }
                    else if (st->terminal() && st->continuation())
                    {
                        len = Rational(1); // start to accumulate sibling
                        last = st;
                        state = 1; //2
                    }
                    else if (st->terminal() && st->single_event())
                    {
                        len = Rational(1); // start to accumulate sibling
                        last = st;
                        state = 1;
                    }
                    else  // grace notes + event:
                          // create a sub-OMRT (causes a warning)
                    {
                        len = Rational(1);
                        last = st;
                        state = 1; //3
                    }
                    break;
                // sum up siblings tied together
                case 1:
                    assert (len > Rational(0));
                    assert (last);
                    if (st->inner())
                    {
                        add(new OMRhythmTree(last, len));
                        add(new OMRhythmTree(st));
                        len = Rational(0);
                        last = NULL;
                        state = 0;
                    }
                    else if (st->terminal() && st->continuation())
                    {
                        len += Rational(1);
                        state = 1;
                    }
                    else if (st->terminal() && st->single_event())
                    {
                        add (new OMRhythmTree(last, len));
                        len = Rational(1);
                        last = st;
                        state = 1;
                    }
                    else // grace notes + event
                    {
                        add (new OMRhythmTree(last, len));
                        len = Rational(1);
                        last = st;
                        state = 1;
                    }
                    break;
                // should not happen
                default:
                {
                    ERROR ("construction OMRhythmTree: unknown state");
                    assert (false);
                }
            } // end switch case
        } // end for loop on children

        // add pending sibling
        if (state == 1)
        {
            assert (len >= Rational(0));
            assert (last);
            add (new OMRhythmTree(last, len));
        }
        assert (_children.size() <= a);
    } // end case t inner
}


OMRhythmTree::~OMRhythmTree()
{
    // recursive destruction
    for (std::vector<OMRhythmTree*>::iterator i = _children.begin();
         i != _children.end(); ++i)
    {
        delete *i;
    }
    _children.clear(); //destroy the content
}


size_t OMRhythmTree::size() const
{
    return (_children.size());
}


OMRhythmTree* OMRhythmTree::child(size_t i) const
{
    assert (i < _children.size());
    
    return _children[i];
}


void OMRhythmTree::add(OMRhythmTree* t)
{
    assert(t);
    assert (! tie());

    _children.push_back(t);
}


string OMRhythmTree::to_string() const
{
    string res = "";
    
    if (inner())
        res += "<";

#if QP_PLATFORM == PLATFORM_DARWIN
    res += std::to_string(_label.numerator());
#elif QP_PLATFORM == PLATFORM_LINUX
    res += patch::to_string(_label.numerator());
#endif
    if (!_label.integral())
    {
        res += "/";
#if QP_PLATFORM == PLATFORM_DARWIN
        res += std::to_string(_label.denominator());
#elif QP_PLATFORM == PLATFORM_LINUX
        res += patch::to_string(_label.denominator());
#endif
    }

    if (_tied)
    {
        assert (leaf());
        // tied fractional duration not supported by OM RT
        assert (_label.integral());
        res += ".0";
    }

    if (inner())
    {
        size_t a = this->size();
        assert (a > 0);

        res += " (";
        for (size_t i = 0; i < a; i++)
        {
            res += _children[i]->to_string();
            if (i < a-1) { res += " "; }
        }
        res += ")";
        res += ">";
    }
    return res;
}


std::ostream& operator<<(std::ostream& o, const OMRhythmTree& t)
{
    o << t.to_string();
    
    return o;
}


/// @}
