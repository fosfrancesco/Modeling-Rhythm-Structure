//
//  PreWTA.cpp
//  qparse
//
//  Created by Florent Jacquemard on 02/05/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#include "PreWTA.hpp"


PreState::PreState():ps_state(0), ps_pre(0), ps_post(0)
{}


PreState::PreState(state_t s, pre_t pre, pre_t post):
ps_state(s),
ps_pre(pre),
ps_post(post)
{
    rehash();
}


PreState::PreState(const PreState& ps):
ps_state(ps.ps_state),
ps_pre(ps.ps_pre),
ps_post(ps.ps_post)
{
    rehash();
}

PreState::~PreState()
{
    // ps_path deleted with _tree (avoid double delete)
    // delete ps_path;
}

void PreState::rehash()
{
    _hash[0] = ps_state;
    _hash[1] = ps_pre;
    _hash[2] = ps_post;
}

bool PreState::operator==(const PreState& s) const
{
    for (int i = 0; i < _hash_len; i++)
    {
        if (_hash[i] != s._hash[i]) return false;
    }
    return true;
}

// lexicographic comparison on hash value (size_t[3])
bool PreState::operator<(const PreState& s) const
{
    for (int i = 0; i < _hash_len; i++)
    {
        if (_hash[i] > s._hash[i]) return false;
        else if (_hash[i] < s._hash[i]) return true;
        //otherwise _hash[i] == s._hash[i] : continue
    }
    return false;   //they are equal
}

std::ostream& operator<<(std::ostream& o, const PreState& ps)
{
    o << ps.ps_pre << ".";
    o << ps.ps_state << ".";
    o << ps.ps_post;
    return o;
}

state_t PreState::serialize()
{
    return SerialLabel::serialize(ps_pre, ps_post, ps_state);
}


// exists path alignment such that SerialLabel::compatible(label, alignment)
bool PreState::compatible(label_t label) const
{
    return(    (SerialLabel::pre(label)  == ps_pre)
           && (SerialLabel::post(label) == ps_post));
}


// static function
bool PreState::compatible_post(state_t s, const AlignedInterval* al)
{
    assert(al);
    // after subdivisions, at most r_size points of al will be aligned to right
    return(SerialLabel::post(s) <= al->rsize());
}









PreWTA::PreWTA(const WTA& schema):
WTA(schema.weight_zero()),
_schema(schema)
{
    _statemap.clear();
    
    pre_t _max_pre = CST_MAX_GRACE;
    pre_t _max_post = CST_MAX_GRACE;
    state_t init = _schema.initial();
    _initials.resize(_max_pre + 1);
    
    // construction of initial PreStates with:
    // - initial schema state
    // - Alignment covering the whole segment
    // - _max_post values between 0 and the number of points in second half of segment
    // - _max_pre values between 0 and the number given
    for (pre_t i = 0; i <= _max_pre; i++)
    {
        _initials[i].resize(_max_post+1);
        for (pre_t j = 0; j <= _max_post; j++)
        {
            addPreState(PreState(init, i, j));
            // the other PreStates will be added recursively
        }
    }
    
    // destroy tmp table of PreStates
    _statemap.clear();
}


pre_t PreWTA::pre(state_t s)
{
    return SerialLabel::pre(s);
}

pre_t PreWTA::post(state_t s)
{
    return SerialLabel::post(s);
}

state_t PreWTA::state(state_t s)
{
    if (SerialLabel::continuation(s))
        return 0;
    else
        return (1 + SerialLabel::nbGraceNotes(s));
    // return (SerialLabel::nbGraceNotes(s) + (1 - SerialLabel::continuation(s)));
}


