%{
  #include <iostream>
  #include <string>
  #include <fstream>
  #include <climits>
  #include "errors.hpp"
  #include "symbol_table.hpp"
  #include "semantics.hpp"   
  #include "CodeGen.hpp"
  #include <string.h>

  extern int yylex();
  extern int yylineno;
  extern FILE * yyout, *fpcpp;
  extern int chkAtomic;
  void yyerror(std::string s);
  char * dt_state ;
  int array_state;
  int atomic_state;

  int makeParallel = -1;
  char * task_name, * num_thr, * runs;

  char * curr_type ;

  std::vector<std::string> func_array;
  std::vector<std::string> task_array;
  std::vector<std::string> method_array;

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
  int io=0;
  int io1 = 0;
  int atm = 0;
  int arr = 0;
  char * forPowassign = NULL ;
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
           char *stringVal; // If encountered a strin  g constant, will store value here
           char *token; // If encountered a token string like for/while, will store value here
           char *converted; // If the given code has C++ reserved keywords, the changed variable name will be stored here.
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
%token<attr> PIPE
%token<attr> IDENTIFIER
%token<attr> COMMA SEMICOLON COLON
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

%type<attr> subroutine_io  return_statement_m func_decl_m declaration_t func_return all_datatypes expression_op comparison_op arithmetic_op logical_op nonAtomic_datatypes E T all_ops constants next 
%type<attr> RHS nonAtomicSimple atomicSimple nonAtomicArray atomicArray declaration simpleDatatype arrayDatatype declarationStmt simpleList arrayList array_inValues dimlist LHS arr_access exprlist arith_expr arith_operand 
%type<attr> assignment_statement expression_statement exprrr log g both_assignment loop for_loop while_loop conditional when_statement analyze_label analyze_statement func_invoke2 func_invoke arguments 
%type<attr> task_invoke get_invoke sleep file_name input nextip stringvalues return_statement output opstring nextop func_decl atomic_func_decl func_body func_scope func_statements statement statements access id startdec 
%type<attr> start type_declaration type_scope methods method method_invoke2 method_args method_invoke in_stmt method_statements method_body subroutine_token subroutine_id  subroutine_intVal subroutine_decVal subroutine_charVal 
%type<attr> subroutine_boolVal subroutine_stringVal subroutine subroutine_rs subroutine_array subroutine_narray func_args subroutine_in_args

%start begin

%%

subroutine_in_args : %empty{in_call_args = 1;} ;


subroutine_token: %empty {fprintf(fpcpp, "%s ", yylval.attr.token);};
subroutine_id: %empty {fprintf(fpcpp, "%s", yylval.attr.converted);}; // Should be changed to yylval.attr.converted
// subroutine_datatype: %empty {fprintf(fpcpp, "%s", yylval.attr.converted);}; // Should be changed to yylval.attr.converted
//subroutine_is_atomic: %empty {fprintf(fpcpp, "%s", yylval.attr.is_atomic);};
/* %type<attr> subroutine_is_atomic subroutine_is_array subroutine_datatype*/
//subroutine_is_array: %empty {fprintf(fpcpp, "%s", yylval.attr.is_array);};
subroutine_intVal: %empty {fprintf(fpcpp, "%d", yylval.attr.intVal);};
subroutine_decVal: %empty {fprintf(fpcpp, "%f", yylval.attr.decVal);};
subroutine_charVal: %empty {fprintf(fpcpp, "%c", yylval.attr.charVal);};
subroutine_boolVal: %empty {fprintf(fpcpp, "%d", yylval.attr.boolVal);};
subroutine_stringVal: %empty {fprintf(fpcpp, "%s", yylval.attr.stringVal);};
subroutine_io: %empty {if(io==1){fprintf(fpcpp,"cin ");} else{fprintf(fpcpp,"// // cout ");}}
subroutine_rs: %empty {if(io==1){fprintf(fpcpp," >> ");} else{fprintf(fpcpp,"<< ");}}
subroutine_fileH: %empty {if(io==1){fprintf(fpcpp,"\n\tifstream fin(");} else{fprintf(fpcpp,"\n\tofstream fop(");}} 
subroutine_fio: %empty {if(io==1){fprintf(fpcpp,"; fin");} else{fprintf(fpcpp,"; fop");}}
subroutine_fileC: %empty {if(io1 == 0){if(io==1){fprintf(fpcpp," fin.close();\n");} else{fprintf(fpcpp," fop.close();\n");}}}
subroutine_array: %empty {arr = 1;}
subroutine_narray: %empty {arr = 0;}
subr_init: %empty {io1 = 1;}
subroutine: %empty {;};

subroutine_roundopen: %empty {fprintf(fpcpp, "(");} ;
subroutine_roundclose: %empty {fprintf(fpcpp, ")");} ;

subroutine_openscope: %empty {fprintf(fpcpp,"{");} ;
subroutine_closescope: %empty {fprintf(fpcpp,"}");} ;

subr_this: %empty { fprintf(fpcpp, "this"); };

subr_sleep: %empty { fprintf(fpcpp, "usleep"); } ;

all_datatypes: NUDATATYPE subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | AUDATATYPE subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ARRAY NARRUDATATYPE 
                     {
                            // cout << "132 - Hereeee" << endl ;
                            $$.datatype = $2.datatype;
                            $$.is_array = $2.is_array;
                            $$.is_atomic = $2.is_atomic;
                            // cout << "136, dtype: " << $$.datatype << ", is_array: " << $$.is_array << ", is_atomic: "<<$$.is_atomic << endl ;
                     }
             | ATOMIC ARRAY AARRUDATATYPE
                     {
                            $$.datatype = $3.datatype;
                            $$.is_array = $3.is_array;
                            $$.is_atomic = $3.is_atomic;
                     }
             | NBOOL subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NDEC subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NNUM subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NTEXT subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | NLET subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ABOOL subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ADEC subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ALET subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ATEXT subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | ANUM subroutine_narray
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
             | subroutine_array nonAtomicArray 
             {
              /*
              Will be handled down
              */
             $$.converted = $2.converted;
             }
             | subroutine_array atomicArray 
             {
              /*
              Will be handled down
              */
              }
             ;

expression_op: ASSN_DIV subroutine_token
              {
                $$.ID = $1.token;
              }
              | ASSN_MODULO subroutine_token
              {
                $$.ID = $1.token;
              } 
              | ASSN_MUL subroutine_token
              {
                $$.ID = $1.token;
              } | INCR subroutine_token
              {
                $$.ID = $1.token;
              } | DECR subroutine_token
              {
                $$.ID = $1.token;
              } 
              ;
comparison_op: LT subroutine_token {$$.ID = $1.token;} 
              | GT subroutine_token {$$.ID = $1.token;} 
              | GTEQ subroutine_token {$$.ID = $1.token;} 
              | LTEQ subroutine_token {$$.ID = $1.token;} 
              | NOT_EQ subroutine_token {$$.ID = $1.token;} 
              | EQUAL_TWO subroutine_token {$$.ID = $1.token;} 
              ;
arithmetic_op: ADD subroutine_token {$$.ID = $1.token;} 
              | SUB subroutine_token {$$.ID = $1.token;} 
              | MUL subroutine_token {$$.ID = $1.token;} 
              | DIV subroutine_token {$$.ID = $1.token;} 
              | MODULO subroutine_token {$$.ID = $1.token;}
              | EXPONENT subroutine_token {$$.ID = $1.token;} 
              ;
logical_op: AND subroutine_token {$$.ID = $1.token;} 
          | OR subroutine_token {$$.ID = $1.token;} 
          ;
nonAtomic_datatypes: nonAtomicArray | nonAtomicSimple ;


begin : %empty {
              if(startCount < 1){
                     printError(yylineno,START_ERROR_LESS);
                     return 1 ;
              }
       }
      | startdec begin
      | declaration begin
      | function begin
      | task begin
      | type_declaration begin
      ;


/* RHS */

E      :    subroutine
       | SQUAREOPEN {curr_array_level = 0;fprintf(fpcpp, "%s", $1.token);} arr_access SQUARECLOSE { fprintf(fpcpp, "%s", $4.token); }
       {
              // // cout << "273 - " << $1.ID << endl ;
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              if(stoi(a[1]) != 1){
                     printError(yylineno,NOT_AN_ARRAY);
                     return 1;
              }
              // // cout << "283-" << curr_array_level <<", ID level: "<<stoi(a[2]) << endl ;
              if(stoi(a[3]) != curr_array_level + 1){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
       }
       ;

T : IDENTIFIER {curr_array_level = -1;} subroutine_id E 
       {
              var_name = $1.ID ;
              // // cout << "294-Search Variable is: " << var_name << endl ;    
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno, VARIABLE_NOT_FOUND);
                     return 1;
              }
              // // cout <<"300-Datatype of " << var_name << " is "<< a[0] << endl ;
              return_dim_count = stoi(a[3]);
              // // cout << "302-Return dim count: "<< return_dim_count << endl ;
              var_name = "" ;
              $$.datatype =  cstr(a[0]);
              $$.is_atomic = stoi(a[2]);
              // // cout << "304- Datatype is " << $$.datatype << endl ;
              // // cout <<"306 - Current array level " << curr_array_level << endl ;
              // // cout <<"311 - in call args " << in_call_args << endl ;
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
              fprintf(fpcpp, "+");
              $$.ID = $1.token ;
      } 
      ;

