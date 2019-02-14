# qparse
This package implements Rhythm Quantization based on parsing algorithms for weighted tree automata. Taking in input a symbolic musical performance (sequence of notes with real-time dates and durations, typically a [MIDI file](https://www.midi.org/specifications-old/item/standard-midi-files-smf)), and a weighted context-free grammar describing a language of prefered rhythms, it outputs a music score. Several output formats are possible, including [XML MEI](http://music-encoding.org/about/).


## compilation
in order to produce MEI scores, you will need the 
library [libMEI](https://github.com/DDMAL/libmei) - a C++ library for reading and writing MEI files.

The compilation of libMEI may halt due to the following error: 
  `warning: les spécifications dynamiques d'exceptions sont dépréciées en C++11 [-Wdeprecate ]`

Commenting lines 84-86 in ./libmei/CMakeLists.txt before compiling may solve the
problem.

To compile Qparse targets, use the following commands:

	$ mkdir build; cd build
	$ cmake ..
	$ make [targets]

where `[targets]` is a list containing some of 
`squant`, `equiv`, `schemas`, and `midiutil` (see below for a description of the targets).
In case `targets` is omitted, all above targets are produced.

## targets
Each of the following `targets` produces a command line utility, 
either for applying the quantization procedure or for the construction and management of automatas or transcription input.


* **squant**
Transcription of an input given by a text or a MIDI file wrt a given automaton 
(stored in a file and called schema).
Various output possible, including MEI score file and quantized MIDI file.

- **equiv** 
Enumeration of rhythm trees in a given schema language 
equivalent to a given sequence of (quantized) durations (Inter-Onset-Intervals).

- **schemas**
Utilities for the construction of schema and computation of weights.

- **midiutils**
Utilities for reading MIDI files and conversion to text format.


## contributors

* **Florent Jacquemard** (Inria). First author. 
* **Francesco Foscarin** (PhD, CNAM). Automated construction of grammars from corpus. Evaluation.
* **Clement Poncelet** (Salzburg U.). Integration of [Midifile](http://midifile.sapp.org) library for MIDI input.
* **Philippe Rigaux** (CNAM). Production of scores in MEI format and intermediate model of output scores.
* **Masahiko Sakai** (Nagoya U.). Input/output distance metrics for quantization and CMake framework. Evaluation.


## target squant 
Some examples of command lines using the files in directory `test/`

For producing a MEI output file from MIDI input and given schema.
The option barsec specifies the number of seconds per bar, for reading the MIDI input file (converted to 60 bpm, i.e. it corresponds to the number of beats)

    squant -v 4 -a test/schema/schema-04.txt -i test/midi_in/311-Alto.mid -config params.ini -norest -barsec 4.0 -output test/mei/311-Alto-out.mei


	quant -v 4 -a test/schema/schema-03.txt -i ../corpus/MIDI.perf/103-SaintSaens-elephant_FJ.mid -config params.ini -norest -barsec 3.0 -output ~/Documents/workspace/scorelib/app/media/103.mei

For producing a MIDI output file from MIDI input and given schema.
The option barbeat specifies the number of beats per bar, for computing the quantized MIDI output.

    squant -v 4 -a test/schema/schema-04.txt -i test/midi_in/311-Alto.mid -config params.ini -norest -barsec 4.0 -barbeat 4 -output test/midi_out/311-Alto-out.mid


for explanations about the options:

    squant -h

**schema file** : 
Specified by the command line option `-a` or `-schema`, the schema file is a text file containing transitions of one of the forms (1 transition per line):

- `state` (`state_0` ... `state_n`) `weight`, or
- `state` `c` `weight`

where:

- `state`, `state_0`,..., `state_n` are integers (non terminal symbols), 
- `weight` is a weight value 
- `c` is an integer (terminal symbol, number of events on a rhythm tree leave).

before the transitions, a weight type should be specified, amongst:

- `[stochastic]`
   if weight values in transition are probabilities
- `[penalty]`
   if weight values in transition are cost
- `[counting]`
   if weight values in transition are counts in a corpus.

A command line option about the weight type can be added, amongst:

-  `-counting`, 
-  `-penalty`, 
-  `-probability` or `-stochastic`.

If the weight type specifier is not present in the schema file,
the given option must be present and it is used as weight type for parsing with the schema.

If both the weight type specifier (in schema file) and the option are present,
the schema is read using the weight type specifier 
and the weight values are then to the type specified by the option
(for some combinations, the cast may fail).

NB: only the weight type penalty and stochastic are supported by the quantization algorithm.
  

**input file** : 
Its name is given with command line option `-i` file or `-input`.
It can be either

- a textfile, characterized by extension `.txt`.
it contains: a start date, a sequence of onsets (one per line), an end date. All the timestamps are expressed in seconds.
- a midifile, characterized by extension `.mid` or `-midi`.


**output file** : 
The output filename can be specified with the command line option `-o` or `-output`. 

It can be either

- a MIDI file, characterized by extension `.mid` or `.midi`.
- an XML MEI file,  characterized by extension `.mei`.

**configuration file** : 
Some configuration options can be given in a file with the the command line option `-config`. The file is a text file in [INI syntax](https://en.wikipedia.org/wiki/INI_file). It can contain the following section and key definitions:

- section `params`
	- key `alpha` : coefficient applied for distances for combination with grammar's weight in penalty model.
	- key `sigma2` : parameter of a probabilistic performance model.
	- key `maxarity` : maximal number of divisions 	
- section `options`
	- key `run_dur` (optimization flag) : compute the duration sequences associated to trees (runs). if unset, then `run_unit` and `run_strict` must be unset.
	- key `run_unit` (optimization flag) : do not add non-terminal runs with duration sequences of the form `[0…0, 1]`. They correspond to reducible runs of the form `p(x, _,…, _)` where `x` is a leaf and `_` is a continuation (tie).
	- key `run_strict` (optimization flag) : compute at most one best run for a duration sequence in each record. It is the first best run added, i.e. the best with that duration sequence.
	- key `norest` : do not fill gaps in input (MIDI) file with rests (extend previous note instead).
- section `hash`
	- key `seed`
	- key `factor` : use in the definition of hash functions.

## Example 

./test/run_quant.sh beethoven_trio/beethoven_trio_midi_quant.mid beethoven_trio/beethoven_trio_grammar.txt beethoven_trio_midi_quant.mei 2 4
