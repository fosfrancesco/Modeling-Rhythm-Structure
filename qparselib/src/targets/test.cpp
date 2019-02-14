//
//  test.cpp
//  qparse
//
//  Created by Florent Jacquemard on 05/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

#include <stdio.h>



// test label serialization
bool test_label(label_t m)
{
    for (size_t n = 0; n <= m; n++)
        for (pre_t post = 0; post < 3; post++)
            for (pre_t pre = 0; pre < 3; pre++)
            {
                label_t c = Label::serialize(pre, post, n);
                cout << "serial=" << c << "(" << pre << "," << post << "," << n << ")";
                cout << " pre="  << Label::pre(c) << "|" << pre;
                cout << " post=" << Label::post(c) << "|" << post;
                cout << " evts=" << Label::nbEvents(c) << "|" << n;
                cout << " cont=" << Label::continuation(c);
                cout << " g.n.=" << Label::nbGraceNotes(c);
                
                if (   (pre == Label::pre(c))
                    && (post == Label::post(c))
                    && ((! Label::continuation(c)) || ((n == 0) && (Label::nbGraceNotes(c) == 0)))
                    && (Label::continuation(c) || ((n > 0) && (Label::nbGraceNotes(c)+1 == n))))
                    cout << " OK\n";
                else
                    exit (1);
            }
    cout << "OK\n";
    return 1;
}


//    std::cout << "\n==== Test Weight\n";
//    Weight* w = new TropicalWeight(1);
//    cout << "print " << *w << "\n";
//    exit(0);



bool test_tree(Kalignment* kkt,
               State s, size_t k,
               size_t a, size_t i,
               pre_t cpre=0)
{
    Kalignment* sub = kkt->sub(a, i);
    Run r = sub->best(s, k, cpre);
    RhythmTree t = RhythmTree(r, sub);
    std::cout << k << "-best(" << s << ") = " << t.to_string();
    std::cout << " (weight=" << r.weight << ")";
    std::cout << " " << r.duration << "\n";
    
    return 1;
}




#include "DurationList.hpp"

bool test_duration_list()
{
    DurationList dl1 = DurationList();
    DurationList dl2 = DurationList();
    DurationList dl3 = DurationList();
    
    dl1.add(Rational(1,2));
    dl1.add(Rational(1,2));
    dl2.addcont(Rational(1,3));
    dl2.add(Rational(2,3));
    dl3.add(Rational(1,4));
    dl3.add(Rational(1,2));
    dl3.add(Rational(1,4));
    cout << "dl1 " << dl1 << "\n";
    cout << "dl2 " << dl2 << "\n";
    
    dl1 += dl2;
    cout << "+ " << dl1 << "\n";
    dl1 += dl3;
    cout << "+ " << dl1 << "\n";
    dl1.normalize();
    cout << "norm " << dl1 << "\n";
    
    return 1;
}


// test state 1
bool test_duration_list1()
{
    DurationList dl1 = DurationList();
    DurationList dl2 = DurationList();
    DurationList dl3 = DurationList();
    
    dl1.addcont(Rational(1));
    dl2.addcont(Rational(1));
    dl3.addcont(Rational(1));
    cout << "dl1 " << dl1 << "\n";
    cout << "dl2 " << dl2 << "\n";
    cout << "dl2 " << dl3 << "\n";
    
    dl1 += dl2;
    cout << " + " << dl1 << "\n";
    dl1 += dl3;
    cout << " + " << dl1 << "\n";
    dl1.normalize();
    cout << "norm " << dl1 << "\n";
    
    return 1;
}


