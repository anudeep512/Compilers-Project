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

all_datatypes: UDATAYPE | AUDATAYPE | NBOOL | NDEC | NNUM | NTEXT | NLET | ABOOL | ADEC | ALET | ATEXT | ANUM ;
expression_op: ASSN_DIV | ASSN_EXPONENT | ASSN_MODULO | ASSN_MUL | INCR | DECR ; //didn't include EQ (=)
comparison_op: LT | GT | GTEQ | LTEQ | NOT_EQ | EQUAL_TWO ; //didn't add '~' negation operator
arithmetic_op: ADD | SUB | MUL | DIV | MODULO | EXPONENT ;
operators: EQ | expression_op | comparison_op | NEG | AND | OR | ARROW | arithmetic_op ;


begin : 
      ;

RHS: ;


 /*ASSIGNMENT STATEMENT*/
assignment_statement: IDENTIFIER EQ RHS;

 /*EXPRESSION STATEMENT*/
expression_statement: IDENTIFIER expression_op RHS ;


/*statements*/
statements: ;



 /*LOOPS*/
loop: for_loop | while_loop

 /*FOR LOOP*/
for_loop: FOR SQUAREOPEN assignment_statement SEMICOLON predicate SEMICOLON expression_statement SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN predicate SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;




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