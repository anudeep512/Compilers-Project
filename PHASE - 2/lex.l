%{
  #include <iostream>
  #include <string>
  #include "y.tab.h"
  extern FILE * fp;
%}

%option yylineno

/* Regular Expressions and Definations*/

/* Datatypes*/
PRIMITIVE "void"|"number"|"decimal"|"letter"|"text"|"bool"
ATOMIC_PRIMITIVE "atomic number"|"atomic decimal"|"atomic letter"|"atomic text"|"atomic bool"
ARRAY "array "{PRIMITIVE}
ATOMIC_ARRAY "atomic array number"|"atomic array decimal"|"atomic array letter"|"atomic array text"|"atomic array bool"

/* Special Symbols */

SPECIALSYMBOL ("<<"|">>"|"("|")"|"["|"]"|"#") 

/* Constants */

/* Integer Constant */
INTEGERLIT -?[0-9]+

/* Boolean Constant */
BOOLIT ("true"|"false")

/* Float Constant */
FLOATLIT -?[0-9]+.[0-9]+

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

{PRIMITIVE} {
    if(strcmp(yytext, "number") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NNUM;}
    if(strcmp(yytext, "decimal") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NDEC;}
    if(strcmp(yytext, "boolean") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NBOOL;}
    if(strcmp(yytext, "letter") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NLET;}
    if(strcmp(yytext, "text") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NTEXT;}
    if(strcmp(yytext, "void") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NVOID;}
}

{ATOMIC_PRIMITIVE} {
    if(strcmp(yytext, "atomic number") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NNUM;}
    if(strcmp(yytext, "atomic decimal") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NDEC;}
    if(strcmp(yytext, "atomic boolean") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NBOOL;}
    if(strcmp(yytext, "atomic letter") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NLET;}
    if(strcmp(yytext, "atomic text") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NTEXT;}
}

{ARRAY} {
    if(strcmp(yytext, "array void") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NNUM;}
    if(strcmp(yytext, "array number") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NNUM;}
    if(strcmp(yytext, "array decimal") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NDEC;}
    if(strcmp(yytext, "array boolean") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NBOOL;}
    if(strcmp(yytext, "array letter") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NLET;}
    if(strcmp(yytext, "array text") == 0) {fprintf(fp,"inbuilt datatype: %s\n", yytext); return NTEXT;}
}

{ATOMIC_ARRAY} {
    if(strcmp(yytext, "atomic array number") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NNUM;}
    if(strcmp(yytext, "atomic array decimal") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NDEC;}
    if(strcmp(yytext, "atomic array boolean") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NBOOL;}
    if(strcmp(yytext, "atomic array letter") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NLET;}
    if(strcmp(yytext, "atomic array text") == 0) {fprintf(fp,"atomic inbuilt datatype: %s\n", yytext); return NTEXT;}
}

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







