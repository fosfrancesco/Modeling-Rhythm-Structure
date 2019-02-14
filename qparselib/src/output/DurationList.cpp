//
//  DurationList.cpp
//  qparse
//
//  Created by Florent Jacquemard on 02/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "DurationList.hpp"

// empty duration list
DurationList::DurationList():
_continuation(Rational(0)),
_main(),
_sum(0.0),
_summed(0),
_dummy(1),
_state(0)
{
    assert (this->empty());
}


DurationList::DurationList(const DurationList& l):
_continuation(l._continuation),
_main(l._main),
_sum(l._sum),
_summed(l._summed),
_dummy(l._dummy),
_state(l._state)
{
    assert (l._continuation >= Rational(0));
}


DurationList& DurationList::operator=(const DurationList& other)
{
    if (this != &other) // protect against invalid self-assignment
    {
        _continuation = other._continuation;
        _sum = other._sum;
        _summed = other._summed;
        _dummy = other._dummy;
        _state = other._state;
        
        _main.assign(other._main.begin(), other._main.end()); // copy of _main
    }
    return *this;
}


DurationList::DurationList(const DurationList& l, Rational q):
_main(),
_sum(l._sum * q),
_summed(l._summed),
_dummy(l._dummy),
_state(l._state)
{
    assert (l._continuation >= Rational(0));

    _continuation = l._continuation * q;
    for(std::list<Rational>::const_iterator i = l._main.begin(); i != l._main.end(); ++i)
    {
        _main.push_back((*i)*q);
    }
}


DurationList::DurationList(std::string filename):
_continuation(Rational(0)),
_main(),
_sum(0.0),
_summed(1), // TBC
_dummy(0),
_state(0)
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
            first = false;
        }
        else
        {
            assert (d >= 0);
            add(d);
        }
    }
    file.close();
}


bool DurationList::empty() const
{
    assert ((_state != 0) || (_continuation.null() && _main.empty()));
    assert ((_state != 7) || (_continuation.null() && _main.empty()));
    
    return ((_state == 0) || (_state == 7));
}


bool DurationList::_check_empty() const
{
    return (_summed + _dummy == 1) &&
        _continuation.null() && _main.empty();
}


bool DurationList::complete() const
{
    return (_state == 1) || (_state == 3) || (_state == 4) || (_state == 6) || (_state == 7);
}

            
bool DurationList::_check_complete() const
{
    return (_sum == _summed);
}


bool DurationList::unit() const
{
    return (_state == 1) || (_state == 3) || (_state == 4);
}


bool DurationList::_check_unit() const
{
    if (empty())
        return false;
    
    assert (_continuation >= Rational(0));

    if (_continuation == Rational(1))
    {
        assert (_main.size() == 0);
        return true;
    }
    
    if (_continuation.null())
    {
        for (std::list<Rational>::const_iterator i = _main.begin();
             i != _main.end(); i++)
        {
            // grace note
            if ((*i).null())
                continue;
            // single event in interval
            else if ((*i) == Rational(1))
            {
                assert (++i == _main.end());
                return true;
            }
            // shorter event
            else
                return false;
        }
    }
    
    return false;
}

bool DurationList::single_continuation() const
{
    return (_state == 1);
}

bool DurationList::_check_single_continuation() const
{
    return (( _main.empty()) &&
            (! _continuation.null()) &&
            (_continuation == Rational(_summed)));
}

bool DurationList::single_event() const
{
    return (_state == 3);
}

bool DurationList::_check_single_event() const
{
    return ((_continuation.null()) &&
            (_main.size() == 1) &&
            (_main.front() == Rational(_summed)));
}

bool DurationList::event() const
{
    return (_state == 4);
}

