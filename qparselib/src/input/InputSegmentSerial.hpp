//
//  InputSegmentSerial.hpp
//  squant
//
//  Created by Florent Jacquemard on 06/04/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
/// @defgroup input Input module
///
/// The `input` module contains utilities for reading from and writing to
/// files the data given in input to the quantization by parsing algorithm
/// (schema and segment).


#ifndef InputSegmentSerial_hpp
#define InputSegmentSerial_hpp

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>

#include "init.hpp"
#include "Rational.hpp"
#include "InputSegment.hpp"


/// @brief serialization of an input segment in a text file.
///
/// functions for import, export and comparison (evaluation).
///
/// @ingroup input
class InputSegmentSerial : public InputSegment //InputSegmentMonoOn
{
public:
    /// @brief read input segment from a text file.
    ///
    /// if not present in text file, the musical onsets and durations
    /// are all set to -1.
    /// @param filename name of input text file
    /// @param mono flag is true if we want a monophonic input segment.
    InputSegmentSerial(const std::string filename, bool mono=true);

    InputSegmentSerial(const InputSegmentSerial&);

    virtual ~InputSegmentSerial() {}

    inline std::string filename() const { return _filename; }

    /// @brief export this input segment into given file.
    size_t save(const std::string filename);
    
    /// @brief return the final status for import.
    /// @return 0 if import or export worked well
    /// @return error code > 0 otherwise
    inline size_t status() const { return _status; }
    
private:
    /// @brief name of text file read for building this input segment.
    std::string _filename;
    
    size_t _status;
    
    /// @brief read monophonic input segment with timestamped events
    /// from text file.
    ///
    /// - the first line contains start date (float in seconds)
    /// - the next lines contain event's dates (must be increasing)
    /// - the last line contains end date.
    size_t import_textfile(std::ifstream& file);
    
    size_t export_textfile(std::ifstream& file);
    
    
};


#endif /* InputSegmentSerial_hpp */
