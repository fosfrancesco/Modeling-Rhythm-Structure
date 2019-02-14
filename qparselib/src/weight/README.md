# src/weight
Definition of several domains and operations for the weights of automata.
Each of them is defined as a semiring, with 

- a weight domain, 
- a binary operator `add` (associative, commutative), 
- a neutral element `zero` for `plus`, 
- a binary operator `mult` (associative),
- a neutral element `one` for mult,

such that `zero` is an absorbing element for `mult`
and `mult` distributes over `plus`.

- `Weight` is a structure of polymorphic weight.
i.e. a wrapper (envelop) containing a pointer to a `LetterWeight`.
A `Weight` with an empty pointer is called unknown.

- a `LetterWeight` is the definition of a semiring.
We have implemented the following  `LetterWeights`:

- `FloatWeight` : scalar weight values
	- domain : floating point numbers
	- operator `add` is +
	- `zero` is 0.0
	- operator `mult` is *
	- `one` is 1.0
- `TropicalWeight` : tropical algebra: scalar weight values are non-negative floating point numbers
	- domain : positive or null double + infinity
	- operator `add` is min
	- `zero` is infinity
	- operator `mult` is +
	- `one` is 0
- `ViterbiWeight` : scalar weight values are probabilities of the best derivations
	- domain : positive or null rational numbers in [0, 1]
	- operator `add` is max
	- `zero` is 0
	- operator `mult` is *
	- `one` is 1
- `Distance` : a particular case of `TropicalWeight` 
  which can be constructed from an interval of an input segment, 
  and corresponds to the distance of alignement of the points on the left and right bounds of the interval.
- `PerformanceModel` : a particular case of `ViterbiWeight` which can be constructed from an interval of an input segment, and defines  a probability of alignment of the points on the left and right bounds of the interval, following a Gaussian distribution.
- `CountingWeight` : a algebra of weight for counting the number of applications of automata transitions rules on a given corpus. Useful for computation of Viterbi Weight values from corpus.
	- domain : 
		- vectors of fixed dim k > 0 
		- + FAIL = stuck (0 run in state s for 1 tree)
		- + ERROR = ambiguity in grammar (2 runs for 1 tree)
	- operator `add` : for all x, y vectors dim k
		- x + y = ERROR
		- ERROR is absorbing for +
	- `zero` = FAIL
	- operator `mult` : for all x, y vectors dim k
		- x . y = component-wise sum
		- x . FAIL = FAIL . x = FAIL
		- FAIL . FAIL = FAIL
		- is ERROR absorbing for .
	- `one` = null vector of dim k
