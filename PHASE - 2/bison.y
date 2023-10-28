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

%left ROUNDOPEN ROUNDCLOSE ARROW
%right EXPONENT
%left MUL DIV MODULO
%left ADD SUB
%left GTEQ GT LTEQ LT
%left EQUAL_TWO NOT_EQ
%right NEG
%left AND
%left OR
%right EQ ASSN_MUL ASSN_DIV ASSN_EXPONENT ASSN_MODULO INCR DECR
%left COMMA

%start begin

%%

all_datatypes: UDATATYPE | AUDATATYPE | NBOOL | NDEC | NNUM | NTEXT | NLET | ABOOL | ADEC | ALET | ATEXT | ANUM ;
expression_op: ASSN_DIV | ASSN_EXPONENT | ASSN_MODULO | ASSN_MUL | INCR | DECR ;
comparison_op: LT | GT | GTEQ | LTEQ | NOT_EQ | EQUAL_TWO ;
arithmetic_op: ADD | SUB | MUL | DIV | MODULO | EXPONENT ;
logical_op: AND | OR ;
unary_logical_op: NEG ;
operators: EQ | expression_op | comparison_op | logical_op | ARROW | arithmetic_op ;


begin : 
      ;


 /*ASSIGNMENT STATEMENT*/
assignment_statement: IDENTIFIER EQ RHS;

 /*EXPRESSION STATEMENT*/
expression_statement: IDENTIFIER expression_op RHS ;


/*statements*/
statements: ;



 /*LOOPS*/
loop: for_loop | while_loop

 /*FOR LOOP*/
for_loop: FOR SQUAREOPEN assignment_statement SEMICOLON RHS SEMICOLON expression_statement SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN RHS SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;



/*CONDITIONAL STATEMENT*/
conditional: when_statement when_default;

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS SQUARECLOSE SCOPEOPEN statements SCOPECLOSE
              | when_statement ELSE_WHEN SQUAREOPEN RHS SQUARECLOSE SCOPEOPEN statements SCOPECLOSE
              ;

 /*DEFAULT STATEMENT (occurs only once)*/
when_default: DEFAULT SQUAREOPEN RHS SQUARECLOSE SCOPEOPEN statements SCOPECLOSE 
            |
            ;  

 /*ANALYSIS STATEMENT*/

analyze_label : STRINGLITERAL | IDENTIFIER ; 

analyze_syntax : ANALYZE analyze_label COLON analyze_label COLON array COLON array | analyze_syntax COLON array 

analyze_statement : analyze_syntax SEMICOLON { fprintf(yyout, " : analyze statement"); }

/*calls*/

/*Function calls using Invoke*/
func_invoke: INVOKE IDENTIFIER COLON arguments SEMICOLON

/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER COLON INTEGERLITERAL COLON INTEGERLITERAL COLON arguments SEMICOLON

arguments    : IDENTIFIER
             | arguments COMMA IDENTIFIER

/*get statement*/
get_invoke : GET ARROW TIME

/*Sleep*/
sleep : SLEEP ROUNDOPEN FLOATLITERAL ROUNDCLOSE

array : ;

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
      fprintf(yyout, " : Input");
     }
    ;

stringvalues : STRINGLITERAL 
             | IDENTIFIER
            ;

output : OP COLON opstring file_name SEMICOLON
       { 
        fprintf(yyout, " : Output");
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
