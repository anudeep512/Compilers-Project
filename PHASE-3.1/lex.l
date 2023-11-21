%{
  #include <iostream>
  #include <unordered_set>
  #include <string>
  #include "bison.tab.h"

  extern FILE* fp;

  int chkType = 0; // to track if the encountered token is type or not
  int chkAtomic = 0;
  int chkArray = 0;
  std::unordered_set<std::string> userdefined;
%}

%option yylineno

/* REGULAR EXPRESSIONS AND DEFINITIONS*/

/*RESERVED KEYWORDS*/
KEYWORD_1               "when"|"repeat"|"else when"|"default"|"for"|"break"|"continue"
KEYWORD_2               "task"|"make parallel"|"null"|"tid"|"analyze"|"get"|"sleep"|"time"
KEYWORD_3               "start"|"return"|"type"|"atomic"|"array"|"in"|"func"|"invoke"|"ip"|"op" 
KEYWORD 			      {KEYWORD_1}|{KEYWORD_2}|{KEYWORD_3}


/*DATATYPES*/
PRIMITIVE "void"|"number"|"decimal"|"letter"|"text"|"bool"
ATOMIC_PRIMITIVE "atomic number"|"atomic decimal"|"atomic letter"|"atomic text"|"atomic bool"
ARRAY "array "{PRIMITIVE}
ATOMIC_ARRAY "atomic array number"|"atomic array decimal"|"atomic array letter"|"atomic array text"|"atomic array bool"


/*PUNCTUATION*/
PUNCTUATIONS [,;:]

/*CONSTANTS*/
/* Integer Constant */
DIGIT [0-9]
INTEGERLIT -?[0-9]+

/* Boolean Constant */
BOOLIT ("true"|"false")

/* Float Constant */
FLOATLIT -?[0-9]+"."[0-9]+

/* Character Constant */
CHARACTERLIT '(\\.|[^\\'])+'

/* String Constant */
STRINGLIT	\"(\\.|[^\\"])*\"



/*OPERATORS*/
ARITHMETIC_OP           "/"|"*"|"+"|"-"|"^"|"%"
ACCESS_OP               "->"
ASSGN_OP                "+="|"-="|"^="|"*="|"/="|"%="|"="
LOGICAL_OP              "&&"|"||"
RELATIONAL_OP           "<"|">"|"<="|">="|"=="|"!="|"~"
OPERATOR                {ARITHMETIC_OP}|{ASSGN_OP}|{ACCESS_OP}|{LOGICAL_OP}|{RELATIONAL_OP}



/*IDENTIFIERS*/
/*Numbers*/

/*Alphabets from English*/
ALPHABET                   [a-zA-Z]

/*A special symbol underscore*/
UNDERSCORE "_"

/*Identifier*/
IDENTIFIER_ALPHABET        {ALPHABET}|{UNDERSCORE}
ID                 {IDENTIFIER_ALPHABET}({IDENTIFIER_ALPHABET}|{DIGIT})*

/* INVALID IDENTIFIERS */
INVALIDID [a-zA-Z0-9_]*


/*SPECIAL SYMBOLS*/
SPECIALSYMBOL ("<<"|">>"|"("|")"|"["|"]"|"#"|"|") 



/*WHITESPACES*/
WHITESPACES [ \t]+


/*NEWLINE*/
NEWLINE [\n]

/*Comments*/
SINGLE_LINE_COMMENT        "$$".*
MULTI_LINE_COMMENT         "$*"([^"*$"]|[\n])*"*$" 
COMMENTS                   ({SINGLE_LINE_COMMENT}|{MULTI_LINE_COMMENT})


%%


