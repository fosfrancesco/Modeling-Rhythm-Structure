//
//  RT.cpp
//  qparse
//
//  Created by Florent Jacquemard on 16/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "RT.hpp"
#include <sstream>

#define RT_PAR_OPEN '('
#define RT_PAR_CLOSE ')'
#define RT_SEP ','   // not used


// empty sequence = root position
Position::Position():
_content()
{ }

Position::Position(const Position& p):
_content(p._content)
{ }

bool Position::empty() const
{
    return _content.empty();
}

size_t Position::length() const
{
    return _content.size();
}

// concatenate given int to this position
// int must be positive
void Position::operator+=(size_t a)
{
    assert (a >= 0);
    _content.push_back(a);
}


void Position::print(std::ostream& o) const
{
    o << "[";
    size_t len = _content.size();
    
    for (size_t i = 0; i < len; i++)
    {
        o << _content[i] << ", ";
    }
    // last element
    if (len > 0)
    {
        o << _content[len-1];
    }
    o << "]";
}


std::ostream& operator<<(std::ostream& o, const Position& pos)
{
    pos.print(o);
    return o;
}















RhythmTree::RhythmTree():
_label(-1),
_children()
{ }


RhythmTree::RhythmTree(label_t lab):
_label(lab),
_children()
{
    assert (lab >= 0);
}


RhythmTree::RhythmTree(const string& s):
_label(-1),
_children()
{
    if (s.empty())
        ERROR("RhythmTree from empty string");

    //std::istringstream in(s);   //make a stream from the string description
    std::string::const_iterator it = s.begin();
    std::string::const_iterator end = s.end();
    assert (it != end);
    read_tree(it, it, end);
}



void RhythmTree::read_tree(std::string::const_iterator& it,
                           const std::string::const_iterator& beg,
                           const std::string::const_iterator& end)
{
    if (it == end)
    {
        ERROR("read_tree: parse error(EOS)");
        throw "error parsing tree";
    }
    else if (std::isspace(*it))
    {
        read_space(it, beg, end);
        read_tree(it, beg, end);
    }
    else if (std::isdigit(*it))
    {
        read_int(it, beg, end);
    }
    else if (*it == RT_PAR_OPEN)
    {
        it++;
        read_list(it, beg, end);
        read_space(it, beg, end);
        if (*it == RT_PAR_CLOSE)
            it++;
        else
        {
            ERROR("read_tree: error at {} (par)", std::distance(beg, it));
            throw "error parsing tree";
        }
    }
    else
    {
        ERROR("read_tree: parse error at {} (unexpected symbol)",
              std::distance(beg, it));
        throw "error parsing tree";
    }
}


void RhythmTree::read_space(std::string::const_iterator& it,
                            const std::string::const_iterator& beg,
                            const std::string::const_iterator& end)
{
    while (it != end && std::isspace(*it))
    {
        it++;
    }
}


void RhythmTree::read_int(std::string::const_iterator& it,
                          const std::string::const_iterator& beg,
                          const std::string::const_iterator& end)
{
    assert (isdigit(*it));
    int v = 0;
    while (it != end && isdigit(*it))
    {
        v = v * 10 + *it - '0';
        it++;
    }
    assert (v >= 0);
    _label = v;
}


void RhythmTree::read_list(std::string::const_iterator& it,
                           const std::string::const_iterator& beg,
                           const std::string::const_iterator& end)
{
    if (it == end)
    {
        ERROR("read_list: parse error (EOS)");
        throw "error parsing tree list";
    }
    else if (std::isspace(*it))
    {
        read_space(it, beg, end);
        read_list(it, beg, end);
    }
    else if (std::isdigit(*it) || (*it == RT_PAR_OPEN))
    {
        RhythmTree* t = new RhythmTree();
        t->read_tree(it, beg, end);
        _children.push_back(t);
        read_list(it, beg, end);
    }
    else if (*it == RT_PAR_CLOSE)
    {
        // end
    }
    else
    {
        ERROR("read_list: parse error at {} (unexpected symbol)",
              std::distance(beg, it));
        throw "error parsing tree list";
    }
}


RhythmTree::~RhythmTree()
{
    // recursive destruction
    for (std::vector<RhythmTree*>::iterator i = _children.begin();
         i != _children.end(); ++i)
    {
            delete *i;
    }
    _children.clear(); //destroy the content
}


