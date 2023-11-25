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
  extern int chkAtomic;
  void yyerror(std::string s);
  char * dt_state ;
  int array_state;
  int atomic_state;
  char * curr_type ;
  std::vector<char *> decl_arg_dat; // used at declarations, will be sent to adding functions
  std::vector<int> decl_arg_is_array ;
  std::vector<int> decl_arg_is_atomic ;
  std::vector<char *> arg_dat; // used during invokes, will be sent to searching funcs
  std::vector<int> arg_is_array ;
  std::vector<int> arg_is_atomic ;
  string var_name ;
  int in_scope = 0;
  int in_task = 0; // For tid
  MethodTable m_tb ;
  FunctionTable f_tb ;
  TaskTable t_tb ;
  VariableTable i_tb ;
  AttributeTable attr_tb ;
  TypeTable c_tb ;
  int scopeLevel = 0 ;
  int startCount = 0;
  int in_make_parallel_arrays = 1;
  char * dt_type = NULL ;
  char * return_type = NULL ;
  int is_array_ret = 0;
  int tok = 0;
  int number_of_returns = 0;
  int func_start = 0;
  int curr_array_level = 0;
  int array_dim = 0;
  int return_dim_count = 0;
  int in_call_args = 0;
%}

%union {
       struct attribute
       {
           char *ID;          // Name of the variable
           bool is_atomic;    // Is the variable atomic?
           bool is_array;     // Is the datatype multidimensional?
           char *datatype;    // What is the datatype? (number/decimal/letter/text/bool)

           int intVal; // If encountered a integer constant, will store value here
           float decVal; // If encountered a decimal constant, will store value here
           char charVal; // If encountered a character constant, will store value here
           bool boolVal; // If encountered a boolean constant, will store value here
           bool stringVal; // If encountered a string constant, will store value here
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

%type<attr> func_args return_statement_m func_decl_m declaration_t func_return all_datatypes expression_op comparison_op arithmetic_op logical_op 
%type<attr> nonAtomic_datatypes E T all_ops constants next RHS nonAtomicSimple atomicSimple nonAtomicArray atomicArray declaration simpleDatatype 
%type<attr> arrayDatatype declarationStmt simpleList arrayList array_inValues dimlist LHS arr_access exprlist arith_expr arith_operand assignment_statement 
%type<attr> expression_statement exprrr log g both_assignment loop for_loop while_loop conditional when_statement analyze_label analyze_statement 
%type<attr> func_invoke2 func_invoke arguments task_invoke get_invoke sleep file_name input nextip stringvalues return_statement output opstring nextop 
%type<attr> func_decl atomic_func_decl func_body func_scope func_statements statement statements access id startdec start type_declaration type_scope methods method 
%type<attr> method_invoke2 method_args method_invoke in_stmt method_statements method_body subroutine_in_args subroutine

%start begin

%%

subroutine_in_args : %empty{in_call_args = 1;} ;
subroutine: %empty {;};

all_datatypes: NUDATATYPE 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | AUDATATYPE 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ARRAY NARRUDATATYPE 
                     {
                            cout << "132 - Hereeee" << endl ;
                            $$.datatype = $2.datatype;
                            $$.is_array = $2.is_array;
                            $$.is_atomic = $2.is_atomic;
                            cout << "136, dtype: " << $$.datatype << ", is_array: " << $$.is_array << ", is_atomic: "<<$$.is_atomic << endl ;
                     }
             | ATOMIC ARRAY AARRUDATATYPE
                     {
                            $$.datatype = $3.datatype;
                            $$.is_array = $3.is_array;
                            $$.is_atomic = $3.is_atomic;
                     }
             | NBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NDEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NNUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NTEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NLET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ABOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ADEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ALET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ATEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ANUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | nonAtomicArray { /* Is Handled Already */ }
             | atomicArray { /* Will be handled down */ }
             ;

expression_op: ASSN_DIV 
              {
                $$.ID = $1.token;
              }
              | ASSN_EXPONENT 
              {
                $$.ID = $1.token;
              } 
              | ASSN_MODULO
              {
                $$.ID = $1.token;
              } 
              | ASSN_MUL 
              {
                $$.ID = $1.token;
              } | INCR 
              {
                $$.ID = $1.token;
              } | DECR 
              {
                $$.ID = $1.token;
              } 
              ;

comparison_op: LT {$$.ID = $1.token;} 
              | GT {$$.ID = $1.token;} 
              | GTEQ {$$.ID = $1.token;} 
              | LTEQ {$$.ID = $1.token;} 
              | NOT_EQ {$$.ID = $1.token;} 
              | EQUAL_TWO {$$.ID = $1.token;} 
              ;

arithmetic_op: ADD {$$.ID = $1.token;} 
              | SUB {$$.ID = $1.token;} 
              | MUL {$$.ID = $1.token;} 
              | DIV {$$.ID = $1.token;} 
              | MODULO {$$.ID = $1.token;}
              | EXPONENT {$$.ID = $1.token;} 
              ;

logical_op: AND {$$.ID = $1.token;} 
          | OR {$$.ID = $1.token;} 
          ;

nonAtomic_datatypes: nonAtomicArray 
                   | nonAtomicSimple 
                   ;

begin_subroutine: %empty {
              if(startCount < 1){
                     printError(yylineno,START_ERROR_LESS);
                     return 1 ;
              }
       }
       ;

begin : begin_subroutine
      | startdec begin
      | declaration begin
      | function begin
      | task begin
      | type_declaration begin
      ;


/* RHS */

E      :    subroutine
       | SQUAREOPEN {curr_array_level = 0;} arr_access SQUARECLOSE
       {
              cout << "273 - " << $1.ID << endl ;
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              if(stoi(a[1]) != 1){
                     printError(yylineno,NOT_AN_ARRAY);
                     return 1;
              }
              cout << "283-" << curr_array_level <<", ID level: "<<stoi(a[2]) << endl ;
              if(stoi(a[3]) != curr_array_level + 1){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
       }
       ;

T : IDENTIFIER {curr_array_level = -1;} E 
       {
              var_name = $1.ID ;
              cout << "294-Search Variable is: " << var_name << endl ;    
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              cout <<"300-Datatype of " << var_name << " is "<< a[0] << endl ;
              return_dim_count = stoi(a[3]);
              cout << "302-Return dim count: "<< return_dim_count << endl ;
              var_name = "" ;
              $$.datatype =  cstr(a[0]);
              $$.is_atomic = stoi(a[2]);
              cout << "304- Datatype is " << $$.datatype << endl ;
              cout <<"306 - Current array level " << curr_array_level << endl ;
              cout <<"311 - in call args " << in_call_args << endl ;
              if(in_call_args){
                     if(return_dim_count == 1 && curr_array_level + 1 == 0){
                            $$.is_array = true ;
                     }else $$.is_array = false ;
              }else {
              if(curr_array_level + 1 < return_dim_count )
                     $$.is_array = true;
              if(curr_array_level + 1 == return_dim_count ){
                     $$.is_array = false ;
              }
              }
       }
  | func_invoke
  {
       $$.datatype = $1.datatype;
       $$.is_array = $1.is_array;
       $$.is_atomic = $1.is_atomic;
  }
  | access 
  {
       $$.datatype = $1.datatype ;
       $$.is_array = false ;
       $$.is_array = false ;
  }
  ;

all_ops: arithmetic_op 
       {
              $$.ID = $1.ID ;
       }
      | comparison_op 
      {
              $$.ID = $1.ID ;
      }
      | logical_op
      {
              $$.ID = $1.ID ;
      }
      | HASH
      {
              $$.ID = $1.token ;
      } 
      ;

constants: INTEGERLITERAL 
       {
              $$.datatype = "number"; 
              $$.is_array = false ;
              $$.is_atomic = false ;
              $$.intVal = $1.intVal;
       }

     | CHARACTERLITERAL 
              {
                     $$.datatype = "letter"; 
                     $$.is_array = false ;
                     $$.is_atomic = false ;
                     $$.charVal = $1.charVal;
              }

      | FLOATLITERAL 
              {
                     $$.datatype = "decimal"; 
                     $$.is_array = false ;
                     $$.is_atomic = false ;
                     $$.decVal = $1.decVal;
              }

      | BOOLEANLITERAL 
        {
              $$.datatype = "bool"; 
              $$.is_array = false ;
              $$.is_atomic = false ;
              $$.boolVal = $1.boolVal;
        }

       | STRINGLITERAL 
       {
              $$.datatype = "text"; 
              $$.is_array = false ;
              $$.is_atomic = false ;
              $$.stringVal = $1.stringVal;
       }
      ;

next : RHS all_ops next 
       {
              string a = is_coercible_rhs($1.datatype,$3.datatype,$2.ID) ; 
              cout << "383: "<<$1.datatype << " " << $3.datatype << " " << $2.ID << endl ;
              if( a == "" ){
                     printError(yylineno,TYPE_ERROR_RHS);
                     return 1 ;
              }
              $$.datatype = cstr(a) ;
              $$.is_atomic = false ;
              $$.is_array = false ;
       }
	| RHS 		
       {
              $$.datatype = $1.datatype ;
              $$.is_array = $1.is_array ;
              $$.is_atomic = $1.is_atomic ;
       }		
	;

RHS :	constants 
       {
              $$.datatype = $1.datatype ;
              $$.is_array = $1.is_array ;
              $$.is_atomic = $1.is_atomic ;
       }
    | T
       {
              $$.datatype = $1.datatype ;
              $$.is_array = $1.is_array ;
              $$.is_atomic = $1.is_atomic ;
       }
    | TID
       {
              if(in_task == 0){
                     printError(yylineno,CANNOT_USE_TID);
                     return 1 ;
              }
              $$.datatype = "number";
              $$.is_array = false ;
              $$.is_atomic = false ;
       }
    | get_invoke 
       {
              $$.datatype = "decimal" ;
              $$.is_array = false ;
              $$.is_atomic = false ;
       }
    | method_invoke 
       {
              $$.datatype = $1.datatype;
              $$.is_array = $1.is_array;
              $$.is_atomic = $1.is_atomic;
       }
    | in_stmt
       {
              $$.datatype = $1.datatype;
              $$.is_array = $1.is_array;
              $$.is_atomic = $1.is_atomic;
       }
    | ROUNDOPEN RHS all_ops next ROUNDCLOSE
    {
       string a = is_coercible_rhs(string($2.datatype),string($4.datatype),$3.ID);
       cout << "443-"<<$2.datatype << " " << $4.datatype << " " << $3.ID << endl ;
       // cout << a << endl ;
       if( a == "" ){
              printError(yylineno,TYPE_ERROR_RHS);
              return 1 ;
       }
       $$.datatype = cstr(a) ;
       $$.is_atomic = false ;
       $$.is_array = false ;
    }
    | ROUNDOPEN RHS ROUNDCLOSE 
    {
       $$.datatype = $2.datatype ;
       $$.is_array = $2.is_array ;
       $$.is_atomic = $2.is_atomic ;
    }
    | NEG ROUNDOPEN RHS ROUNDCLOSE
       {
              cout << "468- " << $3.datatype << endl ;
              if(string($3.datatype) == "number" || string($3.datatype) == "decimal" || string($3.datatype) == "bool" || string($3.datatype) == "letter"){
                    $$.datatype = "bool" ;
                    $$.is_array = false ;
                    $$.is_atomic = false ; 
                    cout << "473- " << $$.datatype << endl ;  
              }else{
                     printError(yylineno,TYPE_ERROR_RHS);
                     return 1;
              }
       }
       ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NDEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NLET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NTEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                | NVOID 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
                ;

atomicSimple : ANUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ADEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ABOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ALET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ATEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ; 

nonAtomicArray : NARRNUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRDEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRLET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NARRTEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ;

atomicArray : AARRNUM 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRDEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRLET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | AARRTEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              ;


/* DECLARATION STATEMENT : Only Declaration + Assignment */
errorDatatypes: IDENTIFIER| ATOMIC IDENTIFIER| ARRAY IDENTIFIER| ATOMIC ARRAY IDENTIFIER;

declaration : declarationStmt SEMICOLON 
            { 
                     i_tb.print();
                     fprintf(yyout, " : declaration statement"); 
            }
            | errorDatatypes IDENTIFIER 
            {
                     printError(yylineno,TYPE_NOT_FOUND); 
                     return 1;
            }
            ;


/* declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ; */

simpleDatatype : nonAtomicSimple 
                     {
                            $$.datatype = $1.datatype;
                            cout << "627-Datatype is: " << $$.datatype << endl ;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;    
                     }
              | atomicSimple 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NUDATATYPE 
                     {
                            $$.datatype = $1.datatype;
                            cout << "640-Datatype is: " << $$.datatype << endl ;
                            $$.is_array = false; 
                            $$.is_atomic = false;
                     }
           
          | ATOMIC AUDATATYPE 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = false; 
                            $$.is_atomic = true;
                     }
            
         ;
arrayDatatype  : nonAtomicArray 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | atomicArray 
                     {
                            
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | ARRAY NARRUDATATYPE 
                     {
                            $$.datatype = $2.datatype;
                            $$.is_array = true; 
                            $$.is_atomic = false;
                     }
            
         | ATOMIC ARRAY AARRUDATATYPE 
                     {
                            $$.datatype = $3.datatype;
                            $$.is_array = true; 
                            $$.is_atomic = true;
                     }
              ;

declarationStmt : simpleDatatype  
                {
                     // printf("%s\n",$1.datatype);
                     dt_state = $1.datatype;
                     array_state = false;
                     atomic_state = $1.is_atomic;
                } 
                simpleList
                | 
                arrayDatatype  
                {
                     dt_state = $1.datatype;
                     array_state = true;
                     atomic_state = $1.is_atomic;
                } 
                arrayList
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
                     i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array,0);
                     // i_tb.print();
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
                     i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array,0);
                     // i_tb.print();
              }
          | IDENTIFIER EQ RHS //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $1.datatype = (dt_state);
                     $1.is_array = array_state;
                     $1.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($1.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     cout << $3.datatype  << endl ;      
                     cout << $1.datatype << endl;
                     cout << (string($1.datatype) == string($3.datatype)) << endl ;
                     if(assignment($1.datatype, $3.datatype, 0)) {
                            i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array,0);
                     }else {
                            printError(yylineno,TYPE_ERROR_RHS_LHS);
                            return 1;
                     }
                     /*
                     Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state,
                     atomic_state, Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and
                     RHS.datatype
                     */
              }
          | simpleList COMMA IDENTIFIER EQ RHS //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $3.datatype = (dt_state);
                     $3.is_array = array_state;
                     $3.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($3.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     if(assignment($3.datatype,$5.datatype, 0)) {
                            i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array,0);
                     }else {
                            printError(yylineno,TYPE_ERROR_RHS_LHS);
                            return 1;
                     }
                     // i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $3.ID, dt_state, array_state, atomic_state,
                     Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                     */
              }
          ;