constants: INTEGERLITERAL subroutine_intVal
       {
              $$.datatype = "number"; 
              $$.is_array = false ;
              $$.is_atomic = false ;
              $$.intVal = $1.intVal;
       } 

     | CHARACTERLITERAL subroutine_charVal
              {
                     $$.datatype = "letter"; 
                     $$.is_array = false ;
                     $$.is_atomic = false ;
                     $$.charVal = $1.charVal;
              } 

      | FLOATLITERAL subroutine_decVal
              {
                     $$.datatype = "decimal"; 
                     $$.is_array = false ;
                     $$.is_atomic = false ;
                     $$.decVal = $1.decVal;
              } 

      | BOOLEANLITERAL subroutine_boolVal
        {
              $$.datatype = "bool"; 
              $$.is_array = false ;
              $$.is_atomic = false ;
              $$.boolVal = $1.boolVal;
        }

       | STRINGLITERAL subroutine_stringVal
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
              // // cout << "383: "<<$1.datatype << " " << $3.datatype << " " << $2.ID << endl ;
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
    | TID subroutine_token
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
    | ROUNDOPEN subroutine_roundopen RHS all_ops next subroutine_roundclose ROUNDCLOSE
    {
       string a = is_coercible_rhs(string($3.datatype),string($5.datatype),$4.ID);
       // // cout << "443-"<<$3.datatype << " " << $5.datatype << " " << $4.ID << endl ;
       // cout << a << endl ;
       if( a == "" ){
              printError(yylineno,TYPE_ERROR_RHS);
              return 1 ;
       }
       $$.datatype = cstr(a) ;
       $$.is_atomic = false ;
       $$.is_array = false ;
    }
    | ROUNDOPEN subroutine_roundopen RHS subroutine_roundclose ROUNDCLOSE 
    {
       $$.datatype = $3.datatype ;
       $$.is_array = $3.is_array ;
       $$.is_atomic = $3.is_atomic ;
    }
    | NEG ROUNDOPEN RHS ROUNDCLOSE
       {
              // // cout << "468- " << $3.datatype << endl ;
              if(string($3.datatype) == "number" || string($3.datatype) == "decimal" || string($3.datatype) == "bool" || string($3.datatype) == "letter"){
                    $$.datatype = "bool" ;
                    $$.is_array = false ;
                    $$.is_atomic = false ; 
                    // // cout << "473- " << $$.datatype << endl ;  
              }
       }
       ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM 
                     {
                            // cout << "I must be here1\n";
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
                | NDEC 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                            // printf("%s\n", $1.converted);
                            // cout << "I must be here1 " << std::string($1.converted) << " Here\n";
                     }
                | NBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
                | NLET 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
                | NTEXT 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
                | NVOID
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
                ;

atomicSimple : ANUM
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | ADEC
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | ABOOL
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | ALET
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | ATEXT
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              ; 

nonAtomicArray : NARRNUM
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | NARRDEC
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | NARRBOOL
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | NARRLET
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | NARRTEXT
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              ;

atomicArray : AARRNUM
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | AARRDEC
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | AARRBOOL 
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;                     }
              | AARRLET
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              | AARRTEXT
                     {
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            $$.converted = $1.converted;
                     }
              ;


/* DECLARATION STATEMENT : Only Declaration + Assignment */
errorDatatypes: IDENTIFIER | ATOMIC IDENTIFIER | ARRAY IDENTIFIER | ATOMIC ARRAY IDENTIFIER;

declaration : declarationStmt SEMICOLON subroutine_token 
            { 
                     // i_tb.print();
                     fprintf(yyout, " : declaration statement"); 
            }
            | errorDatatypes IDENTIFIER subroutine_token  
            {
                     printError(yylineno,TYPE_NOT_FOUND); 
                     return 1;
            }
            ;


