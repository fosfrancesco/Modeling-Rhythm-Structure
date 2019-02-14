//
//  Table.hpp
//  squant
//
//  Created by Florent Jacquemard on 12/12/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @defgroup table Table module
///
/// The `table` module contains classes for parse tables and their content.

/// @addtogroup table
/// @{


#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include <assert.h>
#include <unordered_map> // and unordered_multimap
#include <queue>

#include "init.hpp"
#include "trace.hpp"
#include "State.hpp"
#include "Transition.hpp"
#include "Rune.hpp"
#include "Record.hpp"
#include "Atable.hpp"
//#include "Environment.hpp"


template<class P, class R, class H> using MapRecord =
std::unordered_map<P,R,H>;

// needs equality P.operator== and hash function H.operator()
template<class P, class H> using MapInstances =
std::unordered_multimap<P,P,H>;
// other option using P.operator< : std::multimap<P,P>;


/// parse table.
///
/// table defines two main undorered mappings:
///
/// map table:
/// @code map key -> value @endcode where
/// - key of type P = Pointer
/// - value of type R = Record<P> (stores some Run<P>*)
/// - H = Hasher for P
/// - equal+to is op. == defined in P
///
/// table of instances:
/// @code multimap: key -> keys @endcode where
/// - key of type P = Pointer (partial)
/// - keys of type P = complete Pointer instances of key
/// - H = Hasher for P
/// - equal+to is op. == defined in P
//
// P = concrete pointer class (keys in table)
// R = record class (values in table)
// H = PointerHasher (for keys)
template<class P, class R, class H>
class Table : public Atable<P>
{
public:    
    
    /// concrete table.
    /// @see Atable for arguments
    /// @param env the parsing environment must not be NULL
    Table(Parser<P>* env, RunCompare<P> comp);

    ~Table();

    //  best(p)
    /// return k-best run pointed by p
    /// or NULL if there is none.
    /// k is either included in p or the default value 1.
    /// @param p must be complete.
    virtual Run<P>* best(const P& p);
    
    /// tree corresponding to the k-best run in p.
    virtual RhythmTree* bestTree(const P& p);

    /// when the k-best run in p is already computed.
    virtual RhythmTree* bestTree(Run<P>* r);
    
    // add(p, r)
    // interface for adding run r to record of p
    // when run is partially evaluated
    // for lazy k-best processing of candidates
    // p must be complete and have registered entry in table
    // (i.e. best was called)
    // r can be complete or partial
    // @todo TBR
    //virtual void add(const P&, Run<P>*);
    
    //  add(p)
    /// if p complete, create a new record in table for it and process it
    /// (add runs),
    /// if p partial, process it (register instances to table) with addPartial.
    /// @param p can be partial or complete.
    /// @warning p must have yet no associated record in table when complete.
    /// @warning p must not have been added before if partial
    /// (no registered instances).
    /// @return a pointer to the newly created record if p complete.
    /// @return a NULL pointer in this case if p partial.
    Record<P>* add(const P& p);
    
    //  add(p, r, i)
    /// @param p can be complete or partial.
    /// @param r can be complete or partial.
    /// @param i if p is complete, then i must be an pointer to the entry
    ///        for p in table,
    ///        otherwise (p partial), i is NULL.
    ///
    /// add possible instances of run r
    /// to the entries in table for corresp. to possible instances for p.
    /// dispatch to the four functions below according to p and r.
    /// @return 0 if the run or one instance of the run (at least)
    ///           was added to the table.
    /// @return > 0 otherwise.
    virtual size_t add(const P& p, Run<P>* r, Record<P>* i);
    
    // DEBUG functions
    
    virtual size_t nb_entries() { return _nb_rows; }
    virtual size_t nb_runs() { return _nb_runs; }

    void dump_table() const;

    void dump_instances() const;
   
    
private:
    MapRecord<P,R,H> _table;
    
    /// associate to every registered partial ptr p
    /// an iterator to pairs (p', r)
    /// where p' is a complete instance of p assciated to r in _table
    MapInstances<P,H> _instances;
    // was
    // typename std::unordered_multimap<P, P, H> _instances;

    /// stats.
    size_t _nb_rows;
    /// stats.
    size_t _nb_runs;
    
// access to tables