{KEYWORD}		{
  yylval.attr.token = strdup(yytext);
	fprintf(fp, "reserved keyword: %s\n", yytext);
  fprintf(yyout, "%s", yytext);

  if(strcmp(yytext,"when") == 0) { return WHEN; }
	if(strcmp(yytext,"repeat") == 0) { return REPEAT; }
	if(strcmp(yytext,"else when") == 0) { return ELSE_WHEN; }
	if(strcmp(yytext,"default") == 0) { return DEFAULT; }
	if(strcmp(yytext,"for") == 0) { return FOR; }
	if(strcmp(yytext,"break") == 0) { return BREAK; }
	if(strcmp(yytext,"continue") == 0) { return CONTINUE; }
	if(strcmp(yytext,"task") == 0) { return TASK; }
	if(strcmp(yytext,"make parallel") == 0) { return MAKE_PARALLEL; }
	if(strcmp(yytext,"null") == 0) { return NULL_ARGS; }
	if(strcmp(yytext,"tid") == 0) { return TID; }
	if(strcmp(yytext,"analyze") == 0) { return ANALYZE; }
	if(strcmp(yytext,"get") == 0) { return GET; }
	if(strcmp(yytext,"sleep") == 0) { return SLEEP; }
	if(strcmp(yytext,"time") == 0) { return TIME; }
	if(strcmp(yytext,"start") == 0) { return START; }
	if(strcmp(yytext,"return") == 0) { return RETURN; }
	if(strcmp(yytext,"type") == 0) { 
        chkType = 1;
        return TYPE; 
    }
	if(strcmp(yytext,"atomic") == 0) { 
        chkAtomic = 1;
        return ATOMIC;
    }
  if(strcmp(yytext, "array") == 0)
  {
    chkArray = 1;
    return ARRAY;
  }
	if(strcmp(yytext,"in") == 0) { return IN; }
	if(strcmp(yytext,"func") == 0) { return FUNC; }
	if(strcmp(yytext,"invoke") == 0) { return INVOKE; }
	if(strcmp(yytext,"ip") == 0) { return IP; }
	if(strcmp(yytext,"op") == 0) { return OP; }
}


 /*DATATYPES*/
{PRIMITIVE} {
    yylval.attr.is_array = false;
    yylval.attr.is_atomic = false;
    yylval.attr.datatype = strdup(yytext);

    if(!strcmp(yytext, "number")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext); fprintf(yyout, "%s", yytext);
 return NNUM;
    }
    if(!strcmp(yytext, "decimal")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
 return NDEC;
    }
    if(!strcmp(yytext, "bool")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
 return NBOOL;
    }
    if(!strcmp(yytext, "letter")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
 return NLET;
    }
    if(!strcmp(yytext, "text")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
 return NTEXT;
    }
    if(!strcmp(yytext, "void")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
 return NVOID;
    }
}

{ATOMIC_PRIMITIVE} {
  yylval.attr.is_array = false;
  yylval.attr.is_atomic = true;
    if(!strcmp(yytext, "atomic number")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("number");
 return ANUM;
    }
    if(!strcmp(yytext, "atomic decimal")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("decimal");
 return ADEC;
    }
    if(!strcmp(yytext, "atomic bool")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("bool");
 return ABOOL;
    }
    if(!strcmp(yytext, "atomic letter")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("letter");
 return ALET;
    }
    if(!strcmp(yytext, "atomic text")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("text");
 return ATEXT;
    }
}