arrayList : IDENTIFIER SQUAREOPEN {array_dim = 0;} dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $1.datatype = (dt_state);
                     $1.is_array = array_state;
                     $1.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($1.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }

                     i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array,array_dim+1);
                     array_dim = 0;
                     // i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                     Scope Level
                     */
              }
          | arrayList COMMA IDENTIFIER SQUAREOPEN {array_dim=0;} dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $3.datatype = (dt_state);
                     $3.is_array = array_state;
                     $3.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($3.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }

                     i_tb.addVariable($3.ID, $3.datatype, $3.is_atomic, $3.is_array,array_dim+1);
                     array_dim = 0;
                     // i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, 
                     atomic_state, Scope Level
                     */
              }
          ;

array_inValues: INTEGERLITERAL 
              {
                     $$.intVal = $1.intVal;
              }
              | IDENTIFIER 
              {
                     $$.intVal = INT_MAX;
              }
              ;

dimlist : dimlist COMMA {array_dim++;} array_inValues
        | array_inValues
        ;

LHS :  IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
       {
              cout << "826 - " << $1.ID << endl ;
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno,VARIABLE_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]) ;
              $$.is_atomic = stoi(a[2]) ;
              /*
              Search for identifier, get it's attributes, 
              store in $1.datatype, $1.is_array, $1.is_atomic
              */
       }
       | IDENTIFIER {in_make_parallel_arrays = 2;curr_array_level = 0;} SQUAREOPEN arr_access SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
       {
              cout << "842 - " << $1.ID << endl ;
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno,VARIABLE_NOT_FOUND);
                     return 1;
              }
              if(stoi(a[1]) == 0){
                     printError(yylineno,NOT_AN_ARRAY);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]) ;
              $$.is_atomic = stoi(a[2]) ;
              cout << "855-" << curr_array_level << endl ;
              if(curr_array_level + 1 != stoi(a[3])){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
                     /*
                     Search for identifier, get it's attributes, store
                     in $1.datatype, $1.is_array, $1.is_atomic
                     */
                     /*
                     If is_array of Identifier is false, then semantic error
                     */
              curr_array_level = 0;
              in_make_parallel_arrays = 1;
       }
       | access 
       {
              $$.datatype = $1.datatype ;
              $$.is_array = false ;
              $$.is_array = false ;
       }
       | IN ARROW IDENTIFIER 
       {
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              vector<string> a = attr_tb.rhsSearchAttribute($3.ID,curr_type);
              if(a.size() == 0){
                     printError(yylineno,TYPE_ATTR_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]);
              $$.is_atomic = stoi(a[2]);
       }
       | IN ARROW IDENTIFIER {in_make_parallel_arrays = 2;curr_array_level = 0;} SQUAREOPEN arr_access SQUARECLOSE{
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              vector<string> a = attr_tb.rhsSearchAttribute($3.ID,curr_type);
              if(a.size() == 0){
                     printError(yylineno,TYPE_ATTR_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]);
              $$.is_atomic = stoi(a[2]);
              cout << "904-" << curr_array_level << endl ;
              if(curr_array_level +1 != stoi(a[3])){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
       }
       ;

arr_access: exprlist
          ;

exprlist: arith_expr
         | exprlist COMMA {curr_array_level++;} arith_expr
         ;

arith_operand: IDENTIFIER 
              {
                     cout <<"916-search identifier: "<<($1.ID) << endl ;
                     vector<string> a = i_tb.rhsSearchVariable($1.ID);
                     if(a.size() == 0){
                            printError(yylineno, VARIABLE_NOT_FOUND);
                            return 1;
                     }
                     if(string(a[0]) != "number"){
                            if(in_make_parallel_arrays == 2) {
                                   printError(yylineno,ARRAY_CANNOT_HAVE_NON_INTEGERS);
                                   return 1;
                            }
                            else if(in_make_parallel_arrays == 1) {
                                   printError(yylineno,MAKE_PARALLEL_ERROR);
                                   return 1;
                            }
                     }
                     $$.datatype = "number";
              }
              | INTEGERLITERAL
              {
                     $$.datatype = "number";
              }
              | ROUNDOPEN arith_expr ROUNDCLOSE
              {
                     $$.datatype = "number";
              }
              ;

arith_expr: arith_expr arithmetic_op arith_operand
          | arith_operand
          ;

 /*ASSIGNMENT STATEMENT*/
assignment_statement: LHS EQ RHS //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            if(!assignment($1.datatype, $3.datatype, 0)) {
                                   printError(yylineno,TYPE_ERROR_RHS_LHS);
                                   return 1;
                            }
                            /*
                            Type check for LHS.datatype, RHS.datatype
                            */
                     }
                    ;

 /*EXPRESSION STATEMENT*/