    //  getRecord(p, state)
    /// return an pointer to the table entry (record) for p;
    /// the entry is created if there is none.
    /// @param p must be complete.
    Record<P>* getRecord(const P& p, unsigned int state = 0);

    /// return a pair,
    /// whose first component is an iterator
    /// to the first instance of p registered
    /// and second component is an iterator to the end of
    /// the range of instances of p.
    /// The instances range between these two iterators,
    /// including pair::first, but not pair::second.
    std::pair<typename MapInstances<P,H>::iterator,
              typename MapInstances<P,H>::iterator>
    getInstances(const P&);
    
    /// if the pair (pp, pc) is registered in the instance table.
    bool existsInstance(const P&, const P&) const;

    
// construction of tables
    
    //  addComplete(p, it)
    /// the record pointed by it (second param) has been updated
    /// (filled with all runs with target p)
    /// and can be asked for best run (or k-best runs).
    /// @param p target pointer, must be complete,
    /// it must be an iterator to a pair associated to p in table
    /// (first component must be p).
    /// @param it record to fill with runs rageting p.
    size_t addComplete(const P& p, Record<P>* it);
    
    // addPartial(p)
    /// table of instances is updated with all possible instances of p, and
    /// map table is updated with all runs for all these instances of p.
    /// @param p must be partial.
    /// @warning this must the first call to addPartial for p.
    size_t addPartial(const P& p);

    //  add(p, i).
    /// Compute and add all complete runs with target p
    /// (or complete instances of p if p partial)
    /// to records associated to p
    /// (associated to all complete instances of p if p partial)
    /// using WTA transition table to compute these runs.
    /// @param p can be complete or partial,
    /// @param i if p is complete then i must be a pointer
    /// to the record associated to p in table.
    /// otherwise it is NULL.
    ///
    /// @warning must be called by addComplete or addPartial.
    size_t add(const P& p, Record<P>* i);
    
    /// subcase of add(p, i) for the case when p has WTA state s.
    /// @warning must be called by add(p, it)
    /// @todo TBR
    void newWTARun(const P& p,
                   Record<P>* i,
                   state_t s);

    /// subcase of add(p, i) for the case when p has meta state s.
    /// @warning must be called by add(p, it)
    /// @todo TBR
    void newMetaRun(const P&, Record<P>*, state_t s);

    // if p is complete, then i must be a pointer to the entry for p in table
    // (record).
    // otherwise (p partial), i is NULL.
    // TBC
    //void add(const P&, Run<P>*, R*);
    
    /// particular case of add(p, r, i)
    /// add r to the record in the given entry for p in the map table.
    /// @param p must be complete.
    /// @param r must be complete.
    /// @param i must be an pointer to the entry for p in table.
    /// @return 0
    size_t addTable(const P& p, Run<P>* r, Record<P>* i);

    /// particular case of add(p, r, it)
    /// create the instance p' of p defined by r,
    /// add r to the entry for p' in the map table and
    /// add the pair (p, p') to the instance table.
    /// @param p must be partial.
    /// @param r must be complete.
    /// @return 0 if the run or one instance of the run (at least)
    /// was added to the table
    /// @return > 0 otherwise
    size_t addInstanciate(const P& p, Run<P>* r);
    
    /// particular case of add(p, r, it)
    /// add (to p's record) all possible complete updates of r
    /// (obtained by replacing the partial ptr in r by a complete instance).
    /// @param p must be complete.
    /// @param r must be partial.
    /// @param it must be an iterator to the entry for p in table.
    /// @return 0 if the run or one instance of the run (at least)
    /// was added to the table
    /// @return > 0 otherwise
    size_t addUpdate(const P& p, Run<P>* r, Record<P>* it);
    

    /// add(pp, pc)
    /// create a record it associated to pc in table and
    /// add the pair <pp, it> to the table of instances .
    /// @param pp must be partial.
    /// @param pc must be complete,
    /// pc must be an instance of pp,
    /// pc must not be registered in table.
    void addInstance(const P& pp, const P& pc);
    //typename MapRecord<P, R, H>::iterator add(const P&, const P&);
    
};


// separated definition of template class
#include "Table.tpp"


#endif /* Table_hpp */


/// @}
