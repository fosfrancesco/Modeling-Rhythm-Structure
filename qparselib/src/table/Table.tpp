//
//  Table.tpp
//  squant
//
//  Created by Florent Jacquemard on 12/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

template <class P, class R, class H>
Table<P, R, H>::Table(Parser<P>* env, RunCompare<P> comp):
Atable<P>(env, comp),
_table(),
_instances(),
_nb_rows(0),
_nb_runs(0)
{
    assert(env);
    TRACE(env->segment?"new Table for quantization":
          "new Table for WTA enumeration");
};


template <class P, class R, class H>
Table<P, R, H>::~Table()
{
    TRACE("delete table");
    assert(_nb_rows == _table.size());
    INFO("nb of entries in table: {}", _nb_rows);
    //INFO("size of table:          {}", _table.size());
    INFO("nb of runs in table:    {}", _nb_runs);
    INFO("size of instances map:  {}", _instances.size());

    _instances.clear();
    _table.clear();
}


// best(p)
template <class P, class R, class H>
Run<P>* Table<P, R, H>::best(const P& p)
{
    assert(p.complete());
    
    // find/create Record for p in table
    Record<P>* it = this->getRecord(p);
    assert (it != NULL);
    
    // record was just created by above call to getRecord
    if (it->state == 0)
    {
        // add runs to the new record for p
        addComplete(p, it);
        assert(it->state == 2);
    }
    
    // call best on the record for p in table
    size_t k = p.rank(); // default is 1
    
    Run<P>* r = it->best(this, k);
    assert(r == NULL || r->complete());
    
    return r;
};


// bestTree(p)
template <class P, class R, class H>
RhythmTree* Table<P, R, H>::bestTree(const P& p)
{
    Run<P>* r = best(p);
    if (r)
    {
        assert(r->complete());
        return bestTree(r);
    }
    else
        return NULL;
};


// bestTree(p, r)
template <class P, class R, class H>
RhythmTree* Table<P, R, H>::bestTree(Run<P>* r)
{
    assert (r);
    assert (! r->null());
    assert (r->complete());
    
    
    if (r->terminal())
    {
        return new RhythmTree(r->label());
    }
    else
    {
        assert (r->inner());
        size_t a = r->arity();
        assert (a > 0);
        
        // inner RhythmTree, initialy empty.
        RhythmTree* t = new RhythmTree();
        
        for (size_t i = 0; i < a; i++)
        {
            t->add(bestTree((*r)[i]));
        }
        return t;
    }
};



// getRecord(p, state)
template <class P, class R, class H>
Record<P>*
Table<P, R, H>::getRecord(const P& p, unsigned int state)
{
    assert(p.complete());
    
    // search Record for p in table
    typename MapRecord<P, R, H>::iterator it = _table.find(p);
    
    // p has no Record in table
    // create and add in table a new record for p
    // using piecewise constructor
    if (it == _table.end())
    {
        TRACE("add key {} to main table (create entry)", p);
        std::pair<typename MapRecord<P, R, H>::iterator, bool> pret =
        _table.emplace(std::piecewise_construct,
                       std::forward_as_tuple(p),                   // Pointer
                       std::forward_as_tuple(p, this->_comparer)); // Record
        
        // false if p was already in _table
        assert(pret.second);
        
        pret.first->second.state = state;
        assert(p == pret.first->first);
        _nb_rows++; // stats
        return &(pret.first->second); // pointer to new record
    }
    else
    {
        assert(it->first == p);
        return &(it->second); // pointer to record found in table
    }
}

// getInstances(p)
template <class P, class R, class H>
std::pair<typename MapInstances<P,H>::iterator,
typename MapInstances<P,H>::iterator>
Table<P, R, H>::getInstances(const P& p)
{
    assert(p.partial());
    
    return _instances.equal_range(p);
}


template <class P, class R, class H>
bool Table<P, R, H>::existsInstance(const P& pp, const P& pc) const
{
    assert(pp.partial());
    assert(pc.complete());

    std::pair<typename MapInstances<P,H>::const_iterator,
              typename MapInstances<P,H>::const_iterator> pit =
    _instances.equal_range(pp);
    
    for (typename MapInstances<P,H>::const_iterator i = pit.first;
         i != pit.second; i++)
    {
        assert(i->first == pp);
        if (i->second == pc)
            return true;
    }
    return false;
}


// add(p)
template <class P, class R, class H>
Record<P>* Table<P, R, H>::add(const P& p)
{
    if (p.partial())
    {
        if (_instances.count(p) > 0)
        {
            ERROR("partial key {} already in table, ignored.", p);
        }
        else
        {
            addPartial(p);
        }
        return NULL;
    }
    else
    {
        assert(p.complete());
        Record<P>* it = getRecord(p);
        assert(it);
        assert(it->state == 0); // had not been added before
        addComplete(p, it);
        return it;
    }
}


