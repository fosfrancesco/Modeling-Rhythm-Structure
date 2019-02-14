//
//  OMRT.hpp
//  qparse
//
//  Created by Florent Jacquemard on 31/07/2017.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


// cast RT into OMRT (OpenMusic Rhythm Tree)
//
// following spec in http://support.ircam.fr/docs/om/om6-manual/co/RT.html
// an OMRT is either
// - a rational duration "p/q"
// - a tied integral duration "p.0"
// - a pair "<d (t1 ... tn)>" where
//   d is a rational duration
//   t1 ... tn are OMRTs



#ifndef OMRT_hpp
#define OMRT_hpp

#include <stdio.h>

#include "Rational.hpp"
#include "RT.hpp"



class OMRhythmTree
{
public:

    // grace note
    OMRhythmTree();
    
    // singleton OMRhythmTree
    OMRhythmTree(Rational lab, bool tied=false);
    
    // cast a RhythmTree into an OMRhythmTree
    OMRhythmTree(const RhythmTree*, Rational dur=Rational(1));
   
    ~OMRhythmTree();
    
    // it is a single node tree
    bool leaf() const {  return _children.empty(); }
    
    bool inner() const { return (! leaf()); }
    
    inline Rational label() { return _label; }
    
    inline bool tie() { return _tied; }
    
    // arity of root node = number of children.
    size_t size() const;
    
    // return the ith child of this tree
    OMRhythmTree* child(size_t) const;
    
    // add a subtree at the end of the children list
    void add(OMRhythmTree*);
    
    string to_string() const;
    
    friend std::ostream& operator<<(std::ostream&, const OMRhythmTree&);
  
private:
    // node label
    Rational _label;

    //  tie with the previous note. for leaves only.
    bool _tied;
    
    std::vector<OMRhythmTree*> _children;

};


#endif /* OMRT_hpp */


/// @}
