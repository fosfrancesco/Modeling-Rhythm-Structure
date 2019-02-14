//
//  QDate.hpp
//  qparse
//
//  Created by Florent Jacquemard on 23/10/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @defgroup output Output module
///
/// The `output` module contains representations for the output
/// of the parsing procedure and conversion into music transcription results.

/// @addtogroup output
/// @{


#ifndef QDate_hpp
#define QDate_hpp

#include <stdio.h>
#include <assert.h>
#include <vector>

#include "init.hpp"
#include "trace.hpp"
#include "Rational.hpp"


/// quantified onset values
/// expressed in number of samples.
///
/// the value of RESOLUTION (total number of samples)
/// is not stored in objects of this class.
/// it should be the same for each date created.
class QDate
{
public:
    QDate();
    
    QDate(size_t blocs, size_t rel);
    
    QDate(const QDate&);
    
    ~QDate() {}
    
    virtual QDate& operator= (const QDate&);
    
    virtual QDate* clone() const;
    
    /// number of bloc of length RES.
    inline size_t bloc() const
    { return _quotient; }

    /// quantified date (samples) modulo RES
    /// (date in last bloc).
    inline size_t relative() const
    { return _modulo;}
    
    /// quantified date as rational value.
    Rational absolute(size_t res) const;
    
    void print(std::ostream&) const;

    /// fractional print using resolution value.
    void print(std::ostream&, size_t) const;

    
    friend inline std::ostream& operator<<(std::ostream&, const QDate&);
    
protected:
   
    /// date in samples / RESOLUTION
    /// = bloc number
    size_t _quotient;;

    /// date in samples modulo RESOLUTION
    size_t _modulo;;

};

inline std::ostream& operator<<(std::ostream& o, const QDate& rhs)
{
    rhs.print(o);
    return o;
}


#endif /* QDate_hpp */


/// @}
