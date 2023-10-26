%{
  #include <iostream>
  #include <string>
  #include "y.tab.h"
%}

/* Regular Expressions and Definations*/

/* Special Symbols */

SPECIALSYMBOL ("<<"|">>"|"("|")"|"["|"]"|"#") 
INTEGERLITERAL [0-9]+








