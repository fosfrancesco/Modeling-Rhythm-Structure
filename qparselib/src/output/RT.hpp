//
//  RT.hpp
//  qparse
//
//  Created by Florent Jacquemard on 16/11/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#ifndef RT_hpp
#define RT_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <iostream>
#include <assert.h>

#include "Label.hpp"


/// position in a RT.
///
/// = sequence of integers to reach position from root.
class Position
{
public:
    /// empty sequence = root position
    Position();
    
    Position(const Position&);
  
    bool empty() const;
    size_t length() const;

    /// concatenate given int to this position
    /// @param i int must be positive
    void operator+=(size_t i);
    
    friend std::ostream& operator<<(std::ostream& o, const Position& pos);
    friend Position operator+(const Position&, const size_t&);

protected:
    std::vector<size_t> _content;
    
    void print(std::ostream& o) const;
};

inline Position operator+(const Position& p, const size_t& i)
{
    Position p0(p); // copy
    p0 += i;
    return p0;
}


/// Rhythm Trees.
///
/// for the value of leaf labels
/// @see WTA.hpp
/// @see Label.hpp
class RhythmTree
{
public:

    /// empty inner tree (not terminal)
    /// @warning the child list must be completed with add
    RhythmTree();
    
    /// single leaf rhythm tree
    /// (terminal tree)
    RhythmTree(label_t lab);

    /// extract RT from string description
    RhythmTree(const string&);
    
    ~RhythmTree();

    /// single node tree
    bool terminal() const;

    bool inner() const { return (! terminal()); }
    
    /// arity of root node (0 for terminal tree)
    size_t arity() const;
    
    /// return the ith child of this tree
    /// @warning this tree must be inner (not terminal)
    RhythmTree* child(size_t i) const;
    
    /// label for terminal node
    /// @warning this tree must be terminal
    label_t label() const;

    /// label of terminal node is a continuation
    /// @warning this tree must be terminal
    bool continuation() const;
    
    /// label of terminal node is a single event (1 note / rest, no grace note).
    /// @warning this tree must be terminal
    bool single_event() const;

    /// number of grace notes in this terminal node.
    /// @warning this tree must be terminal
    size_t nbgn() const;
    
    /// this tree contains a subtree of the form.
    /// @code p(n, o,...,o) @endcode or
    /// @code p(o,...,o) @endcode
    bool reducible() const;
    
    /// add a subtree.
    /// @warning this tree must not be terminal
    void add(RhythmTree*);

    /// LilyPond format.
    string lily(int depth, bool tie=false) const;
    
    /// LilyPond format with dots.
    string lilydot(int depth);
    
    /// global variable set if a dot is added in lilydot.
    static bool dot_flag;
    
    /// format for Tree Edit Distance Salzburg library.
    string APTED() const;
    
    string to_string() const;
    
    friend std::ostream& operator<<(std::ostream&, const RhythmTree&);
    
protected:
    /// for leaves, it is the positive integer stored in the leaf;
    /// for inner tree, it is a negative integer.
    ///
    /// long int : for comparison with state_t = size_t = unsigned long
    /// (=label of terminal Run)
    long _label;

    std::vector<RhythmTree*> _children;

    /// inner and the children list is of the form.
    /// @code (_, o,...,o) @endcode
    bool tail_redex() const;

    /// inner and one of the children 1..a is reducible.
    bool tail_reducible() const;

    // utilities for LilyPond convert
    
    /// return whether this tree is a continuation (a leaf).
    bool tie() const;

    /// return whether this tree is binary.
    bool binary() const;

    /// return whether the leftmost innermost leaf is a tie (continuation).
    bool tied() const;

    /// return whether this tree is binary and the second child is tied.
    bool second_tied() const;
    
    /// return whether this tree is binary
    /// and the left son is a dot (continuation after the dotted note).
    bool dot_after() const;

    /// return whether this tree is binary
    /// and the right son is a dot (continuation before the dotted note).
    bool dot_before() const;
    
    /// LilyPond format with dots.
    string lilydot(int depth,
                   bool tie,
                   bool dot,
                   bool ignore_first,
                   bool ignore_second);
    
private:
    void read_space(std::string::const_iterator& it,
                    const std::string::const_iterator& beg,
                    const std::string::const_iterator& end);

    void read_tree(std::string::const_iterator& it,
                   const std::string::const_iterator& beg,
                   const std::string::const_iterator& end);

    void read_int(std::string::const_iterator& it,
                  const std::string::const_iterator& beg,
                  const std::string::const_iterator& end);
    
    void read_list(std::string::const_iterator& it,
                   const std::string::const_iterator& beg,
                   const std::string::const_iterator& end);
};


#endif /* RT_hpp */


/// @}