state_t PreWTA::addPreState(const PreState& ps)
{
    if (TRACE_LEVEL > 1) { cout << "pre-state: " << ps; }
    assert (ps.ps_pre  <= CST_MAX_GRACE);
    assert (ps.ps_post <= CST_MAX_GRACE);
    
    // pre-state found in map: pre-state has been treated already
    std::map<PreState, state_t>::const_iterator it = _statemap.find(ps);
    if (it != _statemap.end())
    {
        if (TRACE_LEVEL > 1) { cout << " = state " << it->second << " (old)\n"; }
        return it->second;
    }
    
    // otherwise, create new state
    state_t s = SerialLabel::serialize(ps.ps_pre, ps.ps_post, ps.ps_state);
    if (TRACE_LEVEL > 1) { cout << " (" << s << ")"; }
    
    // add map of current PreState to new state
    _statemap[ps] = s;
    //register state
    bool initial = false;
    
    state_t q = ps.ps_state;                // current state in schema
    
    // case of initial states
    if (q == _schema.initial())
    {
        if (TRACE_LEVEL > 1) { cout << "*"; }
        assert (_initials.size() > ps.ps_pre);
        assert (_initials[ps.ps_pre].size() > ps.ps_post);
        _initials[ps.ps_pre][ps.ps_post] = s;
        if ((ps.ps_pre == 0) && (ps.ps_post == 0))
        {
            _initial = s;
        }
        initial = true;
    }
    
    if (TRACE_LEVEL > 1) { cout << "\n"; }

    // register state s
    TransitionList& tv = add(s, initial); // empty vector of Transitions

    // enumerate the transitions to q in schema
    for (TransitionList_const_iterator it = _schema.cbegin(q);
         it != _schema.end(q); ++it)
    {
        const Transition& t = *it;         // transition of schema
        assert(t.inner() != t.terminal()); // exclusive or
        size_t a = t.size();               // arity of schema transition
        assert (a >= 1);
        
        if (TRACE_LEVEL > 1)
        {
            cout << "  old transition: " << q << " =" << t << "\n";
        }
        
        // leaf schema transition:
        // add at most one leaf transition to PreWTA
        if (t.terminal())
        {
            assert (a == 1);
            // for such transition, the body is a singleton containing a label
            state_t label = SerialLabel::serialize(ps.ps_pre, ps.ps_post, t.label());
            assert(ps.compatible(label));
            
            assert (! t.weight().unknown());
            // we clone the letter weight of transition t
            // @todo recompute weight (stochastic conditions)
            Transition newt = Transition(label, t.weight());
            assert(newt.terminal());
            tv.add(newt);
            if (TRACE_LEVEL > 1)
            {
                cout << "  new transition: " << ps << " = ";
                cout << "[";
                cout << ps.ps_pre << "." << t.label() << "." << ps.ps_post;
                cout << "]";
                cout << " (" << label << ") ";
                cout << newt.weight();
                cout << "\n";
            }
        }
        
        // inner schema transition:
        // add zero or several transitions to PreWTA
        // (acc. to guesses for post values)
        else if (t.inner())
        {
            // tmp list of transitions to add (to count)
            std::vector<Transition> newts;
            assert (a > 1);
            // conditions: post must be propagated from target ps to rightmost child
            // i.e. post_a = post
            
            // max possible post for rightmost child (propagated post)
            // TBC heuristics to reduce WTA size:
            // retriction for grace notes inside tuples
            pre_t max_post;
            if (a == 2)
                max_post = CST_MAX_GRACE;
            else if (a == 3)
                max_post = 1;
            else
                max_post = 0;

            // this aux. vector will store all the possible values
            // of the a-1 first rr of child PreStates,
            // between 0 and the max allowed rr value defined in vp (r_size)
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
                // It is the same for all the PreWTA transitions
                // @todo shared pointers?
                // we clone the letter weight of transition t
                assert (! t.weight().unknown());
                // @todo recompute weight (stochastic conditions)
                Transition newt = Transition(t.weight());
                // propagation of rp from target cs to leftmost child
                pre_t pre = ps.ps_pre;

                for(int i = 0; i < a-1; i++)
                {
                    // recursive registration of new PreState i of transition
                    // cannot be initial (@todo AV)
                    state_t news = addPreState(PreState(t.at(i), pre, posts[i]));
                    newt.push(news);
                    pre = posts[i]; // next rp is current rr
                }

                // recursive registration of last PreState of transition
                state_t news = addPreState(PreState(t.at(a-1), pre, ps.ps_post));
                newt.push(news);
                assert(newt.inner());
                assert(newt.size() == a);
                newts.push_back(newt); // store in tmp transition vector
                
                // construct next posts vector (of length a-1)
                for (int i = 0; ; )
                {
                    posts[i]++;
                    // we reach max value for rr[i]
                    if (posts[i] > max_post)
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
            } // while flag loop // else (rr too big) do not add transitions

            // normalise the weight of transitions to add
            size_t nb_newts = newts.size();
            if (nb_newts > 0)
            {
                double coeff = 1.0/nb_newts;
                if (TRACE_LEVEL > 1) { cout << "  nb=" << nb_newts << "\n"; }
                if (TRACE_LEVEL > 1) { cout << "  coeff=" << coeff << "\n"; }
                for (size_t i = 0; i < nb_newts; i++)
                {
                    Transition newt = newts[i];
                    newt.scalar(coeff);
                    tv.add(newt);
                    if (TRACE_LEVEL > 1)
                    {
                        cout << "  new transition: " << ps << " = ";
                        cout << "[";
                        for (size_t it = 0; it < t.size(); it++)
                        {
                            state_t prints = newt.at(it);
                            cout << PreWTA::pre(prints) << ".";
                            cout << PreWTA::state(prints) << ".";
                            cout << PreWTA::post(prints) << " ";
                        }
                        cout << "]";
                        //cout << ps.ps_pre << "." << t.label() << "." << ps.ps_post;
                        cout << newt << "\n";
                    }
                }
            }
        } // end case inner transition
    }// enumerate transitions
    return s;
}


state_t PreWTA::initial(pre_t pre, pre_t post) const
{
    assert (_initials.size() > pre);
    assert (_initials[pre].size() > post);
    return _initials[pre][post];
}


std::ostream& operator<<(std::ostream& o, const PreWTA& a)
{
    for (std::map<state_t,TransitionList>::const_iterator i = a._table.begin();
         i != a._table.end(); ++i)
    {
        state_t s = i->first;
        TransitionList tv = i->second;
        for(TransitionList_const_iterator j = tv.cbegin(); j != tv.cend(); j++)
        {
            const Transition& t = *j;
            //o << s << t;
            o << PreWTA::pre(s) << ".";
            o << PreWTA::state(s) << ".";
            o << PreWTA::post(s);
            o << "/" << s;
            o << " = ";
            if (t.inner())
            {
                o << "(";
                for (size_t it = 0; it < t.size(); it++)
                {
                    state_t q = t.at(it);
                    o << PreWTA::pre(q) << ".";
                    o << PreWTA::state(q) << ".";
                    o << PreWTA::post(q);
                    o << "/" << q << " ";
                }
                o << ")";
            }
            else if (t.terminal())
            {
                state_t lab = t.label();
                o << "<" << SerialLabel::pre(lab) << ".";
                o << SerialLabel::nbEvents(lab) << ".";
                o << SerialLabel::post(lab) << "/" << lab << ">";
            }
            o << " " << t.weight();
            o << " \n";
        }
    }
    return o;
}


/// @}
