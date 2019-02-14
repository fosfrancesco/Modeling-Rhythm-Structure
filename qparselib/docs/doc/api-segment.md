# group `segment` {#group__segment}

The `segment` module contains classes for abstract representation of data in input processed by parsing.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::ostream & `[`operator<<`](#group__segment_1gaa5d5d2dd440400af33e39d031cb08fa5)`(std::ostream & o,const `[`AlignedInterval`](#classAlignedInterval)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__segment_1ga6c33ecb9851e077e90345090b15c87c3)`(std::ostream & o,const `[`InputSegment`](#classInputSegment)` & s)`            | 
`public std::ostream & `[`operator<<`](#group__segment_1ga2f4c47a191d9e8f503a8a18bfba89f2c)`(std::ostream & o,const `[`Interval`](#classInterval)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__segment_1gac85491c9b09a0e009fe58f15da5e88ab)`(std::ostream & o,const `[`IntervalTree`](#classIntervalTree)` & p)`            | 
`public inline std::ostream & `[`operator<<`](#group__segment_1gade87c7b11c1a1fdbcd922e08b3eaa3c5)`(std::ostream & o,const `[`MusEvent`](#classMusEvent)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#group__segment_1ga7d6e1aa31e5a2132257840adeb5bf23f)`(std::ostream & o,const `[`Pitch`](#classPitch)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__segment_1gad95cc714e40b63c5df8e1dc41305178e)`(std::ostream & o,const `[`Point`](#classPoint)` & rhs)`            | 
`public inline bool `[`operator==`](#group__segment_1gaf9d08e42ae7632f815ad7bd3c093b497)`(const `[`SpiralPoint`](#structSpiralPoint)` & lhs,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public inline bool `[`operator!=`](#group__segment_1ga0b4ffecf00942ad046a9ea6785319f6f)`(const `[`SpiralPoint`](#structSpiralPoint)` & lhs,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public inline std::ostream & `[`operator<<`](#group__segment_1gab3a698d42f743ce361da6916209eca88)`(std::ostream & o,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public inline bool `[`operator==`](#group__segment_1gaeba3d7c6ab7481a52f2cd4ce980c08ca)`(const `[`NoteName`](#structNoteName)` & lhs,const `[`NoteName`](#structNoteName)` & rhs)`            | 
`public inline bool `[`operator!=`](#group__segment_1ga7c5e53ea6aa75682a2320bdf2f6f17fa)`(const `[`NoteName`](#structNoteName)` & lhs,const `[`NoteName`](#structNoteName)` & rhs)`            | 
`public inline std::ostream & `[`operator<<`](#group__segment_1ga696a465764983bfca52bcd6406e373f9)`(std::ostream & o,const `[`NoteName`](#structNoteName)` & p)`            | 
`public  `[`AlignedInterval`](#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,bool f_align)`            | [Interval](#classInterval) covering the whole length of the given input segment with given musical time length (number of bars).
`protected  `[`AlignedInterval`](#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,bool f_align)`            | aligned interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.
`public  `[`AlignedInterval`](#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5)`(const `[`AlignedInterval`](#classAlignedInterval)` &)`            | copy.
`public virtual `[`AlignedInterval`](#classAlignedInterval)` & `[`operator=`](#group__segment_1ga304aac2ec620d785bbfb67996a7a613b)`(const `[`AlignedInterval`](#classAlignedInterval)` &)`            | 
`public virtual bool `[`operator==`](#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62)`(const `[`AlignedInterval`](#classAlignedInterval)` &) const`            | 
`public bool `[`aligned`](#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175)`() const`            | this interval has been aligned.
`public size_t `[`align`](#group__segment_1ga25f42094dbb3623c73df11dd85596185)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)`            | set the alignment parameters, starting from index b of input segment point and return the next index of point in input segment to be processed (first index at right of this interval) or the size of input segment (total # points) if end of segment is reached.
`public size_t `[`align`](#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77)`(const `[`InputSegment`](#classInputSegment)` * s)`            | same as previous but uses _seg_first instead of argument b.
`public size_t `[`rewind`](#group__segment_1gafad6a7eea9e5892cfae9986f6263a738)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)`            | compute only the value of the next point (the first element of input segment after the right bound of this interval) starting from index b of input segment point.
`public size_t `[`rewind`](#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16)`(const `[`InputSegment`](#classInputSegment)` *)`            | same as previous but uses _seg_first instead of arg. b.
`private bool `[`_check_first`](#group__segment_1ga0be5d430ebcf64f2789eb37886b16367)`(const `[`InputSegment`](#classInputSegment)` *)`            | 
`private bool `[`_check_next`](#group__segment_1ga427dfea0ea3968e99fb4f59ff462a378)`(const `[`InputSegment`](#classInputSegment)` *)`            | 
`public  `[`Environment`](#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf)`(`[`InputSegment`](#classInputSegment)` * s)`            | #### Parameters
`public  `[`~Environment`](#group__segment_1ga8e294735187880dd3d59be10c425b29d)`()`            | 
`public  `[`InputSegment`](#group__segment_1gaec471ec05052a932b1bb2738bfc8b172)`(double b,double e)`            | constructs an empty input segment (no events)
`public  `[`InputSegment`](#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492)`(const `[`InputSegment`](#classInputSegment)` &)`            | 
`public  `[`InputSegment`](#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef)`(const `[`InputSegment`](#classInputSegment)` & s,double b,double e)`            | copy and resize.
`public virtual  `[`~InputSegment`](#group__segment_1gab8da320feb29d4b009d2e6a37924337e)`()`            | 
`public size_t `[`size`](#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63)`() const`            | number of non-floating points in segment.
`public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`begin`](#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d)`()`            | iterators to the segment's contents.
`public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`end`](#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e)`()`            | 
`public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cbegin`](#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90)`() const`            | 
`public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cend`](#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b)`() const`            | 
`protected bool `[`check_index`](#group__segment_1ga82a64bae54200b634bc42ac06dc7a916)`(long i) const`            | 
`protected void `[`link`](#group__segment_1ga43310a16681e2241b20da4b68de9f35b)`(long i,long j)`            | the event of index i is linked to the event of index j.
`public long `[`add_back`](#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)`            | insert new timestamped muspoint created from the parameters, at the end of the segment.
`public long `[`add_back`](#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4)`(const `[`MusPoint`](#classMusPoint)` &)`            | 
`public long `[`add_floating`](#group__segment_1gad44eb7379e181fc4295ee2514a568204)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)`            | create new timestamped muspoint from the parameters, and add the the heap of floating points (not in segment).
`public long `[`add_floating`](#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a)`(const `[`MusPoint`](#classMusPoint)` &)`            | 
`public const `[`MusPoint`](#classMusPoint)` & `[`point`](#group__segment_1ga5463f900db31be4b7d109e88a710971f)`(long i) const`            | return a ref to the point of index i.
`protected `[`MusPoint`](#classMusPoint)` & `[`ncpoint`](#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd)`(long i)`            | same as point but not const.
`public `[`MusEvent`](#classMusEvent)` * `[`event`](#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca)`(long i) const`            | return the event of the point of index i.
`public double `[`rdate`](#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a)`(long i) const`            | return the real-time date (in seconds) of the point of index i
`public double `[`rduration`](#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf)`(const `[`MusPoint`](#classMusPoint)` & p) const`            | return the real-time duration (in seconds) of the given point.
`public double `[`rduration`](#group__segment_1gafbf05e143d416de49180d2f18a53977b)`(long i) const`            | return the real-time duration (in seconds) of the point of index i.
`public `[`Rational`](#classRational)` & `[`mdate`](#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50)`(long i)`            | return a reference to the musical-time date (in fraction of bar) of the point of index i.
`public `[`Rational`](#classRational)` & `[`mduration`](#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342)`(long i)`            | return a reference to the musical-time duration (in fraction of bar) of the point of index i.
`public void `[`close`](#group__segment_1gae75db088893a7cfc719ec393e09d7ece)`(double e)`            | set end date.
`public void `[`respell`](#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c)`(int k)`            | pitch spelling. unwindowed.
`public void `[`respell`](#group__segment_1gac79787254008e05d9f54226d93dcb0cb)`(`[`Rational`](#classRational)` ws,int k)`            | pitch spelling with a sliding window of given musical duration.
`public void `[`print`](#group__segment_1ga623c2367191018ecac046e7e11f14976)`(std::ostream &) const`            | print size to output stream.
`public template<>`  <br/>`void `[`quantize`](#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e)`(`[`Atable`](#classAtable)`< P > * table,const P & p)`            | set the musical time date and duration of events in this given input segment, according to the best run for p in given table.
`public template<>`  <br/>`size_t `[`quantizu`](#group__segment_1gab4c42d088ce3d170b7899712789ab464)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)`            | set the musical time date and duration of events in this given input segment, according to the best run for p in given table, starting from point number b in interval.
`private template<>`  <br/>`size_t `[`quantize_assert`](#group__segment_1ga8c7a48cd8c319c2d5697b57ea2c4d733)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)`            | 
`public  `[`InputSegmentMono`](#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2)`(const `[`InputSegment`](#classInputSegment)` & s)`            | transform the given input segment into a monophonic input segment (no two notes in the same time).
`public  `[`InputSegmentNogap`](#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548)`(const `[`InputSegment`](#classInputSegment)` & s,bool norest)`            | transform the given input segment into a new input segment without gaps.
`public  `[`Interval`](#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)`            | top interval constructed from an input segment.
`protected  `[`Interval`](#group__segment_1gaefc21b7c838661c05286304f6d891690)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend)`            | build an interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.
`public  `[`Interval`](#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5)`(const `[`Interval`](#classInterval)` &)`            | copy.
`public  `[`Interval`](#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458)`(`[`Interval`](#classInterval)` *)`            | used for copy of downcasted [IntervalTree](api-segment.md#classIntervalTree).
`private bool `[`sanity_check`](#group__segment_1ga04dee911c27559f22144e1ab329550df)`()`            | 
`private bool `[`sanity_check`](#group__segment_1ga29a886b3ca41b923ffe9c1a291973dc9)`(const `[`InputSegment`](#classInputSegment)` *)`            | 
`public virtual `[`Interval`](#classInterval)` & `[`operator=`](#group__segment_1ga6508f58e15c54be6146d5505d91a4b91)`(const `[`Interval`](#classInterval)` &)`            | 
`public virtual bool `[`operator==`](#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6)`(const `[`Interval`](#classInterval)` &) const`            | for using [Interval](api-segment.md#classInterval) as key in map.
`public bool `[`insideBar`](#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb)`() const`            | 
`public  `[`IntervalHeap`](#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51)`()`            | 
`public  `[`~IntervalHeap`](#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8)`()`            | 
`public bool `[`empty`](#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0)`() const`            | 
`public size_t `[`size`](#group__segment_1ga87e6be639c7435053444d83913505c1b)`() const`            | 
`public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,double rext)`            | find or create (and push) a top interval of real-time duration covering the whole length of the given input segment s (root of interval tree) + the given extension.
`public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad886d53d2881a80f06c6f9fbf202d727)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)`            | get interval from heap, build it if not present.
`private `[`IntervalTree`](#classIntervalTree)` *const `[`push`](#group__segment_1ga3327b1c81b67df8c21468492a845630e)`(`[`IntervalTree`](#classIntervalTree)` * p)`            | 
`protected  `[`IntervalTree`](#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)`            | top interval (root of interval tree).
`protected  `[`IntervalTree`](#group__segment_1gac16f2a8d9c584a869bbed6a263914360)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)`            | build an interval tree with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.
`public  `[`~IntervalTree`](#group__segment_1gae2c50e46e3997dd8631669046bf06c27)`()`            | 
`public `[`IntervalTree`](#classIntervalTree)` * `[`top`](#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` * h,`[`Rational`](#classRational)` mend)`            | top interval (root of interval tree) covering the whole length of the given input segment s.
`public `[`IntervalTree`](#classIntervalTree)` * `[`split`](#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)`            | return a sub interval.
`public `[`IntervalTree`](#classIntervalTree)` * `[`split_back`](#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)`            | return a sub interval.
`public `[`IntervalTree`](#classIntervalTree)` * `[`sub`](#group__segment_1gacb8de7e3756951950c391d241adec21c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,size_t a,size_t i)`            | return a the i-1th sub-interval of the division of this interval in n equal parts. the sub-interval returned is aligned.
`public  `[`MusEvent`](#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17)`(int nb)`            | 
`public  `[`MusEvent`](#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27)`(const `[`MusEvent`](#classMusEvent)` &)`            | 
`public  `[`RestEvent`](#group__segment_1gaafcefa86601b97d137cfba40ed349414)`(int nb)`            | 
`public  `[`RestEvent`](#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91)`(const `[`RestEvent`](#classRestEvent)` &)`            | 
`public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga6ebb6acd4c78929d31a4831c58911639)`() const`            | 
`public virtual void `[`print`](#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45)`(std::ostream & o) const`            | 
`public  `[`NoteEvent`](#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be)`(unsigned int vel,int nb)`            | unpitched note (drums).
`public  `[`NoteEvent`](#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7)`(`[`Pitch`](#classPitch)` p,unsigned int vel,int nb)`            | pitched note.
`public  `[`NoteEvent`](#group__segment_1ga135e904aa3f5ea4d375e451281fe5323)`(unsigned int p,unsigned int vel,int nb)`            | pitched note with MIDI pitch in 0..127.
`public  `[`NoteEvent`](#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc)`(const `[`NoteEvent`](#classNoteEvent)` &)`            | 
`public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049)`() const`            | 
`public virtual void `[`print`](#group__segment_1gafa25174e584b872e814643c895cad283)`(std::ostream & o) const`            | 
`public  `[`MusPoint`](#group__segment_1ga006e3062fd920202aab9e36f6a0e394e)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)`            | 
`public  `[`MusPoint`](#group__segment_1ga1bb17bef698401de18bc814c7f965999)`(const `[`Point`](#classPoint)` & p,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)`            | copy of point.
`public  `[`MusPoint`](#group__segment_1ga5f00500846d251b165f48a41552be18e)`(const `[`MusPoint`](#classMusPoint)` &)`            | event (if any) is cloned.
`public  `[`~MusPoint`](#group__segment_1ga036951554acf624dd62469abbd8142df)`()`            | 
`public `[`MusPoint`](#classMusPoint)` & `[`operator=`](#group__segment_1ga522126acc9eb79e737068941370bb172)`(const `[`MusPoint`](#classMusPoint)` &)`            | event (if any) is cloned.
`public virtual bool `[`operator==`](#group__segment_1ga07139fb89dcc2388b299b9e6464b3177)`(const `[`Point`](#classPoint)` &) const`            | 
`protected virtual void `[`print`](#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830)`(std::ostream & o) const`            | 
`public  `[`Pitch`](#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084)`()`            | undef pitch value.
`public  `[`Pitch`](#group__segment_1gaf3f9d88915bb6688d522f09d7542f690)`(char name,float alt,int oct)`            | construct pitch from name+alteration+octave.
`public  `[`Pitch`](#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b)`(unsigned int pitch,PitchUnit u)`            | construct note from MIDI pitch
`public  `[`Pitch`](#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b)`(const `[`Pitch`](#classPitch)` &)`            | 
`public `[`Pitch`](#classPitch)` & `[`operator=`](#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91)`(const `[`Pitch`](#classPitch)` &)`            | 
`public bool `[`operator==`](#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d)`(const `[`Pitch`](#classPitch)` &) const`            | 
`private static char `[`midi_to_name`](#group__segment_1ga507b693a51dd2d626dc3cf42e7d93d99)`(unsigned int)`            | 
`private static float `[`midi_to_alt`](#group__segment_1ga45a060956b0a13178b4a2e987597ab95)`(unsigned int)`            | 
`private static int `[`midi_to_oct`](#group__segment_1gade0788e4c49153b64197dce1203744ae)`(unsigned int)`            | 
`private static unsigned int `[`name_to_int`](#group__segment_1gaa706b7d526d2ccb75c03c202dcd54e5c)`(char)`            | 
`private static unsigned int `[`name_to_midi`](#group__segment_1ga18ee1055465d12e1b9778a4c625cc850)`(char,float,int)`            | 
`public  `[`Point`](#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link)`            | timestamped monophonic or polyphonic event.
`public  `[`Point`](#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc)`(const `[`Point`](#classPoint)` &)`            | event (if any) is cloned.
`public  `[`~Point`](#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1)`()`            | event is deallocated and matcher (linked) also.
`public virtual `[`Point`](#classPoint)` & `[`operator=`](#group__segment_1ga55eeab949e62268da63176d48570eb54)`(const `[`Point`](#classPoint)` &)`            | event (if any) is cloned.
`public virtual bool `[`operator==`](#group__segment_1ga1055933b999ef990df6b48745c27a197)`(const `[`Point`](#classPoint)` &) const`            | 
`protected virtual void `[`print`](#group__segment_1gaf6904981d6c631a7756499cd0b42ce29)`(std::ostream & o) const`            | 
`public  `[`SpiralPoint`](#group__segment_1ga80277d41d835c643826b4e813490849a)`(double,double,double)`            | 
`public  `[`SpiralPoint`](#group__segment_1gae521f98807e13c4e0019b561565cda18)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public `[`SpiralPoint`](#structSpiralPoint)` & `[`operator=`](#group__segment_1gab4085951f6e5264f912feadf327a8c81)`(const `[`SpiralPoint`](#structSpiralPoint)` &)`            | 
`public bool `[`isnormal`](#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0)`() const`            | #### Returns
`public void `[`operator+=`](#group__segment_1ga50ce60a751c8ad173a53ccee629a4598)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public void `[`operator-=`](#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)`            | 
`public void `[`operator*=`](#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03)`(double a)`            | 
`public double `[`distance`](#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs) const`            | #### Returns
`public  `[`NoteName`](#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb)`(char n,float alt,int id)`            | notename object from name, alteration and index.
`public  `[`NoteName`](#group__segment_1gaba2eabd0e4626b56685968ea53153b3b)`(const `[`NoteName`](#structNoteName)` & rhs)`            | 
`public `[`NoteName`](#structNoteName)` & `[`operator=`](#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f)`(const `[`NoteName`](#structNoteName)` & rhs)`            | 
`public static const `[`NoteName`](#structNoteName)` & `[`ofkey`](#group__segment_1ga055480a382a6fde05bde51abed31a56c)`(int k)`            | ref to a [NoteName](api-segment.md#structNoteName) in table synonyms. */
`public static const `[`NoteName`](#structNoteName)` & `[`closest`](#group__segment_1gaf4a2321d9bc5a69a5b8a94cf1e146052)`(unsigned int pitch,const `[`SpiralPoint`](#structSpiralPoint)` & p)`            | note name (ref in table synonyms) corresponding to given midi pitch and closest to given point.
`class `[`AlignedInterval`](api-segment.md#classAlignedInterval) | Extension of [Interval](#classInterval) with computed alignment of [InputSegment](#classInputSegment) points onto left- and right-bounds.
`class `[`Environment`](api-segment.md#classEnvironment) | wrapper abstract class embedding a standard input environment for parsing algos.
`class `[`InputSegment`](api-segment.md#classInputSegment) | intermediate representation for input performance data.
`class `[`InputSegmentMono`](api-segment.md#classInputSegmentMono) | conversion of [InputSegment](api-segment.md#classInputSegment) to remove overlapping notes.
`class `[`InputSegmentNogap`](api-segment.md#classInputSegmentNogap) | 
`class `[`Interval`](api-segment.md#classInterval) | an [Interval](#classInterval) in an input segment with realtime bounds (seconds) and musical bounds (fraction of bars).
`class `[`IntervalHeap`](api-segment.md#classIntervalHeap) | table for storage of aligned intervals to avoid recomputation of alignments.
`class `[`IntervalTree`](api-segment.md#classIntervalTree) | extension of Aligned [Interval](api-segment.md#classInterval) to define a tree of nested Alignements with sharing using hash table to store all alignment constructed.
`class `[`MusEvent`](api-segment.md#classMusEvent) | input events
`class `[`RestEvent`](api-segment.md#classRestEvent) | 
`class `[`NoteEvent`](api-segment.md#classNoteEvent) | 
`class `[`MusPoint`](api-segment.md#classMusPoint) | [Point](#classPoint) extended with mutable musical time date and duration (expressed in fraction of bars).
`class `[`Pitch`](api-segment.md#classPitch) | internal representation of a pitch value.
`class `[`Point`](api-segment.md#classPoint) | timestamped event.
`struct `[`IntervalHasher`](api-segment.md#structIntervalHasher) | hash function for using interval as key in a unordered map.
`struct `[`PointedIntervalEq`](api-segment.md#structPointedIntervalEq) | 
`struct `[`PointedIntervalHash`](api-segment.md#structPointedIntervalHash) | 
`struct `[`SpiralPoint`](api-segment.md#structSpiralPoint) | Elaine Chew's spiral of fifths.
`struct `[`NoteName`](api-segment.md#structNoteName) | 

## Members

#### `public std::ostream & `[`operator<<`](#group__segment_1gaa5d5d2dd440400af33e39d031cb08fa5)`(std::ostream & o,const `[`AlignedInterval`](#classAlignedInterval)` & p)` {#group__segment_1gaa5d5d2dd440400af33e39d031cb08fa5}

#### `public std::ostream & `[`operator<<`](#group__segment_1ga6c33ecb9851e077e90345090b15c87c3)`(std::ostream & o,const `[`InputSegment`](#classInputSegment)` & s)` {#group__segment_1ga6c33ecb9851e077e90345090b15c87c3}

#### `public std::ostream & `[`operator<<`](#group__segment_1ga2f4c47a191d9e8f503a8a18bfba89f2c)`(std::ostream & o,const `[`Interval`](#classInterval)` & p)` {#group__segment_1ga2f4c47a191d9e8f503a8a18bfba89f2c}

#### `public std::ostream & `[`operator<<`](#group__segment_1gac85491c9b09a0e009fe58f15da5e88ab)`(std::ostream & o,const `[`IntervalTree`](#classIntervalTree)` & p)` {#group__segment_1gac85491c9b09a0e009fe58f15da5e88ab}

#### `public inline std::ostream & `[`operator<<`](#group__segment_1gade87c7b11c1a1fdbcd922e08b3eaa3c5)`(std::ostream & o,const `[`MusEvent`](#classMusEvent)` & rhs)` {#group__segment_1gade87c7b11c1a1fdbcd922e08b3eaa3c5}

#### `public std::ostream & `[`operator<<`](#group__segment_1ga7d6e1aa31e5a2132257840adeb5bf23f)`(std::ostream & o,const `[`Pitch`](#classPitch)` & p)` {#group__segment_1ga7d6e1aa31e5a2132257840adeb5bf23f}

#### `public std::ostream & `[`operator<<`](#group__segment_1gad95cc714e40b63c5df8e1dc41305178e)`(std::ostream & o,const `[`Point`](#classPoint)` & rhs)` {#group__segment_1gad95cc714e40b63c5df8e1dc41305178e}

#### `public inline bool `[`operator==`](#group__segment_1gaf9d08e42ae7632f815ad7bd3c093b497)`(const `[`SpiralPoint`](#structSpiralPoint)` & lhs,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1gaf9d08e42ae7632f815ad7bd3c093b497}

#### `public inline bool `[`operator!=`](#group__segment_1ga0b4ffecf00942ad046a9ea6785319f6f)`(const `[`SpiralPoint`](#structSpiralPoint)` & lhs,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1ga0b4ffecf00942ad046a9ea6785319f6f}

#### `public inline std::ostream & `[`operator<<`](#group__segment_1gab3a698d42f743ce361da6916209eca88)`(std::ostream & o,const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1gab3a698d42f743ce361da6916209eca88}

#### `public inline bool `[`operator==`](#group__segment_1gaeba3d7c6ab7481a52f2cd4ce980c08ca)`(const `[`NoteName`](#structNoteName)` & lhs,const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1gaeba3d7c6ab7481a52f2cd4ce980c08ca}

#### `public inline bool `[`operator!=`](#group__segment_1ga7c5e53ea6aa75682a2320bdf2f6f17fa)`(const `[`NoteName`](#structNoteName)` & lhs,const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1ga7c5e53ea6aa75682a2320bdf2f6f17fa}

#### `public inline std::ostream & `[`operator<<`](#group__segment_1ga696a465764983bfca52bcd6406e373f9)`(std::ostream & o,const `[`NoteName`](#structNoteName)` & p)` {#group__segment_1ga696a465764983bfca52bcd6406e373f9}

#### `public  `[`AlignedInterval`](#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,bool f_align)` {#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da}

[Interval](#classInterval) covering the whole length of the given input segment with given musical time length (number of bars).

#### Parameters
* `s` given input segment 

* `mend` given musical time length 

* `f_align` flag says wether alignement must be computed for the interval.

#### `protected  `[`AlignedInterval`](#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,bool f_align)` {#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492}

aligned interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

#### Parameters
* `first` must be the first element of input segment after the beginning of this interval.

* `f_align` flag says wether alignement must be computed for the interval.

#### `public  `[`AlignedInterval`](#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` {#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5}

copy.

#### `public virtual `[`AlignedInterval`](#classAlignedInterval)` & `[`operator=`](#group__segment_1ga304aac2ec620d785bbfb67996a7a613b)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` {#group__segment_1ga304aac2ec620d785bbfb67996a7a613b}

#### `public virtual bool `[`operator==`](#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62)`(const `[`AlignedInterval`](#classAlignedInterval)` &) const` {#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62}

#### `public bool `[`aligned`](#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175)`() const` {#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175}

this interval has been aligned.

#### `public size_t `[`align`](#group__segment_1ga25f42094dbb3623c73df11dd85596185)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` {#group__segment_1ga25f42094dbb3623c73df11dd85596185}

set the alignment parameters, starting from index b of input segment point and return the next index of point in input segment to be processed (first index at right of this interval) or the size of input segment (total # points) if end of segment is reached.

#### Parameters
* `s` input segment processed 

* `b` must be the index of a segment's point. it must be after the left bound of the interval (begin). it can be out of the interval, i.e. after the right bound (end). _seg_first is replaced by b.

The realtime begin date of this interval can be out of the input segment bounds. 

The realtime end date of this interval can be out of the input segment bounds. In the later case, alignement is done like the input segment is padded with empty space up to the end of this interval.

#### `public size_t `[`align`](#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77)`(const `[`InputSegment`](#classInputSegment)` * s)` {#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77}

same as previous but uses _seg_first instead of argument b.

#### `public size_t `[`rewind`](#group__segment_1gafad6a7eea9e5892cfae9986f6263a738)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` {#group__segment_1gafad6a7eea9e5892cfae9986f6263a738}

compute only the value of the next point (the first element of input segment after the right bound of this interval) starting from index b of input segment point.

#### Parameters
* `b` same preconditions on b as for align.

#### `public size_t `[`rewind`](#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16)`(const `[`InputSegment`](#classInputSegment)` *)` {#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16}

same as previous but uses _seg_first instead of arg. b.

#### `private bool `[`_check_first`](#group__segment_1ga0be5d430ebcf64f2789eb37886b16367)`(const `[`InputSegment`](#classInputSegment)` *)` {#group__segment_1ga0be5d430ebcf64f2789eb37886b16367}

#### `private bool `[`_check_next`](#group__segment_1ga427dfea0ea3968e99fb4f59ff462a378)`(const `[`InputSegment`](#classInputSegment)` *)` {#group__segment_1ga427dfea0ea3968e99fb4f59ff462a378}

#### `public  `[`Environment`](#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf)`(`[`InputSegment`](#classInputSegment)` * s)` {#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf}

#### Parameters
* `s` input segment can be :

* NULL : e.g. for simple enumeration of the given wta

* non-NULL: e.g. for quantization of the points of given input segment using a given wta

#### `public  `[`~Environment`](#group__segment_1ga8e294735187880dd3d59be10c425b29d)`()` {#group__segment_1ga8e294735187880dd3d59be10c425b29d}

#### `public  `[`InputSegment`](#group__segment_1gaec471ec05052a932b1bb2738bfc8b172)`(double b,double e)` {#group__segment_1gaec471ec05052a932b1bb2738bfc8b172}

constructs an empty input segment (no events)

#### Parameters
* `b` start date (in seconds) 

* `e` end date (in seconds)

#### `public  `[`InputSegment`](#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492)`(const `[`InputSegment`](#classInputSegment)` &)` {#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492}

#### `public  `[`InputSegment`](#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef)`(const `[`InputSegment`](#classInputSegment)` & s,double b,double e)` {#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef}

copy and resize.

#### Parameters
* `s` input segment to copy. 

* `b` new start date (in seconds) 

* `e` new end date (in seconds) 

copy only the events inside the new bounds.

#### `public virtual  `[`~InputSegment`](#group__segment_1gab8da320feb29d4b009d2e6a37924337e)`()` {#group__segment_1gab8da320feb29d4b009d2e6a37924337e}

#### `public size_t `[`size`](#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63)`() const` {#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63}

number of non-floating points in segment.

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`begin`](#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d)`()` {#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d}

iterators to the segment's contents.

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`end`](#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e)`()` {#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e}

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cbegin`](#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90)`() const` {#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90}

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cend`](#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b)`() const` {#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b}

#### `protected bool `[`check_index`](#group__segment_1ga82a64bae54200b634bc42ac06dc7a916)`(long i) const` {#group__segment_1ga82a64bae54200b634bc42ac06dc7a916}

#### `protected void `[`link`](#group__segment_1ga43310a16681e2241b20da4b68de9f35b)`(long i,long j)` {#group__segment_1ga43310a16681e2241b20da4b68de9f35b}

the event of index i is linked to the event of index j.

#### Parameters
* `j` must be a valid index, 

* `i` must be a valid and not NULL index, 

both i and j can be in heap (negative index). 

the point at i must not be linked (NULL link index). 

the realtime date of i must be <= realtime date of j (if not NULL).

#### `public long `[`add_back`](#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d}

insert new timestamped muspoint created from the parameters, at the end of the segment.

The realtime dateof the point must be after the current last point of this segment. 

#### Returns
the index of the inserted point (can be used as link).

#### `public long `[`add_back`](#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4}

#### `public long `[`add_floating`](#group__segment_1gad44eb7379e181fc4295ee2514a568204)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1gad44eb7379e181fc4295ee2514a568204}

create new timestamped muspoint from the parameters, and add the the heap of floating points (not in segment).

(allocated and freed by this segment) 
#### Returns
the index of the new point (can be used as link).

#### `public long `[`add_floating`](#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a}

#### `public const `[`MusPoint`](#classMusPoint)` & `[`point`](#group__segment_1ga5463f900db31be4b7d109e88a710971f)`(long i) const` {#group__segment_1ga5463f900db31be4b7d109e88a710971f}

return a ref to the point of index i.

* ith point in this input segment if 0 <= i < input segment size

* or the -i-1th floating point if heap size <= i < 0. 
#### Parameters
* `i` must be in the above range of values.

#### `protected `[`MusPoint`](#classMusPoint)` & `[`ncpoint`](#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd)`(long i)` {#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd}

same as point but not const.

#### `public `[`MusEvent`](#classMusEvent)` * `[`event`](#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca)`(long i) const` {#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca}

return the event of the point of index i.

#### `public double `[`rdate`](#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a)`(long i) const` {#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a}

return the real-time date (in seconds) of the point of index i

#### `public double `[`rduration`](#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf)`(const `[`MusPoint`](#classMusPoint)` & p) const` {#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf}

return the real-time duration (in seconds) of the given point.

#### `public double `[`rduration`](#group__segment_1gafbf05e143d416de49180d2f18a53977b)`(long i) const` {#group__segment_1gafbf05e143d416de49180d2f18a53977b}

return the real-time duration (in seconds) of the point of index i.

#### `public `[`Rational`](#classRational)` & `[`mdate`](#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50)`(long i)` {#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50}

return a reference to the musical-time date (in fraction of bar) of the point of index i.

#### `public `[`Rational`](#classRational)` & `[`mduration`](#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342)`(long i)` {#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342}

return a reference to the musical-time duration (in fraction of bar) of the point of index i.

#### `public void `[`close`](#group__segment_1gae75db088893a7cfc719ec393e09d7ece)`(double e)` {#group__segment_1gae75db088893a7cfc719ec393e09d7ece}

set end date.

#### `public void `[`respell`](#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c)`(int k)` {#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c}

pitch spelling. unwindowed.

this segment must have been quantized.

#### `public void `[`respell`](#group__segment_1gac79787254008e05d9f54226d93dcb0cb)`(`[`Rational`](#classRational)` ws,int k)` {#group__segment_1gac79787254008e05d9f54226d93dcb0cb}

pitch spelling with a sliding window of given musical duration.

this segment must have been quantized.

#### `public void `[`print`](#group__segment_1ga623c2367191018ecac046e7e11f14976)`(std::ostream &) const` {#group__segment_1ga623c2367191018ecac046e7e11f14976}

print size to output stream.

#### `public template<>`  <br/>`void `[`quantize`](#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e)`(`[`Atable`](#classAtable)`< P > * table,const P & p)` {#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e}

set the musical time date and duration of events in this given input segment, according to the best run for p in given table.

ptr type P must have interval. 

all the musical dates and durations of events in this segment will be changed.

#### `public template<>`  <br/>`size_t `[`quantizu`](#group__segment_1gab4c42d088ce3d170b7899712789ab464)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)` {#group__segment_1gab4c42d088ce3d170b7899712789ab464}

set the musical time date and duration of events in this given input segment, according to the best run for p in given table, starting from point number b in interval.

#### Returns
the next point of input segment with musical date and duration yet unset after processing p. 

ptr type P must have interval. 

all the musical date of events must be unknown in seg. 

all the musical durations of events must be unknown in seg.

TBR (replaced by quantize)

#### `private template<>`  <br/>`size_t `[`quantize_assert`](#group__segment_1ga8c7a48cd8c319c2d5697b57ea2c4d733)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)` {#group__segment_1ga8c7a48cd8c319c2d5697b57ea2c4d733}

#### `public  `[`InputSegmentMono`](#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2)`(const `[`InputSegment`](#classInputSegment)` & s)` {#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2}

transform the given input segment into a monophonic input segment (no two notes in the same time).

by moving note-off events

#### `public  `[`InputSegmentNogap`](#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548)`(const `[`InputSegment`](#classInputSegment)` & s,bool norest)` {#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548}

transform the given input segment into a new input segment without gaps.

by prolongations of some notes (option norest = true) or insertion of rests events (option norest = false)

#### `public  `[`Interval`](#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` {#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125}

top interval constructed from an input segment.

[Interval](#classInterval) covering the whole length of the given input segment s with given musical time length (number of bars)

#### `protected  `[`Interval`](#group__segment_1gaefc21b7c838661c05286304f6d891690)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend)` {#group__segment_1gaefc21b7c838661c05286304f6d891690}

build an interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

not aligned.

#### `public  `[`Interval`](#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5)`(const `[`Interval`](#classInterval)` &)` {#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5}

copy.

#### `public  `[`Interval`](#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458)`(`[`Interval`](#classInterval)` *)` {#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458}

used for copy of downcasted [IntervalTree](#classIntervalTree).

#### `private bool `[`sanity_check`](#group__segment_1ga04dee911c27559f22144e1ab329550df)`()` {#group__segment_1ga04dee911c27559f22144e1ab329550df}

#### `private bool `[`sanity_check`](#group__segment_1ga29a886b3ca41b923ffe9c1a291973dc9)`(const `[`InputSegment`](#classInputSegment)` *)` {#group__segment_1ga29a886b3ca41b923ffe9c1a291973dc9}

#### `public virtual `[`Interval`](#classInterval)` & `[`operator=`](#group__segment_1ga6508f58e15c54be6146d5505d91a4b91)`(const `[`Interval`](#classInterval)` &)` {#group__segment_1ga6508f58e15c54be6146d5505d91a4b91}

#### `public virtual bool `[`operator==`](#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6)`(const `[`Interval`](#classInterval)` &) const` {#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6}

for using [Interval](#classInterval) as key in map.

#### `public bool `[`insideBar`](#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb)`() const` {#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb}

#### `public  `[`IntervalHeap`](#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51)`()` {#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51}

#### `public  `[`~IntervalHeap`](#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8)`()` {#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8}

#### `public bool `[`empty`](#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0)`() const` {#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0}

#### `public size_t `[`size`](#group__segment_1ga87e6be639c7435053444d83913505c1b)`() const` {#group__segment_1ga87e6be639c7435053444d83913505c1b}

#### `public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,double rext)` {#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019}

find or create (and push) a top interval of real-time duration covering the whole length of the given input segment s (root of interval tree) + the given extension.

* inside-bar interval (musical time duration of 1 bar) if flag bar is true

* multiple interval if flag bar is false (default).

not aligned.

#### `public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad886d53d2881a80f06c6f9fbf202d727)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` {#group__segment_1gad886d53d2881a80f06c6f9fbf202d727}

get interval from heap, build it if not present.

not aligned (when built).

#### `private `[`IntervalTree`](#classIntervalTree)` *const `[`push`](#group__segment_1ga3327b1c81b67df8c21468492a845630e)`(`[`IntervalTree`](#classIntervalTree)` * p)` {#group__segment_1ga3327b1c81b67df8c21468492a845630e}

#### `protected  `[`IntervalTree`](#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` {#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0}

top interval (root of interval tree).

covering the whole length of the given input segment s inside-bar interval of musical time duration of 1 bar if flag bar is true multi-bar interval if flag bar is false.

the interval tree created is not registered to an interval heap. 

not aligned.

#### `protected  `[`IntervalTree`](#group__segment_1gac16f2a8d9c584a869bbed6a263914360)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` {#group__segment_1gac16f2a8d9c584a869bbed6a263914360}

build an interval tree with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

#### Parameters
* `p` pointer to the parent. 

* `ps` pointer to the previous sibling. 

not aligned - must be aligned afterwards. 

use only internaly construction of recursive paths.

#### `public  `[`~IntervalTree`](#group__segment_1gae2c50e46e3997dd8631669046bf06c27)`()` {#group__segment_1gae2c50e46e3997dd8631669046bf06c27}

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`top`](#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` * h,`[`Rational`](#classRational)` mend)` {#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b}

top interval (root of interval tree) covering the whole length of the given input segment s.

inside-bar interval of musical time duration of 1 bar if flag bar is true. multi-bar interval if flag bar is false.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`split`](#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` {#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048}

return a sub interval.

* if i = 1 first sub-interval starting at same point as this interval of realtime duration rdur of musical duration mdur bar. it not is aligned.

* if i = 2 second sub-interval (rest) starting at this interval realtime start + rdur and this interval musical time start + mdur of realtime duration this realtime duration - rdur. if the real starting date is out of this interval, then the real duration of the returned second sub-interval is zero. the musical starting date must be inside this interval. it is not aligned.

#### Parameters
* `rdur` must be strictly positive. 

* `mdur` must be strictly positive.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`split_back`](#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` {#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c}

return a sub interval.

* if i = 1 first sub-interval starts at same point as this interval of realtime duration : duration of this interval - rdur of musical duration : musical duration of this interval - mdur bars. if the starting date is out of the input segment, then the real duration of the returned first sub-interval is zero. it is not aligned.

* if i = 2 second sub-interval (rest) starts at this interval realtime end - rdur and this interval musical time end - mdur of realtime duration rdur. it is not aligned.

#### Parameters
* `rdur` must be strictly positive. 

* `mdur` must be strictly positive.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`sub`](#group__segment_1gacb8de7e3756951950c391d241adec21c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,size_t a,size_t i)` {#group__segment_1gacb8de7e3756951950c391d241adec21c}

return a the i-1th sub-interval of the division of this interval in n equal parts. the sub-interval returned is aligned.

#### Parameters
* `a` must be > 1 

* `i` must be smaller than a. 

this interval must be aligned.

#### `public  `[`MusEvent`](#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17)`(int nb)` {#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17}

#### `public  `[`MusEvent`](#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27)`(const `[`MusEvent`](#classMusEvent)` &)` {#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27}

#### `public  `[`RestEvent`](#group__segment_1gaafcefa86601b97d137cfba40ed349414)`(int nb)` {#group__segment_1gaafcefa86601b97d137cfba40ed349414}

#### `public  `[`RestEvent`](#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91)`(const `[`RestEvent`](#classRestEvent)` &)` {#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91}

#### `public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga6ebb6acd4c78929d31a4831c58911639)`() const` {#group__segment_1ga6ebb6acd4c78929d31a4831c58911639}

#### `public virtual void `[`print`](#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45)`(std::ostream & o) const` {#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45}

#### `public  `[`NoteEvent`](#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be)`(unsigned int vel,int nb)` {#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be}

unpitched note (drums).

#### `public  `[`NoteEvent`](#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7)`(`[`Pitch`](#classPitch)` p,unsigned int vel,int nb)` {#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7}

pitched note.

#### `public  `[`NoteEvent`](#group__segment_1ga135e904aa3f5ea4d375e451281fe5323)`(unsigned int p,unsigned int vel,int nb)` {#group__segment_1ga135e904aa3f5ea4d375e451281fe5323}

pitched note with MIDI pitch in 0..127.

#### `public  `[`NoteEvent`](#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc)`(const `[`NoteEvent`](#classNoteEvent)` &)` {#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc}

#### `public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049)`() const` {#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049}

#### `public virtual void `[`print`](#group__segment_1gafa25174e584b872e814643c895cad283)`(std::ostream & o) const` {#group__segment_1gafa25174e584b872e814643c895cad283}

#### `public  `[`MusPoint`](#group__segment_1ga006e3062fd920202aab9e36f6a0e394e)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1ga006e3062fd920202aab9e36f6a0e394e}

#### `public  `[`MusPoint`](#group__segment_1ga1bb17bef698401de18bc814c7f965999)`(const `[`Point`](#classPoint)` & p,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1ga1bb17bef698401de18bc814c7f965999}

copy of point.

extended with given onset and duration values (in fraction of bars)

#### `public  `[`MusPoint`](#group__segment_1ga5f00500846d251b165f48a41552be18e)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga5f00500846d251b165f48a41552be18e}

event (if any) is cloned.

#### `public  `[`~MusPoint`](#group__segment_1ga036951554acf624dd62469abbd8142df)`()` {#group__segment_1ga036951554acf624dd62469abbd8142df}

#### `public `[`MusPoint`](#classMusPoint)` & `[`operator=`](#group__segment_1ga522126acc9eb79e737068941370bb172)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga522126acc9eb79e737068941370bb172}

event (if any) is cloned.

#### `public virtual bool `[`operator==`](#group__segment_1ga07139fb89dcc2388b299b9e6464b3177)`(const `[`Point`](#classPoint)` &) const` {#group__segment_1ga07139fb89dcc2388b299b9e6464b3177}

#### `protected virtual void `[`print`](#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830)`(std::ostream & o) const` {#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830}

#### `public  `[`Pitch`](#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084)`()` {#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084}

undef pitch value.

#### `public  `[`Pitch`](#group__segment_1gaf3f9d88915bb6688d522f09d7542f690)`(char name,float alt,int oct)` {#group__segment_1gaf3f9d88915bb6688d522f09d7542f690}

construct pitch from name+alteration+octave.

#### Parameters
* `name` see table NAMES in [constant.h](#constant_8h_source)

* `alt` in [-2, 2] where 1.0 is half tone 

* `oct` in -10..10

#### `public  `[`Pitch`](#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b)`(unsigned int pitch,PitchUnit u)` {#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b}

construct note from MIDI pitch

#### Parameters
* `pitch` in 0..127

#### `public  `[`Pitch`](#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b)`(const `[`Pitch`](#classPitch)` &)` {#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b}

#### `public `[`Pitch`](#classPitch)` & `[`operator=`](#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91)`(const `[`Pitch`](#classPitch)` &)` {#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91}

#### `public bool `[`operator==`](#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d)`(const `[`Pitch`](#classPitch)` &) const` {#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d}

#### `private static char `[`midi_to_name`](#group__segment_1ga507b693a51dd2d626dc3cf42e7d93d99)`(unsigned int)` {#group__segment_1ga507b693a51dd2d626dc3cf42e7d93d99}

#### `private static float `[`midi_to_alt`](#group__segment_1ga45a060956b0a13178b4a2e987597ab95)`(unsigned int)` {#group__segment_1ga45a060956b0a13178b4a2e987597ab95}

#### `private static int `[`midi_to_oct`](#group__segment_1gade0788e4c49153b64197dce1203744ae)`(unsigned int)` {#group__segment_1gade0788e4c49153b64197dce1203744ae}

#### `private static unsigned int `[`name_to_int`](#group__segment_1gaa706b7d526d2ccb75c03c202dcd54e5c)`(char)` {#group__segment_1gaa706b7d526d2ccb75c03c202dcd54e5c}

#### `private static unsigned int `[`name_to_midi`](#group__segment_1ga18ee1055465d12e1b9778a4c625cc850)`(char,float,int)` {#group__segment_1ga18ee1055465d12e1b9778a4c625cc850}

#### `public  `[`Point`](#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link)` {#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d}

timestamped monophonic or polyphonic event.

#### `public  `[`Point`](#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc)`(const `[`Point`](#classPoint)` &)` {#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc}

event (if any) is cloned.

#### `public  `[`~Point`](#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1)`()` {#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1}

event is deallocated and matcher (linked) also.

#### `public virtual `[`Point`](#classPoint)` & `[`operator=`](#group__segment_1ga55eeab949e62268da63176d48570eb54)`(const `[`Point`](#classPoint)` &)` {#group__segment_1ga55eeab949e62268da63176d48570eb54}

event (if any) is cloned.

#### `public virtual bool `[`operator==`](#group__segment_1ga1055933b999ef990df6b48745c27a197)`(const `[`Point`](#classPoint)` &) const` {#group__segment_1ga1055933b999ef990df6b48745c27a197}

#### `protected virtual void `[`print`](#group__segment_1gaf6904981d6c631a7756499cd0b42ce29)`(std::ostream & o) const` {#group__segment_1gaf6904981d6c631a7756499cd0b42ce29}

#### `public  `[`SpiralPoint`](#group__segment_1ga80277d41d835c643826b4e813490849a)`(double,double,double)` {#group__segment_1ga80277d41d835c643826b4e813490849a}

#### `public  `[`SpiralPoint`](#group__segment_1gae521f98807e13c4e0019b561565cda18)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1gae521f98807e13c4e0019b561565cda18}

#### `public `[`SpiralPoint`](#structSpiralPoint)` & `[`operator=`](#group__segment_1gab4085951f6e5264f912feadf327a8c81)`(const `[`SpiralPoint`](#structSpiralPoint)` &)` {#group__segment_1gab4085951f6e5264f912feadf327a8c81}

#### `public bool `[`isnormal`](#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0)`() const` {#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0}

#### Returns
wether coordinate are not NAN. */

#### `public void `[`operator+=`](#group__segment_1ga50ce60a751c8ad173a53ccee629a4598)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1ga50ce60a751c8ad173a53ccee629a4598}

#### `public void `[`operator-=`](#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1}

#### `public void `[`operator*=`](#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03)`(double a)` {#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03}

#### `public double `[`distance`](#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs) const` {#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745}

#### Returns
Euclidian distance to given point.

#### `public  `[`NoteName`](#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb)`(char n,float alt,int id)` {#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb}

notename object from name, alteration and index.

#### Parameters
* `n` must be between 'A' and 'G' 

* `alt` must be between -2.0 and 2.0 

* `id` must be between -15 and 19

#### `public  `[`NoteName`](#group__segment_1gaba2eabd0e4626b56685968ea53153b3b)`(const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1gaba2eabd0e4626b56685968ea53153b3b}

#### `public `[`NoteName`](#structNoteName)` & `[`operator=`](#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f)`(const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f}

#### `public static const `[`NoteName`](#structNoteName)` & `[`ofkey`](#group__segment_1ga055480a382a6fde05bde51abed31a56c)`(int k)` {#group__segment_1ga055480a382a6fde05bde51abed31a56c}

ref to a [NoteName](#structNoteName) in table synonyms. */

#### `public static const `[`NoteName`](#structNoteName)` & `[`closest`](#group__segment_1gaf4a2321d9bc5a69a5b8a94cf1e146052)`(unsigned int pitch,const `[`SpiralPoint`](#structSpiralPoint)` & p)` {#group__segment_1gaf4a2321d9bc5a69a5b8a94cf1e146052}

note name (ref in table synonyms) corresponding to given midi pitch and closest to given point.

#### Parameters
* `p` point in spiral 

* `pitch` must be in 0..128

# class `AlignedInterval` {#classAlignedInterval}

```
class AlignedInterval
  : public Interval
```  

Extension of [Interval](#classInterval) with computed alignment of [InputSegment](#classInputSegment) points onto left- and right-bounds.

The result of aligment can be consulted with function l/rsize, l/rfirst. alignement is computed by function align.

The alignement is computed automatically for newly created intervals, the other created intervals (multiple-bars intervals) are not aligned.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`AlignedInterval`](#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,bool f_align)` | [Interval](#classInterval) covering the whole length of the given input segment with given musical time length (number of bars).
`public  `[`AlignedInterval`](#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` | copy.
`public inline  `[`~AlignedInterval`](#classAlignedInterval_1ae327b28af603aaffbe9bc8480c6e2109)`()` | do not deallocate the segment here.
`public virtual `[`AlignedInterval`](#classAlignedInterval)` & `[`operator=`](#group__segment_1ga304aac2ec620d785bbfb67996a7a613b)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` | 
`public virtual bool `[`operator==`](#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62)`(const `[`AlignedInterval`](#classAlignedInterval)` &) const` | 
`public inline size_t `[`lsize`](#classAlignedInterval_1a260f8eead747a05642d7b5d720d02e5b)`() const` | number of elements of input segment in the first half of this interval.
`public inline size_t `[`lfirst`](#classAlignedInterval_1a85114f9883305f0cf975dbdffff41772)`() const` | index of the first element of input segment inside the fist half of this interval.
`public inline size_t `[`rsize`](#classAlignedInterval_1abf3b5daa25e0d74999e5a2d1d04cd185)`() const` | number of elements of input segment in the second half of this interval.
`public inline size_t `[`rfirst`](#classAlignedInterval_1aa7c4a66d5fd0ff2dc29a4fea57f0c561)`() const` | index of the first element of input segment inside the second half of this interval.
`public inline size_t `[`size`](#classAlignedInterval_1aacfe86f36bfd28f6a56c7a673ed7dad7)`() const` | number of elements of input segment in this interval.
`public inline size_t `[`first`](#classAlignedInterval_1a1660736ae6e829e6c92616e49784a583)`() const` | index of the first element of input segment after the right bound of this interval (i.e. inside or after this interval).
`public inline size_t `[`next`](#classAlignedInterval_1ac9617c302c66993c1f84c757f2c71d16)`() const` | index of the first element of input segment ouside this interval (= after the right bound).
`public inline bool `[`inhabited`](#classAlignedInterval_1adefeebb5ddd10a68e83ed7382626d380)`() const` | this interval contains at least an element of the input segment
`public size_t `[`align`](#group__segment_1ga25f42094dbb3623c73df11dd85596185)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` | set the alignment parameters, starting from index b of input segment point and return the next index of point in input segment to be processed (first index at right of this interval) or the size of input segment (total # points) if end of segment is reached.
`public size_t `[`align`](#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77)`(const `[`InputSegment`](#classInputSegment)` * s)` | same as previous but uses _seg_first instead of argument b.
`public size_t `[`rewind`](#group__segment_1gafad6a7eea9e5892cfae9986f6263a738)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` | compute only the value of the next point (the first element of input segment after the right bound of this interval) starting from index b of input segment point.
`public size_t `[`rewind`](#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16)`(const `[`InputSegment`](#classInputSegment)` *)` | same as previous but uses _seg_first instead of arg. b.
`public bool `[`aligned`](#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175)`() const` | this interval has been aligned.
`protected  `[`AlignedInterval`](#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,bool f_align)` | aligned interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

## Members

#### `public  `[`AlignedInterval`](#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,bool f_align)` {#group__segment_1ga7e9399ce64bb21aa2d2c3cd682ca95da}

[Interval](#classInterval) covering the whole length of the given input segment with given musical time length (number of bars).

#### Parameters
* `s` given input segment 

* `mend` given musical time length 

* `f_align` flag says wether alignement must be computed for the interval.

#### `public  `[`AlignedInterval`](#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` {#group__segment_1ga5bf2bf3fe1a1791989ec52969aace0a5}

copy.

#### `public inline  `[`~AlignedInterval`](#classAlignedInterval_1ae327b28af603aaffbe9bc8480c6e2109)`()` {#classAlignedInterval_1ae327b28af603aaffbe9bc8480c6e2109}

do not deallocate the segment here.

#### `public virtual `[`AlignedInterval`](#classAlignedInterval)` & `[`operator=`](#group__segment_1ga304aac2ec620d785bbfb67996a7a613b)`(const `[`AlignedInterval`](#classAlignedInterval)` &)` {#group__segment_1ga304aac2ec620d785bbfb67996a7a613b}

#### `public virtual bool `[`operator==`](#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62)`(const `[`AlignedInterval`](#classAlignedInterval)` &) const` {#group__segment_1ga40f7de6ee8d8b73172ca1dbfa54bfe62}

#### `public inline size_t `[`lsize`](#classAlignedInterval_1a260f8eead747a05642d7b5d720d02e5b)`() const` {#classAlignedInterval_1a260f8eead747a05642d7b5d720d02e5b}

number of elements of input segment in the first half of this interval.

the interval must have been aligned.

#### `public inline size_t `[`lfirst`](#classAlignedInterval_1a85114f9883305f0cf975dbdffff41772)`() const` {#classAlignedInterval_1a85114f9883305f0cf975dbdffff41772}

index of the first element of input segment inside the fist half of this interval.

#### Returns
out_of_range (= size of segment) if l_size() == 0. 

the interval must have been aligned.

#### `public inline size_t `[`rsize`](#classAlignedInterval_1abf3b5daa25e0d74999e5a2d1d04cd185)`() const` {#classAlignedInterval_1abf3b5daa25e0d74999e5a2d1d04cd185}

number of elements of input segment in the second half of this interval.

the interval must have been aligned.

#### `public inline size_t `[`rfirst`](#classAlignedInterval_1aa7c4a66d5fd0ff2dc29a4fea57f0c561)`() const` {#classAlignedInterval_1aa7c4a66d5fd0ff2dc29a4fea57f0c561}

index of the first element of input segment inside the second half of this interval.

#### Returns
out_of_range (= size of segment) if r_size() == 0. 

the interval must have been aligned.

#### `public inline size_t `[`size`](#classAlignedInterval_1aacfe86f36bfd28f6a56c7a673ed7dad7)`() const` {#classAlignedInterval_1aacfe86f36bfd28f6a56c7a673ed7dad7}

number of elements of input segment in this interval.

the interval must have been aligned.

#### `public inline size_t `[`first`](#classAlignedInterval_1a1660736ae6e829e6c92616e49784a583)`() const` {#classAlignedInterval_1a1660736ae6e829e6c92616e49784a583}

index of the first element of input segment after the right bound of this interval (i.e. inside or after this interval).

#### Returns
out_of_range (= size of segment) if there is none.

#### `public inline size_t `[`next`](#classAlignedInterval_1ac9617c302c66993c1f84c757f2c71d16)`() const` {#classAlignedInterval_1ac9617c302c66993c1f84c757f2c71d16}

index of the first element of input segment ouside this interval (= after the right bound).

#### Returns
out_of_range (= size of segment) if there is none. 

the interval must have been aligned.

#### `public inline bool `[`inhabited`](#classAlignedInterval_1adefeebb5ddd10a68e83ed7382626d380)`() const` {#classAlignedInterval_1adefeebb5ddd10a68e83ed7382626d380}

this interval contains at least an element of the input segment

the interval must have been aligned.

#### `public size_t `[`align`](#group__segment_1ga25f42094dbb3623c73df11dd85596185)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` {#group__segment_1ga25f42094dbb3623c73df11dd85596185}

set the alignment parameters, starting from index b of input segment point and return the next index of point in input segment to be processed (first index at right of this interval) or the size of input segment (total # points) if end of segment is reached.

#### Parameters
* `s` input segment processed 

* `b` must be the index of a segment's point. it must be after the left bound of the interval (begin). it can be out of the interval, i.e. after the right bound (end). _seg_first is replaced by b.

The realtime begin date of this interval can be out of the input segment bounds. 

The realtime end date of this interval can be out of the input segment bounds. In the later case, alignement is done like the input segment is padded with empty space up to the end of this interval.

#### `public size_t `[`align`](#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77)`(const `[`InputSegment`](#classInputSegment)` * s)` {#group__segment_1ga85de404c4ddf91a51bf0c29c6dbe1d77}

same as previous but uses _seg_first instead of argument b.

#### `public size_t `[`rewind`](#group__segment_1gafad6a7eea9e5892cfae9986f6263a738)`(const `[`InputSegment`](#classInputSegment)` * s,size_t b)` {#group__segment_1gafad6a7eea9e5892cfae9986f6263a738}

compute only the value of the next point (the first element of input segment after the right bound of this interval) starting from index b of input segment point.

#### Parameters
* `b` same preconditions on b as for align.

#### `public size_t `[`rewind`](#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16)`(const `[`InputSegment`](#classInputSegment)` *)` {#group__segment_1ga1a6a8f006c2d11e8f4af7250a6fb0b16}

same as previous but uses _seg_first instead of arg. b.

#### `public bool `[`aligned`](#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175)`() const` {#group__segment_1gaeb6593290d19ff04137c3f3c3e9e3175}

this interval has been aligned.

#### `protected  `[`AlignedInterval`](#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,bool f_align)` {#group__segment_1ga4aa5548293e2dcd94ab3845d9a8fe492}

aligned interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

#### Parameters
* `first` must be the first element of input segment after the beginning of this interval.

* `f_align` flag says wether alignement must be computed for the interval.

# class `Environment` {#classEnvironment}

wrapper abstract class embedding a standard input environment for parsing algos.

it encapsulates some input data and structures for memory management.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`InputSegment`](#classInputSegment)` * `[`segment`](#classEnvironment_1a740b0264644db40cb5a657f7ed52bb23) | input points to quantize.
`public `[`IntervalHeap`](#classIntervalHeap)` * `[`iheap`](#classEnvironment_1a810e4b1bd5bd6428c78c18fbeba127f6) | table of aligned input interval recorded.
`public  `[`Environment`](#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf)`(`[`InputSegment`](#classInputSegment)` * s)` | #### Parameters
`public  `[`~Environment`](#group__segment_1ga8e294735187880dd3d59be10c425b29d)`()` | 

## Members

#### `public `[`InputSegment`](#classInputSegment)` * `[`segment`](#classEnvironment_1a740b0264644db40cb5a657f7ed52bb23) {#classEnvironment_1a740b0264644db40cb5a657f7ed52bb23}

input points to quantize.

NULL when not given

#### `public `[`IntervalHeap`](#classIntervalHeap)` * `[`iheap`](#classEnvironment_1a810e4b1bd5bd6428c78c18fbeba127f6) {#classEnvironment_1a810e4b1bd5bd6428c78c18fbeba127f6}

table of aligned input interval recorded.

NULL when not needed (if there are no input points to process).

#### `public  `[`Environment`](#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf)`(`[`InputSegment`](#classInputSegment)` * s)` {#group__segment_1ga35cbd86caf5c17f8d59559ae0b28febf}

#### Parameters
* `s` input segment can be :

* NULL : e.g. for simple enumeration of the given wta

* non-NULL: e.g. for quantization of the points of given input segment using a given wta

#### `public  `[`~Environment`](#group__segment_1ga8e294735187880dd3d59be10c425b29d)`()` {#group__segment_1ga8e294735187880dd3d59be10c425b29d}

# class `InputSegment` {#classInputSegment}

intermediate representation for input performance data.

an input segment is made of:

* a time interval containing some timed events (muspoints), always sorted by increasing realtime date (vector of events).

* a heap of floating points.

The links in points are indexes in the input segment, where an index is a unique identifier of a point in either of the two above structures.

The realtime duration of a linked point is the difference of realtime dates (between the link and the point). the realtime duration of a point without link (with unknown link) is zero.

TODO do the same think with musical time duration.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InputSegment`](#group__segment_1gaec471ec05052a932b1bb2738bfc8b172)`(double b,double e)` | constructs an empty input segment (no events)
`public  `[`InputSegment`](#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492)`(const `[`InputSegment`](#classInputSegment)` &)` | 
`public  `[`InputSegment`](#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef)`(const `[`InputSegment`](#classInputSegment)` & s,double b,double e)` | copy and resize.
`public virtual  `[`~InputSegment`](#group__segment_1gab8da320feb29d4b009d2e6a37924337e)`()` | 
`public inline double `[`rbegin`](#classInputSegment_1a78b3f9b3b422ee5f92ba14056a76ccff)`() const` | real-time start date (in seconds) of segment.
`public inline double `[`rend`](#classInputSegment_1ad81105da6beb534a48a59d9219476732)`() const` | real-time end date (in seconds) of segment.
`public inline double `[`rduration`](#classInputSegment_1a590310d241cec28ac9b03b6a6708489b)`() const` | real-time total duration (in seconds) of segment.
`public inline `[`Rational`](#classRational)` `[`mduration`](#classInputSegment_1aa5410aeef3d5c6a263424b252eb78511)`() const` | musical total duration (in bars) of segment.
`public size_t `[`size`](#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63)`() const` | number of non-floating points in segment.
`public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`begin`](#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d)`()` | iterators to the segment's contents.
`public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`end`](#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e)`()` | 
`public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cbegin`](#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90)`() const` | 
`public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cend`](#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b)`() const` | 
`public const `[`MusPoint`](#classMusPoint)` & `[`point`](#group__segment_1ga5463f900db31be4b7d109e88a710971f)`(long i) const` | return a ref to the point of index i.
`public `[`MusEvent`](#classMusEvent)` * `[`event`](#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca)`(long i) const` | return the event of the point of index i.
`public double `[`rdate`](#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a)`(long i) const` | return the real-time date (in seconds) of the point of index i
`public double `[`rduration`](#group__segment_1gafbf05e143d416de49180d2f18a53977b)`(long i) const` | return the real-time duration (in seconds) of the point of index i.
`public double `[`rduration`](#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf)`(const `[`MusPoint`](#classMusPoint)` & p) const` | return the real-time duration (in seconds) of the given point.
`public `[`Rational`](#classRational)` & `[`mdate`](#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50)`(long i)` | return a reference to the musical-time date (in fraction of bar) of the point of index i.
`public `[`Rational`](#classRational)` & `[`mduration`](#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342)`(long i)` | return a reference to the musical-time duration (in fraction of bar) of the point of index i.
`public long `[`add_back`](#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` | insert new timestamped muspoint created from the parameters, at the end of the segment.
`public long `[`add_back`](#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4)`(const `[`MusPoint`](#classMusPoint)` &)` | 
`public long `[`add_floating`](#group__segment_1gad44eb7379e181fc4295ee2514a568204)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` | create new timestamped muspoint from the parameters, and add the the heap of floating points (not in segment).
`public long `[`add_floating`](#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a)`(const `[`MusPoint`](#classMusPoint)` &)` | 
`public void `[`close`](#group__segment_1gae75db088893a7cfc719ec393e09d7ece)`(double e)` | set end date.
`public inline bool `[`quantized`](#classInputSegment_1a2aa5d8948f3ac162a770bc84bb23ca2f)`() const` | quantization has been applied at least once.
`public template<>`  <br/>`void `[`quantize`](#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e)`(`[`Atable`](#classAtable)`< P > * table,const P & p)` | set the musical time date and duration of events in this given input segment, according to the best run for p in given table.
`public template<>`  <br/>`size_t `[`quantizu`](#group__segment_1gab4c42d088ce3d170b7899712789ab464)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)` | set the musical time date and duration of events in this given input segment, according to the best run for p in given table, starting from point number b in interval.
`public void `[`respell`](#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c)`(int k)` | pitch spelling. unwindowed.
`public void `[`respell`](#group__segment_1gac79787254008e05d9f54226d93dcb0cb)`(`[`Rational`](#classRational)` ws,int k)` | pitch spelling with a sliding window of given musical duration.
`public inline virtual bool `[`hasType`](#classInputSegment_1a3989ef5c44913cb1896920916cdcfcf8)`(std::string code) const` | return wether the segment has the type of the code.
`public void `[`print`](#group__segment_1ga623c2367191018ecac046e7e11f14976)`(std::ostream &) const` | print size to output stream.
`protected double `[`_begin`](api-segment.md#classInputSegment_1ae5267be6a3c036290ee028d032b4c4fc) | start date (in seconds) of segment.
`protected double `[`_end`](api-segment.md#classInputSegment_1a1c6cb6bc0004bc8fa2a1e4667f861f3e) | start date (in seconds) of segment.
`protected double `[`_len`](api-segment.md#classInputSegment_1addcc23fc9ea6a3cb342fd2960b5fbc78) | length (in seconds) of segment.
`protected `[`Rational`](#classRational)` `[`_mduration`](#classInputSegment_1a0ab26fdbc02f67159a8f619254fa7440) | length (in bars) of segment.
`protected std::vector< `[`MusPoint`](#classMusPoint)` > `[`_events`](#classInputSegment_1ac4494ab7de01a9b0f60cdcede78ac847) | event list.
`protected std::vector< `[`MusPoint`](#classMusPoint)` > `[`_heap`](#classInputSegment_1a8f5be09886f96f15d6c82a2828bef194) | floating events.
`protected `[`MusPoint`](#classMusPoint)` & `[`ncpoint`](#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd)`(long i)` | same as point but not const.
`protected bool `[`check_index`](#group__segment_1ga82a64bae54200b634bc42ac06dc7a916)`(long i) const` | 
`protected void `[`link`](#group__segment_1ga43310a16681e2241b20da4b68de9f35b)`(long i,long j)` | the event of index i is linked to the event of index j.

## Members

#### `public  `[`InputSegment`](#group__segment_1gaec471ec05052a932b1bb2738bfc8b172)`(double b,double e)` {#group__segment_1gaec471ec05052a932b1bb2738bfc8b172}

constructs an empty input segment (no events)

#### Parameters
* `b` start date (in seconds) 

* `e` end date (in seconds)

#### `public  `[`InputSegment`](#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492)`(const `[`InputSegment`](#classInputSegment)` &)` {#group__segment_1ga0ca7fa41c0dadabbaa112fdde9e48492}

#### `public  `[`InputSegment`](#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef)`(const `[`InputSegment`](#classInputSegment)` & s,double b,double e)` {#group__segment_1ga58d6af0b8186068f4bc26f58e6e62eef}

copy and resize.

#### Parameters
* `s` input segment to copy. 

* `b` new start date (in seconds) 

* `e` new end date (in seconds) 

copy only the events inside the new bounds.

#### `public virtual  `[`~InputSegment`](#group__segment_1gab8da320feb29d4b009d2e6a37924337e)`()` {#group__segment_1gab8da320feb29d4b009d2e6a37924337e}

#### `public inline double `[`rbegin`](#classInputSegment_1a78b3f9b3b422ee5f92ba14056a76ccff)`() const` {#classInputSegment_1a78b3f9b3b422ee5f92ba14056a76ccff}

real-time start date (in seconds) of segment.

#### `public inline double `[`rend`](#classInputSegment_1ad81105da6beb534a48a59d9219476732)`() const` {#classInputSegment_1ad81105da6beb534a48a59d9219476732}

real-time end date (in seconds) of segment.

#### `public inline double `[`rduration`](#classInputSegment_1a590310d241cec28ac9b03b6a6708489b)`() const` {#classInputSegment_1a590310d241cec28ac9b03b6a6708489b}

real-time total duration (in seconds) of segment.

#### `public inline `[`Rational`](#classRational)` `[`mduration`](#classInputSegment_1aa5410aeef3d5c6a263424b252eb78511)`() const` {#classInputSegment_1aa5410aeef3d5c6a263424b252eb78511}

musical total duration (in bars) of segment.

will return MUSTIME_UNKNOWN if segment was not quantized.

#### `public size_t `[`size`](#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63)`() const` {#group__segment_1ga05fee2bd8565c3076a6d800e37d7ab63}

number of non-floating points in segment.

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`begin`](#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d)`()` {#group__segment_1gaccf3b9127fc3d068a95af19f46d9052d}

iterators to the segment's contents.

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::iterator `[`end`](#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e)`()` {#group__segment_1ga1cc736fda27974f59c2e2dfc44eedf9e}

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cbegin`](#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90)`() const` {#group__segment_1gaff8f8c77de90a74f028f2e7a6ea32f90}

#### `public std::vector< `[`MusPoint`](#classMusPoint)` >::const_iterator `[`cend`](#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b)`() const` {#group__segment_1ga9eae7fefbf0884764ff6a75fc5fa063b}

#### `public const `[`MusPoint`](#classMusPoint)` & `[`point`](#group__segment_1ga5463f900db31be4b7d109e88a710971f)`(long i) const` {#group__segment_1ga5463f900db31be4b7d109e88a710971f}

return a ref to the point of index i.

* ith point in this input segment if 0 <= i < input segment size

* or the -i-1th floating point if heap size <= i < 0. 
#### Parameters
* `i` must be in the above range of values.

#### `public `[`MusEvent`](#classMusEvent)` * `[`event`](#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca)`(long i) const` {#group__segment_1gafaa215f8df4e03b3e22c4c5eb3e494ca}

return the event of the point of index i.

#### `public double `[`rdate`](#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a)`(long i) const` {#group__segment_1ga7c26187b3e70ea62bd10b9b15284a99a}

return the real-time date (in seconds) of the point of index i

#### `public double `[`rduration`](#group__segment_1gafbf05e143d416de49180d2f18a53977b)`(long i) const` {#group__segment_1gafbf05e143d416de49180d2f18a53977b}

return the real-time duration (in seconds) of the point of index i.

#### `public double `[`rduration`](#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf)`(const `[`MusPoint`](#classMusPoint)` & p) const` {#group__segment_1ga5ce66f635c2ab912e0ec9662c5c2ceaf}

return the real-time duration (in seconds) of the given point.

#### `public `[`Rational`](#classRational)` & `[`mdate`](#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50)`(long i)` {#group__segment_1ga6fce03f54fe517cc9541ea446cd26a50}

return a reference to the musical-time date (in fraction of bar) of the point of index i.

#### `public `[`Rational`](#classRational)` & `[`mduration`](#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342)`(long i)` {#group__segment_1ga2c16ef8a681bf9fded1dba29c1a84342}

return a reference to the musical-time duration (in fraction of bar) of the point of index i.

#### `public long `[`add_back`](#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1gabb6224ab371e84d2048f3c9e2692d15d}

insert new timestamped muspoint created from the parameters, at the end of the segment.

The realtime dateof the point must be after the current last point of this segment. 

#### Returns
the index of the inserted point (can be used as link).

#### `public long `[`add_back`](#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga2c58dc6e5e032dc7fee299be296371e4}

#### `public long `[`add_floating`](#group__segment_1gad44eb7379e181fc4295ee2514a568204)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1gad44eb7379e181fc4295ee2514a568204}

create new timestamped muspoint from the parameters, and add the the heap of floating points (not in segment).

(allocated and freed by this segment) 
#### Returns
the index of the new point (can be used as link).

#### `public long `[`add_floating`](#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1gabb9443e79fcefd19a5c7b65c4e54102a}

#### `public void `[`close`](#group__segment_1gae75db088893a7cfc719ec393e09d7ece)`(double e)` {#group__segment_1gae75db088893a7cfc719ec393e09d7ece}

set end date.

#### `public inline bool `[`quantized`](#classInputSegment_1a2aa5d8948f3ac162a770bc84bb23ca2f)`() const` {#classInputSegment_1a2aa5d8948f3ac162a770bc84bb23ca2f}

quantization has been applied at least once.

#### `public template<>`  <br/>`void `[`quantize`](#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e)`(`[`Atable`](#classAtable)`< P > * table,const P & p)` {#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e}

set the musical time date and duration of events in this given input segment, according to the best run for p in given table.

ptr type P must have interval. 

all the musical dates and durations of events in this segment will be changed.

#### `public template<>`  <br/>`size_t `[`quantizu`](#group__segment_1gab4c42d088ce3d170b7899712789ab464)`(`[`Atable`](#classAtable)`< P > * table,const P & p,size_t b)` {#group__segment_1gab4c42d088ce3d170b7899712789ab464}

set the musical time date and duration of events in this given input segment, according to the best run for p in given table, starting from point number b in interval.

#### Returns
the next point of input segment with musical date and duration yet unset after processing p. 

ptr type P must have interval. 

all the musical date of events must be unknown in seg. 

all the musical durations of events must be unknown in seg.

TBR (replaced by quantize)

#### `public void `[`respell`](#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c)`(int k)` {#group__segment_1ga2d78677ab3ea44ae91034c4e312e778c}

pitch spelling. unwindowed.

this segment must have been quantized.

#### `public void `[`respell`](#group__segment_1gac79787254008e05d9f54226d93dcb0cb)`(`[`Rational`](#classRational)` ws,int k)` {#group__segment_1gac79787254008e05d9f54226d93dcb0cb}

pitch spelling with a sliding window of given musical duration.

this segment must have been quantized.

#### `public inline virtual bool `[`hasType`](#classInputSegment_1a3989ef5c44913cb1896920916cdcfcf8)`(std::string code) const` {#classInputSegment_1a3989ef5c44913cb1896920916cdcfcf8}

return wether the segment has the type of the code.

type [InputSegment](#classInputSegment): plain [InputSegment](#classInputSegment) imported from MIDI file (or text) without filters.

#### `public void `[`print`](#group__segment_1ga623c2367191018ecac046e7e11f14976)`(std::ostream &) const` {#group__segment_1ga623c2367191018ecac046e7e11f14976}

print size to output stream.

#### `protected double `[`_begin`](api-segment.md#classInputSegment_1ae5267be6a3c036290ee028d032b4c4fc) {#classInputSegment_1ae5267be6a3c036290ee028d032b4c4fc}

start date (in seconds) of segment.

#### `protected double `[`_end`](api-segment.md#classInputSegment_1a1c6cb6bc0004bc8fa2a1e4667f861f3e) {#classInputSegment_1a1c6cb6bc0004bc8fa2a1e4667f861f3e}

start date (in seconds) of segment.

#### `protected double `[`_len`](api-segment.md#classInputSegment_1addcc23fc9ea6a3cb342fd2960b5fbc78) {#classInputSegment_1addcc23fc9ea6a3cb342fd2960b5fbc78}

length (in seconds) of segment.

#### `protected `[`Rational`](#classRational)` `[`_mduration`](#classInputSegment_1a0ab26fdbc02f67159a8f619254fa7440) {#classInputSegment_1a0ab26fdbc02f67159a8f619254fa7440}

length (in bars) of segment.

is set at quantization

#### `protected std::vector< `[`MusPoint`](#classMusPoint)` > `[`_events`](#classInputSegment_1ac4494ab7de01a9b0f60cdcede78ac847) {#classInputSegment_1ac4494ab7de01a9b0f60cdcede78ac847}

event list.

polymorphic (mono or poly)

#### `protected std::vector< `[`MusPoint`](#classMusPoint)` > `[`_heap`](#classInputSegment_1a8f5be09886f96f15d6c82a2828bef194) {#classInputSegment_1a8f5be09886f96f15d6c82a2828bef194}

floating events.

not in the list but can be linked by events on the list

#### `protected `[`MusPoint`](#classMusPoint)` & `[`ncpoint`](#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd)`(long i)` {#group__segment_1ga2dbfcbf9664a10c1245e298b9257d5cd}

same as point but not const.

#### `protected bool `[`check_index`](#group__segment_1ga82a64bae54200b634bc42ac06dc7a916)`(long i) const` {#group__segment_1ga82a64bae54200b634bc42ac06dc7a916}

#### `protected void `[`link`](#group__segment_1ga43310a16681e2241b20da4b68de9f35b)`(long i,long j)` {#group__segment_1ga43310a16681e2241b20da4b68de9f35b}

the event of index i is linked to the event of index j.

#### Parameters
* `j` must be a valid index, 

* `i` must be a valid and not NULL index, 

both i and j can be in heap (negative index). 

the point at i must not be linked (NULL link index). 

the realtime date of i must be <= realtime date of j (if not NULL).

# class `InputSegmentMono` {#classInputSegmentMono}

```
class InputSegmentMono
  : public InputSegment
```  

conversion of [InputSegment](#classInputSegment) to remove overlapping notes.

if NOTEON1 is linked to NOTEOFF1 and NOTEON2 occurs between NOTEON1 and NOTEOFF1 (including NOTEON1, excluding NOTEOFF1) then NOTEON1 is relinked to NOTEON2, and NOTEOFF1 is ignored if it is not linked.

In the case where NOTEON1 = NOTEON2, we move the NOTEOFF of the shortest note (in real duration). This note becomes a grace note (duration 0).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InputSegmentMono`](#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2)`(const `[`InputSegment`](#classInputSegment)` & s)` | transform the given input segment into a monophonic input segment (no two notes in the same time).

## Members

#### `public  `[`InputSegmentMono`](#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2)`(const `[`InputSegment`](#classInputSegment)` & s)` {#group__segment_1gad033d12a18d0f8cd7a8b0a2f5f029db2}

transform the given input segment into a monophonic input segment (no two notes in the same time).

by moving note-off events

# class `InputSegmentNogap` {#classInputSegmentNogap}

```
class InputSegmentNogap
  : public InputSegment
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InputSegmentNogap`](#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548)`(const `[`InputSegment`](#classInputSegment)` & s,bool norest)` | transform the given input segment into a new input segment without gaps.

## Members

#### `public  `[`InputSegmentNogap`](#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548)`(const `[`InputSegment`](#classInputSegment)` & s,bool norest)` {#group__segment_1gaa05ab07eeaf10f35e57552ab045ac548}

transform the given input segment into a new input segment without gaps.

by prolongations of some notes (option norest = true) or insertion of rests events (option norest = false)

# class `Interval` {#classInterval}

an [Interval](#classInterval) in an input segment with realtime bounds (seconds) and musical bounds (fraction of bars).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Rational`](#classRational)` `[`mbegin`](#classInterval_1a6c8385bc5875cb761827f9e75f783834) | musical-time start. starting date of interval, in musical-time (number of bars) relatively (shift) to current bar start.
`public `[`Rational`](#classRational)` `[`mend`](#classInterval_1a963b9b36f085a7db9c159c55608f8408) | musical-time end.
`public double `[`rbegin`](api-segment.md#classInterval_1aa17f339b42a23f6afc188971e7003d84) | real-time start.
`public double `[`rend`](api-segment.md#classInterval_1a1acb3128311a318b23e68cc8ca0182e9) | real-time end.
`public  `[`Interval`](#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` | top interval constructed from an input segment.
`public  `[`Interval`](#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5)`(const `[`Interval`](#classInterval)` &)` | copy.
`public  `[`Interval`](#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458)`(`[`Interval`](#classInterval)` *)` | used for copy of downcasted [IntervalTree](api-segment.md#classIntervalTree).
`public inline  `[`~Interval`](#classInterval_1a923e1717a3dedfe1ba90f81fcb26d5c5)`()` | do not deallocate the segment here.
`public virtual `[`Interval`](#classInterval)` & `[`operator=`](#group__segment_1ga6508f58e15c54be6146d5505d91a4b91)`(const `[`Interval`](#classInterval)` &)` | 
`public virtual bool `[`operator==`](#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6)`(const `[`Interval`](#classInterval)` &) const` | for using [Interval](api-segment.md#classInterval) as key in map.
`public inline `[`Rational`](#classRational)` `[`mduration`](#classInterval_1aaed8b0e404390af39c51e657636bf14d)`() const` | 
`public inline double `[`rduration`](#classInterval_1afbb05608fd0b263d905a29480e921b75)`() const` | 
`public bool `[`insideBar`](#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb)`() const` | 
`protected  `[`Interval`](#group__segment_1gaefc21b7c838661c05286304f6d891690)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend)` | build an interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

## Members

#### `public `[`Rational`](#classRational)` `[`mbegin`](#classInterval_1a6c8385bc5875cb761827f9e75f783834) {#classInterval_1a6c8385bc5875cb761827f9e75f783834}

musical-time start. starting date of interval, in musical-time (number of bars) relatively (shift) to current bar start.

#### `public `[`Rational`](#classRational)` `[`mend`](#classInterval_1a963b9b36f085a7db9c159c55608f8408) {#classInterval_1a963b9b36f085a7db9c159c55608f8408}

musical-time end.

ending date of interval, in musical-time (number of bars) relatively (shift) to current bar start.

0 for meta interval (in this case begin must be 0).

must be >= begin.

#### `public double `[`rbegin`](api-segment.md#classInterval_1aa17f339b42a23f6afc188971e7003d84) {#classInterval_1aa17f339b42a23f6afc188971e7003d84}

real-time start.

starting date of interval, in real-time (seconds) i.e. real-time date aligned with the musical date bars + begin

#### `public double `[`rend`](api-segment.md#classInterval_1a1acb3128311a318b23e68cc8ca0182e9) {#classInterval_1a1acb3128311a318b23e68cc8ca0182e9}

real-time end.

ending date of interval, in real-time (seconds) i.e. real date aligned with he musical date bars + end. must be > rbegin.

#### `public  `[`Interval`](#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` {#group__segment_1gadfaf31fca3f5e5da49e37c7baa275125}

top interval constructed from an input segment.

[Interval](#classInterval) covering the whole length of the given input segment s with given musical time length (number of bars)

#### `public  `[`Interval`](#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5)`(const `[`Interval`](#classInterval)` &)` {#group__segment_1ga17cfcca410ae94fe906dfcdb726026f5}

copy.

#### `public  `[`Interval`](#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458)`(`[`Interval`](#classInterval)` *)` {#group__segment_1ga43e7da7f24dfa17fccdd0dd40a96f458}

used for copy of downcasted [IntervalTree](#classIntervalTree).

#### `public inline  `[`~Interval`](#classInterval_1a923e1717a3dedfe1ba90f81fcb26d5c5)`()` {#classInterval_1a923e1717a3dedfe1ba90f81fcb26d5c5}

do not deallocate the segment here.

#### `public virtual `[`Interval`](#classInterval)` & `[`operator=`](#group__segment_1ga6508f58e15c54be6146d5505d91a4b91)`(const `[`Interval`](#classInterval)` &)` {#group__segment_1ga6508f58e15c54be6146d5505d91a4b91}

#### `public virtual bool `[`operator==`](#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6)`(const `[`Interval`](#classInterval)` &) const` {#group__segment_1ga4b0896bf3843fec18d68a130fe9a49f6}

for using [Interval](#classInterval) as key in map.

#### `public inline `[`Rational`](#classRational)` `[`mduration`](#classInterval_1aaed8b0e404390af39c51e657636bf14d)`() const` {#classInterval_1aaed8b0e404390af39c51e657636bf14d}

#### `public inline double `[`rduration`](#classInterval_1afbb05608fd0b263d905a29480e921b75)`() const` {#classInterval_1afbb05608fd0b263d905a29480e921b75}

#### `public bool `[`insideBar`](#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb)`() const` {#group__segment_1ga3af4cc83b5ee3d320fa5b24fa244fabb}

#### `protected  `[`Interval`](#group__segment_1gaefc21b7c838661c05286304f6d891690)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend)` {#group__segment_1gaefc21b7c838661c05286304f6d891690}

build an interval with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

not aligned.

# class `IntervalHeap` {#classIntervalHeap}

table for storage of aligned intervals to avoid recomputation of alignments.

the aligned interval are indexed (in table) as intervals (i.e. indexed with bound of real-time and musical-time interval bounds).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IntervalHeap`](#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51)`()` | 
`public  `[`~IntervalHeap`](#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8)`()` | 
`public bool `[`empty`](#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0)`() const` | 
`public size_t `[`size`](#group__segment_1ga87e6be639c7435053444d83913505c1b)`() const` | 
`public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,double rext)` | find or create (and push) a top interval of real-time duration covering the whole length of the given input segment s (root of interval tree) + the given extension.
`public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad886d53d2881a80f06c6f9fbf202d727)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` | get interval from heap, build it if not present.
`protected IntervalSet `[`_interval_heap`](api-segment.md#classIntervalHeap_1a56964ad9a5c60ad550282a6219326681) | table of nodes in interval tree.
`protected int `[`_added`](api-segment.md#classIntervalHeap_1a7347cb18816cc1fe1c53c3727416328d) | 
`protected int `[`_found`](api-segment.md#classIntervalHeap_1ad87165e87b2c1bd7150bc4f8159aef02) | 

## Members

#### `public  `[`IntervalHeap`](#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51)`()` {#group__segment_1ga4516d6ce78ba92f2e1728fdaa930ac51}

#### `public  `[`~IntervalHeap`](#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8)`()` {#group__segment_1gaf66f939648f0ea13c0eb3cee057269b8}

#### `public bool `[`empty`](#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0)`() const` {#group__segment_1ga4a873d9f7d804928f972a3c11d2a1df0}

#### `public size_t `[`size`](#group__segment_1ga87e6be639c7435053444d83913505c1b)`() const` {#group__segment_1ga87e6be639c7435053444d83913505c1b}

#### `public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend,double rext)` {#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019}

find or create (and push) a top interval of real-time duration covering the whole length of the given input segment s (root of interval tree) + the given extension.

* inside-bar interval (musical time duration of 1 bar) if flag bar is true

* multiple interval if flag bar is false (default).

not aligned.

#### `public `[`IntervalTree`](#classIntervalTree)` *const `[`make`](#group__segment_1gad886d53d2881a80f06c6f9fbf202d727)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` {#group__segment_1gad886d53d2881a80f06c6f9fbf202d727}

get interval from heap, build it if not present.

not aligned (when built).

#### `protected IntervalSet `[`_interval_heap`](api-segment.md#classIntervalHeap_1a56964ad9a5c60ad550282a6219326681) {#classIntervalHeap_1a56964ad9a5c60ad550282a6219326681}

table of nodes in interval tree.

#### `protected int `[`_added`](api-segment.md#classIntervalHeap_1a7347cb18816cc1fe1c53c3727416328d) {#classIntervalHeap_1a7347cb18816cc1fe1c53c3727416328d}

#### `protected int `[`_found`](api-segment.md#classIntervalHeap_1ad87165e87b2c1bd7150bc4f8159aef02) {#classIntervalHeap_1ad87165e87b2c1bd7150bc4f8159aef02}

# class `IntervalTree` {#classIntervalTree}

```
class IntervalTree
  : public AlignedInterval
```  

extension of Aligned [Interval](#classInterval) to define a tree of nested Alignements with sharing using hash table to store all alignment constructed.

to construct [IntervalTree](#classIntervalTree) use [IntervalHeap.make](#group__segment_1gad7fd7dd4ddb8d520df0985e67d180019) and the members top, split, split_back and sub.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`~IntervalTree`](#group__segment_1gae2c50e46e3997dd8631669046bf06c27)`()` | 
`public inline virtual `[`IntervalTree`](#classIntervalTree)` * `[`parent`](#classIntervalTree_1a68c95f629571e4d24caa9dfc669a4412)`()` | #### Returns
`public inline virtual `[`IntervalTree`](#classIntervalTree)` * `[`previous_sibling`](#classIntervalTree_1a0b640dcd2f3e26d31a1d4d7b3fd305ed)`()` | #### Returns
`public `[`IntervalTree`](#classIntervalTree)` * `[`top`](#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` * h,`[`Rational`](#classRational)` mend)` | top interval (root of interval tree) covering the whole length of the given input segment s.
`public `[`IntervalTree`](#classIntervalTree)` * `[`split`](#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` | return a sub interval.
`public `[`IntervalTree`](#classIntervalTree)` * `[`split_back`](#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` | return a sub interval.
`public `[`IntervalTree`](#classIntervalTree)` * `[`sub`](#group__segment_1gacb8de7e3756951950c391d241adec21c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,size_t a,size_t i)` | return a the i-1th sub-interval of the division of this interval in n equal parts. the sub-interval returned is aligned.
`protected `[`IntervalTree`](#classIntervalTree)` * `[`_parent`](#classIntervalTree_1a88e4c8c1ec09527a477646747e482fe4) | 
`protected `[`IntervalTree`](#classIntervalTree)` * `[`_previous_sibling`](#classIntervalTree_1a36b39cfc069e75085d3471b73e7c0d8d) | previous sibling [Interval](#classInterval) in the [Interval](#classInterval) tree.
`protected std::map< size_t, std::vector< `[`IntervalTree`](#classIntervalTree)` * > > `[`_children`](#classIntervalTree_1ab33b66f644ed154e05a69c13e979f1cd) | direct access to subtrees.
`protected  `[`IntervalTree`](#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` | top interval (root of interval tree).
`protected  `[`IntervalTree`](#group__segment_1gac16f2a8d9c584a869bbed6a263914360)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` | build an interval tree with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

## Members

#### `public  `[`~IntervalTree`](#group__segment_1gae2c50e46e3997dd8631669046bf06c27)`()` {#group__segment_1gae2c50e46e3997dd8631669046bf06c27}

#### `public inline virtual `[`IntervalTree`](#classIntervalTree)` * `[`parent`](#classIntervalTree_1a68c95f629571e4d24caa9dfc669a4412)`()` {#classIntervalTree_1a68c95f629571e4d24caa9dfc669a4412}

#### Returns
the embedding [Interval](#classInterval) in the [Interval](#classInterval) tree. 

#### Returns
NULL if this [Interval](#classInterval) is the root of the tree.

#### `public inline virtual `[`IntervalTree`](#classIntervalTree)` * `[`previous_sibling`](#classIntervalTree_1a0b640dcd2f3e26d31a1d4d7b3fd305ed)`()` {#classIntervalTree_1a0b640dcd2f3e26d31a1d4d7b3fd305ed}

#### Returns
the previous sibling [Interval](#classInterval) in the [Interval](#classInterval) tree. 

#### Returns
NULL if this [Interval](#classInterval) is the leftmost sibling.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`top`](#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` * h,`[`Rational`](#classRational)` mend)` {#group__segment_1ga0c04840a0d05d3b0d4b99e654d72b81b}

top interval (root of interval tree) covering the whole length of the given input segment s.

inside-bar interval of musical time duration of 1 bar if flag bar is true. multi-bar interval if flag bar is false.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`split`](#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` {#group__segment_1gae9e8f6ca3fa4093cfcd1428e9f41d048}

return a sub interval.

* if i = 1 first sub-interval starting at same point as this interval of realtime duration rdur of musical duration mdur bar. it not is aligned.

* if i = 2 second sub-interval (rest) starting at this interval realtime start + rdur and this interval musical time start + mdur of realtime duration this realtime duration - rdur. if the real starting date is out of this interval, then the real duration of the returned second sub-interval is zero. the musical starting date must be inside this interval. it is not aligned.

#### Parameters
* `rdur` must be strictly positive. 

* `mdur` must be strictly positive.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`split_back`](#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,double rdur,`[`Rational`](#classRational)` mdur,size_t i)` {#group__segment_1ga5b1393db865d0dd81249033dd99ecd5c}

return a sub interval.

* if i = 1 first sub-interval starts at same point as this interval of realtime duration : duration of this interval - rdur of musical duration : musical duration of this interval - mdur bars. if the starting date is out of the input segment, then the real duration of the returned first sub-interval is zero. it is not aligned.

* if i = 2 second sub-interval (rest) starts at this interval realtime end - rdur and this interval musical time end - mdur of realtime duration rdur. it is not aligned.

#### Parameters
* `rdur` must be strictly positive. 

* `mdur` must be strictly positive.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`sub`](#group__segment_1gacb8de7e3756951950c391d241adec21c)`(const `[`InputSegment`](#classInputSegment)` *,`[`IntervalHeap`](#classIntervalHeap)` *,size_t a,size_t i)` {#group__segment_1gacb8de7e3756951950c391d241adec21c}

return a the i-1th sub-interval of the division of this interval in n equal parts. the sub-interval returned is aligned.

#### Parameters
* `a` must be > 1 

* `i` must be smaller than a. 

this interval must be aligned.

#### `protected `[`IntervalTree`](#classIntervalTree)` * `[`_parent`](#classIntervalTree_1a88e4c8c1ec09527a477646747e482fe4) {#classIntervalTree_1a88e4c8c1ec09527a477646747e482fe4}

#### `protected `[`IntervalTree`](#classIntervalTree)` * `[`_previous_sibling`](#classIntervalTree_1a36b39cfc069e75085d3471b73e7c0d8d) {#classIntervalTree_1a36b39cfc069e75085d3471b73e7c0d8d}

previous sibling [Interval](#classInterval) in the [Interval](#classInterval) tree.

NULL if this [Interval](#classInterval) is the leftmost sibling

#### `protected std::map< size_t, std::vector< `[`IntervalTree`](#classIntervalTree)` * > > `[`_children`](#classIntervalTree_1ab33b66f644ed154e05a69c13e979f1cd) {#classIntervalTree_1ab33b66f644ed154e05a69c13e979f1cd}

direct access to subtrees.

every entry in this map associate to an arity a a partition t1,...,ta of the root interval.

#### `protected  `[`IntervalTree`](#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mend)` {#group__segment_1gab092e4338aa4c3369c4fa4404d8706b0}

top interval (root of interval tree).

covering the whole length of the given input segment s inside-bar interval of musical time duration of 1 bar if flag bar is true multi-bar interval if flag bar is false.

the interval tree created is not registered to an interval heap. 

not aligned.

#### `protected  `[`IntervalTree`](#group__segment_1gac16f2a8d9c584a869bbed6a263914360)`(const `[`InputSegment`](#classInputSegment)` * s,`[`Rational`](#classRational)` mbeg,`[`Rational`](#classRational)` mend,double rbeg,double rend,size_t first,`[`IntervalTree`](#classIntervalTree)` * p,`[`IntervalTree`](#classIntervalTree)` * ps)` {#group__segment_1gac16f2a8d9c584a869bbed6a263914360}

build an interval tree with musical-time bounds [mbegin, mbegin+mdur[ and real-time bounds [rbegin, rbegin+rdur[ for the input segment s.

#### Parameters
* `p` pointer to the parent. 

* `ps` pointer to the previous sibling. 

not aligned - must be aligned afterwards. 

use only internaly construction of recursive paths.

# class `MusEvent` {#classMusEvent}

input events

input interface to MIDI, OpenMusic, [MEI](#classMEI) etc keep track of input event list event are not stored internaly (in [WTA](#classWTA)). we just preserve the order. and remap afterwards to input event list (with dfs). abstract class to built polymorphic event lists (in input or output).

can be downcasted to descendant class with dynamic_cast for using particular operations

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`number`](api-segment.md#classMusEvent_1a8cbcc375091dd31d300993cb41e5c31f) | 
`public  `[`MusEvent`](#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17)`(int nb)` | 
`public  `[`MusEvent`](#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27)`(const `[`MusEvent`](#classMusEvent)` &)` | 
`public inline virtual  `[`~MusEvent`](#classMusEvent_1a9d195422a823d831bff7d47ed15584a7)`()` | 
`public `[`MusEvent`](#classMusEvent)` * `[`clone`](#classMusEvent_1a013a5d979aeac811d74929b41b188762)`() const` | 
`public bool `[`isRest`](#classMusEvent_1aa2d6c7ee99cdd95839aee1e5b5df2d92)`() const` | 
`public bool `[`isNote`](#classMusEvent_1abf3d0067b2b28275a26223083b745c7c)`() const` | 
`public void `[`print`](#classMusEvent_1a1a53c7e09246ad1441d26069ff4a9387)`(std::ostream & o) const` | 

## Members

#### `public int `[`number`](api-segment.md#classMusEvent_1a8cbcc375091dd31d300993cb41e5c31f) {#classMusEvent_1a8cbcc375091dd31d300993cb41e5c31f}

#### `public  `[`MusEvent`](#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17)`(int nb)` {#group__segment_1ga00b69e8f1bf80a478fce420d5d378c17}

#### `public  `[`MusEvent`](#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27)`(const `[`MusEvent`](#classMusEvent)` &)` {#group__segment_1ga40f47305a4bd7afbf26a4fbee663dd27}

#### `public inline virtual  `[`~MusEvent`](#classMusEvent_1a9d195422a823d831bff7d47ed15584a7)`()` {#classMusEvent_1a9d195422a823d831bff7d47ed15584a7}

#### `public `[`MusEvent`](#classMusEvent)` * `[`clone`](#classMusEvent_1a013a5d979aeac811d74929b41b188762)`() const` {#classMusEvent_1a013a5d979aeac811d74929b41b188762}

#### `public bool `[`isRest`](#classMusEvent_1aa2d6c7ee99cdd95839aee1e5b5df2d92)`() const` {#classMusEvent_1aa2d6c7ee99cdd95839aee1e5b5df2d92}

#### `public bool `[`isNote`](#classMusEvent_1abf3d0067b2b28275a26223083b745c7c)`() const` {#classMusEvent_1abf3d0067b2b28275a26223083b745c7c}

#### `public void `[`print`](#classMusEvent_1a1a53c7e09246ad1441d26069ff4a9387)`(std::ostream & o) const` {#classMusEvent_1a1a53c7e09246ad1441d26069ff4a9387}

# class `RestEvent` {#classRestEvent}

```
class RestEvent
  : public MusEvent
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`RestEvent`](#group__segment_1gaafcefa86601b97d137cfba40ed349414)`(int nb)` | 
`public  `[`RestEvent`](#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91)`(const `[`RestEvent`](#classRestEvent)` &)` | 
`public inline  `[`~RestEvent`](#classRestEvent_1ad70d3a221d0077108bc9320688e95dd0)`()` | 
`public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga6ebb6acd4c78929d31a4831c58911639)`() const` | 
`public inline virtual bool `[`isRest`](#classRestEvent_1a801a4ea729f7b83b38214f230a50ea6c)`() const` | 
`public inline virtual bool `[`isNote`](#classRestEvent_1a0f4dc932de332e0ae7014e4fade5e26c)`() const` | 
`public virtual void `[`print`](#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45)`(std::ostream & o) const` | 

## Members

#### `public  `[`RestEvent`](#group__segment_1gaafcefa86601b97d137cfba40ed349414)`(int nb)` {#group__segment_1gaafcefa86601b97d137cfba40ed349414}

#### `public  `[`RestEvent`](#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91)`(const `[`RestEvent`](#classRestEvent)` &)` {#group__segment_1gac4e65b67dedabe1736d414b8b4ab7e91}

#### `public inline  `[`~RestEvent`](#classRestEvent_1ad70d3a221d0077108bc9320688e95dd0)`()` {#classRestEvent_1ad70d3a221d0077108bc9320688e95dd0}

#### `public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga6ebb6acd4c78929d31a4831c58911639)`() const` {#group__segment_1ga6ebb6acd4c78929d31a4831c58911639}

#### `public inline virtual bool `[`isRest`](#classRestEvent_1a801a4ea729f7b83b38214f230a50ea6c)`() const` {#classRestEvent_1a801a4ea729f7b83b38214f230a50ea6c}

#### `public inline virtual bool `[`isNote`](#classRestEvent_1a0f4dc932de332e0ae7014e4fade5e26c)`() const` {#classRestEvent_1a0f4dc932de332e0ae7014e4fade5e26c}

#### `public virtual void `[`print`](#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45)`(std::ostream & o) const` {#group__segment_1ga0b9fce9fff8648eae4a51a77957fab45}

# class `NoteEvent` {#classNoteEvent}

```
class NoteEvent
  : public MusEvent
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NoteEvent`](#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be)`(unsigned int vel,int nb)` | unpitched note (drums).
`public  `[`NoteEvent`](#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7)`(`[`Pitch`](#classPitch)` p,unsigned int vel,int nb)` | pitched note.
`public  `[`NoteEvent`](#group__segment_1ga135e904aa3f5ea4d375e451281fe5323)`(unsigned int p,unsigned int vel,int nb)` | pitched note with MIDI pitch in 0..127.
`public  `[`NoteEvent`](#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc)`(const `[`NoteEvent`](#classNoteEvent)` &)` | 
`public inline  `[`~NoteEvent`](#classNoteEvent_1a9f5b32dbc2cd7819799bf9a9d88778a5)`()` | 
`public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049)`() const` | 
`public inline virtual bool `[`isRest`](#classNoteEvent_1afd1615e5f11074184f08946b14232c37)`() const` | 
`public inline virtual bool `[`isNote`](#classNoteEvent_1aaf40b5c82f0f6517b34ca3e0d89f585a)`() const` | 
`public inline bool `[`unpitched`](#classNoteEvent_1a5e8947bdb559558ed1313c02e0bbe834)`() const` | 
`public inline unsigned int `[`velocity`](#classNoteEvent_1a1129f35ed935be6cdc0ce4609677795d)`() const` | 
`public inline `[`Pitch`](#classPitch)` & `[`pitch`](#classNoteEvent_1aa4a9213eb0af96782b6b50de0ef101b0)`()` | can be modified.
`public virtual void `[`print`](#group__segment_1gafa25174e584b872e814643c895cad283)`(std::ostream & o) const` | 
`protected `[`Pitch`](#classPitch)` `[`_pitch`](#classNoteEvent_1a3a9e39f1c7b38802f52f64bc03a0ba60) | 
`protected unsigned int `[`_velocity`](api-segment.md#classNoteEvent_1afeec6adc37e86a01e903dfb6fd24d8e7) | MIDI velocity.

## Members

#### `public  `[`NoteEvent`](#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be)`(unsigned int vel,int nb)` {#group__segment_1gaeeb3a0d391bef4a285f1be45d31e63be}

unpitched note (drums).

#### `public  `[`NoteEvent`](#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7)`(`[`Pitch`](#classPitch)` p,unsigned int vel,int nb)` {#group__segment_1ga1bd25b8699a9ed866f11f62a844645f7}

pitched note.

#### `public  `[`NoteEvent`](#group__segment_1ga135e904aa3f5ea4d375e451281fe5323)`(unsigned int p,unsigned int vel,int nb)` {#group__segment_1ga135e904aa3f5ea4d375e451281fe5323}

pitched note with MIDI pitch in 0..127.

#### `public  `[`NoteEvent`](#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc)`(const `[`NoteEvent`](#classNoteEvent)` &)` {#group__segment_1ga9250db2a9fadb2184d60187e38ee02cc}

#### `public inline  `[`~NoteEvent`](#classNoteEvent_1a9f5b32dbc2cd7819799bf9a9d88778a5)`()` {#classNoteEvent_1a9f5b32dbc2cd7819799bf9a9d88778a5}

#### `public virtual `[`MusEvent`](#classMusEvent)` * `[`clone`](#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049)`() const` {#group__segment_1ga2fe5abb4cd9fbe000b1ec13114d60049}

#### `public inline virtual bool `[`isRest`](#classNoteEvent_1afd1615e5f11074184f08946b14232c37)`() const` {#classNoteEvent_1afd1615e5f11074184f08946b14232c37}

#### `public inline virtual bool `[`isNote`](#classNoteEvent_1aaf40b5c82f0f6517b34ca3e0d89f585a)`() const` {#classNoteEvent_1aaf40b5c82f0f6517b34ca3e0d89f585a}

#### `public inline bool `[`unpitched`](#classNoteEvent_1a5e8947bdb559558ed1313c02e0bbe834)`() const` {#classNoteEvent_1a5e8947bdb559558ed1313c02e0bbe834}

#### `public inline unsigned int `[`velocity`](#classNoteEvent_1a1129f35ed935be6cdc0ce4609677795d)`() const` {#classNoteEvent_1a1129f35ed935be6cdc0ce4609677795d}

#### `public inline `[`Pitch`](#classPitch)` & `[`pitch`](#classNoteEvent_1aa4a9213eb0af96782b6b50de0ef101b0)`()` {#classNoteEvent_1aa4a9213eb0af96782b6b50de0ef101b0}

can be modified.

#### `public virtual void `[`print`](#group__segment_1gafa25174e584b872e814643c895cad283)`(std::ostream & o) const` {#group__segment_1gafa25174e584b872e814643c895cad283}

#### `protected `[`Pitch`](#classPitch)` `[`_pitch`](#classNoteEvent_1a3a9e39f1c7b38802f52f64bc03a0ba60) {#classNoteEvent_1a3a9e39f1c7b38802f52f64bc03a0ba60}

#### `protected unsigned int `[`_velocity`](api-segment.md#classNoteEvent_1afeec6adc37e86a01e903dfb6fd24d8e7) {#classNoteEvent_1afeec6adc37e86a01e903dfb6fd24d8e7}

MIDI velocity.

# class `MusPoint` {#classMusPoint}

```
class MusPoint
  : public Point
```  

[Point](#classPoint) extended with mutable musical time date and duration (expressed in fraction of bars).

TODO redefine musical time duration as realtime duration, with links. TODO replace _mduration by mduration computed from linked point's date mduration is reset in [InputSegment.quantize()](#group__segment_1ga42c65e4989c84fbce42115d8e7813f8e)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`MusPoint`](#group__segment_1ga006e3062fd920202aab9e36f6a0e394e)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` | 
`public  `[`MusPoint`](#group__segment_1ga1bb17bef698401de18bc814c7f965999)`(const `[`Point`](#classPoint)` & p,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` | copy of point.
`public  `[`MusPoint`](#group__segment_1ga5f00500846d251b165f48a41552be18e)`(const `[`MusPoint`](#classMusPoint)` &)` | event (if any) is cloned.
`public  `[`~MusPoint`](#group__segment_1ga036951554acf624dd62469abbd8142df)`()` | 
`public `[`MusPoint`](#classMusPoint)` & `[`operator=`](#group__segment_1ga522126acc9eb79e737068941370bb172)`(const `[`MusPoint`](#classMusPoint)` &)` | event (if any) is cloned.
`public virtual bool `[`operator==`](#group__segment_1ga07139fb89dcc2388b299b9e6464b3177)`(const `[`Point`](#classPoint)` &) const` | 
`public inline `[`Rational`](#classRational)` & `[`mdate`](#classMusPoint_1a88d1f2efdc00dc80985bbe76356099b2)`()` | can be modified.
`public inline `[`Rational`](#classRational)` & `[`mduration`](#classMusPoint_1a2f89f6b4930b75e633d8b3cd3e461aa2)`()` | only for polyphonic events. 
`protected `[`Rational`](#classRational)` `[`_mdate`](#classMusPoint_1a5e678087e524bfa4e1d3612016196a9c) | timestamp in musical time (number of bars).
`protected `[`Rational`](#classRational)` `[`_mduration`](#classMusPoint_1a8d5382b9ab148a21ae7adc52b788b15f) | 
`protected virtual void `[`print`](#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830)`(std::ostream & o) const` | 

## Members

#### `public  `[`MusPoint`](#group__segment_1ga006e3062fd920202aab9e36f6a0e394e)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1ga006e3062fd920202aab9e36f6a0e394e}

#### `public  `[`MusPoint`](#group__segment_1ga1bb17bef698401de18bc814c7f965999)`(const `[`Point`](#classPoint)` & p,`[`Rational`](#classRational)` mdate,`[`Rational`](#classRational)` mduration)` {#group__segment_1ga1bb17bef698401de18bc814c7f965999}

copy of point.

extended with given onset and duration values (in fraction of bars)

#### `public  `[`MusPoint`](#group__segment_1ga5f00500846d251b165f48a41552be18e)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga5f00500846d251b165f48a41552be18e}

event (if any) is cloned.

#### `public  `[`~MusPoint`](#group__segment_1ga036951554acf624dd62469abbd8142df)`()` {#group__segment_1ga036951554acf624dd62469abbd8142df}

#### `public `[`MusPoint`](#classMusPoint)` & `[`operator=`](#group__segment_1ga522126acc9eb79e737068941370bb172)`(const `[`MusPoint`](#classMusPoint)` &)` {#group__segment_1ga522126acc9eb79e737068941370bb172}

event (if any) is cloned.

#### `public virtual bool `[`operator==`](#group__segment_1ga07139fb89dcc2388b299b9e6464b3177)`(const `[`Point`](#classPoint)` &) const` {#group__segment_1ga07139fb89dcc2388b299b9e6464b3177}

#### `public inline `[`Rational`](#classRational)` & `[`mdate`](#classMusPoint_1a88d1f2efdc00dc80985bbe76356099b2)`()` {#classMusPoint_1a88d1f2efdc00dc80985bbe76356099b2}

can be modified.

#### `public inline `[`Rational`](#classRational)` & `[`mduration`](#classMusPoint_1a2f89f6b4930b75e633d8b3cd3e461aa2)`()` {#classMusPoint_1a2f89f6b4930b75e633d8b3cd3e461aa2}

only for polyphonic events. 

can be modified.

#### `protected `[`Rational`](#classRational)` `[`_mdate`](#classMusPoint_1a5e678087e524bfa4e1d3612016196a9c) {#classMusPoint_1a5e678087e524bfa4e1d3612016196a9c}

timestamp in musical time (number of bars).

#### `protected `[`Rational`](#classRational)` `[`_mduration`](#classMusPoint_1a8d5382b9ab148a21ae7adc52b788b15f) {#classMusPoint_1a8d5382b9ab148a21ae7adc52b788b15f}

#### `protected virtual void `[`print`](#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830)`(std::ostream & o) const` {#group__segment_1gafef7a93b7ba8e96efc8d2b179c69a830}

# class `Pitch` {#classPitch}

internal representation of a pitch value.

can be unknown value TODO: extend conversions to MIDIcent (import OM)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public char `[`name`](api-segment.md#classPitch_1a7a7649ed78c05c1ff5f77c69155f1a71) | note name betwen 'A' and 'G'.
`public float `[`alteration`](api-segment.md#classPitch_1a6df5b9a06778d903d95924f122dc8783) | alteration in [-2, 2] where 1.0 is half tone.
`public int `[`octave`](api-segment.md#classPitch_1a3ed3edd50bc2bfa0e1d5c63df4dc6c7a) | octave in -10..10.
`public  `[`Pitch`](#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084)`()` | undef pitch value.
`public  `[`Pitch`](#group__segment_1gaf3f9d88915bb6688d522f09d7542f690)`(char name,float alt,int oct)` | construct pitch from name+alteration+octave.
`public  `[`Pitch`](#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b)`(unsigned int pitch,PitchUnit u)` | construct note from MIDI pitch
`public  `[`Pitch`](#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b)`(const `[`Pitch`](#classPitch)` &)` | 
`public inline  `[`~Pitch`](#classPitch_1a9a592ab90f8d3ab7a5edb5b3a2de2784)`()` | 
`public `[`Pitch`](#classPitch)` & `[`operator=`](#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91)`(const `[`Pitch`](#classPitch)` &)` | 
`public bool `[`operator==`](#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d)`(const `[`Pitch`](#classPitch)` &) const` | 
`public inline bool `[`undef`](#classPitch_1a3d0bc9b824e12c9036b238c52a1ce16f)`() const` | 
`public inline unsigned int `[`midicent`](#classPitch_1aa574b5a09e7eb950903e217ca843f5d3)`() const` | value in MIDIcent.
`public inline unsigned int `[`midi`](#classPitch_1adee54af3f8f7dccc618a5bd585b43dad)`() const` | value in MIDI.
`enum `[`PitchUnit`](api-segment.md#classPitch_1ae72a31f8d047b4b6fa468714f7588a4b) | 

## Members

#### `public char `[`name`](api-segment.md#classPitch_1a7a7649ed78c05c1ff5f77c69155f1a71) {#classPitch_1a7a7649ed78c05c1ff5f77c69155f1a71}

note name betwen 'A' and 'G'.

#### `public float `[`alteration`](api-segment.md#classPitch_1a6df5b9a06778d903d95924f122dc8783) {#classPitch_1a6df5b9a06778d903d95924f122dc8783}

alteration in [-2, 2] where 1.0 is half tone.

#### `public int `[`octave`](api-segment.md#classPitch_1a3ed3edd50bc2bfa0e1d5c63df4dc6c7a) {#classPitch_1a3ed3edd50bc2bfa0e1d5c63df4dc6c7a}

octave in -10..10.

#### `public  `[`Pitch`](#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084)`()` {#group__segment_1ga09a5f5040f1902afa6d81520cf7bd084}

undef pitch value.

#### `public  `[`Pitch`](#group__segment_1gaf3f9d88915bb6688d522f09d7542f690)`(char name,float alt,int oct)` {#group__segment_1gaf3f9d88915bb6688d522f09d7542f690}

construct pitch from name+alteration+octave.

#### Parameters
* `name` see table NAMES in [constant.h](#constant_8h_source)

* `alt` in [-2, 2] where 1.0 is half tone 

* `oct` in -10..10

#### `public  `[`Pitch`](#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b)`(unsigned int pitch,PitchUnit u)` {#group__segment_1gaace1762f4d975560a8d739d2d13fcd9b}

construct note from MIDI pitch

#### Parameters
* `pitch` in 0..127

#### `public  `[`Pitch`](#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b)`(const `[`Pitch`](#classPitch)` &)` {#group__segment_1gafb10e8f7a064ee15f75e4ba5609c682b}

#### `public inline  `[`~Pitch`](#classPitch_1a9a592ab90f8d3ab7a5edb5b3a2de2784)`()` {#classPitch_1a9a592ab90f8d3ab7a5edb5b3a2de2784}

#### `public `[`Pitch`](#classPitch)` & `[`operator=`](#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91)`(const `[`Pitch`](#classPitch)` &)` {#group__segment_1ga738dc72ab88cf6a09d89338e4f1d4b91}

#### `public bool `[`operator==`](#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d)`(const `[`Pitch`](#classPitch)` &) const` {#group__segment_1gab361cf1a2c8b9dca6e5abd8069e2d81d}

#### `public inline bool `[`undef`](#classPitch_1a3d0bc9b824e12c9036b238c52a1ce16f)`() const` {#classPitch_1a3d0bc9b824e12c9036b238c52a1ce16f}

#### `public inline unsigned int `[`midicent`](#classPitch_1aa574b5a09e7eb950903e217ca843f5d3)`() const` {#classPitch_1aa574b5a09e7eb950903e217ca843f5d3}

value in MIDIcent.

#### `public inline unsigned int `[`midi`](#classPitch_1adee54af3f8f7dccc618a5bd585b43dad)`() const` {#classPitch_1adee54af3f8f7dccc618a5bd585b43dad}

value in MIDI.

#### `enum `[`PitchUnit`](api-segment.md#classPitch_1ae72a31f8d047b4b6fa468714f7588a4b) {#classPitch_1ae72a31f8d047b4b6fa468714f7588a4b}

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
MIDI            | 
MIDICENT            | 

# class `Point` {#classPoint}

timestamped event.

event extended with realtime date (in seconds) and optional [on-off] link.

every point has a realtime date (in seconds).

a point can be linked to a forward point (with a realtime date larger or equal). the link is an index in an input segment.

a linked point is also called onset or note-on. an point without link (with link = MUSPOINTREF_NULL) is called offset or note-off.

for the computation of realtime duration of points, see [InputSegment](#classInputSegment).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public long `[`linked`](api-segment.md#classPoint_1a11ca880bad16051872c032fa47b73e42) | link to a point in an input segment marking the end date of this point.
`public  `[`Point`](#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link)` | timestamped monophonic or polyphonic event.
`public  `[`Point`](#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc)`(const `[`Point`](#classPoint)` &)` | event (if any) is cloned.
`public  `[`~Point`](#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1)`()` | event is deallocated and matcher (linked) also.
`public virtual `[`Point`](#classPoint)` & `[`operator=`](#group__segment_1ga55eeab949e62268da63176d48570eb54)`(const `[`Point`](#classPoint)` &)` | event (if any) is cloned.
`public virtual bool `[`operator==`](#group__segment_1ga1055933b999ef990df6b48745c27a197)`(const `[`Point`](#classPoint)` &) const` | 
`public inline `[`MusEvent`](#classMusEvent)` * `[`event`](#classPoint_1acf6506d97b9e96f177e1830a546e3ea3)`() const` | can be NULL.
`public inline double `[`rdate`](#classPoint_1ad2ff6ece321bae579ab2d4f52c71bb31)`() const` | 
`public inline double `[`rduration`](#classPoint_1a21ee97f153dd1c435f7d2e554887294f)`() const` | realtime duration of polyphonic events.
`public inline bool `[`noteon`](#classPoint_1a21d3017c2e04de4cc602306bafa40239)`() const` | is note on.
`public inline bool `[`noteoff`](#classPoint_1a951d10365297b7a1a2dd1bb51100e076)`() const` | is note off.
`protected `[`MusEvent`](#classMusEvent)` * `[`_event`](#classPoint_1abd14c2ceaca50fcb7c8236b8ce0d9aa6) | input event.
`protected double `[`_rdate`](api-segment.md#classPoint_1a650144f8bb470d6d4e364d7082d77f57) | timestamp in real-time (sec).
`protected double `[`_rduration`](api-segment.md#classPoint_1a706ce56822f7e26dc66d67ce225d8a94) | real duration computed using the matcher's rdate.
`protected bool `[`_onoff`](api-segment.md#classPoint_1a5508dcf134387f3f2271e95b578f3e3a) | true if note-on, false if note-off.
`protected virtual void `[`print`](#group__segment_1gaf6904981d6c631a7756499cd0b42ce29)`(std::ostream & o) const` | 

## Members

#### `public long `[`linked`](api-segment.md#classPoint_1a11ca880bad16051872c032fa47b73e42) {#classPoint_1a11ca880bad16051872c032fa47b73e42}

link to a point in an input segment marking the end date of this point.

the link is an index in an input segment structure:

* a point of segment if >= 0,

* or a floating point if < 0. if MUSPOINTREF_NULL, the duration of this point is zero.

#### `public  `[`Point`](#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d)`(`[`MusEvent`](#classMusEvent)` * e,double rdate,double rdur,bool on,long link)` {#group__segment_1ga6cb7f450eee39d3bd8483f017f28906d}

timestamped monophonic or polyphonic event.

#### `public  `[`Point`](#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc)`(const `[`Point`](#classPoint)` &)` {#group__segment_1ga5b7ec0fb127734c1cd5c6f350a3990fc}

event (if any) is cloned.

#### `public  `[`~Point`](#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1)`()` {#group__segment_1ga395fa04b4ec126b66fc053f829a30cc1}

event is deallocated and matcher (linked) also.

#### `public virtual `[`Point`](#classPoint)` & `[`operator=`](#group__segment_1ga55eeab949e62268da63176d48570eb54)`(const `[`Point`](#classPoint)` &)` {#group__segment_1ga55eeab949e62268da63176d48570eb54}

event (if any) is cloned.

#### `public virtual bool `[`operator==`](#group__segment_1ga1055933b999ef990df6b48745c27a197)`(const `[`Point`](#classPoint)` &) const` {#group__segment_1ga1055933b999ef990df6b48745c27a197}

#### `public inline `[`MusEvent`](#classMusEvent)` * `[`event`](#classPoint_1acf6506d97b9e96f177e1830a546e3ea3)`() const` {#classPoint_1acf6506d97b9e96f177e1830a546e3ea3}

can be NULL.

#### `public inline double `[`rdate`](#classPoint_1ad2ff6ece321bae579ab2d4f52c71bb31)`() const` {#classPoint_1ad2ff6ece321bae579ab2d4f52c71bb31}

#### `public inline double `[`rduration`](#classPoint_1a21ee97f153dd1c435f7d2e554887294f)`() const` {#classPoint_1a21ee97f153dd1c435f7d2e554887294f}

realtime duration of polyphonic events.

is computed in input segment

TBR (only for backward compability)

#### `public inline bool `[`noteon`](#classPoint_1a21d3017c2e04de4cc602306bafa40239)`() const` {#classPoint_1a21d3017c2e04de4cc602306bafa40239}

is note on.

#### `public inline bool `[`noteoff`](#classPoint_1a951d10365297b7a1a2dd1bb51100e076)`() const` {#classPoint_1a951d10365297b7a1a2dd1bb51100e076}

is note off.

#### `protected `[`MusEvent`](#classMusEvent)` * `[`_event`](#classPoint_1abd14c2ceaca50fcb7c8236b8ce0d9aa6) {#classPoint_1abd14c2ceaca50fcb7c8236b8ce0d9aa6}

input event.

#### `protected double `[`_rdate`](api-segment.md#classPoint_1a650144f8bb470d6d4e364d7082d77f57) {#classPoint_1a650144f8bb470d6d4e364d7082d77f57}

timestamp in real-time (sec).

#### `protected double `[`_rduration`](api-segment.md#classPoint_1a706ce56822f7e26dc66d67ce225d8a94) {#classPoint_1a706ce56822f7e26dc66d67ce225d8a94}

real duration computed using the matcher's rdate.

TBR (added for backward compatibility)

#### `protected bool `[`_onoff`](api-segment.md#classPoint_1a5508dcf134387f3f2271e95b578f3e3a) {#classPoint_1a5508dcf134387f3f2271e95b578f3e3a}

true if note-on, false if note-off.

TBR

#### `protected virtual void `[`print`](#group__segment_1gaf6904981d6c631a7756499cd0b42ce29)`(std::ostream & o) const` {#group__segment_1gaf6904981d6c631a7756499cd0b42ce29}

# struct `IntervalHasher` {#structIntervalHasher}

hash function for using interval as key in a unordered map.

musical time bounds are ignored here TBR

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structIntervalHasher_1a473d01d16bcc37b4744c1773cc85b3ac)`(const `[`Interval`](#classInterval)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structIntervalHasher_1a473d01d16bcc37b4744c1773cc85b3ac)`(const `[`Interval`](#classInterval)` & p) const` {#structIntervalHasher_1a473d01d16bcc37b4744c1773cc85b3ac}

# struct `PointedIntervalEq` {#structPointedIntervalEq}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline bool `[`operator()`](#structPointedIntervalEq_1a7b7a516ad7ac59f83c4d0cfea3848fd0)`(`[`IntervalTree`](#classIntervalTree)` const * lhs,`[`IntervalTree`](#classIntervalTree)` const * rhs) const` | 

## Members

#### `public inline bool `[`operator()`](#structPointedIntervalEq_1a7b7a516ad7ac59f83c4d0cfea3848fd0)`(`[`IntervalTree`](#classIntervalTree)` const * lhs,`[`IntervalTree`](#classIntervalTree)` const * rhs) const` {#structPointedIntervalEq_1a7b7a516ad7ac59f83c4d0cfea3848fd0}

# struct `PointedIntervalHash` {#structPointedIntervalHash}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structPointedIntervalHash_1a58a0ee22e288bea39121cb435c924740)`(const `[`IntervalTree`](#classIntervalTree)` * p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structPointedIntervalHash_1a58a0ee22e288bea39121cb435c924740)`(const `[`IntervalTree`](#classIntervalTree)` * p) const` {#structPointedIntervalHash_1a58a0ee22e288bea39121cb435c924740}

# struct `SpiralPoint` {#structSpiralPoint}

Elaine Chew's spiral of fifths.

for pitch spelling.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`x`](api-segment.md#structSpiralPoint_1a68150be95db2b13f25312129c7ef96a5) | 
`public double `[`y`](api-segment.md#structSpiralPoint_1aa969dcfbbeb0ce7b09d110ee93509da0) | 
`public double `[`z`](api-segment.md#structSpiralPoint_1a97da96a3080f8aaaab29f35da17af415) | 
`public  `[`SpiralPoint`](#group__segment_1ga80277d41d835c643826b4e813490849a)`(double,double,double)` | 
`public  `[`SpiralPoint`](#group__segment_1gae521f98807e13c4e0019b561565cda18)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` | 
`public `[`SpiralPoint`](#structSpiralPoint)` & `[`operator=`](#group__segment_1gab4085951f6e5264f912feadf327a8c81)`(const `[`SpiralPoint`](#structSpiralPoint)` &)` | 
`public bool `[`isnormal`](#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0)`() const` | #### Returns
`public void `[`operator+=`](#group__segment_1ga50ce60a751c8ad173a53ccee629a4598)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` | 
`public void `[`operator-=`](#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` | 
`public void `[`operator*=`](#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03)`(double a)` | 
`public double `[`distance`](#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs) const` | #### Returns

## Members

#### `public double `[`x`](api-segment.md#structSpiralPoint_1a68150be95db2b13f25312129c7ef96a5) {#structSpiralPoint_1a68150be95db2b13f25312129c7ef96a5}

#### `public double `[`y`](api-segment.md#structSpiralPoint_1aa969dcfbbeb0ce7b09d110ee93509da0) {#structSpiralPoint_1aa969dcfbbeb0ce7b09d110ee93509da0}

#### `public double `[`z`](api-segment.md#structSpiralPoint_1a97da96a3080f8aaaab29f35da17af415) {#structSpiralPoint_1a97da96a3080f8aaaab29f35da17af415}

#### `public  `[`SpiralPoint`](#group__segment_1ga80277d41d835c643826b4e813490849a)`(double,double,double)` {#group__segment_1ga80277d41d835c643826b4e813490849a}

#### `public  `[`SpiralPoint`](#group__segment_1gae521f98807e13c4e0019b561565cda18)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1gae521f98807e13c4e0019b561565cda18}

#### `public `[`SpiralPoint`](#structSpiralPoint)` & `[`operator=`](#group__segment_1gab4085951f6e5264f912feadf327a8c81)`(const `[`SpiralPoint`](#structSpiralPoint)` &)` {#group__segment_1gab4085951f6e5264f912feadf327a8c81}

#### `public bool `[`isnormal`](#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0)`() const` {#group__segment_1ga8d702bcd74b30d19929d1954087bd4b0}

#### Returns
wether coordinate are not NAN. */

#### `public void `[`operator+=`](#group__segment_1ga50ce60a751c8ad173a53ccee629a4598)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1ga50ce60a751c8ad173a53ccee629a4598}

#### `public void `[`operator-=`](#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs)` {#group__segment_1ga81b9a0d474b385cf0335523d49cc9fc1}

#### `public void `[`operator*=`](#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03)`(double a)` {#group__segment_1gaf7d46ab9c2b5dd8e11ec4a940dea3d03}

#### `public double `[`distance`](#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745)`(const `[`SpiralPoint`](#structSpiralPoint)` & rhs) const` {#group__segment_1ga71dccd6f3dd14b2c497e4198ea37d745}

#### Returns
Euclidian distance to given point.

# struct `NoteName` {#structNoteName}

```
struct NoteName
  : public SpiralPoint
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public char `[`name`](api-segment.md#structNoteName_1acd97c2eed21a588fb362e3838183c2d9) | note name. 'A' to 'G' or Pitch::UNDEF_NOTE_NAME
`public float `[`alteration`](api-segment.md#structNoteName_1a6b6ddfa2befdb91e8f2a283569efe579) | note alteration.
`public int `[`index`](api-segment.md#structNoteName_1adf37d714ab36d4769052e4145873fe29) | position in the line of fifths relative to C
`public inline  `[`NoteName`](#structNoteName_1afc3dde13d99d7e198c46a10198a5d78a)`()` | 
`public  `[`NoteName`](#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb)`(char n,float alt,int id)` | notename object from name, alteration and index.
`public  `[`NoteName`](#group__segment_1gaba2eabd0e4626b56685968ea53153b3b)`(const `[`NoteName`](#structNoteName)` & rhs)` | 
`public `[`NoteName`](#structNoteName)` & `[`operator=`](#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f)`(const `[`NoteName`](#structNoteName)` & rhs)` | 
`public inline bool `[`unknown`](#structNoteName_1a84a6beecda767f0481a0b4aa391c676c)`() const` | 

## Members

#### `public char `[`name`](api-segment.md#structNoteName_1acd97c2eed21a588fb362e3838183c2d9) {#structNoteName_1acd97c2eed21a588fb362e3838183c2d9}

note name. 'A' to 'G' or Pitch::UNDEF_NOTE_NAME

**See also**: same has in class [Pitch](#classPitch)

#### `public float `[`alteration`](api-segment.md#structNoteName_1a6b6ddfa2befdb91e8f2a283569efe579) {#structNoteName_1a6b6ddfa2befdb91e8f2a283569efe579}

note alteration.

in [-2.0, 2.0] where 1.0 is half tone or Pitch::UNDEF_NOTE_ALTERATION same has in class [Pitch](#classPitch).

#### `public int `[`index`](api-segment.md#structNoteName_1adf37d714ab36d4769052e4145873fe29) {#structNoteName_1adf37d714ab36d4769052e4145873fe29}

position in the line of fifths relative to C

* C has index 0 and index increases in the direction of sharps:

* G has index 1, D has index 2, F# has index 6...

* F has index -1, Bb has index -2...

values between -15 (Fbb) and 19 (B##)

TBC: it is redundant with name and alteration maybe should replace them?

#### `public inline  `[`NoteName`](#structNoteName_1afc3dde13d99d7e198c46a10198a5d78a)`()` {#structNoteName_1afc3dde13d99d7e198c46a10198a5d78a}

#### `public  `[`NoteName`](#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb)`(char n,float alt,int id)` {#group__segment_1gad81fd626f6b9bc6d70fd5e235ec5c8cb}

notename object from name, alteration and index.

#### Parameters
* `n` must be between 'A' and 'G' 

* `alt` must be between -2.0 and 2.0 

* `id` must be between -15 and 19

#### `public  `[`NoteName`](#group__segment_1gaba2eabd0e4626b56685968ea53153b3b)`(const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1gaba2eabd0e4626b56685968ea53153b3b}

#### `public `[`NoteName`](#structNoteName)` & `[`operator=`](#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f)`(const `[`NoteName`](#structNoteName)` & rhs)` {#group__segment_1ga22a391f4c1fa697f1d320d1a659f130f}

#### `public inline bool `[`unknown`](#structNoteName_1a84a6beecda767f0481a0b4aa391c676c)`() const` {#structNoteName_1a84a6beecda767f0481a0b4aa391c676c}

