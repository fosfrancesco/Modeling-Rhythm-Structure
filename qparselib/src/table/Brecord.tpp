//
//  Brecord.tpp
//  squant
//
//  Created by Florent Jacquemard on 11/01/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//



template<class P>
Brecord<P>::Brecord(const P& p, RunCompare<P> comp):
Record<P>(p, comp), // base class constructor with parameter
_best(NULL)
{
    TRACE("new empty Brecord[{}]", this->_key);
}


template<class P>
Brecord<P>::~Brecord()
{
    TRACE("delete Brecord[{}]", this->_key);
    if(_best)
    {
        assert(! _best->null()); // null Run replaced by NULL Run*
        delete(_best);
    }
}


template<class P>
Run<P>* Brecord<P>::best(Atable<P>* parent, size_t k)
{
    assert(k == 1);
    assert ((_best == NULL) || _best->complete());
    assert ((_best == NULL) || (! _best->null()));
    
    // k-best run already computed at construction
    if (_best == NULL)
    {
        TRACE("Brecord[{}].best() = NULL run", this->_key);
    }
    
    return _best;
}


//template<class P>
//void Brecord<P>::addCand(const Transition& t)
//{
//    TRACE("Brecord[{}].addTr {}", _key, t);
//    _nb_cand++;
//    add(new Run(t));
//}


template<class P>
void Brecord<P>::add(Run<P>* r)
{
    // ignore invalid runs
    if (! this->valid(r))
    {
        return;
    }
    
    assert (r->inner() || r->terminal());
    assert ((_best == NULL) || _best->complete());
    
    this->_nb_cand++;
    const P& thiskey = this->_key;
    
    if (r->partial())
    {
        ERROR("Brecord[{}].add: partial run {}", thiskey, *r);
        delete r;
        return;
    }
    else if ((_best == NULL) || this->_comp(_best, r))
    {
        // r is the new best
        if( r->filter() )
        {
            TRACE("Brecord[{}] add run {}", thiskey, *r);
            if (_best)
            {
                delete _best;
            }
            _best = r;
            assert (_best->complete());
            assert (! _best->null());
        }
        else
        {
            TRACE("Brecord[{}] reject run {} {}", thiskey, *r, r->duration);
            this->_nb_best_rejected++;
            delete r;
        }
    }
    else
    {
        TRACE("Brecord[{}] ignore run {}", thiskey, *r);
        delete r;
    }
}


template<class P>
bool Brecord<P>::empty() const
{
    return (_best == NULL);
}