expression_statement: LHS expression_op RHS //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            if(!assignment($1.datatype, $3.datatype, 1)) {
                                   printError(yylineno,TYPE_ERROR_RHS_LHS);
                                   return 1;
                            }
                            if((string($1.datatype) == "decimal" ||  string($3.datatype) == "decimal") && (string($2.ID) == "%=")){
                                   printError(yylineno,MODULO_ASSIGNMENT_ERROR);
                                   return 1;
                            }
                            /* 
                            SHOULD COME BACK, THERE SHOULD BE A TYPE CHECK BTW LHS.datatype, RHS.datatype. 
                            IF IT MATCHES, WILL $$.datatype BE BOOLEAN? 
                            */
                           /* 
                           In this no user defined datatypes only primitive 
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

g: IDENTIFIER EQ RHS //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(i_tb.searchDeclaration($1.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if(!assignment($1.datatype, $3.datatype, 0)) {
                     printError(yylineno,TYPE_ERROR_RHS_LHS);
                     return 1;
              }
              i_tb.addVariable($1.ID, dt_state, atomic_state, array_state,0);
              i_tb.print();
              /*
              Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
 | g COMMA IDENTIFIER EQ RHS //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(i_tb.searchDeclaration($3.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if(!assignment($3.datatype, $5.datatype, 0)) {
                     printError(yylineno,TYPE_ERROR_RHS_LHS);
                     return 1;
              }
              i_tb.addVariable($2.ID, dt_state, atomic_state, array_state,0);
              /*
              Insert in Normal IDENTIFIER TABLE $2.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
       ;

both_assignment: assignment_statement //////////////////////////////// COMPLETED ///////////////////////////////
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
                            dt_state = $1.datatype;
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
loop: for_loop | while_loop ; //////////////////////////////// COMPLETED ///////////////////////////////

 /*FOR LOOP*/
