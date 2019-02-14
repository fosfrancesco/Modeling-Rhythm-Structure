//
//  Rune.tpp
//  squant
//
//  Created by Florent Jacquemard on 01/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//


template<class P>
Run<P>::Run():
weight(),          // unknown weight
_children(),       // no children
duration(),        // empty duration list
_first_partialortoupdate(0),
_meta(false)
{
    assert (this->null());
}


template<class P>
Run<P>::Run(Weight w):
weight(w),
_children(),       // no children yet
duration(),        // empty duration list
_first_partialortoupdate(0),
_meta(true)
{
    assert(! w.unknown());
}


// WTA (inside-the-bar) run
template<class P>
Run<P>::Run(Environment* env,
            const P& p,
            const Transition& t):
weight(),
duration(),
_children(),
_transition(&t),
_first_partialortoupdate(0),
_meta(false)
{
    assert(env);
    // head ptr must have state to be compatible with transition
    assert(p.has_S());
    assert(State::isWTA(p.state()));
    
    // leaf transition
    if (t.terminal())
    {
        // label of trandition is assumed abstract
        assert(Label::abstract(t.label()));
        assert(p.compatible(t.label(), true)); // abstract label
        assert(env);
        // segment might be NULL
        weight = p.terminalWeight(env->segment, t);
        assert(! weight.unknown());
        //assert(! weight.zero()); //  compatibility is precondition

        // at this point, a concrete label must be computable
        // i.e. p is enough instanciated (pre value)
        label_t clabel = p.label(t);
        // should be equivalent to p.compatible(t.label(), true)
        assert(Label::abstract(t.label(), clabel));
        
        _init_duration_list(clabel);
        
        // fake ptr containing only the concrete label symbol
        _children.emplace_back(clabel);
        // children is singleton vector
        assert(_children.size() == 1);
        
        _first_partialortoupdate = 1;  // run is complete!
        assert(this->terminal());
        assert(this->complete());
    }
    // inner transition: fill _children with pointers to 1-bests
    // @todo suppr. tweight and init directly weight with tr.weight().clone()?
    else
    {
        assert(t.inner());
        assert(p.divisible());
        size_t a = t.size();
        assert(a > 1);
        weight = p.innerWeight(t);
        assert(! weight.unknown());
        assert(! weight.zero());
        
        for (size_t i = 0; i < a; i++)
        {
            _children.emplace_back(env, p, a, i+1, t.at(i));
        }
        
        assert(_children.size() == a);
        assert(_first_partialortoupdate == 0);
        assert(this->inner());
        // even if all ptr are complete, weight is not evaluated
        assert(this->partial());
        // weight is transition weight (children's weights must be added)
        assert(! weight.unknown());
    }
}


// top-down meta run
//template<class P>
//Run<P>::Run(Environment* env,
//            const P& p, state_t s, const Weight& w, bool direction):
//weight(w),
//duration(),
//_children(),
//_transition(NULL),
//_first_partialortoupdate(direction?0:1),
//_meta(true)
//{
//    assert(env);
//    assert(p.has_S());
//    assert(State::isMeta(p.state()));
//    assert(p.divisible());
//    assert(State::isWTA(s));
//    assert(p.has_I());
//
//    // first child (wta)
//    _children.emplace_back(env, p, 2, 1, s);
//    // second child (meta), s ignored
//    _children.emplace_back(env, p, 2, 2, s);
//
//    assert(! weight.unknown());
//    assert(_children.size() == 2);
//    assert(this->inner());
//    assert(this->meta());
//    assert(this->partial());
//}


template<class P>
Run<P>::Run(const Run<P>& r):
weight(r.weight),
duration(r.duration),
_children(r._children), // copy
_transition(r._transition),
_first_partialortoupdate(r._first_partialortoupdate),
_meta(r._meta)
{
    assert (this->null() || this->terminal() || this->inner());
}


template<class P>
Run<P>::Run(const Run<P>& r, size_t i):
Run(r) // copy
{
    assert(r.inner());
    assert(0 <= i);
    assert(i < _children.size());
    assert(_children[i].has_K()); // useless otherwise
    _children[i].incr();
    this->reset();
}


// instanciate first partial
template<class P>
Run<P>::Run(const Run<P>& r, const P& p):
weight(r.weight),
duration(r.duration),
_children(),
_transition(r._transition),
_first_partialortoupdate(r._first_partialortoupdate),
_meta(r._meta)
{
    assert(r.inner());
    assert(0 <= _first_partialortoupdate);
    assert(_first_partialortoupdate < r._children.size());
    assert(r._children[_first_partialortoupdate].partial());
    assert(p.complete());
    assert(r._children[_first_partialortoupdate].subsume(p));
    TRACE("Run {} to instanciate with {}", r, p);
    
    assert(_children.size() == 0);
    
    size_t i;
    
    for (i = 0; i < _first_partialortoupdate; i++)
    {
        _children.emplace_back(r[i]);
    }
    
    // position _first_partialortoupdate
    _children.emplace_back(p); // copy
    i++;
    
    // _first_partialortoupdate has a next sibling
    // update this sibling according to p.
    if ((_first_partialortoupdate < r._children.size()-1) &&
        (r[_first_partialortoupdate+1].partial()))
    {
        // position _first_partialortoupdate+1
        // instanciate next
        _children.emplace_back(p, r[_first_partialortoupdate+1]);
        i++;
    }
    
    for (; i < r._children.size(); i++)
    {
        _children.emplace_back(r[i]);
    }
    
    assert(this->inner());
    assert(this->arity() == r.arity());
    
    // do not incr. _first_partialortoupdate yet
    // its best's weight must be add to Run weight first.
    TRACE("Run instance: {}", *this);
}


