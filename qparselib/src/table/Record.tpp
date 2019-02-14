//
//  Record.tpp
//  squant
//
//  Created by Florent Jacquemard on 12/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//


template<class P>
Record<P>::Record(const P& p, RunCompare<P> comp):
_key(p),
_comp(comp),
_nb_cand(0),
_nb_best_rejected(0)
{
assert(p.complete());
}


template<class P>
bool Record<P>::valid(Run<P>* r)
{
    if (r == NULL)
    {
        WARN("NULL run not added to record");
        return false;
    }
    else if (r->weight.unknown())
    {
        WARN("run {} with unknown weight not added to record", *r);
        return false;
    }
    else if (r->weight.zero())
    {
        ERROR("run {} with zero weight added to record", *r);
        return true;
    }
    else
    {
        return true;
    }
//    return ((r != NULL) &&
//            (! r->weight.unknown()) &&
//            (! r->weight.zero()));
}