for_loop      : FOR {scopeLevel++;} SQUAREOPEN both_assignment PIPE RHS 
              {
                     cout << "1068- Datatype: " << $6.datatype << endl ;
                     if(!(string($6.datatype) == "number" || string($6.datatype) == "letter" || string($6.datatype) == "decimal" || string($6.datatype) == "bool") ){
                            printError(yylineno,PREDICATE_ERROR);
                            return 1;
              }
              } 
              PIPE exprrr SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN statements //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
              } 
              SCOPECLOSE 
              ;

 /*WHILE LOOP*/
while_loop :  REPEAT SQUAREOPEN RHS 
              {
                     cout << "1085 - Datatype: " << $3.datatype << endl ;
                     if(!(string($3.datatype) == "number" || string($3.datatype) == "letter" || string($3.datatype) == "decimal" || string($3.datatype) == "bool") ){
                     printError(yylineno,PREDICATE_ERROR);
                     return 1;
                     }
              } 
              SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN {scopeLevel++;} statements  //////////////////////////////// COMPLETED ///////////////////////////////
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
conditional: when_statement; //////////////////////////////// COMPLETED ///////////////////////////////

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS 
       {
              cout << "1114- Datatype: " << $3.datatype << endl ;
              if(!(string($3.datatype) == "number" || string($3.datatype) == "letter" || string($3.datatype) == "decimal" || string($3.datatype) == "bool") ){
              printError(yylineno,PREDICATE_ERROR);
              return 1;
              }
       } 
       SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements //////////////////////////////// COMPLETED ///////////////////////////////
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE extend 
       ;
