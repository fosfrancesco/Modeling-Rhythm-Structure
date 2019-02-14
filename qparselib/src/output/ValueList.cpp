//
//  ValueList.cpp
//  qparse
//
//  Created by Florent Jacquemard on 29/07/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "ValueList.hpp"


// empty value list
ValueList::ValueList(Rational len):
_continuation(Rational(0)),
_main(),
_length(len),
_accu(Rational(0)),
_nbevt(0),
_nbgn(0)
{
    assert (len >= Rational(0));
    assert (this->empty());
}


ValueList::ValueList(std::string filename):
_continuation(Rational(0)),
_main(),
_length(Rational(0)),
_accu(Rational(0)),
_nbevt(0),
_nbgn(0)
{
    std::ifstream file;
    
    file.open(filename, std::ios_base::in);
    if(!file.is_open())
        throw "cannot open file";
    
    bool first = true;
    
    for(std::string line; getline(file, line); )
    {
        Rational d;
        
        // skip empty line
        if (line.size() == 0) continue;
        
        std::istringstream in(line);   //make a stream from the line
        if (!(in >> d)) continue; // parse error: skip line
        
        if (first && (d < 0))
        {
            addcont(-d);
            _length += d;
            first = false;
        }
        else
        {
            assert (d >= 0);
            add(d);
            _length += d;
        }
    }
    file.close();
}


ValueList::ValueList(const DurationList& dl):
_continuation(dl._continuation),
_main(dl._main),
_length(dl.length()),
_accu(_length),
_nbevt(0),
_nbgn(0)
{
    assert (_continuation >= Rational(0));
    assert (_length >= Rational(0));

    for (std::list<Rational>::const_iterator i = _main.cbegin();
         i != _main.cend();
         i++)
    {
        if ((*i).null())
            _nbgn++;
        else
            _nbevt++;
    }
}


ValueList::ValueList(const ValueList& rhs):
_continuation(rhs._continuation),
_main(rhs._main),
_length(rhs._length),
_accu(rhs._accu),
_nbevt(rhs._nbevt),
_nbgn(rhs._nbgn)
{
    assert (rhs._continuation >= Rational(0));
    assert (rhs._length >= Rational(0));
    assert (rhs._accu >= Rational(0));
}


ValueList& ValueList::operator=(const ValueList& other)
{
    if (this != &other) // protect against invalid self-assignment
    {
        _continuation = other._continuation;
        _main.assign(other._main.begin(), other._main.end()); // copy of _main
        _length = other._length;
        _accu = other._accu;
        _nbevt = other._nbevt;
        _nbgn = other._nbgn;
    }
    return *this;
}


bool ValueList::empty() const
{
    // _main.empty() && _continuation.null()
    return ( _accu.null() && (_nbgn == 0));
}


//bool ValueList::unit() const
//{
//}


bool ValueList::complete() const
{
    return (_accu == _length);
}


bool ValueList::single_continuation() const
{
    return ((_continuation > Rational(0)) &&
            (_main.empty()));
}


bool ValueList::event() const
{
    return  (_continuation.null() &&
             (_nbevt == 1));
}


bool ValueList::single_event() const
{
    return  (event() && (_nbevt == 1));
}


// used only for terminal runs
void ValueList::add(Rational q)
{
    assert (q >= Rational(0));
    
    if (q.null())
        _nbgn++;
    else
        _nbevt++;

    _accu += q;
    assert (_accu <= _length);
    
    _main.push_back(q);
}


void ValueList::addcont(Rational q)
{
    assert (q >= Rational(0));
    assert (_continuation >= Rational(0));
    
    _accu += q;
    assert (_accu <= _length);

    _continuation += q;
}


Rational ValueList::front() const
{
    assert (_continuation.null());
    assert (! _main.empty());
    
    return _main.front();    
}


Rational ValueList::pop()
{
    assert (_continuation.null());
    assert (! _main.empty());

    Rational first = _main.front();
    if (first.null())
        _nbgn--;
    else
        _nbevt--;
    _accu -= first;
    _main.pop_front();
    
    return first;
}


Rational ValueList::popcont()
{
    Rational first = _continuation;

    _accu -= first;
    _continuation = Rational(0);

    return first;
}


void ValueList::popcont(Rational q)
{
    assert (q <= _continuation);
    _accu -= q;
    _continuation -= q;
}


std::ostream& operator<<(std::ostream& o, const ValueList& l)
{
    o << '[';
    assert(l._continuation >= Rational(0));
    if (l._continuation > Rational(0))
    {
        o << " " << -(l._continuation);
    }
    for(std::list<Rational>::const_iterator i = l._main.cbegin();
        i != l._main.cend();
        ++i)
    {
        assert (*i >= 0);
        o << " " << *i;
    }
    o << " ]";
    o << (l.complete()?"":"*");

    return o;
}


/// @}
