%{
  #include <iostream>
  #include <string>
  #include <vector>
  #include<fstream>
  #include <climits>
  #include "errors.hpp"
  #include "symbol_table.hpp"
  #include "semantics.hpp"

  using namespace std;
  extern int yylex();
  extern int yylineno;
  extern FILE * yyout;
  void yyerror(std::string s);
  char *dt_state; // Datatype state
  char *t_state; // Type i.e., class state
  vector<char *> id_vec;
  GlobalTable * g_tb = new GlobalTable();
  // Gives Pointer to current Start Table
  StartTable * s_tb = NULL ;
  // Gives Pointer to current function table in type
  FunctionTable<TypeTable> * m_tb = NULL;
  // Gives Pointer to current function table in global
  FunctionTable<GlobalTable> * f_tb = NULL ;
  // Gives Pointer to current type table
  TypeTable * c_tb = NULL;
  // Gives Pointer to current task table
  TaskTable * t_tb = NULL;
  // Gives pointer to Start Tables NCL Table
  NCLTable<StartTable> * ncl_start = NULL ;
  // Gives pointer to Method Tables NCL Table
  NCLTable<FunctionTable<TypeTable> > * ncl_method = NULL;
  // Gives pointer to Function Tables NCL Table
  NCLTable<FunctionTable<GlobalTable> > * ncl_function = NULL;
  // Gives pointer to Task Tables NCL Table
  NCLTable<TaskTable> * ncl_task = NULL;
  
  // Used to define about scope where the variables are declared 
  // 1 -> Global
  // 2 -> Start
  // 3 -> Type
  // 4 -> Function
  // 5 -> Task
  // 6 -> Method
  int scopeType = 0;
  // To keep track of scope level in the current scope
  // When we encouner a scope is opened then +1 is done, when scope is closed then -1 is done
  int scopeLevel = 0;
  // To keep track of the number of functions encountered until now
  int funcCountGlobal = 0;
  // Keeping track of number of functions encountered in the type
  int funcCountType = 0;
  // Used to keep track of number of classes created
  int typesCount = 0;
  // Used to keep track number of tasks created
  int taskCount = 0;

  IdentifierStruct *args_tracker = new args_tracker();
  std::vector<char *>invoke_vec;
  std::vector<IdentifierStruct> args_vec;
  std::vector<std::vector<int>> dim_vec = {{}};
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
              // 1 -> Global
              // 2 -> Start
              // 3 -> Type
              // 4 -> Function
              // 5 -> Task
              // 6 -> Method
              int scopeType; // For declaration of the variable
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


%type<attr> all_datatypes expression_op comparison_op arithmetic_op logical_op nonAtomic_datatypes E T all_ops constants next RHS nonAtomicSimple atomicSimple nonAtomicArray atomicArray declaration declarationStmt simpleDatatype arrayDatatype simpleList arrayList array_inValues dimlist LHS arr_access exprlist arith_expr assignment_statement expression_statement exprrr log g both_assignment loop for_loop while_loop conditional when_statement when_default analysis_arrays analyze_label analyze_statement analyze_syntax func_invoke2 func_invoke arguments file_name input nextip stringvalues output opstring nextop func_args args func_return func_decl atomic_func_decl func_body func_scope func_statements task taskscope statement statements access id startdec start type_declaration type_scope declaration_t declarationStmt_t methods method method_invoke2 method_args method_invoke in_stmt method_statements method_body sleep task_invoke return_statement arith_operand get_invoke function

%start begin

%%
all_datatypes: NUDATATYPE     {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = false;}
             | AUDATATYPE     {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = true;}
             | NARRUDATATYPE  {$$.datatype = $1.datatype; $$.is_array = true; $$.is_atomic = false;}
             | AARRUDATATYPE  {$$.datatype = $1.datatype; $$.is_array = true; $$.is_atomic = true;}
             | NBOOL          {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
             | NDEC           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
             | NNUM           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
             | NTEXT          {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
             | NLET           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
             | ABOOL          {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ADEC           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ALET           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ATEXT          {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ANUM           {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;} 
             | nonAtomicArray 
             | atomicArray 
             ;
expression_op: ASSN_DIV | ASSN_EXPONENT | ASSN_MODULO | ASSN_MUL | INCR | DECR ;
comparison_op: LT | GT | GTEQ | LTEQ | NOT_EQ | EQUAL_TWO ;
arithmetic_op: ADD | SUB | MUL | DIV | MODULO | EXPONENT ;
logical_op: AND | OR ;
nonAtomic_datatypes: nonAtomicArray | nonAtomicSimple ;

begin :
      |       
       {
              s_tb = g_tb->s_tb ;
              scopeType = 2;
       } 
       startdec {s_tb = NULL;scopeType = 0;} begin
      | 
       {
              scopeType = 1;
       }
       declaration {scopeType = 0;} begin
      | 
       {
              m_tb = new FunctionTable<GlobalTable>();
              g_tb->f_tb.push_back(m_tb);
              scopeType = 2;
       } 
       function {scopeType = 0;m_tb = NULL;funcCountGlobal++;} begin
      | 
      {       
              t_tb = new TaskTable();
              g_tb->t_tb.push_back(t_tb);
              funcCountType = 0;
              scopeType = 3;
      } 
      task {scopeType = 0;t_tb = NULL;taskCount++;} begin
      | 
      {
              c_tb = new TypeTable();
              g_tb->c_tb.push_back(c_tb);
              scopeType = 4;
      }
       type_declaration {scopeType = 0;c_tb = NULL;typesCount++;} begin
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

constants: INTEGERLITERAL      {$$.intVal = yylval.attr.intVal;}
           | CHARACTERLITERAL  {$$.charVal = yylval.attr.charVal;}
           | FLOATLITERAL      {$$.decVal = yylval.attr.decVal;}
           | BOOLEANLITERAL    {$$.boolVal = yylval.attr.charVal;}
           | STRINGLITERAL     {$$.stringVal = yylval.attr.stringVal;}
           ;

next : RHS all_ops next 
	| RHS 				
	;

RHS :	constants {$$.datatype = $1.datatype;}
    | T {$$.datatype = $1.datatype;}
    | TID {$$.datatype = "number";}
    | get_invoke {$$.datatype = "decimal";} | method_invoke {$$.datatype = $1.datatype;} | in_stmt {$$.datatype = $1.datatype;}
    | ROUNDOPEN RHS all_ops next ROUNDCLOSE {$$.datatype = "will be replaced by iscoercible function";}
    | ROUNDOPEN RHS ROUNDCLOSE {$$.datatype = $2.datatype;}
    | NEG ROUNDOPEN RHS ROUNDCLOSE {$$.datatype = $3.datatype;}
    ;

/* DATATYPE SEGREGATION FOR DECL STATEMENTS */
nonAtomicSimple : NNUM   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NDEC   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NBOOL  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NLET   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NTEXT  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                | NVOID  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
                ;
atomicSimple : ANUM   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;} 
             | ADEC   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ABOOL  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ALET   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             | ATEXT  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = true;}
             ;

nonAtomicArray : NARRNUM   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRDEC   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRBOOL  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = false; $$.is_atomic = false;}
               | NARRLET   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRTEXT  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               ; 
atomicArray : AARRNUM   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRDEC   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRBOOL  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRLET   {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            | AARRTEXT  {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
            ;


/* DECLARATION STATEMENT : Only Declaration + Assignment */

declaration : declarationStmt SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ;
            
simpleDatatype : nonAtomicSimple   {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = false;}
               | atomicSimple      {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = true;}
               | NUDATATYPE        {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = false;}
               | ATOMIC AUDATATYPE {$$.datatype = $1.datatype; $$.is_array = false; $$.is_atomic = true;}
               ; 
arrayDatatype  : nonAtomicArray              {$$.datatype = $1.datatype; $$.is_array = true; $$.is_atomic = false;}
               | atomicArray                 {$$.datatype = $1.datatype; $$.is_array = true; $$.is_atomic = true;}
               | ARRAY NARRUDATATYPE         {$$.datatype = $2.datatype; $$.is_array = true; $$.is_atomic = false;}
               | ATOMIC ARRAY AARRUDATATYPE  {$$.datatype = $3.datatype; $$.is_array = true; $$.is_atomic = true;}
               ;

declarationStmt : simpleDatatype simpleList 
                {
                     int count = 0;
                     // Insertion to Symbol Table is done now
                     for(auto i : id_vec){
                            if(scopeType == 1){ // Global Table addition
                                   // if(search_identifier(g_tb, $1.)); commented, should complte else throwing error
                                   if(search_global_table(g_tb, i)) {
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   g_tb->i_tb->add_variable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 2){ // Start table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(s_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   s_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 4){ // Function table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(f_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   f_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            else if(scopeType == 5){ // Task table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(t_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   t_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 6){ // Method table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(m_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   m_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            count++;
                     }
                     id_vec.clear();
                     dim_vec.clear();
                }
                | arrayDatatype arrayList
                {
                     int count = 0;
                     // Insertion to Symbol Table is done now
                     for(auto i : id_vec){
                            if(scopeType == 1){ // Global Table addition
                                   // if(search_identifier(g_tb, $1.)); commented, should complte else throwing error
                                   if(search_global_table(g_tb, i)) {
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   g_tb->i_tb->add_variable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 2){ // Start table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(s_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   s_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 4){ // Function table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(f_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   f_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            else if(scopeType == 5){ // Task table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(t_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   t_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }else if(scopeType == 6){ // Method table addition
                                   // Search if already exists in the current scope
                                   if(search_current_scope_redeclaration(m_tb->ncl_tb,i)){
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   m_tb->ncl_tb->add_ncltable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            count++;
                     }
                     id_vec.clear();
                     dim_vec.clear();
                }
                ;

simpleList: IDENTIFIER 
              {
                     $1.ID = yylval.attr.ID; id_vec.push_back($1.ID);
              }
          | simpleList COMMA IDENTIFIER {$3.ID = yylval.attr.ID; id_vec.push_back($3.ID);}
          | IDENTIFIER EQ RHS {$1.ID = yylval.attr.ID; id_vec.push_back($1.ID); /*There should be a type check for RHS and dt_state*/}
          | simpleList COMMA IDENTIFIER EQ RHS {$3.ID = yylval.attr.ID; id_vec.push_back($3.ID); /*There should be a type check for RHS and dt_state*/}
          ;

push_empty_rule : {dim_vec.push_back({});};

arrayList : IDENTIFIER SQUAREOPEN dimlist push_empty_rule SQUARECLOSE
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist push_empty_rule SQUARECLOSE
          | IDENTIFIER SQUAREOPEN dimlist push_empty_rule SQUARECLOSE EQ RHS 
          | arrayList COMMA IDENTIFIER SQUAREOPEN dimlist push_empty_rule SQUARECLOSE EQ RHS 
          ;

array_inValues: INTEGERLITERAL            {$1.intVal = yylval.attr.intVal; $$.intVal = $1.intVal;} | IDENTIFIER {$$.intVal = INT_MAX;};

dimlist : dimlist COMMA array_inValues    {dim_vec[dim_vec.size()-1].push_back($3.intVal);}
        | array_inValues                  {dim_vec[dim_vec.size()-1].push_back($1.intVal);}
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
for_loop: FOR SQUAREOPEN both_assignment PIPE RHS PIPE exprrr SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN {scopeLevel++;} statements {scopeLevel--;} SCOPECLOSE;

 /*WHILE LOOP*/
while_loop: REPEAT SQUAREOPEN RHS SQUARECLOSE  {fprintf(yyout, " : loop statement");} SCOPEOPEN {scopeLevel++;} statements {scopeLevel--;} SCOPECLOSE;



/*CONDITIONAL STATEMENT*/
conditional: when_statement when_default;

/*WHEN STATEMENT*/
when_statement: WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements {scopeLevel--;} SCOPECLOSE
              | when_statement ELSE_WHEN SQUAREOPEN RHS SQUARECLOSE { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements {scopeLevel--;} SCOPECLOSE
              ;

 /*DEFAULT STATEMENT (occurs only once)*/
when_default: DEFAULT { fprintf(yyout, " : conditional statement");  } SCOPEOPEN {scopeLevel++;} statements {scopeLevel--;} SCOPECLOSE 
            | {;}
            ;  

analysis_arrays: NARRDEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | NARRNUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = false;}
               | AARRDEC {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
               | AARRNUM {dt_state = yylval.attr.datatype; $$.datatype = yylval.attr.datatype; $$.is_array = true; $$.is_atomic = true;}
               ;

 /*ANALYSIS STATEMENT*/
analyze_label : STRINGLITERAL | IDENTIFIER ; 

analyze_statement : ANALYZE analyze_label COLON analyze_label COLON analysis_arrays COLON analysis_arrays analyze_syntax SEMICOLON { fprintf(yyout, " : analyze statement");  } ; ;

analyze_syntax   : COLON analysis_arrays analyze_syntax | {;};

/*calls*/

// RHS:  RHS;

func_invoke2 : func_invoke SEMICOLON { fprintf(yyout, " : call statement");  }
             ;

func_invoke: INVOKE IDENTIFIER COLON arguments COLON { invoke_vec.insert(invoke_vec.begin(), $2.ID);/*Call that function, after it's use, we will clear, so I am proceeding with clear*/ 
                     // for(int i = 0; i < invoke_vec.size(); i++)
                     // {
                     //        //std::cout << invoke_vec[i] << " " << yylineno << " ";
                     // }
                     // //std::cout << "\n";
                      invoke_vec.clear();}
           | INVOKE IDENTIFIER COLON NULL_ARGS COLON {invoke_vec.insert(invoke_vec.begin(), $2.ID); invoke_vec.push_back("null"); /*Check*/ invoke_vec.clear();}
          ;


arguments : arguments COMMA RHS {invoke_vec.push_back($3.datatype);}
          | RHS {invoke_vec.push_back($1.datatype);}
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
return_statement : RETURN RHS SEMICOLON    {$$.datatype = $2.datatype; $$.is_atomic = $2.is_atomic; $$.is_array = $2.is_array; fprintf(yyout, " : return statement"); } ;
                 | RETURN NVOID SEMICOLON  {$$.datatype = $2.datatype; $$.is_atomic = $2.is_atomic; $$.is_array = $2.is_array; fprintf(yyout, " : return statement"); } ;

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
function:         func_decl func_body | atomic_func_decl func_body {/*Check for matching datatypes of $1.datatype, $2.datatype*/};

func_args:        all_datatypes IDENTIFIER {args_tracker->name = $2.ID; args_tracker->datatype = $1.datatype; args_tracker->is_array = $1.is_array; args_tracker->is_atomic = $1.is_atomic; args_vec.push_back(args_tracker);}
         | func_args COMMA all_datatypes IDENTIFIER {args_tracker->name = $4.ID; args_tracker->datatype = $3.datatype; args_tracker->is_array = $3.is_array; args_tracker->is_atomic = $3.is_atomic; args_vec.push_back(args_tracker);};

args: func_args {for(auto i: args_vec){cout << i.name << " ";}cout << "\n";}
    | NULL_ARGS /*No need to push anything to the i_tb of the f_tb in this case so leaving empty*/;

func_return : nonAtomic_datatypes   {dt_state = yylval.attr.datatype; $$.datatype = $1.datatype ; $$.is_array = $1.is_array; $$.is_atomic = $1.is_atomic;}
            | NUDATATYPE            {dt_state = yylval.attr.datatype; $$.datatype = $1.datatype ; $$.is_array = false; $$.is_atomic = false;}
            ;

func_decl :       FUNC IDENTIFIER COLON args {/*By now name + arguments will be in args_vec. Do args check here*/} COLON func_return {dt_state = yylval.attr.datatype; $$.datatype = $6.datatype ; $$.is_array = $6.is_array; fprintf(yyout, " : function declaration statement"); } 
                 ;
atomic_func_decl :   ATOMIC FUNC IDENTIFIER COLON args {/*By now name + arguments will be in args_vec. Do args check here*/} COLON func_return   {dt_state = yylval.attr.datatype; $$.datatype = $7.datatype ; $7.is_array = $7.is_array; fprintf(yyout, " : function declaration statement"); }
                     ;

func_body : SCOPEOPEN func_statements SCOPECLOSE{dt_state = yylval.attr.datatype; $$.datatype = $2.datatype;};

func_scope: declaration
          | log
          | task_invoke
          | func_invoke2
          | loop
          | return_statement {dt_state = yylval.attr.datatype; $$.datatype = $1.datatype;}
          | conditional
          | analyze_statement
          | input | output    | sleep
          | SCOPEOPEN func_statements SCOPECLOSE
          | method_invoke2
          ;

func_statements: func_scope func_statements {dt_state = yylval.attr.datatype; $$.datatype = $1.datatype;}
               | {;}
               ;

/* Task declaration and implemenatation scope */
task: TASK IDENTIFIER COLON args { fprintf(yyout, " : task declaration statement"); } SCOPEOPEN {scopeLevel++;} taskscope {scopeLevel--;} SCOPECLOSE
    ;

taskscope: declaration taskscope
        | log taskscope
        | conditional taskscope
        | loop taskscope
        | func_invoke2 taskscope
        | output taskscope
        | SCOPEOPEN {scopeLevel++;} taskscope {scopeLevel--;} SCOPECLOSE taskscope
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
          
          
access : IDENTIFIER ARROW id {$$.datatype = dt_state;};
id     : IDENTIFIER
       | id ARROW IDENTIFIER
       ;
       
/* START DEFINAITON */

startdec: START SCOPEOPEN {scopeLevel++;} start {scopeLevel--;} SCOPECLOSE 
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
     | SCOPEOPEN {scopeLevel++;} start {scopeLevel--;} SCOPECLOSE start
     | sleep start
     | method_invoke2 start
     | {;}
     ;

/* TYPE DEFINITION */

type_declaration: TYPE TYPENAME { $2.datatype = yylval.attr.datatype; t_state = $2.datatype; /* Create type table function */ fprintf(yyout, " : type declaration statement"); } SCOPEOPEN {scopeLevel++;} type_scope methods {scopeLevel--;} SCOPECLOSE
                ;

type_scope: declaration_t {/*Here, we have to push_back to the vector of type with name dt_state*/} type_scope |  {;};

declaration_t : declarationStmt_t SEMICOLON { fprintf(yyout, " : declaration statement"); }
            ;

declarationStmt_t : simpleDatatype simpleList {/*Insert in the typetable of the t_state full vectorlist. is_array,is_atomic attr false, datatype will be there*/ 
                     int count = 0;
                     // Insertion to Symbol Table is done now
                     for(auto i : id_vec){
                            if(scopeType == 3){ // Type Table addition
                                   if(search_type_table(t_tb, i)) {
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   t_tb->i_tb->add_variable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            count++;
                     }
                     id_vec.clear();
                     dim_vec.clear();
              }
                | arrayDatatype arrayList {/*Insert in the typetable of the t_state full vectorlist. is_array,is_atomic attr false, datatype will be there*/ 
                     int count = 0;
                     // Insertion to Symbol Table is done now
                     for(auto i : id_vec){
                            if(scopeType == 3){ // Type Table addition
                                   if(search_type_table(t_tb, i)) {
                                          printError(yylineno,REDECLARATION_ERROR);
                                          return 1;
                                   }
                                   t_tb->i_tb->add_variable(i,$1.is_atomic, $2.is_array, $1.datatype, dim_vec[count]);
                            }
                            count++;
                     }
                     id_vec.clear();
                     dim_vec.clear();
              }
              ;

methods: methods method
       | {;}
       ;

method: func_decl SCOPEOPEN {scopeLevel++;} method_body {funcCountType++;scopeLevel--;} SCOPECLOSE ;


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
                 | SCOPEOPEN {scopeLevel++;} method_statements {scopeLevel--;} SCOPECLOSE
                 | method_invoke2
                 ;

method_body: method_statements method_body
           | {;}
           ;
           
%%

void yyerror(std::string s){
  std::cout << "Syntax Error: " << s << " at line number - " << yylineno << std::endl;
}
