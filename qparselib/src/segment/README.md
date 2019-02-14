# src/segment
Classes for the abstract representation of data in input processed by parsing.

The first category of classes are used for the representation of performances in input: sequences of timestamped musical events.

* `Pitch` : MIDI and name/accident/octave pitch.
* `MusEvent` : musical events (without timestamps); it can be a pitched note or a rest. No time information (onset or duration). 
* `Point` : musical event extended with real-time date (in seconds). 
	* a point is marked either as `on` of `off` (similarly to note-on / note-off midi messages).
	* a point can be linked to a matching point (according to the MIDI on-off pairing).
	* a point `p` marked `on` and linked to another point `p’` (`on` or `off`) has a duration = `date(p’) - date(p)` (this quantity must be positive or null).
	* any other point has an unspecified duration. 
* `MusPoint` : Point extended with musical-time date and durations (expressed in fraction of bars).
* `InputSegment` sequence of musical points events, ordered by real-time dates. Constructors for empty input segmemnt and for inserting new points (inservtion respects the date order). For import/export from MIDI files, see [dir input/](../input/README.md).

The second category of classes represent time intervals, 
and tools for the alignement of input events to these intervals (for quantization).
Every interval has real-time and musical-time bound.

* `Interval` : time interval with realtime bounds (in seconds) and musical bounds (in fraction of bars).
* `AlignedInterval` : `Interval` extended with with computed alignment of `InputSegment` points inside the left- and right-bounds: points resp. inside the first half and second half of interval.
* `IntervalTree` : the above organized hierarchicaly in a tree of nested intervals.
* `IntervalHeap` : table for storage of aligned intervals
 to avoid recomputation of alignments.

