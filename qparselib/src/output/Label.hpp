//
//  Label.hpp
//  qparse
//
//  Created by Florent Jacquemard on 04/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#ifndef Label_hpp
#define Label_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"


/// type for concrete and abstract labels
typedef size_t label_t;


// max value for abstract pre and post
//const label_t MAX_GRACE = 3;

class Event;

enum LabelKind
{
    EVENT,
    TIE,    // continuation
    INNER,  // inner node
};

/// labels for nodes of output Rhythm Trees.
///
/// Inner nodes are simply labeled by arity.
///
/// Leaves are labeled by info on:
/// - input (segment of unquantized points) and
/// - output (quantized points).
///
/// More precisely,
/// - the input info is about the alignement of unquantized input points
///   on the bounds of the interval associated to the node.
///   These are the pre and post values.
/// - the output info is about the number of quantized input points
///   in this interval.
///   - number 0 corresponds to a tie,
///   - number 1 corresponds to a single event,
///   - bigger numbers correspond to a event + grace notes.
///
/// we consider the abstract domain [0,...,MAX_GRACE] for the values of:
/// - i)  the pre and post, and
/// - ii) the number of g.n. + note
///
/// for i) the meaning is
/// - 0: 0
/// - 1: 1
/// - ...
/// - MAX_GRACE: >= MAX_GRACE
///
/// for ii) the meaning is
/// - 0: tie (no event)
/// - 1: 1 note
/// - 2: 1 gn + 1 note
/// - ...
/// - MAX_GRACE: >= MAX_GRACE-1 gn + 1 note (appogiature) = all other cases
///
/// an abstract label is a label in abstract domain.
///
/// a concrete label is a positive integer.
///
/// an abstract label a is an abstraction of a concrete label b if
/// - either b <= MAX_GRACE and a = b
/// - or b > MAX_GRACE and a = MAX_GRACE.
//
// generic label with a kind
// class Label
/// @todo TBR the class Label is not used (except for static members)
class Label
{
public:
    // tie if arity = 0
    // inner node if arity > 0
    Label(int a=0);
    
    size_t arity() const;
    
    bool isLeaf() const { return (_ar == 0); };

    bool isInner() const { return (_ar > 0); };
    
    LabelKind kind() const { return _type; };

    // return the number of grace node encoded in given leaf label
    static size_t nbGraceNotes(label_t);
    
    // number of note + grace notes encoded in given leaf label
    static size_t nbEvents(label_t);
    
    // the given leaf label is a continuation (no event, no grace note)
    static bool continuation(label_t);

    // the given leaf label has an abstract value
    static bool abstract(label_t);
    
    // the first value is an abstraction of the second one
    static bool abstract(label_t a, label_t n);

    // exists c >= 0 such that abstract(a, n+c)
    static bool leqabstract(label_t a, label_t n);
    
    // the content of the given alignment
    // (sub-segment of initial input corr. to an interval)
    // and the concrete values pre and post
    // (points aligned to left and right of interval)
    // correspond to the encoding expressed in the label lab.
//    static bool compatible(label_t label, AlignedInterval* p,
//                           pre_t pre, pre_t post);

protected:
    
    LabelKind _type;

    // arity (0 for leaf)
    size_t _ar;
    
};



/// label for inner node.
/// contains only arity (more info later?)
/// @todo TBR (NOT USED)
class InnerLabel: Label
{
public:
    // Label of inner node with arity given in param
    // 0 grace note, kind note if leaf (a == 0)
    InnerLabel(unsigned int);

};


/// @todo TBR (NOT USED)
class EventLabel: Label
{
public:
    // Label for leaf of kind tie
    EventLabel();

    // Label for leaf of kind event,
    // number of grace notes given in param
    // @todo change to list events ?
    EventLabel(unsigned int n=0);
    
    // to be called only on a leaf
    size_t nbGraceNotes() const;

    // add number of grace notes given in param
    // the type of this Label must be NOTE
    void addGraceNotes(unsigned int);
    
    void pushEvent(Event*);

private:
    // number of events (grace notes + note)
    // 0 for tie
    // > 0 for grace notes + event
    unsigned int _nbe;
    
    // in MIDIcent
    // not used
    std::vector<Event*> _events;
    
};


#endif /* Label_hpp */


/// @}
