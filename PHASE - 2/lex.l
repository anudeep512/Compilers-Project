%{
  #include <iostream>
  #include <string>
  #include "y.tab.h"
  extern FILE * fp;
%}

%option yylineno

/* Regular Expressions and Definations*/

/* Special Symbols */

SPECIALSYMBOL ("<<"|">>"|"("|")"|"["|"]"|"#") 

/* Constants */

/* Integer Constant */
INTEGERLIT -?[0-9]+

/* Boolean Constant */
BOOLIT ("true"|"false")

/* Float Constant */
FLOATLIT [0-9]+.[0-9]+

/* Character Constant */
CHARACTERLIT '(\\.|[^\\'])+'

/* String Constant */
STRINGLIT	\"(\\.|[^\\"])*\"

/* Whitespaces */
WHITESPACES [ \t]+

/* Newline */
NEWLINE [\n]

/* Invalid Identifier */
INVALIDID [a-zA-Z0-9_]*

%%

{SPECIALSYMBOL} {
  fprintf(fp,"Special Symbol: %s\n",yytext);
  if(!strcmp("<<",yytext)){
    return SCOPEOPEN;
  }
  if(!strcmp(">>",yytext)){
    return SCOPECLOSE;
  }
  if(!strcmp("(",yytext)){
    return ROUNDOPEN;
  }
  if(!strcmp(")",yytext)){
    return ROUNDCLOSE;
  }
  if(!strcmp("[",yytext)){
    return SQUAREOPEN;
  }
  if(!strcmp("]",yytext)){
    return SQUARECLOSE;
  }
  if(!strcmp("#",yytext)){
    return HASH;
  }
}

{INTEGERLIT} {
  fprintf(fp,"Constant: %s\n",yytext);
  return INTEGERLITERAL;
}

{CHARACTERLIT} {
  fprintf(fp,"Constant: %s\n",yytext);
  return CHARACTERLITERAL;
}

{STRINGLIT} {
  fprintf(fp,"Constant: %s\n",yytext);
  return STRINGLITERAL;
}

{FLOATLIT} {
  fprintf(fp,"Constant: %s\n",yytext);
  return FLOATLITERAL;
}

{BOOLIT} {
  fprintf(fp,"Constant: %s\n",yytext);
  return BOOLEANLITERAL;
}


{INVALIDID} {
  fprintf(fp,"Lex Error in line: %d\n Invalid Identifier: %s\n",yylineno,yytext);
  return LEXERROR;
}

{WHITESPACES} ;

{NEWLINE} ;

. {
  fprintf(fp,"Lex Error in line: %d\n Error is: %s\n",yylineno,yytext);
  return LEXERROR;
}

%%

int yywrap(void){
	return 1;
}