template<class P>
Run<P>::~Run()
{
    TRACE("delete Run {}", *this);
    _children.clear();
    //delete weight;
}


template<class P>
bool Run<P>::null() const
{
    if (_children.empty())
    {
    //  assert(weight.unknown());
        return true;
    }
    else
        return false;
}


template<class P>
bool Run<P>::terminal() const
{
    return (_children.size() == 1);
}


template<class P>
bool Run<P>::inner() const
{
    return (_children.size() > 1);
}


template<class P>
bool Run<P>::meta() const
{
    return _meta;
    //    if ((! this->inner()) || (_children.size() != 2))
    //    {
    //        return false;
    //    }
    //    else
    //    {
    //        assert(_children[1].has_S());
    //        return (State::isMeta(_children[1].state()));
    //    }
}


template<class P>
bool Run<P>::allcomplete() const
{
    if (inner())
    {
        for (size_t i = 0; i < _children.size(); i++)
        {
            if (_children[i].partial())
                return false;
        }
    }
    
    return true;
}


template<class P>
bool Run<P>::complete() const
{
    if (inner())
    {
        return (_first_partialortoupdate >= _children.size());
    }
    else if (terminal())
    {
        return true;
    }
    else
    {
        ERROR("Run.complete {} : test of run not inner or terminal", *this);
        return false;
    }
}


template<class P>
Run<P>& Run<P>::operator= (const Run<P>& rhs)
{
    if(this != &rhs)
    {
        weight = rhs.weight;
        duration = rhs.duration;
        _first_partialortoupdate = rhs._first_partialortoupdate;
        _meta = rhs._meta;
        
        _children.resize(rhs._children.size());
        _children = rhs._children; // copy
        //        for (size_t i = 0; i < rhs._children.size(); i++)
        //        {
        //            _children[i] = rhs._children[i];
        //        }
    };
    return *this;
}


template<class P>
label_t Run<P>::label() const
{
    assert (this->terminal());    // 1 children
    assert (_children.size() == 1);
    assert(_children[0].has_S());
    
    // TBC convertion of state_t value into Label_t type
    assert(State::isLabel(_children[0].state()));
    return _children[0].state();
}


template<class P>
size_t Run<P>::arity() const
{
    size_t a = _children.size();
    switch (a)
    {
        case 0:
        case 1:
            return 0;
            
        default:
            return a;
    }
}


template<class P>
bool Run<P>::filter()
{
    if (this->null())
    {
        WARN("Run::filter: null Run");
        return false;
    }
    
    assert(this->inner() || this->terminal());
    
    // filter acc. to optimization flags
    // we do not filter out meta runs
    if (! this->meta() && OPT_RUN_UNIT)
    {
        assert (OPT_RUN_DUR);
        if (this->duration.unit() && this->inner())
            return false;
    }
    return true;
}


//template<class P>
//void Run<P>::set(const Weight& w)
//{
//    weight.clear();
//    weight = w;
//}


template<class P>
void Run<P>::reset()
{
    assert(this->inner());
    assert(! this->meta());
    assert(_transition);
    
    weight = _transition->weight();
    duration = DurationList();
    _first_partialortoupdate = 0;
    
    assert (this->partial());
}


template<class P>
const P& Run<P>::first() const
{
    assert(this->inner());
    assert(_children.size() > 0);
    return _children.front();
}


template<class P>
const P& Run<P>::last() const
{
    assert(this->inner());
    assert(_children.size() > 0);
    return _children.back();
}


template<class P>
const P& Run<P>::firstPartialorUpdate() const
{
    assert(_first_partialortoupdate < _children.size());
    
    return _children[_first_partialortoupdate];
}


template<class P>
void Run<P>::insert(const P& p)
{
    _children.push_back(p);
}


template<class P>
void Run<P>::update(const Weight& w, const DurationList& dl) // arg duration
{
    assert(this->inner());
    assert(! w.unknown());
    //assert(! w.zero()); // zero weight
    assert(_first_partialortoupdate < _children.size());
    assert(_children[_first_partialortoupdate].complete());
    // assert(! weight.zero()); // zero weight

    weight *= w;
    // (flag) concatenation dur
    if (OPT_RUN_DUR) // dl may be empty in case of manual update
    {
        duration += dl;
    }
    _first_partialortoupdate++;
    
    // update is terminated
    if (this->complete() && OPT_RUN_DUR && (! dl.empty()))
    {
        assert (duration.summed() == this->arity());
        duration.normalize();   // .mult(Rational(1, arity));
    }
}


template<class P>
void Run<P>::_init_duration_list(label_t label)
{
    // update duration list
    if (OPT_RUN_DUR)
    {
        if (Label::continuation(label))
        {
            // relative duration of leaf is 1
            duration.addcont(Rational(1));
        }
        // leaf contains 0 or several grace notes and one event
        else
        {
            for (int i = 0; i < Label::nbGraceNotes(label); i++)
            {
                // every grace note has duration 0
                duration.add(Rational(0));
            }
            // the event in leaf has relative duration 1
            duration.add(Rational(1));
        }
    }
}


//template<class P>
//std::ostream& operator<<(std::ostream& o, const Run<P>& r)
//{
//    if (r.null())
//    {
//        o << "NULL_RUN";
//    }
//    else if (r.terminal())
//    {
//        assert (r._children.size() == 1);
//        o << r._children[0] << " " << r.weight;
//    }
//    else if (r.inner())
//    {
//        o << "( ";
//        for(typename vector<P>::const_iterator i = r._children.begin();
//            i != r._children.end();
//            ++i)
//        {
//            o << *i << " ";
//        }
//
//        o << ") " << r.weight;
//    }
//
//    return o;
//}
