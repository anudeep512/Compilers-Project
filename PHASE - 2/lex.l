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
INTEGERLIT [0-9]+

/* Character Constant */
ESCAPE_SEQUENCE				[\\n\\t]
C_CHAR 						{ESCAPE_SEQUENCE}|[^("\'"|"\\"|"\n")]
C_CHAR_SEQUENCE				{C_CHAR}+
CHARACTERLIT			'{C_CHAR_SEQUENCE}'

/* String Constant */
S_CHAR  					[^("\\""|"\\"|"\n")]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE				{S_CHAR}+
STRINGLIT				\"({S_CHAR_SEQUENCE}?)\"

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







