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
//
// quantization based on stochastic model
// combination of prior model of score language and performance model


#include <stdio.h>
#include <time.h>
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

#include "ViterbiWeight.hpp"
#include "PreWTA.hpp"
#include "Kalign.hpp"
#include "constant.h"
#include "DurationList.hpp"


double duration(clock_t start)
{
    return ((double)(clock() - start)/CLOCKS_PER_SEC * 1000);
}



int main(int argc, const char * argv[])
{
    
    // log levels:
    // trace = 0,
    // debug = 1,
    // info = 2,
    // warn = 3,
    // err = 4,
    // critical = 5,
    // off = 6
    spd::set_level(spd::level::trace);
    
    clock_t time_start;
    //clock_t time_end;
    
    
// test WTA file IO
    assert (argc >= 2);
    std::cout << "\n==== Read schema WTA from " << argv[1] << '\n';

    Weight seed = Weight(new ViterbiWeight(0));
    WTA* schema = new WTA(argv[1], seed);
    schema->print(cout);

    std::cout << "\n==== Clean schema:\n";
    time_start = clock();
    schema->clean();
    //time_end = clock();
    std::cout << "time to clean WTA : ";
    std::cout << duration(time_start) << "ms \n";
    schema->print(cout);

    std::cout << "\n====  Normalize schema:\n";
    time_start = clock();
    schema->normalize(0); // penalty model
    //time_end = clock();
    std::cout << "time to normalize WTA : ";
    std::cout << duration(time_start) << "ms \n";
    std::cout << *schema;
    schema->print(cout);

    std::cout << "\n====  Compute Resolution:\n";
    time_start = clock();
    size_t res = schema->resolution();
    std::cout << "time to compute resolution : ";
    std::cout << duration(time_start) << "ms \n";
    std::cout << "\nresolution = " << res << '\n';


    
// test PreWTA construction
    size_t max_pre = 0;
    size_t max_post = MAX_GRACE;
    
    std::cout << "\n==== Construction Pre\n";
    time_start = clock();
    PreWTA* combo = new PreWTA(*schema);
    
    delete schema;
    
    std::cout << "\nPreWTA:\n";
    std::cout << *combo;
    combo->print(cout);
    std::cout << "time to compute PreWTA : ";
    std::cout << duration(time_start) << "ms \n";
    
    
// test k-best for initial states of PreWTA
    if (argc == 2) return 0;
    std::cout << "\n==== Read input segment from " << argv[2] << '\n';
    Segment seg = Segment(argv[2], res);
    std::cout << "segment size " << seg.size() << '\n';
    
    int k = 10;
    time_start = clock();
    Kalignment* kkt = new Kalignment(seg, combo, weightMax);
    
    for (size_t pre = 0; pre <= max_pre; pre++)
    {
        for (size_t post = 0; post <= max_post; post++)
        {
            std::cout << "\n==== " << k << "-best for ";
            std::cout << "pre=" << pre << " post=" << post << "\n";
            for (int i = 1; i <= k; i++)
            {
                Run r = kkt->best(combo->initial(pre, post), i);
                if (! r.unknown())
                {
                    RhythmTree t = RhythmTree(r, kkt);
                    std::cout << i << "-best: ";
                    std::cout << t.to_string();
                    std::cout << " (weight=" << r.weight << ")";
                    std::cout << " " << r.duration << " ";
                    std::cout << ((t.reducible())?"REDUCIBLE\n":"\n");
                }
            }
        }
    }
    
    std::cout << "\ntime for " << k << "-best for all initial states PreWTA : ";
    std::cout << duration(time_start) << "ms \n";
   
    console->info("Delete table");
    delete kkt;

    console->info("Delete PreWTA");
    delete combo;

    return 0;
}