simpleDatatype : nonAtomicSimple
                     {      
                            // cout << "I came here " << std::string($1.converted) << " there"<< "\n";
                            // fprintf(fpcpp, "%s", $1.converted);
                            $$.datatype = $1.datatype;
                            // cout << "627-Datatype is: " << $$.datatype << endl ;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            // $$.converted    
                     }
              | atomicSimple 
                     {
                            fprintf(fpcpp, "atomic <%s>", $1.converted);
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                     }
              | NUDATATYPE
                     {
                            // // cout << "I am here, the user defined datatype!\n";
                            // fprintf(fpcpp, "%s", $1.datatype);
                            $$.datatype = $1.datatype;
                            // // cout << "640-Datatype is: " << $$.datatype << endl ;
                            $$.is_array = false; 
                            $$.is_atomic = false;
                     }
           
          | ATOMIC AUDATATYPE
                     {
                            fprintf(fpcpp, "%s<%s>", $1.token, $2.datatype);
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
                            fprintf(fpcpp, "%s", $1.converted);
                     }
              | atomicArray 
                     {
                            
                            $$.datatype = $1.datatype;
                            $$.is_array = $1.is_array;
                            $$.is_atomic = $1.is_atomic;
                            fprintf(fpcpp, "atomic <%s>", $1.converted);
                     }
              | ARRAY NARRUDATATYPE
                     {
                            fprintf(fpcpp, "%s", $2.datatype);
                            $$.datatype = ($2.datatype);
                            $$.is_array = true; 
                            $$.is_atomic = false;
                     }
            
              | ATOMIC ARRAY AARRUDATATYPE
                     {
                            fprintf(fpcpp, "%s<%s>", $1.token, $3.datatype);
                            $$.datatype = ($3.datatype);
                            $$.is_array = true; 
                            $$.is_atomic = true;
                     }
              ;

declarationStmt : simpleDatatype  
                {
                     dt_state = $1.datatype;
                     array_state = $1.is_array;
                     atomic_state = $1.is_atomic;

                } 
                simpleList
                | 
                arrayDatatype  
                {
                     dt_state = $1.datatype;
                     array_state = $1.is_array;
                     atomic_state = $1.is_atomic;
                } 
                arrayList
                ;

simpleList: IDENTIFIER subroutine_id //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $1.datatype = (dt_state);
                     $1.is_array = array_state;
                     $1.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($1.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     i_tb.addVariable($1.ID, $1.datatype, $1.is_atomic, $1.is_array,0);
                     //i_tb.print();
              }
          | simpleList COMMA subroutine_token IDENTIFIER //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $4.datatype = (dt_state);
                     $4.is_array = array_state;
                     $4.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($4.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array,0);
                     //i_tb.print();
                     fprintf(fpcpp, "%s", $4.ID);
              }
          | IDENTIFIER subroutine_id EQ subroutine_token RHS //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $1.datatype = (dt_state);
                     $1.is_array = array_state;
                     $1.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($1.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     // cout << $5.datatype  << endl ;      
                     // cout << $1.datatype << endl;
                     // cout << (string($1.datatype) == string($5.datatype)) << endl ;
                     if(assignment($1.datatype, $5.datatype, 0)) {
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
          | simpleList COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token RHS //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $4.datatype = (dt_state);
                     $4.is_array = array_state;
                     $4.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($4.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }
                     if(assignment($4.datatype,$8.datatype, 0)) {
                            i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array,0);
                     }else {
                            printError(yylineno,TYPE_ERROR_RHS_LHS);
                            return 1;
                     }
                     //i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $3.ID, dt_state, array_state, atomic_state,
                     Scope Level + TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
                     */
              }
          ;

arrayList : IDENTIFIER subroutine_id SQUAREOPEN subroutine_token {array_dim = 0;} dimlist SQUARECLOSE subroutine_token //////////////////////////////// COMPLETED ///////////////////////////////
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
                     //i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state,
                     Scope Level
                     */
              }
          | arrayList COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token {array_dim=0;} dimlist SQUARECLOSE subroutine_token //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     $4.datatype = (dt_state);
                     $4.is_array = array_state;
                     $4.is_atomic = atomic_state;
                     if(i_tb.searchDeclaration($4.ID)){
                            printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                            return 1;
                     }

                     i_tb.addVariable($4.ID, $4.datatype, $4.is_atomic, $4.is_array,array_dim+1);
                     array_dim = 0;
                     //i_tb.print();
                     /*
                     Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, 
                     atomic_state, Scope Level
                     */
              }
          ;

array_inValues: INTEGERLITERAL 
              {
                     $$.intVal = $1.intVal;
                     fprintf(fpcpp, "%d", $1.intVal);
              }
              | IDENTIFIER 
              {
                     $$.intVal = INT_MAX;
                     fprintf(fpcpp, "%s", $1.ID);
              }
              ;

dimlist : dimlist COMMA { fprintf(fpcpp, "][");array_dim++; } array_inValues
        | array_inValues
        ;

LHS :  IDENTIFIER subroutine_id //////////////////////////////// COMPLETED ///////////////////////////////
       {
              // cout << "826 - " << $1.ID << endl ;
              vector<string> a = i_tb.rhsSearchVariable($1.ID);
              if(a.size() == 0){
                     printError(yylineno,VARIABLE_NOT_FOUND);
                     return 1;
              }
              if(stoi(a[1]) == 1){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
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
       | IDENTIFIER subroutine_id {in_make_parallel_arrays = 2;curr_array_level = 0;} SQUAREOPEN subroutine_token arr_access SQUARECLOSE subroutine_token//////////////////////////////// COMPLETED ///////////////////////////////
       {
              // cout << "842 - " << $1.ID << endl ;
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
              // cout << "855-" << curr_array_level << endl ;
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
       | IN ARROW IDENTIFIER SQUAREOPEN {in_make_parallel_arrays = 2;curr_array_level = 0;} arr_access SQUARECLOSE{
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
              // cout << "904-" << curr_array_level << endl ;
              if(curr_array_level +1 != stoi(a[3])){
                     printError(yylineno,THE_ARRAY_SHOULD_BE_ACCESSED_FULLY);
                     return 1;
              }
       }
       ;

arr_access: exprlist
          ;

exprlist: arith_expr
         | exprlist COMMA subroutine_id {curr_array_level++;} arith_expr
         ;

arith_operand: IDENTIFIER 
              {
                     makeParallel = 0;
                     // // cout <<"916-search identifier: "<<($1.ID) << endl ;
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
                     fprintf(fpcpp, "%s", $1.ID);
              }
              | INTEGERLITERAL
              {
                     makeParallel = 1;
                     $$.datatype = "number";
                     fprintf(fpcpp, "%d", $1.intVal);
              }
              | ROUNDOPEN subroutine_token  arith_expr ROUNDCLOSE subroutine_token 
              {
                     $$.datatype = "number";
              }
              ;

arith_expr: arith_expr arithmetic_op arith_operand
          | arith_operand
          ;

 /*ASSIGNMENT STATEMENT*/
assignment_statement: LHS EQ subroutine_token RHS //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            if(!assignment($1.datatype, $4.datatype, 0)) {
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
      | ROUNDOPEN subroutine_token expression_statement ROUNDCLOSE subroutine_token 
      ;

//for logging
log: assignment_statement SEMICOLON subroutine_token { fprintf(yyout, " : assignment statement");  }
    | expression_statement SEMICOLON subroutine_token { fprintf(yyout, " : expression statement");  }
    ;

g: IDENTIFIER subroutine_id EQ subroutine_token RHS //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(i_tb.searchDeclaration($1.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if(!assignment($1.datatype, $5.datatype, 0)) {
                     printError(yylineno,TYPE_ERROR_RHS_LHS);
                     return 1;
              }
              i_tb.addVariable($1.ID, dt_state, atomic_state, array_state,0);
              // i_tb.print();
              /*
              Insert in Normal IDENTIFIER TABLE $1.ID, dt_state, array_state, atomic_state, Scope Level + 
              TYPE CHECK FOR COERCIBILITY OF dt_state and RHS.datatype
              */
       }
 | g COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token  RHS //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(i_tb.searchDeclaration($4.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if(!assignment($4.datatype, $8.datatype, 0)) {
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
                | ROUNDOPEN subroutine_token assignment_statement ROUNDCLOSE subroutine_token 
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
                }
                ;

 /*LOOPS*/
