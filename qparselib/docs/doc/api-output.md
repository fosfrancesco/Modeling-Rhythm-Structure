# group `output` {#group__output}

The `output` module contains representations for the output of the parsing procedure and conversion into music transcription results.

[MEI](#classMEI) interface. Can be used to output [MEI](#classMEI) document from a transcription result

Philippe Rigaux

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`RT_PAR_OPEN`](#group__output_1gae303eba6aa9e3b8613a5795c73e4fbea)            | 
`define `[`RT_PAR_CLOSE`](#group__output_1gae92f0807f278bf37adf40090ad2dc4be)            | 
`define `[`RT_SEP`](#group__output_1ga503dde6f933b959604bbeb17820933d5)            | 
`enum `[`LabelKind`](#group__output_1ga3ff5a8deeeca12e8b6fea9c51eccd987)            | 
`public std::ostream & `[`operator<<`](#group__output_1gaca893b02b4d6e0b4a33e08e8fedd3e00)`(std::ostream & o,const `[`DurationList`](#classDurationList)` & l)`            | 
`public inline bool `[`operator==`](#group__output_1gaa14d56806f18314e1c59a090964bc687)`(const `[`DurationList`](#classDurationList)` & lhs,const `[`DurationList`](#classDurationList)` & rhs)`            | 
`public inline bool `[`operator!=`](#group__output_1ga6a883cabc768b899c9a5edcd3c3d5dd2)`(const `[`DurationList`](#classDurationList)` & lhs,const `[`DurationList`](#classDurationList)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#group__output_1ga580b3f6969d32fc7ad84b7d6fec0ecbe)`(std::ostream & o,const `[`DurationTree`](#classDurationTree)` & t)`            | 
`public std::ostream & `[`operator<<`](#group__output_1gad0161a497bb5a9861366ec032cd79392)`(std::ostream & o,const `[`OMRhythmTree`](#classOMRhythmTree)` & t)`            | 
`public const `[`Onsets`](#classOnsets)` `[`operator+`](#group__output_1ga42a2ffdfe358dcac1df9704c4179dfeb)`(const `[`Onsets`](#classOnsets)` & lhs,const `[`Onsets`](#classOnsets)` & rhs)`            | ordered merge
`public inline std::ostream & `[`operator<<`](#group__output_1ga633737bbc1050067a6ae18fac4de863f)`(std::ostream & o,const `[`QDate`](#classQDate)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#group__output_1ga352cef0201630bbd48cc2cd14ecbe5ab)`(std::ostream & o,const `[`Position`](#classPosition)` & pos)`            | 
`public std::ostream & `[`operator<<`](#group__output_1gaccc3468661637ee13e14eb176997086f)`(std::ostream & o,const `[`RhythmTree`](#classRhythmTree)` & t)`            | 
`public inline `[`Position`](#classPosition)` `[`operator+`](#group__output_1gaa15fcbf280e167eab1fe03f9c0f5663c)`(const `[`Position`](#classPosition)` & p,const size_t & i)`            | 
`public std::ostream & `[`operator<<`](#group__output_1ga857c7d77fd72ff4aa331c2d7aa1ff9b2)`(std::ostream & o,const `[`ValueList`](#classValueList)` & l)`            | 
`public inline bool `[`operator==`](#group__output_1gaca91eab87be1cd794334474670baa188)`(const `[`ValueList`](#classValueList)` & lhs,const `[`ValueList`](#classValueList)` & rhs)`            | 
`public inline bool `[`operator!=`](#group__output_1gaad126050f09b6e61d8a4bda13c17ad8a)`(const `[`ValueList`](#classValueList)` & lhs,const `[`ValueList`](#classValueList)` & rhs)`            | 
`public string `[`APTED`](#group__output_1ga2c194b384127267b8cfed2c41e70d338)`() const`            | format for Tree Edit [Distance](api-weight.md#classDistance) Salzburg library.
`public  `[`DurationList`](#group__output_1ga24f753a9aa9316fc7903e6f253b94944)`()`            | empty duration list.
`public  `[`DurationList`](#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8)`(const `[`DurationList`](#classDurationList)` &)`            | 
`public `[`DurationList`](#classDurationList)` & `[`operator=`](#group__output_1ga831728f737383383f8f74580161eb3fb)`(const `[`DurationList`](#classDurationList)` &)`            | 
`public  `[`DurationList`](#group__output_1ga95ba6b1b14592003fdc97b69f982677c)`(const `[`DurationList`](#classDurationList)` & l,`[`Rational`](#classRational)` q)`            | copy of duration list l where all elements are multiplied by given Ratio q.
`public  `[`DurationList`](#group__output_1gab678d41f41605596499c3f17a5f39120)`(std::string)`            | read duration list from file.
`public bool `[`empty`](#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a)`() const`            | 
`private bool `[`_check_empty`](#group__output_1ga804e83e82fca5380650865ce1feabb6d)`() const`            | for asserts (check _state correctness).
`public bool `[`complete`](#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54)`() const`            | 
`private bool `[`_check_complete`](#group__output_1gae04a60c20656f2fe0eb9b6df23fa5948)`() const`            | 
`public bool `[`unit`](#group__output_1ga130ef44efbc7af3c3c9a6efa23639378)`() const`            | 
`private bool `[`_check_unit`](#group__output_1ga74cb6301d04160f6fe40d27355b9c6f5)`() const`            | 
`public bool `[`single_continuation`](#group__output_1ga8b4434664a0dd2938fae9791fd34febd)`() const`            | one (non null) continuation and no event in the main list.
`private bool `[`_check_single_continuation`](#group__output_1ga9c011b8c82332aaeaac790470d33bbbf)`() const`            | 
`public bool `[`single_event`](#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471)`() const`            | no continuation and only one event in the main list.
`private bool `[`_check_single_event`](#group__output_1ga22ddcbbc15b283f49cfa8cc6b98ed906)`() const`            | 
`public bool `[`event`](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)`() const`            | no continuation and some grace notes (dur=0) + one event (dur>0) in the main list.
`private bool `[`_check_event`](#group__output_1ga2f27ece8ac0781de8497f485a7e83c71)`() const`            | 
`private bool `[`_check_gracenotes`](#group__output_1ga6f10e2b817fd6b2ec1e4cbea3df91c31)`() const`            | 
`private bool `[`_check_state`](#group__output_1gacf08ddb1cdc1cab5abbad781d8ddd006)`() const`            | the state value is correct.
`public size_t `[`nbgn`](#group__output_1ga72427605bbceabff329459a610db1201)`() const`            | number of grace note must be an [event()](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)
`private `[`Rational`](#classRational)` `[`_compute_length`](#group__output_1ga3afa63ce4cfad77e1b2fb9cb4bb76847)`() const`            | 
`public `[`Rational`](#classRational)` `[`length`](#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de)`() const`            | sum of the elements of the duration list (including continuation)
`public void `[`add`](#group__output_1gaddb48455388f36f48ace0f0c0b250105)`(`[`Rational`](#classRational)`)`            | add the event at the end of the main list.
`public void `[`addcont`](#group__output_1gab9d508060073c83c27e13f8f2472de38)`(`[`Rational`](#classRational)`)`            | push a continuation value.
`public `[`DurationList`](#classDurationList)` & `[`operator+=`](#group__output_1ga06ae4f865c1c27edd490f1631d76452a)`(const `[`DurationList`](#classDurationList)` & rhs)`            | concatenation.
`public void `[`normalize`](#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5)`()`            | divide by the number of lists summed.
`public  `[`~DurationTree`](#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6)`()`            | 
`public  `[`DurationTree`](#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8)`(const `[`DurationList`](#classDurationList)` & d)`            | 
`public `[`DurationTree`](#classDurationTree)` * `[`sub`](#group__output_1ga524c96edadc8725d997f81de3663ce4d)`(size_t,size_t)`            | 
`public  `[`Label`](#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00)`(int a)`            | 
`public size_t `[`arity`](#group__output_1ga189208973cef74bb65357535d43885ed)`() const`            | 
`public static size_t `[`nbGraceNotes`](#group__output_1ga9c677c6efeee575a05c0a32511ad7cf1)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | 
`public static size_t `[`nbEvents`](#group__output_1ga58660df99e9a20f35ee0dab2901aa637)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | 
`public static bool `[`continuation`](#group__output_1ga56a227805fd6d43d1f2618e871a4108c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | 
`public static bool `[`abstract`](#group__output_1ga3724371343de270b6f488ca47d11b917)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | 
`public static bool `[`abstract`](#group__output_1ga07b8cb2137bfde63b8f2686ed6f20db0)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` a,`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` n)`            | 
`public static bool `[`leqabstract`](#group__output_1ga686ea0e366bdefcf68714e411cad577f)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` a,`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` n)`            | 
`public  `[`InnerLabel`](#group__output_1ga7679a09f4cdd668f395a24deb498cdc2)`(unsigned int)`            | 
`public  `[`EventLabel`](#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9)`()`            | 
`public  `[`EventLabel`](#group__output_1gad5d7a4117cae3ac10b55ea051aa92848)`(unsigned int n)`            | 
`public size_t `[`nbGraceNotes`](#group__output_1gae8b849bfdbed392ff2171126354210a0)`() const`            | 
`public void `[`addGraceNotes`](#group__output_1ga77779608bf4588f37330cecaf4cc2f1e)`(unsigned int)`            | 
`public void `[`pushEvent`](#group__output_1ga6a71e2488e33f2556ee9051d0bc88820)`(Event *)`            | 
`public string `[`lily`](#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259)`(int depth,bool tie) const`            | LilyPond format.
`public string `[`lilydot`](#group__output_1ga93aca0f691a35a081d51eaad06e8ce50)`(int depth)`            | LilyPond format with dots.
`protected string `[`lilydot`](#group__output_1ga89f5bf140b902f886be124d620ac8474)`(int depth,bool tie,bool dot,bool ignore_first,bool ignore_second)`            | LilyPond format with dots.
`public  `[`MEI`](#group__output_1ga67acb233e47d9942cb678fb24b67f799)`()`            | Main constructor
`public void `[`createFromScore`](#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)`            | 
`public void `[`createScoreDef`](#group__output_1gaec3627352aed16ef31dfabe7d243c476)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)`            | Create the score definition part
`public std::pair< string, int > `[`chooseClef`](#group__output_1ga707656b4b214953f8be23c95415a8ed5)`(std::pair< `[`Pitch](#classPitch), [Pitch`](#classPitch)` > range)`            | Choose a clef based on range
`public void `[`writeInFile`](#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da)`(const string fname)`            | Save in file
`public static Note * `[`makeNote`](#group__output_1ga6c05e4fec7d79e79d9022130e8fef2ad)`(const `[`ScoreModel::Note`](#classScoreModel_1_1Note)` * noteEvent)`            | 
`public static Tie * `[`makeTie`](#group__output_1gafa5b4ccd58b7537120b30437c8072852)`(const ScoreModel::Tie * tie)`            | 
`public static TupletSpan * `[`makeTupletSpan`](#group__output_1gabbdc2a86af7313ccc63b1b502d9b0aa5)`(const `[`ScoreModel::Tuplet`](#classScoreModel_1_1Tuplet)` * tuplet)`            | 
`public  `[`~MEI`](#group__output_1ga1e4233e0a65d642f227dba08be1fe592)`()`            | Destructor
`public  `[`OMRhythmTree`](#group__output_1gafa2112e5abf005b87ad68073ac92670f)`()`            | 
`public  `[`OMRhythmTree`](#group__output_1gac708fcabf8489ca08a9f7231eeb928d0)`(`[`Rational`](#classRational)` lab,bool tied)`            | 
`public  `[`OMRhythmTree`](#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3)`(const `[`RhythmTree`](#classRhythmTree)` *,`[`Rational`](#classRational)` dur)`            | 
`public  `[`~OMRhythmTree`](#group__output_1gaea89bed9d2782e13bf697069147331a4)`()`            | 
`public size_t `[`size`](#group__output_1ga5877122dcb737ec9bdbe94241b867b4e)`() const`            | 
`public `[`OMRhythmTree`](#classOMRhythmTree)` * `[`child`](#group__output_1ga59d59642fc58d66772d51a075720a701)`(size_t) const`            | 
`public void `[`add`](#group__output_1ga6e273a3942470268fb775857d80bc2a8)`(`[`OMRhythmTree`](#classOMRhythmTree)` *)`            | 
`public string `[`to_string`](#group__output_1ga14633b5c977b30f4a28085c686c3c17f)`() const`            | 
`public  `[`Onsets`](#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f)`(const `[`DurationList`](#classDurationList)` &)`            | the list of onsets defined by the given duration list (IOI's) the first onset is 0.
`public `[`DurationList`](#classDurationList)` `[`ioi`](#group__output_1gad3393b6422e8708954e27a52933620e1)`() const`            | the list of IOI associated to this list of onsets.
`public  `[`PointedRhythmTree`](#group__output_1gaf7f8a09842cce99950290469727cb4f2)`()`            | 
`public  `[`PointedRhythmTree`](#group__output_1ga00153f3142fe2d750b995d95435d852e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)`            | 
`public  `[`PointedRhythmTree`](#group__output_1gad86382b8bc2a62cc5d8848c516280c52)`(const `[`RhythmTree`](#classRhythmTree)` *,const `[`InputSegment`](#classInputSegment)` *,size_t i)`            | 
`public  `[`~PointedRhythmTree`](#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28)`()`            | 
`public  `[`QDate`](#group__output_1gac553172d4c172c75bb78e9b246eaa0a1)`()`            | 
`public  `[`QDate`](#group__output_1ga1151b393ffd2c621914c8e0641fff3d3)`(size_t blocs,size_t rel)`            | 
`public  `[`QDate`](#group__output_1gab39d4fd438b410d8310f4bf43703904f)`(const `[`QDate`](#classQDate)` &)`            | 
`public virtual `[`QDate`](#classQDate)` & `[`operator=`](#group__output_1ga28238d09bb0f332bda66fafb92facb3b)`(const `[`QDate`](#classQDate)` &)`            | 
`public virtual `[`QDate`](#classQDate)` * `[`clone`](#group__output_1ga59599012a00e9c2ae587144f47085130)`() const`            | 
`public `[`Rational`](#classRational)` `[`absolute`](#group__output_1ga07a4414576afc26204002ce92dcc7ce9)`(size_t res) const`            | quantified date as rational value.
`public void `[`print`](#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36)`(std::ostream &) const`            | 
`public void `[`print`](#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1)`(std::ostream &,size_t) const`            | fractional print using resolution value.
`public  `[`Position`](#group__output_1ga369a577425f8ba02e8750d04b6a088db)`()`            | empty sequence = root position
`public  `[`Position`](#group__output_1ga63750e368482cc5ef45180d3672b1c55)`(const `[`Position`](#classPosition)` &)`            | 
`public bool `[`empty`](#group__output_1ga886868520756636e98110cdb06349326)`() const`            | 
`public size_t `[`length`](#group__output_1ga009f3b456aa0995413db1b8c0bd6f374)`() const`            | 
`public void `[`operator+=`](#group__output_1gab6b7dd5c2869fb23755faee32f1e6731)`(size_t i)`            | concatenate given int to this position
`protected void `[`print`](#group__output_1ga19d238e39cbe5a9f03929473bbd5b745)`(std::ostream & o) const`            | 
`public  `[`RhythmTree`](#group__output_1gac7614a6239a4917c771641dfdfd597ab)`()`            | empty inner tree (not terminal)
`public  `[`RhythmTree`](#group__output_1gac868521df843e116ef04bcfa52405d01)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)`            | single leaf rhythm tree (terminal tree)
`public  `[`RhythmTree`](#group__output_1ga058c6d59881e1be259594165d19c8588)`(const string &)`            | extract RT from string description
`private void `[`read_tree`](#group__output_1ga70f6b23946fcfd1823b9fb3fde9506a3)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)`            | 
`private void `[`read_space`](#group__output_1gafd2cba61567f7096dc5050bca22cf4f1)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)`            | 
`private void `[`read_int`](#group__output_1ga1b87a8ab06f066092cf5d9dac5a5497c)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)`            | 
`private void `[`read_list`](#group__output_1gac45127942de2570f415b8e4dd0c5c20c)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)`            | 
`public  `[`~RhythmTree`](#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee)`()`            | 
`public bool `[`terminal`](#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd)`() const`            | single node tree
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350)`() const`            | label for terminal node
`public bool `[`continuation`](#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0)`() const`            | label of terminal node is a continuation
`public bool `[`single_event`](#group__output_1gabd793b78f71fb62edb13497e0a13f48c)`() const`            | label of terminal node is a single event (1 note / rest, no grace note).
`public size_t `[`nbgn`](#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7)`() const`            | number of grace notes in this terminal node.
`public size_t `[`arity`](#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e)`() const`            | arity of root node (0 for terminal tree)
`public `[`RhythmTree`](#classRhythmTree)` * `[`child`](#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd)`(size_t i) const`            | return the ith child of this tree
`public void `[`add`](#group__output_1ga5749469b3ff6ec88fcab75961e7d278c)`(`[`RhythmTree`](#classRhythmTree)` *)`            | add a subtree.
`public bool `[`reducible`](#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9)`() const`            | this tree contains a subtree of the form.
`protected bool `[`tail_redex`](#group__output_1gaf723874e871dc01efb036ccbac07c32b)`() const`            | inner and the children list is of the form.
`protected bool `[`tail_reducible`](#group__output_1ga799761965ae00bb24e16ebb98f66995a)`() const`            | inner and one of the children 1..a is reducible.
`protected bool `[`tie`](#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47)`() const`            | return whether this tree is a continuation (a leaf).
`protected bool `[`tied`](#group__output_1gacd73e0032e3dd22320819c4cda3d60a4)`() const`            | return whether the leftmost innermost leaf is a tie (continuation).
`protected bool `[`binary`](#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72)`() const`            | return whether this tree is binary.
`protected bool `[`second_tied`](#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4)`() const`            | return whether this tree is binary and the second child is tied.
`protected bool `[`dot_after`](#group__output_1gac785e6d945ef6e0808132459669ab038)`() const`            | return whether this tree is binary and the left son is a dot (continuation after the dotted note).
`protected bool `[`dot_before`](#group__output_1ga2079bd534900d0b10e74682e404230b1)`() const`            | return whether this tree is binary and the right son is a dot (continuation before the dotted note).
`public string `[`to_string`](#group__output_1gac6764688e24fe9b942464a9c2053ee92)`() const`            | 
`public static size_t `[`nbEvents`](#group__output_1ga2d7e95e5b2cc887aa9c4db52fab1b0d3)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | number of note + grace notes encoded in given leaf label
`public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#group__output_1ga3d92180f844d00eaf0bbd46e10f022e4)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | return the pre value of the given leaf label
`public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#group__output_1ga7c5289addb03e9bf54467e2d84c7ef79)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | return the post value of the given leaf label
`public static size_t `[`nbGraceNotes`](#group__output_1ga0f5679843d6bcd3e97ecd535c4d3c6f8)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | return the number of grace node encoded in given leaf label
`public static bool `[`continuation`](#group__output_1gaaf4c88a23710366cbe35081a0967b536)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | the given leaf label is a continuation (no event, no grace note)
`public static `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`serialize`](#group__output_1ga69973921641222cb765112c70df25318)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,size_t nb)`            | return the leaf label encoding the given
`public  `[`ValueList`](#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185)`(`[`Rational`](#classRational)`)`            | 
`public  `[`ValueList`](#group__output_1gad518d3f6ddf7fb7b74275eef20205893)`(std::string)`            | 
`public  `[`ValueList`](#group__output_1gaec135d71a5c51579bec52c805c0b3ded)`(const `[`DurationList`](#classDurationList)` &)`            | 
`public  `[`ValueList`](#group__output_1gabd7a0aa8113f72c13205c0702eb269ff)`(const `[`ValueList`](#classValueList)` &)`            | 
`public `[`ValueList`](#classValueList)` & `[`operator=`](#group__output_1gab09ac2a5e83e806431634ddd87f596fc)`(const `[`ValueList`](#classValueList)` &)`            | 
`public bool `[`empty`](#group__output_1ga7510db734db466464100413728db233c)`() const`            | 
`public bool `[`complete`](#group__output_1ga2ebf6a43ad145e4593cc961a4016f330)`() const`            | 
`public bool `[`single_continuation`](#group__output_1ga9d68ca01f81000f92f1c8911cbd414da)`() const`            | 
`public bool `[`event`](#group__output_1gaff6e5912f71832597303efe0093d5d00)`() const`            | 
`public bool `[`single_event`](#group__output_1ga699183ea1d3babeb7c2c094e31e7070f)`() const`            | 
`public void `[`add`](#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0)`(`[`Rational`](#classRational)`)`            | 
`public void `[`addcont`](#group__output_1gaeb6d26ee1813f879c07148df644a5321)`(`[`Rational`](#classRational)`)`            | 
`public `[`Rational`](#classRational)` `[`front`](#group__output_1ga282fe7cbc28917f2b096d2183419a30c)`() const`            | 
`public `[`Rational`](#classRational)` `[`pop`](#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed)`()`            | 
`public `[`Rational`](#classRational)` `[`popcont`](#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9)`()`            | 
`public void `[`popcont`](#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea)`(`[`Rational`](#classRational)`)`            | 
`namespace `[`std`](#namespacestd) | 
`class `[`DurationList`](api-output.md#classDurationList) | list of rational durations to label nodes of [WTA](api-schemata.md#classWTA) Runs for Kbest enum.
`class `[`DurationTree`](api-output.md#classDurationTree) | a tree container for duration lists. to avoid recomputation of division of duration lists.
`class `[`Label`](api-output.md#classLabel) | labels for nodes of output Rhythm Trees.
`class `[`InnerLabel`](api-output.md#classInnerLabel) | 
`class `[`EventLabel`](api-output.md#classEventLabel) | 
`class `[`MEI`](api-output.md#classMEI) | The main [MEI](api-output.md#classMEI) class.
`class `[`OMRhythmTree`](api-output.md#classOMRhythmTree) | 
`class `[`Onsets`](api-output.md#classOnsets) | sequence of onsets used for merge of duration lists.
`class `[`PointedRhythmTree`](api-output.md#classPointedRhythmTree) | 
`class `[`QDate`](api-output.md#classQDate) | quantified onset values expressed in number of samples.
`class `[`Position`](api-output.md#classPosition) | position in a RT.
`class `[`RhythmTree`](api-output.md#classRhythmTree) | Rhythm Trees.
`class `[`SerialLabel`](api-output.md#classSerialLabel) | static functions for serializable int encoding of input and output leaf symbols containing the following info:
`class `[`ValueList`](api-output.md#classValueList) | list of rational durations as components of value states.

## Members

#### `define `[`RT_PAR_OPEN`](#group__output_1gae303eba6aa9e3b8613a5795c73e4fbea) {#group__output_1gae303eba6aa9e3b8613a5795c73e4fbea}

#### `define `[`RT_PAR_CLOSE`](#group__output_1gae92f0807f278bf37adf40090ad2dc4be) {#group__output_1gae92f0807f278bf37adf40090ad2dc4be}

#### `define `[`RT_SEP`](#group__output_1ga503dde6f933b959604bbeb17820933d5) {#group__output_1ga503dde6f933b959604bbeb17820933d5}

#### `enum `[`LabelKind`](#group__output_1ga3ff5a8deeeca12e8b6fea9c51eccd987) {#group__output_1ga3ff5a8deeeca12e8b6fea9c51eccd987}

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
EVENT            | 
TIE            | 
INNER            | 

#### `public std::ostream & `[`operator<<`](#group__output_1gaca893b02b4d6e0b4a33e08e8fedd3e00)`(std::ostream & o,const `[`DurationList`](#classDurationList)` & l)` {#group__output_1gaca893b02b4d6e0b4a33e08e8fedd3e00}

#### `public inline bool `[`operator==`](#group__output_1gaa14d56806f18314e1c59a090964bc687)`(const `[`DurationList`](#classDurationList)` & lhs,const `[`DurationList`](#classDurationList)` & rhs)` {#group__output_1gaa14d56806f18314e1c59a090964bc687}

#### `public inline bool `[`operator!=`](#group__output_1ga6a883cabc768b899c9a5edcd3c3d5dd2)`(const `[`DurationList`](#classDurationList)` & lhs,const `[`DurationList`](#classDurationList)` & rhs)` {#group__output_1ga6a883cabc768b899c9a5edcd3c3d5dd2}

#### `public std::ostream & `[`operator<<`](#group__output_1ga580b3f6969d32fc7ad84b7d6fec0ecbe)`(std::ostream & o,const `[`DurationTree`](#classDurationTree)` & t)` {#group__output_1ga580b3f6969d32fc7ad84b7d6fec0ecbe}

#### `public std::ostream & `[`operator<<`](#group__output_1gad0161a497bb5a9861366ec032cd79392)`(std::ostream & o,const `[`OMRhythmTree`](#classOMRhythmTree)` & t)` {#group__output_1gad0161a497bb5a9861366ec032cd79392}

#### `public const `[`Onsets`](#classOnsets)` `[`operator+`](#group__output_1ga42a2ffdfe358dcac1df9704c4179dfeb)`(const `[`Onsets`](#classOnsets)` & lhs,const `[`Onsets`](#classOnsets)` & rhs)` {#group__output_1ga42a2ffdfe358dcac1df9704c4179dfeb}

ordered merge

#### `public inline std::ostream & `[`operator<<`](#group__output_1ga633737bbc1050067a6ae18fac4de863f)`(std::ostream & o,const `[`QDate`](#classQDate)` & rhs)` {#group__output_1ga633737bbc1050067a6ae18fac4de863f}

#### `public std::ostream & `[`operator<<`](#group__output_1ga352cef0201630bbd48cc2cd14ecbe5ab)`(std::ostream & o,const `[`Position`](#classPosition)` & pos)` {#group__output_1ga352cef0201630bbd48cc2cd14ecbe5ab}

#### `public std::ostream & `[`operator<<`](#group__output_1gaccc3468661637ee13e14eb176997086f)`(std::ostream & o,const `[`RhythmTree`](#classRhythmTree)` & t)` {#group__output_1gaccc3468661637ee13e14eb176997086f}

#### `public inline `[`Position`](#classPosition)` `[`operator+`](#group__output_1gaa15fcbf280e167eab1fe03f9c0f5663c)`(const `[`Position`](#classPosition)` & p,const size_t & i)` {#group__output_1gaa15fcbf280e167eab1fe03f9c0f5663c}

#### `public std::ostream & `[`operator<<`](#group__output_1ga857c7d77fd72ff4aa331c2d7aa1ff9b2)`(std::ostream & o,const `[`ValueList`](#classValueList)` & l)` {#group__output_1ga857c7d77fd72ff4aa331c2d7aa1ff9b2}

#### `public inline bool `[`operator==`](#group__output_1gaca91eab87be1cd794334474670baa188)`(const `[`ValueList`](#classValueList)` & lhs,const `[`ValueList`](#classValueList)` & rhs)` {#group__output_1gaca91eab87be1cd794334474670baa188}

#### `public inline bool `[`operator!=`](#group__output_1gaad126050f09b6e61d8a4bda13c17ad8a)`(const `[`ValueList`](#classValueList)` & lhs,const `[`ValueList`](#classValueList)` & rhs)` {#group__output_1gaad126050f09b6e61d8a4bda13c17ad8a}

#### `public string `[`APTED`](#group__output_1ga2c194b384127267b8cfed2c41e70d338)`() const` {#group__output_1ga2c194b384127267b8cfed2c41e70d338}

format for Tree Edit [Distance](#classDistance) Salzburg library.

RT output format for Tree Edit [Distance](#classDistance) library APTED algorithm of M. Pawlik and N. Augsten [http://tree-edit-distance.dbresearch.uni-salzburg.at](http://tree-edit-distance.dbresearch.uni-salzburg.at).

#### `public  `[`DurationList`](#group__output_1ga24f753a9aa9316fc7903e6f253b94944)`()` {#group__output_1ga24f753a9aa9316fc7903e6f253b94944}

empty duration list.

#### `public  `[`DurationList`](#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8}

#### `public `[`DurationList`](#classDurationList)` & `[`operator=`](#group__output_1ga831728f737383383f8f74580161eb3fb)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga831728f737383383f8f74580161eb3fb}

#### `public  `[`DurationList`](#group__output_1ga95ba6b1b14592003fdc97b69f982677c)`(const `[`DurationList`](#classDurationList)` & l,`[`Rational`](#classRational)` q)` {#group__output_1ga95ba6b1b14592003fdc97b69f982677c}

copy of duration list l where all elements are multiplied by given Ratio q.

#### Parameters
* `l` suration list to copy and update 

* `q` given ratio for update

#### `public  `[`DurationList`](#group__output_1gab678d41f41605596499c3f17a5f39120)`(std::string)` {#group__output_1gab678d41f41605596499c3f17a5f39120}

read duration list from file.

one ratio per line if the first line is negative ratio, it is a continuation all other line must contain positive or null ratios. the file must not be empty.

TBR only for testing.

#### `public bool `[`empty`](#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a)`() const` {#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a}

#### `private bool `[`_check_empty`](#group__output_1ga804e83e82fca5380650865ce1feabb6d)`() const` {#group__output_1ga804e83e82fca5380650865ce1feabb6d}

for asserts (check _state correctness).

#### `public bool `[`complete`](#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54)`() const` {#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54}

#### `private bool `[`_check_complete`](#group__output_1gae04a60c20656f2fe0eb9b6df23fa5948)`() const` {#group__output_1gae04a60c20656f2fe0eb9b6df23fa5948}

#### `public bool `[`unit`](#group__output_1ga130ef44efbc7af3c3c9a6efa23639378)`() const` {#group__output_1ga130ef44efbc7af3c3c9a6efa23639378}

#### `private bool `[`_check_unit`](#group__output_1ga74cb6301d04160f6fe40d27355b9c6f5)`() const` {#group__output_1ga74cb6301d04160f6fe40d27355b9c6f5}

#### `public bool `[`single_continuation`](#group__output_1ga8b4434664a0dd2938fae9791fd34febd)`() const` {#group__output_1ga8b4434664a0dd2938fae9791fd34febd}

one (non null) continuation and no event in the main list.

#### `private bool `[`_check_single_continuation`](#group__output_1ga9c011b8c82332aaeaac790470d33bbbf)`() const` {#group__output_1ga9c011b8c82332aaeaac790470d33bbbf}

#### `public bool `[`single_event`](#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471)`() const` {#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471}

no continuation and only one event in the main list.

#### `private bool `[`_check_single_event`](#group__output_1ga22ddcbbc15b283f49cfa8cc6b98ed906)`() const` {#group__output_1ga22ddcbbc15b283f49cfa8cc6b98ed906}

#### `public bool `[`event`](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)`() const` {#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc}

no continuation and some grace notes (dur=0) + one event (dur>0) in the main list.

#### `private bool `[`_check_event`](#group__output_1ga2f27ece8ac0781de8497f485a7e83c71)`() const` {#group__output_1ga2f27ece8ac0781de8497f485a7e83c71}

#### `private bool `[`_check_gracenotes`](#group__output_1ga6f10e2b817fd6b2ec1e4cbea3df91c31)`() const` {#group__output_1ga6f10e2b817fd6b2ec1e4cbea3df91c31}

#### `private bool `[`_check_state`](#group__output_1gacf08ddb1cdc1cab5abbad781d8ddd006)`() const` {#group__output_1gacf08ddb1cdc1cab5abbad781d8ddd006}

the state value is correct.

#### `public size_t `[`nbgn`](#group__output_1ga72427605bbceabff329459a610db1201)`() const` {#group__output_1ga72427605bbceabff329459a610db1201}

number of grace note must be an [event()](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)

#### `private `[`Rational`](#classRational)` `[`_compute_length`](#group__output_1ga3afa63ce4cfad77e1b2fb9cb4bb76847)`() const` {#group__output_1ga3afa63ce4cfad77e1b2fb9cb4bb76847}

#### `public `[`Rational`](#classRational)` `[`length`](#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de)`() const` {#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de}

sum of the elements of the duration list (including continuation)

#### `public void `[`add`](#group__output_1gaddb48455388f36f48ace0f0c0b250105)`(`[`Rational`](#classRational)`)` {#group__output_1gaddb48455388f36f48ace0f0c0b250105}

add the event at the end of the main list.

fail if event cannot be added (makes sum > 1). 

this list must not have have been summed with others.

#### `public void `[`addcont`](#group__output_1gab9d508060073c83c27e13f8f2472de38)`(`[`Rational`](#classRational)`)` {#group__output_1gab9d508060073c83c27e13f8f2472de38}

push a continuation value.

fail if cont cannot be added (makes sum > 1). 

this list must not have been summed with others.

#### `public `[`DurationList`](#classDurationList)` & `[`operator+=`](#group__output_1ga06ae4f865c1c27edd490f1631d76452a)`(const `[`DurationList`](#classDurationList)` & rhs)` {#group__output_1ga06ae4f865c1c27edd490f1631d76452a}

concatenation.

#### Parameters
* `rhs` duration list to concatenate, must not be empty, and must not be the summation of several duration lists.

#### `public void `[`normalize`](#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5)`()` {#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5}

divide by the number of lists summed.

#### `public  `[`~DurationTree`](#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6)`()` {#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6}

#### `public  `[`DurationTree`](#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8)`(const `[`DurationList`](#classDurationList)` & d)` {#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8}

#### `public `[`DurationTree`](#classDurationTree)` * `[`sub`](#group__output_1ga524c96edadc8725d997f81de3663ce4d)`(size_t,size_t)` {#group__output_1ga524c96edadc8725d997f81de3663ce4d}

#### `public  `[`Label`](#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00)`(int a)` {#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00}

#### `public size_t `[`arity`](#group__output_1ga189208973cef74bb65357535d43885ed)`() const` {#group__output_1ga189208973cef74bb65357535d43885ed}

#### `public static size_t `[`nbGraceNotes`](#group__output_1ga9c677c6efeee575a05c0a32511ad7cf1)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga9c677c6efeee575a05c0a32511ad7cf1}

#### `public static size_t `[`nbEvents`](#group__output_1ga58660df99e9a20f35ee0dab2901aa637)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga58660df99e9a20f35ee0dab2901aa637}

#### `public static bool `[`continuation`](#group__output_1ga56a227805fd6d43d1f2618e871a4108c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga56a227805fd6d43d1f2618e871a4108c}

#### `public static bool `[`abstract`](#group__output_1ga3724371343de270b6f488ca47d11b917)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga3724371343de270b6f488ca47d11b917}

#### `public static bool `[`abstract`](#group__output_1ga07b8cb2137bfde63b8f2686ed6f20db0)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` a,`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` n)` {#group__output_1ga07b8cb2137bfde63b8f2686ed6f20db0}

#### `public static bool `[`leqabstract`](#group__output_1ga686ea0e366bdefcf68714e411cad577f)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` a,`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` n)` {#group__output_1ga686ea0e366bdefcf68714e411cad577f}

#### `public  `[`InnerLabel`](#group__output_1ga7679a09f4cdd668f395a24deb498cdc2)`(unsigned int)` {#group__output_1ga7679a09f4cdd668f395a24deb498cdc2}

#### `public  `[`EventLabel`](#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9)`()` {#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9}

#### `public  `[`EventLabel`](#group__output_1gad5d7a4117cae3ac10b55ea051aa92848)`(unsigned int n)` {#group__output_1gad5d7a4117cae3ac10b55ea051aa92848}

#### `public size_t `[`nbGraceNotes`](#group__output_1gae8b849bfdbed392ff2171126354210a0)`() const` {#group__output_1gae8b849bfdbed392ff2171126354210a0}

#### `public void `[`addGraceNotes`](#group__output_1ga77779608bf4588f37330cecaf4cc2f1e)`(unsigned int)` {#group__output_1ga77779608bf4588f37330cecaf4cc2f1e}

#### `public void `[`pushEvent`](#group__output_1ga6a71e2488e33f2556ee9051d0bc88820)`(Event *)` {#group__output_1ga6a71e2488e33f2556ee9051d0bc88820}

#### `public string `[`lily`](#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259)`(int depth,bool tie) const` {#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259}

LilyPond format.

Lilypond output for RT [http://lilypond.org](http://lilypond.org).

#### `public string `[`lilydot`](#group__output_1ga93aca0f691a35a081d51eaad06e8ce50)`(int depth)` {#group__output_1ga93aca0f691a35a081d51eaad06e8ce50}

LilyPond format with dots.

#### `protected string `[`lilydot`](#group__output_1ga89f5bf140b902f886be124d620ac8474)`(int depth,bool tie,bool dot,bool ignore_first,bool ignore_second)` {#group__output_1ga89f5bf140b902f886be124d620ac8474}

LilyPond format with dots.

#### `public  `[`MEI`](#group__output_1ga67acb233e47d9942cb678fb24b67f799)`()` {#group__output_1ga67acb233e47d9942cb678fb24b67f799}

Main constructor

#### `public void `[`createFromScore`](#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` {#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5}

#### `public void `[`createScoreDef`](#group__output_1gaec3627352aed16ef31dfabe7d243c476)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` {#group__output_1gaec3627352aed16ef31dfabe7d243c476}

Create the score definition part

#### `public std::pair< string, int > `[`chooseClef`](#group__output_1ga707656b4b214953f8be23c95415a8ed5)`(std::pair< `[`Pitch](#classPitch), [Pitch`](#classPitch)` > range)` {#group__output_1ga707656b4b214953f8be23c95415a8ed5}

Choose a clef based on range

#### `public void `[`writeInFile`](#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da)`(const string fname)` {#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da}

Save in file

#### `public static Note * `[`makeNote`](#group__output_1ga6c05e4fec7d79e79d9022130e8fef2ad)`(const `[`ScoreModel::Note`](#classScoreModel_1_1Note)` * noteEvent)` {#group__output_1ga6c05e4fec7d79e79d9022130e8fef2ad}

#### `public static Tie * `[`makeTie`](#group__output_1gafa5b4ccd58b7537120b30437c8072852)`(const ScoreModel::Tie * tie)` {#group__output_1gafa5b4ccd58b7537120b30437c8072852}

#### `public static TupletSpan * `[`makeTupletSpan`](#group__output_1gabbdc2a86af7313ccc63b1b502d9b0aa5)`(const `[`ScoreModel::Tuplet`](#classScoreModel_1_1Tuplet)` * tuplet)` {#group__output_1gabbdc2a86af7313ccc63b1b502d9b0aa5}

#### `public  `[`~MEI`](#group__output_1ga1e4233e0a65d642f227dba08be1fe592)`()` {#group__output_1ga1e4233e0a65d642f227dba08be1fe592}

Destructor

#### `public  `[`OMRhythmTree`](#group__output_1gafa2112e5abf005b87ad68073ac92670f)`()` {#group__output_1gafa2112e5abf005b87ad68073ac92670f}

#### `public  `[`OMRhythmTree`](#group__output_1gac708fcabf8489ca08a9f7231eeb928d0)`(`[`Rational`](#classRational)` lab,bool tied)` {#group__output_1gac708fcabf8489ca08a9f7231eeb928d0}

#### `public  `[`OMRhythmTree`](#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3)`(const `[`RhythmTree`](#classRhythmTree)` *,`[`Rational`](#classRational)` dur)` {#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3}

#### `public  `[`~OMRhythmTree`](#group__output_1gaea89bed9d2782e13bf697069147331a4)`()` {#group__output_1gaea89bed9d2782e13bf697069147331a4}

#### `public size_t `[`size`](#group__output_1ga5877122dcb737ec9bdbe94241b867b4e)`() const` {#group__output_1ga5877122dcb737ec9bdbe94241b867b4e}

#### `public `[`OMRhythmTree`](#classOMRhythmTree)` * `[`child`](#group__output_1ga59d59642fc58d66772d51a075720a701)`(size_t) const` {#group__output_1ga59d59642fc58d66772d51a075720a701}

#### `public void `[`add`](#group__output_1ga6e273a3942470268fb775857d80bc2a8)`(`[`OMRhythmTree`](#classOMRhythmTree)` *)` {#group__output_1ga6e273a3942470268fb775857d80bc2a8}

#### `public string `[`to_string`](#group__output_1ga14633b5c977b30f4a28085c686c3c17f)`() const` {#group__output_1ga14633b5c977b30f4a28085c686c3c17f}

#### `public  `[`Onsets`](#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f}

the list of onsets defined by the given duration list (IOI's) the first onset is 0.

a continuation in duration list will be treated like other events

#### `public `[`DurationList`](#classDurationList)` `[`ioi`](#group__output_1gad3393b6422e8708954e27a52933620e1)`() const` {#group__output_1gad3393b6422e8708954e27a52933620e1}

the list of IOI associated to this list of onsets.

#### `public  `[`PointedRhythmTree`](#group__output_1gaf7f8a09842cce99950290469727cb4f2)`()` {#group__output_1gaf7f8a09842cce99950290469727cb4f2}

#### `public  `[`PointedRhythmTree`](#group__output_1ga00153f3142fe2d750b995d95435d852e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` {#group__output_1ga00153f3142fe2d750b995d95435d852e}

#### `public  `[`PointedRhythmTree`](#group__output_1gad86382b8bc2a62cc5d8848c516280c52)`(const `[`RhythmTree`](#classRhythmTree)` *,const `[`InputSegment`](#classInputSegment)` *,size_t i)` {#group__output_1gad86382b8bc2a62cc5d8848c516280c52}

#### `public  `[`~PointedRhythmTree`](#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28)`()` {#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28}

#### `public  `[`QDate`](#group__output_1gac553172d4c172c75bb78e9b246eaa0a1)`()` {#group__output_1gac553172d4c172c75bb78e9b246eaa0a1}

#### `public  `[`QDate`](#group__output_1ga1151b393ffd2c621914c8e0641fff3d3)`(size_t blocs,size_t rel)` {#group__output_1ga1151b393ffd2c621914c8e0641fff3d3}

#### `public  `[`QDate`](#group__output_1gab39d4fd438b410d8310f4bf43703904f)`(const `[`QDate`](#classQDate)` &)` {#group__output_1gab39d4fd438b410d8310f4bf43703904f}

#### `public virtual `[`QDate`](#classQDate)` & `[`operator=`](#group__output_1ga28238d09bb0f332bda66fafb92facb3b)`(const `[`QDate`](#classQDate)` &)` {#group__output_1ga28238d09bb0f332bda66fafb92facb3b}

#### `public virtual `[`QDate`](#classQDate)` * `[`clone`](#group__output_1ga59599012a00e9c2ae587144f47085130)`() const` {#group__output_1ga59599012a00e9c2ae587144f47085130}

#### `public `[`Rational`](#classRational)` `[`absolute`](#group__output_1ga07a4414576afc26204002ce92dcc7ce9)`(size_t res) const` {#group__output_1ga07a4414576afc26204002ce92dcc7ce9}

quantified date as rational value.

#### `public void `[`print`](#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36)`(std::ostream &) const` {#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36}

#### `public void `[`print`](#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1)`(std::ostream &,size_t) const` {#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1}

fractional print using resolution value.

#### `public  `[`Position`](#group__output_1ga369a577425f8ba02e8750d04b6a088db)`()` {#group__output_1ga369a577425f8ba02e8750d04b6a088db}

empty sequence = root position

#### `public  `[`Position`](#group__output_1ga63750e368482cc5ef45180d3672b1c55)`(const `[`Position`](#classPosition)` &)` {#group__output_1ga63750e368482cc5ef45180d3672b1c55}

#### `public bool `[`empty`](#group__output_1ga886868520756636e98110cdb06349326)`() const` {#group__output_1ga886868520756636e98110cdb06349326}

#### `public size_t `[`length`](#group__output_1ga009f3b456aa0995413db1b8c0bd6f374)`() const` {#group__output_1ga009f3b456aa0995413db1b8c0bd6f374}

#### `public void `[`operator+=`](#group__output_1gab6b7dd5c2869fb23755faee32f1e6731)`(size_t i)` {#group__output_1gab6b7dd5c2869fb23755faee32f1e6731}

concatenate given int to this position

#### Parameters
* `i` int must be positive

#### `protected void `[`print`](#group__output_1ga19d238e39cbe5a9f03929473bbd5b745)`(std::ostream & o) const` {#group__output_1ga19d238e39cbe5a9f03929473bbd5b745}

#### `public  `[`RhythmTree`](#group__output_1gac7614a6239a4917c771641dfdfd597ab)`()` {#group__output_1gac7614a6239a4917c771641dfdfd597ab}

empty inner tree (not terminal)

the child list must be completed with add

#### `public  `[`RhythmTree`](#group__output_1gac868521df843e116ef04bcfa52405d01)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` {#group__output_1gac868521df843e116ef04bcfa52405d01}

single leaf rhythm tree (terminal tree)

#### `public  `[`RhythmTree`](#group__output_1ga058c6d59881e1be259594165d19c8588)`(const string &)` {#group__output_1ga058c6d59881e1be259594165d19c8588}

extract RT from string description

#### `private void `[`read_tree`](#group__output_1ga70f6b23946fcfd1823b9fb3fde9506a3)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)` {#group__output_1ga70f6b23946fcfd1823b9fb3fde9506a3}

#### `private void `[`read_space`](#group__output_1gafd2cba61567f7096dc5050bca22cf4f1)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)` {#group__output_1gafd2cba61567f7096dc5050bca22cf4f1}

#### `private void `[`read_int`](#group__output_1ga1b87a8ab06f066092cf5d9dac5a5497c)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)` {#group__output_1ga1b87a8ab06f066092cf5d9dac5a5497c}

#### `private void `[`read_list`](#group__output_1gac45127942de2570f415b8e4dd0c5c20c)`(std::string::const_iterator & it,const std::string::const_iterator & beg,const std::string::const_iterator & end)` {#group__output_1gac45127942de2570f415b8e4dd0c5c20c}

#### `public  `[`~RhythmTree`](#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee)`()` {#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee}

#### `public bool `[`terminal`](#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd)`() const` {#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd}

single node tree

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350)`() const` {#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350}

label for terminal node

this tree must be terminal

#### `public bool `[`continuation`](#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0)`() const` {#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0}

label of terminal node is a continuation

this tree must be terminal

#### `public bool `[`single_event`](#group__output_1gabd793b78f71fb62edb13497e0a13f48c)`() const` {#group__output_1gabd793b78f71fb62edb13497e0a13f48c}

label of terminal node is a single event (1 note / rest, no grace note).

this tree must be terminal

#### `public size_t `[`nbgn`](#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7)`() const` {#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7}

number of grace notes in this terminal node.

this tree must be terminal

#### `public size_t `[`arity`](#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e)`() const` {#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e}

arity of root node (0 for terminal tree)

#### `public `[`RhythmTree`](#classRhythmTree)` * `[`child`](#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd)`(size_t i) const` {#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd}

return the ith child of this tree

this tree must be inner (not terminal)

#### `public void `[`add`](#group__output_1ga5749469b3ff6ec88fcab75961e7d278c)`(`[`RhythmTree`](#classRhythmTree)` *)` {#group__output_1ga5749469b3ff6ec88fcab75961e7d278c}

add a subtree.

this tree must not be terminal

#### `public bool `[`reducible`](#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9)`() const` {#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9}

this tree contains a subtree of the form.

```cpp
p(n, o,...,o) 
```
 or 
```cpp
p(o,...,o) 
```

#### `protected bool `[`tail_redex`](#group__output_1gaf723874e871dc01efb036ccbac07c32b)`() const` {#group__output_1gaf723874e871dc01efb036ccbac07c32b}

inner and the children list is of the form.

```cpp
(_, o,...,o) 
```

#### `protected bool `[`tail_reducible`](#group__output_1ga799761965ae00bb24e16ebb98f66995a)`() const` {#group__output_1ga799761965ae00bb24e16ebb98f66995a}

inner and one of the children 1..a is reducible.

#### `protected bool `[`tie`](#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47)`() const` {#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47}

return whether this tree is a continuation (a leaf).

#### `protected bool `[`tied`](#group__output_1gacd73e0032e3dd22320819c4cda3d60a4)`() const` {#group__output_1gacd73e0032e3dd22320819c4cda3d60a4}

return whether the leftmost innermost leaf is a tie (continuation).

#### `protected bool `[`binary`](#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72)`() const` {#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72}

return whether this tree is binary.

#### `protected bool `[`second_tied`](#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4)`() const` {#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4}

return whether this tree is binary and the second child is tied.

#### `protected bool `[`dot_after`](#group__output_1gac785e6d945ef6e0808132459669ab038)`() const` {#group__output_1gac785e6d945ef6e0808132459669ab038}

return whether this tree is binary and the left son is a dot (continuation after the dotted note).

#### `protected bool `[`dot_before`](#group__output_1ga2079bd534900d0b10e74682e404230b1)`() const` {#group__output_1ga2079bd534900d0b10e74682e404230b1}

return whether this tree is binary and the right son is a dot (continuation before the dotted note).

#### `public string `[`to_string`](#group__output_1gac6764688e24fe9b942464a9c2053ee92)`() const` {#group__output_1gac6764688e24fe9b942464a9c2053ee92}

#### `public static size_t `[`nbEvents`](#group__output_1ga2d7e95e5b2cc887aa9c4db52fab1b0d3)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga2d7e95e5b2cc887aa9c4db52fab1b0d3}

number of note + grace notes encoded in given leaf label

#### `public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#group__output_1ga3d92180f844d00eaf0bbd46e10f022e4)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga3d92180f844d00eaf0bbd46e10f022e4}

return the pre value of the given leaf label

#### `public static `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#group__output_1ga7c5289addb03e9bf54467e2d84c7ef79)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga7c5289addb03e9bf54467e2d84c7ef79}

return the post value of the given leaf label

#### `public static size_t `[`nbGraceNotes`](#group__output_1ga0f5679843d6bcd3e97ecd535c4d3c6f8)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1ga0f5679843d6bcd3e97ecd535c4d3c6f8}

return the number of grace node encoded in given leaf label

#### `public static bool `[`continuation`](#group__output_1gaaf4c88a23710366cbe35081a0967b536)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__output_1gaaf4c88a23710366cbe35081a0967b536}

the given leaf label is a continuation (no event, no grace note)

#### `public static `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`serialize`](#group__output_1ga69973921641222cb765112c70df25318)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,size_t nb)` {#group__output_1ga69973921641222cb765112c70df25318}

return the leaf label encoding the given

#### Parameters
* `pre` value in 0..MAX_GRACE 

* `post` value in 0..MAX_GRACE 

* `nb` number of events

#### `public  `[`ValueList`](#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185)`(`[`Rational`](#classRational)`)` {#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185}

#### `public  `[`ValueList`](#group__output_1gad518d3f6ddf7fb7b74275eef20205893)`(std::string)` {#group__output_1gad518d3f6ddf7fb7b74275eef20205893}

#### `public  `[`ValueList`](#group__output_1gaec135d71a5c51579bec52c805c0b3ded)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1gaec135d71a5c51579bec52c805c0b3ded}

#### `public  `[`ValueList`](#group__output_1gabd7a0aa8113f72c13205c0702eb269ff)`(const `[`ValueList`](#classValueList)` &)` {#group__output_1gabd7a0aa8113f72c13205c0702eb269ff}

#### `public `[`ValueList`](#classValueList)` & `[`operator=`](#group__output_1gab09ac2a5e83e806431634ddd87f596fc)`(const `[`ValueList`](#classValueList)` &)` {#group__output_1gab09ac2a5e83e806431634ddd87f596fc}

#### `public bool `[`empty`](#group__output_1ga7510db734db466464100413728db233c)`() const` {#group__output_1ga7510db734db466464100413728db233c}

#### `public bool `[`complete`](#group__output_1ga2ebf6a43ad145e4593cc961a4016f330)`() const` {#group__output_1ga2ebf6a43ad145e4593cc961a4016f330}

#### `public bool `[`single_continuation`](#group__output_1ga9d68ca01f81000f92f1c8911cbd414da)`() const` {#group__output_1ga9d68ca01f81000f92f1c8911cbd414da}

#### `public bool `[`event`](#group__output_1gaff6e5912f71832597303efe0093d5d00)`() const` {#group__output_1gaff6e5912f71832597303efe0093d5d00}

#### `public bool `[`single_event`](#group__output_1ga699183ea1d3babeb7c2c094e31e7070f)`() const` {#group__output_1ga699183ea1d3babeb7c2c094e31e7070f}

#### `public void `[`add`](#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0)`(`[`Rational`](#classRational)`)` {#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0}

#### `public void `[`addcont`](#group__output_1gaeb6d26ee1813f879c07148df644a5321)`(`[`Rational`](#classRational)`)` {#group__output_1gaeb6d26ee1813f879c07148df644a5321}

#### `public `[`Rational`](#classRational)` `[`front`](#group__output_1ga282fe7cbc28917f2b096d2183419a30c)`() const` {#group__output_1ga282fe7cbc28917f2b096d2183419a30c}

#### `public `[`Rational`](#classRational)` `[`pop`](#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed)`()` {#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed}

#### `public `[`Rational`](#classRational)` `[`popcont`](#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9)`()` {#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9}

#### `public void `[`popcont`](#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea)`(`[`Rational`](#classRational)`)` {#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea}

# namespace `std` {#namespacestd}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`std::hash< DurationList >`](api-output.md#structstd_1_1hash_3_01DurationList_01_4) | 
`struct `[`std::hash< ValueList >`](api-output.md#structstd_1_1hash_3_01ValueList_01_4) | 

# struct `std::hash< DurationList >` {#structstd_1_1hash_3_01DurationList_01_4}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline size_t `[`operator()`](#structstd_1_1hash_3_01DurationList_01_4_1a8f165a7fb48bda9ef5b8d03b08b9b4b3)`(const `[`DurationList`](#classDurationList)` & d) const` | 

## Members

#### `public inline size_t `[`operator()`](#structstd_1_1hash_3_01DurationList_01_4_1a8f165a7fb48bda9ef5b8d03b08b9b4b3)`(const `[`DurationList`](#classDurationList)` & d) const` {#structstd_1_1hash_3_01DurationList_01_4_1a8f165a7fb48bda9ef5b8d03b08b9b4b3}

# struct `std::hash< ValueList >` {#structstd_1_1hash_3_01ValueList_01_4}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline size_t `[`operator()`](#structstd_1_1hash_3_01ValueList_01_4_1ab9890ebe6ad98362e5f5b47587f30bd4)`(const `[`ValueList`](#classValueList)` & d) const` | 

## Members

#### `public inline size_t `[`operator()`](#structstd_1_1hash_3_01ValueList_01_4_1ab9890ebe6ad98362e5f5b47587f30bd4)`(const `[`ValueList`](#classValueList)` & d) const` {#structstd_1_1hash_3_01ValueList_01_4_1ab9890ebe6ad98362e5f5b47587f30bd4}

# class `DurationList` {#classDurationList}

list of rational durations to label nodes of [WTA](#classWTA) Runs for Kbest enum.

Duration is either positive (event w or wo continuations -ties) or null (grace note).

a duration list is made of 2 parts:

* _cont : initial duration (possibly null) tied to the previous duration list

* _main : main list of the other events (without ties) it is represented by _cont[_main]

to speed up processing, every [DurationList](#classDurationList) is associated a state value, wich is one of the following:

* 0: empty list initial 0[] _cont=0, _main empty empty list assigned to a run at creation before appending of children's run lists.

* 1: single continuation 1[] _cont=1, _main empty

* 2: only-gn 0[0..0] _cont=0, _main = [0,...,0]

* 3: single event 0[1] _cont=0, _main = [1]

* 4: event 0[0..01] _cont=0, _main = [0,...,0,1]

* 5: other incomplete

* 6: other complete

* 7: empty non initial empty but other (children's) list have been appened already

* 0, 2, 5 are incomplete (sum != _summed)

* 1, 3, 4, 6, 7 are complete

* 1, 3, 4 are unit: the duration list represents one event and some grace notes

in quantization the length of list for a run correspoding to a segment is equal to the length of the segment.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DurationList`](#group__output_1ga24f753a9aa9316fc7903e6f253b94944)`()` | empty duration list.
`public  `[`DurationList`](#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8)`(const `[`DurationList`](#classDurationList)` &)` | 
`public  `[`DurationList`](#group__output_1ga95ba6b1b14592003fdc97b69f982677c)`(const `[`DurationList`](#classDurationList)` & l,`[`Rational`](#classRational)` q)` | copy of duration list l where all elements are multiplied by given Ratio q.
`public  `[`DurationList`](#group__output_1gab678d41f41605596499c3f17a5f39120)`(std::string)` | read duration list from file.
`public inline  `[`~DurationList`](#classDurationList_1a79280887543a2f43a0dc51f780e3b41c)`()` | 
`public `[`DurationList`](#classDurationList)` & `[`operator=`](#group__output_1ga831728f737383383f8f74580161eb3fb)`(const `[`DurationList`](#classDurationList)` &)` | 
`public bool `[`empty`](#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a)`() const` | 
`public bool `[`unit`](#group__output_1ga130ef44efbc7af3c3c9a6efa23639378)`() const` | 
`public inline size_t `[`size`](#classDurationList_1ac3b9ad9eadfa60cf0c72d05afc399226)`() const` | 
`public inline `[`Rational`](#classRational)` `[`cont`](#classDurationList_1aa014f16c3c1300e781d6f3673b9b1152)`() const` | 
`public inline size_t `[`summed`](#classDurationList_1a61173a371c4d74d551f0915f132565c2)`() const` | for checking.
`public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`begin`](#classDurationList_1a7e2a43d04431026b96baf67ea0961df4)`() const` | 
`public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`end`](#classDurationList_1af72d4a22703809811bc5bc1ef9689220)`() const` | 
`public bool `[`complete`](#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54)`() const` | 
`public bool `[`single_continuation`](#group__output_1ga8b4434664a0dd2938fae9791fd34febd)`() const` | one (non null) continuation and no event in the main list.
`public bool `[`single_event`](#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471)`() const` | no continuation and only one event in the main list.
`public bool `[`event`](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)`() const` | no continuation and some grace notes (dur=0) + one event (dur>0) in the main list.
`public size_t `[`nbgn`](#group__output_1ga72427605bbceabff329459a610db1201)`() const` | number of grace note must be an [event()](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)
`public `[`Rational`](#classRational)` `[`length`](#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de)`() const` | sum of the elements of the duration list (including continuation)
`public void `[`add`](#group__output_1gaddb48455388f36f48ace0f0c0b250105)`(`[`Rational`](#classRational)`)` | add the event at the end of the main list.
`public void `[`addcont`](#group__output_1gab9d508060073c83c27e13f8f2472de38)`(`[`Rational`](#classRational)`)` | push a continuation value.
`public void `[`normalize`](#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5)`()` | divide by the number of lists summed.
`public `[`DurationList`](#classDurationList)` & `[`operator+=`](#group__output_1ga06ae4f865c1c27edd490f1631d76452a)`(const `[`DurationList`](#classDurationList)` & rhs)` | concatenation.

## Members

#### `public  `[`DurationList`](#group__output_1ga24f753a9aa9316fc7903e6f253b94944)`()` {#group__output_1ga24f753a9aa9316fc7903e6f253b94944}

empty duration list.

#### `public  `[`DurationList`](#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga3dffe3684ea0f218d03ddcfd7ee783f8}

#### `public  `[`DurationList`](#group__output_1ga95ba6b1b14592003fdc97b69f982677c)`(const `[`DurationList`](#classDurationList)` & l,`[`Rational`](#classRational)` q)` {#group__output_1ga95ba6b1b14592003fdc97b69f982677c}

copy of duration list l where all elements are multiplied by given Ratio q.

#### Parameters
* `l` suration list to copy and update 

* `q` given ratio for update

#### `public  `[`DurationList`](#group__output_1gab678d41f41605596499c3f17a5f39120)`(std::string)` {#group__output_1gab678d41f41605596499c3f17a5f39120}

read duration list from file.

one ratio per line if the first line is negative ratio, it is a continuation all other line must contain positive or null ratios. the file must not be empty.

TBR only for testing.

#### `public inline  `[`~DurationList`](#classDurationList_1a79280887543a2f43a0dc51f780e3b41c)`()` {#classDurationList_1a79280887543a2f43a0dc51f780e3b41c}

#### `public `[`DurationList`](#classDurationList)` & `[`operator=`](#group__output_1ga831728f737383383f8f74580161eb3fb)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga831728f737383383f8f74580161eb3fb}

#### `public bool `[`empty`](#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a)`() const` {#group__output_1ga293312eb9bbd4ac03d0add796c8eb12a}

#### `public bool `[`unit`](#group__output_1ga130ef44efbc7af3c3c9a6efa23639378)`() const` {#group__output_1ga130ef44efbc7af3c3c9a6efa23639378}

#### `public inline size_t `[`size`](#classDurationList_1ac3b9ad9eadfa60cf0c72d05afc399226)`() const` {#classDurationList_1ac3b9ad9eadfa60cf0c72d05afc399226}

#### `public inline `[`Rational`](#classRational)` `[`cont`](#classDurationList_1aa014f16c3c1300e781d6f3673b9b1152)`() const` {#classDurationList_1aa014f16c3c1300e781d6f3673b9b1152}

#### `public inline size_t `[`summed`](#classDurationList_1a61173a371c4d74d551f0915f132565c2)`() const` {#classDurationList_1a61173a371c4d74d551f0915f132565c2}

for checking.

#### `public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`begin`](#classDurationList_1a7e2a43d04431026b96baf67ea0961df4)`() const` {#classDurationList_1a7e2a43d04431026b96baf67ea0961df4}

#### `public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`end`](#classDurationList_1af72d4a22703809811bc5bc1ef9689220)`() const` {#classDurationList_1af72d4a22703809811bc5bc1ef9689220}

#### `public bool `[`complete`](#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54)`() const` {#group__output_1ga7fa2c8c9f2e3954592e4f0e264560e54}

#### `public bool `[`single_continuation`](#group__output_1ga8b4434664a0dd2938fae9791fd34febd)`() const` {#group__output_1ga8b4434664a0dd2938fae9791fd34febd}

one (non null) continuation and no event in the main list.

#### `public bool `[`single_event`](#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471)`() const` {#group__output_1gabdd5f118e0ea1566362a9eaed2ce0471}

no continuation and only one event in the main list.

#### `public bool `[`event`](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)`() const` {#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc}

no continuation and some grace notes (dur=0) + one event (dur>0) in the main list.

#### `public size_t `[`nbgn`](#group__output_1ga72427605bbceabff329459a610db1201)`() const` {#group__output_1ga72427605bbceabff329459a610db1201}

number of grace note must be an [event()](#group__output_1gadd91aa5ec57a51c6253ea872eadb28dc)

#### `public `[`Rational`](#classRational)` `[`length`](#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de)`() const` {#group__output_1ga540cf8decb4f62a80e871ab1e6dd31de}

sum of the elements of the duration list (including continuation)

#### `public void `[`add`](#group__output_1gaddb48455388f36f48ace0f0c0b250105)`(`[`Rational`](#classRational)`)` {#group__output_1gaddb48455388f36f48ace0f0c0b250105}

add the event at the end of the main list.

fail if event cannot be added (makes sum > 1). 

this list must not have have been summed with others.

#### `public void `[`addcont`](#group__output_1gab9d508060073c83c27e13f8f2472de38)`(`[`Rational`](#classRational)`)` {#group__output_1gab9d508060073c83c27e13f8f2472de38}

push a continuation value.

fail if cont cannot be added (makes sum > 1). 

this list must not have been summed with others.

#### `public void `[`normalize`](#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5)`()` {#group__output_1ga20a55c27bcb4ec4f639d4f7f79153be5}

divide by the number of lists summed.

#### `public `[`DurationList`](#classDurationList)` & `[`operator+=`](#group__output_1ga06ae4f865c1c27edd490f1631d76452a)`(const `[`DurationList`](#classDurationList)` & rhs)` {#group__output_1ga06ae4f865c1c27edd490f1631d76452a}

concatenation.

#### Parameters
* `rhs` duration list to concatenate, must not be empty, and must not be the summation of several duration lists.

# class `DurationTree` {#classDurationTree}

a tree container for duration lists. to avoid recomputation of division of duration lists.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`ValueList`](#classValueList)` `[`top`](#classDurationTree_1a5bc3a3111a608d2992accf0b6d98da40) | 
`public inline  `[`DurationTree`](#classDurationTree_1a0bfd7d1de526da6f0e7f8bdbd0c63416)`(`[`Rational`](#classRational)` len)` | 
`public  `[`DurationTree`](#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8)`(const `[`DurationList`](#classDurationList)` & d)` | 
`public  `[`~DurationTree`](#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6)`()` | 
`public `[`DurationTree`](#classDurationTree)` * `[`sub`](#group__output_1ga524c96edadc8725d997f81de3663ce4d)`(size_t,size_t)` | 

## Members

#### `public `[`ValueList`](#classValueList)` `[`top`](#classDurationTree_1a5bc3a3111a608d2992accf0b6d98da40) {#classDurationTree_1a5bc3a3111a608d2992accf0b6d98da40}

#### `public inline  `[`DurationTree`](#classDurationTree_1a0bfd7d1de526da6f0e7f8bdbd0c63416)`(`[`Rational`](#classRational)` len)` {#classDurationTree_1a0bfd7d1de526da6f0e7f8bdbd0c63416}

#### `public  `[`DurationTree`](#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8)`(const `[`DurationList`](#classDurationList)` & d)` {#group__output_1ga2c12fa35cd11a35a98e4680975e3f8b8}

#### `public  `[`~DurationTree`](#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6)`()` {#group__output_1gac65ba3ab5f97b37e8f5a1ce6358422f6}

#### `public `[`DurationTree`](#classDurationTree)` * `[`sub`](#group__output_1ga524c96edadc8725d997f81de3663ce4d)`(size_t,size_t)` {#group__output_1ga524c96edadc8725d997f81de3663ce4d}

# class `Label` {#classLabel}

labels for nodes of output Rhythm Trees.

Inner nodes are simply labeled by arity.

Leaves are labeled by info on:

* input (segment of unquantized points) and

* output (quantized points).

More precisely,

* the input info is about the alignement of unquantized input points on the bounds of the interval associated to the node. These are the pre and post values.

* the output info is about the number of quantized input points in this interval.

* number 0 corresponds to a tie,

* number 1 corresponds to a single event,

* bigger numbers correspond to a event + grace notes.

we consider the abstract domain [0,...,MAX_GRACE] for the values of:

* i) the pre and post, and

* ii) the number of g.n. + note

for i) the meaning is

* 0: 0

* 1: 1

* ...

* MAX_GRACE: ≥ MAX_GRACE

for ii) the meaning is

* 0: tie (no event)

* 1: 1 note

* 2: 1 gn + 1 note

* ...

* MAX_GRACE: ≥ MAX_GRACE-1 gn + 1 note (appogiature) = all other cases

an abstract label is a label in abstract domain.

a concrete label is a positive integer.

an abstract label a is an abstraction of a concrete label b if

* either b <= MAX_GRACE and a = b

* or b > MAX_GRACE and a = MAX_GRACE.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Label`](#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00)`(int a)` | 
`public size_t `[`arity`](#group__output_1ga189208973cef74bb65357535d43885ed)`() const` | 
`public inline bool `[`isLeaf`](#classLabel_1aece2f72aeab3b5e59371d270acd66ef7)`() const` | 
`public inline bool `[`isInner`](#classLabel_1ae6629ed1895cbb2a95cdf284cbd18cdd)`() const` | 
`public inline LabelKind `[`kind`](#classLabel_1a46339b9942fe44345634652e245807b0)`() const` | 
`protected LabelKind `[`_type`](api-output.md#classLabel_1a6a1180995fe66be113d8433f40251715) | 
`protected size_t `[`_ar`](api-output.md#classLabel_1a072ec434ffc5fbe8bc4f8618e559dda6) | 

## Members

#### `public  `[`Label`](#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00)`(int a)` {#group__output_1gaa2d2c8bb6a5bd48679122a220a9d8d00}

#### `public size_t `[`arity`](#group__output_1ga189208973cef74bb65357535d43885ed)`() const` {#group__output_1ga189208973cef74bb65357535d43885ed}

#### `public inline bool `[`isLeaf`](#classLabel_1aece2f72aeab3b5e59371d270acd66ef7)`() const` {#classLabel_1aece2f72aeab3b5e59371d270acd66ef7}

#### `public inline bool `[`isInner`](#classLabel_1ae6629ed1895cbb2a95cdf284cbd18cdd)`() const` {#classLabel_1ae6629ed1895cbb2a95cdf284cbd18cdd}

#### `public inline LabelKind `[`kind`](#classLabel_1a46339b9942fe44345634652e245807b0)`() const` {#classLabel_1a46339b9942fe44345634652e245807b0}

#### `protected LabelKind `[`_type`](api-output.md#classLabel_1a6a1180995fe66be113d8433f40251715) {#classLabel_1a6a1180995fe66be113d8433f40251715}

#### `protected size_t `[`_ar`](api-output.md#classLabel_1a072ec434ffc5fbe8bc4f8618e559dda6) {#classLabel_1a072ec434ffc5fbe8bc4f8618e559dda6}

# class `InnerLabel` {#classInnerLabel}

```
class InnerLabel
  : private Label
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InnerLabel`](#group__output_1ga7679a09f4cdd668f395a24deb498cdc2)`(unsigned int)` | 

## Members

#### `public  `[`InnerLabel`](#group__output_1ga7679a09f4cdd668f395a24deb498cdc2)`(unsigned int)` {#group__output_1ga7679a09f4cdd668f395a24deb498cdc2}

# class `EventLabel` {#classEventLabel}

```
class EventLabel
  : private Label
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`EventLabel`](#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9)`()` | 
`public  `[`EventLabel`](#group__output_1gad5d7a4117cae3ac10b55ea051aa92848)`(unsigned int n)` | 
`public size_t `[`nbGraceNotes`](#group__output_1gae8b849bfdbed392ff2171126354210a0)`() const` | 
`public void `[`addGraceNotes`](#group__output_1ga77779608bf4588f37330cecaf4cc2f1e)`(unsigned int)` | 
`public void `[`pushEvent`](#group__output_1ga6a71e2488e33f2556ee9051d0bc88820)`(Event *)` | 

## Members

#### `public  `[`EventLabel`](#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9)`()` {#group__output_1ga4da9c2ee628ede0e5d20e9f0155884e9}

#### `public  `[`EventLabel`](#group__output_1gad5d7a4117cae3ac10b55ea051aa92848)`(unsigned int n)` {#group__output_1gad5d7a4117cae3ac10b55ea051aa92848}

#### `public size_t `[`nbGraceNotes`](#group__output_1gae8b849bfdbed392ff2171126354210a0)`() const` {#group__output_1gae8b849bfdbed392ff2171126354210a0}

#### `public void `[`addGraceNotes`](#group__output_1ga77779608bf4588f37330cecaf4cc2f1e)`(unsigned int)` {#group__output_1ga77779608bf4588f37330cecaf4cc2f1e}

#### `public void `[`pushEvent`](#group__output_1ga6a71e2488e33f2556ee9051d0bc88820)`(Event *)` {#group__output_1ga6a71e2488e33f2556ee9051d0bc88820}

# class `MEI` {#classMEI}

The main [MEI](#classMEI) class.

Takes a Rhythm tree as input, and creates a [MEI](#classMEI) score

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`MEI`](#group__output_1ga67acb233e47d9942cb678fb24b67f799)`()` | Main constructor
`public void `[`createFromScore`](#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` | 
`public void `[`createScoreDef`](#group__output_1gaec3627352aed16ef31dfabe7d243c476)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` | Create the score definition part
`public void `[`findStartingBeam`](#classMEI_1a5211ad9f61cfb653788c2c72df6e644c)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` | Find whether a beam start on an event
`public void `[`writeInFile`](#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da)`(const string fname)` | Save in file
`public std::pair< string, int > `[`chooseClef`](#group__output_1ga707656b4b214953f8be23c95415a8ed5)`(std::pair< `[`Pitch](#classPitch), [Pitch`](#classPitch)` > range)` | Choose a clef based on range
`public  `[`~MEI`](#group__output_1ga1e4233e0a65d642f227dba08be1fe592)`()` | Destructor

## Members

#### `public  `[`MEI`](#group__output_1ga67acb233e47d9942cb678fb24b67f799)`()` {#group__output_1ga67acb233e47d9942cb678fb24b67f799}

Main constructor

#### `public void `[`createFromScore`](#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` {#group__output_1ga28b9390a3699a9ae7abdba51cb3cb7d5}

#### `public void `[`createScoreDef`](#group__output_1gaec3627352aed16ef31dfabe7d243c476)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` {#group__output_1gaec3627352aed16ef31dfabe7d243c476}

Create the score definition part

#### `public void `[`findStartingBeam`](#classMEI_1a5211ad9f61cfb653788c2c72df6e644c)`(const `[`ScoreModel::Score`](#classScoreModel_1_1Score)` & s)` {#classMEI_1a5211ad9f61cfb653788c2c72df6e644c}

Find whether a beam start on an event

#### `public void `[`writeInFile`](#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da)`(const string fname)` {#group__output_1ga7f0c47ab091313feb0a7fba4d23e09da}

Save in file

#### `public std::pair< string, int > `[`chooseClef`](#group__output_1ga707656b4b214953f8be23c95415a8ed5)`(std::pair< `[`Pitch](#classPitch), [Pitch`](#classPitch)` > range)` {#group__output_1ga707656b4b214953f8be23c95415a8ed5}

Choose a clef based on range

#### `public  `[`~MEI`](#group__output_1ga1e4233e0a65d642f227dba08be1fe592)`()` {#group__output_1ga1e4233e0a65d642f227dba08be1fe592}

Destructor

# class `OMRhythmTree` {#classOMRhythmTree}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`OMRhythmTree`](#group__output_1gafa2112e5abf005b87ad68073ac92670f)`()` | 
`public  `[`OMRhythmTree`](#group__output_1gac708fcabf8489ca08a9f7231eeb928d0)`(`[`Rational`](#classRational)` lab,bool tied)` | 
`public  `[`OMRhythmTree`](#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3)`(const `[`RhythmTree`](#classRhythmTree)` *,`[`Rational`](#classRational)` dur)` | 
`public  `[`~OMRhythmTree`](#group__output_1gaea89bed9d2782e13bf697069147331a4)`()` | 
`public inline bool `[`leaf`](#classOMRhythmTree_1a04e14eae7285e3f9473823354599ab84)`() const` | 
`public inline bool `[`inner`](#classOMRhythmTree_1af820acb008741753d15dbae463a511c5)`() const` | 
`public inline `[`Rational`](#classRational)` `[`label`](#classOMRhythmTree_1afdd5d2e8c598012d228d484fef59ea54)`()` | 
`public inline bool `[`tie`](#classOMRhythmTree_1a3af64526e62a8148b5966dc43f7e9f74)`()` | 
`public size_t `[`size`](#group__output_1ga5877122dcb737ec9bdbe94241b867b4e)`() const` | 
`public `[`OMRhythmTree`](#classOMRhythmTree)` * `[`child`](#group__output_1ga59d59642fc58d66772d51a075720a701)`(size_t) const` | 
`public void `[`add`](#group__output_1ga6e273a3942470268fb775857d80bc2a8)`(`[`OMRhythmTree`](#classOMRhythmTree)` *)` | 
`public string `[`to_string`](#group__output_1ga14633b5c977b30f4a28085c686c3c17f)`() const` | 

## Members

#### `public  `[`OMRhythmTree`](#group__output_1gafa2112e5abf005b87ad68073ac92670f)`()` {#group__output_1gafa2112e5abf005b87ad68073ac92670f}

#### `public  `[`OMRhythmTree`](#group__output_1gac708fcabf8489ca08a9f7231eeb928d0)`(`[`Rational`](#classRational)` lab,bool tied)` {#group__output_1gac708fcabf8489ca08a9f7231eeb928d0}

#### `public  `[`OMRhythmTree`](#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3)`(const `[`RhythmTree`](#classRhythmTree)` *,`[`Rational`](#classRational)` dur)` {#group__output_1ga1dae8e3f43573cc3aac4859b5b618ef3}

#### `public  `[`~OMRhythmTree`](#group__output_1gaea89bed9d2782e13bf697069147331a4)`()` {#group__output_1gaea89bed9d2782e13bf697069147331a4}

#### `public inline bool `[`leaf`](#classOMRhythmTree_1a04e14eae7285e3f9473823354599ab84)`() const` {#classOMRhythmTree_1a04e14eae7285e3f9473823354599ab84}

#### `public inline bool `[`inner`](#classOMRhythmTree_1af820acb008741753d15dbae463a511c5)`() const` {#classOMRhythmTree_1af820acb008741753d15dbae463a511c5}

#### `public inline `[`Rational`](#classRational)` `[`label`](#classOMRhythmTree_1afdd5d2e8c598012d228d484fef59ea54)`()` {#classOMRhythmTree_1afdd5d2e8c598012d228d484fef59ea54}

#### `public inline bool `[`tie`](#classOMRhythmTree_1a3af64526e62a8148b5966dc43f7e9f74)`()` {#classOMRhythmTree_1a3af64526e62a8148b5966dc43f7e9f74}

#### `public size_t `[`size`](#group__output_1ga5877122dcb737ec9bdbe94241b867b4e)`() const` {#group__output_1ga5877122dcb737ec9bdbe94241b867b4e}

#### `public `[`OMRhythmTree`](#classOMRhythmTree)` * `[`child`](#group__output_1ga59d59642fc58d66772d51a075720a701)`(size_t) const` {#group__output_1ga59d59642fc58d66772d51a075720a701}

#### `public void `[`add`](#group__output_1ga6e273a3942470268fb775857d80bc2a8)`(`[`OMRhythmTree`](#classOMRhythmTree)` *)` {#group__output_1ga6e273a3942470268fb775857d80bc2a8}

#### `public string `[`to_string`](#group__output_1ga14633b5c977b30f4a28085c686c3c17f)`() const` {#group__output_1ga14633b5c977b30f4a28085c686c3c17f}

# class `Onsets` {#classOnsets}

sequence of onsets used for merge of duration lists.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Onsets`](#classOnsets_1a4d14411a65fa38670ae35f691bb74acd)`()` | 
`public  `[`Onsets`](#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f)`(const `[`DurationList`](#classDurationList)` &)` | the list of onsets defined by the given duration list (IOI's) the first onset is 0.
`public inline void `[`add`](#classOnsets_1a7cabc75f68a8d2e74d7356433a4964e5)`(`[`Rational`](#classRational)` r)` | 
`public `[`DurationList`](#classDurationList)` `[`ioi`](#group__output_1gad3393b6422e8708954e27a52933620e1)`() const` | the list of IOI associated to this list of onsets.

## Members

#### `public inline  `[`Onsets`](#classOnsets_1a4d14411a65fa38670ae35f691bb74acd)`()` {#classOnsets_1a4d14411a65fa38670ae35f691bb74acd}

#### `public  `[`Onsets`](#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1ga6a3bc246737b5cc48df0e07b36e9935f}

the list of onsets defined by the given duration list (IOI's) the first onset is 0.

a continuation in duration list will be treated like other events

#### `public inline void `[`add`](#classOnsets_1a7cabc75f68a8d2e74d7356433a4964e5)`(`[`Rational`](#classRational)` r)` {#classOnsets_1a7cabc75f68a8d2e74d7356433a4964e5}

#### `public `[`DurationList`](#classDurationList)` `[`ioi`](#group__output_1gad3393b6422e8708954e27a52933620e1)`() const` {#group__output_1gad3393b6422e8708954e27a52933620e1}

the list of IOI associated to this list of onsets.

# class `PointedRhythmTree` {#classPointedRhythmTree}

```
class PointedRhythmTree
  : public RhythmTree
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public std::vector< const `[`MusEvent`](#classMusEvent)` * > `[`events`](#classPointedRhythmTree_1a404071b821179c511a3f9b1e0d6e9ad8) | 
`public  `[`PointedRhythmTree`](#group__output_1gaf7f8a09842cce99950290469727cb4f2)`()` | 
`public  `[`PointedRhythmTree`](#group__output_1ga00153f3142fe2d750b995d95435d852e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` | 
`public  `[`PointedRhythmTree`](#group__output_1gad86382b8bc2a62cc5d8848c516280c52)`(const `[`RhythmTree`](#classRhythmTree)` *,const `[`InputSegment`](#classInputSegment)` *,size_t i)` | 
`public  `[`~PointedRhythmTree`](#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28)`()` | 
`public inline size_t `[`next`](#classPointedRhythmTree_1a8faa96c4256d16d554985195c0487c0b)`()` | 
`protected size_t `[`_next`](api-output.md#classPointedRhythmTree_1a8bbbb0e996dbe12dbc41eeede70f0527) | 

## Members

#### `public std::vector< const `[`MusEvent`](#classMusEvent)` * > `[`events`](#classPointedRhythmTree_1a404071b821179c511a3f9b1e0d6e9ad8) {#classPointedRhythmTree_1a404071b821179c511a3f9b1e0d6e9ad8}

#### `public  `[`PointedRhythmTree`](#group__output_1gaf7f8a09842cce99950290469727cb4f2)`()` {#group__output_1gaf7f8a09842cce99950290469727cb4f2}

#### `public  `[`PointedRhythmTree`](#group__output_1ga00153f3142fe2d750b995d95435d852e)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` {#group__output_1ga00153f3142fe2d750b995d95435d852e}

#### `public  `[`PointedRhythmTree`](#group__output_1gad86382b8bc2a62cc5d8848c516280c52)`(const `[`RhythmTree`](#classRhythmTree)` *,const `[`InputSegment`](#classInputSegment)` *,size_t i)` {#group__output_1gad86382b8bc2a62cc5d8848c516280c52}

#### `public  `[`~PointedRhythmTree`](#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28)`()` {#group__output_1gaff594d1f9db1bc40c552aeaa7cb9fc28}

#### `public inline size_t `[`next`](#classPointedRhythmTree_1a8faa96c4256d16d554985195c0487c0b)`()` {#classPointedRhythmTree_1a8faa96c4256d16d554985195c0487c0b}

#### `protected size_t `[`_next`](api-output.md#classPointedRhythmTree_1a8bbbb0e996dbe12dbc41eeede70f0527) {#classPointedRhythmTree_1a8bbbb0e996dbe12dbc41eeede70f0527}

# class `QDate` {#classQDate}

quantified onset values expressed in number of samples.

the value of RESOLUTION (total number of samples) is not stored in objects of this class. it should be the same for each date created.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`QDate`](#group__output_1gac553172d4c172c75bb78e9b246eaa0a1)`()` | 
`public  `[`QDate`](#group__output_1ga1151b393ffd2c621914c8e0641fff3d3)`(size_t blocs,size_t rel)` | 
`public  `[`QDate`](#group__output_1gab39d4fd438b410d8310f4bf43703904f)`(const `[`QDate`](#classQDate)` &)` | 
`public inline  `[`~QDate`](#classQDate_1ae4f8a0d5f827801fbe0aaae1dc9cf02d)`()` | 
`public virtual `[`QDate`](#classQDate)` & `[`operator=`](#group__output_1ga28238d09bb0f332bda66fafb92facb3b)`(const `[`QDate`](#classQDate)` &)` | 
`public virtual `[`QDate`](#classQDate)` * `[`clone`](#group__output_1ga59599012a00e9c2ae587144f47085130)`() const` | 
`public inline size_t `[`bloc`](#classQDate_1a5583b42d333739ef0432446d73400320)`() const` | number of bloc of length RES.
`public inline size_t `[`relative`](#classQDate_1ad531ed61e0c9a207a1016af4b0245d46)`() const` | quantified date (samples) modulo RES (date in last bloc).
`public `[`Rational`](#classRational)` `[`absolute`](#group__output_1ga07a4414576afc26204002ce92dcc7ce9)`(size_t res) const` | quantified date as rational value.
`public void `[`print`](#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36)`(std::ostream &) const` | 
`public void `[`print`](#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1)`(std::ostream &,size_t) const` | fractional print using resolution value.
`protected size_t `[`_quotient`](api-output.md#classQDate_1ae3c7801be338e952050f037c7cc4c799) | date in samples / RESOLUTION = bloc number
`protected size_t `[`_modulo`](api-output.md#classQDate_1ad14e1214b142bb77fa92e7f2b80f927c) | date in samples modulo RESOLUTION

## Members

#### `public  `[`QDate`](#group__output_1gac553172d4c172c75bb78e9b246eaa0a1)`()` {#group__output_1gac553172d4c172c75bb78e9b246eaa0a1}

#### `public  `[`QDate`](#group__output_1ga1151b393ffd2c621914c8e0641fff3d3)`(size_t blocs,size_t rel)` {#group__output_1ga1151b393ffd2c621914c8e0641fff3d3}

#### `public  `[`QDate`](#group__output_1gab39d4fd438b410d8310f4bf43703904f)`(const `[`QDate`](#classQDate)` &)` {#group__output_1gab39d4fd438b410d8310f4bf43703904f}

#### `public inline  `[`~QDate`](#classQDate_1ae4f8a0d5f827801fbe0aaae1dc9cf02d)`()` {#classQDate_1ae4f8a0d5f827801fbe0aaae1dc9cf02d}

#### `public virtual `[`QDate`](#classQDate)` & `[`operator=`](#group__output_1ga28238d09bb0f332bda66fafb92facb3b)`(const `[`QDate`](#classQDate)` &)` {#group__output_1ga28238d09bb0f332bda66fafb92facb3b}

#### `public virtual `[`QDate`](#classQDate)` * `[`clone`](#group__output_1ga59599012a00e9c2ae587144f47085130)`() const` {#group__output_1ga59599012a00e9c2ae587144f47085130}

#### `public inline size_t `[`bloc`](#classQDate_1a5583b42d333739ef0432446d73400320)`() const` {#classQDate_1a5583b42d333739ef0432446d73400320}

number of bloc of length RES.

#### `public inline size_t `[`relative`](#classQDate_1ad531ed61e0c9a207a1016af4b0245d46)`() const` {#classQDate_1ad531ed61e0c9a207a1016af4b0245d46}

quantified date (samples) modulo RES (date in last bloc).

#### `public `[`Rational`](#classRational)` `[`absolute`](#group__output_1ga07a4414576afc26204002ce92dcc7ce9)`(size_t res) const` {#group__output_1ga07a4414576afc26204002ce92dcc7ce9}

quantified date as rational value.

#### `public void `[`print`](#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36)`(std::ostream &) const` {#group__output_1gac8e931429f0f79f9e9f5754d3b98fe36}

#### `public void `[`print`](#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1)`(std::ostream &,size_t) const` {#group__output_1gaf69eee7904ee41d76e3a1a61ab92cfd1}

fractional print using resolution value.

#### `protected size_t `[`_quotient`](api-output.md#classQDate_1ae3c7801be338e952050f037c7cc4c799) {#classQDate_1ae3c7801be338e952050f037c7cc4c799}

date in samples / RESOLUTION = bloc number

#### `protected size_t `[`_modulo`](api-output.md#classQDate_1ad14e1214b142bb77fa92e7f2b80f927c) {#classQDate_1ad14e1214b142bb77fa92e7f2b80f927c}

date in samples modulo RESOLUTION

# class `Position` {#classPosition}

position in a RT.

= sequence of integers to reach position from root.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Position`](#group__output_1ga369a577425f8ba02e8750d04b6a088db)`()` | empty sequence = root position
`public  `[`Position`](#group__output_1ga63750e368482cc5ef45180d3672b1c55)`(const `[`Position`](#classPosition)` &)` | 
`public bool `[`empty`](#group__output_1ga886868520756636e98110cdb06349326)`() const` | 
`public size_t `[`length`](#group__output_1ga009f3b456aa0995413db1b8c0bd6f374)`() const` | 
`public void `[`operator+=`](#group__output_1gab6b7dd5c2869fb23755faee32f1e6731)`(size_t i)` | concatenate given int to this position
`protected std::vector< size_t > `[`_content`](api-output.md#classPosition_1afccdc3a3b6183af2b150c4672ccf4b2f) | 
`protected void `[`print`](#group__output_1ga19d238e39cbe5a9f03929473bbd5b745)`(std::ostream & o) const` | 

## Members

#### `public  `[`Position`](#group__output_1ga369a577425f8ba02e8750d04b6a088db)`()` {#group__output_1ga369a577425f8ba02e8750d04b6a088db}

empty sequence = root position

#### `public  `[`Position`](#group__output_1ga63750e368482cc5ef45180d3672b1c55)`(const `[`Position`](#classPosition)` &)` {#group__output_1ga63750e368482cc5ef45180d3672b1c55}

#### `public bool `[`empty`](#group__output_1ga886868520756636e98110cdb06349326)`() const` {#group__output_1ga886868520756636e98110cdb06349326}

#### `public size_t `[`length`](#group__output_1ga009f3b456aa0995413db1b8c0bd6f374)`() const` {#group__output_1ga009f3b456aa0995413db1b8c0bd6f374}

#### `public void `[`operator+=`](#group__output_1gab6b7dd5c2869fb23755faee32f1e6731)`(size_t i)` {#group__output_1gab6b7dd5c2869fb23755faee32f1e6731}

concatenate given int to this position

#### Parameters
* `i` int must be positive

#### `protected std::vector< size_t > `[`_content`](api-output.md#classPosition_1afccdc3a3b6183af2b150c4672ccf4b2f) {#classPosition_1afccdc3a3b6183af2b150c4672ccf4b2f}

#### `protected void `[`print`](#group__output_1ga19d238e39cbe5a9f03929473bbd5b745)`(std::ostream & o) const` {#group__output_1ga19d238e39cbe5a9f03929473bbd5b745}

# class `RhythmTree` {#classRhythmTree}

Rhythm Trees.

for the value of leaf labels 
**See also**: [WTA.hpp](#WTA_8hpp_source)

**See also**: [Label.hpp](#Label_8hpp_source)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`RhythmTree`](#group__output_1gac7614a6239a4917c771641dfdfd597ab)`()` | empty inner tree (not terminal)
`public  `[`RhythmTree`](#group__output_1gac868521df843e116ef04bcfa52405d01)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` | single leaf rhythm tree (terminal tree)
`public  `[`RhythmTree`](#group__output_1ga058c6d59881e1be259594165d19c8588)`(const string &)` | extract RT from string description
`public  `[`~RhythmTree`](#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee)`()` | 
`public bool `[`terminal`](#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd)`() const` | single node tree
`public inline bool `[`inner`](#classRhythmTree_1a67a3180bb74745a6e81f88835a74f740)`() const` | 
`public size_t `[`arity`](#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e)`() const` | arity of root node (0 for terminal tree)
`public `[`RhythmTree`](#classRhythmTree)` * `[`child`](#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd)`(size_t i) const` | return the ith child of this tree
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350)`() const` | label for terminal node
`public bool `[`continuation`](#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0)`() const` | label of terminal node is a continuation
`public bool `[`single_event`](#group__output_1gabd793b78f71fb62edb13497e0a13f48c)`() const` | label of terminal node is a single event (1 note / rest, no grace note).
`public size_t `[`nbgn`](#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7)`() const` | number of grace notes in this terminal node.
`public bool `[`reducible`](#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9)`() const` | this tree contains a subtree of the form.
`public void `[`add`](#group__output_1ga5749469b3ff6ec88fcab75961e7d278c)`(`[`RhythmTree`](#classRhythmTree)` *)` | add a subtree.
`public string `[`lily`](#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259)`(int depth,bool tie) const` | LilyPond format.
`public string `[`lilydot`](#group__output_1ga93aca0f691a35a081d51eaad06e8ce50)`(int depth)` | LilyPond format with dots.
`public string `[`APTED`](#group__output_1ga2c194b384127267b8cfed2c41e70d338)`() const` | format for Tree Edit [Distance](api-weight.md#classDistance) Salzburg library.
`public string `[`to_string`](#group__output_1gac6764688e24fe9b942464a9c2053ee92)`() const` | 
`protected long `[`_label`](api-output.md#classRhythmTree_1a172a0c68e4b6adace9c025c9159040e2) | for leaves, it is the positive integer stored in the leaf; for inner tree, it is a negative integer.
`protected std::vector< `[`RhythmTree`](#classRhythmTree)` * > `[`_children`](#classRhythmTree_1ac11078e58a8ca630953768bc6dc4d74e) | 
`protected bool `[`tail_redex`](#group__output_1gaf723874e871dc01efb036ccbac07c32b)`() const` | inner and the children list is of the form.
`protected bool `[`tail_reducible`](#group__output_1ga799761965ae00bb24e16ebb98f66995a)`() const` | inner and one of the children 1..a is reducible.
`protected bool `[`tie`](#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47)`() const` | return whether this tree is a continuation (a leaf).
`protected bool `[`binary`](#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72)`() const` | return whether this tree is binary.
`protected bool `[`tied`](#group__output_1gacd73e0032e3dd22320819c4cda3d60a4)`() const` | return whether the leftmost innermost leaf is a tie (continuation).
`protected bool `[`second_tied`](#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4)`() const` | return whether this tree is binary and the second child is tied.
`protected bool `[`dot_after`](#group__output_1gac785e6d945ef6e0808132459669ab038)`() const` | return whether this tree is binary and the left son is a dot (continuation after the dotted note).
`protected bool `[`dot_before`](#group__output_1ga2079bd534900d0b10e74682e404230b1)`() const` | return whether this tree is binary and the right son is a dot (continuation before the dotted note).
`protected string `[`lilydot`](#group__output_1ga89f5bf140b902f886be124d620ac8474)`(int depth,bool tie,bool dot,bool ignore_first,bool ignore_second)` | LilyPond format with dots.

## Members

#### `public  `[`RhythmTree`](#group__output_1gac7614a6239a4917c771641dfdfd597ab)`()` {#group__output_1gac7614a6239a4917c771641dfdfd597ab}

empty inner tree (not terminal)

the child list must be completed with add

#### `public  `[`RhythmTree`](#group__output_1gac868521df843e116ef04bcfa52405d01)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` lab)` {#group__output_1gac868521df843e116ef04bcfa52405d01}

single leaf rhythm tree (terminal tree)

#### `public  `[`RhythmTree`](#group__output_1ga058c6d59881e1be259594165d19c8588)`(const string &)` {#group__output_1ga058c6d59881e1be259594165d19c8588}

extract RT from string description

#### `public  `[`~RhythmTree`](#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee)`()` {#group__output_1gaa58da0cc1e6a1848d19c7276eaeb23ee}

#### `public bool `[`terminal`](#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd)`() const` {#group__output_1ga4f875cf76d3ebc8270a471ef57e93ddd}

single node tree

#### `public inline bool `[`inner`](#classRhythmTree_1a67a3180bb74745a6e81f88835a74f740)`() const` {#classRhythmTree_1a67a3180bb74745a6e81f88835a74f740}

#### `public size_t `[`arity`](#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e)`() const` {#group__output_1ga813a6feea3e6aa565fa0aed29e970a4e}

arity of root node (0 for terminal tree)

#### `public `[`RhythmTree`](#classRhythmTree)` * `[`child`](#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd)`(size_t i) const` {#group__output_1ga130dd34b9f3e0db4ad4f185181895dbd}

return the ith child of this tree

this tree must be inner (not terminal)

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350)`() const` {#group__output_1ga40e2aa462ed42fa46d3beafca9dbc350}

label for terminal node

this tree must be terminal

#### `public bool `[`continuation`](#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0)`() const` {#group__output_1ga1ca015dec36fa32ff6d66aaad10f4eb0}

label of terminal node is a continuation

this tree must be terminal

#### `public bool `[`single_event`](#group__output_1gabd793b78f71fb62edb13497e0a13f48c)`() const` {#group__output_1gabd793b78f71fb62edb13497e0a13f48c}

label of terminal node is a single event (1 note / rest, no grace note).

this tree must be terminal

#### `public size_t `[`nbgn`](#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7)`() const` {#group__output_1gaaaf06fe2227a6598b109a72d89afa8d7}

number of grace notes in this terminal node.

this tree must be terminal

#### `public bool `[`reducible`](#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9)`() const` {#group__output_1gafdda5b1a3c16c8e64337c26bcdb368e9}

this tree contains a subtree of the form.

```cpp
p(n, o,...,o) 
```
 or 
```cpp
p(o,...,o) 
```

#### `public void `[`add`](#group__output_1ga5749469b3ff6ec88fcab75961e7d278c)`(`[`RhythmTree`](#classRhythmTree)` *)` {#group__output_1ga5749469b3ff6ec88fcab75961e7d278c}

add a subtree.

this tree must not be terminal

#### `public string `[`lily`](#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259)`(int depth,bool tie) const` {#group__output_1gafcd0d23d1cdb8cd92fbaec2fac51d259}

LilyPond format.

Lilypond output for RT [http://lilypond.org](http://lilypond.org).

#### `public string `[`lilydot`](#group__output_1ga93aca0f691a35a081d51eaad06e8ce50)`(int depth)` {#group__output_1ga93aca0f691a35a081d51eaad06e8ce50}

LilyPond format with dots.

#### `public string `[`APTED`](#group__output_1ga2c194b384127267b8cfed2c41e70d338)`() const` {#group__output_1ga2c194b384127267b8cfed2c41e70d338}

format for Tree Edit [Distance](#classDistance) Salzburg library.

RT output format for Tree Edit [Distance](#classDistance) library APTED algorithm of M. Pawlik and N. Augsten [http://tree-edit-distance.dbresearch.uni-salzburg.at](http://tree-edit-distance.dbresearch.uni-salzburg.at).

#### `public string `[`to_string`](#group__output_1gac6764688e24fe9b942464a9c2053ee92)`() const` {#group__output_1gac6764688e24fe9b942464a9c2053ee92}

#### `protected long `[`_label`](api-output.md#classRhythmTree_1a172a0c68e4b6adace9c025c9159040e2) {#classRhythmTree_1a172a0c68e4b6adace9c025c9159040e2}

for leaves, it is the positive integer stored in the leaf; for inner tree, it is a negative integer.

long int : for comparison with state_t = size_t = unsigned long (=label of terminal [Run](#classRun))

#### `protected std::vector< `[`RhythmTree`](#classRhythmTree)` * > `[`_children`](#classRhythmTree_1ac11078e58a8ca630953768bc6dc4d74e) {#classRhythmTree_1ac11078e58a8ca630953768bc6dc4d74e}

#### `protected bool `[`tail_redex`](#group__output_1gaf723874e871dc01efb036ccbac07c32b)`() const` {#group__output_1gaf723874e871dc01efb036ccbac07c32b}

inner and the children list is of the form.

```cpp
(_, o,...,o) 
```

#### `protected bool `[`tail_reducible`](#group__output_1ga799761965ae00bb24e16ebb98f66995a)`() const` {#group__output_1ga799761965ae00bb24e16ebb98f66995a}

inner and one of the children 1..a is reducible.

#### `protected bool `[`tie`](#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47)`() const` {#group__output_1ga3933e83072d4e7c3bb3d19d25df90b47}

return whether this tree is a continuation (a leaf).

#### `protected bool `[`binary`](#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72)`() const` {#group__output_1gafb30d2c520e4c5e8600ae3a58abf9c72}

return whether this tree is binary.

#### `protected bool `[`tied`](#group__output_1gacd73e0032e3dd22320819c4cda3d60a4)`() const` {#group__output_1gacd73e0032e3dd22320819c4cda3d60a4}

return whether the leftmost innermost leaf is a tie (continuation).

#### `protected bool `[`second_tied`](#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4)`() const` {#group__output_1ga9aebdccd4ce1d1029d03f4ec38c101c4}

return whether this tree is binary and the second child is tied.

#### `protected bool `[`dot_after`](#group__output_1gac785e6d945ef6e0808132459669ab038)`() const` {#group__output_1gac785e6d945ef6e0808132459669ab038}

return whether this tree is binary and the left son is a dot (continuation after the dotted note).

#### `protected bool `[`dot_before`](#group__output_1ga2079bd534900d0b10e74682e404230b1)`() const` {#group__output_1ga2079bd534900d0b10e74682e404230b1}

return whether this tree is binary and the right son is a dot (continuation before the dotted note).

#### `protected string `[`lilydot`](#group__output_1ga89f5bf140b902f886be124d620ac8474)`(int depth,bool tie,bool dot,bool ignore_first,bool ignore_second)` {#group__output_1ga89f5bf140b902f886be124d620ac8474}

LilyPond format with dots.

# class `SerialLabel` {#classSerialLabel}

static functions for serializable int encoding of input and output leaf symbols containing the following info:

* [input info]

* pre value: number of events from previous segment aligned to left of current input segment

* post value: number of events aligned to right of current input segment

* [output info]

* number of grace notes in output

* number of events in output (notes + grace notes)

the encoding is 
```cpp
pre * (MAX_GRACE+1)^2 + post * (MAX_GRACE+1) + number_events
```

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ValueList` {#classValueList}

list of rational durations as components of value states.

Each duration is either positive (event w or wo continuations -ties) or null (grace note).

a value list is made of 2 parts:

* _cont : initial duration (possibly null) tied to the previous duration list

* _main : main list of the other events (without ties) it is represented by _cont[_main]

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ValueList`](#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185)`(`[`Rational`](#classRational)`)` | 
`public  `[`ValueList`](#group__output_1gaec135d71a5c51579bec52c805c0b3ded)`(const `[`DurationList`](#classDurationList)` &)` | 
`public  `[`ValueList`](#group__output_1gabd7a0aa8113f72c13205c0702eb269ff)`(const `[`ValueList`](#classValueList)` &)` | 
`public  `[`ValueList`](#group__output_1gad518d3f6ddf7fb7b74275eef20205893)`(std::string)` | 
`public inline  `[`~ValueList`](#classValueList_1ae604218dbae6c1bc0c9675960be5af5d)`()` | 
`public `[`ValueList`](#classValueList)` & `[`operator=`](#group__output_1gab09ac2a5e83e806431634ddd87f596fc)`(const `[`ValueList`](#classValueList)` &)` | 
`public bool `[`empty`](#group__output_1ga7510db734db466464100413728db233c)`() const` | 
`public inline size_t `[`size`](#classValueList_1a21c3cca5483e25f27cadb7ae82d2dd96)`() const` | 
`public inline `[`Rational`](#classRational)` `[`length`](#classValueList_1a1a24053a2e70a12da2af6680b594d03b)`() const` | 
`public inline `[`Rational`](#classRational)` `[`cont`](#classValueList_1a3d7f406dd34ed78e0f12324075ee2c8b)`() const` | 
`public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`begin`](#classValueList_1af5e02ab5d58c4c9196a23473d55e7ae9)`() const` | 
`public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`end`](#classValueList_1abd03430257070988728b597fa1467353)`() const` | 
`public bool `[`complete`](#group__output_1ga2ebf6a43ad145e4593cc961a4016f330)`() const` | 
`public bool `[`single_continuation`](#group__output_1ga9d68ca01f81000f92f1c8911cbd414da)`() const` | 
`public bool `[`single_event`](#group__output_1ga699183ea1d3babeb7c2c094e31e7070f)`() const` | 
`public bool `[`event`](#group__output_1gaff6e5912f71832597303efe0093d5d00)`() const` | 
`public inline size_t `[`nbgn`](#classValueList_1a502abe52ee55ed7616fcfadfa4f1e070)`() const` | 
`public void `[`add`](#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0)`(`[`Rational`](#classRational)`)` | 
`public void `[`addcont`](#group__output_1gaeb6d26ee1813f879c07148df644a5321)`(`[`Rational`](#classRational)`)` | 
`public `[`Rational`](#classRational)` `[`front`](#group__output_1ga282fe7cbc28917f2b096d2183419a30c)`() const` | 
`public `[`Rational`](#classRational)` `[`pop`](#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed)`()` | 
`public `[`Rational`](#classRational)` `[`popcont`](#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9)`()` | 
`public void `[`popcont`](#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea)`(`[`Rational`](#classRational)`)` | 

## Members

#### `public  `[`ValueList`](#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185)`(`[`Rational`](#classRational)`)` {#group__output_1ga187d1dfe0e942d18f1e2c3150e9aa185}

#### `public  `[`ValueList`](#group__output_1gaec135d71a5c51579bec52c805c0b3ded)`(const `[`DurationList`](#classDurationList)` &)` {#group__output_1gaec135d71a5c51579bec52c805c0b3ded}

#### `public  `[`ValueList`](#group__output_1gabd7a0aa8113f72c13205c0702eb269ff)`(const `[`ValueList`](#classValueList)` &)` {#group__output_1gabd7a0aa8113f72c13205c0702eb269ff}

#### `public  `[`ValueList`](#group__output_1gad518d3f6ddf7fb7b74275eef20205893)`(std::string)` {#group__output_1gad518d3f6ddf7fb7b74275eef20205893}

#### `public inline  `[`~ValueList`](#classValueList_1ae604218dbae6c1bc0c9675960be5af5d)`()` {#classValueList_1ae604218dbae6c1bc0c9675960be5af5d}

#### `public `[`ValueList`](#classValueList)` & `[`operator=`](#group__output_1gab09ac2a5e83e806431634ddd87f596fc)`(const `[`ValueList`](#classValueList)` &)` {#group__output_1gab09ac2a5e83e806431634ddd87f596fc}

#### `public bool `[`empty`](#group__output_1ga7510db734db466464100413728db233c)`() const` {#group__output_1ga7510db734db466464100413728db233c}

#### `public inline size_t `[`size`](#classValueList_1a21c3cca5483e25f27cadb7ae82d2dd96)`() const` {#classValueList_1a21c3cca5483e25f27cadb7ae82d2dd96}

#### `public inline `[`Rational`](#classRational)` `[`length`](#classValueList_1a1a24053a2e70a12da2af6680b594d03b)`() const` {#classValueList_1a1a24053a2e70a12da2af6680b594d03b}

#### `public inline `[`Rational`](#classRational)` `[`cont`](#classValueList_1a3d7f406dd34ed78e0f12324075ee2c8b)`() const` {#classValueList_1a3d7f406dd34ed78e0f12324075ee2c8b}

#### `public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`begin`](#classValueList_1af5e02ab5d58c4c9196a23473d55e7ae9)`() const` {#classValueList_1af5e02ab5d58c4c9196a23473d55e7ae9}

#### `public inline std::list< `[`Rational`](#classRational)` >::const_iterator `[`end`](#classValueList_1abd03430257070988728b597fa1467353)`() const` {#classValueList_1abd03430257070988728b597fa1467353}

#### `public bool `[`complete`](#group__output_1ga2ebf6a43ad145e4593cc961a4016f330)`() const` {#group__output_1ga2ebf6a43ad145e4593cc961a4016f330}

#### `public bool `[`single_continuation`](#group__output_1ga9d68ca01f81000f92f1c8911cbd414da)`() const` {#group__output_1ga9d68ca01f81000f92f1c8911cbd414da}

#### `public bool `[`single_event`](#group__output_1ga699183ea1d3babeb7c2c094e31e7070f)`() const` {#group__output_1ga699183ea1d3babeb7c2c094e31e7070f}

#### `public bool `[`event`](#group__output_1gaff6e5912f71832597303efe0093d5d00)`() const` {#group__output_1gaff6e5912f71832597303efe0093d5d00}

#### `public inline size_t `[`nbgn`](#classValueList_1a502abe52ee55ed7616fcfadfa4f1e070)`() const` {#classValueList_1a502abe52ee55ed7616fcfadfa4f1e070}

#### `public void `[`add`](#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0)`(`[`Rational`](#classRational)`)` {#group__output_1ga9078b4e45f9864eec53bbfa68d7709d0}

#### `public void `[`addcont`](#group__output_1gaeb6d26ee1813f879c07148df644a5321)`(`[`Rational`](#classRational)`)` {#group__output_1gaeb6d26ee1813f879c07148df644a5321}

#### `public `[`Rational`](#classRational)` `[`front`](#group__output_1ga282fe7cbc28917f2b096d2183419a30c)`() const` {#group__output_1ga282fe7cbc28917f2b096d2183419a30c}

#### `public `[`Rational`](#classRational)` `[`pop`](#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed)`()` {#group__output_1ga9d5ccdd934a0715c597650fd8cd8d5ed}

#### `public `[`Rational`](#classRational)` `[`popcont`](#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9)`()` {#group__output_1ga77bf4e64e28ee7a3bd2989ffe25f7fc9}

#### `public void `[`popcont`](#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea)`(`[`Rational`](#classRational)`)` {#group__output_1ga7802d98c6ad4e622847be23fbaa6cbea}

