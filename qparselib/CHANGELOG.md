### 2018 jul. 05
- pitch spelling
- handling of rests in MEI output

### 2018 jun. 08
- revise Counting WTA model
- new MIDI test files

### 2018 apr. 17
- new transcription scenarios with demos:
	- single bar, 1-best solution 
	- single bar, k-best solutions
	- multiple bars, 1-best, bottom-up binary runs
	- multiple bars, 1-best, flat runs

### 2018 apr. 08
- MIDIfile output
- improvements in MEI output: clef, ties
- simplification of MIDIfile input
- préparation of architecture for lib (separation of parsing algos and input, output) 

### 2018 mar. 28
- CMake configuration files
- FreeBSD version
- revision of distance function and combination distance / penalty in computation of weights
- types pre_t, label_t

### 2018 mar. 15
- configuration file .ini. some compile options and command line options moved to this file.
- redef weight models PerfoWeight et Distance pour nouvelles class alignements
- debug performance model (used with stochastic grammars)
- new command line options
- mv evaluation corpus to a new repository

### 2018 feb. 22
- output of MEI files (first version)
- developement of ScoreModel

### 2018 feb. 09
- new architecture for 1-best and k-best parsing algorithms, with template classes for keys (index in table, parameter of templates), runs (parse trees), records (run containers), table (map key -> record).
- input data: complete and clean Event, Point, Input Segment
- compilation for platform CYGWIN

### 2017 nov. 12
- new target command line : midi file utilities 
- domain of weights for counting occurences of grammar's rules.
- evaluation of weight on a (parse) tree by grammar
- command line option for input of tree from string (interface with Python)
- options -start and -end to set start/end dates in input Segment
- option norest : ignore rests in midifile

### 2017 oct. 31
- command line options (GNU getopt)
- update weight models and casting (counting, penalty, probabilities)

### 2017 oct. 24
- merge rearchi branch into master
- MIDIfile import
- updated class of input Segment with realtime dates (seconds)
- update function of alignement of Path interval (dates in samples) to input Segment
- add bloc numbers for sequential processing

### 2017 oct. 31
- Weight casting functions for WTA
- compile options related to weight models
- other changes in command line option processing

### 2017 jul. 28
- internal storage of time intervals in a tree (opt)
- compution of alignement of input segment on time intervals
- rewritten ComboWTA construction

## 2017 jun. 21
- change architecture: new classes for Viterbi and k-best algos (various data structures). see  src/Kbest/Config.hpp 
- implementation of parse tables for Viterbi algos (1-best) in 3 cases (w/o Intervals and pre/post)
- optimization of the computation of grammar's runs. redesign of DurationList with states (for efficiency)
 

## 2017 may 13
- revised performance model : computation of distance as probabilities of alignement of input points to a score following a truncated Gaussian distribution
- revise computation of alignement and storage in tree
- generic WTA constructor from file (with seed weight) 
- WTA normalisation

## 2017 mar. 15
- polymorphic classes of weights with the envelop/letter paradigm
- tracing

### 2016 dec. 11 
- Lilypond output
- target equiv (enumeration of rhythms corresponding to a given sequence of durations)

### 2016 nov. 16 
- structure of duration sequences for runs
- structure of rhythm trees
- target schemas (command line utilities for the construction of rhythm grammars). first version.
- banchmarking utilities

### 2016 oct. 20 
- first version with a comboWTA : weighted tree automata constructed as the product of a given context-free grammar and an automaton computing an input-output distance.
- k-best parsing algorithm for standard WTA

