# /src/targets
definition of command line utilities.

Every `target` is defined in a .cpp file with a main function.
The commandline options are handled using the GNU [getopt](https://www.gnu.org/software/libc/manual/html_node/Getopt.html) function.

* `quant` 
Transcription of an input given by a text or a MIDI file wrt a given automaton 
(stored in a file and called schema).
Various output possible, including MEI score file and quantized MIDI file.

- `equiv` 
Enumeration of rhythm trees in a given schema language 
equivalent to a given sequence of (quantized) durations (Inter-Onset-Intervals).

- `schemas`
Utilities for the construction of schema and computation of weights.

- `midiutils`
Utilities for reading MIDI files and conversion to text format.