%{
  #include <iostream>
  #include <string>
  #include <vector>
  #include<fstream>

  extern int yylex();
  extern int yylineno;
  extern FILE * yyout;
  void yyerror(std::string s);
  char *dt_state; // Datatype state
  char *t_state; // Type i.e., class state
  std::vector<char *> id_vec;
  std::vector<int> dim_vec;
%}


%union 
{
       struct attribute
       {
              char* ID;   // Name of the variable
              char* _type; // Variable/Function/Task/Type/Constant Marchali
              bool is_atomic;
              bool is_array;
              char* datatype;
              int intVal;
              float decVal;
              char charVal;
              bool boolVal;
              char* stringVal;
              char* token;
       }attr;
}

%token<attr> WHEN REPEAT ELSE_WHEN DEFAULT FOR BREAK CONTINUE 
%token<attr> TASK MAKE_PARALLEL NULL_ARGS TID ANALYZE GET SLEEP TIME
%token<attr> START RETURN TYPE ATOMIC ARRAY IN FUNC INVOKE IP OP
%token<attr> DIV ADD SUB MUL EXPONENT MODULO 
%token<attr> ARROW
%token<attr> EQ INCR DECR ASSN_MODULO ASSN_EXPONENT ASSN_DIV ASSN_MUL 
%token<attr> AND OR GT LT GTEQ LTEQ NOT_EQ NEG EQUAL_TWO
%token<attr> INTEGERLITERAL STRINGLITERAL CHARACTERLITERAL BOOLEANLITERAL FLOATLITERAL
%token<attr> COMMA SEMICOLON COLON
%token<attr> PIPE
%token<attr> IDENTIFIER
%token<attr> SCOPEOPEN SCOPECLOSE
%token<attr> ROUNDOPEN ROUNDCLOSE
%token<attr> SQUAREOPEN SQUARECLOSE
%token<attr> HASH
%token<attr> LEXERROR

%token<attr> NNUM NDEC NBOOL NLET NTEXT NVOID

%token<attr> NARRNUM NARRDEC NARRBOOL NARRLET NARRTEXT

%token<attr> ANUM ADEC ABOOL ALET ATEXT

%token<attr> AARRNUM AARRDEC AARRBOOL AARRLET AARRTEXT

%token<attr> TYPENAME
%token<attr> NUDATATYPE AUDATATYPE // Simple User Defined, Simple Atomic user defined
%token<attr> NARRUDATATYPE AARRUDATATYPE // Array user defined, Array atomic user defined

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


%type<attr> constants nonAtomicSimple atomicSimple nonAtomicArray atomicArray simpleDatatype arrayDatatype simpleList arrayList declaration_t array_inValues dimlist


%start begin

%%
all_datatypes: NUDATATYPE | AUDATATYPE | NARRUDATATYPE | AARRUDATATYPE| NBOOL | NDEC | NNUM | NTEXT | NLET | ABOOL | ADEC | ALET | ATEXT | ANUM | nonAtomicArray | atomicArray ;
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
  ;

all_ops: arithmetic_op
      | comparison_op
      | logical_op
      | HASH
      | ARROW
      ;

constants: INTEGERLITERAL | CHARACTERLITERAL | FLOATLITERAL | BOOLEANLITERAL | STRINGLITERAL
           ;

next : RHS all_ops next 
	| RHS 				
	;

