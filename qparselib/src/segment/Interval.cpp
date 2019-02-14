//
//  Interval.cpp
//  qparse
//
//  Created by Florent Jacquemard on 06/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "Interval.hpp"


Interval::Interval(const InputSegment* s, Rational me):
mbegin(Rational(0)),
mend(me),
rbegin(s->rbegin()),
rend(s->rend())
{
    assert(s);
    assert(this->sanity_check(s));
}


//Interval::Interval(const InputSegment* s, double rdur, size_t bar):
//bars(bar),
//begin(Rational(0)),
//end(Rational(1)),
//rbegin(s->rbegin()),
//rend(s->rbegin()+rdur)
//{
//    assert(s);
//    assert(rdur > 0);
//    assert(rend <= s->rend());
//}


//Interval::Interval(const InputSegment* s, const Interval& p):
//bars(p.bars+1),
//begin(Rational(0)),
//end(Rational(1)),
//rbegin(p.rend),
//rend(p.rend+p.rduration())
//{
//    assert(s->rbegin() <= rbegin);
//    assert(rend <= s->rend());
//}


// internal use only
Interval::Interval(const InputSegment* s,
                   Rational mb, Rational me,
                   double rb, double re):
mbegin(mb),
mend(me),
rbegin(rb),
rend(re)
{
    assert(s);
    assert(this->sanity_check(s));
}


Interval::Interval(const Interval& p):
mbegin(p.mbegin),
mend(p.mend),
rbegin(p.rbegin),
rend(p.rend)
{
    assert(this->sanity_check());
}


Interval::Interval(Interval* p):
mbegin(p->mbegin),
mend(p->mend),
rbegin(p->rbegin),
rend(p->rend)
{
    assert(p);
    assert(this->sanity_check());
}


bool Interval::sanity_check()
{
    assert(Rational(0) <= mbegin);
    //assert(mbegin <= Rational(1));
    assert(mbegin <= mend);
    //assert(mend <= Rational(1));
//    assert(this->multi() || (mbegin < mend));
//    assert(this->inside() || (mbegin == Rational(0)));
    
    assert(rbegin <= rend);
    
    return true;
}


bool Interval::sanity_check(const InputSegment* s)
{
    sanity_check();
    assert(s);
    assert(s->rbegin() <= rbegin);
    // the interval can start after the input segment's end
    //assert((mduration() == 0) || (rbegin <= s->rend()));
    //assert(rend <= s->rend());
    
    return true;
}


Interval& Interval::operator= (const Interval& p)
{
    if(this != &p)
    {
        mbegin = p.mbegin;
        mend = p.mend;
        rbegin = p.rbegin;
        rend = p.rend;
    };
    return *this;
}


bool Interval::operator==(const Interval& p) const
{
    return ((rbegin == p.rbegin) &&
            (rend   == p.rend)   &&
            (mbegin == p.mbegin) &&
            (mend   == p.mend));
}


//int ::rdate(size_t i) const
//{
//    assert(0 <= i);
//    assert(i < _seg->size());
//    return _seg->rdate(i);
//}


bool Interval::insideBar() const
{
    return (mduration() <= Rational(1));
}


std::ostream& operator<<(std::ostream& o, const Interval& p)
{
    o << "[";
    p.mbegin.printint(o);
    o << "-";
    p.mend.printint(o);
    o << "]";
    o << " [" << p.rbegin << "-" << p.rend << "]";
    
    return o;
}


/// @}
