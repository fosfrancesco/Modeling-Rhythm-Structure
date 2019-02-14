//
//  CountingWTA.hpp
//  schemas
//
//  Created by Florent Jacquemard on 28/11/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup schemata
/// @{


#ifndef CountingWTA_hpp
#define CountingWTA_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "init.hpp"
#include "trace.hpp"
#include "State.hpp"
#include "Label.hpp"
#include "SerialLabel.hpp"
#include "Weight.hpp"
#include "CountingWeight.hpp"
#include "WTA.hpp"
#include "RT.hpp"

/// transtition table ordered by transition's ids
typedef
std::set<std::pair<state_t, Transition&>,
         bool(*)(std::pair<state_t, Transition&>,
                 std::pair<state_t, Transition&>)>
OTransitionTable;

/// copy of WTA dedicated to corpus statistics.
///
/// for WTA weight estimation and WTA construction from corpus.
///
/// construction of WTA with counting weights (unit vectors) from WTA
/// and verbose tree evaluation with feedback.
///
/// @warning only for target SCHEMA
class CountingWTA: public WTA
{
public:
    ///default initializer for cython
    CountingWTA();
    /// copy base WTA
    /// reset weight values to counting weights (unit vectors)
    CountingWTA(const WTA& a);
    
    virtual bool hasType(std::string code) const
    { return (code == "CountingWTA"); }

    /// special version of eval for CountingWeight
    /// with feedback in case of fail
    virtual Weight eval(const RhythmTree& t) const;

    /// it is important to enumerate in same order
    /// for printing and building unit weights!
    friend std::ostream& operator<<(std::ostream&, const CountingWTA&);

protected:
    Weight evalCountingVerbose(const RhythmTree&, state_t, Position) const;

    /// the weight of this WTA are replaced by "CountingWeight"
    /// unit vector of length dim (one unit per transition)
    void resetCounting(size_t dim);
    
    /// copy of transition table
    /// ordered according to the transition's ids (can be iterated).
    OTransitionTable _tableids;
    
    /// pointer to comparison functionå
    static bool(*_trcomp_ptr)(std::pair<state_t, Transition&>,
                              std::pair<state_t, Transition&>);
    
};

#endif /* CountingWTA_hpp */


/// @}
