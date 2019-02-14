//
//  quant.cpp
//  qparse
//
// https://github.com/florento/q-parse
//
//  Created by Florent Jacquemard on 01/10/16.
//  Copyright © 2016 Florent Jacquemard. All rights reserved.
//
// terminal command line for
// rhythm quantization with qparse library


#include <stdio.h>
#include <time.h>
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

#include "TropicalWeight.hpp"
#include "ComboWTA.hpp"
#include "Kbest.hpp"
#include "SubdivisionSchema.hpp"
#include "RT.hpp"


double duration(clock_t start)
{
    return ((double)(clock() - start)/CLOCKS_PER_SEC * 1000);
}

int main(int argc, const char * argv[])
{
    
    clock_t time_start;
    //clock_t time_end;

//    std::cout << "\n==== Test Weight\n";
//    Weight* w = new TropicalWeight(1);
//    cout << "print " << *w << "\n";
//    exit(0);

    
    
// test WTA file IO
    assert (argc >= 2);
    std::cout << "\n==== Read schema WTA from " << argv[1] << '\n';

    Weight seed = Weight(new TropicalWeight(0));
    WTA* schema = new WTA(argv[1], seed);
    schema->print(cout);

    cout << "\n==== Clean schema:\n";
    time_start = clock();
    schema->clean();
    //time_end = clock();
    cout << "time to clean WTA : ";
    cout << duration(time_start) << "ms \n";
    schema->print(cout);

    time_start = clock();
    size_t res = schema->resolution();
    cout << "time to compute resolution : ";
    cout << duration(time_start) << "ms \n";
    std::cout << "\nresolution = " << res << '\n';
    
    
// test 1-best (compute max weight of schema)
    cout << "\n==== 1-best for all of " << schema->initials.size() << " initials\n";
    time_start = clock();
    Ktable kt0 = Ktable(schema, weightMax);
    // we qualify the name best
    // because the Kcontainer members are not visible in the derived template class Ktable
    // (the base template member names are dependent names)
    Run r = kt0.Kcontainer::bestinit(1);
    cout << "1-best (max) = ";
    if (r.unknown()) { cout << "NaN\n"; }
    else
    {
        RhythmTree t = RhythmTree(r, &kt0);
        cout << t.to_string();
        cout << " weight ";
        cout << r.weight << "\n";
    }
    
    cout << "time to 1-best (max) for initial state of schema : ";
    cout << duration(time_start) << "ms \n";
    
// test Combo construction
    if (argc == 2) return 0;
    std::cout << "\n==== Read input segment from " << argv[2] << '\n';
    Segment seg = Segment(argv[2], res);
    std::cout << "segment size " << seg.size() << '\n';

    std::cout << "\n==== COnstruction COmbo\n";
    time_start = clock();
    ComboWTA* combo = new ComboWTA(seg, *schema, 0);
    cout << "time to compute ComboWTA : ";
    cout << duration(time_start) << "ms \n";

    delete schema;

    cout << "\nCombo:\n";
    combo->print(cout);
    cout << *combo;
    
//    cout << "\n==== Clean Combo:\n";
//    time_start = clock();
//    combo->clean();
//    cout << "time to clean ComboWTA : ";
//    cout << duration(time_start) << "ms \n";
//    combo->print();
//    cout << *combo;


    
// test k-best for initial states of Combo
    int k = 30;
    time_start = clock();
    Ktable kkt = Ktable(combo, weightMin);
    
    for (size_t pre = 0; pre <= combo->max_pre(); pre++)
    {
        for (size_t post = 0; post <= combo->max_post(); post++)
        {
            cout << "\n==== " << k << "-best for ";
            cout << "pre=" << pre << " post=" << post << "\n";
            for (int i = k; i > 0; i--)
            {
                Run r = kkt.Kcontainer::bestinit(pre, post, i);
                if (! r.unknown())
                {
                    RhythmTree t = RhythmTree(r, &kt0);
                    cout << i << "-best: ";
                    cout << t.to_string();
                    cout << " (weight=" << r.weight << ")";
                    cout << " " << r.duration << "\n";
                }
            }
        }
    }
    
    cout << "\ntime for " << k << "-best for all initial states ComboWTA : ";
    cout << duration(time_start) << "ms \n";
   
    delete combo;

    return 0;
}

// test Label
//unsigned int c = SerialLabel::serialize(1, 0, 0);
//cout << "serial = " << c << " ";
//cout << "pre = " << SerialLabel::pre(c) << " ";
//cout << "post = " << SerialLabel::post(c) << " ";
//cout << "cont = " << SerialLabel::continuation(c) << " ";
//cout << "g.n. = " << SerialLabel::nbGraceNotes(c) << "\n";






