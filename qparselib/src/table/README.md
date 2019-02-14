# src/table
A table stores the result of parsing wrt a given grammar.
It defines the associations to `keys` of `records`, where every `records` contains some `runs`, 
and can be requested for a k-best `run`.

`Keys` :  Several classes of `keys` are implemented (named `Ptr*`), made of different components, amongst:

 - state
 - rank (kth best number)
 - interval bounds and alignments
 - pre and post values.

A `key` can have unknown components, and in this case it is called partial. Partial `keys` can be completed symbolic constraint solving techniques (see below).

`Runs` : 
A `run` is either a tuple of `keys` (inner `run`) or a `label` (terminal = leaf `run`).
A `key` in a `run` defines a pointer to a sub-`run`: it is the  k-best `run` (according to the rank) for the `key` defined by other components of the pointer.
Therefore, one can reconstruct a tree given a `run` and a `table`,
and a `table` associates best trees (with `labels` in leaves) to `keys`.

An inner `run` is partial when some of its `key` is unknown or when its weight is not computed (from the weights of sub-`runs`). We complete a `run` by updating the `keys` and weight from left to right.

`Records` : 
A `record` stores (complete) `runs`. Bests `runs` can be accessed from a record.

`Table` : 
A `table` associates a `record` (hence best `runs`) to a (complete) `key`.
One can add a `run` to a `key` in a given `table`.
More precisely:

- one can add a complete `run` to a complete `key` : the `run` is then just added to the associated `record`.

- one can add a partial `run` to a `key`. In that case the `run` is completed first.

- one can add a complete `run` to a partial `key` : the `key` is then completed according to the values in the `run`. Some example can be found in notes.




