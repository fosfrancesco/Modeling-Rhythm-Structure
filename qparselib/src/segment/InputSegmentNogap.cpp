//
//  InputSegmentNogap.cpp
//  qparse
//
//  Created by Florent Jacquemard on 13/06/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "InputSegmentNogap.hpp"


InputSegmentNogap::InputSegmentNogap(const InputSegment& seg, bool norest):
InputSegment(seg.rbegin(), seg.rend()) // initialy empty list of events
{
    // create a new _events vector for this segment by copy of given seg.
    
    // pointer to a currently sounding event (in events of this segment)
    // with latest expected link (in seg)
    MusPoint* longest_sounding = NULL;
    // and the index of latest expected link (in seg)
    //long longest_index = MUSPOINTREF_NULL;
    
    // @todo replace by set of ref to noteon points in this segment
    // ordered by their (non-updated) links in seg
    // when empty : gap
    
    // iterator to the event of seg currently read
    std::vector<MusPoint>::const_iterator seg_it=seg.cbegin();
    // index of seg_it
    long seg_index = 0;
    
    // traverse seg (in index ordering = chronological ordering)
    while (seg_it != seg.cend())
    {
        // current point in segment
        const MusPoint& current = *seg_it;

        // not in a gap (some notes sounding)
        if (longest_sounding != NULL)
        {
            // note-on (beginning of new sounding note)
            if (current.linked != MUSPOINTREF_NULL)
            {
                
            }
            // note_off
            else
            {
                if (longest_sounding->linked != seg_index)
                {
                    this->add_back(current);
                    // @todo update link in
                }
            }
        }
        // in a gap
        else
        {
            // note-on
            if (current.linked != MUSPOINTREF_NULL)
            {
                
            }
            // note_off
            else
            {
                
            }
        }
        
        seg_it++;
        seg_index++;
    }
}


/// @}
