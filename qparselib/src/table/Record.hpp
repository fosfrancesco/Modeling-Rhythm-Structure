//
//  Record.hpp
//  squant
//
//  Created by Florent Jacquemard on 12/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup table
/// @{


#ifndef Record_hpp
#define Record_hpp

#include <stdio.h>

//#include "Spointer.hpp"
#include "Rune.hpp"
//#include "Atable.hpp"

template<class P> class Atable;
//template<class P> class Run;


/// abstract class describing the basic functionalities of a record.
///
/// each record is associated to a Ptr
/// it can be filled with add
/// and can be interrogating with best,
/// for retrieving the best runs for the associated Ptr.
///
/// when uncomplete runs are added to the record
/// (either by the record or from outside)
/// their weight must be computed using a table.
///
/// there are 3 similar kinds of Run* that should not be added in record:
/// TBC should not be returned by best on the record ?
/// - NULL ptr to Run
/// - ptr to Run with unknown weight (i.e. weight with NULL letter)
///   that case includes null runs.
/// - ptr to Run with weight == zero (acc. to test zero()).
/// a Run not in these 3 case is called valid.
///
/// [update] the runs with weight zero (still invalid) can be added to records
/// but an error message is displayed (for debugging).
//template<class P, template<typename> class R = Run>
template<class P>
class Record
{
public:
    Record(const P&, RunCompare<P>);

    /// add a run to the record.
    virtual void add(Run<P>*) = 0;
    
    /// returns the k-th best run of the record
    /// @param table can be used to compute weights of new runs.
    /// @param k rank (as in k-best)
    virtual Run<P>* best(Atable<P>* table, size_t k=1) = 0;
    
    inline const P& key() { return _key; }

    virtual bool empty() const = 0;
    
    /// state - possible values:
    /// 0 : empty (record just created no run was stored)
    /// 1 : add(_key) was not called
    ///     but add(p) was called for p partial and subsuming _key
    /// 2 : add(_key) was called
    /// 3 : some run has been stored
    ///     but we are not in 1 or 2. should not happen.
    ///
    /// The state is not changed inside the Record class.
    /// It is changed by callers (table.add).
    unsigned int state;

protected:

    /// copy of the key associated to the record in container.
    P _key;
    
    /// comparison function.
    RunCompare<P> _comp;
    
    /// number of candidate bests constructed.
    size_t _nb_cand;
    
    /// number of best not added to the list because of optimization filters.
    size_t _nb_best_rejected;
    
    bool valid(Run<P>*);

};

// separated definition of template class
#include "Record.tpp"


#endif /* Record_hpp */


/// @}