// addComplete(p, it)
// p must be complete.
// it must point to the record associated to p.
template <class P, class R, class H>
size_t Table<P, R, H>::addComplete(const P& p, Record<P>* it)
{
    assert(p.complete());
    assert(it);
    assert(it->key() == p); // TBC rank ignored in ==
    assert(it->state == 0);
    
    TRACE("add complete key {} to table (record state {})", p, it->state);
    it->state = 2;
    return add(p, it);
}


// addPartial(p)
// p must be partial.
template <class P, class R, class H>
size_t Table<P, R, H>::addPartial(const P& p)
{
    assert(p.partial());
    if (_instances.count(p) == 0)  // never called for p
    {
        TRACE("new partial key {}", p);
        return add(p, NULL);
    }
    // else ignore (p already treated)
    else
    {
        TRACE("partial key {} already in tables", p);
        return 2;
    }
}


// add(p, it)
// p is partial or complete.
// if p partial then it must be _table.end
// if p complete then it must point ot the associated record in table
template <class P, class R, class H>
size_t Table<P, R, H>::add(const P& p, Record<P>* it)
{
    TRACE("table add entry {}", p);
    assert(p.partial()  || (it != NULL));
    assert(p.complete() || (it == NULL));
    
    // the creation of runs for p is delegated to the parsing environment
    assert(this->parent);
    return this->parent->addRuns(this, p, it);
}


// add(p, r)
// p must be complete and registered to table
// r can be partial or complete
// for external call (public)
// @todo TBR
//template <class P, class R, class H>
//void Table<P, R, H>::add(const P& p, Run<P>* r)
//{
//    assert(p.complete());
//    assert(r);
//    assert (! r->weight.unknown());
//    assert (r->inner() || r->terminal());
//
//    typename MapRecord<P, R, H>::iterator it = _table.find(p);
//    assert(it != _table.end());
//
//    if (r->complete())
//    {
//        addTable(p, r, &(it.second));
//    }
//    // r partial
//    else
//    {
//        assert(r->partial());
//        assert(r->inner());
//        addUpdate(p, r, &(it.second));
//    }
//}


// add(p, r, it)
// p can be partial or complete
// if p is complete,
// then it must point to a Record,
// otherwise it must be NULL.
// r can be partial or complete
template <class P, class R, class H>
size_t Table<P, R, H>::add(const P& p, Run<P>* r, Record<P>* it)
{
    TRACE("table add entry {} run {}", p, *r);
    assert (r);
    assert (! r->weight.unknown());
    assert (r->inner() || r->terminal());
    assert(p.complete() || (it == NULL));
    assert(p.partial()  || (it != NULL));
    
    if (r->complete())
    {
        if (p.complete())
        {
            return addTable(p, r, it);
        }
        else
        {
            // p partial (no other case)
            assert(p.partial());
            
            return addInstanciate(p, r);
        }
    }
    // r partial
    else
    {
        assert(r->partial());
        assert(r->inner());
        
        return addUpdate(p, r, it);
    }
}


// addTable(p, r, it)
// p complete
// r complete
template <class P, class R, class H>
size_t Table<P, R, H>::addTable(const P& p, Run<P>* r, Record<P>* it)
{
    assert(p.complete());
    assert(r);
    assert(r->complete());
    assert(it != NULL);
    assert(it->key() == p);
    TRACE("table addTable entry {} run {}", p, *r);
    // @todo evaluate (in record) r if unknown
    // cf. Xrecord.best

    assert((it->state == 1) || (it->state == 2));
    it->add(r); // will check that weight is known
    _nb_runs++; // stats
    return 0;
};


