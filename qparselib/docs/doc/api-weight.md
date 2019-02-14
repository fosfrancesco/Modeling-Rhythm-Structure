# group `weight` {#group__weight}

The `weight` module contains the definitions of several domains for weight values for tree automata.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::ostream & `[`operator<<`](#group__weight_1gab340452fea725573e28644234d68147e)`(std::ostream & o,const `[`CountingWeight`](#classCountingWeight)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#group__weight_1ga28da9ceeeef71d7da863914db5247228)`(std::ostream & o,const `[`FloatWeight`](#classFloatWeight)` & rhs)`            | 
`public inline bool `[`operator==`](#group__weight_1ga985964770c3e3b3aea4ea1ebd817f1c8)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | **See also**: equal
`public inline bool `[`operator!=`](#group__weight_1ga3f8df07b63284c0a1d9da46b7d01588e)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | 
`public inline bool `[`operator<`](#group__weight_1gaf058ecdf4336e4dff64400d149c791f9)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | **See also**: smaller
`public inline bool `[`operator>`](#group__weight_1ga3eb9b7d865559995803e57f557f085b3)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | 
`public inline bool `[`operator<=`](#group__weight_1ga37b0ffb977541c9ff2ee7fdc3ec9fd0c)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | 
`public inline bool `[`operator>=`](#group__weight_1ga77d4e41a067e6104b5783f06a5018a1c)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)`            | 
`public inline std::ostream & `[`operator<<`](#group__weight_1ga5fa6fc187426e2cc6aa40f7acddf8455)`(std::ostream & o,const `[`Weight`](#classWeight)` & rhs)`            | **See also**: print
`protected  `[`CountingWeight`](#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa)`(CWType t,size_t dim)`            | must dim > 0
`public  `[`CountingWeight`](#group__weight_1ga1c356f04569b90215755f5d1289c78aa)`(const `[`CountingWeight`](#classCountingWeight)` &)`            | 
`public  `[`~CountingWeight`](#group__weight_1gaf006e414e6fee4c338bea085e0bceeba)`()`            | 
`public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gaa78f8a12ada406ba6a331acc42baa052)`(const `[`CountingWeight`](#classCountingWeight)` &)`            | 
`public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)`            | #### Parameters
`public virtual `[`CountingWeight`](#classCountingWeight)` * `[`clone`](#group__weight_1ga7e6061ad27a65ee071647866da6a971f)`() const`            | 
`public virtual `[`Weight`](#classWeight)` `[`make`](#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2)`(double v) const`            | #### Returns
`public static `[`Weight`](#classWeight)` `[`make_one`](#group__weight_1ga6963921223bbd482ce8454ffa6d6fda5)`(size_t)`            | 
`public static `[`Weight`](#classWeight)` `[`make_unit`](#group__weight_1ga12cda7b4188f3917d256808fd42c3364)`(size_t dim,size_t i)`            | #### Parameters
`public virtual `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb)`() const`            | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public virtual `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843)`() const`            | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public virtual bool `[`zero`](#group__weight_1ga62b599ef59770e981d17d565e6727ca9)`() const`            | this weight is zero (FAIL)
`public bool `[`error`](#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5)`() const`            | this weight is the error value
`public virtual bool `[`one`](#group__weight_1ga5189380be1ac03126180846e3a8fd1cb)`() const`            | this weight is one (null vector)
`public virtual double `[`norm`](#group__weight_1gabb8ca43a6821de970e8f6b23c848c804)`() const`            | do not use
`public virtual void `[`scalar`](#group__weight_1gabb65ce9f0f34112159f6689a36594470)`(double)`            | add to each component.
`protected virtual bool `[`equal`](#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`protected virtual bool `[`smaller`](#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`protected virtual void `[`add`](#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | * FAIL is neutral
`protected virtual void `[`mult`](#group__weight_1ga102af16b814daad826afb91d6f6c75b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | * VECTOR . VECTOR = VECTOR with component-wise sum
`protected virtual void `[`print`](#group__weight_1ga00d9ffa71ae947eb191e118570049b73)`(std::ostream &) const`            | 
`protected virtual void `[`rawprint`](#group__weight_1ga30707b9335976941e15aef45c4db86bf)`(std::ostream &) const`            | 
`public  `[`Distance`](#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p)`            | weight which is the distance defined by alignment for input segment not unknown.
`private double `[`distcoeff`](#group__weight_1ga076cdb529e76ef7cd5715c451f50c1df)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)`            | sum of the 2 above or 1 if sum is null.
`private double `[`dist_prev`](#group__weight_1gae22f0c2d151a20073571c25e47ca84a3)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)`            | distance to the closest point before j not at the same rdate as j.
`private double `[`dist_next`](#group__weight_1gaf87f2d4066d9a8403b7a149cc2dc9a20)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)`            | distance to the closest point after j not at the same rdate as j.
`public `[`Distance`](#classDistance)` & `[`operator=`](#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f)`(const `[`Distance`](#classDistance)` &)`            | 
`public virtual `[`Distance`](#classDistance)` * `[`clone`](#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610)`() const`            | 
`protected virtual void `[`print`](#group__weight_1gaf9785af97fcce45a15098363efe5b7c8)`(std::ostream &) const`            | 
`public  `[`FloatWeight`](#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8)`(double d)`            | defaut = null weight - not unknown
`public  `[`FloatWeight`](#group__weight_1gac7ac9026fecc24193526ef577d819a3b)`(const `[`FloatWeight`](#classFloatWeight)` &)`            | 
`public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52)`(const `[`FloatWeight`](#classFloatWeight)` &)`            | 
`public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1)`(const `[`LetterWeight`](#classLetterWeight)` &)`            | 
`public virtual `[`FloatWeight`](#classFloatWeight)` * `[`clone`](#group__weight_1ga3ee8633406a8dc51ba579254872b21e4)`() const`            | 
`public virtual void `[`scalar`](#group__weight_1ga8fe884fff3323382bfc7729500cca368)`(double)`            | 
`public virtual void `[`invert`](#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab)`()`            | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf)`() const`            | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1gac90a90f052aba6f1a03a5238bae96159)`() const`            | this letterweight is neutral element for mult.
`public bool `[`equal`](#group__weight_1ga11c58941eafe9e4f3a45558812786e36)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const`            | 
`protected virtual bool `[`equal`](#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`public bool `[`smaller`](#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const`            | 
`protected virtual bool `[`smaller`](#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`public void `[`add`](#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)`            | 
`protected virtual void `[`add`](#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | #### Parameters
`public void `[`mult`](#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)`            | 
`protected virtual void `[`mult`](#group__weight_1ga16591d6a01c98477ccd57deadf8d4738)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | #### Parameters
`protected virtual void `[`print`](#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f)`(std::ostream &) const`            | 
`public  `[`PerfoWeight`](#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)`            | probability of positions in the given alignement in the interval defined by the given path.
`public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41)`(const `[`PerfoWeight`](#classPerfoWeight)` &)`            | 
`public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)`            | #### Parameters
`public static void `[`set_sigma2`](#group__weight_1ga6761f06ee3b129a22fc0101f4947b4e9)`(double)`            | 
`private static double `[`trnorm`](#group__weight_1ga3661d1533628116f3581a8c0ac82c221)`(double x)`            | Gaussian pr. density distribution truncated to [a,b].
`public  `[`TropicalWeight`](#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa)`(const `[`TropicalWeight`](#classTropicalWeight)` &)`            | 
`public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1gaa275b4800bdc220d59ee42b2165f638a)`(const `[`TropicalWeight`](#classTropicalWeight)` &)`            | 
`public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246)`(const `[`LetterWeight`](#classLetterWeight)` &)`            | rvalue must be a [TropicalWeight](api-weight.md#classTropicalWeight)
`public virtual `[`TropicalWeight`](#classTropicalWeight)` * `[`clone`](#group__weight_1ga378883be65a16bb86f13b1a9d941f104)`() const`            | 
`public virtual double `[`norm`](#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941)`() const`            | must not be zero (infinity)
`public virtual void `[`scalar`](#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5)`(double)`            | 
`public virtual void `[`invert`](#group__weight_1ga2bad107be8a2e71fc12b75196adde070)`()`            | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36)`() const`            | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1gae362229d75df663272f4d52c15a04315)`() const`            | this letterweight is neutral element for mult.
`protected virtual bool `[`equal`](#group__weight_1ga7203d6028f02a2791bdeede99ef59b97)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`protected virtual bool `[`smaller`](#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | #### Parameters
`protected virtual void `[`add`](#group__weight_1ga41791f144fea9717092970563337d040)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | sum is min.
`protected virtual void `[`mult`](#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | product is sum.
`protected virtual void `[`print`](#group__weight_1gaa6f92a288b315fed3b301de728f2717d)`(std::ostream &) const`            | 
`public static `[`TropicalWeight`](#classTropicalWeight)` `[`inner`](#group__weight_1gace00a414884a9a4824c3cac4b8b084a9)`(size_t)`            | penalty for an inner node.
`public static `[`TropicalWeight`](#classTropicalWeight)` `[`tie`](#group__weight_1gad8d0422a24b5d4a76856191cc441396c)`()`            | penalty for a tie.
`public static `[`TropicalWeight`](#classTropicalWeight)` `[`gracenote`](#group__weight_1ga739a8c09964d0db9552f5924b494c89d)`(size_t)`            | penalty for given number of grace notes in a leaf.
`protected  `[`ViterbiWeight`](#group__weight_1gaf4e626612999673b8e4e0a322119402c)`(double)`            | default is one
`public  `[`ViterbiWeight`](#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)`            | 
`public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga388bdd81eafaa3cb729934f36f603f35)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)`            | 
`public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0)`(const `[`LetterWeight`](#classLetterWeight)` & rvalue)`            | #### Parameters
`public virtual `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef)`() const`            | 
`public virtual double `[`norm`](#group__weight_1ga01383c055ca0dafc28870ecd701dbd15)`() const`            | 
`public virtual void `[`scalar`](#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36)`(double)`            | 
`public virtual void `[`invert`](#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb)`()`            | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1ga35f29b2dcd594cc2cfac884322095c16)`() const`            | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde)`() const`            | this letterweight is neutral element for mult.
`protected virtual bool `[`equal`](#group__weight_1ga96f4c23e4845b232451e99b648bddfd6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | rhs must be a [ViterbiWeight](api-weight.md#classViterbiWeight).
`protected virtual bool `[`smaller`](#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const`            | rhs must be a [ViterbiWeight](api-weight.md#classViterbiWeight).
`protected virtual void `[`add`](#group__weight_1ga009b0216c58308f81497e4aabe49aaed)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | sum is min.
`protected virtual void `[`mult`](#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)`            | product is sum.
`protected virtual void `[`print`](#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51)`(std::ostream &) const`            | 
`protected virtual bool `[`equal`](#group__weight_1gaf00322921db3c5212f8d5ca63081d689)`(const `[`LetterWeight`](#classLetterWeight)` *) const`            | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual bool `[`smaller`](#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2)`(const `[`LetterWeight`](#classLetterWeight)` *) const`            | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual void `[`add`](#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8)`(const `[`LetterWeight`](#classLetterWeight)` *)`            | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual void `[`mult`](#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01)`(const `[`LetterWeight`](#classLetterWeight)` *)`            | binary operators are defined only between descendant LetterWeights of same typeid.
`public virtual bool `[`zero`](#group__weight_1gabaad113da06b47c4b291558d05da6aa6)`() const`            | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0)`() const`            | this letterweight is neutral element for mult.
`protected virtual void `[`print`](#group__weight_1gabef24fcc2eb0c72c420e83e6db625545)`(std::ostream & o) const`            | 
`public  `[`Weight`](#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c)`(const `[`Weight`](#classWeight)` & w)`            | clone the letter.
`public  `[`~Weight`](#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f)`()`            | 
`public `[`Weight`](#classWeight)` & `[`operator=`](#group__weight_1ga548aadee137a6c274aeb1e56607b05dd)`(const `[`Weight`](#classWeight)` &)`            | 
`public `[`Weight`](#classWeight)` * `[`clone`](#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed)`() const`            | 
`public `[`Weight`](#classWeight)` `[`make`](#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729)`(double v) const`            | **See also**: [LetterWeight.make](api-weight.md#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)
`public `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55)`() const`            | return the neutral element for add (absorbing element for mult) for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).
`public `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga48012227b61aa4c10064bed70936d78e)`() const`            | return the neutral element for mult for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).
`public bool `[`unknown`](#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47)`() const`            | unknown weight is a [Weight](api-weight.md#classWeight) with NULL letter.
`public bool `[`hasType`](#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35)`(std::string code) const`            | #### Parameters
`public double `[`norm`](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)`()`            | this [Weight](#classWeight) must not be unknown (letter != NULL) 
`public void `[`scalar`](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)`(double)`            | scalar multiplication.
`public void `[`invert`](#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28)`()`            | multiplicative inverse, for semifields
`public void `[`clear`](#group__weight_1gaace5b230ea1544aac7b049091e142bd3)`()`            | delete the letter.
`public bool `[`zero`](#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61)`() const`            | this weight is neutral element for + (absorbing element for *).
`public bool `[`one`](#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6)`() const`            | this weight is neutral element for *
`protected bool `[`equal`](#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e)`(const `[`Weight`](#classWeight)` & rhs) const`            | binary operators are defined only between descendant Weights of same typeid
`protected bool `[`smaller`](#group__weight_1gab3a3a5fb989514e5673582b9a7107d97)`(const `[`Weight`](#classWeight)` & rhs) const`            | * unknown [Weight](api-weight.md#classWeight) is minimal:
`protected void `[`add`](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)`(const `[`Weight`](#classWeight)` & rhs)`            | this and rhs must not be unknown
`protected void `[`mult`](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)`(const `[`Weight`](#classWeight)` & rhs)`            | this and rhs must not be unknown
`protected void `[`print`](#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60)`(std::ostream & o) const`            | 
`public std::string `[`save_to_string`](#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8)`()`            | 
`class `[`CountingWeight`](api-weight.md#classCountingWeight) | domain : vectors of fixed dim k > 0
`class `[`Distance`](api-weight.md#classDistance) | concrete [Weight](#classWeight) domain identical to [TropicalWeight](#classTropicalWeight) with an additional constructor to compute a distance value from an Alignement, obtained as the sum of the pointwise distances.
`class `[`FloatWeight`](api-weight.md#classFloatWeight) | concrete [Weight](api-weight.md#classWeight) defined as a scalar value.
`class `[`PerfoWeight`](api-weight.md#classPerfoWeight) | extention of [ViterbiWeight](api-weight.md#classViterbiWeight) with a model of performance.
`class `[`SemiRing`](api-weight.md#classSemiRing) | semiring structure.
`class `[`TropicalWeight`](api-weight.md#classTropicalWeight) | concrete [Weight](api-weight.md#classWeight) defined as a scalar value: non-negative weights.
`class `[`ViterbiWeight`](api-weight.md#classViterbiWeight) | Viterbi semifield. concrete [Weight](api-weight.md#classWeight) defined as a scalar value: probability of the best derivation.
`class `[`LetterWeight`](api-weight.md#classLetterWeight) | abstract class for concrete weight values. Every concrete weight domain must be a derived class of [LetterWeight](api-weight.md#classLetterWeight).
`class `[`Weight`](api-weight.md#classWeight) | A class of polymorphic weight domains for tree series.

## Members

#### `public std::ostream & `[`operator<<`](#group__weight_1gab340452fea725573e28644234d68147e)`(std::ostream & o,const `[`CountingWeight`](#classCountingWeight)` & rhs)` {#group__weight_1gab340452fea725573e28644234d68147e}

#### `public std::ostream & `[`operator<<`](#group__weight_1ga28da9ceeeef71d7da863914db5247228)`(std::ostream & o,const `[`FloatWeight`](#classFloatWeight)` & rhs)` {#group__weight_1ga28da9ceeeef71d7da863914db5247228}

#### `public inline bool `[`operator==`](#group__weight_1ga985964770c3e3b3aea4ea1ebd817f1c8)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga985964770c3e3b3aea4ea1ebd817f1c8}

**See also**: equal

#### `public inline bool `[`operator!=`](#group__weight_1ga3f8df07b63284c0a1d9da46b7d01588e)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga3f8df07b63284c0a1d9da46b7d01588e}

#### `public inline bool `[`operator<`](#group__weight_1gaf058ecdf4336e4dff64400d149c791f9)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1gaf058ecdf4336e4dff64400d149c791f9}

**See also**: smaller

#### `public inline bool `[`operator>`](#group__weight_1ga3eb9b7d865559995803e57f557f085b3)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga3eb9b7d865559995803e57f557f085b3}

#### `public inline bool `[`operator<=`](#group__weight_1ga37b0ffb977541c9ff2ee7fdc3ec9fd0c)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga37b0ffb977541c9ff2ee7fdc3ec9fd0c}

#### `public inline bool `[`operator>=`](#group__weight_1ga77d4e41a067e6104b5783f06a5018a1c)`(const `[`Weight`](#classWeight)` & lhs,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga77d4e41a067e6104b5783f06a5018a1c}

#### `public inline std::ostream & `[`operator<<`](#group__weight_1ga5fa6fc187426e2cc6aa40f7acddf8455)`(std::ostream & o,const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga5fa6fc187426e2cc6aa40f7acddf8455}

**See also**: print

#### `protected  `[`CountingWeight`](#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa)`(CWType t,size_t dim)` {#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa}

must dim > 0

#### `public  `[`CountingWeight`](#group__weight_1ga1c356f04569b90215755f5d1289c78aa)`(const `[`CountingWeight`](#classCountingWeight)` &)` {#group__weight_1ga1c356f04569b90215755f5d1289c78aa}

#### `public  `[`~CountingWeight`](#group__weight_1gaf006e414e6fee4c338bea085e0bceeba)`()` {#group__weight_1gaf006e414e6fee4c338bea085e0bceeba}

#### `public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gaa78f8a12ada406ba6a331acc42baa052)`(const `[`CountingWeight`](#classCountingWeight)` &)` {#group__weight_1gaa78f8a12ada406ba6a331acc42baa052}

#### `public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` {#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

#### `public virtual `[`CountingWeight`](#classCountingWeight)` * `[`clone`](#group__weight_1ga7e6061ad27a65ee071647866da6a971f)`() const` {#group__weight_1ga7e6061ad27a65ee071647866da6a971f}

#### `public virtual `[`Weight`](#classWeight)` `[`make`](#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2)`(double v) const` {#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2}

#### Returns
ERROR should not be used

#### `public static `[`Weight`](#classWeight)` `[`make_one`](#group__weight_1ga6963921223bbd482ce8454ffa6d6fda5)`(size_t)` {#group__weight_1ga6963921223bbd482ce8454ffa6d6fda5}

#### `public static `[`Weight`](#classWeight)` `[`make_unit`](#group__weight_1ga12cda7b4188f3917d256808fd42c3364)`(size_t dim,size_t i)` {#group__weight_1ga12cda7b4188f3917d256808fd42c3364}

#### Parameters
* `dim` must be > 0 

* `i` must be >=0 

* `i` must be < dim

#### `public virtual `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb)`() const` {#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public virtual `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843)`() const` {#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public virtual bool `[`zero`](#group__weight_1ga62b599ef59770e981d17d565e6727ca9)`() const` {#group__weight_1ga62b599ef59770e981d17d565e6727ca9}

this weight is zero (FAIL)

#### `public bool `[`error`](#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5)`() const` {#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5}

this weight is the error value

#### `public virtual bool `[`one`](#group__weight_1ga5189380be1ac03126180846e3a8fd1cb)`() const` {#group__weight_1ga5189380be1ac03126180846e3a8fd1cb}

this weight is one (null vector)

#### `public virtual double `[`norm`](#group__weight_1gabb8ca43a6821de970e8f6b23c848c804)`() const` {#group__weight_1gabb8ca43a6821de970e8f6b23c848c804}

do not use

#### `public virtual void `[`scalar`](#group__weight_1gabb65ce9f0f34112159f6689a36594470)`(double)` {#group__weight_1gabb65ce9f0f34112159f6689a36594470}

add to each component.

#### `protected virtual bool `[`equal`](#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

#### `protected virtual bool `[`smaller`](#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

do not use

#### `protected virtual void `[`add`](#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5}

* FAIL is neutral

* ERROR absorbing

* VECTOR + VECTOR = ERROR this and rhs must have same dimension

#### `protected virtual void `[`mult`](#group__weight_1ga102af16b814daad826afb91d6f6c75b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga102af16b814daad826afb91d6f6c75b3}

* VECTOR . VECTOR = VECTOR with component-wise sum

* VECTOR . FAIL = FAIL . VECTOR = FAIL

* FAIL . FAIL = FAIL

* ERROR absorbing this and rhs must have same dimension

#### `protected virtual void `[`print`](#group__weight_1ga00d9ffa71ae947eb191e118570049b73)`(std::ostream &) const` {#group__weight_1ga00d9ffa71ae947eb191e118570049b73}

#### `protected virtual void `[`rawprint`](#group__weight_1ga30707b9335976941e15aef45c4db86bf)`(std::ostream &) const` {#group__weight_1ga30707b9335976941e15aef45c4db86bf}

#### `public  `[`Distance`](#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p)` {#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7}

weight which is the distance defined by alignment for input segment not unknown.

#### `private double `[`distcoeff`](#group__weight_1ga076cdb529e76ef7cd5715c451f50c1df)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)` {#group__weight_1ga076cdb529e76ef7cd5715c451f50c1df}

sum of the 2 above or 1 if sum is null.

#### `private double `[`dist_prev`](#group__weight_1gae22f0c2d151a20073571c25e47ca84a3)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)` {#group__weight_1gae22f0c2d151a20073571c25e47ca84a3}

distance to the closest point before j not at the same rdate as j.

#### `private double `[`dist_next`](#group__weight_1gaf87f2d4066d9a8403b7a149cc2dc9a20)`(const `[`InputSegment`](#classInputSegment)` * s,size_t j)` {#group__weight_1gaf87f2d4066d9a8403b7a149cc2dc9a20}

distance to the closest point after j not at the same rdate as j.

#### `public `[`Distance`](#classDistance)` & `[`operator=`](#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f)`(const `[`Distance`](#classDistance)` &)` {#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f}

#### `public virtual `[`Distance`](#classDistance)` * `[`clone`](#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610)`() const` {#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610}

#### `protected virtual void `[`print`](#group__weight_1gaf9785af97fcce45a15098363efe5b7c8)`(std::ostream &) const` {#group__weight_1gaf9785af97fcce45a15098363efe5b7c8}

#### `public  `[`FloatWeight`](#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8)`(double d)` {#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8}

defaut = null weight - not unknown

#### `public  `[`FloatWeight`](#group__weight_1gac7ac9026fecc24193526ef577d819a3b)`(const `[`FloatWeight`](#classFloatWeight)` &)` {#group__weight_1gac7ac9026fecc24193526ef577d819a3b}

#### `public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52)`(const `[`FloatWeight`](#classFloatWeight)` &)` {#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52}

#### `public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1}

#### `public virtual `[`FloatWeight`](#classFloatWeight)` * `[`clone`](#group__weight_1ga3ee8633406a8dc51ba579254872b21e4)`() const` {#group__weight_1ga3ee8633406a8dc51ba579254872b21e4}

#### `public virtual void `[`scalar`](#group__weight_1ga8fe884fff3323382bfc7729500cca368)`(double)` {#group__weight_1ga8fe884fff3323382bfc7729500cca368}

#### `public virtual void `[`invert`](#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab)`()` {#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab}

multiplicative inverse.

this weight must not be zero.

#### `public virtual bool `[`zero`](#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf)`() const` {#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1gac90a90f052aba6f1a03a5238bae96159)`() const` {#group__weight_1gac90a90f052aba6f1a03a5238bae96159}

this letterweight is neutral element for mult.

#### `public bool `[`equal`](#group__weight_1ga11c58941eafe9e4f3a45558812786e36)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` {#group__weight_1ga11c58941eafe9e4f3a45558812786e36}

#### `protected virtual bool `[`equal`](#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `public bool `[`smaller`](#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` {#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c}

#### `protected virtual bool `[`smaller`](#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `public void `[`add`](#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` {#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c}

#### `protected virtual void `[`add`](#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `public void `[`mult`](#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` {#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451}

#### `protected virtual void `[`mult`](#group__weight_1ga16591d6a01c98477ccd57deadf8d4738)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga16591d6a01c98477ccd57deadf8d4738}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `protected virtual void `[`print`](#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f)`(std::ostream &) const` {#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f}

#### `public  `[`PerfoWeight`](#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352}

probability of positions in the given alignement in the interval defined by the given path.

= product of the probabilities for the points in the alignement,

* the pre points on the left bound

* the post rightmost points in the right half of the alignment

#### `public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41)`(const `[`PerfoWeight`](#classPerfoWeight)` &)` {#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41}

#### `public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` {#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63}

#### Parameters
* `rhs` must be a [PerfoWeight](#classPerfoWeight)

#### `public static void `[`set_sigma2`](#group__weight_1ga6761f06ee3b129a22fc0101f4947b4e9)`(double)` {#group__weight_1ga6761f06ee3b129a22fc0101f4947b4e9}

#### `private static double `[`trnorm`](#group__weight_1ga3661d1533628116f3581a8c0ac82c221)`(double x)` {#group__weight_1ga3661d1533628116f3581a8c0ac82c221}

Gaussian pr. density distribution truncated to [a,b].

#### `public  `[`TropicalWeight`](#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` {#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa}

#### `public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1gaa275b4800bdc220d59ee42b2165f638a)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` {#group__weight_1gaa275b4800bdc220d59ee42b2165f638a}

#### `public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246}

rvalue must be a [TropicalWeight](#classTropicalWeight)

#### `public virtual `[`TropicalWeight`](#classTropicalWeight)` * `[`clone`](#group__weight_1ga378883be65a16bb86f13b1a9d941f104)`() const` {#group__weight_1ga378883be65a16bb86f13b1a9d941f104}

#### `public virtual double `[`norm`](#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941)`() const` {#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941}

must not be zero (infinity)

#### `public virtual void `[`scalar`](#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5)`(double)` {#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5}

#### `public virtual void `[`invert`](#group__weight_1ga2bad107be8a2e71fc12b75196adde070)`()` {#group__weight_1ga2bad107be8a2e71fc12b75196adde070}

multiplicative inverse.

this weight must not be zero.

#### `public virtual bool `[`zero`](#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36)`() const` {#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1gae362229d75df663272f4d52c15a04315)`() const` {#group__weight_1gae362229d75df663272f4d52c15a04315}

this letterweight is neutral element for mult.

#### `protected virtual bool `[`equal`](#group__weight_1ga7203d6028f02a2791bdeede99ef59b97)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga7203d6028f02a2791bdeede99ef59b97}

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight)

#### `protected virtual bool `[`smaller`](#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11}

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight)

#### `protected virtual void `[`add`](#group__weight_1ga41791f144fea9717092970563337d040)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga41791f144fea9717092970563337d040}

sum is min.

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight) set this to the min of this and rhs

#### `protected virtual void `[`mult`](#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6}

product is sum.

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight) set this to the sum of this and rhs

#### `protected virtual void `[`print`](#group__weight_1gaa6f92a288b315fed3b301de728f2717d)`(std::ostream &) const` {#group__weight_1gaa6f92a288b315fed3b301de728f2717d}

#### `public static `[`TropicalWeight`](#classTropicalWeight)` `[`inner`](#group__weight_1gace00a414884a9a4824c3cac4b8b084a9)`(size_t)` {#group__weight_1gace00a414884a9a4824c3cac4b8b084a9}

penalty for an inner node.

#### `public static `[`TropicalWeight`](#classTropicalWeight)` `[`tie`](#group__weight_1gad8d0422a24b5d4a76856191cc441396c)`()` {#group__weight_1gad8d0422a24b5d4a76856191cc441396c}

penalty for a tie.

#### `public static `[`TropicalWeight`](#classTropicalWeight)` `[`gracenote`](#group__weight_1ga739a8c09964d0db9552f5924b494c89d)`(size_t)` {#group__weight_1ga739a8c09964d0db9552f5924b494c89d}

penalty for given number of grace notes in a leaf.

* 0 = 1 event, no grace note

* 1 = 1 event, 1 grace note

* 2 = 1 event, 2 grace notes

* etc

#### `protected  `[`ViterbiWeight`](#group__weight_1gaf4e626612999673b8e4e0a322119402c)`(double)` {#group__weight_1gaf4e626612999673b8e4e0a322119402c}

default is one

#### `public  `[`ViterbiWeight`](#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` {#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9}

#### `public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga388bdd81eafaa3cb729934f36f603f35)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` {#group__weight_1ga388bdd81eafaa3cb729934f36f603f35}

#### `public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0)`(const `[`LetterWeight`](#classLetterWeight)` & rvalue)` {#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0}

#### Parameters
* `rvalue` must be a [ViterbiWeight](#classViterbiWeight)

#### `public virtual `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef)`() const` {#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef}

#### `public virtual double `[`norm`](#group__weight_1ga01383c055ca0dafc28870ecd701dbd15)`() const` {#group__weight_1ga01383c055ca0dafc28870ecd701dbd15}

#### `public virtual void `[`scalar`](#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36)`(double)` {#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36}

#### `public virtual void `[`invert`](#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb)`()` {#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb}

multiplicative inverse.

this weight must not be zero. TBR

#### `public virtual bool `[`zero`](#group__weight_1ga35f29b2dcd594cc2cfac884322095c16)`() const` {#group__weight_1ga35f29b2dcd594cc2cfac884322095c16}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde)`() const` {#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde}

this letterweight is neutral element for mult.

#### `protected virtual bool `[`equal`](#group__weight_1ga96f4c23e4845b232451e99b648bddfd6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga96f4c23e4845b232451e99b648bddfd6}

rhs must be a [ViterbiWeight](#classViterbiWeight).

#### `protected virtual bool `[`smaller`](#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1}

rhs must be a [ViterbiWeight](#classViterbiWeight).

#### `protected virtual void `[`add`](#group__weight_1ga009b0216c58308f81497e4aabe49aaed)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga009b0216c58308f81497e4aabe49aaed}

sum is min.

#### Parameters
* `rhs` must be a [ViterbiWeight](#classViterbiWeight). set this to the min of this and rhs.

#### `protected virtual void `[`mult`](#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635}

product is sum.

#### Parameters
* `rhs` must be a [ViterbiWeight](#classViterbiWeight). set this to the sum of this and rhs.

#### `protected virtual void `[`print`](#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51)`(std::ostream &) const` {#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51}

#### `protected virtual bool `[`equal`](#group__weight_1gaf00322921db3c5212f8d5ca63081d689)`(const `[`LetterWeight`](#classLetterWeight)` *) const` {#group__weight_1gaf00322921db3c5212f8d5ca63081d689}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual bool `[`smaller`](#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2)`(const `[`LetterWeight`](#classLetterWeight)` *) const` {#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual void `[`add`](#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8)`(const `[`LetterWeight`](#classLetterWeight)` *)` {#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual void `[`mult`](#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01)`(const `[`LetterWeight`](#classLetterWeight)` *)` {#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `public virtual bool `[`zero`](#group__weight_1gabaad113da06b47c4b291558d05da6aa6)`() const` {#group__weight_1gabaad113da06b47c4b291558d05da6aa6}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0)`() const` {#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0}

this letterweight is neutral element for mult.

#### `protected virtual void `[`print`](#group__weight_1gabef24fcc2eb0c72c420e83e6db625545)`(std::ostream & o) const` {#group__weight_1gabef24fcc2eb0c72c420e83e6db625545}

#### `public  `[`Weight`](#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c)`(const `[`Weight`](#classWeight)` & w)` {#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c}

clone the letter.

#### `public  `[`~Weight`](#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f)`()` {#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f}

#### `public `[`Weight`](#classWeight)` & `[`operator=`](#group__weight_1ga548aadee137a6c274aeb1e56607b05dd)`(const `[`Weight`](#classWeight)` &)` {#group__weight_1ga548aadee137a6c274aeb1e56607b05dd}

#### `public `[`Weight`](#classWeight)` * `[`clone`](#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed)`() const` {#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed}

#### `public `[`Weight`](#classWeight)` `[`make`](#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729)`(double v) const` {#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729}

**See also**: [LetterWeight.make](#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)

#### `public `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55)`() const` {#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55}

return the neutral element for add (absorbing element for mult) for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).

#### `public `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga48012227b61aa4c10064bed70936d78e)`() const` {#group__weight_1ga48012227b61aa4c10064bed70936d78e}

return the neutral element for mult for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).

#### `public bool `[`unknown`](#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47)`() const` {#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47}

unknown weight is a [Weight](#classWeight) with NULL letter.

#### `public bool `[`hasType`](#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35)`(std::string code) const` {#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35}

#### Parameters
* `code` is the code of the letter weight if there is one or "UNKNOWN" otherwise.

#### `public double `[`norm`](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)`()` {#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4}

this [Weight](#classWeight) must not be unknown (letter != NULL) 

not const: may need recomputations.

#### `public void `[`scalar`](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)`(double)` {#group__weight_1ga5d63ead0a1d21ee5628c643fca773903}

scalar multiplication.

this [Weight](#classWeight) must not be unknown (letter != NULL).

#### `public void `[`invert`](#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28)`()` {#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28}

multiplicative inverse, for semifields

this [Weight](#classWeight) must not be zero 

this [Weight](#classWeight) must not be unknown (letter != NULL)

TBR : replace by div with const rhs

#### `public void `[`clear`](#group__weight_1gaace5b230ea1544aac7b049091e142bd3)`()` {#group__weight_1gaace5b230ea1544aac7b049091e142bd3}

delete the letter.

this weight becomes unknown.

#### `public bool `[`zero`](#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61)`() const` {#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61}

this weight is neutral element for + (absorbing element for *).

#### `public bool `[`one`](#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6)`() const` {#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6}

this weight is neutral element for *

#### `protected bool `[`equal`](#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e)`(const `[`Weight`](#classWeight)` & rhs) const` {#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e}

binary operators are defined only between descendant Weights of same typeid

* two unknown Weights are equal

* one unknown weight and one not unknown are not equal

* equality of two not unknown weight depends on the descendant class

#### `protected bool `[`smaller`](#group__weight_1gab3a3a5fb989514e5673582b9a7107d97)`(const `[`Weight`](#classWeight)` & rhs) const` {#group__weight_1gab3a3a5fb989514e5673582b9a7107d97}

* unknown [Weight](#classWeight) is minimal:

* unknown [Weight](#classWeight) is smaller than any not unknown [Weight](#classWeight)

* not unknown [Weight](#classWeight) is not smaller that unknown [Weight](#classWeight)

* unknown [Weight](#classWeight) is not smaller than unknown [Weight](#classWeight)

* inequality of two not unknown weight depends on the descendant class

#### `protected void `[`add`](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)`(const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga261db18abff49cac38bd02b8f7af94db}

this and rhs must not be unknown

#### `protected void `[`mult`](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)`(const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga7188f571e507d7f31b76de7faebdb78f}

this and rhs must not be unknown

#### `protected void `[`print`](#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60)`(std::ostream & o) const` {#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60}

#### `public std::string `[`save_to_string`](#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8)`()` {#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8}

# class `CountingWeight` {#classCountingWeight}

```
class CountingWeight
  : public LetterWeight
```  

domain : vectors of fixed dim k > 0

* FAIL = stuck (0 run in state s for 1 tree)

* ERROR = ambiguity in grammar (2 runs for 1 tree)

zero = FAIL add : for all x, y vectors dim k x + y = ERROR ERROR absorbing for + one = null vector of dim k mult : for all x, y vectors dim k x . y = component-wise sum x . FAIL = FAIL . x = FAIL FAIL . FAIL = FAIL ERROR absorbing for .

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CountingWeight`](#group__weight_1ga1c356f04569b90215755f5d1289c78aa)`(const `[`CountingWeight`](#classCountingWeight)` &)` | 
`public  `[`~CountingWeight`](#group__weight_1gaf006e414e6fee4c338bea085e0bceeba)`()` | 
`public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gaa78f8a12ada406ba6a331acc42baa052)`(const `[`CountingWeight`](#classCountingWeight)` &)` | 
`public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` | #### Parameters
`public virtual `[`CountingWeight`](#classCountingWeight)` * `[`clone`](#group__weight_1ga7e6061ad27a65ee071647866da6a971f)`() const` | 
`public virtual `[`Weight`](#classWeight)` `[`make`](#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2)`(double v) const` | #### Returns
`public virtual `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public virtual `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public virtual double `[`norm`](#group__weight_1gabb8ca43a6821de970e8f6b23c848c804)`() const` | do not use
`public virtual void `[`scalar`](#group__weight_1gabb65ce9f0f34112159f6689a36594470)`(double)` | add to each component.
`public inline virtual void `[`invert`](#classCountingWeight_1ab9749abc9fbcee9ed064a9be33879829)`()` | do not use
`public virtual bool `[`zero`](#group__weight_1ga62b599ef59770e981d17d565e6727ca9)`() const` | this weight is zero (FAIL)
`public inline bool `[`fail`](#classCountingWeight_1a4b5b3fa15f85d10d35f062225b35323d)`() const` | this weight is the error value
`public bool `[`error`](#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5)`() const` | this weight is the error value
`public virtual bool `[`one`](#group__weight_1ga5189380be1ac03126180846e3a8fd1cb)`() const` | this weight is one (null vector)
`public inline virtual size_t `[`dim`](#classCountingWeight_1a1b0bd542683b909c2dc4d35bbbf42887)`() const` | 
`public inline virtual bool `[`hasType`](#classCountingWeight_1aedc7b4e3519adc6e29bcabd4d8ba719a)`(std::string code) const` | 
`protected CWType `[`_type`](api-weight.md#classCountingWeight_1a3b1e3ac9e87f34af7d041b8eac01bfb1) | 
`protected size_t `[`_dim`](api-weight.md#classCountingWeight_1ab1f3033b8d14a5389572f158a2b8b757) | 
`protected std::vector< size_t > `[`_counters`](api-weight.md#classCountingWeight_1a951d677729f631cd63505f10fac4cd31) | 
`protected  `[`CountingWeight`](#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa)`(CWType t,size_t dim)` | must dim > 0
`protected virtual bool `[`equal`](#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual bool `[`smaller`](#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual void `[`add`](#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | * FAIL is neutral
`protected virtual void `[`mult`](#group__weight_1ga102af16b814daad826afb91d6f6c75b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | * VECTOR . VECTOR = VECTOR with component-wise sum
`protected virtual void `[`print`](#group__weight_1ga00d9ffa71ae947eb191e118570049b73)`(std::ostream &) const` | 
`protected virtual void `[`rawprint`](#group__weight_1ga30707b9335976941e15aef45c4db86bf)`(std::ostream &) const` | 

## Members

#### `public  `[`CountingWeight`](#group__weight_1ga1c356f04569b90215755f5d1289c78aa)`(const `[`CountingWeight`](#classCountingWeight)` &)` {#group__weight_1ga1c356f04569b90215755f5d1289c78aa}

#### `public  `[`~CountingWeight`](#group__weight_1gaf006e414e6fee4c338bea085e0bceeba)`()` {#group__weight_1gaf006e414e6fee4c338bea085e0bceeba}

#### `public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gaa78f8a12ada406ba6a331acc42baa052)`(const `[`CountingWeight`](#classCountingWeight)` &)` {#group__weight_1gaa78f8a12ada406ba6a331acc42baa052}

#### `public `[`CountingWeight`](#classCountingWeight)` & `[`operator=`](#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` {#group__weight_1gabde05f9a8f2eb526e5154c4f3480205b}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

#### `public virtual `[`CountingWeight`](#classCountingWeight)` * `[`clone`](#group__weight_1ga7e6061ad27a65ee071647866da6a971f)`() const` {#group__weight_1ga7e6061ad27a65ee071647866da6a971f}

#### `public virtual `[`Weight`](#classWeight)` `[`make`](#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2)`(double v) const` {#group__weight_1ga1d225aef0e74c70d8ae73164de4f56e2}

#### Returns
ERROR should not be used

#### `public virtual `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb)`() const` {#group__weight_1ga76eb9cd401bbeba9450469a889dfb7eb}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public virtual `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843)`() const` {#group__weight_1ga0a589d8beac0f16f54f7e4f451adc843}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public virtual double `[`norm`](#group__weight_1gabb8ca43a6821de970e8f6b23c848c804)`() const` {#group__weight_1gabb8ca43a6821de970e8f6b23c848c804}

do not use

#### `public virtual void `[`scalar`](#group__weight_1gabb65ce9f0f34112159f6689a36594470)`(double)` {#group__weight_1gabb65ce9f0f34112159f6689a36594470}

add to each component.

#### `public inline virtual void `[`invert`](#classCountingWeight_1ab9749abc9fbcee9ed064a9be33879829)`()` {#classCountingWeight_1ab9749abc9fbcee9ed064a9be33879829}

do not use

#### `public virtual bool `[`zero`](#group__weight_1ga62b599ef59770e981d17d565e6727ca9)`() const` {#group__weight_1ga62b599ef59770e981d17d565e6727ca9}

this weight is zero (FAIL)

#### `public inline bool `[`fail`](#classCountingWeight_1a4b5b3fa15f85d10d35f062225b35323d)`() const` {#classCountingWeight_1a4b5b3fa15f85d10d35f062225b35323d}

this weight is the error value

#### `public bool `[`error`](#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5)`() const` {#group__weight_1ga41f35b8902b2474f1ac39878a40f5ca5}

this weight is the error value

#### `public virtual bool `[`one`](#group__weight_1ga5189380be1ac03126180846e3a8fd1cb)`() const` {#group__weight_1ga5189380be1ac03126180846e3a8fd1cb}

this weight is one (null vector)

#### `public inline virtual size_t `[`dim`](#classCountingWeight_1a1b0bd542683b909c2dc4d35bbbf42887)`() const` {#classCountingWeight_1a1b0bd542683b909c2dc4d35bbbf42887}

#### `public inline virtual bool `[`hasType`](#classCountingWeight_1aedc7b4e3519adc6e29bcabd4d8ba719a)`(std::string code) const` {#classCountingWeight_1aedc7b4e3519adc6e29bcabd4d8ba719a}

#### `protected CWType `[`_type`](api-weight.md#classCountingWeight_1a3b1e3ac9e87f34af7d041b8eac01bfb1) {#classCountingWeight_1a3b1e3ac9e87f34af7d041b8eac01bfb1}

#### `protected size_t `[`_dim`](api-weight.md#classCountingWeight_1ab1f3033b8d14a5389572f158a2b8b757) {#classCountingWeight_1ab1f3033b8d14a5389572f158a2b8b757}

#### `protected std::vector< size_t > `[`_counters`](api-weight.md#classCountingWeight_1a951d677729f631cd63505f10fac4cd31) {#classCountingWeight_1a951d677729f631cd63505f10fac4cd31}

#### `protected  `[`CountingWeight`](#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa)`(CWType t,size_t dim)` {#group__weight_1gaff2b14e164c777c04be1a0e3c73b71fa}

must dim > 0

#### `protected virtual bool `[`equal`](#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga33f06a811859bdbbf1c0ad2e34299df9}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

#### `protected virtual bool `[`smaller`](#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga149e9ae84c83b9235d512c68fec54d1c}

#### Parameters
* `rhs` must be a [CountingWeight](#classCountingWeight)

do not use

#### `protected virtual void `[`add`](#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga01ca779f7d5378564f4419150d7ae1f5}

* FAIL is neutral

* ERROR absorbing

* VECTOR + VECTOR = ERROR this and rhs must have same dimension

#### `protected virtual void `[`mult`](#group__weight_1ga102af16b814daad826afb91d6f6c75b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga102af16b814daad826afb91d6f6c75b3}

* VECTOR . VECTOR = VECTOR with component-wise sum

* VECTOR . FAIL = FAIL . VECTOR = FAIL

* FAIL . FAIL = FAIL

* ERROR absorbing this and rhs must have same dimension

#### `protected virtual void `[`print`](#group__weight_1ga00d9ffa71ae947eb191e118570049b73)`(std::ostream &) const` {#group__weight_1ga00d9ffa71ae947eb191e118570049b73}

#### `protected virtual void `[`rawprint`](#group__weight_1ga30707b9335976941e15aef45c4db86bf)`(std::ostream &) const` {#group__weight_1ga30707b9335976941e15aef45c4db86bf}

# class `Distance` {#classDistance}

```
class Distance
  : public TropicalWeight
```  

concrete [Weight](#classWeight) domain identical to [TropicalWeight](#classTropicalWeight) with an additional constructor to compute a distance value from an Alignement, obtained as the sum of the pointwise distances.

a [Distance](#classDistance) hasType "TropicalWeight"

ALT: implement as vector of pointwise distances

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Distance`](#classDistance_1af0d871cc82151e600c043de0765bcb9d)`(double d)` | defaut = null distance - not unknown
`public  `[`Distance`](#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p)` | weight which is the distance defined by alignment for input segment not unknown.
`public inline  `[`Distance`](#classDistance_1ae27d1f8eca9cda4e4435c933e94daa53)`(const `[`Distance`](#classDistance)` & d)` | 
`public inline  `[`~Distance`](#classDistance_1a933d4ecca7e420ac53945e36d64e9500)`()` | 
`public `[`Distance`](#classDistance)` & `[`operator=`](#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f)`(const `[`Distance`](#classDistance)` &)` | 
`public virtual `[`Distance`](#classDistance)` * `[`clone`](#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610)`() const` | 
`public inline virtual `[`Weight`](#classWeight)` `[`make`](#classDistance_1a1fe45f762afff378c46f81d6199a14ab)`(double v) const` | value must be positive
`public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classDistance_1affe4a5bab7ca33e5119d3f93484dccb3)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classDistance_1a8aac0a94a73b60ef2bf566eb59a3e704)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`protected virtual void `[`print`](#group__weight_1gaf9785af97fcce45a15098363efe5b7c8)`(std::ostream &) const` | 

## Members

#### `public inline  `[`Distance`](#classDistance_1af0d871cc82151e600c043de0765bcb9d)`(double d)` {#classDistance_1af0d871cc82151e600c043de0765bcb9d}

defaut = null distance - not unknown

#### `public  `[`Distance`](#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p)` {#group__weight_1ga4ebd2ecbdf6955d1ed9064d391cc71b7}

weight which is the distance defined by alignment for input segment not unknown.

#### `public inline  `[`Distance`](#classDistance_1ae27d1f8eca9cda4e4435c933e94daa53)`(const `[`Distance`](#classDistance)` & d)` {#classDistance_1ae27d1f8eca9cda4e4435c933e94daa53}

#### `public inline  `[`~Distance`](#classDistance_1a933d4ecca7e420ac53945e36d64e9500)`()` {#classDistance_1a933d4ecca7e420ac53945e36d64e9500}

#### `public `[`Distance`](#classDistance)` & `[`operator=`](#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f)`(const `[`Distance`](#classDistance)` &)` {#group__weight_1gaf54b8155e1a7652461400d4dd0a5739f}

#### `public virtual `[`Distance`](#classDistance)` * `[`clone`](#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610)`() const` {#group__weight_1gafb8da4bc0d0e23217ecad4c219d9a610}

#### `public inline virtual `[`Weight`](#classWeight)` `[`make`](#classDistance_1a1fe45f762afff378c46f81d6199a14ab)`(double v) const` {#classDistance_1a1fe45f762afff378c46f81d6199a14ab}

value must be positive

TBR : stricly positive

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classDistance_1affe4a5bab7ca33e5119d3f93484dccb3)`() const` {#classDistance_1affe4a5bab7ca33e5119d3f93484dccb3}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classDistance_1a8aac0a94a73b60ef2bf566eb59a3e704)`() const` {#classDistance_1a8aac0a94a73b60ef2bf566eb59a3e704}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `protected virtual void `[`print`](#group__weight_1gaf9785af97fcce45a15098363efe5b7c8)`(std::ostream &) const` {#group__weight_1gaf9785af97fcce45a15098363efe5b7c8}

# class `FloatWeight` {#classFloatWeight}

```
class FloatWeight
  : public LetterWeight
```  

concrete [Weight](#classWeight) defined as a scalar value.

* domain : double

* operators

* add is +

* zero is 0.0

* mult is *

* one is 1.0

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FloatWeight`](#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8)`(double d)` | defaut = null weight - not unknown
`public  `[`FloatWeight`](#group__weight_1gac7ac9026fecc24193526ef577d819a3b)`(const `[`FloatWeight`](#classFloatWeight)` &)` | 
`public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52)`(const `[`FloatWeight`](#classFloatWeight)` &)` | 
`public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1)`(const `[`LetterWeight`](#classLetterWeight)` &)` | 
`public virtual `[`FloatWeight`](#classFloatWeight)` * `[`clone`](#group__weight_1ga3ee8633406a8dc51ba579254872b21e4)`() const` | 
`public inline virtual `[`Weight`](#classWeight)` `[`make`](#classFloatWeight_1a71464c94830161af2f0dd3df99fe6856)`(double v) const` | factory.
`public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classFloatWeight_1a0e9f541164db5cf13978efd46585810b)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classFloatWeight_1a4952f3b312622eccc331b4d001c816a4)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public inline virtual double `[`norm`](#classFloatWeight_1a2c63d370c10678609f814907193b23ee)`() const` | 
`public virtual void `[`scalar`](#group__weight_1ga8fe884fff3323382bfc7729500cca368)`(double)` | 
`public virtual void `[`invert`](#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab)`()` | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf)`() const` | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1gac90a90f052aba6f1a03a5238bae96159)`() const` | this letterweight is neutral element for mult.
`public bool `[`equal`](#group__weight_1ga11c58941eafe9e4f3a45558812786e36)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` | 
`public bool `[`smaller`](#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` | 
`public void `[`add`](#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` | 
`public void `[`mult`](#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` | 
`public inline virtual bool `[`hasType`](#classFloatWeight_1ab0d05685ad9a718cc9020a55d2932486)`(std::string code) const` | 
`protected double `[`_val`](api-weight.md#classFloatWeight_1a379227ff21946891cf58783ece9c30f3) | 
`protected virtual bool `[`equal`](#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual bool `[`smaller`](#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual void `[`add`](#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | #### Parameters
`protected virtual void `[`mult`](#group__weight_1ga16591d6a01c98477ccd57deadf8d4738)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | #### Parameters
`protected virtual void `[`print`](#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f)`(std::ostream &) const` | 

## Members

#### `public  `[`FloatWeight`](#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8)`(double d)` {#group__weight_1ga7eed0253fd20af20e3fec8dc2f4652b8}

defaut = null weight - not unknown

#### `public  `[`FloatWeight`](#group__weight_1gac7ac9026fecc24193526ef577d819a3b)`(const `[`FloatWeight`](#classFloatWeight)` &)` {#group__weight_1gac7ac9026fecc24193526ef577d819a3b}

#### `public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52)`(const `[`FloatWeight`](#classFloatWeight)` &)` {#group__weight_1ga265949c1cd1d5dbf5888bcd2d4283d52}

#### `public `[`FloatWeight`](#classFloatWeight)` & `[`operator=`](#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#group__weight_1gafae5ba059c08a25f4bd2ffa422b953c1}

#### `public virtual `[`FloatWeight`](#classFloatWeight)` * `[`clone`](#group__weight_1ga3ee8633406a8dc51ba579254872b21e4)`() const` {#group__weight_1ga3ee8633406a8dc51ba579254872b21e4}

#### `public inline virtual `[`Weight`](#classWeight)` `[`make`](#classFloatWeight_1a71464c94830161af2f0dd3df99fe6856)`(double v) const` {#classFloatWeight_1a71464c94830161af2f0dd3df99fe6856}

factory.

#### Returns
a weight of same type as this letter, initialized with given value.

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classFloatWeight_1a0e9f541164db5cf13978efd46585810b)`() const` {#classFloatWeight_1a0e9f541164db5cf13978efd46585810b}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classFloatWeight_1a4952f3b312622eccc331b4d001c816a4)`() const` {#classFloatWeight_1a4952f3b312622eccc331b4d001c816a4}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public inline virtual double `[`norm`](#classFloatWeight_1a2c63d370c10678609f814907193b23ee)`() const` {#classFloatWeight_1a2c63d370c10678609f814907193b23ee}

#### `public virtual void `[`scalar`](#group__weight_1ga8fe884fff3323382bfc7729500cca368)`(double)` {#group__weight_1ga8fe884fff3323382bfc7729500cca368}

#### `public virtual void `[`invert`](#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab)`()` {#group__weight_1ga45533bb9d354577728ddb1e0a42c4bab}

multiplicative inverse.

this weight must not be zero.

#### `public virtual bool `[`zero`](#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf)`() const` {#group__weight_1gafb9e6bffef57c6462cd2eea89efbfeaf}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1gac90a90f052aba6f1a03a5238bae96159)`() const` {#group__weight_1gac90a90f052aba6f1a03a5238bae96159}

this letterweight is neutral element for mult.

#### `public bool `[`equal`](#group__weight_1ga11c58941eafe9e4f3a45558812786e36)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` {#group__weight_1ga11c58941eafe9e4f3a45558812786e36}

#### `public bool `[`smaller`](#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs) const` {#group__weight_1ga0a34058d4d70333e0b74edc66aa8884c}

#### `public void `[`add`](#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` {#group__weight_1gaf86e96735a95a82f3ad7b11ee9d6162c}

#### `public void `[`mult`](#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451)`(const `[`FloatWeight`](#classFloatWeight)` & rhs)` {#group__weight_1ga05347e9d4ebd5c7f95d8f575cc396451}

#### `public inline virtual bool `[`hasType`](#classFloatWeight_1ab0d05685ad9a718cc9020a55d2932486)`(std::string code) const` {#classFloatWeight_1ab0d05685ad9a718cc9020a55d2932486}

#### `protected double `[`_val`](api-weight.md#classFloatWeight_1a379227ff21946891cf58783ece9c30f3) {#classFloatWeight_1a379227ff21946891cf58783ece9c30f3}

#### `protected virtual bool `[`equal`](#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1gaaa895d17971bdd11c3ecddb9d701ac0a}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `protected virtual bool `[`smaller`](#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga89e27d308aeaadbc11621ae9a6e839b3}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `protected virtual void `[`add`](#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga987ee2a0704f046a9be6e2456d56df7c}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `protected virtual void `[`mult`](#group__weight_1ga16591d6a01c98477ccd57deadf8d4738)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga16591d6a01c98477ccd57deadf8d4738}

#### Parameters
* `rhs` must be a [FloatWeight](#classFloatWeight).

#### `protected virtual void `[`print`](#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f)`(std::ostream &) const` {#group__weight_1ga535988d2b88e8f2bbb24eeeba5daf81f}

# class `PerfoWeight` {#classPerfoWeight}

```
class PerfoWeight
  : public ViterbiWeight
```  

extention of [ViterbiWeight](#classViterbiWeight) with a model of performance.

compute probabilities of alignement of input points to a score following a truncated Gaussian distribution with parameters mu (default 0) and sigma (default 1) and is truncated on the interval [a,b] (values in samples) and shifted.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`PerfoWeight`](#classPerfoWeight_1a37edc602ff52c15e3a3306935c4f7f2a)`(double v)` | 
`public  `[`PerfoWeight`](#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` | probability of positions in the given alignement in the interval defined by the given path.
`public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41)`(const `[`PerfoWeight`](#classPerfoWeight)` &)` | 
`public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` | #### Parameters
`public inline  `[`~PerfoWeight`](#classPerfoWeight_1aadcab66aee485f9f0a9802b265831598)`()` | 
`public virtual `[`PerfoWeight`](#classPerfoWeight)` * `[`clone`](#classPerfoWeight_1a8023bda84f8e883bbad23b31c1ccdd0b)`() const` | 
`public inline virtual `[`Weight`](#classWeight)` `[`make`](#classPerfoWeight_1ad9237d9b3fccf6f0b70133e10c1103b2)`(double v) const` | factory.
`public inline virtual bool `[`hasType`](#classPerfoWeight_1a170351b18fd33ea7753d8b82eb83ae9e)`(std::string code) const` | type code is still "ViterbiWeight"

## Members

#### `public inline  `[`PerfoWeight`](#classPerfoWeight_1a37edc602ff52c15e3a3306935c4f7f2a)`(double v)` {#classPerfoWeight_1a37edc602ff52c15e3a3306935c4f7f2a}

#### `public  `[`PerfoWeight`](#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`AlignedInterval`](#classAlignedInterval)` * p,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__weight_1gaa4edfc478ea676a169bd5b58b82ff352}

probability of positions in the given alignement in the interval defined by the given path.

= product of the probabilities for the points in the alignement,

* the pre points on the left bound

* the post rightmost points in the right half of the alignment

#### `public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41)`(const `[`PerfoWeight`](#classPerfoWeight)` &)` {#group__weight_1ga00a9b370fb237b3230cbce5cf9d8fe41}

#### `public `[`PerfoWeight`](#classPerfoWeight)` & `[`operator=`](#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63)`(const `[`LetterWeight`](#classLetterWeight)` & rhs)` {#group__weight_1gaabb75d1419be3bb59dcdd3b8e56b0e63}

#### Parameters
* `rhs` must be a [PerfoWeight](#classPerfoWeight)

#### `public inline  `[`~PerfoWeight`](#classPerfoWeight_1aadcab66aee485f9f0a9802b265831598)`()` {#classPerfoWeight_1aadcab66aee485f9f0a9802b265831598}

#### `public virtual `[`PerfoWeight`](#classPerfoWeight)` * `[`clone`](#classPerfoWeight_1a8023bda84f8e883bbad23b31c1ccdd0b)`() const` {#classPerfoWeight_1a8023bda84f8e883bbad23b31c1ccdd0b}

#### `public inline virtual `[`Weight`](#classWeight)` `[`make`](#classPerfoWeight_1ad9237d9b3fccf6f0b70133e10c1103b2)`(double v) const` {#classPerfoWeight_1ad9237d9b3fccf6f0b70133e10c1103b2}

factory.

#### Returns
a weight of same type as this letter, initialized with given value.

#### `public inline virtual bool `[`hasType`](#classPerfoWeight_1a170351b18fd33ea7753d8b82eb83ae9e)`(std::string code) const` {#classPerfoWeight_1a170351b18fd33ea7753d8b82eb83ae9e}

type code is still "ViterbiWeight"

# class `SemiRing` {#classSemiRing}

semiring structure.

* add is associative, commutative

* zero is neutral element for plus

* mult is associative

* one is neutral element for mult

* zero is absorbing element for mult

* mult distributes over plus

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `TropicalWeight` {#classTropicalWeight}

```
class TropicalWeight
  : public LetterWeight
```  

concrete [Weight](#classWeight) defined as a scalar value: non-negative weights.

* domain : positive or null double + infinity

* operators of tropical algebra:

* add is min

* zero is infinity

* mult is +

* one is 0

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`TropicalWeight`](#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` | 
`public inline  `[`~TropicalWeight`](#classTropicalWeight_1ac1e9e62336532b7362b1b5f79d7e7d7b)`()` | 
`public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1gaa275b4800bdc220d59ee42b2165f638a)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` | 
`public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246)`(const `[`LetterWeight`](#classLetterWeight)` &)` | rvalue must be a [TropicalWeight](api-weight.md#classTropicalWeight)
`public virtual `[`TropicalWeight`](#classTropicalWeight)` * `[`clone`](#group__weight_1ga378883be65a16bb86f13b1a9d941f104)`() const` | 
`public inline virtual `[`Weight`](#classWeight)` `[`make`](#classTropicalWeight_1abc00c8fe56beedff6b7192325833d6d3)`(double v) const` | value must be positive
`public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classTropicalWeight_1a8de59f3233cfd822712b04d6069f5256)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classTropicalWeight_1a62d1dc9815ba6ba04665047ba6581731)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public virtual double `[`norm`](#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941)`() const` | must not be zero (infinity)
`public virtual void `[`scalar`](#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5)`(double)` | 
`public virtual void `[`invert`](#group__weight_1ga2bad107be8a2e71fc12b75196adde070)`()` | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36)`() const` | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1gae362229d75df663272f4d52c15a04315)`() const` | this letterweight is neutral element for mult.
`public inline virtual bool `[`hasType`](#classTropicalWeight_1a276bcd4dd3d61887d1628e63665edd7e)`(std::string code) const` | 
`protected double `[`_val`](api-weight.md#classTropicalWeight_1a8b8b7de0bd57c28630fb978daceeeffb) | 
`protected inline  `[`TropicalWeight`](#classTropicalWeight_1add8ba82f403d669abe6d7601f003bc77)`()` | default is one
`protected inline  `[`TropicalWeight`](#classTropicalWeight_1a09d45439a55d482120356f949c638da5)`(double v)` | 
`protected virtual bool `[`equal`](#group__weight_1ga7203d6028f02a2791bdeede99ef59b97)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual bool `[`smaller`](#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | #### Parameters
`protected virtual void `[`add`](#group__weight_1ga41791f144fea9717092970563337d040)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | sum is min.
`protected virtual void `[`mult`](#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | product is sum.
`protected virtual void `[`print`](#group__weight_1gaa6f92a288b315fed3b301de728f2717d)`(std::ostream &) const` | 

## Members

#### `public  `[`TropicalWeight`](#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` {#group__weight_1ga17f51f13d0338bbcbc76ada716e626aa}

#### `public inline  `[`~TropicalWeight`](#classTropicalWeight_1ac1e9e62336532b7362b1b5f79d7e7d7b)`()` {#classTropicalWeight_1ac1e9e62336532b7362b1b5f79d7e7d7b}

#### `public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1gaa275b4800bdc220d59ee42b2165f638a)`(const `[`TropicalWeight`](#classTropicalWeight)` &)` {#group__weight_1gaa275b4800bdc220d59ee42b2165f638a}

#### `public `[`TropicalWeight`](#classTropicalWeight)` & `[`operator=`](#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#group__weight_1ga3aeb0d5a945daa39a0ed9a02fe92f246}

rvalue must be a [TropicalWeight](#classTropicalWeight)

#### `public virtual `[`TropicalWeight`](#classTropicalWeight)` * `[`clone`](#group__weight_1ga378883be65a16bb86f13b1a9d941f104)`() const` {#group__weight_1ga378883be65a16bb86f13b1a9d941f104}

#### `public inline virtual `[`Weight`](#classWeight)` `[`make`](#classTropicalWeight_1abc00c8fe56beedff6b7192325833d6d3)`(double v) const` {#classTropicalWeight_1abc00c8fe56beedff6b7192325833d6d3}

value must be positive

TBR : stricly positive

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classTropicalWeight_1a8de59f3233cfd822712b04d6069f5256)`() const` {#classTropicalWeight_1a8de59f3233cfd822712b04d6069f5256}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classTropicalWeight_1a62d1dc9815ba6ba04665047ba6581731)`() const` {#classTropicalWeight_1a62d1dc9815ba6ba04665047ba6581731}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public virtual double `[`norm`](#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941)`() const` {#group__weight_1gabea8959ba2b8538194c3aadf5f9e4941}

must not be zero (infinity)

#### `public virtual void `[`scalar`](#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5)`(double)` {#group__weight_1ga9b479f4a9f23f4c423729b669aa69dc5}

#### `public virtual void `[`invert`](#group__weight_1ga2bad107be8a2e71fc12b75196adde070)`()` {#group__weight_1ga2bad107be8a2e71fc12b75196adde070}

multiplicative inverse.

this weight must not be zero.

#### `public virtual bool `[`zero`](#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36)`() const` {#group__weight_1ga55f1e2bcb9e1e3fd521d652a5aebfc36}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1gae362229d75df663272f4d52c15a04315)`() const` {#group__weight_1gae362229d75df663272f4d52c15a04315}

this letterweight is neutral element for mult.

#### `public inline virtual bool `[`hasType`](#classTropicalWeight_1a276bcd4dd3d61887d1628e63665edd7e)`(std::string code) const` {#classTropicalWeight_1a276bcd4dd3d61887d1628e63665edd7e}

#### `protected double `[`_val`](api-weight.md#classTropicalWeight_1a8b8b7de0bd57c28630fb978daceeeffb) {#classTropicalWeight_1a8b8b7de0bd57c28630fb978daceeeffb}

#### `protected inline  `[`TropicalWeight`](#classTropicalWeight_1add8ba82f403d669abe6d7601f003bc77)`()` {#classTropicalWeight_1add8ba82f403d669abe6d7601f003bc77}

default is one

#### `protected inline  `[`TropicalWeight`](#classTropicalWeight_1a09d45439a55d482120356f949c638da5)`(double v)` {#classTropicalWeight_1a09d45439a55d482120356f949c638da5}

#### `protected virtual bool `[`equal`](#group__weight_1ga7203d6028f02a2791bdeede99ef59b97)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga7203d6028f02a2791bdeede99ef59b97}

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight)

#### `protected virtual bool `[`smaller`](#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga4237553cf4beafd5a96bd0ac7da7ac11}

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight)

#### `protected virtual void `[`add`](#group__weight_1ga41791f144fea9717092970563337d040)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga41791f144fea9717092970563337d040}

sum is min.

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight) set this to the min of this and rhs

#### `protected virtual void `[`mult`](#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga6bf7a669a9798ebbd6b4138cce2bade6}

product is sum.

#### Parameters
* `rhs` must be a [TropicalWeight](#classTropicalWeight) set this to the sum of this and rhs

#### `protected virtual void `[`print`](#group__weight_1gaa6f92a288b315fed3b301de728f2717d)`(std::ostream &) const` {#group__weight_1gaa6f92a288b315fed3b301de728f2717d}

# class `ViterbiWeight` {#classViterbiWeight}

```
class ViterbiWeight
  : public LetterWeight
```  

Viterbi semifield. concrete [Weight](#classWeight) defined as a scalar value: probability of the best derivation.

* domain : positive or null rational numbers in [0, 1]

* operators:

* add is max

* zero is 0

* mult is *

* one is 1

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ViterbiWeight`](#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` | 
`public inline  `[`~ViterbiWeight`](#classViterbiWeight_1ad24850a46f10b4abb94dec4b675b2e69)`()` | 
`public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga388bdd81eafaa3cb729934f36f603f35)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` | 
`public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0)`(const `[`LetterWeight`](#classLetterWeight)` & rvalue)` | #### Parameters
`public virtual `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef)`() const` | 
`public inline virtual `[`Weight`](#classWeight)` `[`make`](#classViterbiWeight_1a8b4676e41a4edb2cc5466d1e8cb1059a)`(double v) const` | factory.
`public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classViterbiWeight_1af7655a0c00c0af95699e186ceec25a7e)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classViterbiWeight_1a5009d22fc226821a8dfd876ed9bd9e84)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public virtual double `[`norm`](#group__weight_1ga01383c055ca0dafc28870ecd701dbd15)`() const` | 
`public virtual void `[`scalar`](#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36)`(double)` | 
`public virtual void `[`invert`](#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb)`()` | multiplicative inverse.
`public virtual bool `[`zero`](#group__weight_1ga35f29b2dcd594cc2cfac884322095c16)`() const` | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde)`() const` | this letterweight is neutral element for mult.
`public inline virtual bool `[`hasType`](#classViterbiWeight_1a115d43704bf01603dad9cda0d28292bf)`(std::string code) const` | 
`protected double `[`_val`](api-weight.md#classViterbiWeight_1a0e70b1bda371ba1887ea71e5ff5f91bf) | 
`protected  `[`ViterbiWeight`](#group__weight_1gaf4e626612999673b8e4e0a322119402c)`(double)` | default is one
`protected virtual bool `[`equal`](#group__weight_1ga96f4c23e4845b232451e99b648bddfd6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | rhs must be a [ViterbiWeight](api-weight.md#classViterbiWeight).
`protected virtual bool `[`smaller`](#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` | rhs must be a [ViterbiWeight](api-weight.md#classViterbiWeight).
`protected virtual void `[`add`](#group__weight_1ga009b0216c58308f81497e4aabe49aaed)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | sum is min.
`protected virtual void `[`mult`](#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` | product is sum.
`protected virtual void `[`print`](#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51)`(std::ostream &) const` | 

## Members

#### `public  `[`ViterbiWeight`](#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` {#group__weight_1gad7ca8b9082125f4ac2f9f562685517a9}

#### `public inline  `[`~ViterbiWeight`](#classViterbiWeight_1ad24850a46f10b4abb94dec4b675b2e69)`()` {#classViterbiWeight_1ad24850a46f10b4abb94dec4b675b2e69}

#### `public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga388bdd81eafaa3cb729934f36f603f35)`(const `[`ViterbiWeight`](#classViterbiWeight)` &)` {#group__weight_1ga388bdd81eafaa3cb729934f36f603f35}

#### `public `[`ViterbiWeight`](#classViterbiWeight)` & `[`operator=`](#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0)`(const `[`LetterWeight`](#classLetterWeight)` & rvalue)` {#group__weight_1ga6624ad5a46c38eeae5382fc00cf4b8a0}

#### Parameters
* `rvalue` must be a [ViterbiWeight](#classViterbiWeight)

#### `public virtual `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef)`() const` {#group__weight_1ga315ec4d2ce14bcdea7b8a3d0c9d278ef}

#### `public inline virtual `[`Weight`](#classWeight)` `[`make`](#classViterbiWeight_1a8b4676e41a4edb2cc5466d1e8cb1059a)`(double v) const` {#classViterbiWeight_1a8b4676e41a4edb2cc5466d1e8cb1059a}

factory.

#### Returns
a weight of same type as this letter, initialized with given value.

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_zero`](#classViterbiWeight_1af7655a0c00c0af95699e186ceec25a7e)`() const` {#classViterbiWeight_1af7655a0c00c0af95699e186ceec25a7e}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public inline virtual `[`Weight`](#classWeight)` `[`get_one`](#classViterbiWeight_1a5009d22fc226821a8dfd876ed9bd9e84)`() const` {#classViterbiWeight_1a5009d22fc226821a8dfd876ed9bd9e84}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public virtual double `[`norm`](#group__weight_1ga01383c055ca0dafc28870ecd701dbd15)`() const` {#group__weight_1ga01383c055ca0dafc28870ecd701dbd15}

#### `public virtual void `[`scalar`](#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36)`(double)` {#group__weight_1ga9b7f93efd61f58a88d9274a9e12ebe36}

#### `public virtual void `[`invert`](#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb)`()` {#group__weight_1ga1fa4dd503a5f4915df2f9c5663aeeaeb}

multiplicative inverse.

this weight must not be zero. TBR

#### `public virtual bool `[`zero`](#group__weight_1ga35f29b2dcd594cc2cfac884322095c16)`() const` {#group__weight_1ga35f29b2dcd594cc2cfac884322095c16}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde)`() const` {#group__weight_1ga31f697ce8283cf19cd1b2f9520c83cde}

this letterweight is neutral element for mult.

#### `public inline virtual bool `[`hasType`](#classViterbiWeight_1a115d43704bf01603dad9cda0d28292bf)`(std::string code) const` {#classViterbiWeight_1a115d43704bf01603dad9cda0d28292bf}

#### `protected double `[`_val`](api-weight.md#classViterbiWeight_1a0e70b1bda371ba1887ea71e5ff5f91bf) {#classViterbiWeight_1a0e70b1bda371ba1887ea71e5ff5f91bf}

#### `protected  `[`ViterbiWeight`](#group__weight_1gaf4e626612999673b8e4e0a322119402c)`(double)` {#group__weight_1gaf4e626612999673b8e4e0a322119402c}

default is one

#### `protected virtual bool `[`equal`](#group__weight_1ga96f4c23e4845b232451e99b648bddfd6)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga96f4c23e4845b232451e99b648bddfd6}

rhs must be a [ViterbiWeight](#classViterbiWeight).

#### `protected virtual bool `[`smaller`](#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1)`(const `[`LetterWeight`](#classLetterWeight)` * rhs) const` {#group__weight_1ga54f4048f888a9432f02bc0d9f25257c1}

rhs must be a [ViterbiWeight](#classViterbiWeight).

#### `protected virtual void `[`add`](#group__weight_1ga009b0216c58308f81497e4aabe49aaed)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga009b0216c58308f81497e4aabe49aaed}

sum is min.

#### Parameters
* `rhs` must be a [ViterbiWeight](#classViterbiWeight). set this to the min of this and rhs.

#### `protected virtual void `[`mult`](#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635)`(const `[`LetterWeight`](#classLetterWeight)` * rhs)` {#group__weight_1ga842377ca8ad5fa73cc9787fa97e88635}

product is sum.

#### Parameters
* `rhs` must be a [ViterbiWeight](#classViterbiWeight). set this to the sum of this and rhs.

#### `protected virtual void `[`print`](#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51)`(std::ostream &) const` {#group__weight_1gad54ea0c48179932f2b8e553f5e3ade51}

# class `LetterWeight` {#classLetterWeight}

abstract class for concrete weight values. Every concrete weight domain must be a derived class of [LetterWeight](#classLetterWeight).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LetterWeight`](#classLetterWeight_1a2f9af55d38b8e7fd73af6cbbcb50971c)`()` | should not happen.
`public inline  `[`LetterWeight`](#classLetterWeight_1adaab28cd9be9b7ef9164bf3b33c58815)`(const `[`LetterWeight`](#classLetterWeight)` &)` | 
`public inline virtual  `[`~LetterWeight`](#classLetterWeight_1a953daf9c03224b05f6e4deae78100e53)`()` | virtual destructor to ensure correct destruction of derived objects through a pointer to base [Weight](api-weight.md#classWeight) object.
`public inline `[`LetterWeight`](#classLetterWeight)` & `[`operator=`](#classLetterWeight_1a5f8b1c03c2f08be2728ee7638b5cee3d)`(const `[`LetterWeight`](#classLetterWeight)` &)` | 
`public `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#classLetterWeight_1a23cdcf32e0f0782dbb33b2a65cf9de77)`() const` | 
`public `[`Weight`](#classWeight)` `[`make`](#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)`(double v) const` | factory.
`public `[`Weight`](#classWeight)` `[`get_zero`](#classLetterWeight_1a5caa3123e7b1ac3369c30e33f511a554)`() const` | return the neutral element for add (absorbing element for mult) wrapped in a [Weight](api-weight.md#classWeight).
`public `[`Weight`](#classWeight)` `[`get_one`](#classLetterWeight_1a4660750188a19b63b24569b6a584a5ca)`() const` | return the neutral element for mult wrapped in a [Weight](api-weight.md#classWeight).
`public double `[`norm`](#classLetterWeight_1a6ec9398f9fc437e222207644056fb4de)`() const` | 
`public void `[`scalar`](#classLetterWeight_1aef0e684851ba69336a3e86c93c5a6a58)`(double)` | 
`public void `[`invert`](#classLetterWeight_1a76a013deb82c8c1511cb6a68e5a06218)`()` | multiplicative inverse, for semifields.
`public virtual bool `[`zero`](#group__weight_1gabaad113da06b47c4b291558d05da6aa6)`() const` | this letterweight is neutral element for add (absorbing element for mult).
`public virtual bool `[`one`](#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0)`() const` | this letterweight is neutral element for mult.
`public bool `[`hasType`](#classLetterWeight_1a7c087b5999657545934b72660928a2ee)`(std::string) const` | 
`protected virtual bool `[`equal`](#group__weight_1gaf00322921db3c5212f8d5ca63081d689)`(const `[`LetterWeight`](#classLetterWeight)` *) const` | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual bool `[`smaller`](#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2)`(const `[`LetterWeight`](#classLetterWeight)` *) const` | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual void `[`add`](#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8)`(const `[`LetterWeight`](#classLetterWeight)` *)` | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual void `[`mult`](#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01)`(const `[`LetterWeight`](#classLetterWeight)` *)` | binary operators are defined only between descendant LetterWeights of same typeid.
`protected virtual void `[`print`](#group__weight_1gabef24fcc2eb0c72c420e83e6db625545)`(std::ostream & o) const` | 

## Members

#### `public inline  `[`LetterWeight`](#classLetterWeight_1a2f9af55d38b8e7fd73af6cbbcb50971c)`()` {#classLetterWeight_1a2f9af55d38b8e7fd73af6cbbcb50971c}

should not happen.

#### `public inline  `[`LetterWeight`](#classLetterWeight_1adaab28cd9be9b7ef9164bf3b33c58815)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#classLetterWeight_1adaab28cd9be9b7ef9164bf3b33c58815}

#### `public inline virtual  `[`~LetterWeight`](#classLetterWeight_1a953daf9c03224b05f6e4deae78100e53)`()` {#classLetterWeight_1a953daf9c03224b05f6e4deae78100e53}

virtual destructor to ensure correct destruction of derived objects through a pointer to base [Weight](#classWeight) object.

#### `public inline `[`LetterWeight`](#classLetterWeight)` & `[`operator=`](#classLetterWeight_1a5f8b1c03c2f08be2728ee7638b5cee3d)`(const `[`LetterWeight`](#classLetterWeight)` &)` {#classLetterWeight_1a5f8b1c03c2f08be2728ee7638b5cee3d}

#### `public `[`LetterWeight`](#classLetterWeight)` * `[`clone`](#classLetterWeight_1a23cdcf32e0f0782dbb33b2a65cf9de77)`() const` {#classLetterWeight_1a23cdcf32e0f0782dbb33b2a65cf9de77}

#### `public `[`Weight`](#classWeight)` `[`make`](#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)`(double v) const` {#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1}

factory.

#### Returns
a weight of same type as this letter, initialized with given value.

#### `public `[`Weight`](#classWeight)` `[`get_zero`](#classLetterWeight_1a5caa3123e7b1ac3369c30e33f511a554)`() const` {#classLetterWeight_1a5caa3123e7b1ac3369c30e33f511a554}

return the neutral element for add (absorbing element for mult) wrapped in a [Weight](#classWeight).

#### `public `[`Weight`](#classWeight)` `[`get_one`](#classLetterWeight_1a4660750188a19b63b24569b6a584a5ca)`() const` {#classLetterWeight_1a4660750188a19b63b24569b6a584a5ca}

return the neutral element for mult wrapped in a [Weight](#classWeight).

#### `public double `[`norm`](#classLetterWeight_1a6ec9398f9fc437e222207644056fb4de)`() const` {#classLetterWeight_1a6ec9398f9fc437e222207644056fb4de}

#### `public void `[`scalar`](#classLetterWeight_1aef0e684851ba69336a3e86c93c5a6a58)`(double)` {#classLetterWeight_1aef0e684851ba69336a3e86c93c5a6a58}

#### `public void `[`invert`](#classLetterWeight_1a76a013deb82c8c1511cb6a68e5a06218)`()` {#classLetterWeight_1a76a013deb82c8c1511cb6a68e5a06218}

multiplicative inverse, for semifields.

#### `public virtual bool `[`zero`](#group__weight_1gabaad113da06b47c4b291558d05da6aa6)`() const` {#group__weight_1gabaad113da06b47c4b291558d05da6aa6}

this letterweight is neutral element for add (absorbing element for mult).

#### `public virtual bool `[`one`](#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0)`() const` {#group__weight_1ga53200866c20ae5e4aae7ab8acd8f3ad0}

this letterweight is neutral element for mult.

#### `public bool `[`hasType`](#classLetterWeight_1a7c087b5999657545934b72660928a2ee)`(std::string) const` {#classLetterWeight_1a7c087b5999657545934b72660928a2ee}

#### `protected virtual bool `[`equal`](#group__weight_1gaf00322921db3c5212f8d5ca63081d689)`(const `[`LetterWeight`](#classLetterWeight)` *) const` {#group__weight_1gaf00322921db3c5212f8d5ca63081d689}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual bool `[`smaller`](#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2)`(const `[`LetterWeight`](#classLetterWeight)` *) const` {#group__weight_1ga0ef9dd9bcd765c0e3c50b384b34d88d2}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual void `[`add`](#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8)`(const `[`LetterWeight`](#classLetterWeight)` *)` {#group__weight_1ga49b09c8f364a2ebf1d154f606d9aaea8}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual void `[`mult`](#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01)`(const `[`LetterWeight`](#classLetterWeight)` *)` {#group__weight_1gad1208e74e54ca8fc2f361e6fc106df01}

binary operators are defined only between descendant LetterWeights of same typeid.

#### `protected virtual void `[`print`](#group__weight_1gabef24fcc2eb0c72c420e83e6db625545)`(std::ostream & o) const` {#group__weight_1gabef24fcc2eb0c72c420e83e6db625545}

# class `Weight` {#classWeight}

A class of polymorphic weight domains for tree series.

Every concrete weight domain must be a derived class of [Weight](#classWeight).

the type [Weight](#classWeight) is the union of an unknown weight value and different weight domain.

it is implemented as an envelope, containing either

* a null letter. in this case, we have an unknown weight value.

* a non-null letter, pointing to an object of a derived weight class (concrete weight). In this case, the envelope is a wrapper for the object of the derived class, corresponding to an actual (known) weight value. see Envelope Letter Idiom (wikibooks)

Client code only uses the [Weight](#classWeight) class (not the derived classes), except for allocation of new concrete weights values by [Weight(new DerivedWeight(...))](#classWeight)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Weight`](#classWeight_1ac33fb795eaee8c56d2e4179020a0d2eb)`(`[`LetterWeight`](#classLetterWeight)` * w)` | wrapper and unknown weight constructor (empty envelope, default).
`public  `[`Weight`](#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c)`(const `[`Weight`](#classWeight)` & w)` | clone the letter.
`public  `[`~Weight`](#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f)`()` | 
`public `[`Weight`](#classWeight)` & `[`operator=`](#group__weight_1ga548aadee137a6c274aeb1e56607b05dd)`(const `[`Weight`](#classWeight)` &)` | 
`public inline `[`LetterWeight`](#classLetterWeight)` * `[`operator->`](#classWeight_1a6b38fd1721594ffc303858e6201d1b2b)`() const` | must not be unknown
`public `[`Weight`](#classWeight)` * `[`clone`](#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed)`() const` | 
`public bool `[`unknown`](#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47)`() const` | unknown weight is a [Weight](api-weight.md#classWeight) with NULL letter.
`public `[`Weight`](#classWeight)` `[`make`](#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729)`(double v) const` | **See also**: [LetterWeight.make](api-weight.md#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)
`public bool `[`hasType`](#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35)`(std::string code) const` | #### Parameters
`public double `[`norm`](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)`()` | this [Weight](#classWeight) must not be unknown (letter != NULL) 
`public void `[`scalar`](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)`(double)` | scalar multiplication.
`public bool `[`zero`](#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61)`() const` | this weight is neutral element for + (absorbing element for *).
`public `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55)`() const` | return the neutral element for add (absorbing element for mult) for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).
`public inline void `[`operator+=`](#classWeight_1a840aea7512916a91b6baf0a0772b46db)`(const `[`Weight`](#classWeight)` & rhs)` | **See also**: [add](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)
`public bool `[`one`](#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6)`() const` | this weight is neutral element for *
`public `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga48012227b61aa4c10064bed70936d78e)`() const` | return the neutral element for mult for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).
`public inline void `[`operator*=`](#classWeight_1a4968f430abd50a0eaea15d01422ef0bb)`(const `[`Weight`](#classWeight)` & rhs)` | **See also**: [mult](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)
`public void `[`invert`](#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28)`()` | multiplicative inverse, for semifields
`public void `[`clear`](#group__weight_1gaace5b230ea1544aac7b049091e142bd3)`()` | delete the letter.
`public std::string `[`save_to_string`](#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8)`()` | 
`protected `[`LetterWeight`](#classLetterWeight)` * `[`_letter`](#classWeight_1a01c1d2af2914d5429696a79f891318ea) | letter always points to an object of one of the derived *Weight classes never to an object of the [Weight](api-weight.md#classWeight) base class.
`protected bool `[`equal`](#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e)`(const `[`Weight`](#classWeight)` & rhs) const` | binary operators are defined only between descendant Weights of same typeid
`protected bool `[`smaller`](#group__weight_1gab3a3a5fb989514e5673582b9a7107d97)`(const `[`Weight`](#classWeight)` & rhs) const` | * unknown [Weight](api-weight.md#classWeight) is minimal:
`protected void `[`add`](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)`(const `[`Weight`](#classWeight)` & rhs)` | this and rhs must not be unknown
`protected void `[`mult`](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)`(const `[`Weight`](#classWeight)` & rhs)` | this and rhs must not be unknown
`protected void `[`print`](#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60)`(std::ostream & o) const` | 

## Members

#### `public inline  `[`Weight`](#classWeight_1ac33fb795eaee8c56d2e4179020a0d2eb)`(`[`LetterWeight`](#classLetterWeight)` * w)` {#classWeight_1ac33fb795eaee8c56d2e4179020a0d2eb}

wrapper and unknown weight constructor (empty envelope, default).

#### `public  `[`Weight`](#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c)`(const `[`Weight`](#classWeight)` & w)` {#group__weight_1ga9283a1d2c4b91605a0c60a2c7033cb2c}

clone the letter.

#### `public  `[`~Weight`](#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f)`()` {#group__weight_1gaf09ef86cb7c7b833cd3ea327f153543f}

#### `public `[`Weight`](#classWeight)` & `[`operator=`](#group__weight_1ga548aadee137a6c274aeb1e56607b05dd)`(const `[`Weight`](#classWeight)` &)` {#group__weight_1ga548aadee137a6c274aeb1e56607b05dd}

#### `public inline `[`LetterWeight`](#classLetterWeight)` * `[`operator->`](#classWeight_1a6b38fd1721594ffc303858e6201d1b2b)`() const` {#classWeight_1a6b38fd1721594ffc303858e6201d1b2b}

must not be unknown

#### `public `[`Weight`](#classWeight)` * `[`clone`](#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed)`() const` {#group__weight_1gade2f7d7b4ddf749326fb0a6c674387ed}

#### `public bool `[`unknown`](#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47)`() const` {#group__weight_1ga2185b6a5b1957fcab19bf6281adeed47}

unknown weight is a [Weight](#classWeight) with NULL letter.

#### `public `[`Weight`](#classWeight)` `[`make`](#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729)`(double v) const` {#group__weight_1gaf8f62c5cee5ffa37e30ef7239a33b729}

**See also**: [LetterWeight.make](#classLetterWeight_1af1f898e0845f59299440fc50a58fd2f1)

#### `public bool `[`hasType`](#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35)`(std::string code) const` {#group__weight_1gad236331c6f6ca8dd9fced5ffffd79f35}

#### Parameters
* `code` is the code of the letter weight if there is one or "UNKNOWN" otherwise.

#### `public double `[`norm`](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)`()` {#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4}

this [Weight](#classWeight) must not be unknown (letter != NULL) 

not const: may need recomputations.

#### `public void `[`scalar`](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)`(double)` {#group__weight_1ga5d63ead0a1d21ee5628c643fca773903}

scalar multiplication.

this [Weight](#classWeight) must not be unknown (letter != NULL).

#### `public bool `[`zero`](#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61)`() const` {#group__weight_1gad0c93ac5f963b02ca3f6c1d5d02f5d61}

this weight is neutral element for + (absorbing element for *).

#### `public `[`Weight`](#classWeight)` `[`get_zero`](#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55)`() const` {#group__weight_1gaf7214d45d290b39f6bb2555fc46adf55}

return the neutral element for add (absorbing element for mult) for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).

#### `public inline void `[`operator+=`](#classWeight_1a840aea7512916a91b6baf0a0772b46db)`(const `[`Weight`](#classWeight)` & rhs)` {#classWeight_1a840aea7512916a91b6baf0a0772b46db}

**See also**: [add](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)

#### `public bool `[`one`](#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6)`() const` {#group__weight_1ga0fb0a47475e245e955aa6e7926f7a0f6}

this weight is neutral element for *

#### `public `[`Weight`](#classWeight)` `[`get_one`](#group__weight_1ga48012227b61aa4c10064bed70936d78e)`() const` {#group__weight_1ga48012227b61aa4c10064bed70936d78e}

return the neutral element for mult for the [LetterWeight](#classLetterWeight), if any otherwise return unknown [Weight](#classWeight).

#### `public inline void `[`operator*=`](#classWeight_1a4968f430abd50a0eaea15d01422ef0bb)`(const `[`Weight`](#classWeight)` & rhs)` {#classWeight_1a4968f430abd50a0eaea15d01422ef0bb}

**See also**: [mult](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)

#### `public void `[`invert`](#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28)`()` {#group__weight_1gabc3309e134f0fdda38ebbcb12d350a28}

multiplicative inverse, for semifields

this [Weight](#classWeight) must not be zero 

this [Weight](#classWeight) must not be unknown (letter != NULL)

TBR : replace by div with const rhs

#### `public void `[`clear`](#group__weight_1gaace5b230ea1544aac7b049091e142bd3)`()` {#group__weight_1gaace5b230ea1544aac7b049091e142bd3}

delete the letter.

this weight becomes unknown.

#### `public std::string `[`save_to_string`](#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8)`()` {#group__weight_1gaeb6c4f1cf187978576df2bc31a5e5eb8}

#### `protected `[`LetterWeight`](#classLetterWeight)` * `[`_letter`](#classWeight_1a01c1d2af2914d5429696a79f891318ea) {#classWeight_1a01c1d2af2914d5429696a79f891318ea}

letter always points to an object of one of the derived *Weight classes never to an object of the [Weight](#classWeight) base class.

#### `protected bool `[`equal`](#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e)`(const `[`Weight`](#classWeight)` & rhs) const` {#group__weight_1ga11236e38c2dc7cc66a367c2ea5921c1e}

binary operators are defined only between descendant Weights of same typeid

* two unknown Weights are equal

* one unknown weight and one not unknown are not equal

* equality of two not unknown weight depends on the descendant class

#### `protected bool `[`smaller`](#group__weight_1gab3a3a5fb989514e5673582b9a7107d97)`(const `[`Weight`](#classWeight)` & rhs) const` {#group__weight_1gab3a3a5fb989514e5673582b9a7107d97}

* unknown [Weight](#classWeight) is minimal:

* unknown [Weight](#classWeight) is smaller than any not unknown [Weight](#classWeight)

* not unknown [Weight](#classWeight) is not smaller that unknown [Weight](#classWeight)

* unknown [Weight](#classWeight) is not smaller than unknown [Weight](#classWeight)

* inequality of two not unknown weight depends on the descendant class

#### `protected void `[`add`](#group__weight_1ga261db18abff49cac38bd02b8f7af94db)`(const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga261db18abff49cac38bd02b8f7af94db}

this and rhs must not be unknown

#### `protected void `[`mult`](#group__weight_1ga7188f571e507d7f31b76de7faebdb78f)`(const `[`Weight`](#classWeight)` & rhs)` {#group__weight_1ga7188f571e507d7f31b76de7faebdb78f}

this and rhs must not be unknown

#### `protected void `[`print`](#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60)`(std::ostream & o) const` {#group__weight_1ga0f92a47af6c72b59183835d0b11a3d60}

