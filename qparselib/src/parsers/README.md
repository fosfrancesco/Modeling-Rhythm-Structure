# src/parsers
A `parser` class defines a running environement for transcription by parsing for  a given `input`. It assembles elements from the `table` directory for the construction of a table used to compute a tree from a `grammar` and some `input`.

Each `parser` class may contain a `demo` fonction to be called in a target.

The following `parsers` have been implemented:

- `Inputless1best` : compute the 1-best tree of a `WTA`. no input segment.

- `Inputlesskbest` : compute the k best trees of a `WTA`. no input segment.

- `1bar1bestSIP` : computing the 1-best tree in a given `WTA` language for the transcription of a given input segment.
If the WTA trees represent 1 bar, this scenario is transcription of
the whole segment as a single bar.

- `1barkbestSKIP` : computing the k best trees in a given `WTA` language for the transcription of a given input segment.

- `Multibar1bestSIPBU` : 1-best parsing with `SIP` pointers. Process input as multiple bars, where a sequence of bars is represented by a binary tree (meta-run), 
constructed in a bottom-up fashion:

```
                               [bars 1-n]
                                /     \
                    [bars 1-(n-1)]   bar m
                  ...
         [bars 1-2]   bar3
          /      \
     [bars 1]   bar2
     /    \
   [ ]   bar1
```

Every node corresponds to a SIP pointer.
The nodes `p1`, `p2` immediately below a node `p` represent a binary
run `(p1, p2)` in the table entry for `p`.
The pointers in `[ ]` correspond to several bars (meta pointers),
they do have a non-WTA state.
Every other pointer correspond to a single bar,
with the initial WTA state (and contain a best run for that bar).


It is assumed that the number of bars is known and the bar length is fixed (tempo does not vary from bar to bar).

This parser can be used for online (bar by bar) transcription.

- `Multibar1bestSIPflat` : same as above but the sequence of bars is represented by a tuple (flat tree), constructed from left to right.

```
       [bars 1-n]
        /      \
      bar1 ... bar m
```

Every node correspond to a SIP pointer.
The top note correspond to the whole segment (meta pointer for all bars)
Every node below correspond to a single bar,
with the initial WTA state (and contain a best run for that bar).
This parser cannot be used for online transcription.

This parser is very inefficient with constraint solving (in Table)
for pre, post values - need to store an exponential number of partial runs.
The BU version is more efficient - with more compact representation of partial runs.




