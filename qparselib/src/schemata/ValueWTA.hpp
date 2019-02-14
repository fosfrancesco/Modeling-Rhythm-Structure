//
//  ValueWTA.hpp
//  qparse
//
//  Created by Florent Jacquemard on 15/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{



#ifndef ValueWTA_hpp
#define ValueWTA_hpp

#include <stdio.h>

#include <assert.h>
#include <array>
#include <queue>
#include <unordered_map>

#include "Label.hpp"
#include "State.hpp"
#include "WTA.hpp"
#include "DurationList.hpp"
#include "DurationTree.hpp"


//class DurationList; // Rhythmic Value




/// tmp state structure for construction of ValueWTA
/// casted into state_t after construction
///
/// value state = (q:int, d:DurationList) ou label (feuille)
/// q: state base schema
/// d: current duration list
class ValueState
{
public:
    
    //ValueState();
    
    ValueState(state_t, DurationTree*);
    
    ~ValueState();
    
    state_t state() const { return _state; }

    inline ValueList value() const { assert(_tree); return _tree->top; }

    inline DurationTree* tree() const { assert(_tree); return _tree; }
    
    bool operator==(const ValueState& s) const;
    
    bool compatible(label_t label) const;
    
    friend std::ostream& operator<<(std::ostream&, const ValueState&);
    
private:
    /// state of base schema
    state_t _state;

    /// sequence of ratios associated to this state (shared structure)
    DurationTree* _tree;
    
};


struct ValueStateHasher
{
    std::size_t operator()(const ValueState& vs) const
    {
        using std::size_t;
        using std::hash;
        
        // see constant.h
        size_t h = HASH_SEED;
        h = h * HASH_FACTOR + hash<state_t>()(vs.state());
        h = h * HASH_FACTOR + hash<ValueList>()(vs.value());
        return h;
    }
};

//namespace std {
//    template <> struct hash<ValueState>
//    {
//        size_t operator()(const ValueState& vs) const
//        {
//            return hash<state_t>()(vs.state()) ^ hash<DurationList>()(vs.value());
//        }
//    };
//}

typedef std::unordered_map<ValueState, state_t, ValueStateHasher> Valuemap;


/// Value WTA
/// is a special kind of WTA associated to an initial WTA (schema)
/// and a rhythmic value (DurationList).
///
/// It characterizes the trees of the schema language
/// (with weight defined by schema)
/// having the given rhythmic value.
///
/// table of transitions
/// construction top-down, given an initial schema (WTA) and a DurationList
class ValueWTA: public WTA
{
public:
    
    /// construction from given initial list and WTA (base schema)
    ValueWTA(const DurationList&, const WTA&);
    
    virtual bool hasType(std::string code) const
    { return (code == "ValueWTA"); }

private:
    // Global variables for the WTA construction
    
    const WTA& _schema;
    
    /// counter for new WTA states
    state_t _cpt;
    
    /// map of ValueStates into their index in WTA
    /// tmp (only for constructor)
    ///unordered_map<cs_key, state_t, container_hasher> _statemap;
    Valuemap _statemap;
    
    /// tree of DurationLists organized hierarchically
    /// the ValueStates use the pointers stored in this tree
    DurationTree* _tree;
    
    // addValueState(vs, flag)
    /// returns the ValueWTA state
    /// associated to the ValueState vs
    /// if there exists one.
    /// otherwise:
    /// -  a new ValueWTA state_t s is created,
    /// -  s is associated to vs,
    /// -  s is added to the transition table
    /// -  the ValueWTA transitions with head s are computed
    ///    and added to the table
    /// -  s is returned
    state_t addValueState(const ValueState& vs, bool initial=false);

    // use ValueState.compatible
//    bool compatible(label_t label, const ValueState& vs);
    
};

#endif /* ValueWTA_hpp */


/// @}
