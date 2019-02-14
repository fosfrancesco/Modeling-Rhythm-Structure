//
//  IntervalTree.cpp
//  qparse
//
//  Created by Florent Jacquemard on 11/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "IntervalTree.hpp"
#include "IntervalHeap.hpp"


// internal use
IntervalTree::IntervalTree(const InputSegment* s, Rational me):
AlignedInterval(s, me),
_parent(NULL),
_previous_sibling(NULL)
{
    assert(s);
}


// internal use
IntervalTree::IntervalTree(const InputSegment* s,
                             Rational mb, Rational me,
                             double rb, double re,
                             size_t first,
                             IntervalTree* p,
                             IntervalTree* ps):
AlignedInterval(s, mb, me, rb, re, first),
_parent(p),
_previous_sibling(ps),
_children()
{
    assert(s);
    // sanity check done in parent's constructor
}


IntervalTree::~IntervalTree()
{
    TRACE("delete IntervalTree {}", *this);
    // all the children IntervalTree* are deleted when heap is cleared
    _children.clear();
}


IntervalTree* IntervalTree::top(const InputSegment* s,
                                IntervalHeap* ih,
                                Rational mend)
{
    assert(s);
    assert(ih);
    
    return ih->make(s, mend);
}


IntervalTree* IntervalTree::split(const InputSegment* s,
                                  IntervalHeap* ih,
                                  double rdur,
                                  Rational mdur,
                                  size_t i)
{
    assert(s);
    assert(ih);
    assert (rdur > 0);
    assert (mdur > Rational(0));
    assert (mdur <= mduration());

    //assert (rdur0 <= this->rduration());
    assert ((i == 1) || (i == 2));
    
    double rpivot = rbegin + rdur;
    Rational mpivot = mbegin + mdur;
    size_t j = this->first();
    IntervalTree* p[2];
    assert(rbegin < rpivot);

    // first new sub-interval starting at rbegin of dur rdur
    // aligned
    TRACE("split(1) of meta {}: [{}, {}] [{}, {}]",
          *(this), rbegin, rpivot, mbegin, mpivot);
    p[0] = ih->make(s,
                    mbegin, mpivot,
                    rbegin, rpivot,
                    j,
                    this, NULL); // no previous sibling
    assert(p[0]);
    assert(p[0]->first() == j);
    j = p[0]->rewind(s); //p[0]->align(s);
    
    // second new sub-alignment starting at rbegin+rdur
    // real-time duration null if start out of input segment
    // not aligned
    double rendnew = (rpivot <= rend)?(this->rend):rpivot;
    assert(this->mduration() >= mdur);

    TRACE("split(2) of meta {}: [{}, {}] [{}, {}]",
          *(this), rpivot, rendnew, mpivot, mend);
    p[1] = ih->make(s,
                    mpivot, mend,
                    rpivot, rendnew,
                    j,
                    this, p[0]);
    assert(p[1]);
    p[1]->rewind(s);
    
    return p[i-1];
}


IntervalTree* IntervalTree::split_back(const InputSegment* s,
                                       IntervalHeap* ih,
                                       double rdur,
                                       Rational mdur,
                                       size_t i)
{
    assert(s);
    assert(ih);
    assert (rdur > 0);
    assert (mdur > Rational(0));
    assert (mdur <= mduration());
    //assert (rdur0 <= this->rduration());
    assert ((i == 1) || (i == 2));
    
    size_t j = this->first();
    IntervalTree* p[2];
    
    // first new sub-interval starting at rbegin
    // not aligned
    //double rrest = (this->rduration() > rdur)?(this->rduration() - rdur):0.0;
    double rpivot = (this->rduration() > rdur)?(rbegin+rdur):rbegin;
    assert(this->mduration() >= mdur);
    Rational mpivot = mbegin + mdur;
    
    TRACE("split_back(1) of meta {}: [{}, {}] [{}, {}]",
          *(this), rbegin, rpivot, mbegin, mpivot);

    p[0] = ih->make(s,
                    mbegin, mpivot,
                    rbegin, rpivot,
                    j,
                    this, NULL);

    assert(p[0]);
    assert(p[0]->first() == j);
    j = p[0]->rewind(s);
    
    // first new sub-interval starting at rbegin of dur rdur
    // aligned
    TRACE("split_back(2) of meta {}: [{}, {}] [{}, {}]",
          *(this), rpivot, rdur, mpivot, mdur);
    p[1] = ih->make(s,
                    mpivot, mdur,
                    rpivot, rdur,
                    j,
                    this, p[0]); // no previous sibling
    assert(p[1]);
    p[1]->rewind(s); //p[1]->align(s);
    
    return p[i-1];
}


IntervalTree* IntervalTree::sub(const InputSegment* s,
                                IntervalHeap* ih,
                                size_t a, size_t i)
{
    assert (a > 1);
    assert (1 <= i);
    assert (i <= a);
    assert(this->aligned());
    
    // creates an empty vector if it is not found
    std::pair<std::map<size_t, std::vector<IntervalTree*>>::iterator, bool> ret =
    _children.insert(std::pair<size_t, std::vector<IntervalTree*>>(a,
                                                std::vector<IntervalTree*>()));
    std::vector<IntervalTree*>& v = ret.first->second;

    // newly created vector for a, fill it with aligned sub intervals
    if (ret.second)
    {
        assert(v.size() == 0);
        size_t b = this->first();
        Rational mbeg = mbegin;
        Rational mdur = (mend-mbegin) / Rational(a);
        double rbeg = rbegin;
        double rdur = (rend - rbegin) / ((double) a);
        double rbeg_next;
        IntervalTree* sibling = NULL;
        
        for (int j = 0; j < a; j++)
        {
            rbeg_next = (j == a-1)?rend:rbeg+rdur;
            assert(j<a-1 || mbeg+mdur == mend);
            TRACE("sub({}/{}) of {}: [{}, {}] [{}, {}]",
                  j+1, a, *(this), rbeg, rbeg_next, mbeg, mbeg+mdur);
            IntervalTree* pt = ih->make(s,
                                        mbeg, mbeg+mdur,
                                        rbeg, rbeg_next,
                                        b,
                                        this, sibling);
            assert(pt);
            if (pt->aligned())
            {
                b = pt->next();
            }
            else
            {
                b = pt->align(s, b);
            }
            v.push_back(pt);
            mbeg += mdur;
            rbeg = rbeg_next;
            sibling = pt;
        }
    }
    //  key a already exist in map
    else
    {
        assert(v.size() == a);
    }
    assert(v.size() == a);
    return v[i-1];
}


std::ostream& operator<<(std::ostream& o, const IntervalTree& p)
{
    o << static_cast<const Interval&>(p);
    
    return o;
}


/// @}