// addUpdate(p, r, it)
// p complete or partial
// r partial
template <class P, class R, class H>
size_t Table<P, R, H>::addUpdate(const P& p, Run<P>* r, Record<P>* it)
{
    assert(r);
    assert(p.complete() || (it == NULL));
    assert(p.partial()  || (it != NULL));
    assert(r->partial());
    assert(r->inner());
    assert(r->arity() >= 1);
    TRACE("table addUpdate entry {} run {}", p, *r);

    const P pi = r->firstPartialorUpdate();
    
    // pi partial:
    // we construct instances of the run r, replacing pi by complete instances
    if (pi.partial())
    {
        size_t ret = 0;
        TRACE("update partial run {} PTR={}", *r, p);
        // compute the runs for pi only if that was not done before
        addPartial(pi);
        //TRACE("{} complete instances of {}", _instances.count(pi), pi);
        
        // find complete instances of pi added in inst. table
        std::pair<typename MapInstances<P,H>::iterator,
        typename MapInstances<P,H>::iterator> range = getInstances(pi);
        
        //TRACE("range size = {}", std::distance(range.first, range.second));
        
        // the table _instances may be completed during the loop
        // (when the new run rinst is added)
        // and the loop will re-iterate over new elements of )instances,
        // which are not appropriate.
        // to avoid this problem,
        // we store in advance the instances of pi in a FIFO .
        std::queue<P> completes;
        for(typename MapInstances<P,H>::iterator rit = range.first;
            rit != range.second; ++rit)
        {
            assert(rit->first == pi);
            assert(rit->second.complete());
            assert(rit->second.instance(pi));
            completes.push(rit->second);
        }
        
        size_t l = 1;
        size_t total = completes.size();
        
        TRACE("addUpdate: {} complete instances of {}", total, pi);
        if (total == 0)
        {
            TRACE("addUpdate: no instances of {}", pi);
            ret = 1;
        }
        
        while (! completes.empty())
        {
            TRACE("range loop {}/{}", l, total);
            TRACE("INSTANCE {}", completes.front());
            TRACE("replace {} by {} in {}", pi, completes.front(), *r);
            
            Run<P>* rinst = new Run<P>(*r, completes.front());
            TRACE("replacement run = {}", *rinst);
            
            // rinst can be partial or complete
            add(p, rinst, it);
            completes.pop();
            l++;
        }
        
        // all possible instances of r have been computed
        // partial r is not useful anymore
        delete(r);
        return ret;
    }
    // pi complete:
    // we update the weight of the run r
    else
    {
        TRACE("update run (weight) {}", *r);
        assert(pi.complete()); // no other case
        
        Run<P>* ri = best(pi); // add pi if it not in table
            
        // there is no best for pi
        // run r cannot be evaluated
        // abort evaluation of r and don't add r.
        if (ri == NULL)
        {
            delete r;
            return 2;
        }
        // update weight of r in place
        else
        {
            assert(ri->complete());
            
            if (ri->weight.zero())
            {
                WARN("addUpdate: child run {} with zero weight", *ri);
            }
            r->update(ri->weight, ri->duration);
            // updated r can be partial or complete
            return add(p, r, it);
        }
    }
}


// addInstanciate(p, r)
// p partial
// r complete
// creation (from r) and registration of a new instance of p,
template <class P, class R, class H>
size_t Table<P, R, H>::addInstanciate(const P& p, Run<P>* r)
{
    assert(r);
    assert(p.partial());
    assert(r->complete());
    TRACE("table addIntanciate entry {} run {}", p, *r);
    
    //   complete p into pc acc. to r;
    P pc; // initial is arbitrary choice
    
    if (r->terminal())
    {
        // label is assumed concrete
        label_t label = r->label();
        assert(State::isLabel(label));
        
        // instanciate p as leaf (Terminal)
        assert(p.compatible(label, false)); // @todo TBR would not be added otherwise
        // create instance as leaf
        // TBC cast of label type into state_t value
        // default duration
        assert(this->parent);
        assert(this->parent->input);
        pc = P(this->parent->input, p, 0, 0, (state_t) label);
        assert(pc.compatible(label, false)); // important
        
        // p should not be incompatible with label. handler:
        // {
        //    ERROR("add {} incompatible with {}", *r, p);
        //    delete (r);
        //    return;
        // }
    }
    else
    {
        assert (r->inner());
        assert (p.divisible());
        // instanciate p by propagating values in r children
        pc = P(p, r->first(), r->last());
    }
    
    assert(pc.complete());
    assert(pc.instance(p));
    
    // update tables new complete instance
    Record<P>* it = getRecord(pc);
    assert(it);
    if (it->state == 0)
    {
        it->state = 1; // new record for pc
    }
    addInstance(p, pc);
    return addTable(pc, r, it); // shortcut for add(pc, r, it)
}


// add(ppartial, pcomplete)
template <class P, class R, class H>
void Table<P, R, H>::addInstance(const P& pp, const P& pc)
{
    assert(pp.partial());
    assert(pc.complete());
    
    // pc may have been registered to table (by former add(pp, pc)
    if (existsInstance(pp, pc))
    {
        TRACE("table of instances: pair already registered: {}, {}", pp, pc);
    }
    else
    {
        TRACE("table of instances: add pair {}, {}", pp, pc);
        _instances.emplace(pp, pc);
    }
};


template <class P, class R, class H>
void Table<P, R, H>::dump_table() const
{
    INFO("size of table: {}", _table.size());
    INFO("Table: instances map:");
    for (typename MapRecord<P,R,H>::const_iterator i=_table.begin();
         i != _table.end(); i++)
    {
        INFO("{}  :  {} runs", i->first, i->second.size());
    }
}


template <class P, class R, class H>
void Table<P, R, H>::dump_instances() const
{
    INFO("size of instances map: {}", _instances.size());
    INFO("Table: instances map:");
    for (typename MapInstances<P,H>::const_iterator i=_instances.begin();
         i != _instances.end(); i++)
    {
        INFO("{}  :  {}", i->first, i->second);
    }
}

