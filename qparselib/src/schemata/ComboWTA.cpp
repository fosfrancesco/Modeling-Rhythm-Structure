//
//  ComboWTA.cpp
//  qparse
//
//  Created by Florent Jacquemard on 11/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "init.hpp"
#include "trace.hpp"
#include "ComboWTA.hpp"



ComboState::ComboState(const InputSegment* s, IntervalHeap* ih):
cs_state(0),
cs_pre(0),
cs_post(0)
{
    assert(s);
    assert(ih);
    cs_path = ih->make(s, Rational(1));
}


ComboState::ComboState(state_t s, IntervalTree* p, pre_t pre, pre_t post):
cs_state(s),
cs_path(p),
cs_pre(pre),
cs_post(post)
{
    assert(p);
//    rehash();
}


ComboState::ComboState(const ComboState& cs, pre_t pre, pre_t post):
cs_state(cs.cs_state),
cs_path(cs.cs_path),
cs_pre(pre),
cs_post(post)
{
    assert(cs_path);
//    rehash();
}

ComboState::~ComboState()
{
    // cs_path deleted with _tree (avoid double delete)
    // delete cs_path;
}

//void ComboState::rehash()
//{
//    assert(cs_path);
//    _hash[0] = cs_state;
//    _hash[1] = cs_path->begin();
//    _hash[2] = cs_path->length();
//    _hash[3] = cs_pre;
//    _hash[4] = cs_post;
//}


bool ComboState::compatible(label_t label) const
{
    const IntervalTree* p = cs_path;
    assert(p);
    
    return(
           (
            (
             // if it is a continuation (tie): there must be no point aligned to the left (of this Path)
             Label::continuation(label) &&
             (cs_pre == 0) &&   // no point of previous Path aligned to left
             (p->lsize() == 0)  // no point of this Path aligned to left
             )
            ||
            // if it contains note and grace notes (no continuation):
            // the label must be consistent with
            // the info in guess (# grace notes)
            (
             (! Label::continuation(label)) &&
             Label::abstract(label, cs_pre + p->lsize())
             //      (Label::nbGraceNotes(label) == (cs.cs_pre + p->l_size() - 1))
             )
            )
           &&
           // and check the info in current Path (# points aligned on right)
           // (must be true in both cases (continuation or not)
           (cs_post == p->rsize()));
}


bool ComboState::operator==(const ComboState& s) const
{
    if (cs_state != s.cs_state) return false;
    else if (cs_path->rbegin != s.cs_path->rbegin) return false;
    else if (cs_path->rend != s.cs_path->rend) return false;
    else if (cs_pre != s.cs_pre) return false;
    else if (cs_post != s.cs_post) return false;
    else return true;
    
//    for (int i = 0; i < _hash_len; i++)
//    {
//        if (_hash[i] != s._hash[i]) return false;
//    }
//    return true;
}

// lexicographic comparison on hash value (size_t[5])
bool ComboState::operator<(const ComboState& s) const
{
    if (cs_state > s.cs_state) return false;
    else if (cs_state < s.cs_state) return true;
    //otherwise cs_state == s.cs_state : continue
    else if (cs_path->rbegin > s.cs_path->rbegin) return false;
    else if (cs_path->rbegin < s.cs_path->rbegin) return true;
    //
    else if (cs_path->rend > s.cs_path->rend) return false;
    else if (cs_path->rend < s.cs_path->rend) return true;
    //
    else if (cs_pre > s.cs_pre) return false;
    else if (cs_pre < s.cs_pre) return true;
    //
    else if (cs_post > s.cs_post) return false;
    else if (cs_post < s.cs_post) return true;
    // this equal to s
    else
    {
        assert (*this == s);
        return false;
    }

//    for (int i = 0; i < _hash_len; i++)
//    {
//        if (_hash[i] > s._hash[i]) return false;
//        else if (_hash[i] < s._hash[i]) return true;
//        //otherwise _hash[i] == s._hash[i] : continue
//    }
//    return false;   //they are equal
}


std::ostream& operator<<(std::ostream& o, const ComboState& cs)
{
    o << "< " << cs.cs_state << ", ";
    o << cs.cs_path->rbegin << "-";
    o << cs.cs_path->rend << ", ";
    o << cs.cs_pre << ", ";
    o << cs.cs_post << ">";
    return o;
}


