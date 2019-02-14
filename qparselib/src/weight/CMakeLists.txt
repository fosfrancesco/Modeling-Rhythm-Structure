## CountingWeight.cpp only for target schema

add_library(weight STATIC
  Weight.cpp
  FloatWeight.cpp
  TropicalWeight.cpp
  ViterbiWeight.cpp
  CountingWeight.cpp
  Distance.cpp
  PerformanceModel.cpp
)
