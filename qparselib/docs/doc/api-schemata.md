# group `schemata` {#group__schemata}

The `schemata` module contains classes of weighted tree automata used for parsing.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::ostream & `[`operator<<`](#group__schemata_1gaacfb8dd676081cbdacc586bd08ef5339)`(std::ostream & o,const `[`ComboState`](#classComboState)` & cs)`            | 
`public bool `[`trcomp`](#group__schemata_1ga5876dc1d6e1700ecd64b79abc371f852)`(std::pair< state_t, `[`Transition`](#classTransition)` &> lhs,std::pair< state_t, `[`Transition`](#classTransition)` &> rhs)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1gaf522606427f33e50d5ccd45945e140ac)`(std::ostream & o,const `[`CountingWTA`](#classCountingWTA)` & a)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1gaf8b99aabcea05e6f7f8b31da07ee3790)`(std::ostream & o,const `[`PreState`](#classPreState)` & ps)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1ga9bf0c703002e360545ebd943f933fb18)`(std::ostream & o,const `[`PreWTA`](#classPreWTA)` & a)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1gaf1cd2ec3c46754e845d9083fcca78307)`(std::ostream & o,const `[`Transition`](#classTransition)` & t)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1ga3e1e0cf974d650010f69166d22e7d0da)`(std::ostream & o,const `[`ValueState`](#classValueState)` & vs)`            | 
`public size_t `[`gcd`](#group__schemata_1ga83eaab443b166582ff8beee576b4fd51)`(size_t a,size_t b)`            | 
`public size_t `[`lcm`](#group__schemata_1ga21cc98547ba237fc676751c60c220415)`(size_t a,size_t b)`            | 
`public std::ostream & `[`operator<<`](#group__schemata_1gab750ab8b8fe56baba66c96e38398b632)`(std::ostream & o,const `[`WTA`](#classWTA)` & a)`            | 
`public  `[`ComboState`](#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` *)`            | 
`public  `[`ComboState`](#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1)`(state_t,`[`IntervalTree`](#classIntervalTree)` *,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)`            | 
`public  `[`ComboState`](#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39)`(const `[`ComboState`](#classComboState)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)`            | 
`public  `[`~ComboState`](#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6)`()`            | 
`public bool `[`compatible`](#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const`            | 
`public bool `[`operator==`](#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395)`(const `[`ComboState`](#classComboState)` & s) const`            | 
`public bool `[`operator<`](#group__schemata_1ga505e9ff93681bbfe5632a15708facb63)`(const `[`ComboState`](#classComboState)` & s) const`            | lexicographic comparison on hash value (array[5])
`private state_t `[`addComboState`](#group__schemata_1gae3bbd0756c7a72efc67e5085fc8be63b)`(const `[`ComboState`](#classComboState)` & cs,bool initial)`            | returns the [ComboWTA](#classComboWTA) state s associated to the [ComboState](#classComboState) cs if there exists one. otherwise:
`public virtual state_t `[`initial`](#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const`            | state representing the whole segment.
`public  `[`ComboWTA`](#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7)`(const `[`InputSegment`](#classInputSegment)` *,size_t bloc,const `[`WTA`](#classWTA)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre)`            | construction from input segment and [WTA](#classWTA) (base schema) with given max pre value and bloc number (in input segment, for alignement).
`public  `[`CountingWTA`](#group__schemata_1gad46a7f821d01aed3719a585f66130e27)`()`            | default initializer for cython
`public  `[`CountingWTA`](#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093)`(const `[`WTA`](#classWTA)` & a)`            | copy base [WTA](#classWTA) reset weight values to counting weights (unit vectors)
`protected void `[`resetCounting`](#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0)`(size_t dim)`            | the weight of this [WTA](#classWTA) are replaced by "CountingWeight" unit vector of length dim (one unit per transition)
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f)`(const `[`RhythmTree`](#classRhythmTree)` & t) const`            | special version of eval for [CountingWeight](api-weight.md#classCountingWeight) with feedback in case of fail
`protected `[`Weight`](#classWeight)` `[`evalCountingVerbose`](#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3)`(const `[`RhythmTree`](#classRhythmTree)` &,state_t,`[`Position`](#classPosition)`) const`            | 
`public  `[`PreState`](#group__schemata_1gad02325f302e819ab93c8a501674b4bf4)`()`            | 
`public  `[`PreState`](#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8)`(state_t,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)`            | 
`public  `[`PreState`](#group__schemata_1gabc0c5bcc094646426f0a90313808907b)`(const `[`PreState`](#classPreState)` &)`            | 
`public  `[`~PreState`](#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec)`()`            | 
`private void `[`rehash`](#group__schemata_1ga5f379ef9372d48f4992a6c4c948b8a5b)`()`            | 
`public bool `[`operator==`](#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d)`(const `[`PreState`](#classPreState)` & s) const`            | 
`public bool `[`operator<`](#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b)`(const `[`PreState`](#classPreState)` & s) const`            | lexicographic comparison on hash value (array[5])
`public state_t `[`serialize`](#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4)`()`            | return a state value unically associated to this [PreState](api-schemata.md#classPreState)
`public bool `[`compatible`](#group__schemata_1gab947b64699704a087db2eda3eb47575d)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const`            | 
`public static bool `[`compatible_post`](#group__schemata_1gaa509247277fd021460056bfe6484a5b4)`(state_t,const `[`AlignedInterval`](#classAlignedInterval)` *)`            | compatible(s, al) the serialized state value s is compatible with the content of the alignment al (sub-segment of initial input corr. to an interval)
`public  `[`PreWTA`](#group__schemata_1ga6287aa82de69987b65518b4997112ac5)`(const `[`WTA`](#classWTA)` &)`            | construction from [WTA](#classWTA) (base schema)
`public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#group__schemata_1gaab30a1faaa381ecfabd705a8c12d179b)`(state_t)`            | access to original components of new [PreWTA](api-schemata.md#classPreWTA) states
`public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#group__schemata_1ga2c8c24b19312ad6436eaf76e4506e02f)`(state_t)`            | 
`public static state_t `[`state`](#group__schemata_1ga3e74404d5f453b8eed85254791724ffe)`(state_t)`            | 
`private state_t `[`addPreState`](#group__schemata_1gaf528dddbe05e879324558a4518738b2d)`(const `[`PreState`](#classPreState)` &)`            | addPreState(ps) returns the [PreWTA](#classPreWTA) state s associated to the [PreState](#classPreState) ps if there exists one. otherwise: a new [PreWTA](#classPreWTA) state s is created, s is associated to cs, s is added to the table the [PreWTA](#classPreWTA) transitions with head s are computed and added to the table s is returned moreover, the state is added to the initial state set of the [PreWTA](#classPreWTA) if the state component of ps is initial.
`public virtual state_t `[`initial`](#group__schemata_1gaf47213e6243f48f06681089e03fa08ef)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const`            | initial(pre, port) returns state representing the whole segment, with pre points of the previous segment aligned to the left and post points of the current segment aligned to the right (i.e. to the left of the next segment)
`public bool `[`isMeta`](#group__schemata_1gaa5b5cf5f92a0c443d4c1a1e152f9292c)`(state_t)`            | 
`public bool `[`isWTA`](#group__schemata_1ga1722ba39591c8a25ed5ee91e9e91232a)`(state_t)`            | 
`public bool `[`isLabel`](#group__schemata_1gabd744185c22c686d1c95d74523a007b3)`(state_t)`            | 
`public state_t `[`MetaState`](#group__schemata_1ga0ffeaad4a7482bc302dce44a23a85a6e)`(size_t barnb)`            | Meta state corresponding to bar nb barnb.
`public void `[`rename`](#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b)`(unsigned int s,unsigned int u)`            | 
`public void `[`shift`](#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84)`(unsigned int n)`            | increase source and target state by n
`public void `[`shift0`](#group__schemata_1ga811afd94c0a2afda729115e1afade496)`(unsigned int n)`            | increase source and target state by n, if they are not 0
`public  `[`dagSchema`](#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27)`(const `[`ANode`](#classANode)` &)`            | translation of AND-OR alternating nested lists into dag-schemas
`public  `[`dagSchema`](#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8)`(const `[`ONode`](#classONode)` &)`            | 
`public void `[`add`](#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20)`(const `[`ds_transition`](#structds__transition)` & dst)`            | for testing. do not use
`private void `[`rename`](#group__schemata_1ga5d904f7412e4bd1263f5369115f910d3)`(unsigned int i,unsigned int j)`            | rename state i into state j
`private void `[`shift`](#group__schemata_1ga942b88d2618ccf43acea8b95cd34d96d)`(unsigned int n)`            | rename every state s into s + n the result is not a dag-schema
`private void `[`shift0`](#group__schemata_1gaeb6128c3a43d7b6fa5996e8830b4860a)`(unsigned int n)`            | rename every state s into s + n except 0
`public  `[`Transition`](#group__schemata_1ga73b44b2338b11807f77b620a3e810f92)`()`            | transition with unknown weight and empty body.
`public  `[`Transition`](#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71)`(const `[`Weight`](#classWeight)` &)`            | [Transition(w)](api-schemata.md#classTransition) creates a transition with weight a copy of w and empty body.
`public  `[`Transition`](#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de)`(`[`LetterWeight`](#classLetterWeight)` *)`            | [Transition(lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null)
`public  `[`Transition`](#group__schemata_1gad126f7c68acac0315b1782decaf54d3b)`(std::vector< state_t >,const `[`Weight`](#classWeight)` &)`            | [Transition(v, w)](api-schemata.md#classTransition) creates a transition with weight a copy of w and body a copy of the vector v.
`public  `[`Transition`](#group__schemata_1ga50836c0d84b3968b9ceb968521418e22)`(std::vector< state_t >,`[`LetterWeight`](#classLetterWeight)` *)`            | [Transition(v, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body a copy of the vector v.
`public  `[`Transition`](#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5)`(state_t,const `[`Weight`](#classWeight)` &)`            | [Transition(s, w)](#classTransition) creates a transition with weight a copy of w and body (of size 1) the singleton (s) (terminal symbol).
`public  `[`Transition`](#group__schemata_1ga458b953211e3b5de292c8c1535ff7281)`(state_t,`[`LetterWeight`](#classLetterWeight)` *)`            | [Transition(s, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body (of size 1) the singleton (s) (terminal symbol).
`public  `[`~Transition`](#group__schemata_1gab66e8623f23c71cd4f07c69596427bab)`()`            | 
`public bool `[`inner`](#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084)`() const`            | 
`public bool `[`terminal`](#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd)`() const`            | 
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__schemata_1ga97dce48d13fac75a4a444a68aae07608)`() const`            | this transition must be terminal
`public void `[`scalar`](#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7)`(double)`            | modify weight of transition.
`public void `[`invert`](#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0)`()`            | 
`public size_t `[`size`](#group__schemata_1ga743ca128dc509e129a49d66500a0f151)`() const`            | size of body.
`public size_t `[`arity`](#group__schemata_1gad6ae5de36df4526b83bf7af59d178066)`() const`            | 
`public state_t `[`at`](#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec)`(size_t i) const`            | at(i) returns the ith state in the body.
`public void `[`push`](#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf)`(state_t)`            | add given state at the end of the body of this transition.
`public bool `[`member`](#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8)`(state_t) const`            | whether the given state belongs to the body of this transition.
`public bool `[`allin`](#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11)`(const std::set< state_t > &) const`            | every state of the body is in the given set.
`public bool `[`nonein`](#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276)`(const std::set< state_t > &) const`            | no state of the body is in the given set.
`public  `[`ValueState`](#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf)`(state_t,`[`DurationTree`](#classDurationTree)` *)`            | 
`public  `[`~ValueState`](#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb)`()`            | 
`public bool `[`compatible`](#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const`            | 
`public bool `[`operator==`](#group__schemata_1ga8e4a967143877229169d6c28842185c8)`(const `[`ValueState`](#classValueState)` & s) const`            | 
`private state_t `[`addValueState`](#group__schemata_1ga074f48ad3b6e8f357ca5bf5dce242b18)`(const `[`ValueState`](#classValueState)` &,bool initial)`            | returns the [ValueWTA](#classValueWTA) state associated to the [ValueState](#classValueState) vs if there exists one. otherwise:
`public  `[`ValueWTA`](#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f)`(const `[`DurationList`](#classDurationList)` &,const `[`WTA`](#classWTA)` &)`            | construction from given initial list and [WTA](#classWTA) (base schema)
`public  `[`~TransitionList`](#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe)`()`            | 
`public bool `[`empty`](#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2)`() const`            | zero transition
`public size_t `[`size`](#group__schemata_1gaa719dbdab17047360e889910795a07f2)`() const`            | number of transitions.
`public void `[`add`](#group__schemata_1gadc77b77a90197483168626230fe4dbf4)`(const `[`Transition`](#classTransition)` &)`            | 
`public void `[`clear`](#group__schemata_1ga2f4181b350f6dec7054072fcf2095834)`()`            | 
`public void `[`remove`](#group__schemata_1gad9709d189b3748d2285f2a3592bed2da)`(TransitionList_iterator)`            | 
`public void `[`remove`](#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c)`(state_t)`            | remove all transitions of length > 1 in the list containing the given state do not remove length 1 transitions to terminal symbols
`public  `[`WTA`](#group__schemata_1ga5636da911ebbe8772c5444172d56800d)`()`            | nullary constructor for cython
`public  `[`WTA`](#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca)`(`[`Weight`](#classWeight)` seed,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)`            | empty automaton
`public  `[`~WTA`](#group__schemata_1gaacdee6c2292baea7f712c84a5e205432)`()`            | 
`public size_t `[`size`](#group__schemata_1gab201fee50d73843159cbef5f453838f0)`() const`            | number of states
`public bool `[`empty`](#group__schemata_1gada977ff7270308f29852b59f38965bde)`() const`            | 
`public bool `[`isRegistered`](#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58)`(state_t) const`            | the state is present in the automaton
`public bool `[`isInitial`](#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6)`(state_t) const`            | the state is an initial state TBR
`public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga924a1c533383a7185b9d466b59c5a495)`(state_t,bool initial)`            | add(s, i) register state s if s was already registered, return a reference to its transition list. otherwise, create state s with an empty transition list and returns a reference to it. moreover s is set as initial if i = true. TODO suppr. flag initial
`public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2)`(state_t,const `[`Transition`](#classTransition)` &,bool initial)`            | add(s, t) add a transition with head s and with body/weight described in t if s was not registered, it is registered the transition t is added to the transition list of s and a reference to this transition list is returned moreover s is set as initial if i = true. TODO suppr. flag initial
`public void `[`remove`](#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf)`(state_t)`            | remove the entry for given state s in the table of the table i.e. all transitions targeted to s, and all the transitions with s in their body. if s was in the initial set, it is also removed from this set. s must be registered.
`public TransitionList_const_iterator `[`begin`](#group__schemata_1ga23c3f9884c683e4bbab323208e08c672)`(state_t) const`            | begin(s) returns an iterator pointing to the first transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.
`public TransitionList_const_iterator `[`end`](#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5)`(state_t) const`            | begin(s) returns an iterator pointing to the past-the-end transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.
`public size_t `[`countStates`](#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915)`() const`            | number of states
`public size_t `[`countTransitions`](#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a)`() const`            | number of transition
`public size_t `[`countAll`](#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7)`() const`            | number of symbols (state occurences)
`public size_t `[`oftarget`](#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8)`(state_t) const`            | oftarget(s) return the number of transitions of head state s. s must be registered.
`public size_t `[`resolution`](#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4)`() const`            | 
`protected std::set< state_t > `[`step`](#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc)`(const std::set< state_t > &)`            | step(s) returns the set of states reachable in one transition step by this [WTA](api-schemata.md#classWTA) from the given state set s. all the states in the set s must be registered.
`protected std::set< state_t > `[`allStates`](#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d)`() const`            | returns the set of all states occuring in wta (in head or body)
`public std::set< state_t > `[`emptyStates`](#group__schemata_1gaea41b32c37bbe955d0359039d7731fea)`() const`            | returns the set of all non-inhabited (zero weight) states in wta
`public bool `[`isClean`](#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202)`() const`            | the [WTA](api-schemata.md#classWTA) has no empty states
`public void `[`clean`](#group__schemata_1gaec169477bdc2cf883916c38dbc18e577)`()`            | remove states not inhabited and transitions containing these states
`public void `[`abstract`](#group__schemata_1ga91e272f4f9463149cd296f48e65a4185)`(bool flag)`            | abstract the leaf label values in domain [0..MAX_GRACE] every value > MAX_GRACE is casted to MAX_GRACE the weights are summed accordingly
`public void `[`CountingtoStochastic`](#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7)`()`            | cast weights in all transitions.
`public void `[`CountingtoPenalty`](#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a)`()`            | cast weights in all transitions.
`public void `[`PenaltytoCounting`](#group__schemata_1gaff1196a45ffd1400bc4004e27b167218)`()`            | cast weights in all transitions.
`public void `[`StochastictoPenalty`](#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5)`()`            | cast weights in all transitions.
`public bool `[`hasWeightType`](#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b)`(std::string code) const`            | return wether the weights in transition have the type of the code (code of the letter weight if there is one or "UNKNOWN" otherwise).
`public virtual `[`Weight`](#classWeight)` `[`weight_zero`](#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6)`() const`            | return the 0 value in the weight domain in this [WTA](api-schemata.md#classWTA)
`public virtual `[`Weight`](#classWeight)` `[`weight_one`](#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd)`() const`            | return the 1 value in the weight domain in this [WTA](api-schemata.md#classWTA)
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gaa6598176fb91c70988bea7cf824ec157)`(const `[`RhythmTree`](#classRhythmTree)` & t) const`            | evaluate the weight of the tree t for [WTA](api-schemata.md#classWTA) in initial state
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gac842f196f85e3c3b079c7c0992173e46)`(const `[`RhythmTree`](#classRhythmTree)` & t,state_t s) const`            | 
`public void `[`print`](#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06)`(std::ostream &) const`            | print sizes to output stream
`private void `[`mark_rec`](#group__schemata_1ga6b9809d53e619eb95d9ad9e668ce2b56)`(state_t,int,const `[`WTA`](#classWTA)` &)`            | 
`public  `[`DepthMarking`](#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935)`(const `[`WTA`](#classWTA)` &)`            | 
`public int `[`depth`](#group__schemata_1gaaa84e1d149651938af82e47b91888017)`(state_t) const`            | return depth mark if given state marked return -1 otherwise
`public bool `[`multiple`](#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b)`(state_t) const`            | return true if the given state can occur at multiple depths return false otherwise or if state not marked
`public int `[`mark`](#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d)`(state_t,int)`            | mark state using given depth and return new mark value can be the given depth or a greater depth with which the state had been already marked.
`class `[`ComboState`](api-schemata.md#classComboState) | tmp state structure for construction of [ComboWTA](#classComboWTA) from a [WTA](#classWTA) (base schema) and an input segment casted into state_t after construction
`class `[`ComboWTA`](api-schemata.md#classComboWTA) | [WTA](#classWTA) combo: A special kind of [WTA](#classWTA) for quantization constructed from.
`class `[`CountingWTA`](api-schemata.md#classCountingWTA) | copy of [WTA](api-schemata.md#classWTA) dedicated to corpus statistics.
`class `[`PreState`](api-schemata.md#classPreState) | tmp state structure for construction of [PreWTA](#classPreWTA) from a [WTA](#classWTA) (base schema) casted aka state_t after construction
`class `[`PreWTA`](api-schemata.md#classPreWTA) | extension of [WTA](api-schemata.md#classWTA) where states are associated pre and post values.
`class `[`AONode`](api-schemata.md#classAONode) | AND-OR alternating nested lists used by Adrien in RQ.
`class `[`ANode`](api-schemata.md#classANode) | 
`class `[`ONode`](api-schemata.md#classONode) | 
`class `[`dagSchema`](api-schemata.md#classdagSchema) | dag whose edges are labeled by arity values two distinguished nodes:
`class `[`Transition`](api-schemata.md#classTransition) | a [Transition](#classTransition) is defined by a sequence of antecedent states (body) the weight must be not null (null weight means a missing transition).
`class `[`ValueState`](api-schemata.md#classValueState) | 
`class `[`ValueWTA`](api-schemata.md#classValueWTA) | Value [WTA](#classWTA) is a special kind of [WTA](#classWTA) associated to an initial [WTA](#classWTA) (schema) and a rhythmic value ([DurationList](#classDurationList)).
`class `[`TransitionList`](api-schemata.md#classTransitionList) | 
`class `[`WTA`](api-schemata.md#classWTA) | class of schemas = weighted tree automata = weighted CFG.
`class `[`DepthMarking`](api-schemata.md#classDepthMarking) | marking of states of a [WTA](#classWTA) with informations on the depth of their occurences initialized with a [WTA](#classWTA), can be interrogated afterwards
`struct `[`ComboStateHasher`](api-schemata.md#structComboStateHasher) | 
`struct `[`ds_transition`](api-schemata.md#structds__transition) | dag schema
`struct `[`ValueStateHasher`](api-schemata.md#structValueStateHasher) | 

## Members

#### `public std::ostream & `[`operator<<`](#group__schemata_1gaacfb8dd676081cbdacc586bd08ef5339)`(std::ostream & o,const `[`ComboState`](#classComboState)` & cs)` {#group__schemata_1gaacfb8dd676081cbdacc586bd08ef5339}

#### `public bool `[`trcomp`](#group__schemata_1ga5876dc1d6e1700ecd64b79abc371f852)`(std::pair< state_t, `[`Transition`](#classTransition)` &> lhs,std::pair< state_t, `[`Transition`](#classTransition)` &> rhs)` {#group__schemata_1ga5876dc1d6e1700ecd64b79abc371f852}

#### `public std::ostream & `[`operator<<`](#group__schemata_1gaf522606427f33e50d5ccd45945e140ac)`(std::ostream & o,const `[`CountingWTA`](#classCountingWTA)` & a)` {#group__schemata_1gaf522606427f33e50d5ccd45945e140ac}

#### `public std::ostream & `[`operator<<`](#group__schemata_1gaf8b99aabcea05e6f7f8b31da07ee3790)`(std::ostream & o,const `[`PreState`](#classPreState)` & ps)` {#group__schemata_1gaf8b99aabcea05e6f7f8b31da07ee3790}

#### `public std::ostream & `[`operator<<`](#group__schemata_1ga9bf0c703002e360545ebd943f933fb18)`(std::ostream & o,const `[`PreWTA`](#classPreWTA)` & a)` {#group__schemata_1ga9bf0c703002e360545ebd943f933fb18}

#### `public std::ostream & `[`operator<<`](#group__schemata_1gaf1cd2ec3c46754e845d9083fcca78307)`(std::ostream & o,const `[`Transition`](#classTransition)` & t)` {#group__schemata_1gaf1cd2ec3c46754e845d9083fcca78307}

#### `public std::ostream & `[`operator<<`](#group__schemata_1ga3e1e0cf974d650010f69166d22e7d0da)`(std::ostream & o,const `[`ValueState`](#classValueState)` & vs)` {#group__schemata_1ga3e1e0cf974d650010f69166d22e7d0da}

#### `public size_t `[`gcd`](#group__schemata_1ga83eaab443b166582ff8beee576b4fd51)`(size_t a,size_t b)` {#group__schemata_1ga83eaab443b166582ff8beee576b4fd51}

#### `public size_t `[`lcm`](#group__schemata_1ga21cc98547ba237fc676751c60c220415)`(size_t a,size_t b)` {#group__schemata_1ga21cc98547ba237fc676751c60c220415}

#### `public std::ostream & `[`operator<<`](#group__schemata_1gab750ab8b8fe56baba66c96e38398b632)`(std::ostream & o,const `[`WTA`](#classWTA)` & a)` {#group__schemata_1gab750ab8b8fe56baba66c96e38398b632}

#### `public  `[`ComboState`](#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` *)` {#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e}

#### `public  `[`ComboState`](#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1)`(state_t,`[`IntervalTree`](#classIntervalTree)` *,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` {#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1}

#### `public  `[`ComboState`](#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39)`(const `[`ComboState`](#classComboState)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` {#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39}

#### `public  `[`~ComboState`](#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6)`()` {#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6}

#### `public bool `[`compatible`](#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929}

#### `public bool `[`operator==`](#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395)`(const `[`ComboState`](#classComboState)` & s) const` {#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395}

#### `public bool `[`operator<`](#group__schemata_1ga505e9ff93681bbfe5632a15708facb63)`(const `[`ComboState`](#classComboState)` & s) const` {#group__schemata_1ga505e9ff93681bbfe5632a15708facb63}

lexicographic comparison on hash value (array[5])

#### `private state_t `[`addComboState`](#group__schemata_1gae3bbd0756c7a72efc67e5085fc8be63b)`(const `[`ComboState`](#classComboState)` & cs,bool initial)` {#group__schemata_1gae3bbd0756c7a72efc67e5085fc8be63b}

returns the [ComboWTA](#classComboWTA) state s associated to the [ComboState](#classComboState) cs if there exists one. otherwise:

* a new [ComboWTA](#classComboWTA) state s is created,

* s is associated to cs,

* s is added to the table

* the [ComboWTA](#classComboWTA) transitions with head s are computed and added to the table

* s is returned 
#### Parameters
* `cs` given [ComboState](#classComboState)

* `initial` flag: the state constructed is added to the initial state set of the [ComboWTA](#classComboWTA) if initial=true

#### `public virtual state_t `[`initial`](#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` {#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd}

state representing the whole segment.

#### Parameters
* `pre` points of the previous segment aligned to the left 

* `post` points of the current segment aligned to the right (i.e. to the left of the next segment).

#### `public  `[`ComboWTA`](#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7)`(const `[`InputSegment`](#classInputSegment)` *,size_t bloc,const `[`WTA`](#classWTA)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre)` {#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7}

construction from input segment and [WTA](#classWTA) (base schema) with given max pre value and bloc number (in input segment, for alignement).

#### `public  `[`CountingWTA`](#group__schemata_1gad46a7f821d01aed3719a585f66130e27)`()` {#group__schemata_1gad46a7f821d01aed3719a585f66130e27}

default initializer for cython

#### `public  `[`CountingWTA`](#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093)`(const `[`WTA`](#classWTA)` & a)` {#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093}

copy base [WTA](#classWTA) reset weight values to counting weights (unit vectors)

#### `protected void `[`resetCounting`](#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0)`(size_t dim)` {#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0}

the weight of this [WTA](#classWTA) are replaced by "CountingWeight" unit vector of length dim (one unit per transition)

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` {#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f}

special version of eval for [CountingWeight](#classCountingWeight) with feedback in case of fail

#### `protected `[`Weight`](#classWeight)` `[`evalCountingVerbose`](#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3)`(const `[`RhythmTree`](#classRhythmTree)` &,state_t,`[`Position`](#classPosition)`) const` {#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3}

#### `public  `[`PreState`](#group__schemata_1gad02325f302e819ab93c8a501674b4bf4)`()` {#group__schemata_1gad02325f302e819ab93c8a501674b4bf4}

#### `public  `[`PreState`](#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8)`(state_t,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8}

#### `public  `[`PreState`](#group__schemata_1gabc0c5bcc094646426f0a90313808907b)`(const `[`PreState`](#classPreState)` &)` {#group__schemata_1gabc0c5bcc094646426f0a90313808907b}

#### `public  `[`~PreState`](#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec)`()` {#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec}

#### `private void `[`rehash`](#group__schemata_1ga5f379ef9372d48f4992a6c4c948b8a5b)`()` {#group__schemata_1ga5f379ef9372d48f4992a6c4c948b8a5b}

#### `public bool `[`operator==`](#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d)`(const `[`PreState`](#classPreState)` & s) const` {#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d}

#### `public bool `[`operator<`](#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b)`(const `[`PreState`](#classPreState)` & s) const` {#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b}

lexicographic comparison on hash value (array[5])

#### `public state_t `[`serialize`](#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4)`()` {#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4}

return a state value unically associated to this [PreState](#classPreState)

#### `public bool `[`compatible`](#group__schemata_1gab947b64699704a087db2eda3eb47575d)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1gab947b64699704a087db2eda3eb47575d}

#### `public static bool `[`compatible_post`](#group__schemata_1gaa509247277fd021460056bfe6484a5b4)`(state_t,const `[`AlignedInterval`](#classAlignedInterval)` *)` {#group__schemata_1gaa509247277fd021460056bfe6484a5b4}

compatible(s, al) the serialized state value s is compatible with the content of the alignment al (sub-segment of initial input corr. to an interval)

#### `public  `[`PreWTA`](#group__schemata_1ga6287aa82de69987b65518b4997112ac5)`(const `[`WTA`](#classWTA)` &)` {#group__schemata_1ga6287aa82de69987b65518b4997112ac5}

construction from [WTA](#classWTA) (base schema)

#### `public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#group__schemata_1gaab30a1faaa381ecfabd705a8c12d179b)`(state_t)` {#group__schemata_1gaab30a1faaa381ecfabd705a8c12d179b}

access to original components of new [PreWTA](#classPreWTA) states

#### `public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#group__schemata_1ga2c8c24b19312ad6436eaf76e4506e02f)`(state_t)` {#group__schemata_1ga2c8c24b19312ad6436eaf76e4506e02f}

#### `public static state_t `[`state`](#group__schemata_1ga3e74404d5f453b8eed85254791724ffe)`(state_t)` {#group__schemata_1ga3e74404d5f453b8eed85254791724ffe}

#### `private state_t `[`addPreState`](#group__schemata_1gaf528dddbe05e879324558a4518738b2d)`(const `[`PreState`](#classPreState)` &)` {#group__schemata_1gaf528dddbe05e879324558a4518738b2d}

addPreState(ps) returns the [PreWTA](#classPreWTA) state s associated to the [PreState](#classPreState) ps if there exists one. otherwise: a new [PreWTA](#classPreWTA) state s is created, s is associated to cs, s is added to the table the [PreWTA](#classPreWTA) transitions with head s are computed and added to the table s is returned moreover, the state is added to the initial state set of the [PreWTA](#classPreWTA) if the state component of ps is initial.

#### `public virtual state_t `[`initial`](#group__schemata_1gaf47213e6243f48f06681089e03fa08ef)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` {#group__schemata_1gaf47213e6243f48f06681089e03fa08ef}

initial(pre, port) returns state representing the whole segment, with pre points of the previous segment aligned to the left and post points of the current segment aligned to the right (i.e. to the left of the next segment)

#### `public bool `[`isMeta`](#group__schemata_1gaa5b5cf5f92a0c443d4c1a1e152f9292c)`(state_t)` {#group__schemata_1gaa5b5cf5f92a0c443d4c1a1e152f9292c}

#### `public bool `[`isWTA`](#group__schemata_1ga1722ba39591c8a25ed5ee91e9e91232a)`(state_t)` {#group__schemata_1ga1722ba39591c8a25ed5ee91e9e91232a}

#### `public bool `[`isLabel`](#group__schemata_1gabd744185c22c686d1c95d74523a007b3)`(state_t)` {#group__schemata_1gabd744185c22c686d1c95d74523a007b3}

#### `public state_t `[`MetaState`](#group__schemata_1ga0ffeaad4a7482bc302dce44a23a85a6e)`(size_t barnb)` {#group__schemata_1ga0ffeaad4a7482bc302dce44a23a85a6e}

Meta state corresponding to bar nb barnb.

#### `public void `[`rename`](#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b)`(unsigned int s,unsigned int u)` {#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b}

#### `public void `[`shift`](#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84)`(unsigned int n)` {#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84}

increase source and target state by n

#### `public void `[`shift0`](#group__schemata_1ga811afd94c0a2afda729115e1afade496)`(unsigned int n)` {#group__schemata_1ga811afd94c0a2afda729115e1afade496}

increase source and target state by n, if they are not 0

#### `public  `[`dagSchema`](#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27)`(const `[`ANode`](#classANode)` &)` {#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27}

translation of AND-OR alternating nested lists into dag-schemas

#### `public  `[`dagSchema`](#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8)`(const `[`ONode`](#classONode)` &)` {#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8}

#### `public void `[`add`](#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20)`(const `[`ds_transition`](#structds__transition)` & dst)` {#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20}

for testing. do not use

#### `private void `[`rename`](#group__schemata_1ga5d904f7412e4bd1263f5369115f910d3)`(unsigned int i,unsigned int j)` {#group__schemata_1ga5d904f7412e4bd1263f5369115f910d3}

rename state i into state j

#### `private void `[`shift`](#group__schemata_1ga942b88d2618ccf43acea8b95cd34d96d)`(unsigned int n)` {#group__schemata_1ga942b88d2618ccf43acea8b95cd34d96d}

rename every state s into s + n the result is not a dag-schema

#### `private void `[`shift0`](#group__schemata_1gaeb6128c3a43d7b6fa5996e8830b4860a)`(unsigned int n)` {#group__schemata_1gaeb6128c3a43d7b6fa5996e8830b4860a}

rename every state s into s + n except 0

#### `public  `[`Transition`](#group__schemata_1ga73b44b2338b11807f77b620a3e810f92)`()` {#group__schemata_1ga73b44b2338b11807f77b620a3e810f92}

transition with unknown weight and empty body.

#### `public  `[`Transition`](#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71)`(const `[`Weight`](#classWeight)` &)` {#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71}

[Transition(w)](#classTransition) creates a transition with weight a copy of w and empty body.

the letter weight in the envelop w is cloned

#### `public  `[`Transition`](#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de)`(`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de}

[Transition(lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null)

#### `public  `[`Transition`](#group__schemata_1gad126f7c68acac0315b1782decaf54d3b)`(std::vector< state_t >,const `[`Weight`](#classWeight)` &)` {#group__schemata_1gad126f7c68acac0315b1782decaf54d3b}

[Transition(v, w)](#classTransition) creates a transition with weight a copy of w and body a copy of the vector v.

the letter weight in the envelop w is cloned.

#### `public  `[`Transition`](#group__schemata_1ga50836c0d84b3968b9ceb968521418e22)`(std::vector< state_t >,`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga50836c0d84b3968b9ceb968521418e22}

[Transition(v, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body a copy of the vector v.

#### `public  `[`Transition`](#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5)`(state_t,const `[`Weight`](#classWeight)` &)` {#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5}

[Transition(s, w)](#classTransition) creates a transition with weight a copy of w and body (of size 1) the singleton (s) (terminal symbol).

the letter weight in the envelop w is cloned.

#### `public  `[`Transition`](#group__schemata_1ga458b953211e3b5de292c8c1535ff7281)`(state_t,`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga458b953211e3b5de292c8c1535ff7281}

[Transition(s, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body (of size 1) the singleton (s) (terminal symbol).

#### `public  `[`~Transition`](#group__schemata_1gab66e8623f23c71cd4f07c69596427bab)`()` {#group__schemata_1gab66e8623f23c71cd4f07c69596427bab}

#### `public bool `[`inner`](#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084)`() const` {#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084}

#### `public bool `[`terminal`](#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd)`() const` {#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd}

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__schemata_1ga97dce48d13fac75a4a444a68aae07608)`() const` {#group__schemata_1ga97dce48d13fac75a4a444a68aae07608}

this transition must be terminal

#### `public void `[`scalar`](#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7)`(double)` {#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7}

modify weight of transition.

#### `public void `[`invert`](#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0)`()` {#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0}

#### `public size_t `[`size`](#group__schemata_1ga743ca128dc509e129a49d66500a0f151)`() const` {#group__schemata_1ga743ca128dc509e129a49d66500a0f151}

size of body.

#### `public size_t `[`arity`](#group__schemata_1gad6ae5de36df4526b83bf7af59d178066)`() const` {#group__schemata_1gad6ae5de36df4526b83bf7af59d178066}

#### `public state_t `[`at`](#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec)`(size_t i) const` {#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec}

at(i) returns the ith state in the body.

#### Parameters
* `i` must be an index of the body.

#### `public void `[`push`](#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf)`(state_t)` {#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf}

add given state at the end of the body of this transition.

#### `public bool `[`member`](#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8)`(state_t) const` {#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8}

whether the given state belongs to the body of this transition.

#### `public bool `[`allin`](#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11)`(const std::set< state_t > &) const` {#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11}

every state of the body is in the given set.

#### `public bool `[`nonein`](#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276)`(const std::set< state_t > &) const` {#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276}

no state of the body is in the given set.

#### `public  `[`ValueState`](#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf)`(state_t,`[`DurationTree`](#classDurationTree)` *)` {#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf}

#### `public  `[`~ValueState`](#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb)`()` {#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb}

#### `public bool `[`compatible`](#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e}

#### `public bool `[`operator==`](#group__schemata_1ga8e4a967143877229169d6c28842185c8)`(const `[`ValueState`](#classValueState)` & s) const` {#group__schemata_1ga8e4a967143877229169d6c28842185c8}

#### `private state_t `[`addValueState`](#group__schemata_1ga074f48ad3b6e8f357ca5bf5dce242b18)`(const `[`ValueState`](#classValueState)` &,bool initial)` {#group__schemata_1ga074f48ad3b6e8f357ca5bf5dce242b18}

returns the [ValueWTA](#classValueWTA) state associated to the [ValueState](#classValueState) vs if there exists one. otherwise:

* a new [ValueWTA](#classValueWTA) state_t s is created,

* s is associated to vs,

* s is added to the transition table

* the [ValueWTA](#classValueWTA) transitions with head s are computed and added to the table

* s is returned

#### `public  `[`ValueWTA`](#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f)`(const `[`DurationList`](#classDurationList)` &,const `[`WTA`](#classWTA)` &)` {#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f}

construction from given initial list and [WTA](#classWTA) (base schema)

#### `public  `[`~TransitionList`](#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe)`()` {#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe}

#### `public bool `[`empty`](#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2)`() const` {#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2}

zero transition

#### Returns
an empty transition

#### `public size_t `[`size`](#group__schemata_1gaa719dbdab17047360e889910795a07f2)`() const` {#group__schemata_1gaa719dbdab17047360e889910795a07f2}

number of transitions.

#### Returns
the number of transitions in this [WTA](#classWTA)

#### `public void `[`add`](#group__schemata_1gadc77b77a90197483168626230fe4dbf4)`(const `[`Transition`](#classTransition)` &)` {#group__schemata_1gadc77b77a90197483168626230fe4dbf4}

#### `public void `[`clear`](#group__schemata_1ga2f4181b350f6dec7054072fcf2095834)`()` {#group__schemata_1ga2f4181b350f6dec7054072fcf2095834}

#### `public void `[`remove`](#group__schemata_1gad9709d189b3748d2285f2a3592bed2da)`(TransitionList_iterator)` {#group__schemata_1gad9709d189b3748d2285f2a3592bed2da}

#### `public void `[`remove`](#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c)`(state_t)` {#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c}

remove all transitions of length > 1 in the list containing the given state do not remove length 1 transitions to terminal symbols

#### `public  `[`WTA`](#group__schemata_1ga5636da911ebbe8772c5444172d56800d)`()` {#group__schemata_1ga5636da911ebbe8772c5444172d56800d}

nullary constructor for cython

#### `public  `[`WTA`](#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca)`(`[`Weight`](#classWeight)` seed,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca}

empty automaton

#### `public  `[`~WTA`](#group__schemata_1gaacdee6c2292baea7f712c84a5e205432)`()` {#group__schemata_1gaacdee6c2292baea7f712c84a5e205432}

#### `public size_t `[`size`](#group__schemata_1gab201fee50d73843159cbef5f453838f0)`() const` {#group__schemata_1gab201fee50d73843159cbef5f453838f0}

number of states

#### `public bool `[`empty`](#group__schemata_1gada977ff7270308f29852b59f38965bde)`() const` {#group__schemata_1gada977ff7270308f29852b59f38965bde}

#### `public bool `[`isRegistered`](#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58)`(state_t) const` {#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58}

the state is present in the automaton

#### `public bool `[`isInitial`](#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6)`(state_t) const` {#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6}

the state is an initial state TBR

#### `public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga924a1c533383a7185b9d466b59c5a495)`(state_t,bool initial)` {#group__schemata_1ga924a1c533383a7185b9d466b59c5a495}

add(s, i) register state s if s was already registered, return a reference to its transition list. otherwise, create state s with an empty transition list and returns a reference to it. moreover s is set as initial if i = true. TODO suppr. flag initial

#### `public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2)`(state_t,const `[`Transition`](#classTransition)` &,bool initial)` {#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2}

add(s, t) add a transition with head s and with body/weight described in t if s was not registered, it is registered the transition t is added to the transition list of s and a reference to this transition list is returned moreover s is set as initial if i = true. TODO suppr. flag initial

#### `public void `[`remove`](#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf)`(state_t)` {#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf}

remove the entry for given state s in the table of the table i.e. all transitions targeted to s, and all the transitions with s in their body. if s was in the initial set, it is also removed from this set. s must be registered.

#### `public TransitionList_const_iterator `[`begin`](#group__schemata_1ga23c3f9884c683e4bbab323208e08c672)`(state_t) const` {#group__schemata_1ga23c3f9884c683e4bbab323208e08c672}

begin(s) returns an iterator pointing to the first transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.

#### `public TransitionList_const_iterator `[`end`](#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5)`(state_t) const` {#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5}

begin(s) returns an iterator pointing to the past-the-end transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.

#### `public size_t `[`countStates`](#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915)`() const` {#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915}

number of states

#### `public size_t `[`countTransitions`](#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a)`() const` {#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a}

number of transition

#### `public size_t `[`countAll`](#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7)`() const` {#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7}

number of symbols (state occurences)

#### `public size_t `[`oftarget`](#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8)`(state_t) const` {#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8}

oftarget(s) return the number of transitions of head state s. s must be registered.

#### `public size_t `[`resolution`](#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4)`() const` {#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4}

#### `protected std::set< state_t > `[`step`](#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc)`(const std::set< state_t > &)` {#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc}

step(s) returns the set of states reachable in one transition step by this [WTA](#classWTA) from the given state set s. all the states in the set s must be registered.

#### `protected std::set< state_t > `[`allStates`](#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d)`() const` {#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d}

returns the set of all states occuring in wta (in head or body)

#### `public std::set< state_t > `[`emptyStates`](#group__schemata_1gaea41b32c37bbe955d0359039d7731fea)`() const` {#group__schemata_1gaea41b32c37bbe955d0359039d7731fea}

returns the set of all non-inhabited (zero weight) states in wta

#### `public bool `[`isClean`](#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202)`() const` {#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202}

the [WTA](#classWTA) has no empty states

#### `public void `[`clean`](#group__schemata_1gaec169477bdc2cf883916c38dbc18e577)`()` {#group__schemata_1gaec169477bdc2cf883916c38dbc18e577}

remove states not inhabited and transitions containing these states

#### `public void `[`abstract`](#group__schemata_1ga91e272f4f9463149cd296f48e65a4185)`(bool flag)` {#group__schemata_1ga91e272f4f9463149cd296f48e65a4185}

abstract the leaf label values in domain [0..MAX_GRACE] every value > MAX_GRACE is casted to MAX_GRACE the weights are summed accordingly

leaf labels in domain of [Label](#classLabel) (not [SerialLabel](#classSerialLabel)). TBR unused

#### `public void `[`CountingtoStochastic`](#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7)`()` {#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "FloatWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "ViterbiWeight" divide by sum for target state

#### `public void `[`CountingtoPenalty`](#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a)`()` {#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "FloatWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "TropicalWeight" composition of CountingtoStochastic and StochastictoPenalty

#### `public void `[`PenaltytoCounting`](#group__schemata_1gaff1196a45ffd1400bc4004e27b167218)`()` {#group__schemata_1gaff1196a45ffd1400bc4004e27b167218}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "TropicalWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "FloatWeight" inverse

#### `public void `[`StochastictoPenalty`](#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5)`()` {#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "ViterbiWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "TropicalWeight" -ln

#### `public bool `[`hasWeightType`](#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b)`(std::string code) const` {#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b}

return wether the weights in transition have the type of the code (code of the letter weight if there is one or "UNKNOWN" otherwise).

#### `public virtual `[`Weight`](#classWeight)` `[`weight_zero`](#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6)`() const` {#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6}

return the 0 value in the weight domain in this [WTA](#classWTA)

#### `public virtual `[`Weight`](#classWeight)` `[`weight_one`](#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd)`() const` {#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd}

return the 1 value in the weight domain in this [WTA](#classWTA)

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gaa6598176fb91c70988bea7cf824ec157)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` {#group__schemata_1gaa6598176fb91c70988bea7cf824ec157}

evaluate the weight of the tree t for [WTA](#classWTA) in initial state

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gac842f196f85e3c3b079c7c0992173e46)`(const `[`RhythmTree`](#classRhythmTree)` & t,state_t s) const` {#group__schemata_1gac842f196f85e3c3b079c7c0992173e46}

#### `public void `[`print`](#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06)`(std::ostream &) const` {#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06}

print sizes to output stream

#### `private void `[`mark_rec`](#group__schemata_1ga6b9809d53e619eb95d9ad9e668ce2b56)`(state_t,int,const `[`WTA`](#classWTA)` &)` {#group__schemata_1ga6b9809d53e619eb95d9ad9e668ce2b56}

#### `public  `[`DepthMarking`](#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935)`(const `[`WTA`](#classWTA)` &)` {#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935}

#### `public int `[`depth`](#group__schemata_1gaaa84e1d149651938af82e47b91888017)`(state_t) const` {#group__schemata_1gaaa84e1d149651938af82e47b91888017}

return depth mark if given state marked return -1 otherwise

#### `public bool `[`multiple`](#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b)`(state_t) const` {#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b}

return true if the given state can occur at multiple depths return false otherwise or if state not marked

#### `public int `[`mark`](#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d)`(state_t,int)` {#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d}

mark state using given depth and return new mark value can be the given depth or a greater depth with which the state had been already marked.

# class `ComboState` {#classComboState}

tmp state structure for construction of [ComboWTA](#classComboWTA) from a [WTA](#classWTA) (base schema) and an input segment casted into state_t after construction

label (for leaves): see [WTA](#classWTA) = continuation or number of note + grace notes at left of the current path

states (q:int, p:Path, rp:int list, rr:int list) ou label (feuille) q: state of base schema p: current path (interval of points in input segment) rp: guess number of points aligned to right of previous segment rr: guess number of points aligned to right of current segment

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public state_t `[`cs_state`](api-schemata.md#classComboState_1a2b079a791c60d80762ac637b520fc17c) | state of base schema.
`public `[`IntervalTree`](#classIntervalTree)` * `[`cs_path`](#classComboState_1a12b750a5d435968342c756dd5ae08777) | current augmented path (interval of points + alignment of input segment) share: in addComboState many [ComboState](api-schemata.md#classComboState) constructed with the same cs_path.
`public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`cs_pre`](#classComboState_1a22b317fc2ff9848dd35a232da73df5f9) | guess number of points aligned to right of previous segment.
`public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`cs_post`](#classComboState_1adda67e672871773210ed90e6f60d6752) | guess number of points aligned to right of current segment.
`public  `[`ComboState`](#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` *)` | 
`public  `[`ComboState`](#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1)`(state_t,`[`IntervalTree`](#classIntervalTree)` *,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` | 
`public  `[`ComboState`](#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39)`(const `[`ComboState`](#classComboState)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` | 
`public  `[`~ComboState`](#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6)`()` | 
`public bool `[`compatible`](#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` | 
`public bool `[`operator==`](#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395)`(const `[`ComboState`](#classComboState)` & s) const` | 
`public bool `[`operator<`](#group__schemata_1ga505e9ff93681bbfe5632a15708facb63)`(const `[`ComboState`](#classComboState)` & s) const` | lexicographic comparison on hash value (array[5])

## Members

#### `public state_t `[`cs_state`](api-schemata.md#classComboState_1a2b079a791c60d80762ac637b520fc17c) {#classComboState_1a2b079a791c60d80762ac637b520fc17c}

state of base schema.

#### `public `[`IntervalTree`](#classIntervalTree)` * `[`cs_path`](#classComboState_1a12b750a5d435968342c756dd5ae08777) {#classComboState_1a12b750a5d435968342c756dd5ae08777}

current augmented path (interval of points + alignment of input segment) share: in addComboState many [ComboState](#classComboState) constructed with the same cs_path.

#### `public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`cs_pre`](#classComboState_1a22b317fc2ff9848dd35a232da73df5f9) {#classComboState_1a22b317fc2ff9848dd35a232da73df5f9}

guess number of points aligned to right of previous segment.

#### `public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`cs_post`](#classComboState_1adda67e672871773210ed90e6f60d6752) {#classComboState_1adda67e672871773210ed90e6f60d6752}

guess number of points aligned to right of current segment.

#### `public  `[`ComboState`](#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e)`(const `[`InputSegment`](#classInputSegment)` * s,`[`IntervalHeap`](#classIntervalHeap)` *)` {#group__schemata_1gadb95b4bb9322c3e2aba43ef1663a035e}

#### `public  `[`ComboState`](#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1)`(state_t,`[`IntervalTree`](#classIntervalTree)` *,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` {#group__schemata_1gaffac6cd8adcfb6bbb0cd9fc601d9a2e1}

#### `public  `[`ComboState`](#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39)`(const `[`ComboState`](#classComboState)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rp,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` rr)` {#group__schemata_1gad80378e34fdc145bd7f0dac17c306e39}

#### `public  `[`~ComboState`](#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6)`()` {#group__schemata_1gac7c0709a18e5caa98554ab0deedc12a6}

#### `public bool `[`compatible`](#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1ga946acbddc843e4ade0b1f47bca5b0929}

#### `public bool `[`operator==`](#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395)`(const `[`ComboState`](#classComboState)` & s) const` {#group__schemata_1ga66c814d1c1c9f1a90c5fc3a1a9d89395}

#### `public bool `[`operator<`](#group__schemata_1ga505e9ff93681bbfe5632a15708facb63)`(const `[`ComboState`](#classComboState)` & s) const` {#group__schemata_1ga505e9ff93681bbfe5632a15708facb63}

lexicographic comparison on hash value (array[5])

# class `ComboWTA` {#classComboWTA}

```
class ComboWTA
  : public WTA
```  

[WTA](#classWTA) combo: A special kind of [WTA](#classWTA) for quantization constructed from.

* a given [WTA](#classWTA) (base schema)

* a given input segment (Alignment) the [ComboWTA](#classComboWTA) combines weights defined by the [WTA](#classWTA) schema (absolute measure of quality of rhythm) and a weight related to the distance of a rhythm to the given input segment.

not serializable

deprecatred

table of transitions top-down construction, given input and schema

principle:

* rp is propagated from father to leftmost child

* rr is propagated from father to rightmost child

* for every 2 states, s2 sibling and successive, s1.rr = s2.rp

given q state of schema, p path, k ≤ max{ n | q -> q1,...,qn | w transition of schema} mright(q, p, k) = # point d’input dans la derniere 2k partie de p

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ComboWTA`](#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7)`(const `[`InputSegment`](#classInputSegment)` *,size_t bloc,const `[`WTA`](#classWTA)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre)` | construction from input segment and [WTA](#classWTA) (base schema) with given max pre value and bloc number (in input segment, for alignement).
`public inline virtual bool `[`hasType`](#classComboWTA_1aa55734ef06970c324a55c31c12655d0f)`(std::string code) const` | 
`public virtual state_t `[`initial`](#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` | state representing the whole segment.

## Members

#### `public  `[`ComboWTA`](#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7)`(const `[`InputSegment`](#classInputSegment)` *,size_t bloc,const `[`WTA`](#classWTA)` &,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre)` {#group__schemata_1ga4c589573251ec74dbe6a3c9176c39bb7}

construction from input segment and [WTA](#classWTA) (base schema) with given max pre value and bloc number (in input segment, for alignement).

#### `public inline virtual bool `[`hasType`](#classComboWTA_1aa55734ef06970c324a55c31c12655d0f)`(std::string code) const` {#classComboWTA_1aa55734ef06970c324a55c31c12655d0f}

#### `public virtual state_t `[`initial`](#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` {#group__schemata_1ga2a6c3a5867fefdac97470fd083aaa2dd}

state representing the whole segment.

#### Parameters
* `pre` points of the previous segment aligned to the left 

* `post` points of the current segment aligned to the right (i.e. to the left of the next segment).

# class `CountingWTA` {#classCountingWTA}

```
class CountingWTA
  : public WTA
```  

copy of [WTA](#classWTA) dedicated to corpus statistics.

for [WTA](#classWTA) weight estimation and [WTA](#classWTA) construction from corpus.

construction of [WTA](#classWTA) with counting weights (unit vectors) from [WTA](#classWTA) and verbose tree evaluation with feedback.

only for target SCHEMA

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CountingWTA`](#group__schemata_1gad46a7f821d01aed3719a585f66130e27)`()` | default initializer for cython
`public  `[`CountingWTA`](#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093)`(const `[`WTA`](#classWTA)` & a)` | copy base [WTA](#classWTA) reset weight values to counting weights (unit vectors)
`public inline virtual bool `[`hasType`](#classCountingWTA_1a4ac4c2d11483cbd40420148e688e9e7f)`(std::string code) const` | 
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` | special version of eval for [CountingWeight](api-weight.md#classCountingWeight) with feedback in case of fail
`protected `[`OTransitionTable`](#group__schemata_1ga34fd7500c532fc3af1419927d6102bb4)` `[`_tableids`](#classCountingWTA_1afb1577fedda586fb3c97df730b8d4100) | copy of transition table ordered according to the transition's ids (can be iterated).
`protected `[`Weight`](#classWeight)` `[`evalCountingVerbose`](#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3)`(const `[`RhythmTree`](#classRhythmTree)` &,state_t,`[`Position`](#classPosition)`) const` | 
`protected void `[`resetCounting`](#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0)`(size_t dim)` | the weight of this [WTA](#classWTA) are replaced by "CountingWeight" unit vector of length dim (one unit per transition)

## Members

#### `public  `[`CountingWTA`](#group__schemata_1gad46a7f821d01aed3719a585f66130e27)`()` {#group__schemata_1gad46a7f821d01aed3719a585f66130e27}

default initializer for cython

#### `public  `[`CountingWTA`](#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093)`(const `[`WTA`](#classWTA)` & a)` {#group__schemata_1ga590bb9036b59d5cf81bbbedb18d19093}

copy base [WTA](#classWTA) reset weight values to counting weights (unit vectors)

#### `public inline virtual bool `[`hasType`](#classCountingWTA_1a4ac4c2d11483cbd40420148e688e9e7f)`(std::string code) const` {#classCountingWTA_1a4ac4c2d11483cbd40420148e688e9e7f}

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` {#group__schemata_1ga2665883ffe41001dd7c2568bc9bef02f}

special version of eval for [CountingWeight](#classCountingWeight) with feedback in case of fail

#### `protected `[`OTransitionTable`](#group__schemata_1ga34fd7500c532fc3af1419927d6102bb4)` `[`_tableids`](#classCountingWTA_1afb1577fedda586fb3c97df730b8d4100) {#classCountingWTA_1afb1577fedda586fb3c97df730b8d4100}

copy of transition table ordered according to the transition's ids (can be iterated).

#### `protected `[`Weight`](#classWeight)` `[`evalCountingVerbose`](#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3)`(const `[`RhythmTree`](#classRhythmTree)` &,state_t,`[`Position`](#classPosition)`) const` {#group__schemata_1ga3a6ae649f73205b3390f82c3f996f6a3}

#### `protected void `[`resetCounting`](#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0)`(size_t dim)` {#group__schemata_1ga5c94f5191975a32e951e7d39ac606dc0}

the weight of this [WTA](#classWTA) are replaced by "CountingWeight" unit vector of length dim (one unit per transition)

# class `PreState` {#classPreState}

tmp state structure for construction of [PreWTA](#classPreWTA) from a [WTA](#classWTA) (base schema) casted aka state_t after construction

label (for leaves): see [WTA](#classWTA)

states (q:int, pre:int, post:int) ou label (feuille) q: state of base schema pre: guess number of points aligned to right of previous segment post: guess number of points aligned to right of current segment

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public state_t `[`ps_state`](api-schemata.md#classPreState_1a1d941524de94901c642c36d204a13bd9) | state of base schema
`public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`ps_pre`](#classPreState_1a5fc7201e1b332037f39469341dacca62) | guess number of points aligned to right of previous segment
`public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`ps_post`](#classPreState_1a20af8f9950f98cdc6991292004a1e881) | guess number of points aligned to right of current segment
`public  `[`PreState`](#group__schemata_1gad02325f302e819ab93c8a501674b4bf4)`()` | 
`public  `[`PreState`](#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8)`(state_t,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` | 
`public  `[`PreState`](#group__schemata_1gabc0c5bcc094646426f0a90313808907b)`(const `[`PreState`](#classPreState)` &)` | 
`public  `[`~PreState`](#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec)`()` | 
`public bool `[`operator==`](#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d)`(const `[`PreState`](#classPreState)` & s) const` | 
`public bool `[`operator<`](#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b)`(const `[`PreState`](#classPreState)` & s) const` | lexicographic comparison on hash value (array[5])
`public state_t `[`serialize`](#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4)`()` | return a state value unically associated to this [PreState](api-schemata.md#classPreState)
`public bool `[`compatible`](#group__schemata_1gab947b64699704a087db2eda3eb47575d)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` | 

## Members

#### `public state_t `[`ps_state`](api-schemata.md#classPreState_1a1d941524de94901c642c36d204a13bd9) {#classPreState_1a1d941524de94901c642c36d204a13bd9}

state of base schema

#### `public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`ps_pre`](#classPreState_1a5fc7201e1b332037f39469341dacca62) {#classPreState_1a5fc7201e1b332037f39469341dacca62}

guess number of points aligned to right of previous segment

#### `public `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`ps_post`](#classPreState_1a20af8f9950f98cdc6991292004a1e881) {#classPreState_1a20af8f9950f98cdc6991292004a1e881}

guess number of points aligned to right of current segment

#### `public  `[`PreState`](#group__schemata_1gad02325f302e819ab93c8a501674b4bf4)`()` {#group__schemata_1gad02325f302e819ab93c8a501674b4bf4}

#### `public  `[`PreState`](#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8)`(state_t,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__schemata_1gae43261a1dcc43a298836fbe62912f8a8}

#### `public  `[`PreState`](#group__schemata_1gabc0c5bcc094646426f0a90313808907b)`(const `[`PreState`](#classPreState)` &)` {#group__schemata_1gabc0c5bcc094646426f0a90313808907b}

#### `public  `[`~PreState`](#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec)`()` {#group__schemata_1ga1ce89331499174e5de23d4d318dcb5ec}

#### `public bool `[`operator==`](#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d)`(const `[`PreState`](#classPreState)` & s) const` {#group__schemata_1gad8b20db3eff6b527dbbc19bb92f2649d}

#### `public bool `[`operator<`](#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b)`(const `[`PreState`](#classPreState)` & s) const` {#group__schemata_1gaa39a99008e7809c864be28f89c5ef79b}

lexicographic comparison on hash value (array[5])

#### `public state_t `[`serialize`](#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4)`()` {#group__schemata_1gaa60c0f6f8e237bad468bd8a48c3263f4}

return a state value unically associated to this [PreState](#classPreState)

#### `public bool `[`compatible`](#group__schemata_1gab947b64699704a087db2eda3eb47575d)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1gab947b64699704a087db2eda3eb47575d}

# class `PreWTA` {#classPreWTA}

```
class PreWTA
  : public WTA
```  

extension of [WTA](#classWTA) where states are associated pre and post values.

* post is a number of points

* pre is the post of the previous sibling

deprecated

extension of a given schema ([WTA](#classWTA)) with pre and post information in states: during a computation, the current state is associated to an input segment,

* pre value is an abstraction of the number of points in the previous segment aligned to the left of the current segment.

* post value is an abstraction of the number of points aligned to the right of the current segment. cf. Label::abstract for the abstraction domain

top-down construction of the transition table, principle:

* pre propagate from a node to its leftmost child

* post propagte from a node to it rightmost child

* for 2 states s1, s2 at successive siblings, it holds that s1.post = s2.pre

given q state of schema, k ≤ max{ n | q -> q1,...,qn | w transition of schema} mright(q, k) = # point d’input dans la derniere 2k partie de p

we start with states <q0, pre0, post0> in a queue q0 = initial state of the schema pre0 arbitrary (input of problem = previous tree). ctypically 0. post0 in [0, MAX_GRACE]

for all state <q, pre, post> taken from the queue

for all final transition q -> s | w of the schema we add the transition <q, pre, post> -> <s, pre, post> | w such that the value of s abstracts the possible values of pre + lalign(path) for any path.

for all inner transition q -> (q1,…,qk) | w in schema (k > 1) for all post in [0..MAX_GRACE] we add the transitions <q, pre, post> -> (<q1, pre1, post1>,..., <qk, prek, postk>) | w such that

* postk = post

* pre1 = pre

* for all 1 ≤ i < k, posti = prei+1 we also add the states <q1, pre1, post1>,..., <qk, prek, postk> in the queue

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`PreWTA`](#group__schemata_1ga6287aa82de69987b65518b4997112ac5)`(const `[`WTA`](#classWTA)` &)` | construction from [WTA](#classWTA) (base schema)
`public inline virtual bool `[`hasType`](#classPreWTA_1a0cb0b8f217198e19367d88674605995e)`(std::string code) const` | 
`public virtual state_t `[`initial`](#group__schemata_1gaf47213e6243f48f06681089e03fa08ef)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` | initial(pre, port) returns state representing the whole segment, with pre points of the previous segment aligned to the left and post points of the current segment aligned to the right (i.e. to the left of the next segment)

## Members

#### `public  `[`PreWTA`](#group__schemata_1ga6287aa82de69987b65518b4997112ac5)`(const `[`WTA`](#classWTA)` &)` {#group__schemata_1ga6287aa82de69987b65518b4997112ac5}

construction from [WTA](#classWTA) (base schema)

#### `public inline virtual bool `[`hasType`](#classPreWTA_1a0cb0b8f217198e19367d88674605995e)`(std::string code) const` {#classPreWTA_1a0cb0b8f217198e19367d88674605995e}

#### `public virtual state_t `[`initial`](#group__schemata_1gaf47213e6243f48f06681089e03fa08ef)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` {#group__schemata_1gaf47213e6243f48f06681089e03fa08ef}

initial(pre, port) returns state representing the whole segment, with pre points of the previous segment aligned to the left and post points of the current segment aligned to the right (i.e. to the left of the next segment)

# class `AONode` {#classAONode}

AND-OR alternating nested lists used by Adrien in RQ.

from RQ doc: A subdivision schema of this kind is presented in the form of a nested list.

For example : (2 2 3) means that each measure is divided in two, then each part is again divided in two, and finally, each of these parts is divided in 3. (2 2 3) = ∧(2 2 3) = 2.2.3 (AND ∧ means sequential composition also denoted .)

If an element of the list is a list itself, it means that the choice is given between the values of the list. For example : (2 (2 3 5) 3) means (2 2 3) or (2 3 3) or (2 5 3). (2 (2 3 5) 3) = ∧(2 ∨(2 3 5) 3) = 2.(2|3|5).3

If an element of the list is a list of lists, it means that the choice is given between various successions of subdivisions. For example : ( ((2 3) (3 2)) ) means (2 3) or (3 2). ( ((2 3) (3 2)) ) = ∧( ∨(∧(2 3) ∧(3 2)) ) = (2.3) | (3.2) For example : ((2 3) ((2 3) ((3 5) 2))) means (2 2 3) or (2 3 2) or (2 5 2) or (3 2 3) or (3 3 2) or (3 5 2). ((2 3) ((2 3) ((3 5) 2))) = ∧(∨(2 3) ∨(∧(2 3) ∧(∨(3 5) 2))) = (2|3) . ((2.3) | ((3|5).2))

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`AONode`](#classAONode_1a8b2b854573f53b3105ff193d7128bf5a)`(size_t a)` | 
`public inline bool `[`inner`](#classAONode_1a79196ae7696619f60eadcd96eb4750f1)`() const` | 
`public inline bool `[`leaf`](#classAONode_1a63996089a9dc6c2320fb91b54c0fdcc6)`() const` | 
`public inline size_t `[`value`](#classAONode_1ac1ac6a913dc66d8e344dfde2266f8c5c)`() const` | 
`protected size_t `[`_arity`](api-schemata.md#classAONode_1a68dc0af71d8e6bac30b8ff9ec40ff806) | 0 for inner nodes, arity > 1 for leaf

## Members

#### `public inline  `[`AONode`](#classAONode_1a8b2b854573f53b3105ff193d7128bf5a)`(size_t a)` {#classAONode_1a8b2b854573f53b3105ff193d7128bf5a}

#### `public inline bool `[`inner`](#classAONode_1a79196ae7696619f60eadcd96eb4750f1)`() const` {#classAONode_1a79196ae7696619f60eadcd96eb4750f1}

#### `public inline bool `[`leaf`](#classAONode_1a63996089a9dc6c2320fb91b54c0fdcc6)`() const` {#classAONode_1a63996089a9dc6c2320fb91b54c0fdcc6}

#### `public inline size_t `[`value`](#classAONode_1ac1ac6a913dc66d8e344dfde2266f8c5c)`() const` {#classAONode_1ac1ac6a913dc66d8e344dfde2266f8c5c}

#### `protected size_t `[`_arity`](api-schemata.md#classAONode_1a68dc0af71d8e6bac30b8ff9ec40ff806) {#classAONode_1a68dc0af71d8e6bac30b8ff9ec40ff806}

0 for inner nodes, arity > 1 for leaf

# class `ANode` {#classANode}

```
class ANode
  : public AONode
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< `[`ONode`](#classONode)` > `[`children`](#classANode_1a3865adc88fbdec94e78d31935916f80b) | 
`public inline  `[`ANode`](#classANode_1a31957c3642f765505c540ee648bc887d)`()` | 
`public inline  `[`ANode`](#classANode_1ad96635728c3142bf0eef8f13a6bde1b9)`(size_t a)` | 
`public inline void `[`add`](#classANode_1a392728d45708f36056cfaecd0de40a99)`(const `[`ONode`](#classONode)` & n)` | 

## Members

#### `public std::vector< `[`ONode`](#classONode)` > `[`children`](#classANode_1a3865adc88fbdec94e78d31935916f80b) {#classANode_1a3865adc88fbdec94e78d31935916f80b}

#### `public inline  `[`ANode`](#classANode_1a31957c3642f765505c540ee648bc887d)`()` {#classANode_1a31957c3642f765505c540ee648bc887d}

#### `public inline  `[`ANode`](#classANode_1ad96635728c3142bf0eef8f13a6bde1b9)`(size_t a)` {#classANode_1ad96635728c3142bf0eef8f13a6bde1b9}

#### `public inline void `[`add`](#classANode_1a392728d45708f36056cfaecd0de40a99)`(const `[`ONode`](#classONode)` & n)` {#classANode_1a392728d45708f36056cfaecd0de40a99}

# class `ONode` {#classONode}

```
class ONode
  : public AONode
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< `[`ANode`](#classANode)` > `[`children`](#classONode_1a3de9840b800820f217fc9110211d34c5) | 
`public inline  `[`ONode`](#classONode_1aab9058f10812e43dbb622e7d643ab0f8)`()` | 
`public inline  `[`ONode`](#classONode_1a3226a302281a35b89a6c0ba8b480fe78)`(size_t a)` | 
`public inline void `[`add`](#classONode_1a8e4d2ce12d0fb10d38ce2a6142f11269)`(const `[`ANode`](#classANode)` & n)` | 

## Members

#### `public std::vector< `[`ANode`](#classANode)` > `[`children`](#classONode_1a3de9840b800820f217fc9110211d34c5) {#classONode_1a3de9840b800820f217fc9110211d34c5}

#### `public inline  `[`ONode`](#classONode_1aab9058f10812e43dbb622e7d643ab0f8)`()` {#classONode_1aab9058f10812e43dbb622e7d643ab0f8}

#### `public inline  `[`ONode`](#classONode_1a3226a302281a35b89a6c0ba8b480fe78)`(size_t a)` {#classONode_1a3226a302281a35b89a6c0ba8b480fe78}

#### `public inline void `[`add`](#classONode_1a8e4d2ce12d0fb10d38ce2a6142f11269)`(const `[`ANode`](#classANode)` & n)` {#classONode_1a8e4d2ce12d0fb10d38ce2a6142f11269}

# class `dagSchema` {#classdagSchema}

dag whose edges are labeled by arity values two distinguished nodes:

* a source node: 0

* a target node: _max_state

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`dagSchema`](#classdagSchema_1a4684a55125d5d0ef66d35bfd76a7da31)`()` | 
`public  `[`dagSchema`](#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27)`(const `[`ANode`](#classANode)` &)` | translation of AND-OR alternating nested lists into dag-schemas
`public  `[`dagSchema`](#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8)`(const `[`ONode`](#classONode)` &)` | 
`public inline unsigned int `[`max`](#classdagSchema_1ade079e9d6738c9bb02123d6c3cf01331)`() const` | 
`public inline unsigned int `[`max`](#classdagSchema_1af4e948da7d717f8f4600f0e9dcdadec1)`(const `[`dagSchema`](#classdagSchema)` & lhs,const `[`dagSchema`](#classdagSchema)` & rhs)` | 
`public void `[`add`](#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20)`(const `[`ds_transition`](#structds__transition)` & dst)` | for testing. do not use

## Members

#### `public inline  `[`dagSchema`](#classdagSchema_1a4684a55125d5d0ef66d35bfd76a7da31)`()` {#classdagSchema_1a4684a55125d5d0ef66d35bfd76a7da31}

#### `public  `[`dagSchema`](#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27)`(const `[`ANode`](#classANode)` &)` {#group__schemata_1ga1762a1cf61c23100f58a69f092f94e27}

translation of AND-OR alternating nested lists into dag-schemas

#### `public  `[`dagSchema`](#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8)`(const `[`ONode`](#classONode)` &)` {#group__schemata_1ga7f1258e692e42b123b039e9aa1c256b8}

#### `public inline unsigned int `[`max`](#classdagSchema_1ade079e9d6738c9bb02123d6c3cf01331)`() const` {#classdagSchema_1ade079e9d6738c9bb02123d6c3cf01331}

#### `public inline unsigned int `[`max`](#classdagSchema_1af4e948da7d717f8f4600f0e9dcdadec1)`(const `[`dagSchema`](#classdagSchema)` & lhs,const `[`dagSchema`](#classdagSchema)` & rhs)` {#classdagSchema_1af4e948da7d717f8f4600f0e9dcdadec1}

#### `public void `[`add`](#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20)`(const `[`ds_transition`](#structds__transition)` & dst)` {#group__schemata_1ga0dc3e9cf7edbc289976639574ca23d20}

for testing. do not use

# class `Transition` {#classTransition}

a [Transition](#classTransition) is defined by a sequence of antecedent states (body) the weight must be not null (null weight means a missing transition).

a transition can be of two kinds:

* inner transition: the body has length > 1 the arity is the length of the body

* terminal (leaf) transition: the body has length 1 and contains a leaf label the arity is zero

leaf label (terminal transitions): number of note + grace notes at (left of) current node 0 = continuation 1 = 1 note | rest (au + 1 note) 2 = 1 grace notes + 1 note 3 = 2 grace notes + 1 note etc 
**See also**: [Label](#classLabel) for the functions managing these labels

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Transition`](#group__schemata_1ga73b44b2338b11807f77b620a3e810f92)`()` | transition with unknown weight and empty body.
`public  `[`Transition`](#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71)`(const `[`Weight`](#classWeight)` &)` | [Transition(w)](api-schemata.md#classTransition) creates a transition with weight a copy of w and empty body.
`public  `[`Transition`](#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de)`(`[`LetterWeight`](#classLetterWeight)` *)` | [Transition(lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null)
`public  `[`Transition`](#group__schemata_1gad126f7c68acac0315b1782decaf54d3b)`(std::vector< state_t >,const `[`Weight`](#classWeight)` &)` | [Transition(v, w)](api-schemata.md#classTransition) creates a transition with weight a copy of w and body a copy of the vector v.
`public  `[`Transition`](#group__schemata_1ga50836c0d84b3968b9ceb968521418e22)`(std::vector< state_t >,`[`LetterWeight`](#classLetterWeight)` *)` | [Transition(v, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body a copy of the vector v.
`public  `[`Transition`](#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5)`(state_t,const `[`Weight`](#classWeight)` &)` | [Transition(s, w)](#classTransition) creates a transition with weight a copy of w and body (of size 1) the singleton (s) (terminal symbol).
`public  `[`Transition`](#group__schemata_1ga458b953211e3b5de292c8c1535ff7281)`(state_t,`[`LetterWeight`](#classLetterWeight)` *)` | [Transition(s, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body (of size 1) the singleton (s) (terminal symbol).
`public  `[`~Transition`](#group__schemata_1gab66e8623f23c71cd4f07c69596427bab)`()` | 
`public bool `[`inner`](#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084)`() const` | 
`public bool `[`terminal`](#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd)`() const` | 
`public inline size_t `[`id`](#classTransition_1a77ab4e74f63933f38c6e2f8d875b6481)`() const` | 
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__schemata_1ga97dce48d13fac75a4a444a68aae07608)`() const` | this transition must be terminal
`public inline `[`Weight`](#classWeight)` `[`weight`](#classTransition_1a14627398184e9a306cd3e7770a90dd80)`() const` | 
`public inline void `[`setWeight`](#classTransition_1a9430122ef00fdb0916a2c96d706345e4)`(const `[`Weight`](#classWeight)` & w)` | 
`public void `[`scalar`](#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7)`(double)` | modify weight of transition.
`public void `[`invert`](#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0)`()` | 
`public state_t `[`at`](#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec)`(size_t i) const` | at(i) returns the ith state in the body.
`public void `[`push`](#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf)`(state_t)` | add given state at the end of the body of this transition.
`public size_t `[`size`](#group__schemata_1ga743ca128dc509e129a49d66500a0f151)`() const` | size of body.
`public size_t `[`arity`](#group__schemata_1gad6ae5de36df4526b83bf7af59d178066)`() const` | 
`public inline Transition_const_iterator `[`begin`](#classTransition_1a9bfff4ceb09c77df98c708c005bda5cb)`() const` | iterator pointing to the first state in the body of the transition.
`public inline Transition_const_iterator `[`end`](#classTransition_1a985c1d4cc1444ebb75e7703be48eb564)`() const` | iterator pointing to the end of the body of the transition.
`public bool `[`member`](#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8)`(state_t) const` | whether the given state belongs to the body of this transition.
`public bool `[`allin`](#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11)`(const std::set< state_t > &) const` | every state of the body is in the given set.
`public bool `[`nonein`](#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276)`(const std::set< state_t > &) const` | no state of the body is in the given set.

## Members

#### `public  `[`Transition`](#group__schemata_1ga73b44b2338b11807f77b620a3e810f92)`()` {#group__schemata_1ga73b44b2338b11807f77b620a3e810f92}

transition with unknown weight and empty body.

#### `public  `[`Transition`](#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71)`(const `[`Weight`](#classWeight)` &)` {#group__schemata_1ga6e08e637325ab62ee6bfbdb99c8f8a71}

[Transition(w)](#classTransition) creates a transition with weight a copy of w and empty body.

the letter weight in the envelop w is cloned

#### `public  `[`Transition`](#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de)`(`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga09dca130387fcf6ead3f80cc523a59de}

[Transition(lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null)

#### `public  `[`Transition`](#group__schemata_1gad126f7c68acac0315b1782decaf54d3b)`(std::vector< state_t >,const `[`Weight`](#classWeight)` &)` {#group__schemata_1gad126f7c68acac0315b1782decaf54d3b}

[Transition(v, w)](#classTransition) creates a transition with weight a copy of w and body a copy of the vector v.

the letter weight in the envelop w is cloned.

#### `public  `[`Transition`](#group__schemata_1ga50836c0d84b3968b9ceb968521418e22)`(std::vector< state_t >,`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga50836c0d84b3968b9ceb968521418e22}

[Transition(v, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body a copy of the vector v.

#### `public  `[`Transition`](#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5)`(state_t,const `[`Weight`](#classWeight)` &)` {#group__schemata_1ga3c71fb93c73a755408cc963975d4ffa5}

[Transition(s, w)](#classTransition) creates a transition with weight a copy of w and body (of size 1) the singleton (s) (terminal symbol).

the letter weight in the envelop w is cloned.

#### `public  `[`Transition`](#group__schemata_1ga458b953211e3b5de292c8c1535ff7281)`(state_t,`[`LetterWeight`](#classLetterWeight)` *)` {#group__schemata_1ga458b953211e3b5de292c8c1535ff7281}

[Transition(s, lw)](#classTransition) creates a transition with weight a wrapper of the letter lw (must be non null) and body (of size 1) the singleton (s) (terminal symbol).

#### `public  `[`~Transition`](#group__schemata_1gab66e8623f23c71cd4f07c69596427bab)`()` {#group__schemata_1gab66e8623f23c71cd4f07c69596427bab}

#### `public bool `[`inner`](#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084)`() const` {#group__schemata_1gaeb18d5879ecb7757b5e783866c3e6084}

#### `public bool `[`terminal`](#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd)`() const` {#group__schemata_1ga1191490a05cc7d04a9933e5d84ca9fcd}

#### `public inline size_t `[`id`](#classTransition_1a77ab4e74f63933f38c6e2f8d875b6481)`() const` {#classTransition_1a77ab4e74f63933f38c6e2f8d875b6481}

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__schemata_1ga97dce48d13fac75a4a444a68aae07608)`() const` {#group__schemata_1ga97dce48d13fac75a4a444a68aae07608}

this transition must be terminal

#### `public inline `[`Weight`](#classWeight)` `[`weight`](#classTransition_1a14627398184e9a306cd3e7770a90dd80)`() const` {#classTransition_1a14627398184e9a306cd3e7770a90dd80}

#### `public inline void `[`setWeight`](#classTransition_1a9430122ef00fdb0916a2c96d706345e4)`(const `[`Weight`](#classWeight)` & w)` {#classTransition_1a9430122ef00fdb0916a2c96d706345e4}

#### `public void `[`scalar`](#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7)`(double)` {#group__schemata_1ga6d7e864cf11645e39e3999516c2438f7}

modify weight of transition.

#### `public void `[`invert`](#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0)`()` {#group__schemata_1ga00585e8726be305c0a0d5b9af9c585b0}

#### `public state_t `[`at`](#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec)`(size_t i) const` {#group__schemata_1ga9e2e243bfa147bafd947f2cffd1da3ec}

at(i) returns the ith state in the body.

#### Parameters
* `i` must be an index of the body.

#### `public void `[`push`](#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf)`(state_t)` {#group__schemata_1gaacc3c061a48c15ce02b2ead05f9bb2bf}

add given state at the end of the body of this transition.

#### `public size_t `[`size`](#group__schemata_1ga743ca128dc509e129a49d66500a0f151)`() const` {#group__schemata_1ga743ca128dc509e129a49d66500a0f151}

size of body.

#### `public size_t `[`arity`](#group__schemata_1gad6ae5de36df4526b83bf7af59d178066)`() const` {#group__schemata_1gad6ae5de36df4526b83bf7af59d178066}

#### `public inline Transition_const_iterator `[`begin`](#classTransition_1a9bfff4ceb09c77df98c708c005bda5cb)`() const` {#classTransition_1a9bfff4ceb09c77df98c708c005bda5cb}

iterator pointing to the first state in the body of the transition.

#### `public inline Transition_const_iterator `[`end`](#classTransition_1a985c1d4cc1444ebb75e7703be48eb564)`() const` {#classTransition_1a985c1d4cc1444ebb75e7703be48eb564}

iterator pointing to the end of the body of the transition.

#### `public bool `[`member`](#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8)`(state_t) const` {#group__schemata_1gab94ff39ee66515e72c1c52ba855508c8}

whether the given state belongs to the body of this transition.

#### `public bool `[`allin`](#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11)`(const std::set< state_t > &) const` {#group__schemata_1ga9719bf4a7c1e1ec8e0e1fceed8da0a11}

every state of the body is in the given set.

#### `public bool `[`nonein`](#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276)`(const std::set< state_t > &) const` {#group__schemata_1ga6bb49bac8dc5d5dbfb955b9eaea29276}

no state of the body is in the given set.

# class `ValueState` {#classValueState}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ValueState`](#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf)`(state_t,`[`DurationTree`](#classDurationTree)` *)` | 
`public  `[`~ValueState`](#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb)`()` | 
`public inline state_t `[`state`](#classValueState_1a5654fe3f5d536059e34ec0ab116ee958)`() const` | 
`public inline `[`ValueList`](#classValueList)` `[`value`](#classValueState_1af343a6391264cbc3afb17f2383e5f610)`() const` | 
`public inline `[`DurationTree`](#classDurationTree)` * `[`tree`](#classValueState_1aa587a09d4f9eb33956dc4b0bc68316d6)`() const` | 
`public bool `[`operator==`](#group__schemata_1ga8e4a967143877229169d6c28842185c8)`(const `[`ValueState`](#classValueState)` & s) const` | 
`public bool `[`compatible`](#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` | 

## Members

#### `public  `[`ValueState`](#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf)`(state_t,`[`DurationTree`](#classDurationTree)` *)` {#group__schemata_1ga78ce9830cde7d7875888ab5b420beecf}

#### `public  `[`~ValueState`](#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb)`()` {#group__schemata_1ga6f7e57b6744c6a6c729d6b65068f52eb}

#### `public inline state_t `[`state`](#classValueState_1a5654fe3f5d536059e34ec0ab116ee958)`() const` {#classValueState_1a5654fe3f5d536059e34ec0ab116ee958}

#### `public inline `[`ValueList`](#classValueList)` `[`value`](#classValueState_1af343a6391264cbc3afb17f2383e5f610)`() const` {#classValueState_1af343a6391264cbc3afb17f2383e5f610}

#### `public inline `[`DurationTree`](#classDurationTree)` * `[`tree`](#classValueState_1aa587a09d4f9eb33956dc4b0bc68316d6)`() const` {#classValueState_1aa587a09d4f9eb33956dc4b0bc68316d6}

#### `public bool `[`operator==`](#group__schemata_1ga8e4a967143877229169d6c28842185c8)`(const `[`ValueState`](#classValueState)` & s) const` {#group__schemata_1ga8e4a967143877229169d6c28842185c8}

#### `public bool `[`compatible`](#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` label) const` {#group__schemata_1gaa64b0072478e5475befdb4b0212d8e2e}

# class `ValueWTA` {#classValueWTA}

```
class ValueWTA
  : public WTA
```  

Value [WTA](#classWTA) is a special kind of [WTA](#classWTA) associated to an initial [WTA](#classWTA) (schema) and a rhythmic value ([DurationList](#classDurationList)).

It characterizes the trees of the schema language (with weight defined by schema) having the given rhythmic value.

table of transitions construction top-down, given an initial schema ([WTA](#classWTA)) and a [DurationList](#classDurationList)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ValueWTA`](#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f)`(const `[`DurationList`](#classDurationList)` &,const `[`WTA`](#classWTA)` &)` | construction from given initial list and [WTA](#classWTA) (base schema)
`public inline virtual bool `[`hasType`](#classValueWTA_1a4d5f75a4c4dd74e1b419786c30a3837a)`(std::string code) const` | 

## Members

#### `public  `[`ValueWTA`](#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f)`(const `[`DurationList`](#classDurationList)` &,const `[`WTA`](#classWTA)` &)` {#group__schemata_1gab35a1ee1d6e2b2b5d82b930b4d70340f}

construction from given initial list and [WTA](#classWTA) (base schema)

#### `public inline virtual bool `[`hasType`](#classValueWTA_1a4d5f75a4c4dd74e1b419786c30a3837a)`(std::string code) const` {#classValueWTA_1a4d5f75a4c4dd74e1b419786c30a3837a}

# class `TransitionList` {#classTransitionList}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`TransitionList`](#classTransitionList_1a067a5835f4dbc909d65698fc71b93976)`()` | 
`public  `[`~TransitionList`](#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe)`()` | 
`public bool `[`empty`](#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2)`() const` | zero transition
`public size_t `[`size`](#group__schemata_1gaa719dbdab17047360e889910795a07f2)`() const` | number of transitions.
`public inline size_t `[`fullsize`](#classTransitionList_1a895b21c1601aa0227264856f534f3714)`() const` | total size of transition table (sum of transition sizes. = number of occurences of states)
`public void `[`add`](#group__schemata_1gadc77b77a90197483168626230fe4dbf4)`(const `[`Transition`](#classTransition)` &)` | 
`public void `[`remove`](#group__schemata_1gad9709d189b3748d2285f2a3592bed2da)`(TransitionList_iterator)` | 
`public void `[`remove`](#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c)`(state_t)` | remove all transitions of length > 1 in the list containing the given state do not remove length 1 transitions to terminal symbols
`public void `[`clear`](#group__schemata_1ga2f4181b350f6dec7054072fcf2095834)`()` | 
`public inline TransitionList_const_iterator `[`begin`](#classTransitionList_1a7fcbeb316dcf76418642f1f2056a5fda)`() const` | 
`public inline TransitionList_const_iterator `[`end`](#classTransitionList_1ad823ed73ac180f6580ba03f8d1c6f11d)`() const` | 
`public inline TransitionList_iterator `[`nc_begin`](#classTransitionList_1a0db8b4656919b96fc29654126a039930)`()` | non constant iterator.
`public inline TransitionList_iterator `[`nc_end`](#classTransitionList_1a618b9838609de2fd39d9d0ac303798e1)`()` | non constant iterator.

## Members

#### `public inline  `[`TransitionList`](#classTransitionList_1a067a5835f4dbc909d65698fc71b93976)`()` {#classTransitionList_1a067a5835f4dbc909d65698fc71b93976}

#### `public  `[`~TransitionList`](#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe)`()` {#group__schemata_1gaefce3b545139b29c4391f2b5e4f97efe}

#### `public bool `[`empty`](#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2)`() const` {#group__schemata_1gaba83dbc74a223a80ad7f8776847bd6c2}

zero transition

#### Returns
an empty transition

#### `public size_t `[`size`](#group__schemata_1gaa719dbdab17047360e889910795a07f2)`() const` {#group__schemata_1gaa719dbdab17047360e889910795a07f2}

number of transitions.

#### Returns
the number of transitions in this [WTA](#classWTA)

#### `public inline size_t `[`fullsize`](#classTransitionList_1a895b21c1601aa0227264856f534f3714)`() const` {#classTransitionList_1a895b21c1601aa0227264856f534f3714}

total size of transition table (sum of transition sizes. = number of occurences of states)

#### `public void `[`add`](#group__schemata_1gadc77b77a90197483168626230fe4dbf4)`(const `[`Transition`](#classTransition)` &)` {#group__schemata_1gadc77b77a90197483168626230fe4dbf4}

#### `public void `[`remove`](#group__schemata_1gad9709d189b3748d2285f2a3592bed2da)`(TransitionList_iterator)` {#group__schemata_1gad9709d189b3748d2285f2a3592bed2da}

#### `public void `[`remove`](#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c)`(state_t)` {#group__schemata_1ga3c5b906f3ce72168effc16b06ed1ef6c}

remove all transitions of length > 1 in the list containing the given state do not remove length 1 transitions to terminal symbols

#### `public void `[`clear`](#group__schemata_1ga2f4181b350f6dec7054072fcf2095834)`()` {#group__schemata_1ga2f4181b350f6dec7054072fcf2095834}

#### `public inline TransitionList_const_iterator `[`begin`](#classTransitionList_1a7fcbeb316dcf76418642f1f2056a5fda)`() const` {#classTransitionList_1a7fcbeb316dcf76418642f1f2056a5fda}

#### `public inline TransitionList_const_iterator `[`end`](#classTransitionList_1ad823ed73ac180f6580ba03f8d1c6f11d)`() const` {#classTransitionList_1ad823ed73ac180f6580ba03f8d1c6f11d}

#### `public inline TransitionList_iterator `[`nc_begin`](#classTransitionList_1a0db8b4656919b96fc29654126a039930)`()` {#classTransitionList_1a0db8b4656919b96fc29654126a039930}

non constant iterator.

#### `public inline TransitionList_iterator `[`nc_end`](#classTransitionList_1a618b9838609de2fd39d9d0ac303798e1)`()` {#classTransitionList_1a618b9838609de2fd39d9d0ac303798e1}

non constant iterator.

# class `WTA` {#classWTA}

class of schemas = weighted tree automata = weighted CFG.

state (and non-terminals): int

transition table = map state -> (transition = state list), weight state: head state state list: see [Transition.hpp](#Transition_8hpp_source) body states if length ≥ 2 label if length = 1

in other terms transition rules have one of the forms s -> (s1,...,sk) w where k > 1, s, s1, ..., sk are states and w weight s -> (s1) w where s1 is an leaf label = int encoding 

leaf label (terminals): number of note + grace notes at (left of) current node 0 = continuation 1 = 1 note | rest (au + 1 note) 2 = 1 grace notes + 1 note 3 = 2 grace notes + 1 note >etc 

**See also**: [Label](#classLabel) for the functions managing these labels transition [Table module](#group__table): head state -> vector of (state vector, [Weight module](#group__weight)) 

weights are concrete weight values embedded in a [Weight](#classWeight) envelop we consider 3 kinds of weights for [WTA](#classWTA) serialized in file:

* counting model: weight = # of subresettrees in corpus parsed by rule implemented as [FloatWeight](#classFloatWeight)

* penalty model: weight = penalities to sum implemented as [TropicalWeight](#classTropicalWeight) e.g. inverse of counting model (normalized?)

* probabilistic model, fulfilling stochastic condition (sum of weight of transition from a state = 1) implemented as [ViterbiWeight](#classViterbiWeight) e.g. (# of subtrees in corpus parsed by rule) / (# of subtrees matching lhs state)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::set< state_t > `[`initials`](api-schemata.md#classWTA_1a5d8ace9f515a3902d889db560f08f4c5) | set of initial states TODO SUPPR
`public  `[`WTA`](#group__schemata_1ga5636da911ebbe8772c5444172d56800d)`()` | nullary constructor for cython
`public  `[`WTA`](#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca)`(`[`Weight`](#classWeight)` seed,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` | empty automaton
`public  `[`~WTA`](#group__schemata_1gaacdee6c2292baea7f712c84a5e205432)`()` | 
`public inline virtual bool `[`hasType`](#classWTA_1a23060c851d5cf624215c2d9dc8ad4b45)`(std::string code) const` | 
`public size_t `[`size`](#group__schemata_1gab201fee50d73843159cbef5f453838f0)`() const` | number of states
`public bool `[`empty`](#group__schemata_1gada977ff7270308f29852b59f38965bde)`() const` | 
`public bool `[`isRegistered`](#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58)`(state_t) const` | the state is present in the automaton
`public bool `[`isInitial`](#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6)`(state_t) const` | the state is an initial state TBR
`public inline virtual state_t `[`initial`](#classWTA_1ae6b10f70925f14f36b839e5d8657bc5e)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` | initial(pre, post) pre and post are use for quantification and ignored in this version (useless for schemas)
`public size_t `[`resolution`](#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4)`() const` | 
`public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga924a1c533383a7185b9d466b59c5a495)`(state_t,bool initial)` | add(s, i) register state s if s was already registered, return a reference to its transition list. otherwise, create state s with an empty transition list and returns a reference to it. moreover s is set as initial if i = true. TODO suppr. flag initial
`public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2)`(state_t,const `[`Transition`](#classTransition)` &,bool initial)` | add(s, t) add a transition with head s and with body/weight described in t if s was not registered, it is registered the transition t is added to the transition list of s and a reference to this transition list is returned moreover s is set as initial if i = true. TODO suppr. flag initial
`public void `[`remove`](#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf)`(state_t)` | remove the entry for given state s in the table of the table i.e. all transitions targeted to s, and all the transitions with s in their body. if s was in the initial set, it is also removed from this set. s must be registered.
`public TransitionList_const_iterator `[`begin`](#group__schemata_1ga23c3f9884c683e4bbab323208e08c672)`(state_t) const` | begin(s) returns an iterator pointing to the first transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.
`public TransitionList_const_iterator `[`end`](#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5)`(state_t) const` | begin(s) returns an iterator pointing to the past-the-end transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.
`public size_t `[`oftarget`](#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8)`(state_t) const` | oftarget(s) return the number of transitions of head state s. s must be registered.
`public bool `[`isClean`](#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202)`() const` | the [WTA](api-schemata.md#classWTA) has no empty states
`public std::set< state_t > `[`emptyStates`](#group__schemata_1gaea41b32c37bbe955d0359039d7731fea)`() const` | returns the set of all non-inhabited (zero weight) states in wta
`public void `[`clean`](#group__schemata_1gaec169477bdc2cf883916c38dbc18e577)`()` | remove states not inhabited and transitions containing these states
`public void `[`normalize`](#classWTA_1aa4eda8d626af33674c59fef22c8220c1)`(unsigned int flag)` | for all state q, for all transition tr to q (in the transition list TL(q) of q). recompute weights to get a probabilistic [WTA](api-schemata.md#classWTA).
`public void `[`CountingtoStochastic`](#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7)`()` | cast weights in all transitions.
`public void `[`PenaltytoCounting`](#group__schemata_1gaff1196a45ffd1400bc4004e27b167218)`()` | cast weights in all transitions.
`public void `[`StochastictoPenalty`](#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5)`()` | cast weights in all transitions.
`public void `[`CountingtoPenalty`](#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a)`()` | cast weights in all transitions.
`public void `[`abstract`](#group__schemata_1ga91e272f4f9463149cd296f48e65a4185)`(bool flag)` | abstract the leaf label values in domain [0..MAX_GRACE] every value > MAX_GRACE is casted to MAX_GRACE the weights are summed accordingly
`public size_t `[`countStates`](#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915)`() const` | number of states
`public size_t `[`countTransitions`](#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a)`() const` | number of transition
`public size_t `[`countAll`](#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7)`() const` | number of symbols (state occurences)
`public bool `[`hasWeightType`](#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b)`(std::string code) const` | return wether the weights in transition have the type of the code (code of the letter weight if there is one or "UNKNOWN" otherwise).
`public virtual `[`Weight`](#classWeight)` `[`weight_zero`](#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6)`() const` | return the 0 value in the weight domain in this [WTA](api-schemata.md#classWTA)
`public virtual `[`Weight`](#classWeight)` `[`weight_one`](#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd)`() const` | return the 1 value in the weight domain in this [WTA](api-schemata.md#classWTA)
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gaa6598176fb91c70988bea7cf824ec157)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` | evaluate the weight of the tree t for [WTA](api-schemata.md#classWTA) in initial state
`public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gac842f196f85e3c3b079c7c0992173e46)`(const `[`RhythmTree`](#classRhythmTree)` & t,state_t s) const` | 
`public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`max_pre`](#classWTA_1a646bb2048b24358325f8e07c789af82c)`() const` | 
`public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`max_post`](#classWTA_1a1a5cead20cba42a111ff7ab5546bc54c)`() const` | 
`public void `[`print`](#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06)`(std::ostream &) const` | print sizes to output stream
`protected std::map< state_t, `[`TransitionList`](#classTransitionList)` > `[`_table`](#classWTA_1a0d3422d597fbe64d655d9ced77dd7b8f) | transition table
`protected state_t `[`_initial`](api-schemata.md#classWTA_1a52dd7c5ad9439670d75df10f2dd1e4df) | 
`protected size_t `[`_cpt_tr`](api-schemata.md#classWTA_1a76cf3c27412f9d61464a8a82aea97b89) | number of transitions
`protected size_t `[`_cpt_size`](api-schemata.md#classWTA_1a3ed6ca11b3e520485171a0f07deffd21) | full size (number of occurences of states)
`protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_max_pre`](#classWTA_1ae6d1c616caceb7819d4d23f4a635cddc) | used only in descendant classes
`protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_max_post`](#classWTA_1acb19a9da4f88e4b3538b6889cbd49a08) | 
`protected `[`Weight`](#classWeight)` `[`_seed`](#classWTA_1ad93a124d289cf4d1e2801fccb01ca8ea) | arbitrary (polymorphic) weight value. for generation of weights in same domain with get_zero, get_one
`protected std::set< state_t > `[`step`](#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc)`(const std::set< state_t > &)` | step(s) returns the set of states reachable in one transition step by this [WTA](api-schemata.md#classWTA) from the given state set s. all the states in the set s must be registered.
`protected std::set< state_t > `[`allStates`](#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d)`() const` | returns the set of all states occuring in wta (in head or body)

## Members

#### `public std::set< state_t > `[`initials`](api-schemata.md#classWTA_1a5d8ace9f515a3902d889db560f08f4c5) {#classWTA_1a5d8ace9f515a3902d889db560f08f4c5}

set of initial states TODO SUPPR

#### `public  `[`WTA`](#group__schemata_1ga5636da911ebbe8772c5444172d56800d)`()` {#group__schemata_1ga5636da911ebbe8772c5444172d56800d}

nullary constructor for cython

#### `public  `[`WTA`](#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca)`(`[`Weight`](#classWeight)` seed,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__schemata_1ga6eeb789b8c8aa8404f611a6fed61faca}

empty automaton

#### `public  `[`~WTA`](#group__schemata_1gaacdee6c2292baea7f712c84a5e205432)`()` {#group__schemata_1gaacdee6c2292baea7f712c84a5e205432}

#### `public inline virtual bool `[`hasType`](#classWTA_1a23060c851d5cf624215c2d9dc8ad4b45)`(std::string code) const` {#classWTA_1a23060c851d5cf624215c2d9dc8ad4b45}

#### `public size_t `[`size`](#group__schemata_1gab201fee50d73843159cbef5f453838f0)`() const` {#group__schemata_1gab201fee50d73843159cbef5f453838f0}

number of states

#### `public bool `[`empty`](#group__schemata_1gada977ff7270308f29852b59f38965bde)`() const` {#group__schemata_1gada977ff7270308f29852b59f38965bde}

#### `public bool `[`isRegistered`](#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58)`(state_t) const` {#group__schemata_1ga4459bd6654cbe35b39df9cade16c6d58}

the state is present in the automaton

#### `public bool `[`isInitial`](#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6)`(state_t) const` {#group__schemata_1ga88d07a1e47cc3ee537234861b7336dd6}

the state is an initial state TBR

#### `public inline virtual state_t `[`initial`](#classWTA_1ae6b10f70925f14f36b839e5d8657bc5e)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post) const` {#classWTA_1ae6b10f70925f14f36b839e5d8657bc5e}

initial(pre, post) pre and post are use for quantification and ignored in this version (useless for schemas)

#### `public size_t `[`resolution`](#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4)`() const` {#group__schemata_1ga625d9da502c5cd554797ebe9ee9023c4}

#### `public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga924a1c533383a7185b9d466b59c5a495)`(state_t,bool initial)` {#group__schemata_1ga924a1c533383a7185b9d466b59c5a495}

add(s, i) register state s if s was already registered, return a reference to its transition list. otherwise, create state s with an empty transition list and returns a reference to it. moreover s is set as initial if i = true. TODO suppr. flag initial

#### `public `[`TransitionList`](#classTransitionList)` & `[`add`](#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2)`(state_t,const `[`Transition`](#classTransition)` &,bool initial)` {#group__schemata_1ga01de1e03d09518b38ab69a2075276ae2}

add(s, t) add a transition with head s and with body/weight described in t if s was not registered, it is registered the transition t is added to the transition list of s and a reference to this transition list is returned moreover s is set as initial if i = true. TODO suppr. flag initial

#### `public void `[`remove`](#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf)`(state_t)` {#group__schemata_1ga3d8d24249e26ecc8bbdaf672c6e8d3cf}

remove the entry for given state s in the table of the table i.e. all transitions targeted to s, and all the transitions with s in their body. if s was in the initial set, it is also removed from this set. s must be registered.

#### `public TransitionList_const_iterator `[`begin`](#group__schemata_1ga23c3f9884c683e4bbab323208e08c672)`(state_t) const` {#group__schemata_1ga23c3f9884c683e4bbab323208e08c672}

begin(s) returns an iterator pointing to the first transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.

#### `public TransitionList_const_iterator `[`end`](#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5)`(state_t) const` {#group__schemata_1gaf5075f5a210343d6da208f4c80421cb5}

begin(s) returns an iterator pointing to the past-the-end transition with head state s. s must be registered. not for modifying transition list of s. use add(...) methods for this.

#### `public size_t `[`oftarget`](#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8)`(state_t) const` {#group__schemata_1ga28c9a7e35d4d516ef0f9967e773305f8}

oftarget(s) return the number of transitions of head state s. s must be registered.

#### `public bool `[`isClean`](#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202)`() const` {#group__schemata_1ga9ef4193ae949ae7c9e52d30720e37202}

the [WTA](#classWTA) has no empty states

#### `public std::set< state_t > `[`emptyStates`](#group__schemata_1gaea41b32c37bbe955d0359039d7731fea)`() const` {#group__schemata_1gaea41b32c37bbe955d0359039d7731fea}

returns the set of all non-inhabited (zero weight) states in wta

#### `public void `[`clean`](#group__schemata_1gaec169477bdc2cf883916c38dbc18e577)`()` {#group__schemata_1gaec169477bdc2cf883916c38dbc18e577}

remove states not inhabited and transitions containing these states

#### `public void `[`normalize`](#classWTA_1aa4eda8d626af33674c59fef22c8220c1)`(unsigned int flag)` {#classWTA_1aa4eda8d626af33674c59fef22c8220c1}

for all state q, for all transition tr to q (in the transition list TL(q) of q). recompute weights to get a probabilistic [WTA](#classWTA).

with arg = 0, we assume the current [WTA](#classWTA) is a penalty model. the probability is then obtained by dividing ([Weight.scalar](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)) the inverse of the norm ([Weight.norm](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)) of the weight of the tr by the sum of inverses of norms of transitions in TL(q).

with arg = 1, we assume the current [WTA](#classWTA) is a counting model. the probability is then obtained by dividing ([Weight.scalar](#group__weight_1ga5d63ead0a1d21ee5628c643fca773903)) the norm ([Weight.norm](#group__weight_1ga68bd9621500f31ba5f0fbe04dc5a00e4)) of the weight of the tr by the sum of norms of transitions in TL(q).

#### `public void `[`CountingtoStochastic`](#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7)`()` {#group__schemata_1ga8dfef6b591f952f0fea9dae1f5e475c7}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "FloatWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "ViterbiWeight" divide by sum for target state

#### `public void `[`PenaltytoCounting`](#group__schemata_1gaff1196a45ffd1400bc4004e27b167218)`()` {#group__schemata_1gaff1196a45ffd1400bc4004e27b167218}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "TropicalWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "FloatWeight" inverse

#### `public void `[`StochastictoPenalty`](#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5)`()` {#group__schemata_1ga0bddc6750b18023be6976bd5cd46a2f5}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "ViterbiWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "TropicalWeight" -ln

#### `public void `[`CountingtoPenalty`](#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a)`()` {#group__schemata_1ga5f3a0d868bf26b504cccc53b4d55e09a}

cast weights in all transitions.

this [WTA](#classWTA) must have [Weight](#classWeight) Type "FloatWeight". this [WTA](#classWTA) is casted into [Weight](#classWeight) Type "TropicalWeight" composition of CountingtoStochastic and StochastictoPenalty

#### `public void `[`abstract`](#group__schemata_1ga91e272f4f9463149cd296f48e65a4185)`(bool flag)` {#group__schemata_1ga91e272f4f9463149cd296f48e65a4185}

abstract the leaf label values in domain [0..MAX_GRACE] every value > MAX_GRACE is casted to MAX_GRACE the weights are summed accordingly

leaf labels in domain of [Label](#classLabel) (not [SerialLabel](#classSerialLabel)). TBR unused

#### `public size_t `[`countStates`](#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915)`() const` {#group__schemata_1ga0f6551b20a213eb88c6a7e822ebc5915}

number of states

#### `public size_t `[`countTransitions`](#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a)`() const` {#group__schemata_1ga8acbd7562a6f69e7634d6b9f9e341e4a}

number of transition

#### `public size_t `[`countAll`](#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7)`() const` {#group__schemata_1ga9370cdd31619d49bfb0b18fa6b4e13b7}

number of symbols (state occurences)

#### `public bool `[`hasWeightType`](#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b)`(std::string code) const` {#group__schemata_1gaf3c11e99698a2cf7ef039632dc5e2b6b}

return wether the weights in transition have the type of the code (code of the letter weight if there is one or "UNKNOWN" otherwise).

#### `public virtual `[`Weight`](#classWeight)` `[`weight_zero`](#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6)`() const` {#group__schemata_1ga762b5bbee46468815993417ca9b3d9c6}

return the 0 value in the weight domain in this [WTA](#classWTA)

#### `public virtual `[`Weight`](#classWeight)` `[`weight_one`](#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd)`() const` {#group__schemata_1gabfe48e6398d83c03161b664dadcf8fcd}

return the 1 value in the weight domain in this [WTA](#classWTA)

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gaa6598176fb91c70988bea7cf824ec157)`(const `[`RhythmTree`](#classRhythmTree)` & t) const` {#group__schemata_1gaa6598176fb91c70988bea7cf824ec157}

evaluate the weight of the tree t for [WTA](#classWTA) in initial state

#### `public virtual `[`Weight`](#classWeight)` `[`eval`](#group__schemata_1gac842f196f85e3c3b079c7c0992173e46)`(const `[`RhythmTree`](#classRhythmTree)` & t,state_t s) const` {#group__schemata_1gac842f196f85e3c3b079c7c0992173e46}

#### `public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`max_pre`](#classWTA_1a646bb2048b24358325f8e07c789af82c)`() const` {#classWTA_1a646bb2048b24358325f8e07c789af82c}

#### `public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`max_post`](#classWTA_1a1a5cead20cba42a111ff7ab5546bc54c)`() const` {#classWTA_1a1a5cead20cba42a111ff7ab5546bc54c}

#### `public void `[`print`](#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06)`(std::ostream &) const` {#group__schemata_1gaeb713b8807bc81c6c6519ced5d531e06}

print sizes to output stream

#### `protected std::map< state_t, `[`TransitionList`](#classTransitionList)` > `[`_table`](#classWTA_1a0d3422d597fbe64d655d9ced77dd7b8f) {#classWTA_1a0d3422d597fbe64d655d9ced77dd7b8f}

transition table

#### `protected state_t `[`_initial`](api-schemata.md#classWTA_1a52dd7c5ad9439670d75df10f2dd1e4df) {#classWTA_1a52dd7c5ad9439670d75df10f2dd1e4df}

#### `protected size_t `[`_cpt_tr`](api-schemata.md#classWTA_1a76cf3c27412f9d61464a8a82aea97b89) {#classWTA_1a76cf3c27412f9d61464a8a82aea97b89}

number of transitions

#### `protected size_t `[`_cpt_size`](api-schemata.md#classWTA_1a3ed6ca11b3e520485171a0f07deffd21) {#classWTA_1a3ed6ca11b3e520485171a0f07deffd21}

full size (number of occurences of states)

#### `protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_max_pre`](#classWTA_1ae6d1c616caceb7819d4d23f4a635cddc) {#classWTA_1ae6d1c616caceb7819d4d23f4a635cddc}

used only in descendant classes

#### `protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_max_post`](#classWTA_1acb19a9da4f88e4b3538b6889cbd49a08) {#classWTA_1acb19a9da4f88e4b3538b6889cbd49a08}

#### `protected `[`Weight`](#classWeight)` `[`_seed`](#classWTA_1ad93a124d289cf4d1e2801fccb01ca8ea) {#classWTA_1ad93a124d289cf4d1e2801fccb01ca8ea}

arbitrary (polymorphic) weight value. for generation of weights in same domain with get_zero, get_one

#### `protected std::set< state_t > `[`step`](#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc)`(const std::set< state_t > &)` {#group__schemata_1gae6fb2dbd82ed290528b90ee7bb4b6ccc}

step(s) returns the set of states reachable in one transition step by this [WTA](#classWTA) from the given state set s. all the states in the set s must be registered.

#### `protected std::set< state_t > `[`allStates`](#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d)`() const` {#group__schemata_1gab8ea841b4a1e71ef70d3fda927f0507d}

returns the set of all states occuring in wta (in head or body)

# class `DepthMarking` {#classDepthMarking}

marking of states of a [WTA](#classWTA) with informations on the depth of their occurences initialized with a [WTA](#classWTA), can be interrogated afterwards

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DepthMarking`](#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935)`(const `[`WTA`](#classWTA)` &)` | 
`public int `[`depth`](#group__schemata_1gaaa84e1d149651938af82e47b91888017)`(state_t) const` | return depth mark if given state marked return -1 otherwise
`public bool `[`multiple`](#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b)`(state_t) const` | return true if the given state can occur at multiple depths return false otherwise or if state not marked
`public int `[`mark`](#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d)`(state_t,int)` | mark state using given depth and return new mark value can be the given depth or a greater depth with which the state had been already marked.

## Members

#### `public  `[`DepthMarking`](#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935)`(const `[`WTA`](#classWTA)` &)` {#group__schemata_1gaf0a0a9f458a39032b2c653a99f609935}

#### `public int `[`depth`](#group__schemata_1gaaa84e1d149651938af82e47b91888017)`(state_t) const` {#group__schemata_1gaaa84e1d149651938af82e47b91888017}

return depth mark if given state marked return -1 otherwise

#### `public bool `[`multiple`](#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b)`(state_t) const` {#group__schemata_1gad5f3fa885bb5d2be624a26e9aa50dd0b}

return true if the given state can occur at multiple depths return false otherwise or if state not marked

#### `public int `[`mark`](#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d)`(state_t,int)` {#group__schemata_1ga3486fcb9921f3c018b931e088a53df7d}

mark state using given depth and return new mark value can be the given depth or a greater depth with which the state had been already marked.

# struct `ComboStateHasher` {#structComboStateHasher}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structComboStateHasher_1a5468e36007a90b6cb2dd915148589991)`(const `[`ComboState`](#classComboState)` & cs) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structComboStateHasher_1a5468e36007a90b6cb2dd915148589991)`(const `[`ComboState`](#classComboState)` & cs) const` {#structComboStateHasher_1a5468e36007a90b6cb2dd915148589991}

# struct `ds_transition` {#structds__transition}

dag schema

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`dst_source`](api-schemata.md#structds__transition_1a8abb4ba3aafb140f77b5adfce9f9c35e) | 
`public size_t `[`dst_label`](api-schemata.md#structds__transition_1ad363afd9368d0aef7c1f967d860087d5) | 
`public unsigned int `[`dst_target`](api-schemata.md#structds__transition_1ad3882a8e6a30e09084584fcf0455268d) | 
`public inline  `[`ds_transition`](#structds__transition_1af0120de2744bb7e6eaebeb80c014cd2d)`(unsigned int s,size_t l,unsigned int t)` | #### Parameters
`public inline  `[`ds_transition`](#structds__transition_1a812425a6466f00721e3426430f4bd2bb)`(const `[`ds_transition`](#structds__transition)` & dst)` | 
`public void `[`rename`](#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b)`(unsigned int s,unsigned int u)` | 
`public void `[`shift`](#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84)`(unsigned int n)` | increase source and target state by n
`public void `[`shift0`](#group__schemata_1ga811afd94c0a2afda729115e1afade496)`(unsigned int n)` | increase source and target state by n, if they are not 0

## Members

#### `public unsigned int `[`dst_source`](api-schemata.md#structds__transition_1a8abb4ba3aafb140f77b5adfce9f9c35e) {#structds__transition_1a8abb4ba3aafb140f77b5adfce9f9c35e}

#### `public size_t `[`dst_label`](api-schemata.md#structds__transition_1ad363afd9368d0aef7c1f967d860087d5) {#structds__transition_1ad363afd9368d0aef7c1f967d860087d5}

#### `public unsigned int `[`dst_target`](api-schemata.md#structds__transition_1ad3882a8e6a30e09084584fcf0455268d) {#structds__transition_1ad3882a8e6a30e09084584fcf0455268d}

#### `public inline  `[`ds_transition`](#structds__transition_1af0120de2744bb7e6eaebeb80c014cd2d)`(unsigned int s,size_t l,unsigned int t)` {#structds__transition_1af0120de2744bb7e6eaebeb80c014cd2d}

#### Parameters
* `s` source_state 

* `l` arity_val 

* `t` target_state

#### `public inline  `[`ds_transition`](#structds__transition_1a812425a6466f00721e3426430f4bd2bb)`(const `[`ds_transition`](#structds__transition)` & dst)` {#structds__transition_1a812425a6466f00721e3426430f4bd2bb}

#### `public void `[`rename`](#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b)`(unsigned int s,unsigned int u)` {#group__schemata_1ga99612639925cfc0a63a173ea167a6d3b}

#### `public void `[`shift`](#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84)`(unsigned int n)` {#group__schemata_1gaa6bf3664ce3ec4ceddc6fc0546e7af84}

increase source and target state by n

#### `public void `[`shift0`](#group__schemata_1ga811afd94c0a2afda729115e1afade496)`(unsigned int n)` {#group__schemata_1ga811afd94c0a2afda729115e1afade496}

increase source and target state by n, if they are not 0

# struct `ValueStateHasher` {#structValueStateHasher}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structValueStateHasher_1a1d8ffc1cdea4f157957f66041fcbf7f6)`(const `[`ValueState`](#classValueState)` & vs) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structValueStateHasher_1a1d8ffc1cdea4f157957f66041fcbf7f6)`(const `[`ValueState`](#classValueState)` & vs) const` {#structValueStateHasher_1a1d8ffc1cdea4f157957f66041fcbf7f6}