bool RhythmTree::terminal() const
{
//    return _children.empty();
    return (_label >= 0);
}


label_t RhythmTree::label() const
{
    assert (this->terminal());
    return _label;
}


bool RhythmTree::continuation() const
{
    assert (this->terminal());
    return Label::continuation(label());
}


bool RhythmTree::single_event() const
{
    assert (this->terminal());
    return (Label::nbEvents(label()) == 1);
}


size_t RhythmTree::nbgn() const
{
    assert (this->terminal());
    return (Label::nbGraceNotes(label()));
}


size_t RhythmTree::arity() const
{
    if (this->terminal())
        return 0;
    else
        return (_children.size());
}


RhythmTree* RhythmTree::child(size_t i) const
{
    assert (this->inner());
    assert (i < _children.size());
    
    return _children[i];
}


void RhythmTree::add(RhythmTree* t)
{
    assert (this->inner());
    assert (t);

    _children.push_back(t);
}


bool RhythmTree::reducible() const
{
    if (terminal())
        return false;
    else
    {
        assert (inner());
        assert (_children.size() > 0);
        RhythmTree* head = _children[0];
        assert (head);
        if (head->terminal())
            return (tail_redex() || tail_reducible());
        else if (head->reducible())
            return true;
        else
            return tail_reducible();
    }
}

bool RhythmTree::tail_redex() const
{
    assert (inner());
    size_t a = this->arity();
    assert (a > 1);
    
    for (size_t i = 1; i < a; i++)
    {
        RhythmTree* sub = _children[i];
        assert (sub);
        if (sub->terminal() && sub->continuation())
            continue;
        else
            return false;
    }
    return true;
}

bool RhythmTree::tail_reducible() const
{
    assert (inner());
    size_t a = this->arity();
    assert (a > 1);

    for (size_t i = 1; i < a; i++)
    {
        assert (_children[i]);
        if (_children[i]->reducible())
            return true;
    }
    return false;
}

bool RhythmTree::tie() const
{
    return ((this->terminal()) && (Label::continuation(this->label())));
}

bool RhythmTree::tied() const
{
    if (terminal())
    {
        return (Label::continuation(this->label()));
    }
    else // inner()
    {
        assert (_children.size() > 0);
        return (_children[0]->tied());
    }
}

bool RhythmTree::binary() const
{
    return ((this->inner()) && (this->arity() == 2));
}

bool RhythmTree::second_tied() const
{
    return ((this->binary()) &&
            (_children[1]->tied()));
}

bool RhythmTree::dot_after() const
{
    return ((this->binary()) &&
            (_children[0]->tie()));
}

bool RhythmTree::dot_before() const
{
    return ((this->binary()) &&
            (_children[1]->tie()));
}

string RhythmTree::to_string() const
{
    if (terminal())
    {
        label_t a = this->label();
        size_t g = Label::nbGraceNotes(a);
        assert (a >= 0);

        if (Label::continuation(a)) // tie
        { return "-"; } // { return "○"; }
        else if (g == 0)            // single note
        { return "●"; }
        else                        // graces notes + note
        {
            //return (patch::to_string(Label::nbGraceNotes(a)+1)+"●");
            //wchar_t g = '\xF8';
            //const char& g = string("○").at(0);
            //string gn(Label::nbGraceNotes(a), g); // "●";
            string gn = "";
            for (int i = 0; i < Label::nbGraceNotes(a); i++)
                gn += "○";
            gn += "●";
            return gn;
        }
    }
    else // inner()
    {
        size_t a = this->arity();
        assert (a > 1);
#if QP_PLATFORM == PLATFORM_DARWIN
        std::string res = std::to_string(a);
#elif QP_PLATFORM == PLATFORM_CYGWIN
        std::string res = std::to_string(a);
#elif QP_PLATFORM == PLATFORM_LINUX
        std::string res = patch::to_string(a);
#elif QP_PLATFORM == PLATFORM_FREEBSD
        std::string res = std::to_string(a);
#else
#error "unknown PLATFORM"
#endif
        
        res += "(";
        for (size_t i = 0; i < a; i++)
        {
            res += _children[i]->to_string();
            if (i < a-1) { res += ", "; }
        }
        res += ")";
        return res;
    }
}

std::ostream& operator<<(std::ostream& o, const RhythmTree& t)
{
    o << t.to_string();
    
    return o;
}



/// @}
