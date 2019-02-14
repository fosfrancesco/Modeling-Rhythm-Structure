
set(general 
  general/Rational.cpp
  general/init.cpp
  general/trace.cpp
)


set(output 
  output/Onsets.cpp
  output/ValueList.cpp
  output/DurationList.cpp
  output/DurationTree.cpp
  output/Label.cpp
  output/SerialLabel.cpp
  output/RT.cpp
  output/PointedRT.cpp
  output/MEI.cpp
   output/LilyPond.cpp
  output/OMRT.cpp
  output/APTED.cpp
)

set(parsers 
  parsers/ParserInputless1best.cpp
  parsers/ParserInputlessKbest.cpp 
  parsers/Parser1bar1bestSIP.cpp          
  parsers/Parser1barKbestSKIP.cpp
  parsers/ParserMultibar1bestSIPBU.cpp
  parsers/ParserMultibar1bestSIPflat.cpp
)


set(schemata 
  schemata/State.cpp
  schemata/Transition.cpp
  schemata/WTA.cpp
  schemata/SubdivisionSchema.cpp
  schemata/CountingWTA.cpp
  schemata/ValueWTA.cpp
)


set(table 
  table/Ptr.cpp
  table/PtrS.cpp
  table/PtrSK.cpp
  table/PtrSI.cpp
  table/PtrSIP.cpp
  table/PtrSKIP.cpp
)

set(scoremodel  
  scoremodel/Duration.cpp
  scoremodel/Event.cpp
  scoremodel/Measure.cpp
  scoremodel/Note.cpp
  scoremodel/Rest.cpp
  scoremodel/Beam.cpp
  scoremodel/SpanningElement.cpp
  scoremodel/Tuplet.cpp
  scoremodel/Sequence.cpp
  scoremodel/Measure.cpp
  scoremodel/Part.cpp
  scoremodel/Voice.cpp
  scoremodel/Score.cpp
  scoremodel/ScoreMeter.cpp
)


set(segment
  segment/Pitch.cpp
  segment/Spiral.cpp
  segment/MusEvent.cpp    
  segment/Point.cpp
  segment/MusPoint.cpp
  segment/InputSegment.cpp   
  segment/Interval.cpp       
  segment/AlignedInterval.cpp
  segment/IntervalTree.cpp
  segment/IntervalHeap.cpp
  segment/Environment.cpp
)

set(weight 
  weight/Weight.cpp
  weight/FloatWeight.cpp
  weight/TropicalWeight.cpp
  weight/ViterbiWeight.cpp
  weight/CountingWeight.cpp
  weight/Distance.cpp
  weight/PerformanceModel.cpp
)

set(input 
  input/InputSegmentMIDI.cpp
  input/InputSegmentSerial.cpp    
  input/WTAFile.cpp
)


add_library(qparselib SHARED ${general} ${weight} ${table} ${parsers} ${input} ${schemata} ${output} ${scoremodel} ${segment})
target_link_libraries( qparselib midifile )