extend : ELSE_WHEN SQUAREOPEN RHS 
       {
              cout << "1128- Datatype: " << $3.datatype << endl ;
              if(!(string($3.datatype) == "number" || string($3.datatype) == "letter" || string($3.datatype) == "decimal" || string($3.datatype) == "bool") ){
              printError(yylineno,PREDICATE_ERROR);
              return 1;
              }
       } SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements //////////////////////////////// COMPLETED ///////////////////////////////
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE extend 
       | DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       | subroutine
       ;

 /*DEFAULT STATEMENT (occurs only once)*/
/* when_default: DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       | subroutine
       ;   */

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER 
              {
                     /*
                     SHOULD COME BACK, WHAT ARE THESE?
                     */
              } ; 

analyze_statement : ANALYZE analyze_label COLON analyze_label COLON IDENTIFIER COLON IDENTIFIER SEMICOLON { fprintf(yyout, " : analyze statement");  }
       {
       /* 
       SHOULD COME BACK, WHAT ARE THESE? 
       */
       } ;

// RHS:  RHS;

func_invoke2 : func_invoke SEMICOLON { fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER subroutine_in_args COLON arguments COLON 
       {
              /*
              BY here list of arg_dat (list of arguement's datatypes) will be ready. 
              For all functions with name as $2.ID, type check arguements
              */
              printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              vector<string> a = f_tb.rhsSearchFunction($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(a.size() == 0){
                     printError(yylineno, FUNCTION_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]);
              $$.is_atomic = false ;
              arg_dat.clear();
              arg_is_array.clear();
              arg_is_atomic.clear();
              in_call_args = 0;
       }
       | INVOKE IDENTIFIER subroutine_in_args COLON NULL_ARGS COLON 
       {
          /*
          For all functions with name as $2.ID, type check if arguements are null
          */
          vector<string> a = f_tb.rhsSearchFunction($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
          if(a.size() == 0){
                 printError(yylineno, FUNCTION_NOT_FOUND);
                 return 1;
          }
          $$.datatype = cstr(a[0]);
          $$.is_array = stoi(a[1]);
          $$.is_atomic = false ;
          printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
          arg_dat.clear();
          arg_is_array.clear();
          arg_is_atomic.clear();
       }
       ;


arguments : arguments COMMA RHS 
          {
              arg_dat.push_back(($3.datatype));
              arg_is_array.push_back($3.is_array);
              arg_is_atomic.push_back($3.is_atomic);
          }
          | RHS 
          {
              arg_dat.push_back($1.datatype);
              arg_is_array.push_back($1.is_array);
              arg_is_atomic.push_back($1.is_atomic);
          }
          ;

/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER subroutine_in_args COLON  arith_expr COLON arith_expr COLON arguments COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              {
                     /*
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */
                     if(!t_tb.searchTask($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic)){
                            printError(yylineno, TASK_NOT_FOUND);
                            return 1;
                     }
                     printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     arg_is_array.clear();
                     arg_is_atomic.clear();
                     arg_dat.clear();
                     in_call_args = 0;
              }
              | MAKE_PARALLEL IDENTIFIER subroutine_in_args COLON arith_expr COLON arith_expr COLON NULL_ARGS COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              {
                     if(!t_tb.searchTask($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic)){
                            printError(yylineno, TASK_NOT_FOUND);
                            return 1;
                     }
                     printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     arg_dat.clear();
                     arg_is_array.clear();
                     arg_is_atomic.clear();
              }
              ;
              
/*get statement*/
get_invoke : GET ARROW TIME ;

/*SLEEP STATEMENT*/
sleep : SLEEP ROUNDOPEN FLOATLITERAL ROUNDCLOSE SEMICOLON { fprintf(yyout, " : sleep statement");  };
       | SLEEP ROUNDOPEN INTEGERLITERAL ROUNDCLOSE SEMICOLON { fprintf(yyout, " : sleep statement");  };

/* Grammar Rules for Input and Output*/
file_name : ARROW STRINGLITERAL
          | ARROW IDENTIFIER
          {
              vector<string> a = i_tb.rhsSearchVariable($2.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              string b = "text" ;
              cout <<"1299 - " << a[0] << endl ;
              if(a[0] != b) {
                     printError(yylineno,NOT_STRING);
              }
              if(stoi(a[1]) == 1) {if(stoi(a[3]) != curr_array_level + 1){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
              }
          }
          | subroutine
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
             {
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              cout << a[0] << " "<<a[1]<< endl ;
              if(stoi(a[1]) && stoi(a[3]) != curr_array_level + 1){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
             }
            ;

/* Return */
return_statement : RETURN RHS SEMICOLON 
                 { 
                     if(func_start == 0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if($2.is_array == 1 && return_dim_count != 1){
                            printError(yylineno,INCOMPITABLE_ARRAY_DIMS);
                            return 1;
                     }
                     if(!(compatibility(string($2.datatype), return_type) && $2.is_array == is_array_ret)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     $$.datatype = $2.datatype; 
                     $$.is_array = $2.is_array; 
                     /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/
                     fprintf(yyout, " : return statement"); 
                 } ;
                 | RETURN NVOID SEMICOLON 
                 { 
                     if(func_start == 0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if(!(string($2.datatype) == "void" && is_array_ret == 0)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     $$.datatype = $2.datatype; 
                     $$.is_array = $2.is_array; 
                     /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/ 
                     fprintf(yyout, " : return statement"); 
                 } ;

/*PRINT STATEMENT*/
output : OP file_name COLON opstring SEMICOLON
       { 
       //  fprintf(yyout, " : print statement");
       }
      ;

opstring : stringvalues nextop 
         ;

nextop : HASH stringvalues nextop
       | subroutine
       ;


/*FUNCTION DECLARATION AND IMPLEMENTATION SCOPE*/

function: func_decl func_body 
        | atomic_func_decl func_body
        ;

func_args: all_datatypes IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
       {
              cout << "1351 - is_array: " << $1.is_array << endl ;
              decl_arg_dat.push_back($1.datatype);
              decl_arg_is_array.push_back($1.is_array);
              decl_arg_is_atomic.push_back($1.is_atomic);
              if(i_tb.searchDeclaration($2.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if($1.is_array == true) 
              i_tb.addVariable($2.ID, $1.datatype, $1.is_atomic, $1.is_array,1);
              else i_tb.addVariable($2.ID, $1.datatype, $1.is_atomic, $1.is_array,0);
       } /*SHOULD COME BACK and see the order they are getting stored in*/
       | func_args COMMA all_datatypes IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
       {
              cout << "1365 - is_array: " << $3.is_array << endl ;
              decl_arg_dat.push_back(($3.datatype));
              decl_arg_is_array.push_back($3.is_array);
              decl_arg_is_atomic.push_back($3.is_atomic);
              if(i_tb.searchDeclaration($4.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if($3.is_array == true)
              i_tb.addVariable($4.ID, $3.datatype, $3.is_atomic, $3.is_array,1);
              else i_tb.addVariable($4.ID, $3.datatype, $3.is_atomic, $3.is_array,0);
       } 
       ;

args: func_args
    | NULL_ARGS
    ;

func_return : nonAtomic_datatypes 
              {
                     $$.datatype = $1.datatype; 
                     $$.is_array = $1.is_array; 
                     /*Atomic is not needed*/
              }
            | NUDATATYPE 
            {
              $$.datatype = $1.datatype; 
              $$.is_array = $1.is_array; 
              /*Atomic is not needed*/
            }
            | IDENTIFIER {{printError(yylineno,TYPE_NOT_FOUND); return 1;};}
            ;

func_decl :   FUNC {scopeLevel++;func_start = 1;} IDENTIFIER COLON args COLON func_return //////////////////////////////// COMPLETED ///////////////////////////////
              { 
                     /*
                     Add args as they are encountered in the id_table, IN FUNCTIONS TABLE, name of the function
                     is $2.ID decl_arg_dats will be ready, return_type is $6.datatype, $6.is_array 
                     */ 
                    if(f_tb.searchFunction($3.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                     f_tb.addFunction($3.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$7.datatype, $7.is_array);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return_type = $7.datatype ;
                     is_array_ret = $7.is_array ; 
                     fprintf(yyout, " : function declaration statement");
                     f_tb.print();
                    }else {
                     printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return 1 ;
                     fprintf(yyout, " : function declaration statement");
                    }
              } 
              ;
atomic_func_decl :   ATOMIC FUNC {scopeLevel++;func_start = 1;chkAtomic = 0;} IDENTIFIER COLON args COLON func_return //////////////////////////////// COMPLETED ///////////////////////////////
                     { 
                            /*
                            Add args as they are encountered in the id_table, decl_arg_dats will be ready, return_type
                            is $6.datatype, $6.is_array 
                            */ 
                     if(f_tb.searchFunction($4.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                            f_tb.addFunction($4.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$8.datatype, $8.is_array);
                            decl_arg_dat.clear(); 
                            decl_arg_is_array.clear();
                            decl_arg_is_atomic.clear();
                            
                     return_type = $8.datatype ;
                     is_array_ret = $8.is_array ; 
                     cout << "1435 - return_type: "<<return_type << endl ;
                     cout << "1436 - ret_is_array: "<<is_array_ret << endl ;
                            fprintf(yyout, " : function declaration statement");
                            f_tb.print();
                     }
                     else {
                            printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                            decl_arg_dat.clear(); 
                            decl_arg_is_array.clear();
                            decl_arg_is_atomic.clear();
                            return 1 ;
                            fprintf(yyout, " : function declaration statement");
                            }
                     }
                     ;

func_body : SCOPEOPEN func_statements 
       {
              if(number_of_returns == 0){
                     printError(yylineno,FUNCTION_MUST_HAVE_1_RETURN);
                     return 1;
              }
              func_start = 0;
              i_tb.deleteVariables();
              scopeLevel--;
              return_type = NULL ;
              is_array_ret = 0;
              number_of_returns = 0;
              func_start = 0 ; 
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
               | subroutine
               ;

/* Task declaration and implemenatation scope */
task: TASK IDENTIFIER COLON {scopeLevel++;in_task = 1;} args //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(!t_tb.searchTask($2.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic)){
                     t_tb.addTask($2.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     t_tb.print();
                    }else {
                     printError(yylineno, TASK_REDECLARATION_ERROR);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return 1 ;
                    }
              fprintf(yyout, " : task declaration statement");
       }
              SCOPEOPEN taskscope 
       {
              i_tb.deleteVariables();
              scopeLevel--;
              in_task = 0;
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
        | subroutine
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
          | subroutine
          ;
          
          
access : IDENTIFIER {
       cout << "1544 - " << $1.ID << endl ;
       vector<string> b = i_tb.rhsSearchVariable($1.ID);
       if(b.size() == 0){
              printError(yylineno,VARIABLE_NOT_FOUND);
              return 1;
       }
       if(stoi(b[1]) == 1){
              printError(yylineno,ARRAY_CANNOT_BE_ACCESSED_USING_ARROW);
              return 1;
       }
       tok = 1;
       dt_type = cstr(b[0]);
       } ARROW id 
       {
              /*$1.datatype should be from an existing class*/ 
              // $$.datatype = ;
              // cout << "Datatype at end: "<<$4.datatype << endl ;
              $$.datatype = $4.datatype ;
              dt_type = NULL ;
              tok = 0;
       }
       ;

id     : IDENTIFIER
        {     
              if(tok == 1){
                     // cout <<"Here" << endl;
                     vector<string> a = attr_tb.rhsSearchAttribute($1.ID,dt_type);
                     if(a.size() == 0){
                            printError(yylineno,TYPE_ATTR_NOT_FOUND);
                            return 1;
                     }
                     if(stoi(a[1]) == 1){
                            printError(yylineno,ARRAY_CANNOT_BE_ACCESSED_USING_ARROW);
                            return 1;
                     }
                     $$.datatype = cstr(a[0]);
              }else {
                     // cout << "There" << endl ;
                     cout << "1579 - " << $1.ID << endl ;
                     vector<string> b = i_tb.rhsSearchVariable($1.ID);
                     // cout << $1.ID << endl ;
                     if(b.size() == 0){
                            printError(yylineno,VARIABLE_NOT_FOUND);
                            return 1;
                     }
                     if(stoi(b[1]) == 1){
                            printError(yylineno,ARRAY_CANNOT_BE_ACCESSED_USING_ARROW);
                            return 1;
                     }
                     $$.datatype = cstr(b[0]);
              }
       }
       | id ARROW IDENTIFIER 
       {
              /*
                     Type check that t_state is existing in the types_set, and it has an attribute named $3.ID
              */ 
              /*
                     After the check is done, we are supposed to update the t_state to the last identifier type
              */ 
              // cout << "OMG" << endl ;
              // cout << $3.ID <<" "<< $1.datatype << endl ;
              vector<string> a = attr_tb.rhsSearchAttribute($3.ID,$1.datatype);
              if(a.size() == 0){
                     printError(yylineno,TYPE_ATTR_NOT_FOUND);
                     return 1;
              }
              if(stoi(a[1]) == 1){
                     printError(yylineno,ARRAY_CANNOT_BE_ACCESSED_USING_ARROW);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
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
     | subroutine
     ;

/* TYPE DEFINITION */

type_declaration: TYPE TYPENAME //////////////////////////////// COMPLETED ///////////////////////////////
              { 
                     if(c_tb.searchType($2.token)){
                            printError(yylineno,TYPE_REDECLARATION);
                            return 1;
                     }
                     c_tb.addType($2.token);
                     c_tb.print();
                     curr_type = ($2.token);
                     cout<< "1680 - current type: " << curr_type << endl ;
                     fprintf(yyout, " : type declaration statement"); 

              } SCOPEOPEN {scopeLevel++;in_scope = 1;} type_scope methods 
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
                     curr_type = NULL ;
                     attr_tb.print();
                     in_scope = 0;
              } SCOPECLOSE
              ;

type_scope: declaration_t type_scope | subroutine ;

declaration_t : declarationStmt_t SEMICOLON 
              { 
                     fprintf(yyout, " : declaration statement"); 
              }
              | errorDatatypes IDENTIFIER {printError(yylineno,TYPE_NOT_FOUND); return 1;};
              ;

declarationStmt_t : simpleDatatype {
                            dt_state = $1.datatype;
                            cout << "datatype: " << $1.datatype << endl ;
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } simpleList_t
                | arrayDatatype {
                            dt_state = $1.datatype;
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } arrayList_t
                ;

simpleList_t: IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,0);
                                   // attr_tb.print();
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
          | simpleList_t COMMA IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;
                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array,0);
                                   // attr_tb.print();
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
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,0);
                                   // attr_tb.print();
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
          | simpleList_t COMMA IDENTIFIER EQ RHS 
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array,0);
                                   // attr_tb.print();
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

arrayList_t : IDENTIFIER SQUAREOPEN {array_dim = 0;} dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,array_dim +1);
                                   // attr_tb.print();
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            array_dim = 0;
                            /*
                            Insert in ATTRIBUTES $1.ID, dt_state, array_state, class_name will be the
                            last one from the types_Set atomic_state
                            */
                     }
          | arrayList_t COMMA IDENTIFIER SQUAREOPEN {array_dim = 0;} dimlist SQUARECLOSE //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $3.datatype = (dt_state);
                            $3.is_array = array_state;
                            $3.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($3.ID, curr_type) == ""){
                                   attr_tb.addVariable($3.ID, curr_type, $3.datatype, $3.is_atomic, $3.is_array,array_dim + 1);
                                   // attr_tb.print();
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            array_dim = 0;
                            /*
                            Insert in ATTRIBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name 
                            will be the last one from the types_Set
                            */
                     }
                     ;

methods: methods method
       | subroutine
       ;

method: func_decl_m SCOPEOPEN method_body //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(number_of_returns == 0){
                     printError(yylineno,FUNCTION_MUST_HAVE_1_RETURN);
                     return 1;
              }
              i_tb.deleteVariables();
              scopeLevel--;
              return_type = NULL ;
              is_array_ret = 0 ; 
              func_start = 0;
              number_of_returns = 0;
       } SCOPECLOSE ;

func_decl_m : FUNC IDENTIFIER COLON {scopeLevel++;func_start = 1;} args COLON func_return //////////////////////////////// COMPLETED ///////////////////////////////
              {
              /*
              Add args as they are encountered in the IDENTIFIER TABLE, 
              IN METHODS TABLE: $2.ID is method name, decl_arg_dats will be ready, 
              return_type is $6.datatype, $6.is_array class name will be the last element in the types_set
              */ 

              if(m_tb.searchMethod($2.ID, curr_type, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                     m_tb.addMethod($2.ID, curr_type, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$7.datatype, $7.is_array);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return_type = $7.datatype ;
                     is_array_ret = $7.is_array ; 
                     fprintf(yyout, " : function declaration statement");
                     m_tb.print();

                    }
              else {
                     printError(yylineno, METHOD_REDECLARATION_ERROR);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return 1 ;
                     fprintf(yyout, " : function declaration statement");
              }
                     decl_arg_dat.clear(); fprintf(yyout, " : function declaration statement"); 
              } 
              ;

method_invoke2 : method_invoke SEMICOLON  { fprintf(yyout, " : call statement"); }  ;

method_args : arguments | NULL_ARGS ;

method_invoke : INVOKE id ARROW IDENTIFIER subroutine_in_args COLON method_args COLON
              {
                     /* 
                     Type check: $2.datatype should be a class, and $4.ID should be a function 
                     in that class
                     */ 
                     /*
                     BY here list of arg_dat (list of arguement's datatypes) will be ready. 
                     For all mthods with name as $2.ID, type check arguements
                     */
                     // cout << "Here" << endl ;
                     vector<string> b = m_tb.rhsSearchMethod($4.ID,$2.datatype,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     if(b.size() == 0){
                            printError(yylineno, METHOD_NOT_FOUND);
                            return 1;
                     }
                     $$.datatype = cstr(b[0]);
                     $$.is_array = stoi(b[1]);
                     $$.is_atomic =  false;
                     arg_is_array.clear();
                     arg_is_atomic.clear();
                     arg_dat.clear();
                     in_call_args = 0;
              }
              
in_stmt : IN ARROW IDENTIFIER 
       {
              cout << "1909 - In the type: " << $3.ID << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              vector<string> a = attr_tb.rhsSearchAttribute($3.ID,curr_type);
              if(a.size() == 0){
                     printError(yylineno,TYPE_ATTR_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_array = stoi(a[1]);
              $$.is_atomic = stoi(a[2]);
              /*
              In this check if $3.datatype = last element in the type set
              */
       }
       | INVOKE IN ARROW IDENTIFIER subroutine_in_args COLON arguments COLON 
       {
              cout << "1928 - Hereeeeeeeeee" << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              cout << "1933 - Current type: " << curr_type << endl ; 

              vector<string> a = m_tb.rhsSearchMethod($4.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(a.size() == 0){
                     printError(yylineno,METHOD_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_atomic = false ;
              $$.is_array = stoi(a[1]) ;
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set
               + TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
             printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              arg_dat.clear();
              arg_is_array.clear();
              arg_is_atomic.clear();
              in_call_args = 0;
       }
       | INVOKE IN ARROW IDENTIFIER subroutine_in_args COLON NULL_ARGS COLON 
       {      
              cout << "1954 - Theeeereeeee" << endl ;
              cout << arg_dat.size() << arg_is_array.size() << arg_is_atomic.size() << endl;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }      
              vector<string> a = m_tb.rhsSearchMethod($4.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(a.size() == 0){
                     printError(yylineno,METHOD_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_atomic = false ;
              $$.is_array = stoi(a[1]) ;
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set + 
              TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
              printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              arg_dat.clear();
              arg_is_array.clear();
              arg_is_atomic.clear();
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
                 | INVOKE IN ARROW IDENTIFIER subroutine_in_args COLON NULL_ARGS COLON 
       {      
              cout << "1998 - Theeeereeeee" << endl ;
              cout << arg_dat.size() << arg_is_array.size() << arg_is_atomic.size() <<" "<<$4.ID  << endl;
              printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }      
              vector<string> a = m_tb.rhsSearchMethod($4.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(a.size() == 0){
                     printError(yylineno,METHOD_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_atomic = false ;
              $$.is_array = stoi(a[1]) ;
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set + 
              TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
              printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              arg_dat.clear();
              arg_is_array.clear();
              arg_is_atomic.clear();
       }|            INVOKE IN ARROW IDENTIFIER subroutine_in_args COLON arguments COLON 
       {
              cout << "2023 - Hereeeeeeeeee" << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              cout << "2028 - Current type: " << curr_type << endl ; 

              vector<string> a = m_tb.rhsSearchMethod($4.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              if(a.size() == 0){
                     printError(yylineno,METHOD_NOT_FOUND);
                     return 1;
              }
              $$.datatype = cstr(a[0]);
              $$.is_atomic = false ;
              $$.is_array = stoi(a[1]) ;
              /*
              In this check if $4.ID exists in the methods table whose class is last element in the types_set
               + TYPE CHECK FOR PARARMETERS AND RETURN TYPES, SAME AS FUNCTION
              */
             printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
              arg_dat.clear();
              arg_is_array.clear();
              arg_is_atomic.clear();
              in_call_args = 0;
       }
                 ;
/* Return */
return_statement_m : RETURN RHS SEMICOLON 
              { 
                     cout << "2051 - Return is : " << $2.datatype << endl ;
                     if(func_start ==0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if($2.is_array == 1 && return_dim_count != 1){
                            printError(yylineno,INCOMPITABLE_ARRAY_DIMS);
                            return 1;
                     }
                     if(!(compatibility(string($2.datatype), return_type) && $2.is_array == is_array_ret )){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
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
              | RETURN NVOID SEMICOLON 
              { 
                     if(func_start ==0){
                           printError(yylineno,INVALID_USE_OF_RETURN);
                           return 1;
                     }
                     if(!(string($2.datatype) == "void" && is_array_ret == 0)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     number_of_returns++;
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
           | subroutine
           ;
           
%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
