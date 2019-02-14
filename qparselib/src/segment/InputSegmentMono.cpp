//
//  InputSegmentMono.cpp
//  qparse
//
//  Created by Florent Jacquemard on 31/05/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @addtogroup segment
/// @{


#include "InputSegmentMono.hpp"


InputSegmentMono::InputSegmentMono(const InputSegment& seg):
InputSegment(seg.rbegin(), seg.rend()) // initialy empty list of events
{
    // create a new _events vector for this segment by copy of given seg.

    // pointer to currently sounding event in events of this segment
    // = linked event with link not met yet
    // there is at most one
    MusPoint* sounding = NULL;
    long sounding_index = MUSPOINTREF_NULL;
    
    // iterator to the event of seg currently read
    std::vector<MusPoint>::const_iterator seg_it=seg.cbegin();
    // index of seg_it
    long seg_index = 0;
    
    // pointer to previous event inserted in events of this segment
    // MusPoint* prev = NULL;
        
    while (seg_it != seg.cend())
    {
        // current point in segment
        const MusPoint& current = *seg_it;

        // ptr to current point when added to the events of this segment
        MusPoint* this_ptr = NULL;

        // the current point is the expected link of the current sounding note
        if (sounding != NULL && sounding->linked == seg_index)
        {
            // insert and update link to the new index in this segment
            sounding->linked = this->add_back(current);
            // keep ptr to new event for later
            this_ptr = &(_events.back());
        }
        
        // note-on (beginning of new sounding note)
        if (current.linked != MUSPOINTREF_NULL)
        {
            // the new note was already added as the expected (end) link
            // of previous sounding
            // OK we are still monophonic
            if (this_ptr != NULL)
            {
                // set new sounding note as the newly inserted event
                // DO NOT INVERT THESE LINES
                sounding_index = sounding->linked;
                sounding = this_ptr;
                
                TRACE("MonoSegment: copy note-on from {} to {}",
                      seg_index, sounding->linked);
            }
            // was not already added (as link)
            else
            {
                // insert
                long new_index = this->add_back(current);
                TRACE("MonoSegment: copy note-on from {} to {}",
                      seg_index, new_index);
                
                if (sounding != NULL)
                {
                    assert(sounding->linked != seg_index);
                    
                    // case of simultaneous notes
                    // we keep only the longest of simultaneous note sounding
                    if ((sounding->rdate() == current.rdate()) &&
                        (rduration(*sounding) >= rduration(current)))
                    {
                        // the new note will have duration 0
                        _events.back().linked = sounding_index;
                        // keep the same sounding note (longer)
                    }
                    else
                    {
                        // cut the current sounding note
                        sounding->linked = new_index;
                        // set new sounding note as the newly inserted event
                        sounding = &(_events.back());
                        sounding_index = new_index;
                    }
                }
                else
                {
                    sounding = &(_events.back());
                    sounding_index = new_index;
                }
            }
        }
        // note-off
        else
        {
            // was not already added
            if (this_ptr == NULL)
            {
                WARN("MonoSegment: skipped note-off {}", seg_index);
            }
            else
            {
                TRACE("MonoSegment: copy linked note-off from {} to {}",
                      seg_index, sounding->linked);
            }
        }
        
        seg_it++;
        seg_index++;
    }
}


/// @}
