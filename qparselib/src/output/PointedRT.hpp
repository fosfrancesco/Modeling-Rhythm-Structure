//
//  PointedRT.hpp
//  qparse
//
//  Created by Florent Jacquemard on 06/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


// Rhythm Trees (RT) extended with pointers, in leaves, to events 


#ifndef PointedRT_hpp
#define PointedRT_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <assert.h>

#include "MusEvent.hpp"
#include "InputSegment.hpp"
#include "Label.hpp"
#include "RT.hpp"



class PointedRhythmTree : public RhythmTree
{
public:
    // empty for inner nodes
    // pointers to events of input segment for leaves
    std::vector<const MusEvent*> events;
    //std::vector<const MusPoint*> events;


    // empty inner tree (not terminal)
    // the child list must be completed with add
    PointedRhythmTree();
    
    // single leaf rhythm tree
    // (terminal tree)
    PointedRhythmTree(label_t lab);
    
    // build an extended
    PointedRhythmTree(const RhythmTree*, const InputSegment*, size_t i = 0);
    
    ~PointedRhythmTree();
    
    // first index of input segment not in this tree
    // of size of input segment if there is none
    inline size_t next() { return _next; }
    
protected:
    size_t _next;
    
    // sime signature
    //ScoreModel::ScoreMeter _ts;
};


#endif /* PointedRT_hpp */


/// @}