RHS :	constants
    | T
    | TID
    | get_invoke | method_invoke | in_stmt
    | ROUNDOPEN RHS all_ops next ROUNDCLOSE 
    | ROUNDOPEN RHS ROUNDCLOSE
    | NEG ROUNDOPEN RHS ROUNDCLOSE
    ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NDEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NBOOL {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NLET {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NTEXT {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NVOID {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                ;
atomicSimple : ANUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;} 
             | ADEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ABOOL {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ALET {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ATEXT {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             ;

nonAtomicArray : NARRNUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRDEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRBOOL {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
               | NARRLET {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRTEXT {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               ; 
atomicArray : AARRNUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRDEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRBOOL {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRLET {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRTEXT {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            ;


/* DECLARATION STATEMENT : Only Declaration + Assignment */

declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ;

simpleDatatype : nonAtomicSimple | atomicSimple | NUDATATYPE | ATOMIC AUDATATYPE;

arrayDatatype  : nonAtomicArray | atomicArray | ARRAY NARRUDATATYPE | ATOMIC ARRAY AARRUDATATYPE;

declarationStmt : simpleDatatype simpleList {/*Here should make insertion to symtab, for all the vecotrlist and simpleDatatype attributes*/ id_vec.clear();}
                | arrayDatatype arrayList
                ;

simpleList: IDENTIFIER {$1.ID = yylval.attr.ID; id_vec.push_back($1.ID);}
          | simpleList COMMA IDENTIFIER {$3.ID = yylval.attr.ID; id_vec.push_back($3.ID);}
          | IDENTIFIER EQ RHS {$1.ID = yylval.attr.ID; id_vec.push_back($1.ID); /*There should be a type check for RHS and dt_state*/}
          | simpleList COMMA IDENTIFIER EQ RHS {$3.ID = yylval.attr.ID; id_vec.push_back($3.ID); /*There should be a type check for RHS and dt_state*/}
          ;

arrayList : IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE {
                     $1.ID = yylval.attr.ID;
                     id_vec.push_back($1.ID);
                     dim_vec.clear();
              }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE {
                     $3.ID = yylval.attr.ID;
                     id_vec.push_back($3.ID);
                     dim_vec.clear();
          }
          | IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS {
                     $1.ID = yylval.attr.ID;
                     id_vec.push_back($1.ID);
                     dim_vec.clear();
          }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS {
                     $3.ID = yylval.attr.ID;
                     id_vec.push_back($3.ID);
                     dim_vec.clear();
          }
          ;

array_inValues: INTEGERLITERAL {$1.intVal = yylval.attr.intVal; $$.intVal = $1.intVal;} | IDENTIFIER {$$.intVal = INT_MAX;};

dimlist : dimlist COMMA array_inValues {dim_vec.push_back($3.intVal);}
        | array_inValues {dim_vec.push_back($3.intVal);}
        ;

LHS : IDENTIFIER
    | IDENTIFIER SQUAREOPEN arr_access SQUARECLOSE
    | access
    ;

arr_access: exprlist
          ;

exprlist: arith_expr
         | exprlist COMMA arith_expr
         ;

arith_operand: IDENTIFIER
              | INTEGERLITERAL
              | FLOATLITERAL
              | ROUNDOPEN arith_expr ROUNDCLOSE
              ;

arith_expr: arith_expr arithmetic_op arith_operand
          | arith_operand
          ;

 /*ASSIGNMENT STATEMENT*/
assignment_statement: LHS EQ RHS;

 /*EXPRESSION STATEMENT*/
expression_statement: LHS expression_op RHS ;

exprrr: expression_statement | ROUNDOPEN expression_statement ROUNDCLOSE ;

//for logging
log: assignment_statement SEMICOLON { fprintf(yyout, " : assignment statement");  } 
    | expression_statement SEMICOLON { fprintf(yyout, " : expression statement");  }
    ;

g: IDENTIFIER EQ RHS
 | g COMMA IDENTIFIER EQ RHS
 ;

both_assignment: assignment_statement | ROUNDOPEN assignment_statement ROUNDCLOSE 
                | simpleDatatype g
                ;

 /*LOOPS*/
loop: for_loop | while_loop ;

 /*FOR LOOP*/
for_loop: FOR SQUAREOPEN both_assignment PIPE RHS PIPE exprrr SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN RHS SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements SCOPECLOSE;



/*CONDITIONAL STATEMENT*/
conditional: when_statement when_default;

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE
              | when_statement ELSE_WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE
              ;

 /*DEFAULT STATEMENT (occurs only once)*/
when_default: DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN statements SCOPECLOSE 
            | 
            ;  

analysis_arrays: NARRDEC | NARRNUM | AARRDEC | AARRNUM ;

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER ; 

analyze_statement : ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax SEMICOLON { fprintf(yyout, " : analyze statement");  } ; ;

analyze_syntax   : COLON analysis_arrays analyze_syntax | ;

/*calls*/

// RHS:  RHS;

func_invoke2 : func_invoke SEMICOLON { fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER COLON arguments COLON
           | INVOKE IDENTIFIER COLON NULL_ARGS COLON
          ;


arguments : arguments COMMA RHS
          | RHS
          ;


/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON arguments COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              | MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON NULL_ARGS COLON SEMICOLON { fprintf(yyout, " : call statement");  } ;
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

args: func_args | NULL_ARGS ;

func_return : nonAtomic_datatypes
            | NUDATATYPE
            ;

func_decl :       FUNC IDENTIFIER COLON args COLON func_return { fprintf(yyout, " : function declaration statement"); } 
                 ;
atomic_func_decl :   ATOMIC FUNC IDENTIFIER COLON args COLON func_return { fprintf(yyout, " : function declaration statement"); }
                     ;

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
          | method_invoke2
          ;

func_statements: func_scope func_statements
               | 
               ;

/* Task declaration and implemenatation scope */
task: TASK IDENTIFIER COLON args { fprintf(yyout, " : task declaration statement"); } SCOPEOPEN taskscope SCOPECLOSE
    ;

taskscope: declaration taskscope
        | log taskscope
        | conditional taskscope
        | loop taskscope
        | func_invoke2 taskscope
        | output taskscope
        | SCOPEOPEN taskscope SCOPECLOSE taskscope
        | sleep taskscope
        | method_invoke2 taskscope
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
          | method_invoke2
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
     | analyze_statement start
     | output start
     | input start
     | SCOPEOPEN start SCOPECLOSE start
     | sleep start
     | method_invoke2 start
     |
     ;

/* TYPE DEFINITION */

type_declaration: TYPE TYPENAME { $2.datatype = yylval.attr.datatype; t_state = $2.datatype; /* Create type table function */ fprintf(yyout, " : type declaration statement"); } SCOPEOPEN type_scope methods SCOPECLOSE
                ;

type_scope: declaration_t {/*Here, we have to push_back to the vector of type with name dt_state*/} type_scope |  ;

declaration_t : declarationStmt_t SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ;

declarationStmt_t : simpleDatatype simpleList {/*Insert in the typetable of the t_state full vectorlist. is_array,is_atomic attr false, datatype will be there*/ 
                     for(int i = 0; i <id_vec.size(); i++)
                     {
                            std::cout << id_vec[i] << " " << dt_state << " " << t_state << "\n";
                     }
                     id_vec.clear();}
                | arrayDatatype arrayList
                ;

methods: methods method
       | 
       ;

method: func_decl SCOPEOPEN method_body SCOPECLOSE ;


method_invoke2 : method_invoke SEMICOLON  { fprintf(yyout, " : call statement"); }  ;

method_args : arguments | NULL_ARGS ;

method_invoke : INVOKE IDENTIFIER ARROW IDENTIFIER COLON method_args COLON 
              | INVOKE IDENTIFIER id ARROW IDENTIFIER COLON method_args COLON
              ;

in_stmt : IN ARROW IDENTIFIER
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
                 | method_invoke2
                 ;

method_body: method_statements method_body
           |
           ;
           
%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
