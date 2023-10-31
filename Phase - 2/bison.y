%{
  #include <iostream>
  #include <string>
  #include<fstream>

  extern int yylex();
  extern int yylineno;
  extern FILE * yyout;
  void yyerror(std::string s);
%}

%token WHEN REPEAT ELSE_WHEN DEFAULT FOR BREAK CONTINUE 
%token TASK MAKE_PARALLEL NULL_ARGS TID ANALYZE GET SLEEP TIME
%token START RETURN TYPE ATOMIC IN FUNC INVOKE IP OP
%token DIV ADD SUB MUL EXPONENT MODULO 
%token ARROW
%token EQ INCR DECR ASSN_MODULO ASSN_EXPONENT ASSN_DIV ASSN_MUL 
%token AND OR GT LT GTEQ LTEQ NOT_EQ NEG EQUAL_TWO
%token INTEGERLITERAL STRINGLITERAL CHARACTERLITERAL BOOLEANLITERAL FLOATLITERAL
%token COMMA SEMICOLON COLON
%token PIPE
%token IDENTIFIER
%token SCOPEOPEN SCOPECLOSE
%token ROUNDOPEN ROUNDCLOSE
%token SQUAREOPEN SQUARECLOSE
%token HASH
%token LEXERROR

%token NNUM NDEC NBOOL NLET NTEXT NVOID

%token NARRNUM NARRDEC NARRBOOL NARRLET NARRTEXT

%token ANUM ADEC ABOOL ALET ATEXT

%token AARRNUM AARRDEC AARRBOOL AARRLET AARRTEXT

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
nonAtomic_datatypes: nonAtomicArray | nonAtomicSimple ;

begin :
      | startdec begin
      | declaration begin
      | function begin
      | task begin
      | type_declaration begin
      ;


/* RHS */

E : 
| SQUAREOPEN arr_access SQUARECLOSE
;

T : IDENTIFIER E 
  | func_invoke
  | access
  ;

all_ops: arithmetic_op
      | comparison_op
      | logical_op
      | HASH
      | ARROW
      ;

constants: INTEGERLITERAL
           | CHARACTERLITERAL
           | FLOATLITERAL
           | BOOLEANLITERAL
           | STRINGLITERAL
           ;

next : RHS all_ops next 
	| RHS 				
	;

RHS :	constants
    | T
    | TID
    | get_invoke
    | ROUNDOPEN RHS all_ops next ROUNDCLOSE 
    | ROUNDOPEN RHS ROUNDCLOSE
    | NEG ROUNDOPEN RHS ROUNDCLOSE
    ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM|NDEC|NBOOL|NLET|NTEXT|NVOID ;
atomicSimple : ANUM|ADEC|ABOOL|ALET|ATEXT;

nonAtomicArray : NARRNUM|NARRDEC|NARRBOOL|NARRLET|NARRTEXT;
atomicArray : AARRNUM|AARRDEC|AARRBOOL|AARRLET|AARRTEXT;


/* DECLARATION STATEMENT : Only Declaration + Assignment */

declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ;

simpleDatatype : nonAtomicSimple|atomicSimple|UDATATYPE|ATOMIC AUDATATYPE;
arrayDatatype  : nonAtomicArray|atomicArray;

declarationStmt : simpleDatatype simpleList 
                | arrayDatatype arrayList
                ;

simpleList: IDENTIFIER
          | simpleList COMMA IDENTIFIER
          | IDENTIFIER EQ RHS
          | simpleList COMMA IDENTIFIER EQ RHS
          ;

arrayList : IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE
          | IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS
          ;

dimlist : dimlist COMMA INTEGERLITERAL
        | INTEGERLITERAL
        ;

LHS : IDENTIFIER
    | IDENTIFIER SQUAREOPEN arr_access SQUARECLOSE
    | access
    ;

arr_access: dimlist
          | exprlist
          ;

exprlist: arith_expr
         | exprlist COMMA arith_expr
         ;

arith_operand: IDENTIFIER
              | INTEGERLITERAL
              | FLOATLITERAL
              | ROUNDOPEN arith_expr ROUNDCLOSE
              ;

arith_expr:  arith_operand arithmetic_op arith_operand
          ;

 /*ASSIGNMENT STATEMENT*/
assignment_statement: LHS EQ RHS;

 /*EXPRESSION STATEMENT*/
expression_statement: LHS expression_op RHS ;

//for logging
log: assignment_statement SEMICOLON { fprintf(yyout, " : assignment statement");  } 
    | expression_statement SEMICOLON { fprintf(yyout, " : expression statement");  }
    ;

g: IDENTIFIER EQ RHS
 | g COMMA IDENTIFIER EQ RHS
 ;

both_assignment: assignment_statement 
                | simpleDatatype g
                ;

 /*LOOPS*/
loop: for_loop | while_loop ;

 /*FOR LOOP*/
for_loop: FOR SQUAREOPEN both_assignment PIPE RHS PIPE expression_statement SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN RHS SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;



/*CONDITIONAL STATEMENT*/
conditional: when_statement when_default;

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE
              | when_statement ELSE_WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE
              ;

 /*DEFAULT STATEMENT (occurs only once)*/
when_default: DEFAULT SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE 
            | 
            ;  

analysis_arrays: NARRDEC | NARRNUM | AARRDEC | AARRNUM ;

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER ; 

analyze_statement : ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax ;

analyze_syntax   : COLON analysis_arrays analyze_syntax | SEMICOLON { fprintf(yyout, " : analyze statement");  } ;

/*calls*/

// RHS:  RHS;