loop: for_loop | while_loop ; //////////////////////////////// COMPLETED ///////////////////////////////

 /*FOR LOOP*/
for_loop      : FOR {scopeLevel++;fprintf(fpcpp, "%s", $1.token);} SQUAREOPEN subroutine_roundopen both_assignment PIPE { fprintf(fpcpp, ";"); } RHS 
              {
                     // // cout << "1068- Datatype: " << $8.datatype << endl ;
                     if(!(string($8.datatype) == "number" || string($8.datatype) == "letter" || string($8.datatype) == "decimal" || string($8.datatype) == "bool") ){
                            printError(yylineno,PREDICATE_ERROR);
                            return 1;
              }
              } 
              PIPE { fprintf(fpcpp, ";"); }  exprrr SQUARECLOSE subroutine_roundclose  {fprintf(yyout, " : loop statement");} SCOPEOPEN subroutine_openscope statements //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
              } 
              SCOPECLOSE 
              ;

 /*WHILE LOOP*/
while_loop :  REPEAT { fprintf(fpcpp, "while"); }  SQUAREOPEN subroutine_roundopen  RHS 
              {
                     // // cout << "1085 - Datatype: " << $5.datatype << endl ;
                     if(!(string($5.datatype) == "number" || string($5.datatype) == "letter" || string($5.datatype) == "decimal" || string($5.datatype) == "bool") ){
                     printError(yylineno,PREDICATE_ERROR);
                     return 1;
                     }
              } 
              SQUARECLOSE  subroutine_roundclose { fprintf(yyout, " : loop statement");} SCOPEOPEN subroutine_openscope {scopeLevel++;} statements  //////////////////////////////// COMPLETED ///////////////////////////////
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
              } SCOPECLOSE subroutine_closescope
              ;



/*CONDITIONAL STATEMENT*/
conditional: when_statement; //////////////////////////////// COMPLETED ///////////////////////////////

/*WHEN STATEMENT*/
when_statement: WHEN { fprintf(fpcpp, "if"); } SQUAREOPEN subroutine_roundopen RHS 
       {
              // // cout << "1114- Datatype: " << $5.datatype << endl ;
              if(!(string($5.datatype) == "number" || string($5.datatype) == "letter" || string($5.datatype) == "decimal" || string($5.datatype) == "bool") ){
              printError(yylineno,PREDICATE_ERROR);
              return 1;
              }
       } 
       SQUARECLOSE subroutine_roundclose { fprintf(yyout, " : conditional statement");  } SCOPEOPEN subroutine_openscope { scopeLevel++;} statements //////////////////////////////// COMPLETED ///////////////////////////////
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE subroutine_closescope extend 
       ;
extend : ELSE_WHEN { fprintf(fpcpp, "else if"); } SQUAREOPEN subroutine_roundopen RHS 
       {
              // // cout << "1128- Datatype: " << $5.datatype << endl ;
              if(!(string($5.datatype) == "number" || string($5.datatype) == "letter" || string($5.datatype) == "decimal" || string($5.datatype) == "bool") ){
              printError(yylineno,PREDICATE_ERROR);
              return 1;
              }
       } SQUARECLOSE subroutine_roundclose { fprintf(yyout, " : conditional statement");  } SCOPEOPEN subroutine_openscope { scopeLevel++;} statements //////////////////////////////// COMPLETED ///////////////////////////////
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE subroutine_closescope extend 
       | DEFAULT {  fprintf(fpcpp, "else");  fprintf(yyout, " : conditional statement");  } SCOPEOPEN subroutine_openscope { scopeLevel++; } statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE subroutine_closescope
       | subroutine
       ;

 /*DEFAULT STATEMENT (occurs only once)*/
/* when_default: DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements 
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } SCOPECLOSE 
       | {;}
       ;   */


/* analysis statement is not in Cpp syntax!! So we may just put a comment while converting. */

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL subroutine_stringVal| IDENTIFIER subroutine_id 
              {
                     /*
                     SHOULD COME BACK, WHAT ARE THESE?
                     */
              } ; 

analyze_statement : ANALYZE {fprintf(fpcpp,"drawGraph(");} analyze_label COLON {fprintf(fpcpp,",");} analyze_label COLON {fprintf(fpcpp,",");} IDENTIFIER subroutine_id COLON {fprintf(fpcpp,",");} IDENTIFIER subroutine_id subroutine_roundclose SEMICOLON subroutine_token{ fprintf(yyout, " : analyze statement");  }
// analyze_statement : ANALYZE analyze_label COLON analyze_label COLON IDENTIFIER COLON IDENTIFIER SEMICOLON { fprintf(yyout, " : analyze statement");  }
       {
       /* 
       SHOULD COME BACK, WHAT ARE THESE? 
       */
       } ;

// RHS:  RHS;

