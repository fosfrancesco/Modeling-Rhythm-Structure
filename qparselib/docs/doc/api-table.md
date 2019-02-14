# group `table` {#group__table}

The `table` module contains classes for parse tables and their content.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`PTR_LPAR`](#group__table_1ga87af6cf583d4ad6776fb6d5547cecdf0)            | 
`define `[`PTR_RPAR`](#group__table_1ga872ca8d837f318949c33691219969c5b)            | 
`public std::ostream & `[`operator<<`](#group__table_1gad263d9daed9b87d43b2197cac98bced2)`(std::ostream & o,const `[`Spointer`](#classSpointer)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__table_1ga86a37eaf8509fee42b0cecf04740db9b)`(std::ostream & o,const `[`SIpointer`](#classSIpointer)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__table_1ga7576e987b23cc05f8c50602b5fbe5fe3)`(std::ostream & o,const `[`SIPpointer`](#classSIPpointer)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__table_1ga408ad7443ca740b3f261b7ef920bc26f)`(std::ostream & o,const `[`SKpointer`](#classSKpointer)` & p)`            | 
`public std::ostream & `[`operator<<`](#group__table_1ga015154c0d3f197a32544c20ea2f70c10)`(std::ostream & o,const `[`SKIPpointer`](#classSKIPpointer)` & p)`            | 
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga4ca596fe52abd36d550a10818678d54c)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const`            | return the weight for a terminal [Run](#classRun) associated to the given [Transition](#classTransition). The transition must be terminal. This pointer must be compatible with the [Transition](#classTransition). input segment can be NULL.
`public virtual `[`Weight`](#classWeight)` `[`innerWeight`](#group__table_1gad709430d698804267807f12deba9952b)`(const `[`Transition`](#classTransition)` &) const`            | return the initial weight for an inner [Run](#classRun) associated to the given [Transition](#classTransition). the weight will have to be multiplied with all the weights of subruns. the transition must be inner. this pointer must be divisible.
`public  `[`Spointer`](#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4)`()`            | specific
`public  `[`Spointer`](#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | specific
`public  `[`Spointer`](#group__table_1ga49f82b7aafd3ae237243c85272597fa7)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)`            | top ptr (head of the main [Run](#classRun)).
`public  `[`Spointer`](#group__table_1ga72441f0d67497c90602a123c45dc53d1)`(`[`Environment`](#classEnvironment)` * env,const `[`Spointer`](#classSpointer)` & p,size_t a,size_t i,state_t s)`            | sub-pointer or instance as leaf.
`public  `[`Spointer`](#group__table_1gaf40e1a1f0edc608d4413f096a19aae78)`(const `[`Spointer`](#classSpointer)` &)`            | copy.
`public  `[`Spointer`](#group__table_1gac303715911a48c482acb6ae4188508d3)`(const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)`            | next sibling.
`public  `[`Spointer`](#group__table_1gad078973f8318ccf5800db79e87584dcc)`(const `[`Spointer`](#classSpointer)` & p,const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)`            | instance as parent.
`public virtual `[`Spointer`](#classSpointer)` & `[`operator=`](#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb)`(const `[`Spointer`](#classSpointer)` &)`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772)`(const `[`Spointer`](#classSpointer)` &) const`            | for use as key in a unorered_multimap.
`public virtual bool `[`operator<`](#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8)`(const `[`Spointer`](#classSpointer)` &) const`            | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b)`(const `[`Spointer`](#classSpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1ga06fa67855bfb50d81e18bdfacce965ce)`(const `[`Spointer`](#classSpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`complete`](#group__table_1gace5bd2026fef480084f3cc5dc28086f3)`() const`            | the pointer is complete i.e. all fields are set
`public virtual bool `[`dummy`](#group__table_1ga0a994ec6827ef23556b500382fc5a1fc)`() const`            | return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga15067ad809b5ac25b45c0187550e0b17)`(const `[`Transition`](#classTransition)` & t) const`            | return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.
`public virtual bool `[`divisible`](#group__table_1ga54817fbae1688dab4dfff5724e762640)`() const`            | this pointer must have a [WTA](api-schemata.md#classWTA) state always return true in that case
`public  `[`SIpointer`](#group__table_1ga7e962d8567566398e5f620ef964267cd)`()`            | dummy ptr
`public  `[`SIpointer`](#group__table_1ga464163b749ecd94516ab6e94f7baa5bf)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | fake ptr for terminal run, contains only a label symbol it is considered as complete see description in [Ptr.hpp](#Ptr_8hpp_source)
`public  `[`SIpointer`](#group__table_1gac560506e7bf1439877178cf6d2459e7f)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`Rational`](#classRational)` mdur,double rext)`            | class specific top ptr (covering the whole input segment + given extension in realtime, of given musical duration.
`public  `[`SIpointer`](#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)`            | split ptr p in 2 parts.
`public  `[`SIpointer`](#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,size_t a,size_t i,state_t s)`            | sub-pointer or instance as leaf.
`public  `[`SIpointer`](#group__table_1ga3df3168789d247e497f127caa7840e88)`(const `[`SIpointer`](#classSIpointer)` &)`            | copy.
`public  `[`SIpointer`](#group__table_1ga175406f6e30433d90a004aa27c401f29)`(const `[`SIpointer`](#classSIpointer)` & p,const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)`            | instance as parent.
`public  `[`SIpointer`](#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e)`(const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)`            | instance as next sibling.
`public virtual `[`SIpointer`](#classSIpointer)` & `[`operator=`](#group__table_1ga071bb69977a62e26f9ec11230ae2646b)`(const `[`SIpointer`](#classSIpointer)` &)`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`protected bool `[`equal_node`](#group__table_1gacc34f81b5d73c93840bce279ddde4620)`(const `[`SIpointer`](#classSIpointer)` &) const`            | 
`public virtual bool `[`operator==`](#group__table_1ga3330f8e59b08797b4c73ae558f6d588e)`(const `[`SIpointer`](#classSIpointer)` &) const`            | for use as key in a unordered_multimap.
`public virtual bool `[`operator!=`](#group__table_1ga303c4da57a70fa07b7a2de3692fc9091)`(const `[`SIpointer`](#classSIpointer)` &) const`            | 
`public virtual bool `[`operator<`](#group__table_1ga51c64ecf271622a259840f55236778ef)`(const `[`SIpointer`](#classSIpointer)` &) const`            | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1ga259b23462f7e87f6df0e9361c1884618)`(const `[`SIpointer`](#classSIpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f)`(const `[`SIpointer`](#classSIpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`complete`](#group__table_1ga638627bc96caa0f1dbf7093f0f70951b)`() const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga6bdbea8e7013194f834be17932efe642)`(const `[`Transition`](#classTransition)` & t) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source) the _pre value must be known _node must be set
`public virtual bool `[`divisible`](#group__table_1gac83e0619c17ce4efd589f73513706a6b)`() const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`compatible`](#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`dummy`](#group__table_1ga555753e41af94ac201a0c8c99babb83b)`() const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public  `[`SIPpointer`](#group__table_1gac498892cd08ebd0663899dc82b00fac6)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)`            | dummy ptr.
`public  `[`SIPpointer`](#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)`            | fake ptr for terminal run, contains only a label symbol. it is considered as complete
`public  `[`SIPpointer`](#group__table_1ga5470d875405a71931e2349915201da20)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,double rext)`            | class specific top ptr (covering the whole input segment
`public  `[`SIPpointer`](#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)`            | split ptr p in 2 parts.
`public  `[`SIPpointer`](#group__table_1gad83be64e20b13419994b3e9ae23654d1)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,size_t a,size_t i,state_t s)`            | sub-pointer or instance as leaf.
`public  `[`SIPpointer`](#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e)`(const `[`SIPpointer`](#classSIPpointer)` &)`            | copy.
`public  `[`SIPpointer`](#group__table_1gaa4c3c43c081bf789120e96683bc70cb3)`(const `[`SIPpointer`](#classSIPpointer)` & p,const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)`            | instance as parent.
`public  `[`SIPpointer`](#group__table_1ga12c22407821e96d6c7d0bca88392cbda)`(const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)`            | instance as next sibling.
`public virtual `[`SIPpointer`](#classSIPpointer)` & `[`operator=`](#group__table_1ga9855eef9600bbdd1e74343844e0c158c)`(const `[`SIPpointer`](#classSIPpointer)` &)`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1ga519f21be86b2ddb4fae2bab869434863)`(const `[`SIPpointer`](#classSIPpointer)` &) const`            | for use as key in a unordered_multimap.
`public virtual bool `[`operator!=`](#group__table_1ga58f25245c42e16d11738e74c66a63cf6)`(const `[`SIPpointer`](#classSIPpointer)` &) const`            | 
`public virtual bool `[`operator<`](#group__table_1gaefff5ba3579bd6174700ab1462fa13fb)`(const `[`SIPpointer`](#classSIPpointer)` &) const`            | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1gad7e14d03ea63991d16a0da5292eda82d)`(const `[`SIPpointer`](#classSIPpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gae02f880deb0305e3122caf05f9d2bad0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`complete`](#group__table_1ga2f95b5a2058b20744a00737b1240bc83)`() const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0)`(const `[`Transition`](#classTransition)` & t) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`compatible`](#group__table_1gabf87df773f8e0f628e0bae79e88097db)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`dummy`](#group__table_1gaf830b0bf9d24b53e4674de49308b7853)`() const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga01caac75d66ff2e272a248c7e1954415)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`Transition`](#classTransition)` & t) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public  `[`SKpointer`](#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5)`()`            | specific
`public  `[`SKpointer`](#group__table_1ga876c1101716f9aea625574f9be9b3da5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)`            | specific
`public  `[`SKpointer`](#group__table_1ga022b6998c4273e2da8128ccd2205a7f6)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)`            | top ptr.
`public  `[`SKpointer`](#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9)`(`[`Environment`](#classEnvironment)` *,const `[`SKpointer`](#classSKpointer)` & p,size_t a,size_t i,state_t s)`            | sub-pointer or instance as leaf.
`public  `[`SKpointer`](#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3)`(const `[`SKpointer`](#classSKpointer)` &)`            | copy.
`public  `[`SKpointer`](#group__table_1gaf762b88808d2e8188b74e28256d3ed09)`(const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)`            | next sibling.
`public  `[`SKpointer`](#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9)`(const `[`SKpointer`](#classSKpointer)` & p,const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)`            | instance as parent.
`public virtual `[`SKpointer`](#classSKpointer)` & `[`operator=`](#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1)`(const `[`SKpointer`](#classSKpointer)` &)`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1gab77c2fa945fcc938568ace9986c25324)`(const `[`SKpointer`](#classSKpointer)` &) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`instance`](#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937)`(const `[`SKpointer`](#classSKpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1ga38150ffb7a8bf25ebf5133907d568738)`(const `[`SKpointer`](#classSKpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual void `[`incr`](#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a)`()`            | 
`public  `[`SKIPpointer`](#group__table_1ga24e762a60a81030599decff93dc1a1ef)`()`            | dummy ptr.
`public  `[`SKIPpointer`](#group__table_1ga1fc4cd4038153502277d11c5607a14fa)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)`            | specific fake ptr for terminal run, contains only a label symbol. it is considered as complete
`public  `[`SKIPpointer`](#group__table_1gab217454122f2ec0af5c16bb1ae996925)`(`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,bool bar,size_t k)`            | TBR deprecated.
`public  `[`SKIPpointer`](#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,size_t k)`            | class specific top ptr (covering the whole input segment.
`public  `[`SKIPpointer`](#group__table_1ga6cd275122aebf4288f5d60c36a141116)`(`[`Environment`](#classEnvironment)` * env,const `[`SKIPpointer`](#classSKIPpointer)` & p,size_t a,size_t i,state_t s)`            | sub-pointer or instance as leaf.
`public  `[`SKIPpointer`](#group__table_1ga3366b26b81c9cb040716918f7d375879)`(const `[`SKIPpointer`](#classSKIPpointer)` &)`            | copy.
`public  `[`SKIPpointer`](#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d)`(const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)`            | next sibling.
`public  `[`SKIPpointer`](#group__table_1ga8b87b18aa76b4021da6d3421c738b002)`(const `[`SKIPpointer`](#classSKIPpointer)` & p,const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)`            | instance as parent.
`public virtual `[`SKIPpointer`](#classSKIPpointer)` & `[`operator=`](#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4)`(const `[`SKIPpointer`](#classSKIPpointer)` &)`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4)`(const `[`SKIPpointer`](#classSKIPpointer)` &) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`instance`](#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gaacf829ba5696414bdcc753e97e76a7f1)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const`            | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual void `[`incr`](#group__table_1gac0c72ab0a91e652b38eb815206b0baa4)`()`            | 
`class `[`Parser`](api-table.md#classParser) | 
`class `[`Atable`](api-table.md#classAtable) | abstract interface to parse table
`class `[`Brecord`](api-table.md#classBrecord) | record associated to Ptr for one-best procedures.
`class `[`Krecord`](api-table.md#classKrecord) | record associated to Ptr for k-best procedures.
`class `[`Pointer`](api-table.md#classPointer) | abstract class defining a signature for a class of pointer to best runs.
`class `[`Spointer`](api-table.md#classSpointer) | key in a parse table.
`class `[`SIpointer`](api-table.md#classSIpointer) | 
`class `[`SIPpointer`](api-table.md#classSIPpointer) | key in a parse table. pointer to a (best) run for 1-best parsing for [WTA](api-schemata.md#classWTA) and input segment.
`class `[`SKpointer`](api-table.md#classSKpointer) | pointer to a (best) run. for k-best parsing with standard [WTA](#classWTA) a [SKpointer](#classSKpointer) contains
`class `[`SKIPpointer`](api-table.md#classSKIPpointer) | 
`class `[`Record`](api-table.md#classRecord) | abstract class describing the basic functionalities of a record.
`class `[`Run`](api-table.md#classRun) | a run is a compact representation of parse trees as a tuple of pointers to subruns.
`class `[`Table`](api-table.md#classTable) | parse table.
`struct `[`SpointerHasher`](api-table.md#structSpointerHasher) | 
`struct `[`SIpointerHasher`](api-table.md#structSIpointerHasher) | hash function for using as key in a table. rank is ignoreds : same as [SpointerHasher](api-table.md#structSpointerHasher)
`struct `[`SIPpointerHasher`](api-table.md#structSIPpointerHasher) | hash function for using as key in a table rank is ignoreds : same as [SpointerHasher](api-table.md#structSpointerHasher)
`struct `[`SKpointerHasher`](api-table.md#structSKpointerHasher) | hash function for using as key in a table rank is ignoreds : same as [SpointerHasher](api-table.md#structSpointerHasher)
`struct `[`SKIPpointerHasher`](api-table.md#structSKIPpointerHasher) | hash function for using as key in a table.

## Members

#### `define `[`PTR_LPAR`](#group__table_1ga87af6cf583d4ad6776fb6d5547cecdf0) {#group__table_1ga87af6cf583d4ad6776fb6d5547cecdf0}

#### `define `[`PTR_RPAR`](#group__table_1ga872ca8d837f318949c33691219969c5b) {#group__table_1ga872ca8d837f318949c33691219969c5b}

#### `public std::ostream & `[`operator<<`](#group__table_1gad263d9daed9b87d43b2197cac98bced2)`(std::ostream & o,const `[`Spointer`](#classSpointer)` & p)` {#group__table_1gad263d9daed9b87d43b2197cac98bced2}

#### `public std::ostream & `[`operator<<`](#group__table_1ga86a37eaf8509fee42b0cecf04740db9b)`(std::ostream & o,const `[`SIpointer`](#classSIpointer)` & p)` {#group__table_1ga86a37eaf8509fee42b0cecf04740db9b}

#### `public std::ostream & `[`operator<<`](#group__table_1ga7576e987b23cc05f8c50602b5fbe5fe3)`(std::ostream & o,const `[`SIPpointer`](#classSIPpointer)` & p)` {#group__table_1ga7576e987b23cc05f8c50602b5fbe5fe3}

#### `public std::ostream & `[`operator<<`](#group__table_1ga408ad7443ca740b3f261b7ef920bc26f)`(std::ostream & o,const `[`SKpointer`](#classSKpointer)` & p)` {#group__table_1ga408ad7443ca740b3f261b7ef920bc26f}

#### `public std::ostream & `[`operator<<`](#group__table_1ga015154c0d3f197a32544c20ea2f70c10)`(std::ostream & o,const `[`SKIPpointer`](#classSKIPpointer)` & p)` {#group__table_1ga015154c0d3f197a32544c20ea2f70c10}

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga4ca596fe52abd36d550a10818678d54c)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` {#group__table_1ga4ca596fe52abd36d550a10818678d54c}

return the weight for a terminal [Run](#classRun) associated to the given [Transition](#classTransition). The transition must be terminal. This pointer must be compatible with the [Transition](#classTransition). input segment can be NULL.

#### `public virtual `[`Weight`](#classWeight)` `[`innerWeight`](#group__table_1gad709430d698804267807f12deba9952b)`(const `[`Transition`](#classTransition)` &) const` {#group__table_1gad709430d698804267807f12deba9952b}

return the initial weight for an inner [Run](#classRun) associated to the given [Transition](#classTransition). the weight will have to be multiplied with all the weights of subruns. the transition must be inner. this pointer must be divisible.

#### `public  `[`Spointer`](#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4)`()` {#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4}

specific

#### `public  `[`Spointer`](#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5}

specific

#### `public  `[`Spointer`](#group__table_1ga49f82b7aafd3ae237243c85272597fa7)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` {#group__table_1ga49f82b7aafd3ae237243c85272597fa7}

top ptr (head of the main [Run](#classRun)).

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `bar` must be true 

* `k` must be 1 

TBR deprecated (replace by specific constructor)

#### `public  `[`Spointer`](#group__table_1ga72441f0d67497c90602a123c45dc53d1)`(`[`Environment`](#classEnvironment)` * env,const `[`Spointer`](#classSpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1ga72441f0d67497c90602a123c45dc53d1}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `p` must have a wta state 

* `a` 

* `i` if a>0 and i=0, construct a copy of p. if a>0 and 0<i<=a, construct a copy a ptr with state s.

#### `public  `[`Spointer`](#group__table_1gaf40e1a1f0edc608d4413f096a19aae78)`(const `[`Spointer`](#classSpointer)` &)` {#group__table_1gaf40e1a1f0edc608d4413f096a19aae78}

copy.

#### `public  `[`Spointer`](#group__table_1gac303715911a48c482acb6ae4188508d3)`(const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` {#group__table_1gac303715911a48c482acb6ae4188508d3}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial.

#### `public  `[`Spointer`](#group__table_1gad078973f8318ccf5800db79e87584dcc)`(const `[`Spointer`](#classSpointer)` & p,const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` {#group__table_1gad078973f8318ccf5800db79e87584dcc}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial.

#### `public virtual `[`Spointer`](#classSpointer)` & `[`operator=`](#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb)`(const `[`Spointer`](#classSpointer)` &)` {#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772)`(const `[`Spointer`](#classSpointer)` &) const` {#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772}

for use as key in a unorered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator<`](#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8)`(const `[`Spointer`](#classSpointer)` &) const` {#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b)`(const `[`Spointer`](#classSpointer)` & p) const` {#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1ga06fa67855bfb50d81e18bdfacce965ce)`(const `[`Spointer`](#classSpointer)` & p) const` {#group__table_1ga06fa67855bfb50d81e18bdfacce965ce}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`complete`](#group__table_1gace5bd2026fef480084f3cc5dc28086f3)`() const` {#group__table_1gace5bd2026fef480084f3cc5dc28086f3}

the pointer is complete i.e. all fields are set

#### `public virtual bool `[`dummy`](#group__table_1ga0a994ec6827ef23556b500382fc5a1fc)`() const` {#group__table_1ga0a994ec6827ef23556b500382fc5a1fc}

return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga15067ad809b5ac25b45c0187550e0b17)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga15067ad809b5ac25b45c0187550e0b17}

return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.

#### `public virtual bool `[`divisible`](#group__table_1ga54817fbae1688dab4dfff5724e762640)`() const` {#group__table_1ga54817fbae1688dab4dfff5724e762640}

this pointer must have a [WTA](#classWTA) state always return true in that case

#### `public  `[`SIpointer`](#group__table_1ga7e962d8567566398e5f620ef964267cd)`()` {#group__table_1ga7e962d8567566398e5f620ef964267cd}

dummy ptr

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga464163b749ecd94516ab6e94f7baa5bf)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1ga464163b749ecd94516ab6e94f7baa5bf}

fake ptr for terminal run, contains only a label symbol it is considered as complete see description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1gac560506e7bf1439877178cf6d2459e7f)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`Rational`](#classRational)` mdur,double rext)` {#group__table_1gac560506e7bf1439877178cf6d2459e7f}

class specific top ptr (covering the whole input segment + given extension in realtime, of given musical duration.

#### Parameters
* `env` must contain an input segment and interval heap.

#### `public  `[`SIpointer`](#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` {#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05}

split ptr p in 2 parts.

if position = 0, first part has (real-time/musical-time) durations rdur/mdur

if position = 1, second part has (real-time/musical-time) durations rdur/mdur construct part number i (1 or 2) 
#### Parameters
* `env` must contain an input segment and interval heap 

* `rdur` must be strictly positive. 

* `mdur` must be strictly positive. 

* `i` must be 1 or 2. 

* `s` can be [WTA](#classWTA) state or Meta state.

#### `public  `[`SIpointer`](#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga3df3168789d247e497f127caa7840e88)`(const `[`SIpointer`](#classSIpointer)` &)` {#group__table_1ga3df3168789d247e497f127caa7840e88}

copy.

#### `public  `[`SIpointer`](#group__table_1ga175406f6e30433d90a004aa27c401f29)`(const `[`SIpointer`](#classSIpointer)` & p,const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` {#group__table_1ga175406f6e30433d90a004aa27c401f29}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e)`(const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` {#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e}

instance as next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`SIpointer`](#classSIpointer)` & `[`operator=`](#group__table_1ga071bb69977a62e26f9ec11230ae2646b)`(const `[`SIpointer`](#classSIpointer)` &)` {#group__table_1ga071bb69977a62e26f9ec11230ae2646b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `protected bool `[`equal_node`](#group__table_1gacc34f81b5d73c93840bce279ddde4620)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1gacc34f81b5d73c93840bce279ddde4620}

#### `public virtual bool `[`operator==`](#group__table_1ga3330f8e59b08797b4c73ae558f6d588e)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga3330f8e59b08797b4c73ae558f6d588e}

for use as key in a unordered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator!=`](#group__table_1ga303c4da57a70fa07b7a2de3692fc9091)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga303c4da57a70fa07b7a2de3692fc9091}

#### `public virtual bool `[`operator<`](#group__table_1ga51c64ecf271622a259840f55236778ef)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga51c64ecf271622a259840f55236778ef}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga259b23462f7e87f6df0e9361c1884618)`(const `[`SIpointer`](#classSIpointer)` & p) const` {#group__table_1ga259b23462f7e87f6df0e9361c1884618}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f)`(const `[`SIpointer`](#classSIpointer)` & p) const` {#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`complete`](#group__table_1ga638627bc96caa0f1dbf7093f0f70951b)`() const` {#group__table_1ga638627bc96caa0f1dbf7093f0f70951b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga6bdbea8e7013194f834be17932efe642)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga6bdbea8e7013194f834be17932efe642}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source) the _pre value must be known _node must be set

#### `public virtual bool `[`divisible`](#group__table_1gac83e0619c17ce4efd589f73513706a6b)`() const` {#group__table_1gac83e0619c17ce4efd589f73513706a6b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

if this pointer has a [WTA](#classWTA) state: it is not worth descending when this pointer corresponds to an input sub-segment not inhabited.

if this pointer has a Meta state: it is not worth descending when this ptr corresponds to an empty segment.

#### `public virtual bool `[`compatible`](#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` {#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`dummy`](#group__table_1ga555753e41af94ac201a0c8c99babb83b)`() const` {#group__table_1ga555753e41af94ac201a0c8c99babb83b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` {#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

input segment must not be NULL.

#### `public  `[`SIPpointer`](#group__table_1gac498892cd08ebd0663899dc82b00fac6)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__table_1gac498892cd08ebd0663899dc82b00fac6}

dummy ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c}

fake ptr for terminal run, contains only a label symbol. it is considered as complete

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga5470d875405a71931e2349915201da20)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,double rext)` {#group__table_1ga5470d875405a71931e2349915201da20}

class specific top ptr (covering the whole input segment

* given extension in realtime.

#### Parameters
* `env` must contain an input segment and interval heap

#### `public  `[`SIPpointer`](#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` {#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379}

split ptr p in 2 parts.

if position = 0, first part has (real-time/musical-time) durations rdur/mdur

if position = 1, second part has (real-time/musical-time) durations rdur/mdur

construct part number i (1 or 2) 
#### Parameters
* `env` must contain an input segment and interval heap 

* `rdur` must be strictly positive. 

* `mdur` must be strictly positive. 

* `i` must be 1 or 2. 

* `s` (state) can be [WTA](#classWTA) or Meta.

#### `public  `[`SIPpointer`](#group__table_1gad83be64e20b13419994b3e9ae23654d1)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gad83be64e20b13419994b3e9ae23654d1}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e)`(const `[`SIPpointer`](#classSIPpointer)` &)` {#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e}

copy.

#### `public  `[`SIPpointer`](#group__table_1gaa4c3c43c081bf789120e96683bc70cb3)`(const `[`SIPpointer`](#classSIPpointer)` & p,const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` {#group__table_1gaa4c3c43c081bf789120e96683bc70cb3}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga12c22407821e96d6c7d0bca88392cbda)`(const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` {#group__table_1ga12c22407821e96d6c7d0bca88392cbda}

instance as next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`SIPpointer`](#classSIPpointer)` & `[`operator=`](#group__table_1ga9855eef9600bbdd1e74343844e0c158c)`(const `[`SIPpointer`](#classSIPpointer)` &)` {#group__table_1ga9855eef9600bbdd1e74343844e0c158c}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1ga519f21be86b2ddb4fae2bab869434863)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1ga519f21be86b2ddb4fae2bab869434863}

for use as key in a unordered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator!=`](#group__table_1ga58f25245c42e16d11738e74c66a63cf6)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1ga58f25245c42e16d11738e74c66a63cf6}

#### `public virtual bool `[`operator<`](#group__table_1gaefff5ba3579bd6174700ab1462fa13fb)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1gaefff5ba3579bd6174700ab1462fa13fb}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1gad7e14d03ea63991d16a0da5292eda82d)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` {#group__table_1gad7e14d03ea63991d16a0da5292eda82d}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gae02f880deb0305e3122caf05f9d2bad0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` {#group__table_1gae02f880deb0305e3122caf05f9d2bad0}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`complete`](#group__table_1ga2f95b5a2058b20744a00737b1240bc83)`() const` {#group__table_1ga2f95b5a2058b20744a00737b1240bc83}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

the _pre value must be known 

_node must be set

#### `public virtual bool `[`compatible`](#group__table_1gabf87df773f8e0f628e0bae79e88097db)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` {#group__table_1gabf87df773f8e0f628e0bae79e88097db}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`dummy`](#group__table_1gaf830b0bf9d24b53e4674de49308b7853)`() const` {#group__table_1gaf830b0bf9d24b53e4674de49308b7853}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga01caac75d66ff2e272a248c7e1954415)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga01caac75d66ff2e272a248c7e1954415}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `s` input segment must not be NULL.

#### `public  `[`SKpointer`](#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5)`()` {#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5}

specific

#### `public  `[`SKpointer`](#group__table_1ga876c1101716f9aea625574f9be9b3da5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` {#group__table_1ga876c1101716f9aea625574f9be9b3da5}

specific

#### `public  `[`SKpointer`](#group__table_1ga022b6998c4273e2da8128ccd2205a7f6)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` {#group__table_1ga022b6998c4273e2da8128ccd2205a7f6}

top ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `bar` must be true TBR deprecated (replace by specific constructor)

#### `public  `[`SKpointer`](#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9)`(`[`Environment`](#classEnvironment)` *,const `[`SKpointer`](#classSKpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

no default duration for ambiguity reasons.

#### `public  `[`SKpointer`](#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3)`(const `[`SKpointer`](#classSKpointer)` &)` {#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3}

copy.

#### `public  `[`SKpointer`](#group__table_1gaf762b88808d2e8188b74e28256d3ed09)`(const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` {#group__table_1gaf762b88808d2e8188b74e28256d3ed09}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial

#### `public  `[`SKpointer`](#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9)`(const `[`SKpointer`](#classSKpointer)` & p,const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` {#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial

#### `public virtual `[`SKpointer`](#classSKpointer)` & `[`operator=`](#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1)`(const `[`SKpointer`](#classSKpointer)` &)` {#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1gab77c2fa945fcc938568ace9986c25324)`(const `[`SKpointer`](#classSKpointer)` &) const` {#group__table_1gab77c2fa945fcc938568ace9986c25324}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937)`(const `[`SKpointer`](#classSKpointer)` & p) const` {#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1ga38150ffb7a8bf25ebf5133907d568738)`(const `[`SKpointer`](#classSKpointer)` & p) const` {#group__table_1ga38150ffb7a8bf25ebf5133907d568738}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual void `[`incr`](#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a)`()` {#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a}

#### `public  `[`SKIPpointer`](#group__table_1ga24e762a60a81030599decff93dc1a1ef)`()` {#group__table_1ga24e762a60a81030599decff93dc1a1ef}

dummy ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SKIPpointer`](#group__table_1ga1fc4cd4038153502277d11c5607a14fa)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` {#group__table_1ga1fc4cd4038153502277d11c5607a14fa}

specific fake ptr for terminal run, contains only a label symbol. it is considered as complete

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SKIPpointer`](#group__table_1gab217454122f2ec0af5c16bb1ae996925)`(`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,bool bar,size_t k)` {#group__table_1gab217454122f2ec0af5c16bb1ae996925}

TBR deprecated.

#### `public  `[`SKIPpointer`](#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,size_t k)` {#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638}

class specific top ptr (covering the whole input segment.

env must contain an input segment and interval heap.

#### `public  `[`SKIPpointer`](#group__table_1ga6cd275122aebf4288f5d60c36a141116)`(`[`Environment`](#classEnvironment)` * env,const `[`SKIPpointer`](#classSKIPpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1ga6cd275122aebf4288f5d60c36a141116}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

no default duration for ambiguity reasons

#### `public  `[`SKIPpointer`](#group__table_1ga3366b26b81c9cb040716918f7d375879)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` {#group__table_1ga3366b26b81c9cb040716918f7d375879}

copy.

#### `public  `[`SKIPpointer`](#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d)`(const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` {#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial

#### `public  `[`SKIPpointer`](#group__table_1ga8b87b18aa76b4021da6d3421c738b002)`(const `[`SKIPpointer`](#classSKIPpointer)` & p,const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` {#group__table_1ga8b87b18aa76b4021da6d3421c738b002}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial

#### `public virtual `[`SKIPpointer`](#classSKIPpointer)` & `[`operator=`](#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` {#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4)`(const `[`SKIPpointer`](#classSKIPpointer)` &) const` {#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` {#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gaacf829ba5696414bdcc753e97e76a7f1)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` {#group__table_1gaacf829ba5696414bdcc753e97e76a7f1}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual void `[`incr`](#group__table_1gac0c72ab0a91e652b38eb815206b0baa4)`()` {#group__table_1gac0c72ab0a91e652b38eb815206b0baa4}

# class `Parser` {#classParser}

```
class Parser
  : public Environment
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`WTA`](#classWTA)` * `[`wta`](#classParser_1a1d6da7c9962be0987caf9bf69f634ea6) | 
`public `[`Environment`](#classEnvironment)` * `[`input`](#classParser_1a5ab3cb7f02f7bb33dd59f3edbf63675a) | 
`public  `[`Parser`](#classParser_1a7e5b1a5452fb9eb39040d10adec713bb)`(`[`WTA`](#classWTA)` * a,`[`InputSegment`](#classInputSegment)` * s)` | 
`public  `[`~Parser`](#classParser_1a09fc36d1fcc326ea5104a0e8fbab65c5)`()` | 
`public size_t `[`resolution`](#classParser_1a0f3f9620883bb10e9ecd07cec155b1a3)`()` | 
`public size_t `[`addRuns`](#classParser_1a1036f9fa453e662cb87c882978af0f9f)`(`[`Atable`](#classAtable)`< P > *,const P &,`[`Record`](#classRecord)`< P > *)` | 
`public virtual void `[`printobest`](#classParser_1a36e89e4e76b8ba144b764cf07d02ca75)`(std::ostream & o,`[`Atable`](#classAtable)`< P > * table,const P &) const` | 
`public virtual void `[`printobestRun`](#classParser_1ae0a82cabf61977d6a0f0bc618c64e6c8)`(std::ostream & o,`[`Atable`](#classAtable)`< P > * table,`[`Run`](#classRun)`< P > * r) const` | 
`protected size_t `[`_res`](api-table.md#classParser_1a82a307f632a1988fe229f989bbc4584d) | 
`protected virtual size_t `[`addWTARuns`](#classParser_1a00a7b213fe0e4f8cce4e780adbbbd110)`(`[`Atable`](#classAtable)`< P > *,const P &,`[`Record`](#classRecord)`< P > *)` | 

## Members

#### `public `[`WTA`](#classWTA)` * `[`wta`](#classParser_1a1d6da7c9962be0987caf9bf69f634ea6) {#classParser_1a1d6da7c9962be0987caf9bf69f634ea6}

#### `public `[`Environment`](#classEnvironment)` * `[`input`](#classParser_1a5ab3cb7f02f7bb33dd59f3edbf63675a) {#classParser_1a5ab3cb7f02f7bb33dd59f3edbf63675a}

#### `public  `[`Parser`](#classParser_1a7e5b1a5452fb9eb39040d10adec713bb)`(`[`WTA`](#classWTA)` * a,`[`InputSegment`](#classInputSegment)` * s)` {#classParser_1a7e5b1a5452fb9eb39040d10adec713bb}

#### `public  `[`~Parser`](#classParser_1a09fc36d1fcc326ea5104a0e8fbab65c5)`()` {#classParser_1a09fc36d1fcc326ea5104a0e8fbab65c5}

#### `public size_t `[`resolution`](#classParser_1a0f3f9620883bb10e9ecd07cec155b1a3)`()` {#classParser_1a0f3f9620883bb10e9ecd07cec155b1a3}

#### `public size_t `[`addRuns`](#classParser_1a1036f9fa453e662cb87c882978af0f9f)`(`[`Atable`](#classAtable)`< P > *,const P &,`[`Record`](#classRecord)`< P > *)` {#classParser_1a1036f9fa453e662cb87c882978af0f9f}

#### `public virtual void `[`printobest`](#classParser_1a36e89e4e76b8ba144b764cf07d02ca75)`(std::ostream & o,`[`Atable`](#classAtable)`< P > * table,const P &) const` {#classParser_1a36e89e4e76b8ba144b764cf07d02ca75}

#### `public virtual void `[`printobestRun`](#classParser_1ae0a82cabf61977d6a0f0bc618c64e6c8)`(std::ostream & o,`[`Atable`](#classAtable)`< P > * table,`[`Run`](#classRun)`< P > * r) const` {#classParser_1ae0a82cabf61977d6a0f0bc618c64e6c8}

#### `protected size_t `[`_res`](api-table.md#classParser_1a82a307f632a1988fe229f989bbc4584d) {#classParser_1a82a307f632a1988fe229f989bbc4584d}

#### `protected virtual size_t `[`addWTARuns`](#classParser_1a00a7b213fe0e4f8cce4e780adbbbd110)`(`[`Atable`](#classAtable)`< P > *,const P &,`[`Record`](#classRecord)`< P > *)` {#classParser_1a00a7b213fe0e4f8cce4e780adbbbd110}

# class `Atable` {#classAtable}

abstract interface to parse table

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Parser`](#classParser)`< P > * `[`parent`](#classAtable_1a43c761e5718010983659d7162f89d8d3) | parsing environment.
`public  `[`Atable`](#classAtable_1ad519343a13265a31ba1d0951be0e3185)`(`[`Parser`](#classParser)`< P > * env,RunCompare< P > comp)` | #### Parameters
`public  `[`~Atable`](#classAtable_1a535587360990ee5a9351501739585f13)`()` | 
`public `[`Run`](#classRun)`< P > * `[`best`](#classAtable_1a60515b93afede66f01a0e89edb563800)`(const P & p)` | return k-best run pointed by p or NULL if there is none. k is either included in p or the default value 1.
`public `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classAtable_1af3a86206727f9d28cd3e962f709b9bc2)`(const P & p)` | tree corresponding to the k-best run in p.
`public `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classAtable_1a48dfc1adb76a6d50824f28df2f8cd692)`(`[`Run`](#classRun)`< P > * p)` | when the k-best run in p is already computed.
`public size_t `[`add`](#classAtable_1ab644eecedb520d67da426f9170a6213b)`(const P & p,`[`Run`](#classRun)`< P > * r,`[`Record`](#classRecord)`< P > * i)` | add possible instances of run r to the entries in table for corresp. to possible instances for p. dispatch to the four functions below according to p and r.
`public size_t `[`nb_entries`](#classAtable_1a90e01b017faeec6869df32bd50ce5b35)`()` | 
`public size_t `[`nb_runs`](#classAtable_1a66029b49ab5cece68c4a0635a821b877)`()` | 
`protected RunCompare< P > `[`_comparer`](api-table.md#classAtable_1a84214b2c984a18a8cec13313152d3eaa) | 

## Members

#### `public `[`Parser`](#classParser)`< P > * `[`parent`](#classAtable_1a43c761e5718010983659d7162f89d8d3) {#classAtable_1a43c761e5718010983659d7162f89d8d3}

parsing environment.

#### `public  `[`Atable`](#classAtable_1ad519343a13265a31ba1d0951be0e3185)`(`[`Parser`](#classParser)`< P > * env,RunCompare< P > comp)` {#classAtable_1ad519343a13265a31ba1d0951be0e3185}

#### Parameters
* `env` environment must not be null.

#### `public  `[`~Atable`](#classAtable_1a535587360990ee5a9351501739585f13)`()` {#classAtable_1a535587360990ee5a9351501739585f13}

#### `public `[`Run`](#classRun)`< P > * `[`best`](#classAtable_1a60515b93afede66f01a0e89edb563800)`(const P & p)` {#classAtable_1a60515b93afede66f01a0e89edb563800}

return k-best run pointed by p or NULL if there is none. k is either included in p or the default value 1.

#### Parameters
* `p` must be complete.

#### `public `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classAtable_1af3a86206727f9d28cd3e962f709b9bc2)`(const P & p)` {#classAtable_1af3a86206727f9d28cd3e962f709b9bc2}

tree corresponding to the k-best run in p.

#### `public `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classAtable_1a48dfc1adb76a6d50824f28df2f8cd692)`(`[`Run`](#classRun)`< P > * p)` {#classAtable_1a48dfc1adb76a6d50824f28df2f8cd692}

when the k-best run in p is already computed.

#### Parameters
* `p` not used TBR 

the run must be wta.

#### `public size_t `[`add`](#classAtable_1ab644eecedb520d67da426f9170a6213b)`(const P & p,`[`Run`](#classRun)`< P > * r,`[`Record`](#classRecord)`< P > * i)` {#classAtable_1ab644eecedb520d67da426f9170a6213b}

add possible instances of run r to the entries in table for corresp. to possible instances for p. dispatch to the four functions below according to p and r.

#### Parameters
* `p` can be complete or partial. 

* `r` can be complete or partial. 

* `i` if p is complete, then i must be an iterator to the entry for p in table, otherwise (p partial), i is table.end().

#### `public size_t `[`nb_entries`](#classAtable_1a90e01b017faeec6869df32bd50ce5b35)`()` {#classAtable_1a90e01b017faeec6869df32bd50ce5b35}

#### `public size_t `[`nb_runs`](#classAtable_1a66029b49ab5cece68c4a0635a821b877)`()` {#classAtable_1a66029b49ab5cece68c4a0635a821b877}

#### `protected RunCompare< P > `[`_comparer`](api-table.md#classAtable_1a84214b2c984a18a8cec13313152d3eaa) {#classAtable_1a84214b2c984a18a8cec13313152d3eaa}

# class `Brecord` {#classBrecord}

```
class Brecord
  : public Record< P >
```  

record associated to Ptr for one-best procedures.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Brecord`](#classBrecord_1ace582d212928967716927ff6fe20c647)`(const P &,RunCompare< P >)` | 
`public  `[`~Brecord`](#classBrecord_1a30314b5f13445c9f8d9e027caa498c55)`()` | 
`public virtual void `[`add`](#classBrecord_1ac7ec5cf75624a8a05fced677a477d07b)`(`[`Run`](#classRun)`< P > *)` | add a run to the record.
`public virtual `[`Run`](#classRun)`< P > * `[`best`](#classBrecord_1a3e9776d16cdc2fd5c169d5599caf7c4b)`(`[`Atable`](#classAtable)`< P > * parent,size_t k)` | returns the k-th best run of the record
`public virtual bool `[`empty`](#classBrecord_1ad90c15ea15523176e1db7e6e876e8ea9)`() const` | 
`protected `[`Run`](#classRun)`< P > * `[`_best`](#classBrecord_1a88d1eeb254c1814f72f99a28bea5e7d6) | best run for the associated state.

## Members

#### `public  `[`Brecord`](#classBrecord_1ace582d212928967716927ff6fe20c647)`(const P &,RunCompare< P >)` {#classBrecord_1ace582d212928967716927ff6fe20c647}

#### `public  `[`~Brecord`](#classBrecord_1a30314b5f13445c9f8d9e027caa498c55)`()` {#classBrecord_1a30314b5f13445c9f8d9e027caa498c55}

#### `public virtual void `[`add`](#classBrecord_1ac7ec5cf75624a8a05fced677a477d07b)`(`[`Run`](#classRun)`< P > *)` {#classBrecord_1ac7ec5cf75624a8a05fced677a477d07b}

add a run to the record.

#### `public virtual `[`Run`](#classRun)`< P > * `[`best`](#classBrecord_1a3e9776d16cdc2fd5c169d5599caf7c4b)`(`[`Atable`](#classAtable)`< P > * parent,size_t k)` {#classBrecord_1a3e9776d16cdc2fd5c169d5599caf7c4b}

returns the k-th best run of the record

#### Parameters
* `parent` is ignored 

* `k` rank (as in k-best)

#### `public virtual bool `[`empty`](#classBrecord_1ad90c15ea15523176e1db7e6e876e8ea9)`() const` {#classBrecord_1ad90c15ea15523176e1db7e6e876e8ea9}

#### `protected `[`Run`](#classRun)`< P > * `[`_best`](#classBrecord_1a88d1eeb254c1814f72f99a28bea5e7d6) {#classBrecord_1a88d1eeb254c1814f72f99a28bea5e7d6}

best run for the associated state.

# class `Krecord` {#classKrecord}

```
class Krecord
  : public Record< P >
```  

record associated to Ptr for k-best procedures.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Krecord`](#classKrecord_1af92867687943d0f45b4f27d925127393)`(const P &,RunCompare< P >)` | 
`public  `[`~Krecord`](#classKrecord_1a9cdd2100c1da156d0bc52b4055c02e03)`()` | 
`public virtual void `[`add`](#classKrecord_1a7f19d5761c5dd197b845bdd8a2d3bd2a)`(`[`Run`](#classRun)`< P > *)` | add a run to the record.
`public virtual `[`Run`](#classRun)`< P > * `[`best`](#classKrecord_1a3969af28b4979e3647c149e9f35f21b7)`(`[`Atable`](#classAtable)`< P > * table,size_t k)` | returns the k-th best run of the record. Fill the list of best runs up to (at most) k if necessary. If less than k best can be constructed (table is complete), return an null run (weight unknown), otherwise, the weight of the returned run is known.
`public virtual bool `[`empty`](#classKrecord_1a2f4146eec2a91b889e1118a30af978ca)`() const` | 
`protected std::priority_queue< `[`Run](#classRun)< P > *, std::vector< [Run`](#classRun)`< P > * >, RunCompare< P > > `[`_cand`](#classKrecord_1a4bd6f869776d942976f6469aebc64f10) | heap of candidate runs for the associated state. it is empty iff no more k-best can be added
`protected std::vector< `[`Run`](#classRun)`< P > * > `[`_best`](#classKrecord_1a2974d287d3c849f4c9f5b03f51e7159c) | ordered list of best runs for the associated state.
`protected virtual void `[`addCand`](#classKrecord_1ae88ed30977296575c7b60eab0138bbb1)`(`[`Run`](#classRun)`< P > * r)` | add [Run](api-table.md#classRun) r to the heap of candidates after some filtering based on optimisation flags.
`protected virtual void `[`addBest`](#classKrecord_1a101fe075076b9aecb97014a04e023c26)`(`[`Run`](#classRun)`< P > * r)` | add [Run](api-table.md#classRun) r at the end of the list of best runs. record the given run r as one of the best runs of the record.
`protected bool `[`bestFilter`](#classKrecord_1a66b55817885fd985264ca90dbb3dc7ae)`(const `[`Run`](#classRun)`< P > * r)` | 
`protected void `[`addNext`](#classKrecord_1a1cee958825882ef5c782382770688bbe)`(`[`Run`](#classRun)`< P > * r)` | add the candidates following [Run](#classRun) r (lexico order for ranks) to the heap of candidates.

## Members

#### `public  `[`Krecord`](#classKrecord_1af92867687943d0f45b4f27d925127393)`(const P &,RunCompare< P >)` {#classKrecord_1af92867687943d0f45b4f27d925127393}

#### `public  `[`~Krecord`](#classKrecord_1a9cdd2100c1da156d0bc52b4055c02e03)`()` {#classKrecord_1a9cdd2100c1da156d0bc52b4055c02e03}

#### `public virtual void `[`add`](#classKrecord_1a7f19d5761c5dd197b845bdd8a2d3bd2a)`(`[`Run`](#classRun)`< P > *)` {#classKrecord_1a7f19d5761c5dd197b845bdd8a2d3bd2a}

add a run to the record.

#### `public virtual `[`Run`](#classRun)`< P > * `[`best`](#classKrecord_1a3969af28b4979e3647c149e9f35f21b7)`(`[`Atable`](#classAtable)`< P > * table,size_t k)` {#classKrecord_1a3969af28b4979e3647c149e9f35f21b7}

returns the k-th best run of the record. Fill the list of best runs up to (at most) k if necessary. If less than k best can be constructed (table is complete), return an null run (weight unknown), otherwise, the weight of the returned run is known.

#### `public virtual bool `[`empty`](#classKrecord_1a2f4146eec2a91b889e1118a30af978ca)`() const` {#classKrecord_1a2f4146eec2a91b889e1118a30af978ca}

#### `protected std::priority_queue< `[`Run](#classRun)< P > *, std::vector< [Run`](#classRun)`< P > * >, RunCompare< P > > `[`_cand`](#classKrecord_1a4bd6f869776d942976f6469aebc64f10) {#classKrecord_1a4bd6f869776d942976f6469aebc64f10}

heap of candidate runs for the associated state. it is empty iff no more k-best can be added

#### `protected std::vector< `[`Run`](#classRun)`< P > * > `[`_best`](#classKrecord_1a2974d287d3c849f4c9f5b03f51e7159c) {#classKrecord_1a2974d287d3c849f4c9f5b03f51e7159c}

ordered list of best runs for the associated state.

#### `protected virtual void `[`addCand`](#classKrecord_1ae88ed30977296575c7b60eab0138bbb1)`(`[`Run`](#classRun)`< P > * r)` {#classKrecord_1ae88ed30977296575c7b60eab0138bbb1}

add [Run](#classRun) r to the heap of candidates after some filtering based on optimisation flags.

#### Parameters
* `r` given [Run](#classRun) can be complete or partial (weight not fully evaluated)

#### `protected virtual void `[`addBest`](#classKrecord_1a101fe075076b9aecb97014a04e023c26)`(`[`Run`](#classRun)`< P > * r)` {#classKrecord_1a101fe075076b9aecb97014a04e023c26}

add [Run](#classRun) r at the end of the list of best runs. record the given run r as one of the best runs of the record.

#### Parameters
* `r` must be complete (weight fully evaluated).

#### `protected bool `[`bestFilter`](#classKrecord_1a66b55817885fd985264ca90dbb3dc7ae)`(const `[`Run`](#classRun)`< P > * r)` {#classKrecord_1a66b55817885fd985264ca90dbb3dc7ae}

#### `protected void `[`addNext`](#classKrecord_1a1cee958825882ef5c782382770688bbe)`(`[`Run`](#classRun)`< P > * r)` {#classKrecord_1a1cee958825882ef5c782382770688bbe}

add the candidates following [Run](#classRun) r (lexico order for ranks) to the heap of candidates.

#### Parameters
* `r` must be complete (weight fully evaluated). the nexts [Run](#classRun) (new candidates) will be partial

# class `Pointer` {#classPointer}

abstract class defining a signature for a class of pointer to best runs.

## constructors

Every concrete subclass P (descendant) must implement the following generic constructors and class-specific operators. they are called by the templates [Table](#classTable) and [Run](#classRun). Some use the encapsulator [Environment](#classEnvironment).

```cpp
P()
```
 dummy ptr (unique - can not be produced by other constructors).

```cpp
P(label_t s)
```
 fake ptr containing only a label symbol to act as (singleton) body of a terminal runs. the label symbol is concrete (see [Label.hpp](#Label_8hpp_source)). also used for P(state_t) -> confusion types state_t & label_t

```cpp
P(Environment* env, const &P p, size_t a, size_t i, state_t s)
```
 sub-pointer or instance as leaf s must be a wta state (e.g. initial state of wta) there are 2 cases according to a:* if a = 0 : construct a copy of p instanciated as a leaf with label s. i must be 0, p must be partial p must be compatible with s (s = leaf symbol in this case).

* if a > 0 i must be in [0..a] p must be divisible p can have a meta state (meta run with a=2) or a wta state with i=0, construct the head of a run (in general a copy of p but not always) with 0 < i <= a, construct a pointer for the ith children of a run. the details and specific pre-conditions are described in every class P.

```cpp
P(const &P p)
```
 copy

```cpp
P(const &P p, const &P p0, const &P p1)
```
 instance as parent p must be partial p0 must be complete p1 must be complete Construct a copy of p instanciated as an target node of run with p0 as first child and p1 as last child.

```cpp
P(const &P p0, const &P p1)
```
 instance as next sibling p0 must be complete p1 must be partial p1 must be instanciable into a successor sibling of p0. Construct a copy of p1 instanciated as the next sibling of p0.

```cpp
virtual P& operator= (const P& p) = 0;
```

```cpp
virtual bool operator==(const P& p) const;
```
 for using pointer as key in hash table (unordered multimap)

```cpp
virtual bool operator<(const P& p) const;
```
 for using pointer as key in search tree (multimap)

```cpp
bool instance(const P& p)
```
 return wether this ptr is an instance of p. if p is complete, then it is equality.

```cpp
bool subsume(const P& p)
```
 inverse of instance return wether p is an instance of this ptr. if this ptr is complete, then it is equality.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual bool `[`has_S`](#classPointer_1a2a45530c7efca1b398d90a773fdb3c70)`() const` | 
`public inline virtual bool `[`has_K`](#classPointer_1a66999c2d23c4b592228f1e74a96e0315)`() const` | 
`public inline virtual bool `[`has_I`](#classPointer_1a7018d6fde0393288fbd7ed5c1ffe9e5b)`() const` | 
`public inline virtual bool `[`has_P`](#classPointer_1a96063327a69b47d288f345b0d2f4b42b)`() const` | 
`public bool `[`complete`](#classPointer_1a3fa3fb5df21abf35c02c321611d85a3c)`() const` | the pointer is complete i.e. all fields are set
`public inline bool `[`partial`](#classPointer_1aa682c210e4ae3ef7268db1ee5bcf9f9d)`() const` | 
`public inline virtual size_t `[`rank`](#classPointer_1a8ded051c871b7fccfb6b2a20b8920cab)`() const` | return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.
`public inline virtual bool `[`divisible`](#classPointer_1a51529c3e4714cafc28ba07da36078618)`() const` | return wether it is worth descending (dividing) from this pointer. the result may differ according to whether this pointer has a [WTA](api-schemata.md#classWTA) state or a Meta state. For instance:
`public inline virtual void `[`incr`](#classPointer_1a02c73f5f2b21a1fe37b744383508cb64)`()` | 
`public inline virtual bool `[`compatible`](#classPointer_1a7b636072b492b57efe3ead47e03a67bd)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` | return wether this pointer is compatible with the given label.
`public bool `[`dummy`](#classPointer_1afa7a38cfee7181aa05e3634a15066135)`() const` | return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#classPointer_1a767e1ca8f18a9cf07eaca5ae44f689cf)`(const `[`Transition`](#classTransition)` & t) const` | return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga4ca596fe52abd36d550a10818678d54c)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` | return the weight for a terminal [Run](#classRun) associated to the given [Transition](#classTransition). The transition must be terminal. This pointer must be compatible with the [Transition](#classTransition). input segment can be NULL.
`public virtual `[`Weight`](#classWeight)` `[`innerWeight`](#group__table_1gad709430d698804267807f12deba9952b)`(const `[`Transition`](#classTransition)` &) const` | return the initial weight for an inner [Run](#classRun) associated to the given [Transition](#classTransition). the weight will have to be multiplied with all the weights of subruns. the transition must be inner. this pointer must be divisible.

## Members

#### `public inline virtual bool `[`has_S`](#classPointer_1a2a45530c7efca1b398d90a773fdb3c70)`() const` {#classPointer_1a2a45530c7efca1b398d90a773fdb3c70}

#### `public inline virtual bool `[`has_K`](#classPointer_1a66999c2d23c4b592228f1e74a96e0315)`() const` {#classPointer_1a66999c2d23c4b592228f1e74a96e0315}

#### `public inline virtual bool `[`has_I`](#classPointer_1a7018d6fde0393288fbd7ed5c1ffe9e5b)`() const` {#classPointer_1a7018d6fde0393288fbd7ed5c1ffe9e5b}

#### `public inline virtual bool `[`has_P`](#classPointer_1a96063327a69b47d288f345b0d2f4b42b)`() const` {#classPointer_1a96063327a69b47d288f345b0d2f4b42b}

#### `public bool `[`complete`](#classPointer_1a3fa3fb5df21abf35c02c321611d85a3c)`() const` {#classPointer_1a3fa3fb5df21abf35c02c321611d85a3c}

the pointer is complete i.e. all fields are set

#### `public inline bool `[`partial`](#classPointer_1aa682c210e4ae3ef7268db1ee5bcf9f9d)`() const` {#classPointer_1aa682c210e4ae3ef7268db1ee5bcf9f9d}

#### `public inline virtual size_t `[`rank`](#classPointer_1a8ded051c871b7fccfb6b2a20b8920cab)`() const` {#classPointer_1a8ded051c871b7fccfb6b2a20b8920cab}

return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.

#### `public inline virtual bool `[`divisible`](#classPointer_1a51529c3e4714cafc28ba07da36078618)`() const` {#classPointer_1a51529c3e4714cafc28ba07da36078618}

return wether it is worth descending (dividing) from this pointer. the result may differ according to whether this pointer has a [WTA](#classWTA) state or a Meta state. For instance:

* for [WTA](#classWTA) state: it is not worth when this pointer corresponds to an input sub-segment not inhabited.

* for Meta state: it is not worth if this ptr corresponds to an empty segment. default true.

#### `public inline virtual void `[`incr`](#classPointer_1a02c73f5f2b21a1fe37b744383508cb64)`()` {#classPointer_1a02c73f5f2b21a1fe37b744383508cb64}

#### `public inline virtual bool `[`compatible`](#classPointer_1a7b636072b492b57efe3ead47e03a67bd)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` {#classPointer_1a7b636072b492b57efe3ead47e03a67bd}

return wether this pointer is compatible with the given label.

#### Parameters
* `abstract` if flag is true (default), the label is supposed abstract (label of terminal transition). if abstract flag is false, the label is supposed concrete. 

**See also**: [Label.hpp](#Label_8hpp_source) for def. abstract/concrete labels 

#### Returns
default return true.

#### `public bool `[`dummy`](#classPointer_1afa7a38cfee7181aa05e3634a15066135)`() const` {#classPointer_1afa7a38cfee7181aa05e3634a15066135}

return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#classPointer_1a767e1ca8f18a9cf07eaca5ae44f689cf)`(const `[`Transition`](#classTransition)` & t) const` {#classPointer_1a767e1ca8f18a9cf07eaca5ae44f689cf}

return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga4ca596fe52abd36d550a10818678d54c)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` {#group__table_1ga4ca596fe52abd36d550a10818678d54c}

return the weight for a terminal [Run](#classRun) associated to the given [Transition](#classTransition). The transition must be terminal. This pointer must be compatible with the [Transition](#classTransition). input segment can be NULL.

#### `public virtual `[`Weight`](#classWeight)` `[`innerWeight`](#group__table_1gad709430d698804267807f12deba9952b)`(const `[`Transition`](#classTransition)` &) const` {#group__table_1gad709430d698804267807f12deba9952b}

return the initial weight for an inner [Run](#classRun) associated to the given [Transition](#classTransition). the weight will have to be multiplied with all the weights of subruns. the transition must be inner. this pointer must be divisible.

# class `Spointer` {#classSpointer}

```
class Spointer
  : public Pointer
```  

key in a parse table.

pointer to a (best) run for 1-best parsing for standard [WTA](#classWTA).

a [Spointer](#classSpointer) contains

* a state symbol: either

* a [WTA](#classWTA) state or

* a leaf label or

* a meta state

that defines two kind of pointers

* state pointer : points to a state of a [WTA](#classWTA)

* bar pointer : points to a solution for the n first bars in an input segment = a sequence of n solutions pointing to the initial state of [WTA](#classWTA).

all Spointers are complete

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Spointer`](#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4)`()` | specific
`public  `[`Spointer`](#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` | specific
`public  `[`Spointer`](#group__table_1ga49f82b7aafd3ae237243c85272597fa7)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` | top ptr (head of the main [Run](#classRun)).
`public  `[`Spointer`](#group__table_1ga72441f0d67497c90602a123c45dc53d1)`(`[`Environment`](#classEnvironment)` * env,const `[`Spointer`](#classSpointer)` & p,size_t a,size_t i,state_t s)` | sub-pointer or instance as leaf.
`public  `[`Spointer`](#group__table_1gaf40e1a1f0edc608d4413f096a19aae78)`(const `[`Spointer`](#classSpointer)` &)` | copy.
`public  `[`Spointer`](#group__table_1gac303715911a48c482acb6ae4188508d3)`(const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` | next sibling.
`public  `[`Spointer`](#group__table_1gad078973f8318ccf5800db79e87584dcc)`(const `[`Spointer`](#classSpointer)` & p,const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` | instance as parent.
`public virtual `[`Spointer`](#classSpointer)` & `[`operator=`](#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb)`(const `[`Spointer`](#classSpointer)` &)` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772)`(const `[`Spointer`](#classSpointer)` &) const` | for use as key in a unorered_multimap.
`public virtual bool `[`operator<`](#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8)`(const `[`Spointer`](#classSpointer)` &) const` | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b)`(const `[`Spointer`](#classSpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1ga06fa67855bfb50d81e18bdfacce965ce)`(const `[`Spointer`](#classSpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public inline virtual bool `[`has_S`](#classSpointer_1aec852b63ae9427911ff290979bc0a4b4)`() const` | 
`public inline state_t `[`state`](#classSpointer_1a8fa50c04246ceb3a48e961946a2427f7)`() const` | 
`public virtual bool `[`complete`](#group__table_1gace5bd2026fef480084f3cc5dc28086f3)`() const` | the pointer is complete i.e. all fields are set
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga15067ad809b5ac25b45c0187550e0b17)`(const `[`Transition`](#classTransition)` & t) const` | return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.
`public virtual bool `[`dummy`](#group__table_1ga0a994ec6827ef23556b500382fc5a1fc)`() const` | return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.
`public virtual bool `[`divisible`](#group__table_1ga54817fbae1688dab4dfff5724e762640)`() const` | this pointer must have a [WTA](api-schemata.md#classWTA) state always return true in that case
`protected state_t `[`_state`](api-table.md#classSpointer_1a27f37ac70c70f90d9a4a576606bb52e1) | 

## Members

#### `public  `[`Spointer`](#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4)`()` {#group__table_1ga467ee6f93cd0429edb40fc4de100c3c4}

specific

#### `public  `[`Spointer`](#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1gaad8a647a58df31aefd8f2703b9f86dc5}

specific

#### `public  `[`Spointer`](#group__table_1ga49f82b7aafd3ae237243c85272597fa7)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` {#group__table_1ga49f82b7aafd3ae237243c85272597fa7}

top ptr (head of the main [Run](#classRun)).

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `bar` must be true 

* `k` must be 1 

TBR deprecated (replace by specific constructor)

#### `public  `[`Spointer`](#group__table_1ga72441f0d67497c90602a123c45dc53d1)`(`[`Environment`](#classEnvironment)` * env,const `[`Spointer`](#classSpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1ga72441f0d67497c90602a123c45dc53d1}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `p` must have a wta state 

* `a` 

* `i` if a>0 and i=0, construct a copy of p. if a>0 and 0<i<=a, construct a copy a ptr with state s.

#### `public  `[`Spointer`](#group__table_1gaf40e1a1f0edc608d4413f096a19aae78)`(const `[`Spointer`](#classSpointer)` &)` {#group__table_1gaf40e1a1f0edc608d4413f096a19aae78}

copy.

#### `public  `[`Spointer`](#group__table_1gac303715911a48c482acb6ae4188508d3)`(const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` {#group__table_1gac303715911a48c482acb6ae4188508d3}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial.

#### `public  `[`Spointer`](#group__table_1gad078973f8318ccf5800db79e87584dcc)`(const `[`Spointer`](#classSpointer)` & p,const `[`Spointer`](#classSpointer)` & p0,const `[`Spointer`](#classSpointer)` & p1)` {#group__table_1gad078973f8318ccf5800db79e87584dcc}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial.

#### `public virtual `[`Spointer`](#classSpointer)` & `[`operator=`](#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb)`(const `[`Spointer`](#classSpointer)` &)` {#group__table_1ga88eb3c521aa1c9bc9b8891f20b9a01eb}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772)`(const `[`Spointer`](#classSpointer)` &) const` {#group__table_1gacb9d4d8e3da8a1e082b80fd31abb9772}

for use as key in a unorered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator<`](#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8)`(const `[`Spointer`](#classSpointer)` &) const` {#group__table_1ga797b376c9ed1b4777ea94ff8350c65c8}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b)`(const `[`Spointer`](#classSpointer)` & p) const` {#group__table_1ga718cc6f7473c3fb1b074211bf2f16d8b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1ga06fa67855bfb50d81e18bdfacce965ce)`(const `[`Spointer`](#classSpointer)` & p) const` {#group__table_1ga06fa67855bfb50d81e18bdfacce965ce}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public inline virtual bool `[`has_S`](#classSpointer_1aec852b63ae9427911ff290979bc0a4b4)`() const` {#classSpointer_1aec852b63ae9427911ff290979bc0a4b4}

#### `public inline state_t `[`state`](#classSpointer_1a8fa50c04246ceb3a48e961946a2427f7)`() const` {#classSpointer_1a8fa50c04246ceb3a48e961946a2427f7}

#### `public virtual bool `[`complete`](#group__table_1gace5bd2026fef480084f3cc5dc28086f3)`() const` {#group__table_1gace5bd2026fef480084f3cc5dc28086f3}

the pointer is complete i.e. all fields are set

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga15067ad809b5ac25b45c0187550e0b17)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga15067ad809b5ac25b45c0187550e0b17}

return a concrete label value corresponding to this pointer when considered as a leaf position, using the label of the given transition. the given transition must be terminal.

#### `public virtual bool `[`dummy`](#group__table_1ga0a994ec6827ef23556b500382fc5a1fc)`() const` {#group__table_1ga0a994ec6827ef23556b500382fc5a1fc}

return whether this pointer is a dummy pointer i.e. it was constructed with P() default false.

#### `public virtual bool `[`divisible`](#group__table_1ga54817fbae1688dab4dfff5724e762640)`() const` {#group__table_1ga54817fbae1688dab4dfff5724e762640}

this pointer must have a [WTA](#classWTA) state always return true in that case

#### `protected state_t `[`_state`](api-table.md#classSpointer_1a27f37ac70c70f90d9a4a576606bb52e1) {#classSpointer_1a27f37ac70c70f90d9a4a576606bb52e1}

# class `SIpointer` {#classSIpointer}

```
class SIpointer
  : public Spointer
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`SIpointer`](#group__table_1ga7e962d8567566398e5f620ef964267cd)`()` | dummy ptr
`public  `[`SIpointer`](#group__table_1ga464163b749ecd94516ab6e94f7baa5bf)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` | fake ptr for terminal run, contains only a label symbol it is considered as complete see description in [Ptr.hpp](#Ptr_8hpp_source)
`public  `[`SIpointer`](#group__table_1gac560506e7bf1439877178cf6d2459e7f)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`Rational`](#classRational)` mdur,double rext)` | class specific top ptr (covering the whole input segment + given extension in realtime, of given musical duration.
`public  `[`SIpointer`](#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` | split ptr p in 2 parts.
`public  `[`SIpointer`](#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,size_t a,size_t i,state_t s)` | sub-pointer or instance as leaf.
`public  `[`SIpointer`](#group__table_1ga3df3168789d247e497f127caa7840e88)`(const `[`SIpointer`](#classSIpointer)` &)` | copy.
`public  `[`SIpointer`](#group__table_1ga175406f6e30433d90a004aa27c401f29)`(const `[`SIpointer`](#classSIpointer)` & p,const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` | instance as parent.
`public  `[`SIpointer`](#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e)`(const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` | instance as next sibling.
`public virtual `[`SIpointer`](#classSIpointer)` & `[`operator=`](#group__table_1ga071bb69977a62e26f9ec11230ae2646b)`(const `[`SIpointer`](#classSIpointer)` &)` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1ga3330f8e59b08797b4c73ae558f6d588e)`(const `[`SIpointer`](#classSIpointer)` &) const` | for use as key in a unordered_multimap.
`public virtual bool `[`operator!=`](#group__table_1ga303c4da57a70fa07b7a2de3692fc9091)`(const `[`SIpointer`](#classSIpointer)` &) const` | 
`public virtual bool `[`operator<`](#group__table_1ga51c64ecf271622a259840f55236778ef)`(const `[`SIpointer`](#classSIpointer)` &) const` | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1ga259b23462f7e87f6df0e9361c1884618)`(const `[`SIpointer`](#classSIpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f)`(const `[`SIpointer`](#classSIpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public inline virtual bool `[`has_I`](#classSIpointer_1a4cb39a0c156f3b09eb15feb12dad2434)`() const` | 
`public inline virtual bool `[`has_P`](#classSIpointer_1a433d1c2fbb2e79b7f0ada6b424739bec)`() const` | 
`public inline `[`IntervalTree`](#classIntervalTree)` * `[`interval`](#classSIpointer_1a1471edc06d0a40b154cb1b643b9f28f7)`() const` | 
`public virtual bool `[`complete`](#group__table_1ga638627bc96caa0f1dbf7093f0f70951b)`() const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga6bdbea8e7013194f834be17932efe642)`(const `[`Transition`](#classTransition)` & t) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source) the _pre value must be known _node must be set
`public virtual bool `[`divisible`](#group__table_1gac83e0619c17ce4efd589f73513706a6b)`() const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`compatible`](#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`dummy`](#group__table_1ga555753e41af94ac201a0c8c99babb83b)`() const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`protected `[`IntervalTree`](#classIntervalTree)` * `[`_node`](#classSIpointer_1ad623e07df03b58eced4ceaf0855f5993) | 
`protected bool `[`equal_node`](#group__table_1gacc34f81b5d73c93840bce279ddde4620)`(const `[`SIpointer`](#classSIpointer)` &) const` | 

## Members

#### `public  `[`SIpointer`](#group__table_1ga7e962d8567566398e5f620ef964267cd)`()` {#group__table_1ga7e962d8567566398e5f620ef964267cd}

dummy ptr

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga464163b749ecd94516ab6e94f7baa5bf)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1ga464163b749ecd94516ab6e94f7baa5bf}

fake ptr for terminal run, contains only a label symbol it is considered as complete see description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1gac560506e7bf1439877178cf6d2459e7f)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`Rational`](#classRational)` mdur,double rext)` {#group__table_1gac560506e7bf1439877178cf6d2459e7f}

class specific top ptr (covering the whole input segment + given extension in realtime, of given musical duration.

#### Parameters
* `env` must contain an input segment and interval heap.

#### `public  `[`SIpointer`](#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` {#group__table_1ga3abe73f8e3188ca49f11e09d794f1f05}

split ptr p in 2 parts.

if position = 0, first part has (real-time/musical-time) durations rdur/mdur

if position = 1, second part has (real-time/musical-time) durations rdur/mdur construct part number i (1 or 2) 
#### Parameters
* `env` must contain an input segment and interval heap 

* `rdur` must be strictly positive. 

* `mdur` must be strictly positive. 

* `i` must be 1 or 2. 

* `s` can be [WTA](#classWTA) state or Meta state.

#### `public  `[`SIpointer`](#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9)`(`[`Environment`](#classEnvironment)` *,const `[`SIpointer`](#classSIpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gab5c8a8654ef626d4c7b75ef67ed28aa9}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga3df3168789d247e497f127caa7840e88)`(const `[`SIpointer`](#classSIpointer)` &)` {#group__table_1ga3df3168789d247e497f127caa7840e88}

copy.

#### `public  `[`SIpointer`](#group__table_1ga175406f6e30433d90a004aa27c401f29)`(const `[`SIpointer`](#classSIpointer)` & p,const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` {#group__table_1ga175406f6e30433d90a004aa27c401f29}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIpointer`](#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e)`(const `[`SIpointer`](#classSIpointer)` & p0,const `[`SIpointer`](#classSIpointer)` & p1)` {#group__table_1ga19a6965aca9363f90f45c5d0e07bc99e}

instance as next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`SIpointer`](#classSIpointer)` & `[`operator=`](#group__table_1ga071bb69977a62e26f9ec11230ae2646b)`(const `[`SIpointer`](#classSIpointer)` &)` {#group__table_1ga071bb69977a62e26f9ec11230ae2646b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1ga3330f8e59b08797b4c73ae558f6d588e)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga3330f8e59b08797b4c73ae558f6d588e}

for use as key in a unordered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator!=`](#group__table_1ga303c4da57a70fa07b7a2de3692fc9091)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga303c4da57a70fa07b7a2de3692fc9091}

#### `public virtual bool `[`operator<`](#group__table_1ga51c64ecf271622a259840f55236778ef)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1ga51c64ecf271622a259840f55236778ef}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga259b23462f7e87f6df0e9361c1884618)`(const `[`SIpointer`](#classSIpointer)` & p) const` {#group__table_1ga259b23462f7e87f6df0e9361c1884618}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f)`(const `[`SIpointer`](#classSIpointer)` & p) const` {#group__table_1gaa50fe6e651b28c77839ddfaf1bbdcd4f}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public inline virtual bool `[`has_I`](#classSIpointer_1a4cb39a0c156f3b09eb15feb12dad2434)`() const` {#classSIpointer_1a4cb39a0c156f3b09eb15feb12dad2434}

#### `public inline virtual bool `[`has_P`](#classSIpointer_1a433d1c2fbb2e79b7f0ada6b424739bec)`() const` {#classSIpointer_1a433d1c2fbb2e79b7f0ada6b424739bec}

#### `public inline `[`IntervalTree`](#classIntervalTree)` * `[`interval`](#classSIpointer_1a1471edc06d0a40b154cb1b643b9f28f7)`() const` {#classSIpointer_1a1471edc06d0a40b154cb1b643b9f28f7}

#### `public virtual bool `[`complete`](#group__table_1ga638627bc96caa0f1dbf7093f0f70951b)`() const` {#group__table_1ga638627bc96caa0f1dbf7093f0f70951b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga6bdbea8e7013194f834be17932efe642)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga6bdbea8e7013194f834be17932efe642}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source) the _pre value must be known _node must be set

#### `public virtual bool `[`divisible`](#group__table_1gac83e0619c17ce4efd589f73513706a6b)`() const` {#group__table_1gac83e0619c17ce4efd589f73513706a6b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

if this pointer has a [WTA](#classWTA) state: it is not worth descending when this pointer corresponds to an input sub-segment not inhabited.

if this pointer has a Meta state: it is not worth descending when this ptr corresponds to an empty segment.

#### `public virtual bool `[`compatible`](#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` {#group__table_1gaca7d3c4d141ecf2874a5e5512e0c02ff}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`dummy`](#group__table_1ga555753e41af94ac201a0c8c99babb83b)`() const` {#group__table_1ga555753e41af94ac201a0c8c99babb83b}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce)`(const `[`InputSegment`](#classInputSegment)` *,const `[`Transition`](#classTransition)` &) const` {#group__table_1ga6b46b59b3b465ba6a995f76ff34970ce}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

input segment must not be NULL.

#### `protected `[`IntervalTree`](#classIntervalTree)` * `[`_node`](#classSIpointer_1ad623e07df03b58eced4ceaf0855f5993) {#classSIpointer_1ad623e07df03b58eced4ceaf0855f5993}

#### `protected bool `[`equal_node`](#group__table_1gacc34f81b5d73c93840bce279ddde4620)`(const `[`SIpointer`](#classSIpointer)` &) const` {#group__table_1gacc34f81b5d73c93840bce279ddde4620}

# class `SIPpointer` {#classSIPpointer}

```
class SIPpointer
  : public SIpointer
```  

key in a parse table. pointer to a (best) run for 1-best parsing for [WTA](#classWTA) and input segment.

a [SIPpointer](#classSIPpointer) contains

* a state symbol: either a [WTA](#classWTA) state or a meta state or a leaf label

* an aligned interval in the input segment

* pre and post values, known or not (partial ptr)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`SIPpointer`](#group__table_1gac498892cd08ebd0663899dc82b00fac6)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` | dummy ptr.
`public  `[`SIPpointer`](#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` | fake ptr for terminal run, contains only a label symbol. it is considered as complete
`public  `[`SIPpointer`](#group__table_1ga5470d875405a71931e2349915201da20)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,double rext)` | class specific top ptr (covering the whole input segment
`public  `[`SIPpointer`](#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` | split ptr p in 2 parts.
`public  `[`SIPpointer`](#group__table_1gad83be64e20b13419994b3e9ae23654d1)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,size_t a,size_t i,state_t s)` | sub-pointer or instance as leaf.
`public  `[`SIPpointer`](#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e)`(const `[`SIPpointer`](#classSIPpointer)` &)` | copy.
`public  `[`SIPpointer`](#group__table_1gaa4c3c43c081bf789120e96683bc70cb3)`(const `[`SIPpointer`](#classSIPpointer)` & p,const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` | instance as parent.
`public  `[`SIPpointer`](#group__table_1ga12c22407821e96d6c7d0bca88392cbda)`(const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` | instance as next sibling.
`public virtual `[`SIPpointer`](#classSIPpointer)` & `[`operator=`](#group__table_1ga9855eef9600bbdd1e74343844e0c158c)`(const `[`SIPpointer`](#classSIPpointer)` &)` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1ga519f21be86b2ddb4fae2bab869434863)`(const `[`SIPpointer`](#classSIPpointer)` &) const` | for use as key in a unordered_multimap.
`public virtual bool `[`operator!=`](#group__table_1ga58f25245c42e16d11738e74c66a63cf6)`(const `[`SIPpointer`](#classSIPpointer)` &) const` | 
`public virtual bool `[`operator<`](#group__table_1gaefff5ba3579bd6174700ab1462fa13fb)`(const `[`SIPpointer`](#classSIPpointer)` &) const` | for use as key in a multimap.
`public virtual bool `[`instance`](#group__table_1gad7e14d03ea63991d16a0da5292eda82d)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gae02f880deb0305e3122caf05f9d2bad0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public inline virtual bool `[`has_I`](#classSIPpointer_1a1166ddc463561929c52bc12f6cd47bca)`() const` | 
`public inline virtual bool `[`has_P`](#classSIPpointer_1a251168384b826897585f182320d4d8ac)`() const` | 
`public inline `[`IntervalTree`](#classIntervalTree)` * `[`interval`](#classSIPpointer_1a927bea0aa60bd7e1f9b300a7e9cfd572)`() const` | 
`public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#classSIPpointer_1a0c9365dacbf1d57e53ecf9eb3bb22240)`() const` | 
`public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#classSIPpointer_1a0c213749e0aae712a17837e5f9f2b15a)`() const` | 
`public virtual bool `[`complete`](#group__table_1ga2f95b5a2058b20744a00737b1240bc83)`() const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0)`(const `[`Transition`](#classTransition)` & t) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`compatible`](#group__table_1gabf87df773f8e0f628e0bae79e88097db)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`dummy`](#group__table_1gaf830b0bf9d24b53e4674de49308b7853)`() const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga01caac75d66ff2e272a248c7e1954415)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`Transition`](#classTransition)` & t) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_pre`](#classSIPpointer_1acfbd9084ef6db9de5776896247ac71c8) | pre and post contain concrete labels (number of events)
`protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_post`](#classSIPpointer_1ab8ae3255dd4e6f898db0c5e49c860f28) | pre and post contain concrete labels (number of events)

## Members

#### `public  `[`SIPpointer`](#group__table_1gac498892cd08ebd0663899dc82b00fac6)`(`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post)` {#group__table_1gac498892cd08ebd0663899dc82b00fac6}

dummy ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`)` {#group__table_1gafcef62ae9e6a74448beec7ac040f6d7c}

fake ptr for terminal run, contains only a label symbol. it is considered as complete

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga5470d875405a71931e2349915201da20)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,double rext)` {#group__table_1ga5470d875405a71931e2349915201da20}

class specific top ptr (covering the whole input segment

* given extension in realtime.

#### Parameters
* `env` must contain an input segment and interval heap

#### `public  `[`SIPpointer`](#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,double rdur,`[`Rational`](#classRational)` mdur,bool position,size_t i,state_t s)` {#group__table_1gaeea3246bf0f27b8b4a0a930f7d1a4379}

split ptr p in 2 parts.

if position = 0, first part has (real-time/musical-time) durations rdur/mdur

if position = 1, second part has (real-time/musical-time) durations rdur/mdur

construct part number i (1 or 2) 
#### Parameters
* `env` must contain an input segment and interval heap 

* `rdur` must be strictly positive. 

* `mdur` must be strictly positive. 

* `i` must be 1 or 2. 

* `s` (state) can be [WTA](#classWTA) or Meta.

#### `public  `[`SIPpointer`](#group__table_1gad83be64e20b13419994b3e9ae23654d1)`(`[`Environment`](#classEnvironment)` *,const `[`SIPpointer`](#classSIPpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gad83be64e20b13419994b3e9ae23654d1}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e)`(const `[`SIPpointer`](#classSIPpointer)` &)` {#group__table_1ga32c45b7b04d59e932c5b43ba03b47b4e}

copy.

#### `public  `[`SIPpointer`](#group__table_1gaa4c3c43c081bf789120e96683bc70cb3)`(const `[`SIPpointer`](#classSIPpointer)` & p,const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` {#group__table_1gaa4c3c43c081bf789120e96683bc70cb3}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SIPpointer`](#group__table_1ga12c22407821e96d6c7d0bca88392cbda)`(const `[`SIPpointer`](#classSIPpointer)` & p0,const `[`SIPpointer`](#classSIPpointer)` & p1)` {#group__table_1ga12c22407821e96d6c7d0bca88392cbda}

instance as next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`SIPpointer`](#classSIPpointer)` & `[`operator=`](#group__table_1ga9855eef9600bbdd1e74343844e0c158c)`(const `[`SIPpointer`](#classSIPpointer)` &)` {#group__table_1ga9855eef9600bbdd1e74343844e0c158c}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1ga519f21be86b2ddb4fae2bab869434863)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1ga519f21be86b2ddb4fae2bab869434863}

for use as key in a unordered_multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator!=`](#group__table_1ga58f25245c42e16d11738e74c66a63cf6)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1ga58f25245c42e16d11738e74c66a63cf6}

#### `public virtual bool `[`operator<`](#group__table_1gaefff5ba3579bd6174700ab1462fa13fb)`(const `[`SIPpointer`](#classSIPpointer)` &) const` {#group__table_1gaefff5ba3579bd6174700ab1462fa13fb}

for use as key in a multimap.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1gad7e14d03ea63991d16a0da5292eda82d)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` {#group__table_1gad7e14d03ea63991d16a0da5292eda82d}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gae02f880deb0305e3122caf05f9d2bad0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` {#group__table_1gae02f880deb0305e3122caf05f9d2bad0}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public inline virtual bool `[`has_I`](#classSIPpointer_1a1166ddc463561929c52bc12f6cd47bca)`() const` {#classSIPpointer_1a1166ddc463561929c52bc12f6cd47bca}

#### `public inline virtual bool `[`has_P`](#classSIPpointer_1a251168384b826897585f182320d4d8ac)`() const` {#classSIPpointer_1a251168384b826897585f182320d4d8ac}

#### `public inline `[`IntervalTree`](#classIntervalTree)` * `[`interval`](#classSIPpointer_1a927bea0aa60bd7e1f9b300a7e9cfd572)`() const` {#classSIPpointer_1a927bea0aa60bd7e1f9b300a7e9cfd572}

#### `public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`pre`](#classSIPpointer_1a0c9365dacbf1d57e53ecf9eb3bb22240)`() const` {#classSIPpointer_1a0c9365dacbf1d57e53ecf9eb3bb22240}

#### `public inline `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`post`](#classSIPpointer_1a0c213749e0aae712a17837e5f9f2b15a)`() const` {#classSIPpointer_1a0c213749e0aae712a17837e5f9f2b15a}

#### `public virtual bool `[`complete`](#group__table_1ga2f95b5a2058b20744a00737b1240bc83)`() const` {#group__table_1ga2f95b5a2058b20744a00737b1240bc83}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0)`(const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga7f7cd8ae86d71b147fc662d3cc4977c0}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

the _pre value must be known 

_node must be set

#### `public virtual bool `[`compatible`](#group__table_1gabf87df773f8e0f628e0bae79e88097db)`(const `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,bool abstract) const` {#group__table_1gabf87df773f8e0f628e0bae79e88097db}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`dummy`](#group__table_1gaf830b0bf9d24b53e4674de49308b7853)`() const` {#group__table_1gaf830b0bf9d24b53e4674de49308b7853}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual `[`Weight`](#classWeight)` `[`terminalWeight`](#group__table_1ga01caac75d66ff2e272a248c7e1954415)`(const `[`InputSegment`](#classInputSegment)` * s,const `[`Transition`](#classTransition)` & t) const` {#group__table_1ga01caac75d66ff2e272a248c7e1954415}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `s` input segment must not be NULL.

#### `protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_pre`](#classSIPpointer_1acfbd9084ef6db9de5776896247ac71c8) {#classSIPpointer_1acfbd9084ef6db9de5776896247ac71c8}

pre and post contain concrete labels (number of events)

**See also**: [Label.hpp](#Label_8hpp_source)

#### `protected `[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` `[`_post`](#classSIPpointer_1ab8ae3255dd4e6f898db0c5e49c860f28) {#classSIPpointer_1ab8ae3255dd4e6f898db0c5e49c860f28}

pre and post contain concrete labels (number of events)

**See also**: [Label.hpp](#Label_8hpp_source)

# class `SKpointer` {#classSKpointer}

```
class SKpointer
  : public Spointer
```  

pointer to a (best) run. for k-best parsing with standard [WTA](#classWTA) a [SKpointer](#classSKpointer) contains

* a state symbol (see [Spointer](#classSpointer))

* a rank:

* 0 if the state symbol is a leaf label,

* > 0 otherwise in the case of Viterbi algo (1-best), the rank is defaulted to 1

all [SKpointer](#classSKpointer)'s are complete.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`SKpointer`](#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5)`()` | specific
`public  `[`SKpointer`](#group__table_1ga876c1101716f9aea625574f9be9b3da5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` | specific
`public  `[`SKpointer`](#group__table_1ga022b6998c4273e2da8128ccd2205a7f6)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` | top ptr.
`public  `[`SKpointer`](#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9)`(`[`Environment`](#classEnvironment)` *,const `[`SKpointer`](#classSKpointer)` & p,size_t a,size_t i,state_t s)` | sub-pointer or instance as leaf.
`public  `[`SKpointer`](#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3)`(const `[`SKpointer`](#classSKpointer)` &)` | copy.
`public  `[`SKpointer`](#group__table_1gaf762b88808d2e8188b74e28256d3ed09)`(const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` | next sibling.
`public  `[`SKpointer`](#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9)`(const `[`SKpointer`](#classSKpointer)` & p,const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` | instance as parent.
`public virtual `[`SKpointer`](#classSKpointer)` & `[`operator=`](#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1)`(const `[`SKpointer`](#classSKpointer)` &)` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1gab77c2fa945fcc938568ace9986c25324)`(const `[`SKpointer`](#classSKpointer)` &) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`instance`](#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937)`(const `[`SKpointer`](#classSKpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1ga38150ffb7a8bf25ebf5133907d568738)`(const `[`SKpointer`](#classSKpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public inline virtual bool `[`has_K`](#classSKpointer_1afe3aef0a71afa0e6d022c52aa0f28163)`() const` | 
`public inline virtual size_t `[`rank`](#classSKpointer_1ae7afb64da3fbb9fc0487913f3ee594a3)`() const` | return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.
`public virtual void `[`incr`](#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a)`()` | 
`protected size_t `[`_rank`](api-table.md#classSKpointer_1a532a7a3f69049503ccf94834b77f48f3) | k as in k-best

## Members

#### `public  `[`SKpointer`](#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5)`()` {#group__table_1gaffcc41d2b1b8a85e3ea9acd3086321f5}

specific

#### `public  `[`SKpointer`](#group__table_1ga876c1101716f9aea625574f9be9b3da5)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` {#group__table_1ga876c1101716f9aea625574f9be9b3da5}

specific

#### `public  `[`SKpointer`](#group__table_1ga022b6998c4273e2da8128ccd2205a7f6)`(`[`WTA`](#classWTA)` * a,`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mlen,size_t k)` {#group__table_1ga022b6998c4273e2da8128ccd2205a7f6}

top ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### Parameters
* `bar` must be true TBR deprecated (replace by specific constructor)

#### `public  `[`SKpointer`](#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9)`(`[`Environment`](#classEnvironment)` *,const `[`SKpointer`](#classSKpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1gac3044b001a0035c0ea79ffac0a57d1d9}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

no default duration for ambiguity reasons.

#### `public  `[`SKpointer`](#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3)`(const `[`SKpointer`](#classSKpointer)` &)` {#group__table_1gae5dd2d6c4dde18082b5e20e34ead8bf3}

copy.

#### `public  `[`SKpointer`](#group__table_1gaf762b88808d2e8188b74e28256d3ed09)`(const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` {#group__table_1gaf762b88808d2e8188b74e28256d3ed09}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial

#### `public  `[`SKpointer`](#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9)`(const `[`SKpointer`](#classSKpointer)` & p,const `[`SKpointer`](#classSKpointer)` & p0,const `[`SKpointer`](#classSKpointer)` & p1)` {#group__table_1ga8c3f64b049fb3809bec46ba47a124ab9}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial

#### `public virtual `[`SKpointer`](#classSKpointer)` & `[`operator=`](#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1)`(const `[`SKpointer`](#classSKpointer)` &)` {#group__table_1gaa75ae4ae4ce8c389471867fa64f503c1}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1gab77c2fa945fcc938568ace9986c25324)`(const `[`SKpointer`](#classSKpointer)` &) const` {#group__table_1gab77c2fa945fcc938568ace9986c25324}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937)`(const `[`SKpointer`](#classSKpointer)` & p) const` {#group__table_1ga95bdb4d9654b477a82f61d4e8b1d6937}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1ga38150ffb7a8bf25ebf5133907d568738)`(const `[`SKpointer`](#classSKpointer)` & p) const` {#group__table_1ga38150ffb7a8bf25ebf5133907d568738}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public inline virtual bool `[`has_K`](#classSKpointer_1afe3aef0a71afa0e6d022c52aa0f28163)`() const` {#classSKpointer_1afe3aef0a71afa0e6d022c52aa0f28163}

#### `public inline virtual size_t `[`rank`](#classSKpointer_1ae7afb64da3fbb9fc0487913f3ee594a3)`() const` {#classSKpointer_1ae7afb64da3fbb9fc0487913f3ee594a3}

return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.

#### `public virtual void `[`incr`](#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a)`()` {#group__table_1ga560a9c964dcc9ad7631213d6ad061a2a}

#### `protected size_t `[`_rank`](api-table.md#classSKpointer_1a532a7a3f69049503ccf94834b77f48f3) {#classSKpointer_1a532a7a3f69049503ccf94834b77f48f3}

k as in k-best

# class `SKIPpointer` {#classSKIPpointer}

```
class SKIPpointer
  : public SIPpointer
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`SKIPpointer`](#group__table_1ga24e762a60a81030599decff93dc1a1ef)`()` | dummy ptr.
`public  `[`SKIPpointer`](#group__table_1ga1fc4cd4038153502277d11c5607a14fa)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` | specific fake ptr for terminal run, contains only a label symbol. it is considered as complete
`public  `[`SKIPpointer`](#group__table_1gab217454122f2ec0af5c16bb1ae996925)`(`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,bool bar,size_t k)` | TBR deprecated.
`public  `[`SKIPpointer`](#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,size_t k)` | class specific top ptr (covering the whole input segment.
`public  `[`SKIPpointer`](#group__table_1ga6cd275122aebf4288f5d60c36a141116)`(`[`Environment`](#classEnvironment)` * env,const `[`SKIPpointer`](#classSKIPpointer)` & p,size_t a,size_t i,state_t s)` | sub-pointer or instance as leaf.
`public  `[`SKIPpointer`](#group__table_1ga3366b26b81c9cb040716918f7d375879)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` | copy.
`public  `[`SKIPpointer`](#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d)`(const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` | next sibling.
`public  `[`SKIPpointer`](#group__table_1ga8b87b18aa76b4021da6d3421c738b002)`(const `[`SKIPpointer`](#classSKIPpointer)` & p,const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` | instance as parent.
`public virtual `[`SKIPpointer`](#classSKIPpointer)` & `[`operator=`](#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`operator==`](#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4)`(const `[`SKIPpointer`](#classSKIPpointer)` &) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`instance`](#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public virtual bool `[`subsume`](#group__table_1gaacf829ba5696414bdcc753e97e76a7f1)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` | **See also**: description in [Ptr.hpp](#Ptr_8hpp_source)
`public inline virtual bool `[`has_K`](#classSKIPpointer_1aec99858a74fb6a7b15975d3e65f79c31)`() const` | 
`public inline virtual size_t `[`rank`](#classSKIPpointer_1a9c89c0ff929c37399870880fb448de98)`() const` | return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.
`public virtual void `[`incr`](#group__table_1gac0c72ab0a91e652b38eb815206b0baa4)`()` | 
`protected size_t `[`_rank`](api-table.md#classSKIPpointer_1a54ba5b0ffdc369da69f394b791a8b7f2) | k as in k-best.

## Members

#### `public  `[`SKIPpointer`](#group__table_1ga24e762a60a81030599decff93dc1a1ef)`()` {#group__table_1ga24e762a60a81030599decff93dc1a1ef}

dummy ptr.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SKIPpointer`](#group__table_1ga1fc4cd4038153502277d11c5607a14fa)`(`[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)`,size_t k)` {#group__table_1ga1fc4cd4038153502277d11c5607a14fa}

specific fake ptr for terminal run, contains only a label symbol. it is considered as complete

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public  `[`SKIPpointer`](#group__table_1gab217454122f2ec0af5c16bb1ae996925)`(`[`Environment`](#classEnvironment)` * env,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,bool bar,size_t k)` {#group__table_1gab217454122f2ec0af5c16bb1ae996925}

TBR deprecated.

#### `public  `[`SKIPpointer`](#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638)`(`[`Environment`](#classEnvironment)` * env,state_t s,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` pre,`[`pre_t`](#group__general_1ga092fe8b972dfa977c2a0886720a7731e)` post,`[`Rational`](#classRational)` mdur,size_t k)` {#group__table_1ga8a29b4e0af8d4fc8d298b7027e4cf638}

class specific top ptr (covering the whole input segment.

env must contain an input segment and interval heap.

#### `public  `[`SKIPpointer`](#group__table_1ga6cd275122aebf4288f5d60c36a141116)`(`[`Environment`](#classEnvironment)` * env,const `[`SKIPpointer`](#classSKIPpointer)` & p,size_t a,size_t i,state_t s)` {#group__table_1ga6cd275122aebf4288f5d60c36a141116}

sub-pointer or instance as leaf.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

no default duration for ambiguity reasons

#### `public  `[`SKIPpointer`](#group__table_1ga3366b26b81c9cb040716918f7d375879)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` {#group__table_1ga3366b26b81c9cb040716918f7d375879}

copy.

#### `public  `[`SKIPpointer`](#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d)`(const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` {#group__table_1ga5dd0fd6fd23ca132973ec5f76a7f568d}

next sibling.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p1 must be partial

#### `public  `[`SKIPpointer`](#group__table_1ga8b87b18aa76b4021da6d3421c738b002)`(const `[`SKIPpointer`](#classSKIPpointer)` & p,const `[`SKIPpointer`](#classSKIPpointer)` & p0,const `[`SKIPpointer`](#classSKIPpointer)` & p1)` {#group__table_1ga8b87b18aa76b4021da6d3421c738b002}

instance as parent.

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

should not be called since p must be partial

#### `public virtual `[`SKIPpointer`](#classSKIPpointer)` & `[`operator=`](#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4)`(const `[`SKIPpointer`](#classSKIPpointer)` &)` {#group__table_1ga54d7c5b3e7aa20e48ff8d15e9e0895f4}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`operator==`](#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4)`(const `[`SKIPpointer`](#classSKIPpointer)` &) const` {#group__table_1ga4ecc91594489358cf7abdbf8cfd245a4}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`instance`](#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` {#group__table_1gaa9ccc9cf48974dca2a09ca4aa6092d43}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public virtual bool `[`subsume`](#group__table_1gaacf829ba5696414bdcc753e97e76a7f1)`(const `[`SKIPpointer`](#classSKIPpointer)` & p) const` {#group__table_1gaacf829ba5696414bdcc753e97e76a7f1}

**See also**: description in [Ptr.hpp](#Ptr_8hpp_source)

#### `public inline virtual bool `[`has_K`](#classSKIPpointer_1aec99858a74fb6a7b15975d3e65f79c31)`() const` {#classSKIPpointer_1aec99858a74fb6a7b15975d3e65f79c31}

#### `public inline virtual size_t `[`rank`](#classSKIPpointer_1a9c89c0ff929c37399870880fb448de98)`() const` {#classSKIPpointer_1a9c89c0ff929c37399870880fb448de98}

return the rank of best (k) pointed. default is 1. redefine for classes for k-best parsing.

#### `public virtual void `[`incr`](#group__table_1gac0c72ab0a91e652b38eb815206b0baa4)`()` {#group__table_1gac0c72ab0a91e652b38eb815206b0baa4}

#### `protected size_t `[`_rank`](api-table.md#classSKIPpointer_1a54ba5b0ffdc369da69f394b791a8b7f2) {#classSKIPpointer_1a54ba5b0ffdc369da69f394b791a8b7f2}

k as in k-best.

# class `Record` {#classRecord}

abstract class describing the basic functionalities of a record.

each record is associated to a Ptr it can be filled with add and can be interrogating with best, for retrieving the best runs for the associated Ptr.

when uncomplete runs are added to the record (either by the record or from outside) their weight must be computed using a table.

there are 3 similar kinds of Run* that should not be added in record: TBC should not be returned by best on the record ?

* NULL ptr to [Run](#classRun)

* ptr to [Run](#classRun) with unknown weight (i.e. weight with NULL letter) that case includes null runs.

* ptr to [Run](#classRun) with weight == zero (acc. to test zero()). a [Run](#classRun) not in these 3 case is called valid.

[update] the runs with weight zero (still invalid) can be added to records but an error message is displayed (for debugging).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`state`](api-table.md#classRecord_1a9b17378a46d2026b86632728f820d804) | state - possible values: 0 : empty (record just created no run was stored) 1 : add(_key) was not called but add(p) was called for p partial and subsuming _key 2 : add(_key) was called 3 : some run has been stored but we are not in 1 or 2. should not happen.
`public  `[`Record`](#classRecord_1abfb78c84cf6c1a7b932bec064670c35c)`(const P &,RunCompare< P >)` | 
`public void `[`add`](#classRecord_1a33cf3cee78f8b663595f0702f145c9d5)`(`[`Run`](#classRun)`< P > *)` | add a run to the record.
`public `[`Run`](#classRun)`< P > * `[`best`](#classRecord_1a767aeb8c69e0866328fc82e066af7c3b)`(`[`Atable`](#classAtable)`< P > * table,size_t k)` | returns the k-th best run of the record
`public inline const P & `[`key`](#classRecord_1a2432ec9a436061e486512d4201322b10)`()` | 
`public bool `[`empty`](#classRecord_1aa3b6e99a13b1b6537d2b6bde3abb2978)`() const` | 
`protected P `[`_key`](api-table.md#classRecord_1abf6ea6cd82f35b05f70222bd3fdeefba) | copy of the key associated to the record in container.
`protected RunCompare< P > `[`_comp`](api-table.md#classRecord_1ab2357a1913c48fa519a7aff23026155f) | comparison function.
`protected size_t `[`_nb_cand`](api-table.md#classRecord_1a25d3afd2df62895c4768d6a520fd174a) | number of candidate bests constructed.
`protected size_t `[`_nb_best_rejected`](api-table.md#classRecord_1ac95357b0115df96cd4b5da99e973880d) | number of best not added to the list because of optimization filters.
`protected bool `[`valid`](#classRecord_1a6ea298ae02397c6b390ac098f2ed9a66)`(`[`Run`](#classRun)`< P > *)` | 

## Members

#### `public unsigned int `[`state`](api-table.md#classRecord_1a9b17378a46d2026b86632728f820d804) {#classRecord_1a9b17378a46d2026b86632728f820d804}

state - possible values: 0 : empty (record just created no run was stored) 1 : add(_key) was not called but add(p) was called for p partial and subsuming _key 2 : add(_key) was called 3 : some run has been stored but we are not in 1 or 2. should not happen.

The state is not changed inside the [Record](#classRecord) class. It is changed by callers (table.add).

#### `public  `[`Record`](#classRecord_1abfb78c84cf6c1a7b932bec064670c35c)`(const P &,RunCompare< P >)` {#classRecord_1abfb78c84cf6c1a7b932bec064670c35c}

#### `public void `[`add`](#classRecord_1a33cf3cee78f8b663595f0702f145c9d5)`(`[`Run`](#classRun)`< P > *)` {#classRecord_1a33cf3cee78f8b663595f0702f145c9d5}

add a run to the record.

#### `public `[`Run`](#classRun)`< P > * `[`best`](#classRecord_1a767aeb8c69e0866328fc82e066af7c3b)`(`[`Atable`](#classAtable)`< P > * table,size_t k)` {#classRecord_1a767aeb8c69e0866328fc82e066af7c3b}

returns the k-th best run of the record

#### Parameters
* `table` can be used to compute weights of new runs. 

* `k` rank (as in k-best)

#### `public inline const P & `[`key`](#classRecord_1a2432ec9a436061e486512d4201322b10)`()` {#classRecord_1a2432ec9a436061e486512d4201322b10}

#### `public bool `[`empty`](#classRecord_1aa3b6e99a13b1b6537d2b6bde3abb2978)`() const` {#classRecord_1aa3b6e99a13b1b6537d2b6bde3abb2978}

#### `protected P `[`_key`](api-table.md#classRecord_1abf6ea6cd82f35b05f70222bd3fdeefba) {#classRecord_1abf6ea6cd82f35b05f70222bd3fdeefba}

copy of the key associated to the record in container.

#### `protected RunCompare< P > `[`_comp`](api-table.md#classRecord_1ab2357a1913c48fa519a7aff23026155f) {#classRecord_1ab2357a1913c48fa519a7aff23026155f}

comparison function.

#### `protected size_t `[`_nb_cand`](api-table.md#classRecord_1a25d3afd2df62895c4768d6a520fd174a) {#classRecord_1a25d3afd2df62895c4768d6a520fd174a}

number of candidate bests constructed.

#### `protected size_t `[`_nb_best_rejected`](api-table.md#classRecord_1ac95357b0115df96cd4b5da99e973880d) {#classRecord_1ac95357b0115df96cd4b5da99e973880d}

number of best not added to the list because of optimization filters.

#### `protected bool `[`valid`](#classRecord_1a6ea298ae02397c6b390ac098f2ed9a66)`(`[`Run`](#classRun)`< P > *)` {#classRecord_1a6ea298ae02397c6b390ac098f2ed9a66}

# class `Run` {#classRun}

a run is a compact representation of parse trees as a tuple of pointers to subruns.

a run stores

* a list of children represented by pointers (template type) compatible with a transition

* a weight (to evaluate)

* a temporary weight value (initialy the weight of the parent transition)

* a list of relative durations.

a run can be of 3 kinds:

* null run:

* unknown current weight,

* unknown tmp weight,

* no children,

* empty duration list.

* terminal (leaf) run

* created from terminal (length 1) parent transition:

* current weight unknown or current weight known (evaluated),

* tmp weight known,

* 1 child : fake pointer containing as state the transition label (and rank 0 if the pointer class has a rank)

* duration list with single continuation or single event preceeded graces notes

* inner run

* created from inner (length > 1) parent transition:

* current weight unknown or current weight known (evaluated)

* tmpt weight known

* nb children = length parent transition

* duration list == empty (unknown) or not (evaluated).

TODO suppr. null runs

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Weight`](#classWeight)` `[`weight`](#classRun_1a61e6a26fe0ae42b0e4d54babc8c46684) | current weight. totally evaluated when evaluated() = true.
`public `[`DurationList`](#classDurationList)` `[`duration`](#classRun_1ad7eda2272d3a6be2ff0c3e2482051029) | list of relative durations.
`public  `[`Run`](#classRun_1ae8145f85e985d5ff3aa118bd99901675)`()` | construct a null run (special)
`public  `[`Run`](#classRun_1a63172061ee2c7c601f13d4ef3f3a67bd)`(`[`Weight`](#classWeight)` w)` | [Run](api-table.md#classRun) with empty body and given weight. the run is marked as meta. the first PartialorUpdate child is 0.
`public  `[`Run`](#classRun_1a0a075a813930403154728bcea9062a55)`(`[`Environment`](#classEnvironment)` *,const P &,const `[`Transition`](#classTransition)` &)` | [WTA](#classWTA)[Run](#classRun) with head the given pointer. the given pointer must be a wta ptr. the body is build according to the transition t.
`public  `[`Run`](#classRun_1a1ffdaf6f1209f5692898af9142ff0168)`(const `[`Run`](#classRun)`< P > &)` | copy.
`public  `[`Run`](#classRun_1ae14a444c0e91801d76f5138a36da435d)`(const `[`Run`](#classRun)`< P > & r,size_t i)` | copy r and increase rank of pointer number i.
`public  `[`Run`](#classRun_1aa0d15ec06ce84a5db17c26922f708d44)`(const `[`Run`](#classRun)`< P > & r,const P & p)` | copy/update constructor
`public  `[`~Run`](#classRun_1ab0bf6832f238cd38bf78f2074ccdcaf7)`()` | 
`public `[`Run`](#classRun)`< P > & `[`operator=`](#classRun_1a89b0d51eafbc4c34a92f2eca0d8e77f8)`(const `[`Run`](#classRun)`< P > &)` | 
`public bool `[`operator==`](#classRun_1a47f62430b7446078aa94dcbb45e86dfc)`(const `[`Run`](#classRun)`< P > & s) const` | 
`public bool `[`null`](#classRun_1a5efb56b2aaad574a21e42aeb6a7b5742)`() const` | this run is null - constructed with [Run()](api-table.md#classRun_1ae8145f85e985d5ff3aa118bd99901675).
`public bool `[`terminal`](#classRun_1a69d622e31bcd4e6f07c43efc0e788481)`() const` | this run is terminal (leaf).
`public bool `[`inner`](#classRun_1a006c247eb8839a9a5045e53917e984c6)`() const` | this run is inner.
`public bool `[`meta`](#classRun_1a3fc5bc7196b967860f4c412bf47c8d9c)`() const` | meta run: inner, binary and second child is a meta state.
`public bool `[`allcomplete`](#classRun_1abf33aa6674f2799357490fe893b7757a)`() const` | all ptr in children list are complete.
`public bool `[`complete`](#classRun_1a8b93caf0971738f454db7815db41501e)`() const` | all ptr in children list are complete and the weight of this run has been evaluated.
`public inline bool `[`partial`](#classRun_1a920c86e66e9189c7aebb8b449b2441ae)`() const` | 
`public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#classRun_1ab0f5c4a978f33dd4e2df24174f6534f1)`() const` | this run must be terminal
`public size_t `[`arity`](#classRun_1ab9eeb2e8033cf68b80099e56ddca8ff1)`() const` | return the number of children of this [Run](api-table.md#classRun): = 0 in the case of terminal run 1 for inner run <br/><br/>= 2 for meta run
`public bool `[`filter`](#classRun_1a1da9ef823788854753f7641bd872cf50)`()` | 
`public inline const P & `[`operator[]`](#classRun_1a17781141b67e9cd2675c0dad722de2ec)`(size_t i) const` | return the ith subrun of this run.
`public const P & `[`first`](#classRun_1a6b635ca66114e64fbcb91a5a9652d78d)`() const` | first children.
`public const P & `[`last`](#classRun_1a49c0418a8ab9eb372e09d7d5c813e0aa)`() const` | last children.
`public const P & `[`firstPartialorUpdate`](#classRun_1a94a0bfa98d5891b750ba88e5f31441ad)`() const` | index of first children which is either either
`public void `[`insert`](#classRun_1ab41a4b6f0347b7b412637d505614b98f)`(const P &)` | append the given ptr at the end of body.
`public void `[`update`](#classRun_1afe9adec90106c1a7433b626aca320367)`(const `[`Weight`](#classWeight)` & w,const `[`DurationList`](#classDurationList)` & dl)` | update the weight and duration lists of this run with given weight and duration list.

## Members

#### `public `[`Weight`](#classWeight)` `[`weight`](#classRun_1a61e6a26fe0ae42b0e4d54babc8c46684) {#classRun_1a61e6a26fe0ae42b0e4d54babc8c46684}

current weight. totally evaluated when evaluated() = true.

#### `public `[`DurationList`](#classDurationList)` `[`duration`](#classRun_1ad7eda2272d3a6be2ff0c3e2482051029) {#classRun_1ad7eda2272d3a6be2ff0c3e2482051029}

list of relative durations.

#### `public  `[`Run`](#classRun_1ae8145f85e985d5ff3aa118bd99901675)`()` {#classRun_1ae8145f85e985d5ff3aa118bd99901675}

construct a null run (special)

#### `public  `[`Run`](#classRun_1a63172061ee2c7c601f13d4ef3f3a67bd)`(`[`Weight`](#classWeight)` w)` {#classRun_1a63172061ee2c7c601f13d4ef3f3a67bd}

[Run](#classRun) with empty body and given weight. the run is marked as meta. the first PartialorUpdate child is 0.

#### Parameters
* `w` must not be unknown weight . 

the body must be completed with [insert()](#classRun_1ab41a4b6f0347b7b412637d505614b98f).

#### `public  `[`Run`](#classRun_1a0a075a813930403154728bcea9062a55)`(`[`Environment`](#classEnvironment)` *,const P &,const `[`Transition`](#classTransition)` &)` {#classRun_1a0a075a813930403154728bcea9062a55}

[WTA](#classWTA)[Run](#classRun) with head the given pointer. the given pointer must be a wta ptr. the body is build according to the transition t.

* terminal run if t is terminal,

* the given ptr must be compatible with the transition's label.

* singleton children list with fake ptr containing only label.

* the run is complete.

* the weight of run is set to a combination of transition's weight and a distance returned by terminalWeight.

* inner run if t is inner (using states in the body of t)

* children list contains pointers of type P to the 1-best runs for the given transition for transition (s1,...,sn), the 1-best is (<s1,1>,...,<sn,1>).

* the ptrs in body are registered.

* the run is partial.

* the weight of run is set to innerWeight and must be mult. by weights of subruns.

* null run when it is not possible to construct one of the children.

#### `public  `[`Run`](#classRun_1a1ffdaf6f1209f5692898af9142ff0168)`(const `[`Run`](#classRun)`< P > &)` {#classRun_1a1ffdaf6f1209f5692898af9142ff0168}

copy.

#### `public  `[`Run`](#classRun_1ae14a444c0e91801d76f5138a36da435d)`(const `[`Run`](#classRun)`< P > & r,size_t i)` {#classRun_1ae14a444c0e91801d76f5138a36da435d}

copy r and increase rank of pointer number i.

#### Parameters
* `r` must be inner. 

* `i` (child) must have rank, index i must be between 0 and arity of r - 1. the run is reset (partial): 

the weight and duration list of the run must be recomputed (the weight is reset to the weight of creator transition).

#### `public  `[`Run`](#classRun_1aa0d15ec06ce84a5db17c26922f708d44)`(const `[`Run`](#classRun)`< P > & r,const P & p)` {#classRun_1aa0d15ec06ce84a5db17c26922f708d44}

copy/update constructor

#### Parameters
* `r` must be partial. 

* `p` must be complete. copy r and replace first partialorUpdate child by p,

#### `public  `[`~Run`](#classRun_1ab0bf6832f238cd38bf78f2074ccdcaf7)`()` {#classRun_1ab0bf6832f238cd38bf78f2074ccdcaf7}

#### `public `[`Run`](#classRun)`< P > & `[`operator=`](#classRun_1a89b0d51eafbc4c34a92f2eca0d8e77f8)`(const `[`Run`](#classRun)`< P > &)` {#classRun_1a89b0d51eafbc4c34a92f2eca0d8e77f8}

#### `public bool `[`operator==`](#classRun_1a47f62430b7446078aa94dcbb45e86dfc)`(const `[`Run`](#classRun)`< P > & s) const` {#classRun_1a47f62430b7446078aa94dcbb45e86dfc}

#### `public bool `[`null`](#classRun_1a5efb56b2aaad574a21e42aeb6a7b5742)`() const` {#classRun_1a5efb56b2aaad574a21e42aeb6a7b5742}

this run is null - constructed with [Run()](#classRun_1ae8145f85e985d5ff3aa118bd99901675).

#### `public bool `[`terminal`](#classRun_1a69d622e31bcd4e6f07c43efc0e788481)`() const` {#classRun_1a69d622e31bcd4e6f07c43efc0e788481}

this run is terminal (leaf).

#### `public bool `[`inner`](#classRun_1a006c247eb8839a9a5045e53917e984c6)`() const` {#classRun_1a006c247eb8839a9a5045e53917e984c6}

this run is inner.

#### `public bool `[`meta`](#classRun_1a3fc5bc7196b967860f4c412bf47c8d9c)`() const` {#classRun_1a3fc5bc7196b967860f4c412bf47c8d9c}

meta run: inner, binary and second child is a meta state.

#### `public bool `[`allcomplete`](#classRun_1abf33aa6674f2799357490fe893b7757a)`() const` {#classRun_1abf33aa6674f2799357490fe893b7757a}

all ptr in children list are complete.

#### `public bool `[`complete`](#classRun_1a8b93caf0971738f454db7815db41501e)`() const` {#classRun_1a8b93caf0971738f454db7815db41501e}

all ptr in children list are complete and the weight of this run has been evaluated.

#### `public inline bool `[`partial`](#classRun_1a920c86e66e9189c7aebb8b449b2441ae)`() const` {#classRun_1a920c86e66e9189c7aebb8b449b2441ae}

#### `public `[`label_t`](#group__output_1ga22fde970e635fcf63962743b2d5c441d)` `[`label`](#classRun_1ab0f5c4a978f33dd4e2df24174f6534f1)`() const` {#classRun_1ab0f5c4a978f33dd4e2df24174f6534f1}

this run must be terminal

#### `public size_t `[`arity`](#classRun_1ab9eeb2e8033cf68b80099e56ddca8ff1)`() const` {#classRun_1ab9eeb2e8033cf68b80099e56ddca8ff1}

return the number of children of this [Run](#classRun): = 0 in the case of terminal run 1 for inner run 

= 2 for meta run

#### `public bool `[`filter`](#classRun_1a1da9ef823788854753f7641bd872cf50)`()` {#classRun_1a1da9ef823788854753f7641bd872cf50}

#### `public inline const P & `[`operator[]`](#classRun_1a17781141b67e9cd2675c0dad722de2ec)`(size_t i) const` {#classRun_1a17781141b67e9cd2675c0dad722de2ec}

return the ith subrun of this run.

#### Parameters
* `i` index of subrun 

the number of children must be at least i+1

#### `public const P & `[`first`](#classRun_1a6b635ca66114e64fbcb91a5a9652d78d)`() const` {#classRun_1a6b635ca66114e64fbcb91a5a9652d78d}

first children.

this run must be inner with arity > 0

#### `public const P & `[`last`](#classRun_1a49c0418a8ab9eb372e09d7d5c813e0aa)`() const` {#classRun_1a49c0418a8ab9eb372e09d7d5c813e0aa}

last children.

this run must be inner with arity > 0

#### `public const P & `[`firstPartialorUpdate`](#classRun_1a94a0bfa98d5891b750ba88e5f31441ad)`() const` {#classRun_1a94a0bfa98d5891b750ba88e5f31441ad}

index of first children which is either either

* partial, or

* whose weight did not contribute to run's weight or [arity()](#classRun_1ab9eeb2e8033cf68b80099e56ddca8ff1) if there is no such children.

the index of first children is 0, the index of last children is arity - 1. [complete()](#classRun_1a8b93caf0971738f454db7815db41501e) must not hold (otherwise there is no such children). 

this run must be inner with arity > 0.

#### `public void `[`insert`](#classRun_1ab41a4b6f0347b7b412637d505614b98f)`(const P &)` {#classRun_1ab41a4b6f0347b7b412637d505614b98f}

append the given ptr at the end of body.

the run must be marked as meta.

#### `public void `[`update`](#classRun_1afe9adec90106c1a7433b626aca320367)`(const `[`Weight`](#classWeight)` & w,const `[`DurationList`](#classDurationList)` & dl)` {#classRun_1afe9adec90106c1a7433b626aca320367}

update the weight and duration lists of this run with given weight and duration list.

#### Parameters
* `w` the given weight, must not be zero it must be the weight of best run for the first partialorupdate children (this cannot be checked!). 

* `dl` must be the duration list of best run for the first partialorupdate children (this cannot be checked!). 

this run must not be complete. 

the first partialorupdate children must exist and be complete.

the index to first partialorupdate children is incremented.

# class `Table` {#classTable}

```
class Table
  : public Atable< P >
```  

parse table.

table defines two main undorered mappings:

map table: 
```cpp
map key -> value 
```
 where

* key of type P = [Pointer](#classPointer)

* value of type R = [Record](#classRecord)

(stores some [Run](#classRun)

*)

* H = Hasher for P

* equal+to is op. == defined in P

table of instances: 
```cpp
multimap: key -> keys 
```
 where

* key of type P = [Pointer](#classPointer) (partial)

* keys of type P = complete [Pointer](#classPointer) instances of key

* H = Hasher for P

* equal+to is op. == defined in P

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Table`](#classTable_1a75c05943dcc9afb9ee0af010143a692e)`(`[`Parser`](#classParser)`< P > * env,RunCompare< P > comp)` | concrete table.
`public  `[`~Table`](#classTable_1a589746398a8320b124a5b19f37b9851f)`()` | 
`public virtual `[`Run`](#classRun)`< P > * `[`best`](#classTable_1a2e8c9b5856741684b1ec7d8fc640cc81)`(const P & p)` | return k-best run pointed by p or NULL if there is none. k is either included in p or the default value 1.
`public virtual `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classTable_1ace006d9777eee7bb4835f821bc5c9467)`(const P & p)` | tree corresponding to the k-best run in p.
`public virtual `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classTable_1a53788fcf01e286097b3c0d7c7573d61f)`(`[`Run`](#classRun)`< P > * r)` | when the k-best run in p is already computed.
`public `[`Record`](#classRecord)`< P > * `[`add`](#classTable_1a69ccf554edee39f61692c26a3b4667e1)`(const P & p)` | if p complete, create a new record in table for it and process it (add runs), if p partial, process it (register instances to table) with addPartial.
`public virtual size_t `[`add`](#classTable_1a9231e3b8782acfabbafe1f1dcb85a3bb)`(const P & p,`[`Run`](#classRun)`< P > * r,`[`Record`](#classRecord)`< P > * i)` | #### Parameters
`public inline virtual size_t `[`nb_entries`](#classTable_1aea047b02e7a9f2d714248903f52f5722)`()` | 
`public inline virtual size_t `[`nb_runs`](#classTable_1a8e4b509c921bf151b3601fca7704aaee)`()` | 
`public void `[`dump_table`](#classTable_1ab9f913aa0d90a65e1b70dc0a939e041c)`() const` | 
`public void `[`dump_instances`](#classTable_1a3633b7419edf39e46aaeeef580171d36)`() const` | 

## Members

#### `public  `[`Table`](#classTable_1a75c05943dcc9afb9ee0af010143a692e)`(`[`Parser`](#classParser)`< P > * env,RunCompare< P > comp)` {#classTable_1a75c05943dcc9afb9ee0af010143a692e}

concrete table.

**See also**: [Atable](#classAtable) for arguments 

#### Parameters
* `env` the parsing environment must not be NULL

#### `public  `[`~Table`](#classTable_1a589746398a8320b124a5b19f37b9851f)`()` {#classTable_1a589746398a8320b124a5b19f37b9851f}

#### `public virtual `[`Run`](#classRun)`< P > * `[`best`](#classTable_1a2e8c9b5856741684b1ec7d8fc640cc81)`(const P & p)` {#classTable_1a2e8c9b5856741684b1ec7d8fc640cc81}

return k-best run pointed by p or NULL if there is none. k is either included in p or the default value 1.

#### Parameters
* `p` must be complete.

#### `public virtual `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classTable_1ace006d9777eee7bb4835f821bc5c9467)`(const P & p)` {#classTable_1ace006d9777eee7bb4835f821bc5c9467}

tree corresponding to the k-best run in p.

#### `public virtual `[`RhythmTree`](#classRhythmTree)` * `[`bestTree`](#classTable_1a53788fcf01e286097b3c0d7c7573d61f)`(`[`Run`](#classRun)`< P > * r)` {#classTable_1a53788fcf01e286097b3c0d7c7573d61f}

when the k-best run in p is already computed.

#### `public `[`Record`](#classRecord)`< P > * `[`add`](#classTable_1a69ccf554edee39f61692c26a3b4667e1)`(const P & p)` {#classTable_1a69ccf554edee39f61692c26a3b4667e1}

if p complete, create a new record in table for it and process it (add runs), if p partial, process it (register instances to table) with addPartial.

#### Parameters
* `p` can be partial or complete. 

p must have yet no associated record in table when complete. 

p must not have been added before if partial (no registered instances). 

#### Returns
a pointer to the newly created record if p complete. 

#### Returns
a NULL pointer in this case if p partial.

#### `public virtual size_t `[`add`](#classTable_1a9231e3b8782acfabbafe1f1dcb85a3bb)`(const P & p,`[`Run`](#classRun)`< P > * r,`[`Record`](#classRecord)`< P > * i)` {#classTable_1a9231e3b8782acfabbafe1f1dcb85a3bb}

#### Parameters
* `p` can be complete or partial. 

* `r` can be complete or partial. 

* `i` if p is complete, then i must be an pointer to the entry for p in table, otherwise (p partial), i is NULL.

add possible instances of run r to the entries in table for corresp. to possible instances for p. dispatch to the four functions below according to p and r. 
#### Returns
0 if the run or one instance of the run (at least) was added to the table. 

#### Returns
> 0 otherwise.

#### `public inline virtual size_t `[`nb_entries`](#classTable_1aea047b02e7a9f2d714248903f52f5722)`()` {#classTable_1aea047b02e7a9f2d714248903f52f5722}

#### `public inline virtual size_t `[`nb_runs`](#classTable_1a8e4b509c921bf151b3601fca7704aaee)`()` {#classTable_1a8e4b509c921bf151b3601fca7704aaee}

#### `public void `[`dump_table`](#classTable_1ab9f913aa0d90a65e1b70dc0a939e041c)`() const` {#classTable_1ab9f913aa0d90a65e1b70dc0a939e041c}

#### `public void `[`dump_instances`](#classTable_1a3633b7419edf39e46aaeeef580171d36)`() const` {#classTable_1a3633b7419edf39e46aaeeef580171d36}

# struct `SpointerHasher` {#structSpointerHasher}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structSpointerHasher_1abf1bf4b8162161d2defd1ec4d65594f4)`(const `[`Spointer`](#classSpointer)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structSpointerHasher_1abf1bf4b8162161d2defd1ec4d65594f4)`(const `[`Spointer`](#classSpointer)` & p) const` {#structSpointerHasher_1abf1bf4b8162161d2defd1ec4d65594f4}

# struct `SIpointerHasher` {#structSIpointerHasher}

hash function for using as key in a table. rank is ignoreds : same as [SpointerHasher](#structSpointerHasher)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structSIpointerHasher_1ad3858671072869f875338fd56bf3cc82)`(const `[`SIpointer`](#classSIpointer)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structSIpointerHasher_1ad3858671072869f875338fd56bf3cc82)`(const `[`SIpointer`](#classSIpointer)` & p) const` {#structSIpointerHasher_1ad3858671072869f875338fd56bf3cc82}

# struct `SIPpointerHasher` {#structSIPpointerHasher}

hash function for using as key in a table rank is ignoreds : same as [SpointerHasher](#structSpointerHasher)

**See also**: [constant.h](#constant_8h_source)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structSIPpointerHasher_1a089b7f539ef0e7db325062242ee29fa0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structSIPpointerHasher_1a089b7f539ef0e7db325062242ee29fa0)`(const `[`SIPpointer`](#classSIPpointer)` & p) const` {#structSIPpointerHasher_1a089b7f539ef0e7db325062242ee29fa0}

# struct `SKpointerHasher` {#structSKpointerHasher}

hash function for using as key in a table rank is ignoreds : same as [SpointerHasher](#structSpointerHasher)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structSKpointerHasher_1a7fc8a127e77422b38e9ec5bab09718ef)`(const `[`Spointer`](#classSpointer)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structSKpointerHasher_1a7fc8a127e77422b38e9ec5bab09718ef)`(const `[`Spointer`](#classSpointer)` & p) const` {#structSKpointerHasher_1a7fc8a127e77422b38e9ec5bab09718ef}

# struct `SKIPpointerHasher` {#structSKIPpointerHasher}

hash function for using as key in a table.

rank is ignored : same as [SpointerHasher](#structSpointerHasher)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#structSKIPpointerHasher_1a5bab704b8e284d8922465e170953e3f2)`(const `[`Spointer`](#classSpointer)` & p) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#structSKIPpointerHasher_1a5bab704b8e284d8922465e170953e3f2)`(const `[`Spointer`](#classSpointer)` & p) const` {#structSKIPpointerHasher_1a5bab704b8e284d8922465e170953e3f2}

