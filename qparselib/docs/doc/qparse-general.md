# group `general` 

The `general` module contains reusable tools and utilities, initialization of constants, and tracing functions.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`PP_UNKNOWN`](#group__general_1ga93c3f96b8b7345e4e15965f3938e4e0c)            | 
`define `[`PP_KNOWN`](#group__general_1ga3f9e0147289a89265d742be9ea145fda)            | 
`define `[`TRACE_ON`](#group__general_1ga047013f5273eccbbfc0a08db5975f544)            | 
`define `[`DEBUG_ON`](#group__general_1ga911d91f7898a9a0c4e35bb71e01d39a0)            | 
`define `[`_TRACE_CAND`](#group__general_1ga6745ebbbc3fb31c4d8ac57a551060028)            | addition of candidates
`define `[`_TRACE_BEST`](#group__general_1ga5a81e12e5b011ad54d8ddbf6be97ef34)            | addition of best runs
`define `[`_TRACE_TBL`](#group__general_1gad8cbb5acc06d85c055ae6d66d22b6b58)            | initialization and construction of tables
`define `[`ERROR`](#group__general_1ga02ce8a968600d004ba60858425c46307)            | 
`define `[`WARN`](#group__general_1ga8f75b971030a39ef811d3526a62b36b8)            | 
`define `[`INFO`](#group__general_1gaedf01192151e10a6620567952711ff69)            | 
`define `[`TRACE`](#group__general_1ga5f6aa8edcd99914757600b5d3b259bb7)            | 
`define `[`DEBUG`](#group__general_1ga96dd473db0b3d10bd43390cdacb00120)            | 
`define `[`TRACE_CAND`](#group__general_1gab69defacb6a9bf736bb490f7f44e25c3)            | 
`define `[`TRACE_BEST`](#group__general_1gaf4ce41dddbcee02dfa738a7d421e8037)            | 
`define `[`TRACE_TBL`](#group__general_1ga822ec6b7ee1991956603623096cb09b2)            | 
`enum `[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560)            | weight types
`public double `[`duration`](#group__general_1ga8ea30422b6f53a4d8e502ab0a1406dff)`(clock_t start)`            | 
`public int `[`read_config`](#group__general_1gaef0eb8293c9f09a03e431fa23dea831d)`(const std::string filename)`            | read the constant and optimisation flag values in a config file INI file, see [https://en.wikipedia.org/wiki/INI_file](https://en.wikipedia.org/wiki/INI_file) return 0 if reading the values succeded -1 in case of file open error or a number of line in case of parse error in .ini file.
`public std::ostream & `[`operator<<`](#group__general_1ga7a50522782b1a61b37d5f1b3adceed4a)`(std::ostream & o,const `[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560)` & t)`            | 
`public long `[`virtual_memory_size`](#group__general_1ga3cef5c0e66f31aac9e01e5dfd9f3edc7)`()`            | Here we check that the compile flags are set and correct: QP_PLATFORM = PLATFORM_xxx QP_TARGET = TARGET_xxx where the possibles values for PLATFORM_xxx (target platform) and TARGET_xxx (executable) are defined by compiler flags.
`public long `[`resident_memory_size`](#group__general_1gab4d9195d8e5dc86aa14c1eea0535d806)`()`            | 
`public const `[`Rational`](#classRational)` `[`operator+`](#group__general_1gaa0f924144ded8d6509d5d349195b00a8)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` `[`operator-`](#group__general_1ga46d4a6e5db46addfa0d0608e3266571b)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` `[`operator*`](#group__general_1ga0334562ad4831b5b35238fe58bddabb0)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` `[`operator/`](#group__general_1gac87738e39a4f47b27c620375a59b06ee)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public `[`Rational`](#classRational)` `[`rabs`](#group__general_1ga3a2f2c8e28386a081128d450e66999dd)`(const `[`Rational`](#classRational)` & r)`            | 
`public bool `[`operator==`](#group__general_1ga436606f8682952468f6a5b339d972178)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public bool `[`operator!=`](#group__general_1gaca39bd2856e9682cf97234d046c0d52f)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public bool `[`operator<`](#group__general_1gaf34fe75e417e48c51e1d2751d9264569)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public bool `[`operator>`](#group__general_1ga8ae410bb40221ea8f30a6057dff05a1f)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public bool `[`operator<=`](#group__general_1ga7b99e5d0faa3459356ab1249e3315ceb)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public bool `[`operator>=`](#group__general_1gac1e651cdae26413046d477efdaef0539)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)`            | 
`public std::ostream & `[`operator<<`](#group__general_1ga5cf9ab392de156c39a5a115c9b30607b)`(std::ostream & ostr,const `[`Rational`](#classRational)` & r)`            | 
`public std::istream & `[`operator>>`](#group__general_1gaa682331c9d58a26ba320d6414d396a9f)`(std::istream & istr,`[`Rational`](#classRational)` & r)`            | 
`public static `[`Rational`](#classRational)` `[`toRational`](#group__general_1gaf481924a0c90c92bbd4b49979e1bd83f)`(double x,double limit,int iterations)`            | 
`public `[`Rational`](#classRational)` `[`toRational`](#group__general_1ga0bfbe45cc727920e5a74e3a75ab2e6b9)`(double x,int iterations)`            | double -> [Rational](doc/qparse-general.md#classRational) conversion
`public inline double `[`toDouble`](#group__general_1ga95b1b3230673ab78c01058a88a5e3eae)`(const `[`Rational`](#classRational)` & r)`            | [Rational](doc/qparse-general.md#classRational) -> double conversion.
`public inline long `[`trunc`](#group__general_1ga2ae32e90a2bacd18ca646568cb6c456e)`(const `[`Rational`](#classRational)` & r)`            | [Rational](doc/qparse-general.md#classRational) -> long conversions.
`public inline long `[`floor`](#group__general_1gab93ceb248e49c0c1bdf83bee735aea49)`(const `[`Rational`](#classRational)` & r)`            | 
`public inline long `[`ceil`](#group__general_1ga883dcb56e5cb54c652d0eb4e939fd066)`(const `[`Rational`](#classRational)` & r)`            | 
`public  `[`Rational`](#group__general_1ga664c91d4ee5ad46c39e765e6dbf81738)`(long n,long d)`            | default constructor
`public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gaa857f0a929a6898f30b97ba00c463ae6)`(const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gada510c5ee2bbcc7d7f12b8f25b539eff)`(long rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga196f4fcc358d405bbd98a7248bfc75f5)`(const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga33cc7c599a1a3ac9a13bfe104c4456f4)`(long rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1ga17205b7127a763b3eaf44f6fecaac50b)`(const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1gae50b290ade4698dd865cd451c3c23dda)`(long rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa9902842b5b7724cd307b5770a75b0c7)`(const `[`Rational`](#classRational)` & rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa6627aa1f4524568c059b8914b2665bc)`(long rhs)`            | 
`public const `[`Rational`](#classRational)` & `[`operator++`](#group__general_1ga23e1bd04a616269e833eabf12ebb247b)`()`            | 
`public const `[`Rational`](#classRational)` `[`operator++`](#group__general_1gace6087d7c3382a18099dda188d1e5d9c)`(int)`            | 
`public const `[`Rational`](#classRational)` & `[`operator--`](#group__general_1ga46aa465b7b59fbdbc5abff452a713b3c)`()`            | 
`public const `[`Rational`](#classRational)` `[`operator--`](#group__general_1ga45c0bd14078313e6ff7be68dd612efa1)`(int)`            | 
`private long `[`gcd`](#group__general_1gac33fc7df4637c732fa9c9f9ff0ddce95)`(long,long)`            | auxillary helper function to normalize the rationals
`public void `[`printint`](#group__general_1ga11edcb2aed3334c33c9e962be2bda2fe)`(std::ostream &) const`            | print in format int+rat
`public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga1f7f9f9491bbe7f24c488a505ac6887c)`(const `[`Rational`](#classRational)` & rhs)`            | assignment operators
`public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga019d7a6ea6fb10e582310ae8f00a121c)`(long rhs)`            | 
`namespace `[`std`](#namespacestd) | 
`class `[`Rational`](doc/qparse-general.md#classRational) | class of rational numbers

## Members

#### `define `[`PP_UNKNOWN`](#group__general_1ga93c3f96b8b7345e4e15965f3938e4e0c) 

#### `define `[`PP_KNOWN`](#group__general_1ga3f9e0147289a89265d742be9ea145fda) 

#### `define `[`TRACE_ON`](#group__general_1ga047013f5273eccbbfc0a08db5975f544) 

#### `define `[`DEBUG_ON`](#group__general_1ga911d91f7898a9a0c4e35bb71e01d39a0) 

#### `define `[`_TRACE_CAND`](#group__general_1ga6745ebbbc3fb31c4d8ac57a551060028) 

addition of candidates

#### `define `[`_TRACE_BEST`](#group__general_1ga5a81e12e5b011ad54d8ddbf6be97ef34) 

addition of best runs

#### `define `[`_TRACE_TBL`](#group__general_1gad8cbb5acc06d85c055ae6d66d22b6b58) 

initialization and construction of tables

#### `define `[`ERROR`](#group__general_1ga02ce8a968600d004ba60858425c46307) 

#### `define `[`WARN`](#group__general_1ga8f75b971030a39ef811d3526a62b36b8) 

#### `define `[`INFO`](#group__general_1gaedf01192151e10a6620567952711ff69) 

#### `define `[`TRACE`](#group__general_1ga5f6aa8edcd99914757600b5d3b259bb7) 

#### `define `[`DEBUG`](#group__general_1ga96dd473db0b3d10bd43390cdacb00120) 

#### `define `[`TRACE_CAND`](#group__general_1gab69defacb6a9bf736bb490f7f44e25c3) 

#### `define `[`TRACE_BEST`](#group__general_1gaf4ce41dddbcee02dfa738a7d421e8037) 

#### `define `[`TRACE_TBL`](#group__general_1ga822ec6b7ee1991956603623096cb09b2) 

#### `enum `[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
UNDEF            | 
PENALTY            | to be specified
STOCHASTIC            | tropical semiring
COUNTING            | Viterbi semiring.

weight types

#### `public double `[`duration`](#group__general_1ga8ea30422b6f53a4d8e502ab0a1406dff)`(clock_t start)` 

#### `public int `[`read_config`](#group__general_1gaef0eb8293c9f09a03e431fa23dea831d)`(const std::string filename)` 

read the constant and optimisation flag values in a config file INI file, see [https://en.wikipedia.org/wiki/INI_file](https://en.wikipedia.org/wiki/INI_file) return 0 if reading the values succeded -1 in case of file open error or a number of line in case of parse error in .ini file.

#### `public std::ostream & `[`operator<<`](#group__general_1ga7a50522782b1a61b37d5f1b3adceed4a)`(std::ostream & o,const `[`WeightDom`](#group__general_1gae07bdce6f4896785ead3b815ca6ab560)` & t)` 

#### `public long `[`virtual_memory_size`](#group__general_1ga3cef5c0e66f31aac9e01e5dfd9f3edc7)`()` 

Here we check that the compile flags are set and correct: QP_PLATFORM = PLATFORM_xxx QP_TARGET = TARGET_xxx where the possibles values for PLATFORM_xxx (target platform) and TARGET_xxx (executable) are defined by compiler flags.

in Xcode, the flags are defined.

#### `public long `[`resident_memory_size`](#group__general_1gab4d9195d8e5dc86aa14c1eea0535d806)`()` 

#### `public const `[`Rational`](#classRational)` `[`operator+`](#group__general_1gaa0f924144ded8d6509d5d349195b00a8)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` `[`operator-`](#group__general_1ga46d4a6e5db46addfa0d0608e3266571b)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` `[`operator*`](#group__general_1ga0334562ad4831b5b35238fe58bddabb0)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` `[`operator/`](#group__general_1gac87738e39a4f47b27c620375a59b06ee)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public `[`Rational`](#classRational)` `[`rabs`](#group__general_1ga3a2f2c8e28386a081128d450e66999dd)`(const `[`Rational`](#classRational)` & r)` 

#### `public bool `[`operator==`](#group__general_1ga436606f8682952468f6a5b339d972178)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public bool `[`operator!=`](#group__general_1gaca39bd2856e9682cf97234d046c0d52f)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public bool `[`operator<`](#group__general_1gaf34fe75e417e48c51e1d2751d9264569)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public bool `[`operator>`](#group__general_1ga8ae410bb40221ea8f30a6057dff05a1f)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public bool `[`operator<=`](#group__general_1ga7b99e5d0faa3459356ab1249e3315ceb)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public bool `[`operator>=`](#group__general_1gac1e651cdae26413046d477efdaef0539)`(const `[`Rational`](#classRational)` & lhs,const `[`Rational`](#classRational)` & rhs)` 

#### `public std::ostream & `[`operator<<`](#group__general_1ga5cf9ab392de156c39a5a115c9b30607b)`(std::ostream & ostr,const `[`Rational`](#classRational)` & r)` 

#### `public std::istream & `[`operator>>`](#group__general_1gaa682331c9d58a26ba320d6414d396a9f)`(std::istream & istr,`[`Rational`](#classRational)` & r)` 

#### `public static `[`Rational`](#classRational)` `[`toRational`](#group__general_1gaf481924a0c90c92bbd4b49979e1bd83f)`(double x,double limit,int iterations)` 

#### `public `[`Rational`](#classRational)` `[`toRational`](#group__general_1ga0bfbe45cc727920e5a74e3a75ab2e6b9)`(double x,int iterations)` 

double -> [Rational](#classRational) conversion

#### `public inline double `[`toDouble`](#group__general_1ga95b1b3230673ab78c01058a88a5e3eae)`(const `[`Rational`](#classRational)` & r)` 

[Rational](#classRational) -> double conversion.

#### `public inline long `[`trunc`](#group__general_1ga2ae32e90a2bacd18ca646568cb6c456e)`(const `[`Rational`](#classRational)` & r)` 

[Rational](#classRational) -> long conversions.

#### `public inline long `[`floor`](#group__general_1gab93ceb248e49c0c1bdf83bee735aea49)`(const `[`Rational`](#classRational)` & r)` 

#### `public inline long `[`ceil`](#group__general_1ga883dcb56e5cb54c652d0eb4e939fd066)`(const `[`Rational`](#classRational)` & r)` 

#### `public  `[`Rational`](#group__general_1ga664c91d4ee5ad46c39e765e6dbf81738)`(long n,long d)` 

default constructor

#### `public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gaa857f0a929a6898f30b97ba00c463ae6)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gada510c5ee2bbcc7d7f12b8f25b539eff)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga196f4fcc358d405bbd98a7248bfc75f5)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga33cc7c599a1a3ac9a13bfe104c4456f4)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1ga17205b7127a763b3eaf44f6fecaac50b)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1gae50b290ade4698dd865cd451c3c23dda)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa9902842b5b7724cd307b5770a75b0c7)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa6627aa1f4524568c059b8914b2665bc)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator++`](#group__general_1ga23e1bd04a616269e833eabf12ebb247b)`()` 

#### `public const `[`Rational`](#classRational)` `[`operator++`](#group__general_1gace6087d7c3382a18099dda188d1e5d9c)`(int)` 

#### `public const `[`Rational`](#classRational)` & `[`operator--`](#group__general_1ga46aa465b7b59fbdbc5abff452a713b3c)`()` 

#### `public const `[`Rational`](#classRational)` `[`operator--`](#group__general_1ga45c0bd14078313e6ff7be68dd612efa1)`(int)` 

#### `private long `[`gcd`](#group__general_1gac33fc7df4637c732fa9c9f9ff0ddce95)`(long,long)` 

auxillary helper function to normalize the rationals

#### `public void `[`printint`](#group__general_1ga11edcb2aed3334c33c9e962be2bda2fe)`(std::ostream &) const` 

print in format int+rat

#### `public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga1f7f9f9491bbe7f24c488a505ac6887c)`(const `[`Rational`](#classRational)` & rhs)` 

assignment operators

#### `public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga019d7a6ea6fb10e582310ae8f00a121c)`(long rhs)` 

# namespace `std` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`std::hash< Rational >`](doc/qparse-general.md#classstd_1_1hash_3_01Rational_01_4) | 

# class `std::hash< Rational >` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline std::size_t `[`operator()`](#classstd_1_1hash_3_01Rational_01_4_1a3eafa9680a4c7978171d32ca8d2bbf9e)`(const `[`Rational`](#classRational)` & x) const` | 

## Members

#### `public inline std::size_t `[`operator()`](#classstd_1_1hash_3_01Rational_01_4_1a3eafa9680a4c7978171d32ca8d2bbf9e)`(const `[`Rational`](#classRational)` & x) const` 

# class `Rational` 

class of rational numbers

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Rational`](#classRational_1a3bbd6ff67c590da76ddfcbd48cd3de0a)`()` | 
`public  `[`Rational`](#group__general_1ga664c91d4ee5ad46c39e765e6dbf81738)`(long n,long d)` | default constructor
`public inline  `[`Rational`](#classRational_1a6b1b6f2daa26e70c89c9af95ccd8db9f)`(const `[`Rational`](#classRational)` & rhs)` | copy constructor
`public inline  `[`~Rational`](#classRational_1a3600b7a387a12c5ef3d8a2a34ebffc8d)`(void)` | 
`public inline long `[`numerator`](#classRational_1a72439b140815591f5d970494602bb5ad)`(void) const` | 
`public inline long `[`denominator`](#classRational_1a291c66d689ce98e62a14babdd12894d8)`(void) const` | 
`public inline bool `[`null`](#classRational_1a53d55d82fbde5bdd6deb7f7ff4310f92)`(void) const` | 
`public inline bool `[`integral`](#classRational_1a1961c2ea3ed798d2c77a1294fa448164)`(void) const` | 
`public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga1f7f9f9491bbe7f24c488a505ac6887c)`(const `[`Rational`](#classRational)` & rhs)` | assignment operators
`public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga019d7a6ea6fb10e582310ae8f00a121c)`(long rhs)` | 
`public inline `[`Rational`](#classRational)` `[`operator+`](#classRational_1a25ae5a95c48b8108c3c1337cec68b425)`(void) const` | 
`public inline `[`Rational`](#classRational)` `[`operator-`](#classRational_1a86b979ead01c9c4af10808259f86750d)`(void) const` | 
`public inline `[`Rational`](#classRational)` `[`invert`](#classRational_1ab2bd5760859089e81eb3d6ed98341432)`(void) const` | 
`public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gaa857f0a929a6898f30b97ba00c463ae6)`(const `[`Rational`](#classRational)` & rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga196f4fcc358d405bbd98a7248bfc75f5)`(const `[`Rational`](#classRational)` & rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1ga17205b7127a763b3eaf44f6fecaac50b)`(const `[`Rational`](#classRational)` & rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa9902842b5b7724cd307b5770a75b0c7)`(const `[`Rational`](#classRational)` & rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gada510c5ee2bbcc7d7f12b8f25b539eff)`(long rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga33cc7c599a1a3ac9a13bfe104c4456f4)`(long rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1gae50b290ade4698dd865cd451c3c23dda)`(long rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa6627aa1f4524568c059b8914b2665bc)`(long rhs)` | 
`public const `[`Rational`](#classRational)` & `[`operator++`](#group__general_1ga23e1bd04a616269e833eabf12ebb247b)`()` | 
`public const `[`Rational`](#classRational)` `[`operator++`](#group__general_1gace6087d7c3382a18099dda188d1e5d9c)`(int)` | 
`public const `[`Rational`](#classRational)` & `[`operator--`](#group__general_1ga46aa465b7b59fbdbc5abff452a713b3c)`()` | 
`public const `[`Rational`](#classRational)` `[`operator--`](#group__general_1ga45c0bd14078313e6ff7be68dd612efa1)`(int)` | 
`public void `[`printint`](#group__general_1ga11edcb2aed3334c33c9e962be2bda2fe)`(std::ostream &) const` | print in format int+rat

## Members

#### `public inline  `[`Rational`](#classRational_1a3bbd6ff67c590da76ddfcbd48cd3de0a)`()` 

#### `public  `[`Rational`](#group__general_1ga664c91d4ee5ad46c39e765e6dbf81738)`(long n,long d)` 

default constructor

#### `public inline  `[`Rational`](#classRational_1a6b1b6f2daa26e70c89c9af95ccd8db9f)`(const `[`Rational`](#classRational)` & rhs)` 

copy constructor

#### `public inline  `[`~Rational`](#classRational_1a3600b7a387a12c5ef3d8a2a34ebffc8d)`(void)` 

#### `public inline long `[`numerator`](#classRational_1a72439b140815591f5d970494602bb5ad)`(void) const` 

#### `public inline long `[`denominator`](#classRational_1a291c66d689ce98e62a14babdd12894d8)`(void) const` 

#### `public inline bool `[`null`](#classRational_1a53d55d82fbde5bdd6deb7f7ff4310f92)`(void) const` 

#### `public inline bool `[`integral`](#classRational_1a1961c2ea3ed798d2c77a1294fa448164)`(void) const` 

#### `public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga1f7f9f9491bbe7f24c488a505ac6887c)`(const `[`Rational`](#classRational)` & rhs)` 

assignment operators

#### `public inline `[`Rational`](#classRational)` & `[`operator=`](#group__general_1ga019d7a6ea6fb10e582310ae8f00a121c)`(long rhs)` 

#### `public inline `[`Rational`](#classRational)` `[`operator+`](#classRational_1a25ae5a95c48b8108c3c1337cec68b425)`(void) const` 

#### `public inline `[`Rational`](#classRational)` `[`operator-`](#classRational_1a86b979ead01c9c4af10808259f86750d)`(void) const` 

#### `public inline `[`Rational`](#classRational)` `[`invert`](#classRational_1ab2bd5760859089e81eb3d6ed98341432)`(void) const` 

#### `public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gaa857f0a929a6898f30b97ba00c463ae6)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga196f4fcc358d405bbd98a7248bfc75f5)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1ga17205b7127a763b3eaf44f6fecaac50b)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa9902842b5b7724cd307b5770a75b0c7)`(const `[`Rational`](#classRational)` & rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator+=`](#group__general_1gada510c5ee2bbcc7d7f12b8f25b539eff)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator-=`](#group__general_1ga33cc7c599a1a3ac9a13bfe104c4456f4)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator*=`](#group__general_1gae50b290ade4698dd865cd451c3c23dda)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator/=`](#group__general_1gaa6627aa1f4524568c059b8914b2665bc)`(long rhs)` 

#### `public const `[`Rational`](#classRational)` & `[`operator++`](#group__general_1ga23e1bd04a616269e833eabf12ebb247b)`()` 

#### `public const `[`Rational`](#classRational)` `[`operator++`](#group__general_1gace6087d7c3382a18099dda188d1e5d9c)`(int)` 

#### `public const `[`Rational`](#classRational)` & `[`operator--`](#group__general_1ga46aa465b7b59fbdbc5abff452a713b3c)`()` 

#### `public const `[`Rational`](#classRational)` `[`operator--`](#group__general_1ga45c0bd14078313e6ff7be68dd612efa1)`(int)` 

#### `public void `[`printint`](#group__general_1ga11edcb2aed3334c33c9e962be2bda2fe)`(std::ostream &) const` 

print in format int+rat

