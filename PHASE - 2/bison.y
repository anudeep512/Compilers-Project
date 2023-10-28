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
unary_logical_op: NEG ;
operators: EQ | expression_op | comparison_op | logical_op | ARROW | arithmetic_op ;
nonAtomic_datatypes: nonAtomicArray | nonAtomicSimple ;
atomic_datatypes:      atomicArray | atomicSimple ;


begin : 
      ;


/* RHS */

T : IDENTIFIER
  | func_invoke
  ;

all_ops: arithmetic_op
      | comparison_op
      | logical_op
      | HASH
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
    | ROUNDOPEN RHS all_ops next ROUNDCLOSE 
    | ROUNDOPEN RHS ROUNDCLOSE
    | NEG ROUNDOPEN RHS ROUNDCLOSE 
    | get_invoke
    ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM|NDEC|NBOOL|NLET|NTEXT|NVOID ;
atomicSimple : ANUM|ADEC|ABOOL|ALET|ATEXT;

nonAtomicArray : NARRNUM|NARRDEC|NARRBOOL|NARRLET|NARRTEXT;
atomicArray : AARRNUM|AARRDEC|AARRBOOL|AARRLET|AARRTEXT;


/* DECLARATION STATEMENT : Only Declaration + Assignment */

declaration : declarationList
            ;

declarationList : declarationStmt SEMICOLON
                | declarationList declarationStmt SEMICOLON
                ;

simpleDatatype : nonAtomicSimple|atomicSimple|UDATATYPE|AUDATATYPE;
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



 /*ASSIGNMENT STATEMENT*/
assignment_statement: IDENTIFIER EQ RHS;

 /*EXPRESSION STATEMENT*/
expression_statement: IDENTIFIER expression_op RHS ;

//for logging
log: assignment_statement SEMICOLON { fprintf(yyout, " : assignment statement");  } 
    | expression_statement SEMICOLON { fprintf(yyout, " : expression statement");  }
    | get_invoke SEMICOLON { fprintf(yyout, " : get statement");  }
    ;



 /*LOOPS*/
loop: for_loop | while_loop ;

 /*FOR LOOP*/
for_loop: FOR SQUAREOPEN assignment_statement SEMICOLON RHS SEMICOLON expression_statement SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;

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

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER ; 

analyze_syntax : ANALYZE analyze_label COLON analyze_label COLON array COLON array analyze_statement ;

analyze_statement   : COLON array analyze_statement | SEMICOLON { fprintf(yyout, " : analyze statement");  }

/*calls*/

/* Function calls */
is: IDENTIFIER
  | constants
  | func_invoke
  | RHS 
  ;

func_invoke: INVOKE IDENTIFIER COLON arguments SEMICOLON { fprintf(yyout, " : call statement");  }
          ;

arguments : is
             | is COMMA arguments
             | NULL_ARGS
             ;


/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER COLON INTEGERLITERAL COLON INTEGERLITERAL COLON arguments SEMICOLON { fprintf(yyout, " : call statement");  } ;

/*get statement*/
get_invoke : GET ARROW TIME SEMICOLON

/*SLEEP STATEMENT*/
sleep : SLEEP ROUNDOPEN FLOATLITERAL ROUNDCLOSE SEMICOLON { fprintf(yyout, " : sleep statement");  };


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


/*FUNCTION IMPLEMENTATION SCOPE*/
function:         func_decl func_body ;

func_args:        IDENTIFIER | func_args COMMA IDENTIFIER ;
func_decl :       FUNC IDENTIFIER COLON func_args COLON nonAtomic_datatypes { fprintf(yyout, " : function declaration statement"); } ; 

func_body : SCOPEOPEN func_statements SCOPECLOSE;

func_statements: declarationList
               | assignment_statement 
               | expression_statement 
               | task_invoke 
               | func_invoke 
               | loop 
               | return_statement
               | conditional 
               | analyze_statement
               | input | output 
               | sleep_statement
               ;


%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