// RHS:  RHS;
func_invoke2 : func_invoke SEMICOLON {  fprintf(fpcpp, ";");  fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER subroutine_id subroutine_in_args COLON subroutine_roundopen arguments COLON subroutine_roundclose
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
       | INVOKE IDENTIFIER subroutine_id subroutine_in_args COLON subroutine_roundopen NULL_ARGS COLON subroutine_roundclose
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


arguments : arguments COMMA subroutine_token  RHS 
          {
              arg_dat.push_back(($4.datatype));
              arg_is_array.push_back($4.is_array);
              arg_is_atomic.push_back($4.is_atomic);
          }
          | RHS 
          {
              arg_dat.push_back($1.datatype);
              arg_is_array.push_back($1.is_array);
              arg_is_atomic.push_back($1.is_atomic);
          }
          ;

task_invoke_args: {fprintf(fpcpp, ",");} arguments 
                /* | NULL_ARGS {arg_dat.clear();} */
                ;

/*Task call using Make Parallel*/
task_invoke : MAKE_PARALLEL IDENTIFIER subroutine_in_args COLON IDENTIFIER COLON IDENTIFIER COLON {
                     
                                           /*
                     
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */
                     if(!t_tb.searchTask($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic)){
                            printError(yylineno, TASK_NOT_FOUND);
                            return 1;
                     }
                     printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     arg_dat.clear();
                     arg_is_array.clear();
                     arg_is_atomic.clear();

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $6.ID);
                     fprintf(fpcpp, "\t\tget.begin();\n");
                     fprintf(fpcpp, "\t\tthread threads[%s];\n", $4.ID);
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $4.ID);
                     fprintf(fpcpp, "\t\tthreads[i] = thread(%s, i+1", $2.ID);
              } task_invoke_args {

                     fprintf(fpcpp, ");\n\t}");

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n\t\tthreads[i].join();\n\t}\n", $4.ID);
                     fprintf(fpcpp, "\t\tget.stop();\n\t}\n\tdouble t = get.time()/%s;\n", $6.ID);

                     arg_dat.clear();
                     in_call_args = 0;
              } COLON SEMICOLON ;
              | MAKE_PARALLEL IDENTIFIER subroutine_in_args COLON IDENTIFIER COLON IDENTIFIER COLON {
                     
                                           /*
                     
                     By here list of arg_dat (list of arguement's datatypes) will be ready. For all functions with name
                     as $1.ID, type check arguements
                     */
                     if(!t_tb.searchTask($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic)){
                            printError(yylineno, TASK_NOT_FOUND);
                            return 1;
                     }
                     printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     arg_dat.clear();
                     arg_is_array.clear();
                     arg_is_atomic.clear();

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $6.ID);
                     fprintf(fpcpp, "\t\tget.begin();\n");
                     fprintf(fpcpp, "\t\tthread threads[%s];\n", $4.ID);
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $4.ID);
                     fprintf(fpcpp, "\t\tthreads[i] = thread(%s, i+1", $2.ID);
              } NULL_ARGS {

                     fprintf(fpcpp, ");\n\t}");

                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n\t\tthreads[i].join();\n\t}\n", $4.ID);
                     fprintf(fpcpp, "\t\tget.stop();\n\t}\n\tdouble t = get.time()/%s;\n", $6.ID);

                     arg_dat.clear();
                     in_call_args = 0;
              } COLON SEMICOLON { fprintf(yyout, " : call statement");  } 
              {      
                     if(!t_tb.searchTask($2.ID,to_string_vec(arg_dat),arg_is_array,arg_is_atomic)){
                            printError(yylineno, TASK_NOT_FOUND);
                            return 1;
                     }
                     printArgs(to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
                     arg_dat.clear();
                     arg_is_array.clear();
                     arg_is_atomic.clear();
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $6.ID);
                     fprintf(fpcpp, "\t\tget.begin();\n");
                     fprintf(fpcpp, "\t\tthread threads[%s];\n", $4.ID);
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n", $4.ID);
                     fprintf(fpcpp, "\t\tthreads[i] = thread(%s, i+1", $2.ID);
                     fprintf(fpcpp, ");\n\t}");
                     fprintf(fpcpp, "\n\tfor(int i = 0; i < %s; i++) {\n\t\tthreads[i].join();\n\t}\n", $4.ID);
                     fprintf(fpcpp, "\t\tget.stop();\n\t}\n\tdouble t = get.time()/%s;\n", $6.ID);
              }
              ;
              
/*get statement*/
get_invoke : GET ARROW TIME ;

/*SLEEP STATEMENT*/
sleep : SLEEP subr_sleep ROUNDOPEN subroutine_token FLOATLITERAL subroutine_decVal ROUNDCLOSE subroutine_roundclose SEMICOLON subroutine_token { fprintf(yyout, " : sleep statement");  };
       | SLEEP subr_sleep ROUNDOPEN subroutine_roundopen INTEGERLITERAL subroutine_intVal ROUNDCLOSE subroutine_roundclose SEMICOLON subroutine_token { fprintf(yyout, " : sleep statement");  };

/* Grammar Rules for Input and Output*/
file_name : ARROW  subroutine_fileH STRINGLITERAL subroutine_stringVal subroutine_roundclose subroutine_fio {io1 = 0;}
          | ARROW subroutine_fileH IDENTIFIER subroutine_id subroutine_roundclose subroutine_fio 
          | subroutine_io subr_init
          ;

input : IP {io = 1;} file_name COLON subroutine_rs IDENTIFIER subroutine_id nextip subroutine_fileC
      ;

/*SCAN STATEMENT*/
nextip : COMMA subroutine_rs IDENTIFIER subroutine_id nextip
       | SEMICOLON subroutine_token
     { 
      fprintf(yyout, " : scan statement");
     }
    ;

stringvalues : STRINGLITERAL subroutine_stringVal
             | IDENTIFIER subroutine_id
            ;

