%{
  #include <iostream>
  #include <string>
  #include <fstream>
  #include <climits>
  #include "errors.hpp"
  #include "symbol_table.hpp"
  #include "semantics.hpp"   
  #include <string.h>
  extern int yylex();
  extern int yylineno;
  extern FILE * yyout;
  void yyerror(std::string s);
  char * dt_state ;
  int array_state;
  int atomic_state;
  char * t_state ;
  char * curr_type ;
  std::vector<char *> arg_dat; // used during invokes, will be sent to searching funcs
  std::vector<char *> decl_arg_dat; // used at declarations, will be sent to adding functions
  std::vector<int> decl_arg_is_array ;
//   std::unordered_set<char *> types_set;
  MethodTable m_tb ;
  FunctionTable f_tb ;
  TaskTable t_tb ;
  VariableTable i_tb ;
  AttributeTable attr_tb ;
  TypeTable c_tb ;
  int scopeLevel = 0 ;
  int startCount = 0;
%}

%union {
       struct attribute
       {
           char *ID;          // Name of the variable
           char *_type;       // Type of the variable (Function/Task/Type/Normal)
           bool is_atomic;    // Is the variable atomic?
           bool is_array;     // Is the datatype multidimensional?
           char *datatype;    // What is the datatype? (number/decimal/letter/text/bool)

           int intVal; // If encountered a integer constant, will store value here
           float decVal; // If encountered a decimal constant, will store value here
           char charVal; // If encountered a character constant, will store value here
           bool boolVal; // If encountered a boolean constant, will store value here
           char *stringVal; // If encountered a string constant, will store value here
           char *token; // If encountered a token string like for/while, will store value here
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

%type<attr> return_statement_m func_decl_m declaration_t func_return all_datatypes expression_op comparison_op arithmetic_op logical_op nonAtomic_datatypes E T all_ops constants next RHS nonAtomicSimple atomicSimple nonAtomicArray atomicArray declaration simpleDatatype arrayDatatype declarationStmt simpleList arrayList array_inValues dimlist LHS arr_access exprlist arith_expr arith_operand assignment_statement expression_statement exprrr log g both_assignment loop for_loop while_loop conditional when_statement /* when_default */ analysis_arrays analyze_label analyze_statement analyze_syntax func_invoke2 func_invoke arguments task_invoke get_invoke sleep file_name input nextip stringvalues return_statement output opstring nextop func_decl atomic_func_decl func_body func_scope func_statements statement statements access id startdec start type_declaration type_scope methods method method_invoke2 method_args method_invoke in_stmt method_statements method_body


%start begin

%%
all_datatypes: NUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | AUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NARRUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | AARRUDATATYPE
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NBOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NDEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NNUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NTEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NLET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ABOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ADEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ALET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ATEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ANUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | nonAtomicArray 
             {
              /*
              Will be handled down
              */
             }
             | atomicArray 
             {
              /*
              Will be handled down
              */
              }
             ;

expression_op: ASSN_DIV | ASSN_EXPONENT | ASSN_MODULO | ASSN_MUL | INCR | DECR ;
comparison_op: LT | GT | GTEQ | LTEQ | NOT_EQ | EQUAL_TWO ;
arithmetic_op: ADD | SUB | MUL | DIV | MODULO | EXPONENT ;
logical_op: AND | OR ;
nonAtomic_datatypes: nonAtomicArray | nonAtomicSimple ;

begin : {
       if(startCount < 1){
              printError(yylineno,START_ERROR_LESS);
       }
       }
      | startdec begin
      | declaration begin
      | function begin
      | task begin
      | type_declaration begin
      ;


/* RHS */

E : {;}
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

constants: INTEGERLITERAL 
       {
              $$.datatype = "number"; 
              $$.intVal = $1.intVal;
       }

     | CHARACTERLITERAL 
              {
                     $$.datatype = "letter"; 
                     $$.charVal = $1.charVal;
              }

      | FLOATLITERAL 
              {
                     $$.datatype = "decimal"; 
                     $$.decVal = $1.decVal;
              }

      | BOOLEANLITERAL 
        {
               $$.datatype = "bool"; 
               $$.boolVal = $1.boolVal;
        }

       | STRINGLITERAL 
       {
              $$.datatype = "text"; 
              $$.stringVal = $1.stringVal;
       }

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
nonAtomicSimple : NNUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NDEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NBOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NLET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NTEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NVOID 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                ;

atomicSimple : ANUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ADEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ABOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ALET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ATEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ; 

nonAtomicArray : NARRNUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRDEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRBOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRLET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRTEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ;

atomicArray : AARRNUM 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRDEC 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRBOOL 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRLET 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRTEXT 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ;


/* DECLARATION STATEMENT : Only Declaration + Assignment */
errorDatatypes: IDENTIFIER| ATOMIC IDENTIFIER| ARRAY IDENTIFIER| ATOMIC ARRAY IDENTIFIER;

declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            | errorDatatypes IDENTIFIER {printf("TYPE NOT DECLARED, %d\n", yylineno); return 1;};
            ;


/* declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ; */

simpleDatatype : nonAtomicSimple 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | atomicSimple 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = false; 
                            $$.is_atomic = false;
                     }
           
          | ATOMIC AUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = false; 
                            $$.is_atomic = true;
                     }
            
         ;
