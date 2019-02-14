//
//  Krecord.cpp
//  squant
//
//  Created by Florent Jacquemard on 11/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "Krecord.hpp"


template<class P>
Krecord<P>::Krecord(const P& p, RunCompare<P> comp):
Record<P>(p, comp), // base class constructor with parameter
_cand(comp),        // empty candidate list
_best()             // empty best list
{
    TRACE("new empty Krecord[{}]", this->_key);
}


template<class P>
Krecord<P>::~Krecord()
{
    // deallocate all runs in the _cand priority queue
    TRACE("clear  Krecord[{}] candidate queue (size={})", this->_key, _cand.size());
    while (! _cand.empty())
    {
        Run<P>* r = _cand.top();
        _cand.pop();
        assert (r);
        delete r;
    }
    
    
    // no clear() for priority_queues
    _cand = std::priority_queue<Run<P>*,
    std::vector<Run<P>*>,
    RunCompare<P>>();
    //    std::priority_queue<Run<P>*,
    //    vector<Run<P>*>,
    //    std::function<bool(const Run<P>*, const Run<P>*)>>().swap(_cand);
    
    // deallocate all runs in the _best list
    TRACE("clear  Krecord[{}] best list (size={})", this->_key, _best.size());
    for (typename std::vector<Run<P>*>::iterator i = _best.begin();
         i != _best.end(); ++i)
    {
        assert (*i);
        assert(! (*i)->null());
        delete (*i);
    }
    
    _best.clear();
}


template<class P>
bool Krecord<P>::empty() const
{
    return (_cand.empty() && _best.empty());
}


template<class P>
Run<P>* Krecord<P>::best(Atable<P>* table, size_t k)
{
    assert(table);
    assert(this->_key.has_K());
    assert(k > 0);
    // NB:
    // it does not necessary hold that _key.rank() is k
    // we store all bests in record of _key, ignoring rank value of _key.
    
    // k-best run already computed
    if (_best.size() >= k)
    {
        Run<P>* best = _best[k-1];
        assert(best);
        assert(! best->null());
        assert(best->complete());
        return _best[k-1];
    }
    
    // otherwise, we construct the next best run
    
    // cannot (all runs constructed in best table)
    if (_cand.empty())
    {
        return NULL; // was null run new Run<P>()
    }
    
    // otherwise, process the best candidate r
    // CAUTION: runs with unevaluated weight must always be on top
    Run<P>* r = _cand.top();
    
    assert(r);
    assert(! r->null());  // no null run candidate
    assert(r->inner() || r->terminal());
    assert(r->allcomplete());  // no partial child
    TRACE("Krecord[{}] pop  cand run {}", this->_key, *r);
    
    _cand.pop();
    
    // one candidate's weight not evaluated
    if (r->partial())
    {
        // evaluate the weight of the run r and re-add it to this record.
        table->add(this->_key, r, this);
        
        // the evaluation of weight may fail
        // in this case, the run is not added to this record
        // we do not push this run back to the heap of candidates
        // we do not push next runs because they can neither be evaluated
        
        //tail recursive call to evaluate other candidates
        return best(table, k);
    }
    // all candidates have been evaluated
    // because unknown weight has priority
    // r is the best run
    else
    {
        assert(r->complete());
        
        // add the best run to the best table
        addBest(r);
        
        // compute next candidate if run is not terminal
        if (r->inner())
        {
            addNext(r);
        }
        
        // tail recursive call, either:
        // return the run that was just added (if place in best list matches)
        // or try to construct more best runs if needed.
        return best(table, k);
    }
}


//template<class P>
//void BRecord<P>::addCand(const Transition& t)
//{
//    TRACE("BRecord[{}].addTr {}", _key, t);
//    _nb_cand++;
//    add(new Run(t));
//}

template<class P>
void Krecord<P>::add(Run<P>* r)
{
    // ignore invalid runs
    if (this->valid(r))
    {
        assert (r->inner() || r->terminal());    
        addCand(r);
    }
}


// add run to the heap of candidates
template<class P>
void Krecord<P>::addCand(Run<P>* r)
{
    assert(r->allcomplete()); // all children are complete ptr
    // but weight might be partialy evaluated
    
    const P& thiskey = this->_key;
    
    if( r->filter() )
    {
        TRACE("Krecord[{}] push cand run {}", thiskey, *r);
        this->_cand.push(r);
        this->_nb_cand++;
    }
    else
    {
        TRACE("Krecord[{}] reject cand run {}", thiskey, *r);
        this->_nb_best_rejected++;
        delete r;
    }
}


template<class P>
bool Krecord<P>::bestFilter(const Run<P>* r)
{
    assert (r);
    assert(r->inner() || r->terminal());
    
    // filter acc. to optimization flags
    if (OPT_RUN_UNIT)
    {
        assert (OPT_RUN_DUR);
        if (r->duration.unit() && r->inner())
            return false;
    }
    return true;
}


// add run to the list of bests
template<class P>
void Krecord<P>::addBest(Run<P>* r)
{
    assert (r);
    assert (! r->null());
    assert(r->inner() || r->terminal());
    assert(r->complete()); // weight is evaluated
    
    const P& thiskey = this->_key;
    
    if( bestFilter(r) )
    {
        TRACE("Krecord[{}] add  best run {}", thiskey, *r);
        _best.push_back(r);
    }
    else
    {
        TRACE("Krecord[{}] rejected best run {}", thiskey, *r);
        this->_nb_best_rejected++;
    }
}


template<class P>
void Krecord<P>::addNext(Run<P>* r)
{
    assert(r);
    assert(r->inner());
    
    // add next candidates
    for (int i = 0; i < r->arity(); i++)
    {
        // copy and increment rank
        // NB: the run added (to candidates) has unevaluated weight
        // the evaluation is delayed to next call to best (lazy eval)
        addCand(new Run<P>(*r, i));
        
        // do not delete r : it has been placed in best list!
    }
}