/* Return */
return_statement : RETURN {if(atm ==1){
              fprintf(fpcpp,"mtx[mut].unlock();\n");
              fprintf(fpcpp,"\tmut++;\n");
              }} subroutine_token RHS SEMICOLON 
                 { 
                     fprintf(fpcpp,"%s",$4.token); 
                     if(func_start == 0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if($3.is_array == 1 && return_dim_count != 1){
                            printError(yylineno,INCOMPITABLE_ARRAY_DIMS);
                            return 1;
                     }
                     if(!(compatibility(string($3.datatype), return_type) && $3.is_array == is_array_ret)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     $$.datatype = $3.datatype; 
                     $$.is_array = $3.is_array; 
                     /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/
                     fprintf(yyout, " : return statement"); 
                 } ;
                 | RETURN subroutine_token NVOID subroutine_token SEMICOLON subroutine_token
                 { 
                     if(func_start == 0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if(!(string($3.datatype) == "void" && is_array_ret == 0)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     $$.datatype = $3.datatype; 
                     $$.is_array = $3.is_array; 
                     /*Atomics not needed here ig*/ /*TYPE CHECK WITH LAST FUNCTION'S RETURN DATATYPE AND THIS DATATYPE*/ 
                     fprintf(yyout, " : return statement"); 
                 } ;

/*PRINT STATEMENT*/
output : OP {io = 0;} file_name COLON opstring SEMICOLON subroutine_token subroutine_fileC
       { 
        fprintf(yyout, " : print statement");
       //  printf("================================================");
       }
      ;

opstring : subroutine_rs stringvalues nextop 
         ;

nextop : HASH /*subr_outputOP*/ subroutine_rs stringvalues nextop
       | subroutine
       ;


/*FUNCTION DECLARATION AND IMPLEMENTATION SCOPE*/

function: func_decl func_body 
        | atomic_func_decl func_body
        ;

func_args: all_datatypes {func_array.push_back(std::string($1.converted));  method_array.push_back(std::string($1.converted));} IDENTIFIER {if(arr==0){func_array.push_back(std::string($3.ID));} else{func_array.push_back(std::string($3.ID)+"[]");};  method_array.push_back(std::string($3.ID));}
       {
              // cout << "1351 - is_array: " << $1.is_array << endl ;
              decl_arg_dat.push_back($1.datatype);
              decl_arg_is_array.push_back($1.is_array);
              decl_arg_is_atomic.push_back($1.is_atomic);
              if(i_tb.searchDeclaration($3.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if($1.is_array == true) 
              i_tb.addVariable($3.ID, $1.datatype, $1.is_atomic, $1.is_array,1);
              else i_tb.addVariable($3.ID, $1.datatype, $1.is_atomic, $1.is_array,0);
       } /*SHOULD COME BACK and see the order they are getting stored in*/
       | func_args COMMA {func_array.push_back(std::string($2.token)); method_array.push_back(std::string($2.token)); } all_datatypes {func_array.push_back(std::string($4.converted)); method_array.push_back(std::string($4.converted)); } IDENTIFIER {if(arr==0){func_array.push_back(std::string($6.ID));} else{func_array.push_back(std::string($6.ID)+"[]");};  method_array.push_back(std::string($6.ID)); } //////////////////////////////// COMPLETED ///////////////////////////////
       {
              // cout << "1365 - is_array: " << $4.is_array << endl ;
              decl_arg_dat.push_back(($4.datatype));
              decl_arg_is_array.push_back($4.is_array);
              decl_arg_is_atomic.push_back($4.is_atomic);
              if(i_tb.searchDeclaration($6.ID)){
                     printError(yylineno,VARIABLE_REDECLARATION_ERROR);
                     return 1;
              }
              if($4.is_array == true)
              i_tb.addVariable($6.ID, $4.datatype, $4.is_atomic, $4.is_array,1);
              else i_tb.addVariable($6.ID, $4.datatype, $4.is_atomic, $4.is_array,0);
       } 
       ;

args: func_args
    | NULL_ARGS
    ;

func_return : nonAtomic_datatypes 
              {
                     func_array.push_back(std::string($1.converted));
                     method_array.push_back(std::string($1.converted));

                     $$.datatype = $1.datatype; 
                     $$.is_array = $1.is_array; 

                     /*Atomic is not needed*/
              }
            | NUDATATYPE 
            {
              func_array.push_back(std::string($1.datatype));
              method_array.push_back(std::string($1.datatype));

              $$.datatype = $1.datatype; 
              $$.is_array = $1.is_array; 
              /*Atomic is not needed*/
            }
            | IDENTIFIER {{printError(yylineno,TYPE_NOT_FOUND); return 1;};}
            ;

func_decl :  FUNC { scopeLevel++;func_start = 1;func_array.clear(); func_array.push_back(std::string($1.token)); } IDENTIFIER {func_array.push_back(std::string($3.ID));} COLON { func_array.push_back(std::string($5.token)); } args COLON { func_array.push_back(std::string($8.token)); } func_return 
              { 
                    /*
                     Add args as they are encountered in the id_table, IN FUNCTIONS TABLE, name of the function
                     is $2.ID decl_arg_dats will be ready, return_type is $6.datatype, $6.is_array 
                     */ 
                    if(f_tb.searchFunction($3.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                     f_tb.addFunction($3.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$10.datatype, $10.is_array);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return_type = $10.datatype ;
                     is_array_ret = $10.is_array ; 
                     fprintf(yyout, " : function declaration statement");
                     // f_tb.print();
                    }else {
                     printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return 1 ;
                     fprintf(yyout, " : function declaration statement");
                    }
                     atm = 0;
                     // // cout<< FuncDeclGen(func_array);

                     fprintf(fpcpp,"\n%s", FuncDeclGen(func_array).c_str());

                     func_array.clear();
              } 
              ;
atomic_func_decl :   ATOMIC FUNC {func_array.clear(); func_array.push_back(std::string($2.token));scopeLevel++;func_start = 1;chkAtomic = 0; } IDENTIFIER {func_array.push_back(std::string($4.ID));} COLON { func_array.push_back(std::string($6.token)); } args COLON { func_array.push_back(std::string($9.token)); } func_return //////////////////////////////// COMPLETED ///////////////////////////////
                     { 
                            /*
                            Add args as they are encountered in the id_table, decl_arg_dats will be ready, return_type
                            is $6.datatype, $6.is_array 
                            */ 

                     if(f_tb.searchFunction($4.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                            f_tb.addFunction($4.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$11.datatype, $11.is_array);
                            decl_arg_dat.clear(); 
                            decl_arg_is_array.clear();
                            decl_arg_is_atomic.clear();
                            
                     return_type = $11.datatype ;
                     is_array_ret = $11.is_array ; 
                     // // cout << "1435 - return_type: "<<return_type << endl ;
                     // // cout << "1436 - ret_is_array: "<<is_array_ret << endl ;
                            fprintf(yyout, " : function declaration statement");
                            // f_tb.print();
                     }
                     else {
                            printError(yylineno, FUNCTION_REDECLARATION_ERROR);
                            decl_arg_dat.clear(); 
                            decl_arg_is_array.clear();
                            decl_arg_is_atomic.clear();
                            return 1 ;
                            fprintf(yyout, " : function declaration statement");
                            }
                            // // cout<<"====================================="<<endl;
                            // fprintf
                            atm = 1;
                            fprintf(fpcpp, "\n%s", FuncDeclGen(func_array).c_str());

                            func_array.clear();
                     }
                     ;

func_body : SCOPEOPEN subroutine_openscope {if(atm ==1){ fprintf(fpcpp,"\n\tmtx[mut].lock();\n"); scopeLevel++;}} func_statements 
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
       }
       SCOPECLOSE subroutine_closescope
       ;

func_scope: declaration
          | log
          | task_invoke
          | func_invoke2 /*TYPE CHECK IF THE RETURN TYPE OF THIS FUNCTION IS VOID*/
          | loop
          | 
              return_statement
          | conditional
          | analyze_statement
          | input | output    | sleep
          | SCOPEOPEN subroutine_openscope {scopeLevel++;} func_statements 
          {
              i_tb.deleteVariables();
              scopeLevel--;

          } SCOPECLOSE subroutine_closescope
          | method_invoke2
          ;

func_statements: func_scope func_statements
               | subroutine
               ;

/* Task declaration and implemenatation scope */
task: TASK { 
              task_array.clear(); task_array.push_back("void"); 
       } IDENTIFIER  {        
              task_array.push_back(std::string($3.ID)); 
       } COLON {
                     task_array.push_back(std::string($5.token)); 
                     task_array.push_back("int"); 
                     task_array.push_back("tid"); 
              scopeLevel++;in_task = 1;
              } args //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(!t_tb.searchTask($3.ID, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic)){
                     t_tb.addTask($3.ID, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     // t_tb.print();
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
       } SCOPECLOSE subroutine_closescope 
    ;

taskscope: declaration taskscope
        | log taskscope
        | conditional taskscope
        | loop taskscope
        | func_invoke2 taskscope
        | output taskscope
        | SCOPEOPEN subroutine_openscope {scopeLevel++;} taskscope 
        {
              i_tb.deleteVariables();
              scopeLevel--;
        } SCOPECLOSE subroutine_closescope taskscope
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
          | SCOPEOPEN subroutine_openscope { scopeLevel++;} statements
          {
              i_tb.deleteVariables();
              scopeLevel--;
          } SCOPECLOSE subroutine_closescope
          | output
          | sleep
          | BREAK SEMICOLON subroutine_token
          | CONTINUE SEMICOLON subroutine_token
          | input
          | method_invoke2
          ;

statements: statement statements
          | subroutine
          ;
          
          
access : IDENTIFIER subroutine_id {
       // cout << "1544 - " << $1.ID << endl ;
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
       } ARROW subroutine_token id 
       {
              /*$1.datatype should be from an existing class*/ 
              // $$.datatype = ;
              // cout << "Datatype at end: "<<$4.datatype << endl ;
              $$.datatype = $6.datatype ;
              dt_type = NULL ;
              tok = 0;
       }
       ;

id     : IDENTIFIER subroutine_id
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
                     // // cout << "1579 - " << $1.ID << endl ;
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
       | id ARROW subroutine_token IDENTIFIER subroutine_id
       {
              /*
                     Type check that t_state is existing in the types_set, and it has an attribute named $3.ID
              */ 
              /*
                     After the check is done, we are supposed to update the t_state to the last identifier type
              */ 
              // cout << "OMG" << endl ;
              // cout << $3.ID <<" "<< $1.datatype << endl ;
              vector<string> a = attr_tb.rhsSearchAttribute($4.ID,$1.datatype);
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
       fprintf(fpcpp,"int main() ");
       scopeLevel++;
       startCount++;
              if(startCount > 1){
                     printError(yylineno, START_ERROR_MORE);
                     return 1;    
              }
       } SCOPEOPEN subroutine_openscope start
       {
              i_tb.deleteVariables();
              scopeLevel--;
       } {fprintf(fpcpp, "\treturn 0;\n\n");} SCOPECLOSE subroutine_closescope
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
     | SCOPEOPEN subroutine_openscope {scopeLevel++;} start 
     {
       i_tb.deleteVariables();
       scopeLevel--;

     } SCOPECLOSE subroutine_closescope start
     | sleep start
     | method_invoke2 start
     | subroutine
     ;

/* TYPE DEFINITION */
subr_public: %empty { fprintf(fpcpp, "\npublic:"); };

type_declaration: TYPE {fprintf(fpcpp,"class");} TYPENAME//////////////////////////////// COMPLETED ///////////////////////////////
              { 
                     // types_set.insert($2.token); 
                     fprintf(fpcpp,"%s",$3.token);
                     if(c_tb.searchType($3.token)){
                            printError(yylineno,TYPE_REDECLARATION);
                            return 1;
                     }
                     c_tb.addType($3.token);
                     // c_tb.print();
                     curr_type = ($3.token);
                     // cout<< "1680 - current type: " << curr_type << endl ;
                     fprintf(yyout, " : type declaration statement"); 

              } SCOPEOPEN subroutine_openscope { scopeLevel++;in_scope = 1;} subr_public type_scope methods 
              {
                     i_tb.deleteVariables();
                     scopeLevel--;
                     curr_type = NULL ;
                     // attr_tb.print();
                     in_scope = 0;

              } {
                     fprintf(fpcpp, "\t%s() = default;\n", $3.token);
                     fprintf(fpcpp, "\t%s(const %s&) = default;\n", $3.token, $3.token);
                     fprintf(fpcpp, "\t%s& operator = (const %s&) = default;\n", $3.token, $3.token);
                     fprintf(fpcpp, "\t~%s() = default;\n", $3.token);

              } SCOPECLOSE subroutine_closescope {fprintf(fpcpp, ";");}
              ;

type_scope: declaration_t type_scope | subroutine ;

declaration_t : declarationStmt_t SEMICOLON subroutine_token
              { 
                     fprintf(yyout, " : declaration statement"); 
              }
              | errorDatatypes IDENTIFIER {printError(yylineno,TYPE_NOT_FOUND); return 1;};
              ;

declarationStmt_t : simpleDatatype {
                            dt_state = $1.datatype;
                            // // cout << "datatype: " << $1.datatype << endl ;
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } simpleList_t
                | arrayDatatype {
                            dt_state = $1.datatype;
                            array_state = $1.is_array;
                            atomic_state = $1.is_atomic;
                     } arrayList_t
                ;

simpleList_t: IDENTIFIER subroutine_id//////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,0);
                                   //attr_tb.print();
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBBUTES TABLE $1.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
              | simpleList COMMA subroutine_token IDENTIFIER subroutine_id //////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $4.datatype = (dt_state);
                            $4.is_array = array_state;
                            $4.is_atomic = atomic_state;
                            if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                                   attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array,0);
                            }else {
                                   printError(yylineno,TYPE_ATTR_REDECLARATION);
                                   return 1;
                            }
                            /*
                            Insert in ATTRIBUTES TABLE $3.ID, dt_state, array_state, atomic_state, class_name will
                            be the last one from the types_Set
                            */
                     }
              | IDENTIFIER subroutine_id EQ subroutine_token RHS 
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,0);
                                   //attr_tb.print();
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
              | simpleList COMMA subroutine_token IDENTIFIER subroutine_id EQ subroutine_token RHS 
                     {
                            $4.datatype = (dt_state);
                            $4.is_array = array_state;
                            $4.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                                   attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array,0);
                                   //attr_tb.print();
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

arrayList_t : IDENTIFIER subroutine_id SQUAREOPEN subroutine_token {array_dim = 0;} dimlist SQUARECLOSE subroutine_token//////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $1.datatype = (dt_state);
                            $1.is_array = array_state;
                            $1.is_atomic = atomic_state;
                            

                            if(attr_tb.searchAttribute($1.ID, curr_type) == ""){
                                   attr_tb.addVariable($1.ID, curr_type, $1.datatype, $1.is_atomic, $1.is_array,array_dim +1);
                                   //attr_tb.print();
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
              | arrayList_t COMMA subroutine_token IDENTIFIER subroutine_id SQUAREOPEN subroutine_token {array_dim = 0;} dimlist SQUARECLOSE subroutine_token//////////////////////////////// COMPLETED ///////////////////////////////
                     {
                            $4.datatype = (dt_state);
                            $4.is_array = array_state;
                            $4.is_atomic = atomic_state;

                            if(attr_tb.searchAttribute($4.ID, curr_type) == ""){
                                   attr_tb.addVariable($4.ID, curr_type, $4.datatype, $4.is_atomic, $4.is_array,array_dim + 1);
                                   //attr_tb.print();
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

method: func_decl_m SCOPEOPEN subroutine_openscope method_body //////////////////////////////// COMPLETED ///////////////////////////////
       {
              if(number_of_returns == 0){
                     printError(yylineno,FUNCTION_MUST_HAVE_1_RETURN);
                     return 1;
              }
              i_tb.deleteVariables();
              scopeLevel--;

       } SCOPECLOSE subroutine_closescope ;

func_decl_m : FUNC { method_array.clear(); method_array.push_back(std::string($1.token)); } IDENTIFIER { method_array.push_back(std::string($3.ID)); }  COLON {method_array.push_back(std::string($5.token));  scopeLevel++;func_start = 1;} args COLON {method_array.push_back(std::string($8.token)); } func_return //////////////////////////////// COMPLETED ///////////////////////////////
              {
              /*
              Add args as they are encountered in the IDENTIFIER TABLE, 
              IN METHODS TABLE: $2.ID is method name, decl_arg_dats will be ready, 
              return_type is $6.datatype, $6.is_array class name will be the last element in the types_set
              */ 

              if(m_tb.searchMethod($3.ID, curr_type, to_string_vec(decl_arg_dat),decl_arg_is_array,decl_arg_is_atomic) == ""){
                     m_tb.addMethod($3.ID, curr_type, to_string_vec(decl_arg_dat), decl_arg_is_array,decl_arg_is_atomic,$10.datatype, $10.is_array);
                     decl_arg_dat.clear(); 
                     decl_arg_is_array.clear();
                     decl_arg_is_atomic.clear();
                     return_type = $10.datatype ;
                     is_array_ret = $10.is_array ; 
                     fprintf(yyout, " : function declaration statement");
                     // m_tb.print();

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
                     fprintf(fpcpp,"\n\t%s", FuncDeclGen(method_array).c_str());
              } 
              ;

method_invoke2 : method_invoke SEMICOLON  { fprintf(yyout, " : call statement");  fprintf(fpcpp,"%s",$2.token);} ;

method_args : arguments | NULL_ARGS ;

method_invoke : INVOKE id ARROW subroutine_token IDENTIFIER subroutine_id subroutine_in_args COLON subroutine_roundopen method_args COLON subroutine_roundclose
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
              
in_stmt : IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id
       {
              // // cout << "1909 - In the type: " << $5.ID << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              vector<string> a = attr_tb.rhsSearchAttribute($5.ID,curr_type);
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
       | INVOKE IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id subroutine_in_args COLON subroutine_roundopen arguments COLON subroutine_roundclose
       {
              // // cout << "1928 - Hereeeeeeeeee" << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              // // cout << "1933 - Current type: " << curr_type << endl ; 

              vector<string> a = m_tb.rhsSearchMethod($6.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
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
       | INVOKE IN subr_this ARROW subroutine_token IDENTIFIER subroutine_id subroutine_in_args COLON subroutine_roundopen NULL_ARGS COLON subroutine_roundclose
       {      
              // // cout << "1954 - Theeeereeeee" << endl ;
              // // cout << arg_dat.size() << arg_is_array.size() << arg_is_atomic.size() << endl;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }      
              vector<string> a = m_tb.rhsSearchMethod($6.ID,curr_type,to_string_vec(arg_dat),arg_is_array,arg_is_atomic);
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
                 | SCOPEOPEN subroutine_openscope {scopeLevel++;} method_statements 
                 {
                     i_tb.deleteVariables();
                     scopeLevel--;
                 } SCOPECLOSE subroutine_closescope 
                 | method_invoke2
                 | INVOKE IN ARROW IDENTIFIER subroutine_in_args COLON NULL_ARGS COLON 
       {      
              // // cout << "1998 - Theeeereeeee" << endl ;
              // // cout << arg_dat.size() << arg_is_array.size() << arg_is_atomic.size() <<" "<<$4.ID  << endl;
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
              // // cout << "2023 - Hereeeeeeeeee" << endl ;
              if(in_scope == 0){
                     printError(yylineno,IN_SCOPE_ERROR);
                     return 1;
              }
              // // cout << "2028 - Current type: " << curr_type << endl ; 

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
return_statement_m : RETURN subroutine_token RHS SEMICOLON subroutine_token
              { 
                     // // cout << "2051 - Return is : " << $3.datatype << endl ;
                     if(func_start ==0){
                            printError(yylineno,INVALID_USE_OF_RETURN);
                            return 1;
                     }
                     number_of_returns++ ;
                     if($3.is_array == 1 && return_dim_count != 1){
                            printError(yylineno,INCOMPITABLE_ARRAY_DIMS);
                            return 1;
                     }
                     if(!(compatibility(string($3.datatype), return_type) && $3.is_array == is_array_ret )){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     $$.datatype = $3.datatype; 
                     $$.is_array = $3.is_array; 
                     /*
                       Atomics not needed here ig
                     */ 
                     /*
                     TYPE CHECK WITH LAST METHOD'S RETURN DATATYPE AND THIS DATATYPE
                     */
                     fprintf(yyout, " : return statement"); 
              } ;
              | RETURN subroutine_token NVOID SEMICOLON subroutine_token
              { 
                     if(func_start ==0){
                           printError(yylineno,INVALID_USE_OF_RETURN);
                           return 1;
                     }
                     if(!(string($3.datatype) == "void" && is_array_ret == 0)){
                            printError(yylineno, RETURN_TYPE_ERROR);
                            return 1;
                     }
                     number_of_returns++;
                     $$.datatype = $3.datatype; 
                     $$.is_array = $3.is_array; 
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
// io1 = 0;
void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}



