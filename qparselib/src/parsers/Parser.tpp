//
//  Parser.tpp
//  squant
//
//  Created by Florent Jacquemard on 05/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.



// the table must be created in descendant classes
template <class P>
Parser<P>::Parser(WTA* a, InputSegment* s):
wta(a),
input(new Environment(s)),
_res(0)
{
    assert(a);
}


// do not delete the wta
template <class P>
Parser<P>::~Parser()
{
    if (input)
        delete input;
}


template <class P>
size_t Parser<P>::resolution()
{
    // not yet computed
    if (_res == 0)
    {
        if (wta != NULL)
            _res = wta->resolution();
        else
            ERROR("cannot compute resolution: no WTA");
    }
    return _res;
}


template <class P>
size_t Parser<P>::addWTARuns(Atable<P>* table,
                             const P& p, Record<P>* it)
{
    assert(table);
    assert(wta);
    assert(p.has_S());
    state_t s = p.state();
    assert(State::isWTA(s));
    TRACE("addRuns: state {}, entry {}", s, p);

    // zero if one run is successfuly added to table
    size_t ret = 1;
    
    TRACE("addWTARuns: {} transitions for state {}", wta->oftarget(s), s);
    // construct one run for each transition
    for (TransitionList_const_iterator i = wta->cbegin(s);
         i != wta->cend(s); ++i)
    {
        
        //const Transition& t = *i;
        assert(i->inner() || i->terminal());
        
        Run<P>* r = NULL;
        
        // filter for the creation of runs
        // case terminal : compatibility with abstract label of transition
        // case inner: divisibility depends on P class (e.g. inhabited)
        if ((i->terminal() && p.compatible(i->label(), true)) ||
            (i->inner() && p.divisible()) )
        {
            // pass Environment
            r = new Run<P>(input, p, (*i));
            assert(r->null() || (! r->weight.unknown()));
        }
        else
        {
            const Transition& tr = *i;
            TRACE("addWTARuns: discard transition {} for state {} (entry {})",
                 tr, s, p);
        }
        
        if (r)
        {
            if (! r->null())
            {
                TRACE("new WTA runs for {} : {}", p, *r);
                ret *= table->add(p, r, it);
            }
            // @todo TBR creation of null runs
            else
            {
                ERROR("add({}) : null run", p);
                delete(r);
            }
        }
        else
        {
            TRACE("addWTARuns: no run for state {} (entry {}) (filtered out)",
                  s, p);
        }
    }

    return ret;
}


template <class P>
void Parser<P>::printobestRun(std::ostream& o,
                              Atable<P>* table,
                              Run<P>* r) const
{
    if (r)
    {
        RhythmTree* t = table->bestTree(r);
        assert(t);
        Weight cpty = wta->eval(*t);
        
        o << t->to_string() << " ";
        o << "(weight=" << r->weight << ", ";
        o << "cpty=" << cpty  << ", ";
        o << "dist=";
        
        assert(CST_WEIGHT_TYPE == WeightDom::STOCHASTIC ||
               CST_WEIGHT_TYPE == WeightDom::PENALTY);
        // QP_WEIGHT == WEIGHT_STOCHASTIC
        if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )
        {
            if (cpty.zero()) // 0
            {
                o << "unknown";
            }
            else
            {
                o << (r->weight.norm()/cpty.norm());
            }
        }
        // QP_WEIGHT == WEIGHT_PENALTY
        else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
        {
            if (cpty.zero()) // +infinity
            {
                o << "unknown";
            }
            else
            {
//                o << (r->weight.norm()
//                      - (1.0-CST_ALPHA)*cpty.norm()) / CST_ALPHA;
                o << (r->weight.norm() - cpty.norm());
            }
        }
        else
        {
            ERROR("Parser: unxepected weight type");
        }

        o << ") ";
        o << r->duration << " ";
        o << ((t->reducible())?"REDUCIBLE":"");
        delete t;
    }
    else
    {
        o << "null best";
    }
}


template <class P>
void Parser<P>::printobest(std::ostream& o, Atable<P>* table, const P& p) const
{
    assert(wta);
    assert(table);
    
    Run<P>* r = table->best(p);
    printobestRun(o, table, r);
}