bool DurationList::_check_event() const
{
    if ( _continuation.null() && (_main.size() >= 1))
    {
        // last element in main
        std::list<Rational>::const_reverse_iterator i = _main.crbegin();
        assert (i != _main.crend());
        assert (*i >= Rational(0));
        // sequence of grace notes followed by non null event
        if ( *i == Rational(_summed) )
            ++i;
        else
            return false;

        // other elements in main are 0
        while (i != _main.crend())
        {
            assert (*i >= Rational(0));
            if ( *i > Rational(0) ) return false;
            ++i;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool DurationList::_check_gracenotes() const
{
    if ( _continuation.null() && (_main.size() >= 1))
    {
        // sequence of grace notes
        for (std::list<Rational>::const_iterator i = _main.cbegin();
             i != _main.cend();
             ++i)
        {
            assert (*i >= Rational(0));
            if ( *i > Rational(0) ) return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}


bool DurationList::_check_state() const
{
    
    switch (_state){
        case 0:
        case 7:
            return _check_empty();
            break;
        case 1:
            return _check_single_continuation();
            break;
        case 2:
            return _check_gracenotes();
            break;
        case 3:
            return _check_single_event();
            break;
        case 4:
            return _check_event();
            break;
        case 5:
            return (! _check_complete());
            break;
        case 6:
            return _check_complete();
            break;
    }
    
    return (true);
}


size_t DurationList::nbgn() const
{
    assert ( _continuation.null());
    assert (_main.size() >= 1);
    std::list<Rational>::const_reverse_iterator i = _main.crbegin();
    assert (i != _main.crend());
    size_t res = 0;
    assert (*i > 0); // last element is the event
    // previouses are the grace notes
    while (i != _main.crend())
    {
        assert ((*i).null());
        ++res;
        ++i;
    }
    return res;        
}


Rational DurationList::_compute_length() const
{
    Rational sum = _continuation;
    assert (sum >= Rational(0));
    for(std::list<Rational>::const_iterator i = _main.cbegin();
        i != _main.cend(); ++i)
    {
        assert (*i >= Rational(0));
        sum += *i;
    }
    return sum;
}


Rational DurationList::length() const
{
    assert (_continuation >= Rational(0));

    return (_sum);
}


// used only for terminal runs
void DurationList::add(Rational q)
{
    assert (q >= Rational(0));
    assert (q <= Rational(1));
    assert (_summed + _dummy == 1);
    
    if ((_summed == 0) && (_dummy == 1))
    {
        _summed = 1;
        _dummy = 0;
    }
    else
    {
        assert(_summed == 1);
        assert(_dummy == 0);
    }
    
    Rational tmp_sum = _sum + q;

    assert (tmp_sum >= 0);
    assert (tmp_sum <= 1);  // if (tmp_sum > 1) return false;
    
    // complete cases
    // we cannot add duration, even if 0
    // because we assume grace notes always before note
    assert(! complete());
    
    switch (_state){
        case 0:
        case 7:
            if (q == Rational(0))
                _state = 2;
            else if (q == Rational(1))
                _state = 3;
            else
                _state = 5;
            break;
        case 1:
        case 3:
        case 4:
        case 6:
            // we can add no grace note here (terminal node)
            assert (false); // return false
            break;
        case 2:
            if (q == Rational(0))
                _state = 2;
            else if (q == Rational(1))
                _state = 4;
            else
                _state = 5;
            break;
        case 5:
            if (tmp_sum < 1)
                _state = 5;
            else
                _state = 6;
            break;
    }

    
    _sum = tmp_sum;
    _main.push_back(q);

    // @todo TBR
    assert(_check_state());
    // return true
}


void DurationList::addcont(Rational q)
{
    assert (Rational(0) <= q);
    assert (q <= Rational(1));
    assert (_summed + _dummy == 1);
    
    if ((_summed == 0) && (_dummy == 1))
    {
        _summed = 1;
        _dummy = 0;
    }
    else
    {
        assert(_summed == 1);
        assert(_dummy == 0);
    }

    assert (Rational(0) <= _continuation);
    assert (_continuation <= Rational(1));

    Rational tmp_sum = _sum + q;
    
    assert (0 <= tmp_sum);
    assert (tmp_sum <= 1);    //  if (tmp_sum > 1) return false;

    switch (_state){
        case 0:
        case 7:
            if (q == Rational(1))
                _state = 1;
            else
                _state = 5;
            break;
        // complete cases
        // we cannot add duration
        case 1:
        case 3:
        case 4:
        case 6:
            assert (q == Rational(0));  // return false;
            break;
        case 2:
            assert (q < Rational(1)); // return false;
            _state = 5;
            break;
        case 5:
            if (tmp_sum < 1)
                _state = 5;
            else
                _state = 6;
            break;
    }
    
    _continuation += q;
    _sum = tmp_sum;

    assert (_continuation <= 1);
    //  @todo TBR
    assert(_check_state());
    //return true;
}


DurationList& DurationList::operator+=(const DurationList& rhs)
{
    assert (Rational(0) <= _continuation);
    assert ( Rational(0) <= rhs._continuation);
    assert (rhs._summed + rhs._dummy == 1);
    assert(empty() || complete());
    
    
    // (_state == 1) || (_state == 3) || (_state == 4) || (_state == 6);
    // or concatenate 2 empty lists : TBC
    assert(rhs.complete() || (this->empty() && rhs.empty()));
    
    unsigned int _state_original = _state;
    
    // update state
    // note that the new d.l. is complete
    switch (_state){
        case 0:
            assert(_main.empty());
            switch (rhs._state){
                case 0:
                    _state = 7;
                    break;
                default:
                    _state = rhs._state;
                    break;
            }
            break;
        case 7:
            assert(_main.empty());
            switch (rhs._state){
                case 0:
                    _state = 7;
                    break;
                default:
                    _state = rhs._state;
                    break;
            }
            break;
        case 1:
            assert(_main.empty());
            assert(_continuation == _summed);
            switch (rhs._state){
                case 0:
                    _state = 1;
                    break;
                case 1:
                    _state = 1;
                    break;
                case 3:
                case 4:
                case 6:
                    _state = 6;
                    break;
            }
            break;
        case 3:
            assert(! _main.empty());
            switch (rhs._state){
                case 1:
                    _state = 3;
                    break;
                case 3:
                case 4:
                case 6:
                    _state = 6;
                    break;
            }
            break;
        case 4:
            assert(! _main.empty());
            switch (rhs._state){
                case 1:
                    _state = 4;
                    break;
                case 3:
                case 4:
                case 6:
                    _state = 6;
                    break;
            }
            break;
        case 6:
            assert(! _main.empty());
            _state = 6;
            break;
    }

    if (_main.empty())
    {
        _continuation += rhs._continuation;
    }
    else
    {
        std::list<Rational>::reverse_iterator last = _main.rbegin();
        assert (last != _main.rend());
        *last += rhs._continuation;
    }
    
    _main.insert(_main.end(), rhs._main.begin(), rhs._main.end());
    _sum += rhs._sum;
    
    if (_state_original == 0)
    {
        assert(_summed == 0);
        assert(_dummy == 1);
        assert(_state != 0);
        _dummy = 0;
    }
    if (rhs._state == 0)
    {
        _dummy++;
    }
    else
    {
        _summed++;
    }
    
    // @todo TBR
    assert(_check_state());

    return *this;
}


//void DurationList::mult(Rational q)
//{
//    assert (_continuation >= Rational(0));
//    assert (q >= Rational(0));
//
//    _continuation *= q;
//    // multiply every element of _main in place
//    for(Rational &x : _main) { x *= q; }
//}


void DurationList::normalize()
{
    // only dummies were concatenated - should not happen
    if (_summed == 0)
    {
        assert(1 <= _dummy);
        assert(_sum == Rational(0));
        assert(empty());
        assert(_state == 7);
        _dummy = 1;
    }
    else
    {
        assert(1 <= _summed);
        assert(_sum == Rational(_summed));
        assert(_state != 0);
        assert(_state != 7);

        _continuation /= _summed;
        // normalize every element of _main in place
        for(Rational &x : _main)
        {
            x /= _summed;
        }
        _sum = Rational(1);
        _summed = 1;
        _dummy = 0;
        // note that _state is unchanged
    }
}


std::ostream& operator<<(std::ostream& o, const DurationList& l)
{
    o << '[';
    assert(0 <= l._continuation);
    if (0 < l._continuation)
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
#ifdef DEBUG_ON
    o << "_" << l._state;
    //o << l._sum << "/" << l._summed;
#endif

    return o;
}


/// @}
