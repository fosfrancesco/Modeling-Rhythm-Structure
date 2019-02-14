\header{ 
  title = "rhythm notations of value [ 1/4 1/4 1/2 ] (schema-02.txt)"
}

\score {
<<
\new RhythmicStaff {
\time 1/4
 {  { e16 e16 }  e8 }  \bar "||" 
\tuplet 4/2 { e8 e8 e8~ e8 }  \bar "||" 
 { \tuplet 3/2 { e16~  { e32 e32~ }  e16 }  e8 } 
 { \tuplet 3/2 { e16.  e16. }  e8 }  \bar "||" 
\tuplet 3/2 {  { e16~  { e32 e32~ }  }   { e16 e16~ }  e8 } 
\tuplet 3/2 {  { e16. e32~ }  e16 e8. }  \bar "||" 
}
>>
}

\version "2.18.2"
