#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GlobalTable;
template <class T> class NCLTable ;
class StartTable ;
template<class T> class FunctionTable ;
class IdentifierStruct ;
template<class T> class IdentifierTable ;
class TypeTable ;
class TaskTable ;

class IdentifierStruct{
public:
  string name; // Identifier name
  bool is_atomic; // Atomic or Non_atomic type
  bool is_array; // Simple or Array type
  /* 
  "number" for number datatype
  "decimal" for decimal datatype
  "letter" for letter datatype
  "text" for text datatype
  class-name" for user-defined datatye
  Any other character would be illegal
  */
  string datatype; // Datatype of the identifier
  // dimensions[0] = 0 - not an array
  // If array then dimensions[0], represent the size allocated to the arrayx
  vector<int> dimensions ; 
};

template <class T>
class IdentifierTable{
public:
  vector<IdentifierStruct *> i_struct;
  T * p_tb;  
  
  void add_variable(string name, bool is_atomic, bool is_array, string datatype, vector<int> dims);
};

class StartTable {
  public:
    IdentifierTable<StartTable > * i_tb ;
    vector<NCLTable<StartTable> * > ncl_tb ;
    GlobalTable * p_tb ; // Parent pointer
    StartTable(){
      i_tb->p_tb = this ;
    }
    void add_ncltable(StartTable * parent);
};


class GlobalTable{
public:
  vector<TypeTable * > c_tb ;
  vector<TaskTable * > t_tb ;
  vector<FunctionTable<GlobalTable> * > f_tb ;
  IdentifierTable<GlobalTable> * i_tb ;
  StartTable * s_tb ;
  int * p_tb ;
  GlobalTable(){ 
    p_tb = NULL ;
    i_tb->p_tb = this;
  }
  void add_function(GlobalTable * parent,string id_name, int param_count, string retr_type);
  void add_task(GlobalTable * parent,string id_name, int param_count, string retr_type);
  void add_type(GlobalTable * parent,string id_name);
  void add_start(GlobalTable * parent) ;
};

class IdentifierStructNestedScopes{
public:
  string name; // Identifier name
  bool is_atomic; // Atomic or Non_atomic type
  bool is_array; // Simple or Array type
  /* 
  "number" for number datatype
  "decimal" for decimal datatype
  "letter" for letter datatype
  "text" for text datatype
  class-name" for user-defined datatye
  Any other character would be illegal
  */
  string datatype; // Datatype of the identifier
  int level ;
  // dimensions[0] = 0 - not an array
  // If array then dimensions[0], represent the size allocated to the arrayx
  vector<int> dimensions ; 
};

// Whenever we enter scopes of Nested Scope, Conditional, loop scopes then we use this table
template <class T>
class NCLTable{
public:
  IdentifierTable<NCLTable<T> > * i_tb ;
  vector<NCLTable<NCLTable<T> > * > ncl_tb ;
  T * p_tb ;
  NCLTable(){
    i_tb->p_tb = this;
  }
  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to current existing parent
  void add_ncltable(NCLTable<T> * parent);
};

template <class T>
class FunctionTable {
public: 
  string name; // function name
  int num_param; // number of parameters
  string return_type; // (number/decimal/letter/text/user-defined/ arrays)

  IdentifierTable<FunctionTable<T> > * i_tb ; // pointer to identifier table (both parameters & varaiables in this table)
  vector<NCLTable<FunctionTable<T> > * > ncl_tb ; // pointer to NCL Tables 
  T * p_tb ; //Parent pointer
  FunctionTable(){
    i_tb->p_tb = this;
  }
  void add_ncltable(FunctionTable<T> * parent);
};

class TypeTable
{
public:
  string name;
  IdentifierTable<TypeTable> * i_tb;
  vector<FunctionTable<TypeTable> * > f_tb;
  GlobalTable * p_tb;
  TypeTable(){
    i_tb->p_tb = this;
  }
  void add_method(string name, int num_param, string return_type);
};

class TaskTable
{
public:
  int num_param;
  string name;
  IdentifierTable<TaskTable> * i_tb;
  vector<NCLTable<TaskTable> * > ncl_tb;
  GlobalTable * p_tb;
  TaskTable(){
    i_tb->p_tb = this ;
  }
  void add_ncltable(TaskTable * parent);
};

// Global Search Function for an identifier
// Use -> if the identifier name string is sent as input then outputs if it is present or not->
// We need to send info of type = function/ task/ variable declaration->
// We should even mention if the identifier which we are using is assigned with the keyword in or not, then the search is changed according to that
template <class T>
bool search_identifier(T * cur_ptr, string id, bool is_array, vector<int> dims); 

bool search_func_identifier(GlobalTable * global_ptr, vector<string>& func_check); 

bool search_task_identifier(GlobalTable * global_ptr, vector<string>& task_check); 

bool search_attribute_type(GlobalTable * global_ptr,string id, string class_name, bool is_array, vector<int> dims);

bool search_type_idenitifer(GlobalTable * g_ptr, string id); 

bool search_method(GlobalTable * global_ptr, string class_name, vector<string> &method_check); 

#endif

// YACC Work
// Values that need to be passed from bottom to top
// constant values 
// passing identifiers from top to bottom 













