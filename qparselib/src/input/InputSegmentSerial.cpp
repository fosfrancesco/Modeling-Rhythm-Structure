//
//  InputSegmentSerial.cpp
//  squant
//
//  Created by Florent Jacquemard on 06/04/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "InputSegmentSerial.hpp"


InputSegmentSerial::InputSegmentSerial(const std::string filename,
                                       bool mono):
InputSegment(),
_filename(filename),
_status(0)
{
    //assert (mono);
    std::ifstream file;
        
    file.open(filename, std::ios_base::in);
    if( file.is_open() )
    {
        _status = import_textfile(file);
    }
    else
    {
        ERROR("failed to open {}", filename);
        _status = 1;
    }

    assert(0 <= _begin);
    assert(_begin <= _end);
    _len = _end - _begin;
}


InputSegmentSerial::InputSegmentSerial(const InputSegmentSerial& s):
InputSegment(s),
_filename(s._filename),
_status(s._status)
{ }


size_t InputSegmentSerial::import_textfile(std::ifstream& file)
{
    std::vector<double> v;
    int ln = 1;
    
    int count = 0;
    unsigned int state = 0;
    double prev_rdate = -1;
    double rdate = -1;
    long prev = MUSPOINTREF_NULL; // index in this segment
    long current = MUSPOINTREF_NULL;
    
    for(string line; getline(file, line); ln++)
    {
        // skip empty line
        if (line.size() == 0) continue;
        
        std::istringstream in(line);   // make a stream from the line
        if (in >> rdate) // read duration (double)
        {
            if (rdate < 0)
            {
                ERROR("{}:{}: durations must be positive",
                      _filename, ln);
                return 2;
            }

            // first line = begin date
            if (state == 0)
            {
                TRACE("{}: start date {}", _filename, rdate);
                _begin = rdate;
                state = 1;
                continue;
            }
            // second line = first onset
            else if (state == 1)
            {
                // the first point can be at segment beggining
                if(_begin > rdate)
                {
                    ERROR("{}:{}: first point must be after start date",
                          _filename, ln);
                    return 3;
                }
                
                prev_rdate = rdate;
                // unpitched note
                MusEvent* e = new NoteEvent();
                // add as note-on
                prev = this->add_back(e, rdate, 0, true);
                state = 2;
                continue;
            }
            // next lines = onsets
            else if (state == 2)
            {
                // two successive points can coincide
                assert (0 <= prev_rdate);
                if (prev_rdate > rdate)
                {
                    ERROR("{}:{}: successive point must be posterior",
                          _filename, ln);
                    return 4;
                }
                // unpitched note
                MusEvent* e = new NoteEvent();
                // add as note-on
                current = this->add_back(e, rdate, 0, true);
                assert(check_index(prev));
                assert(check_index(current));
                // link previous note to this note
                assert(prev != MUSPOINTREF_NULL);
                this->link(prev, current);
                assert(this->rdate(prev) == prev_rdate);
                //assert(this->rduration(prev) == rdate - prev_rdate);
                TRACE("input_event[{}] at {}s, dur={}s",
                      count, this->rdate(prev), this->rduration(prev));
                count++;
                prev_rdate = rdate;
                prev = current;
            }
        }
        // not a number: skip line (comments etc)
        else
        {
            TRACE("{}: line {} ignored", _filename, ln);
            continue;
        }
    }
    
    // last line is end date
    if (state == 2)
    {
        assert (0 <= rdate);
        assert (prev_rdate == rdate);
        TRACE("{}: end date {}", _filename, rdate);
        _end = rdate;

        // the last point is not an event (it corresponds to the end date)
        assert(! _events.empty());
        assert(check_index(prev));
        // the single event is actually the end date
        if (_events.size() == 1)
        {
            TRACE("empty segment");
        }
        else
        {
            // copy to heap of last event (end date)
            // and link it to the (real) event before.
            this->link(prev, add_floating(_events.back()));
        }
        // delete last (end date) event
        _events.erase(_events.end()-1);
    }
    else
    {
        ERROR ("{}:  the file must contain at least one begin and one end date",
               _filename);
        return 9;
    }
    TRACE("{}: closing, {} events read", _filename, _events.size());
    file.close();
    
    assert(_begin <= _end);
    _len = (_end - _begin);
    return 0;
}


size_t InputSegmentSerial::save(string filename)
{
    std::ofstream file;
    
    file.open(filename, std::ios_base::out);
    if(!file.is_open())
    {
        ERROR("InputSegment export : cannot open {} for writing", filename);
        return 1;
    }
    
    file << _begin << "\n";
    
    for (size_t i = 0; i < _events.size(); i++)
        if(_begin <= _events[i].rdate() && _events[i].rdate() <= _end) {
            file << _events[i].rdate() << "\n";
        }
    
    file << _end << "\n";
    
    file.close();
    return 0;
}


