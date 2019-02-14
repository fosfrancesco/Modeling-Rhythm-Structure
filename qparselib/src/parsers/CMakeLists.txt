## for quant target
## only one parser need to be compiled to build a quant target

add_library(parsers STATIC
  ParserInputless1best.cpp
  ParserInputlessKbest.cpp 
  Parser1bar1bestSIP.cpp          
  Parser1barKbestSKIP.cpp
  ParserMultibar1bestSIPBU.cpp
  ParserMultibar1bestSIPflat.cpp
)