arrayDatatype  : nonAtomicArray 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | atomicArray 
                     {
                            
                            $$.datatype = ($1.datatype);
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ARRAY NARRUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = true; 
                            $$.is_atomic = false;
                     }
            
         | ATOMIC ARRAY AARRUDATATYPE 
                     {
                            $$.datatype = ($1.datatype);
                            $$.is_array = true; 
                            $$.is_atomic = true;
                     }
              ;

declarationStmt : simpleDatatype  
                     {
                            // printf("%s\n",$1.datatype);
                            dt_state = ($1.datatype);
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } simpleList
                | arrayDatatype  
                     {
                            dt_state = ($1.datatype);
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } arrayList
                ;

simpleList: IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
              {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($1.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            i_tb.print();
              }
          | simpleList COMMA IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
              {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($3.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array);
                            i_tb.print();
              }
          | IDENTIFIER EQ RHS 
              {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($1.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            if(/* DO LHS RHS check*/ true) ;

                            i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state,
                            atomic_state, Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and
                            RHS.datatype
                            */
              }
          | simpleList COMMA IDENTIFIER EQ RHS 
              {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($3.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }
                            if(/* DO LHS RHS check*/ true) ;

                            i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $3.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
          ;

arrayList : IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
              {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($1.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level
                            */
              }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
              {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($3.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array);
                            i_tb.print();
                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, 
                            atomic_state, Scope Level
                            */
              }
          | IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS 
              {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(i_tb.searchDeclaration($1.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS 
              {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(i_tb.searchDeclaration($3.ID)){
                                   printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                                   return 1;
                            }

                            i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array);

                            /*
                            Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                            Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
              }
          ;

array_inValues: INTEGERLITERAL {$$.intVal = $1.intVal;}
              | IDENTIFIER {$$.intVal = INT_MAX;}
              ;

dimlist : dimlist COMMA array_inValues
        | array_inValues
        ;

LHS : IDENTIFIER 
       {
              i_tb.searchDeclaration($1.ID);
              /*
              Search for identifier, get it's attributes, 
              store in $1.datatype, $1.is_array, $1.is_atomic
              */
       }
    | IDENTIFIER SQUAREOPEN arr_access SQUARECLOSE 
                 {
                     /*
                     Search for identifier, get it's attributes, store
                     in $1.datatype, $1.is_array, $1.is_atomic
                     */
                     /*
                     If is_array of Identifier is false, then semantic error
                     */
                 }
    | access 
    {
       /* 
       SHOULD COME BACK, THIS IS ARROW ACCESSING
       */
    }
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
assignment_statement: LHS EQ RHS 
                     {

                            /*
                            Type check for LHS.datatype, RHS.datatype
                            */
                     }
                    ;

 /*EXPRESSION STATEMENT*/
expression_statement: LHS expression_op RHS 
                     {
                            /* 
                            SHOULD COME BACK, THERE SHOULD BE A TYPE CHECK BTW LHS.datatype, RHS.datatype. 
                            IF IT MATCHES, WILL $$.datatype BE BOOLEAN? 
                            */
                     }
                    ;
exprrr: expression_statement
      | ROUNDOPEN expression_statement ROUNDCLOSE
      ;

//for logging
log: assignment_statement SEMICOLON { fprintf(yyout, " : assignment statement");  }
    | expression_statement SEMICOLON { fprintf(yyout, " : expression statement");  }
    ;

g: IDENTIFIER EQ RHS 
       {
              if(i_tb.searchDeclaration($1.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              }
              if(/* Do type check with RHS */ true){
                     i_tb.addVariable($1.ID,dt_state,atomic_state, array_state);
              }
              /*
              Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
 | g COMMA IDENTIFIER EQ RHS 
       {
              if(i_tb.searchDeclaration($3.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
              }
              if(/* Do type check with RHS */ true){
                     i_tb.addVariable($3.ID,dt_state,atomic_state, array_state);
              }
              /*
              Insert in Normal IDENTIFIER TABLE $2.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
       ;

both_assignment: assignment_statement 
              {
                     /*
                     NO NEED TO DO ANYTHING, THE ASSIGNMENT STATEMENT RULE TAKES CARE
                     */
              }
                | ROUNDOPEN assignment_statement ROUNDCLOSE 
                {
                     /*
                     NO NEED TO DO ANYTHING, THE ASSIGNMENT STATEMENT RULE TAKES CARE
                     */
                }
                | simpleDatatype {
                            // printf("%s\n",$1.datatype);
                            dt_state = ($1.datatype);
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     }
                     g 
                {
                     dt_state = NULL ;
                     /*
                     NO NEED TO DO ANYTHING, THE g STATEMENT RULE TAKES CARE
                     */
                }
                ;

 /*LOOPS*/
loop: for_loop | while_loop ;

 /*FOR LOOP*/
for_loop: FOR {scopeLevel++;} SQUAREOPEN both_assignment PIPE RHS PIPE exprrr SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       {
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE 
              PREDICATES ARE TAKEN CARE BY ABOVE RULES
              */
       };

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN RHS SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       {
              /*
              RHS.datatype is coercible with boolean?
              */
              /*
              NO NEED TO DO ANYTHING EXCEPT SCOPES, THE PREDICATES ARE
              TAKEN CARE BY ABOVE RULES
              */
       };



/*CONDITIONAL STATEMENT*/
conditional: when_statement;

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE extend 
       ;
extend : ELSE_WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE extend 
       | DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       | {;}
       ;

 /*DEFAULT STATEMENT (occurs only once)*/
/* when_default: DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       | {;}
       ;   */

analysis_arrays: NARRDEC | NARRNUM | AARRDEC | AARRNUM 
              {
                     /* 
                     SHOULD COME BACK, WHAT ARE THESE? 
                     */
              };

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER 
              {
                     /*
                     SHOULD COME BACK, WHAT ARE THESE?
                     */
              } ; 

analyze_statement : ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax SEMICOLON { fprintf(yyout, " : analyze statement");  }
       {
       /* 
       SHOULD COME BACK, WHAT ARE THESE? 
       */
       } ;

analyze_syntax   : COLON analysis_arrays analyze_syntax | 
       {
              /* 
              SHOULD COME BACK, WHAT ARE THESE? 
              */
       };

/*calls*/

// RHS:  RHS;

func_invoke2 : func_invoke SEMICOLON { fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER COLON arguments COLON 
       {
              /*
              BY here list of arg_dat (list of arguement's datatypes) will be ready. 
              For all functions with name as $2.ID, type check arguements
              */
              arg_dat.clear();
       }
           | INVOKE IDENTIFIER COLON NULL_ARGS COLON 
           {
              /*
              For all functions with name as $2.ID, type check if arguements are null
              */ 
             arg_dat.clear();
           }
          ;


arguments : arguments COMMA RHS 
          {
              arg_dat.push_back(($3.datatype));
          }
          | RHS 
          {
              arg_dat.push_back(($1.datatype));
          }
          ;


/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER COLON arith_expr COLON arith_expr COLON arguments COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              {
                     /*
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */
                     arg_dat.clear();
              }
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
          | {;}
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
return_statement : RETURN RHS SEMICOLON { $$.datatype = $2.datatype; $$.is_array = $2.is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/fprintf(yyout, " : return statement"); } ;
                 | RETURN NVOID SEMICOLON { $$.datatype = $2.datatype; $$.is_array = $2.is_array; /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/ fprintf(yyout, " : return statement"); } ;

/*PRINT STATEMENT*/
output : OP COLON opstring file_name SEMICOLON
       { 
        fprintf(yyout, " : print statement");
       }
      ;

opstring : stringvalues nextop 
         ;

nextop : HASH stringvalues nextop
       | {;}
       ;


/*FUNCTION DECLARATION AND IMPLEMENTATION SCOPE*/

function: func_decl func_body 
        | atomic_func_decl func_body
        ;

func_args: all_datatypes IDENTIFIER 
       {
              decl_arg_dat.push_back(($1.ID));
              decl_arg_is_array.push_back($1.is_array);
              i_tb.addVariable($2.ID, $1.datatype, $1.is_atomic, $1.is_array);
       } /*SHOULD COME BACK and see the order they are getting stored in*/
       | func_args COMMA all_datatypes IDENTIFIER 
       {
              i_tb.addVariable($4.ID, $3.datatype, $3.is_atomic, $3.is_array);
              decl_arg_is_array.push_back($3.is_array);
              decl_arg_dat.push_back(($3.ID));
       } 
       ;

args: func_args
    | NULL_ARGS
    ;

func_return : nonAtomic_datatypes 
              {
                     $$.datatype = ($1.datatype); 
                     $$.is_array = $1.is_array; 
                     /*Atomic is not needed*/
              }
            | NUDATATYPE 
            {
              $$.datatype = ($1.datatype); 
              $$.is_array = $1.is_array; 
              /*Atomic is not needed*/
            }
            | IDENTIFIER {{printf("TYPE NOT DECLARED, %d\n", yylineno); return 1;};}
            ;

func_decl :       FUNC IDENTIFIER COLON args COLON func_return 
              { 
                     /*
                     Add args as they are encountered in the id_table, IN FUNCTIONS TABLE, name of the function
                     is $2.ID decl_arg_dats will be ready, return_type is $6.datatype, $6.is_array 
                     */ 
              //       if(f_tb.searchFunction($2.ID, decl_arg_dat,decl_arg_is_array) == ""){
              //        f_tb.addFunction($2.ID, decl_arg_dat, decl_arg_is_array,$6.datatype, $6.is_array, 0);
              //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
              //       }else {
              //        printError(yylineno, FUNCTION_REDECLARATION_ERROR);
              //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
              //       }
                     
              } 
              ;
atomic_func_decl :   ATOMIC FUNC IDENTIFIER COLON args COLON func_return 
                     { 
                            /*
                            Add args as they are encountered in the id_table, decl_arg_dats will be ready, return_type
                            is $6.datatype, $6.is_array 
                            */ 
                            // if(f_tb.searchFunction($2.ID, decl_arg_dat,decl_arg_is_array) == ""){
                            //        f_tb.addFunction($2.ID, decl_arg_dat, decl_arg_is_array , $6.datatype, $6.is_array, 1);
                            //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
                            // }else {                        
                            //        printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                            //        decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement");
                            // }
                     }
                     ;

func_body : SCOPEOPEN {scopeLevel++;} func_statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE;

func_scope: declaration
          | log
          | task_invoke
          | func_invoke2 /*TYPE CHECK IF THE RETURN TYPE OF THIS FUNCTION IS VOID*/
          | loop
          | return_statement
          | conditional
          | analyze_statement
          | input | output    | sleep
          | SCOPEOPEN {scopeLevel++;} func_statements 
          {
              i_tb.deleteVariables();
              scopeLevel--;
          } SCOPECLOSE
          | method_invoke2
          ;

func_statements: func_scope func_statements
               | {;}
               ;

/* Task declaration and implemenatation scope */
task: TASK IDENTIFIER COLON {scopeLevel++;} args { fprintf(yyout, " : task declaration statement"); } SCOPEOPEN taskscope 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE
    ;

taskscope: declaration taskscope
        | log taskscope
        | conditional taskscope
        | loop taskscope
        | func_invoke2 taskscope
        | output taskscope
        | SCOPEOPEN {scopeLevel++;} taskscope 
        {
              i_tb.deleteVariables();
              scopeLevel--;
        } SCOPECLOSE taskscope
        | sleep taskscope
        | method_invoke2 taskscope
        | {;}
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
          | SCOPEOPEN {scopeLevel++;} statements
          {
              i_tb.deleteVariables();
              scopeLevel--;
          } SCOPECLOSE
          | output
          | sleep
          | BREAK SEMICOLON
          | CONTINUE SEMICOLON
          | input
          | method_invoke2
          ;

statements: statement statements
          | {;}
          ;
          
          
access : IDENTIFIER ARROW id 
       {
              /*$1.datatype should be from an existing class*/ 
              t_state = ($1.datatype);
       }
       ;

id     : IDENTIFIER
        {
              t_state = ($1.datatype); 
              $$.datatype = ($1.datatype);
       }
       | id ARROW IDENTIFIER 
       {
              t_state = ($1.datatype); 
              /*
                     Type check that t_state is existing in the types_set, and it has an attribute named $3.ID
              */ 
              /*
                     After the check is done, we are supposed to update the t_state to the last identifier type
              */ 
              t_state = $3.datatype;
       }
       ;
       
/* START DEFINAITON */

startdec: START { //////////////////////////////// COMPLETED ///////////////////////////////
       fprintf(yyout, " : start declaration statement");
       scopeLevel++;
       startCount++;
              if(startCount > 1){
                     printError(yylineno, START_ERROR_MORE);
                     return 1;    
              }
       } SCOPEOPEN start
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
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
     | SCOPEOPEN {scopeLevel++;} start 
     {
       i_tb.deleteVariables();
       scopeLevel--;
     } SCOPECLOSE start
     | sleep start
     | method_invoke2 start
     | {;}
     ;

/* TYPE DEFINITION */

type_declaration: TYPE TYPENAME 
              { 
                     // types_set.insert($2.token); 
                     if(c_tb.searchType($2.ID)){
                            printError(yylineno,TYPE_REDECLARATION);
                            return 1;
                     }
                     curr_type = ($2.ID);
                     fprintf(yyout, " : type declaration statement"); 

              } SCOPEOPEN {scopeLevel++;} type_scope methods 
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
                     curr_type = NULL ;
              } SCOPECLOSE
              ;

type_scope: declaration_t type_scope | {;} ;

declaration_t : declarationStmt_t SEMICOLON 
              { 
                     fprintf(yyout, " : declaration statement"); 
              }
              ;

declarationStmt_t : simpleDatatype simpleList_t
                     {
                            dt_state = ($1.datatype);
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     }
                | arrayDatatype arrayList_t
                     {
                            dt_state = ($1.datatype);
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     }
                ;

simpleList_t: IDENTIFIER 
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
          | simpleList COMMA IDENTIFIER 
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
          | IDENTIFIER EQ RHS 
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
          | simpleList COMMA IDENTIFIER EQ RHS 
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name
                            will be the last one from the types_Set+ TYPE CHECK FOR COERCIBILITY OF
                            dt_state and RHS.datatype
                            */
                     }
          ;

arrayList_t : IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE 
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES $1.ID, dt_state, array_state, class_name will be the
                            last one from the types_Set atomic_state
                            */
                     }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE 
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name 
                            will be the last one from the types_Set
                            */
                     }
          | IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS 
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }

                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be
                            the last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist SQUARECLOSE EQ RHS 
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will be the
                            last one from the types_Set + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                            */
                     }
                     ;

methods: methods method
       | {;}
       ;

method: func_decl_m SCOPEOPEN method_body 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE ;

func_decl_m : FUNC IDENTIFIER{fprintf(fpcpp,"%s",$2.token)}  COLON {fprintf(fpcpp,"(")} {scopeLevel++;} args COLON {fprintf(fpcpp,")")} func_return 
              { 
              /*
              Add args as they are encountered in the IDENTIFIER TABLE, 
              IN METHODS TABLE: $2.ID is method name, decl_arg_dats will be ready, 
              return_type is $6.datatype, $6.is_array class name will be the last element in the types_set
              */ 
                     decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement"); 
              } 
              ;

method_invoke2 : method_invoke SEMICOLON  { fprintf(yyout, " : call statement");  fprintf(fpcpp,"%s",$2.token)} ;

method_args : arguments | NULL_ARGS ;

method_invoke : INVOKE id ARROW{fprintf(fpcpp."%s",$3,token)} IDENTIFIER{fprintf(fpcpp,"%s",$4.token)} COLON {fprintf(fpcpp,"(");} method_args COLON {fprintf(fpcpp,")");}
              {
                     /* 
                     Type check: $2.datatype should be a class, and $4.ID should be a function 
                     in that class
                     */ 
                     /*
                     BY here list of arg_dat (list of arguement's datatypes) will be ready. 
                     For all mthods with name as $2.ID, type check arguements
                     */
              arg_dat.clear();
              }
              /*| INVOKE IDENTIFIER id ARROW IDENTIFIER COLON method_args COLON 
              {
                     /*
                     Currently the t_state variable contains the datatype of id (i.e., $3). 
                     CHECK: is $3.datatype among a type set, CHECK if the IDENTIFIER, i.e, $5.ID is 
                     in the methods table whose type i t_state. If yes, then check for arguements
                     */
              }*/
              ;

