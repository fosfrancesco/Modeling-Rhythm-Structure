# src/schemata
Classes related to rhythm `grammars` used in input for quantization by parsing.

A `grammar` (or weighted tree automaton, `WTA`) associates to every tree with `labeled` leaves a unique weight value, in one of the domain defined in directory `weight` (a unique `weight` domain is fixed for a `grammar`).

A `grammar` is defined by a list of `transition` rules, were each transition rule is defined by a target `state`, a body (sequence of states) and a `weight`.
An initial `state` is distinguished in every `grammar`.

For reading and saving a `grammar` from a text file, describing transition rules and options, see [src/input/README](../input/README.md).


