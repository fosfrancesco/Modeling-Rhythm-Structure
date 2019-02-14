# src/intput

Facilities for reading and writing the data 
given in input to the quantization by parsing algorithm, i.e.

* the grammar (`WTA`)
* sequence of timestamped musical events (`InputSegment`).

The grammar can be read from a text file describing transition rules and some options (weight type, maximum number of grace notes). For details on the syntax of transition rules and options, see [top readme](../../README.md).

A grammar can can also be saved to a file.

The input segment can be read from files in two formats:

* text format.
* MIDI file input. based on the library [Midifile](http://midifile.sapp.org) of Craig Stuart Sapp.

The input segment (updated with quantized dates after quantization)
can be exported (written) as a MIDI file.