in_stmt : IN{fprintf(fpcpp,"this");} ARROW {fprintf(fpcpp,"%s",$2.token)} IDENTIFIER {fprintf(fpcpp,"%s",$3.token);}
       {
              /*
              In this check if $3.datatype = last element in the type set
              */
       }
       | INVOKE IN {fprintf(fpcpp,"this");} ARROW {fprintf(fpcpp,"%s",$3.token)} IDENTIFIER {fprintf(fpcpp,"%s",$4.token);} COLON {fprintf(fpcpp,"(");} arguments COLON {fprintf(fpcpp,")");}
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set
               + TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
       }
       | INVOKE IN {fprintf(fpcpp,"this");} ARROW {fprintf(fpcpp,"%s",$3.token)} IDENTIFIER {fprintf(fpcpp,"%s",$4.token);} COLON {fprintf(fpcpp,"(");} NULL_ARGS COLON {fprintf(fpcpp,")");}
       {
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set + 
              TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
                     */
       }
      ;

method_statements: declaration 
                 | log
                 | task_invoke
                 | func_invoke2
                 | loop
                 | return_statement_m /*TYPE CHECK WITH MOST RECENT METHOD'S RETURN TYPE*/
                 | conditional
                 | analyze_statement
                 | input
                 | output
                 | sleep
                 | SCOPEOPEN {scopeLevel++;} method_statements 
                 {
                     i_tb.deleteVariables();
                     scopeLevel--;
                 } SCOPECLOSE
                 | method_invoke2
                 ;
/* Return */
return_statement_m : RETURN{fprintf(fpcpp,"%s",$1.token);} RHS SEMICOLON {fprintf(fpcpp,"%s",$3.token);}
              { 
                     $$.datatype = $2.datatype; 
                     $$.is_array = $2.is_array; 
                     /*
                       Atomics not needed here ig
                     */ 
                     /*
                     TYPE CHECK WITH LAST METHOD'S RETURN DATATYPE AND THIS DATATYPE
                     */
                     fprintf(yyout, " : return statement"); 
              } ;
              | RETURN {fprintf(fpcpp,"%s",$1.token);}  NVOID SEMICOLON {fprintf(fpcpp,"%s",$3.token);}
              { 
                     $$.datatype = $2.datatype; 
                     $$.is_array = $2.is_array; 
                     /*
                     Atomics not needed here ig
                     */ 
                     /*
                     TYPE CHECK WITH LAST METHOD'S RETURN DATATYPE AND THIS DATATYPE
                     */ 
                     fprintf(yyout, " : return statement"); 
              } ;

method_body: method_statements method_body
           | {;}
           ;
           
%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
