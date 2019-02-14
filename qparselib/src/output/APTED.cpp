//
//  APTED.cpp
//  qparse
//
//  Created by Florent Jacquemard on 11/12/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
/// @addtogroup output
/// @{


#include "RT.hpp"


/// RT output format for Tree Edit Distance library
/// APTED algorithm of M. Pawlik and N. Augsten
/// http://tree-edit-distance.dbresearch.uni-salzburg.at
string RhythmTree::APTED() const
{
    if (terminal())
    {
        label_t a = this->label();
        size_t g = Label::nbGraceNotes(a);
        
        if (Label::continuation(a)) // tie
        { return "{O}"; }
        else if (g == 0)            // single note
        { return "{X}"; }
        else                        // graces notes + note
        {
#if QP_PLATFORM == PLATFORM_DARWIN
            return ("{X"+(std::to_string(Label::nbGraceNotes(a)))+"}");
#elif QP_PLATFORM == PLATFORM_LINUX
            return ("{X"+(patch::to_string(Label::nbGraceNotes(a)))+"}");
#endif
        }
    }
    else // inner()
    {
        size_t a = this->arity();
        assert (a > 1);
        std::string res = "{A";
#if QP_PLATFORM == PLATFORM_DARWIN
        res += std::to_string(a);
#elif QP_PLATFORM == PLATFORM_LINUX
        res += patch::to_string(a);
#endif
        for (size_t i = 0; i < a; i++)
        {
            res += " ";
            res += _children[i]->APTED();
        }
        res += "}";
        return res;
    }
}

/// @}