{ARRAY} {
    yylval.attr.is_array = true;
    yylval.attr.is_atomic = false;
    if(!strcmp(yytext, "array number")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("number");
 return NARRNUM;
    }
    if(!strcmp(yytext, "array decimal")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("decimal");
 return NARRDEC;
    }
    if(!strcmp(yytext, "array bool")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("bool");
 return NARRBOOL;
    }
    if(!strcmp(yytext, "array letter")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("letter");
 return NARRLET;
    }
    if(!strcmp(yytext, "array text")){
      fprintf(fp,"inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("text");
 return NARRTEXT;
    }
}

{ATOMIC_ARRAY} {
  yylval.attr.is_array = true;
  yylval.attr.is_atomic = true;
    if(!strcmp(yytext, "atomic array number")){
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("number");
 return AARRNUM;
    }
    if(!strcmp(yytext, "atomic array decimal")) {
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("decimal");
 return AARRDEC;
    }
    if(!strcmp(yytext, "atomic array bool")) {
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("bool");
 return AARRBOOL;
    }
    if(!strcmp(yytext, "atomic array letter")) {
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("letter");
 return AARRLET;
    }
    if(!strcmp(yytext, "atomic array text")) {
      fprintf(fp,"atomic inbuilt datatype: %s\n", yytext);fprintf(yyout, "%s", yytext);
      yylval.attr.datatype = strdup("text");
 return AARRTEXT;
    }
}



 /*PUNCTUATION*/
{PUNCTUATIONS} {
  yylval.attr.token = strdup(yytext);
fprintf(fp,"PUNCTUATION: %s\n",yytext);fprintf(yyout, "%s", yytext);

if(strcmp(yytext,",") ==0){ return COMMA;}
else if(strcmp(yytext,";") ==0){ return SEMICOLON;}
else if(strcmp(yytext,":") ==0){ return COLON;}
}

 /*CONSTANTS*/
{INTEGERLIT} {
  yylval.attr.intVal = std::stoi(strdup(yytext));
  fprintf(fp,"Constant: %s\n",yytext);fprintf(yyout, "%s", yytext);

  return INTEGERLITERAL;
}

{CHARACTERLIT} {
  yylval.attr.charVal = yytext[2];
  fprintf(fp,"Constant: %s\n",yytext);fprintf(yyout, "%s", yytext);

  return CHARACTERLITERAL;
}

{STRINGLIT} {
  yylval.attr.stringVal = strdup(yytext);
  fprintf(fp,"Constant: %s\n",yytext);fprintf(yyout, "%s", yytext);

  return STRINGLITERAL;
}

{FLOATLIT} {
  yylval.attr.decVal = std::stof(strdup(yytext));
  fprintf(fp,"Constant: %s\n",yytext);fprintf(yyout, "%s", yytext);

  return FLOATLITERAL;
}

{BOOLIT} {
  if(!strcmp(yytext, "true"))
  {
    yylval.attr.boolVal = true;
  }

  else if(!strcmp(yytext, "false"))
  {
    yylval.attr.boolVal = false;
  }

  fprintf(fp,"Constant: %s\n",yytext);fprintf(yyout, "%s", yytext);

  return BOOLEANLITERAL;
}


 /* OPERATORS */
{OPERATOR} 		{
  yylval.attr.token = strdup(yytext);
	fprintf(fp, "operator: %s\n", yytext);
  fprintf(yyout, "%s", yytext);

	if(strcmp(yytext,"/") == 0) { return DIV; }
	if(strcmp(yytext,"*") == 0) { return MUL; }
	if(strcmp(yytext,"+") == 0) { return ADD; }
	if(strcmp(yytext,"-") == 0) { return SUB; }
	if(strcmp(yytext,"^") == 0) { return EXPONENT; }
	if(strcmp(yytext,"%") == 0) { return MODULO; }
	if(strcmp(yytext,"->") == 0) { return ARROW; }
	if(strcmp(yytext,"+=") == 0) { return INCR; }
	if(strcmp(yytext,"-=") == 0) { return DECR; }
	if(strcmp(yytext,"*=") == 0) { return ASSN_MUL; }
	if(strcmp(yytext,"^=") == 0) { return ASSN_EXPONENT; }
	if(strcmp(yytext,"/=") == 0) { return ASSN_DIV; }
	if(strcmp(yytext,"=") == 0) { return EQ; }
	if(strcmp(yytext,"%=") == 0) { return ASSN_MODULO; }
	if(strcmp(yytext,"&&") == 0) { return AND; }
	if(strcmp(yytext,"||") == 0) { return OR; }
	if(strcmp(yytext,"<") == 0) { return LT; }
	if(strcmp(yytext,">") == 0) { return GT; }
	if(strcmp(yytext,">=") == 0) { return GTEQ; }
	if(strcmp(yytext,"<=") == 0) { return LTEQ; }
	if(strcmp(yytext,"==") == 0) { return EQUAL_TWO; }
	if(strcmp(yytext,"!=") == 0) { return NOT_EQ; }
	if(strcmp(yytext,"~") == 0) { return NEG; }
}

 /*IDENTIFIERS*/
{ID} {
  char *x = strdup(yytext);
  std::string y = std::string(x);

  if(chkType == 1)
  {
    fprintf(fp, "Userdefined Datatype: %s\n", x);
    fprintf(yyout, "%s", x);
    // Type name should be considered as a token, not a datatype as of now.
    // The ones declared in the scopes will be rendered as DATATYPE values.
    yylval.attr.token = strdup(yytext);
    userdefined.insert(y);
    chkType = 0;
    return TYPENAME;
  }

  else if(userdefined.find(y) == userdefined.end())
  {
    fprintf(fp, "Identifier: %s\n", x);
    fprintf(yyout, "%s", yytext);

    // This is an identifier, so will be copied to the ID attribute.
    yylval.attr.ID = strdup(yytext);
    return IDENTIFIER;
  }


  else
  {
    // Below all will be rendered in datatype attributes
    yylval.attr.datatype = strdup(yytext);
    if(userdefined.find(y) != userdefined.end() && chkArray == 1 && chkAtomic == 1)
    {
      yylval.attr.is_atomic = true;
      yylval.attr.is_array = true;
      fprintf(fp, "Userdefined Datatype: %s\n", x); fprintf(yyout, "%s", x);
      chkArray = 0;
      chkAtomic = 0;
      return AARRUDATATYPE;
    }

    else if(userdefined.find(y) != userdefined.end() && chkArray == 0 && chkAtomic == 1)
    {
      yylval.attr.is_atomic = true;
      yylval.attr.is_array = false;
      fprintf(fp, "Userdefined Datatype: %s\n", x); fprintf(yyout, "%s", x);
      chkArray = 0;
      chkAtomic = 0;
      return AUDATATYPE;
    }

    else if(userdefined.find(y) != userdefined.end() && chkArray == 1 && chkAtomic == 0)
    {
      yylval.attr.is_atomic = false;
      yylval.attr.is_array = true;
      fprintf(fp, "Userdefined Datatype: %s\n", x); fprintf(yyout, "%s", x);
      chkArray = 0;
      chkAtomic = 0;
      return NARRUDATATYPE;
    }

    else if(userdefined.find(y) != userdefined.end() && chkArray == 0 && chkAtomic == 0)
    {
      yylval.attr.is_atomic = false;
      yylval.attr.is_array = false;
      fprintf(fp, "Userdefined Datatype: %s\n", x); fprintf(yyout, "%s", yytext);
      chkArray = 0;
      chkAtomic = 0;
      return NUDATATYPE;
    }
  }
}


 /*WRONG IDENTIFIERS*/
{INVALIDID} {
  fprintf(fp,"Lex Error in line: %d\n Invalid Identifier: %s\n",yylineno,yytext); fprintf(yyout, "%s", yytext);

  return LEXERROR;
}


 /*SPECIAL SYMBOLS*/
{SPECIALSYMBOL} {
  yylval.attr.token = strdup(yytext);
  fprintf(fp,"Special Symbol: %s\n",yytext); fprintf(yyout, "%s", yytext);

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
  if(!strcmp("|",yytext)){
    return PIPE;
  }
  
}


 /*WHITESPACES*/
{WHITESPACES} {
    fprintf(yyout, "%s", yytext);
}

 /*NEWLINE*/
{NEWLINE} {
  fprintf(yyout, "%s", yytext);
}

 /*COMMENTS*/
{COMMENTS} ;

{SINGLE_LINE_COMMENT} {
  yytext[0] = '/';
  yytext[1] = '/';
  fprintf(yycode,"%s",yytext);
  }

{MULTI_LINE_COMMENT} {
  yytext[0] = '$';
  yytext[1] = '*';
  yytext[yyleng-1] = '$';
  yytext[yyleng-2] = '*';
  fprintf(yycode,"%s",yytext);
}

 /*OTHER TOKENS*/
. {
	fprintf(fp,"Lex Error in line: %d\n Error is: %s\n",yylineno,yytext);
  	return LEXERROR;
}

%%

int yywrap(){
	return 1;
}
