# sources of the qparse library
for rhythm quantization by k-best parsing algorithms based on  weighted tree automata.

The sources are organized into the following sub-directories.

- [targets](targets/README.md) : main functions for producing various command line utilities.
- [general](general/README.md) : initialization, tracing.
- [weight](weight/README.md) : several possible domains for weight values for tree automata.
- [schemata](schemata/README.md) : class of weighted tree automata used for parsing.
- [segment](segment/README.md) : classes for abstract representation of data in input processed by parsing.
- [table](table/README.md) : parse tables.
- [parsers](parsers/README.md) : various transcription scenarii, by parsing of a given `input`, assembling elements from the `table` directory.
- [input](input/README.md) : reading from and writing to files the data given in input to the quantization by parsing algorithm (schema and segment).
- [score model](scoremodel/README.md) : abstract model used to produce scores in various formats from parse trees.
- [output](output/README.md) : representation of the output of the parsing procedure and conversion into
music transcription results.