func_invoke2 : func_invoke SEMICOLON { fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER COLON arguments COLON
           | INVOKE IDENTIFIER COLON NULL_ARGS
          ;


arguments : arguments COMMA RHS 
          | RHS
          ;


/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER COLON INTEGERLITERAL COLON INTEGERLITERAL COLON arguments COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              | MAKE_PARALLEL IDENTIFIER COLON INTEGERLITERAL COLON INTEGERLITERAL COLON NULL_ARGS COLON SEMICOLON { fprintf(yyout, " : call statement");  } ;
               ;

/*get statement*/
get_invoke : GET ARROW TIME ;

/*SLEEP STATEMENT*/
sleep : SLEEP ROUNDOPEN FLOATLITERAL ROUNDCLOSE SEMICOLON { fprintf(yyout, " : sleep statement");  };
       | SLEEP ROUNDOPEN INTEGERLITERAL ROUNDCLOSE SEMICOLON { fprintf(yyout, " : sleep statement");  };

/* Grammar Rules for Input and Output*/
file_name : ARROW STRINGLITERAL
          | ARROW IDENTIFIER
          |
          ;

input : IP file_name COLON IDENTIFIER nextip
      ;

/*SCAN STATEMENT*/
nextip : COMMA IDENTIFIER nextip
     | SEMICOLON
     { 
      fprintf(yyout, " : scan statement");
     }
    ;

stringvalues : STRINGLITERAL 
             | IDENTIFIER
            ;

/* Return */
return_statement : RETURN RHS SEMICOLON { fprintf(yyout, " : return statement"); } ;
                 | RETURN NVOID SEMICOLON { fprintf(yyout, " : return statement"); } ;

/*PRINT STATEMENT*/
output : OP COLON opstring file_name SEMICOLON
       { 
        fprintf(yyout, " : print statement");
       }
      ;

opstring : stringvalues nextop 
         ;

nextop : HASH stringvalues nextop
       |
       ;


/*FUNCTION DECLARATION AND IMPLEMENTATION SCOPE*/
function:         func_decl func_body | atomic_func_decl func_body;

func_args:        all_datatypes IDENTIFIER | func_args COMMA all_datatypes IDENTIFIER ;

func_decl :       FUNC IDENTIFIER COLON func_args COLON nonAtomic_datatypes { fprintf(yyout, " : function declaration statement"); } 
                 | FUNC IDENTIFIER COLON NULL_ARGS COLON nonAtomic_datatypes { fprintf(yyout, " : function declaration statement"); }  ; 
; 
atomic_func_decl :   ATOMIC FUNC IDENTIFIER COLON func_args COLON nonAtomic_datatypes { fprintf(yyout, " : function declaration statement"); }
                     | ATOMIC FUNC IDENTIFIER COLON NULL_ARGS COLON nonAtomic_datatypes { fprintf(yyout, " : function declaration statement"); }  ;  

func_body : SCOPEOPEN func_statements SCOPECLOSE;

func_scope: declaration
          | log
          | task_invoke
          | func_invoke2
          | loop
          | return_statement
          | conditional
          | analyze_statement
          | input | output    | sleep
          | SCOPEOPEN func_statements SCOPECLOSE
          | method_invoke
          ;

func_statements: func_scope func_statements
               | 
               ;


/* Task declaration and implemenatation scope */
task: TASK IDENTIFIER COLON func_args { fprintf(yyout, " : task declaration statement"); } SCOPEOPEN taskscope SCOPECLOSE
    ;

taskscope: declaration taskscope
        | log taskscope
        | conditional taskscope
        | loop taskscope
        | func_invoke2 taskscope
        | output taskscope
        | SCOPEOPEN taskscope SCOPECLOSE taskscope
        | sleep taskscope
        | method_invoke taskscope
        | 
        ;

/* Scope for Conditionals and Loop Statements */
statement: declaration
          | log
          | conditional
          | loop
          | return_statement
          | func_invoke2
          | task_invoke
          | analyze_statement
          | output
          | sleep
          | BREAK SEMICOLON
          | CONTINUE SEMICOLON
          | input
          | method_invoke
          ;

statements: statement statements
          | 
          ;
          
          
access : IDENTIFIER ARROW id;
id     : IDENTIFIER
       | id ARROW IDENTIFIER
       ;
       
/* START DEFINAITON */

startdec: START SCOPEOPEN start SCOPECLOSE 
       ;

start: declaration start
     | log start
     | conditional start
     | loop start
     | func_invoke2 start
     | task_invoke start
     | analyze_syntax start
     | output start
     | input start
     | SCOPEOPEN start SCOPECLOSE start
     | sleep start
     | method_invoke start
     |
     ;

/* TYPE DEFINITION */

type_declaration: TYPE UDATATYPE { fprintf(yyout, " : type declaration statement"); } SCOPEOPEN attributes methods SCOPECLOSE
                ;

attributes: declarationStmt SEMICOLON
          | attributes declarationStmt SEMICOLON
          ;


methods: methods method
       | 
       ;

method: func_decl SCOPEOPEN method_body SCOPECLOSE ;


method_invoke : INVOKE IDENTIFIER ARROW IDENTIFIER COLON RHS arguments COLON
              | INVOKE IDENTIFIER id ARROW IDENTIFIER COLON RHS arguments COLON
              ;


in_statement : IN ARROW IDENTIFIER SEMICOLON
             | INVOKE IN ARROW IDENTIFIER COLON arguments COLON
             | INVOKE IN ARROW IDENTIFIER COLON NULL_ARGS COLON
             ;

method_statements: declaration 
                 | log
                 | task_invoke
                 | func_invoke2
                 | loop
                 | return_statement
                 | conditional
                 | analyze_statement
                 | input
                 | output
                 | sleep
                 | SCOPEOPEN method_statements SCOPECLOSE
                 | in_statement
                 | method_invoke
                 ;

method_body: method_statements method_body
           |
           ;
           
%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
