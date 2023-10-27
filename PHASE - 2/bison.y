%{
  #include <iostream>
  #include <string>

  extern int yylex();
  extern int yylineno;
  void yyerror(std::string s);
%}

%token WHEN REPEAT ELSE_WHEN DEFAULT FOR BREAK CONTINUE 
%token TASK MAKE_PARALLEL NULL_ARGS TID ANALYZE GET SLEEP TIME
%token START RETURN TYPE ATYPE IN FUNC INVOKE IP OP
%token DIV ADD SUB MUL EXPONENT MODULO 
%token ARROW
%token EQ INCR DECR ASSN_MODULO ASSN_EXPONENT ASSN_DIV ASSN_MUL 
%token AND OR GT LT GTEQ LTEQ NOT_EQ NEG EQUAL_TWO
%token INTEGERLITERAL STRINGLITERAL CHARACTERLITERAL BOOLEANLITERAL FLOATLITERAL
%token COMMA SEMICOLON COLON
%token IDENTIFIER
%token SCOPEOPEN SCOPECLOSE
%token ROUNDOPEN ROUNDCLOSE
%token SQUAREOPEN SQUARECLOSE
%token HASH
%token LEXERROR

%token NNUM
%token NDEC
%token NBOOL
%token NLET
%token NTEXT
%token NVOID

%token NARRNUM
%token NARRDEC
%token NARRBOOL
%token NARRLET
%token NARRTEXT
%token NARRVOID


%token ANUM
%token ADEC
%token ABOOL
%token ALET
%token ATEXT

%token AARRNUM
%token AARRDEC
%token AARRBOOL
%token AARRLET
%token AARRTEXT

%token UDATATYPE AUDATATYPE

%start begin

%%

begin : 
      ;

/* Grammar Rules for Input and Output*/
file_name : ARROW STRINGLITERAL
          | ARROW IDENTIFIER
          |
          ;

input : IP file_name COLON IDENTIFIER nextip
      ;

nextip : COMMA IDENTIFIER nextip
     | SEMICOLON
     { 
      std::cout << " : Input"<<std::endl;
     }
    ;

stringvalues : STRINGLITERAL 
             | IDENTIFIER
            ;

output : OP COLON opstring file_name SEMICOLON
       { 
        std::cout << " : Output"<<std::endl;
       }
      ;

opstring : stringvalues nextop 
         ;

nextop : HASH stringvalues nextop
       |
       ;

%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << std::endl;
}