//
//  WTAFile.hpp
//  qparse
//
//  Created by Florent Jacquemard on 08/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.

#ifndef WTAFile_hpp
#define WTAFile_hpp

#include <stdio.h>
#include <algorithm>
#include <string>

#include "init.hpp" // global vars
#include "trace.hpp"
#include "Weight.hpp"
// no compile options for WTA weight : load all classes
#include "FloatWeight.hpp"
#include "TropicalWeight.hpp"
#include "ViterbiWeight.hpp"
#include "WTA.hpp"
#include "ScoreMeter.hpp"


/// @brief wrapper for constructing WTA with various flags for weight type.
///
/// @ingroup input
class WTAFile : public WTA
{
public:
    /// @brief default constructor for cython.
    WTAFile();

    // see https://stackoverflow.com/questions/308276/can-i-call-a-constructor-from-another-constructor-do-constructor-chaining-in-c
    // for definition
    // WTAFile(const char* filename,
    //         WeightDom wt = WeightDom::UNDEF,
    //         pre_t pre=0, pre_t post=0);
    
    
    /// @brief read weight type and schema from file.
    ///
    /// @param filename input text file specifying the schema
    /// @param wt weight type (forced)
    ///
    /// if another weight type is given as argument (forced weight type)
    /// - use it as weight type for reading schema if no weight type found in file
    /// - use it to cast schema (force type).
    /// the WTA can be empty in case of error.
    WTAFile(const std::string filename,
            WeightDom wt = WeightDom::UNDEF,
            pre_t pre=0, pre_t post=0);


    /// @brief read schema from file
    /// @param filename input text file specifying the schema
    /// @param count_flag flag to determine the type of weights
    /// @param penalty_flag flag to determine the type of weights
    /// @param stochastic_flag flag to determine the type of weights
    ///
    /// casts weights according to compile options if needed.
    ///
    /// @todo TBR
    WTAFile(const std::string filename,
            bool count_flag=false,
            bool penalty_flag=true,
            bool stochastic_flag=false);
    
    /// @brief same as WTA destructor.
    ~WTAFile();

    /// @brief save to file.
    size_t save(string filename);
    
    /// @brief read time signature from schema file
    ///
    /// @return 0 if a time signature was found in filename
    /// in that case, the time signature is stored in the given ts,
    /// otherwise, ts is left unchanged.
    ///
    /// @warning must be in the form "[timesig int int]" in the file,
    /// with int > 0.
    static bool readTimesignature(const std::string filename,
                                  ScoreModel::ScoreMeter& ts);

private:
    // weight type found in schema file
    //WeightDom _filewt;
    
    // weight type forced by options
    //WeightDom _givenwt;

   
    /// @brief read WTA from file
    ///
    /// create transition of same type as given sample weight
    /// the initial state set is set to singleton { 0 }
    /// in case of parse error, the WTA is empty.
    /// @return error code 0 if file could be loaded into WTA.
    size_t _load(Weight seed, string filename);
    
    /// @brief read the weight type description found in schema file.
    ///
    /// @warning must be in the form "[weight type]" in the file.
    /// @param filename WTA file read.
    /// @return the weight type description found in filename.
    /// @return WeightDom::UNDEF if not found in file.
    static WeightDom _read_weight_type(const std::string filename);
    
    /// @brief read the specification for grace note abstraction
    /// found in filename.
    /// @warning must be in the form "[max_grace int]" in the file,
    /// with int > 0.
    /// @return 0 if not found in file.
    static label_t _read_max_grace(const std::string filename);
    
    /// @brief search an option in input WTA file
    ///
    /// @warning the option must be of one of the following forms
    /// - [option] if arg1 = arg2 = NULL or
    /// - [option int] if arg1 != NULL, arg2 = NULL or
    /// - [option int int] if arg1 != NULL, arg2 != NULL.
    ///   in the second and third cases, int are stored in arg1 and arg2.
    /// @return wether the search succeeded.
    static bool _read_option(const std::string filename,
                             const std::string option,
                             int* arg1=NULL, int* arg2=NULL);

    static WeightDom _choose(WeightDom file_wt, WeightDom given_wt);
    
    /// @brief a weight value of a type corresponding
    /// to the given weight type description.
    static Weight _seed(WeightDom);
    
    /// @todo TBR
    static Weight _seed(bool count_flag,
                        bool penalty_flag,
                        bool stochastic_flag);

};


#endif /* WTAFile_hpp */
