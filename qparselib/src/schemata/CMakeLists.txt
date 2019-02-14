## ComboWTA.cpp and PreWTA.cpp only needed for prototype parsers of target quant
## Schema.cpp for loading schema from file : mv to input?
## SubdivisionSchema.cpp and CountingWTA.cpp only for target schema
## ValueWTA.cpp only for target equiv

add_library(schemata STATIC
  State.cpp
  Transition.cpp
  WTA.cpp
  SubdivisionSchema.cpp
  CountingWTA.cpp
  ValueWTA.cpp
)