// @todo suppr. flag initial
state_t ComboWTA::addComboState(const ComboState& cs, bool initial)
{
    // combo state found in map: combo state has been treated already
    Combomap::const_iterator it = _statemap.find(cs);
    
    if (it != _statemap.end())
    {
        TRACE("old combo state: {} = state {} (already added)", cs, it->second);

        return it->second;
    }
    
    // the post value of cs cannot be reached in the interval of cs
    if (cs.cs_post > cs.cs_path->rsize())
    {
        TRACE("new combo state {} incompatible with alignment (rsize={})",
              cs,
              cs.cs_path->rsize());
        
        return -1;
    }

    // otherwise, create new state
    state_t s = _cpt++;
    TRACE("new combo state {}{} = {} ({})",
          s,
          (initial)?"*":"",
          cs,
          (cs.cs_path->inhabited())?"hab":"not hab");
    
    // add map of current ComboState to new state
    _statemap[cs] = s;
    //register state
    TransitionList& tv = add(s, initial); // empty vector of Transitions
 
    state_t q = cs.cs_state;                // current state in schema

    // case of initial states
    if (q == _schema.initial())
    {
        assert (_initials.size() > cs.cs_pre);
        assert (_initials[cs.cs_pre].size() > cs.cs_post);
        _initials[cs.cs_pre][cs.cs_post] = s;
        if ((cs.cs_pre == 0) && (cs.cs_post == 0))
        {
            _initial = s;
        }
    }
    
    // add transitions to new state s
    // cs.cs_path is current node in tree = current Path (Alignment)

    // enumerate the transitions to q in schema
    for (TransitionList_const_iterator it = _schema.cbegin(q);
         it != _schema.cend(q); ++it)
    {
        const Transition& t = *it;    // transition of schema
        assert(t.inner() || t.terminal());
        size_t a = t.arity();          //  arity of schema transition

        // leaf schema transition:
        // add at most one leaf transition to ComboWTA
        if (t.terminal())
        {
            assert (a == 0);
            // for such transition, the body is a singleton containing a label
            state_t label = t.label();

            // label must correspond to cs without grace-rests
            // we do not count grace-rest in computation of the complexity weight
            if (cs.compatible(label))
            {
                TRACE("  {} -> <{}> ({}) compatible with seg: llen={}, rlen={}, add terminal tr.",
                      s,
                      label,
                      t.weight(),
                      cs.cs_path->lsize(),
                      cs.cs_path->rsize());
                
                // copy
                Weight tweight = t.weight();
                assert (! tweight.unknown());
                assert (tweight.hasType("ViterbiWeight") ||
                        tweight.hasType("TropicalWeight"));

                assert(CST_WEIGHT_TYPE == WeightDom::STOCHASTIC ||
                       CST_WEIGHT_TYPE == WeightDom::PENALTY);
                // QP_WEIGHT == WEIGHT_STOCHASTIC
                if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )                
                {
                    assert (tweight.hasType("ViterbiWeight"));
                    tweight *= Weight(new PerfoWeight(segment,
                                                      cs.cs_path,
                                                      cs.cs_pre,
                                                      cs.cs_post));
                }
                // QP_WEIGHT == WEIGHT_PENALTY
                else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
                {
                    assert (tweight.hasType("TropicalWeight"));
                    // ALPHA applied to dist only
                    tweight.scalar(1.0 - CST_ALPHA);
                    // compute distance to input segment
                    Weight dist = Weight(new Distance(segment,
                                                      cs.cs_path));
                    TRACE("  {} -> <{}> dist={}", s, label, dist);
                    dist.scalar(CST_ALPHA);
                    // new transition weight =
                    // (1 - alpha) * former transition weight + alpha * distance
                    tweight *= dist; // tropical weight product is a sum
                }
                else
                {
                    ERROR("unxepected weight type");
                }
                
                // we add all events (including grace-rests)
                // in the label of the new transition
                // i.e. concrete_label != label in case of grace rests
                // or in case of abstract label.
                state_t concrete_label;
                if (Label::continuation(label))
                {
                    concrete_label = label;
                }
                else
                {
                    assert (Label::abstract(label,
                                            cs.cs_pre + cs.cs_path->lsize()));
                    concrete_label = cs.cs_pre + cs.cs_path->lsize();
                }
                
                Transition newt = Transition(concrete_label, tweight);
                assert(newt.terminal());
                tv.add(newt);
                TRACE("  {} -> <{}> add {}", s, label, newt);
            }
            
            // otherwise add no transition
            else
            {
                  TRACE("  {} -> <{}> incompatible with seg: llen={}, rlen={}.",
                        s,
                        label,
                        cs.cs_path->lsize(),
                        cs.cs_path->rsize());
            }
        }

        // inner schema transition:
        // add zero or several transitions to ComboWTA (acc. to guesses for post values)
        // do not descent if there are no point in Alignement
        else if (t.inner() && cs.cs_path->inhabited())
        {
            assert (a > 1);
            // conditions: post must be propagated from target cs to rightmost child
            // i.e. post_a = post
            
            // post for the last element of a-partition of cs_path
            // is the max possible post for rightmost child (propagated post)
            pre_t maxpost = cs.cs_path->sub(segment, iheap, a, a-1)->rsize();
            
            if (cs.cs_post > maxpost)
            {
                TRACE("combo state {} incompatible with rsize of part {}={}",
                      cs,
                      a,
                      maxpost);

                break; // next transition
            }
            
            if (cs.cs_post <= maxpost)
            {
                // this aux. vector will store all the possible values
                // of the a-1 first post of child ComboStates,
                // between 0 and the max allowed post value defined in vp (r_size)
                std::vector<pre_t> posts(a-1);
                // initialized to null vector
                for (int i = 0; i < a-1; i++)
                    posts[i] = 0;
                
                // enumeration of all the possible posts vectors (of length a-1)
                // and addition of one transition for each one
                bool cont = true;
                while (cont)
                {
                    // construct and add a new transition
                    // defined by the current posts vector and computed Alignment's
                    // the weight Distance(w) is a combination of null distance
                    // and the weight w of the original schema transition
                    // It is the same for all the ComboWTA transitions
                    // @todo shared pointers?
                    // we clone the letter weight of transition t
                    assert (! t.weight().unknown());
                    Transition newt;
                    
                    // copy
                    Weight tweight = t.weight();
                    assert(! tweight.unknown());
                    assert(tweight.hasType("ViterbiWeight") ||
                            tweight.hasType("TropicalWeight"));
                    
                    assert(CST_WEIGHT_TYPE == WeightDom::STOCHASTIC ||
                           CST_WEIGHT_TYPE == WeightDom::PENALTY);

                    // QP_WEIGHT == WEIGHT_STOCHASTIC
                    if ( CST_WEIGHT_TYPE == WeightDom::STOCHASTIC )
                    {
                        assert(tweight.hasType("ViterbiWeight"));
                        // do not change tweight
                    }
                    // QP_WEIGHT == WEIGHT_PENALTY
                    else if ( CST_WEIGHT_TYPE == WeightDom::PENALTY )
                    {
                        assert (tweight.hasType("TropicalWeight"));
                        // ALPHA applied to dist only
                        tweight.scalar(1.0 - CST_ALPHA);
                    }
                    else
                    {
                        ERROR("unxepected weight type");
                    }

                    
                    // same for WEIGHT_STOCHASTIC and WEIGHT_PENALTY
                    newt = Transition(tweight); // copy of weight
                    
                    // propagation of pre from target cs to leftmost child
                    pre_t pre = cs.cs_pre;
                    for(int i = 0; i < a-1; i++)
                    {
                        // recursive registration of new ComboState i of transition
                        // cannot be initial (@todo AV)
                        state_t news = addComboState(ComboState(t.at(i),
                                           cs.cs_path->sub(segment, iheap,a,i),
                                           pre,
                                           posts[i]));
                        newt.push(news);
                        pre = posts[i]; // next pre is current post
                    }
                    // recursive registration of last ComboState of transition
                    state_t news = addComboState(ComboState(t.at(a-1),
                                       cs.cs_path->sub(segment, iheap,a,a-1),
                                       pre,
                                       cs.cs_post));
                    newt.push(news);
                    assert(newt.inner());
                    assert(newt.size() == a);
                    TRACE("  {} -> {}", s, newt);
                    tv.add(newt);

                    // construct next posts vector (of length a-1)
                    for (int i = 0; ; )
                    {
                        posts[i]++;
                        // we reach max value for post[i]
                        TRACE("CS {}={}, sub({},{}).rsize={} posts[i]={}",
                              s,
                              cs,
                              a,
                              i,
                              cs.cs_path->sub(segment, iheap,a,i)->rsize(),
                              posts[i]);
                        if (posts[i] >
                            cs.cs_path->sub(segment, iheap,a,i)->rsize())
                        {
                            // we have constructed all possible posts
                            if (i+1 == a-1)
                            {
                                cont = false; // break the while loop
                                break;
                            }
                            else
                            {
                                posts[i] = 0;
                                i++;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                } // while flag loop
            }
            // else (post too big) do not add transitions
        } // end inner transition
    }
    return s;
}


state_t ComboWTA::initial(pre_t pre, pre_t post) const
{
    assert (_initials.size() > pre);
    assert (_initials[pre].size() > post);
    return _initials[pre][post];
}


ComboWTA::ComboWTA(const InputSegment* seg, size_t bloc,
                   const WTA& schema, pre_t pre):
WTA(schema.weight_zero(), pre),
_schema(schema),
segment(seg),
iheap(new IntervalHeap())
{
    _statemap.clear();
    _cpt = 0;
    // @todo : what with bloc?
    //    _tree = new BarIntervalTree(seg, bloc);
    _tree = iheap->make(seg, Rational(1));

    _max_post = _tree->rsize();
    state_t init = _schema.initial();
    _initials.resize(_max_pre + 1);

    // construction of initial ComboState's
    // with:
    // - initial schema state
    // - Alignment covering the whole segment
    // - _max_post values between 0 and the number of points in second half of segment
    // - _max_pre values between 0 and the number given
    for (pre_t i = 0; i <= _max_pre; i++)
    {
        _initials[i].resize(_max_post+1);
        for (pre_t j = 0; j <= _max_post; j++)
        {
            addComboState(ComboState(init, _tree, i, j));
            // the other ComboState's will be added recursively
        }
    }
    
    // end of construction
    // destroy all Alignments (Paths)
    delete _tree;
    // destroy all ComboStates
    _statemap.clear();
}


/// @}
