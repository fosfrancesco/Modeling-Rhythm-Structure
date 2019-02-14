//
//  Ptr.tpp
//  squant
//
//  Created by Florent Jacquemard on 19/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#include "Ptr.hpp"


Weight Pointer::terminalWeight(const InputSegment* s,
                               const Transition& tr) const
{
    assert(! tr.weight().unknown());
    assert(tr.terminal());
    assert(this->compatible(tr.label(), true));
    return (tr.weight());
}


Weight Pointer::innerWeight(const Transition& tr) const
{
    assert(! tr.weight().unknown());
    assert(tr.inner());
    return (tr.weight());
    //    return (tr.weight().get_one());
}


/// @}
