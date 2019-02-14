//
//  Atable.cpp
//  squant
//
//  Created by Florent Jacquemard on 02/02/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//



template <class P>
Atable<P>::Atable(Parser<P>* env,
                  RunCompare<P> comp):
parent(env),
_comparer(comp)
{
    assert(env);
};


template <class P>
Atable<P>::~Atable()
{
    assert(parent);
    
    // we do not delete wta and input segment here
};

