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
template<class T> class TypeTable ;
template<class T> class TaskTable ;

class GlobalTable{
public:
  vector<TypeTable<GlobalTable>> c_tb ;
  vector<TaskTable<GlobalTable>> t_tb ;
  vector<FunctionTable<GlobalTable>> f_tb ;
  IdentifierTable<GlobalTable> i_tb ;
  StartTable s_tb ;
  int * p_tb ;
  GlobalTable(){ 
    p_tb = NULL ;
    i_tb.p_tb = this;
  }
  // Adding can be:
  // 1) Adding a new class-table object to vector c_tb
  // 2) Adding a new task-table object to t_tb
  // 3) Adding a new function-table object to f_tb
  // 4) Pointing to an identifier table and then adding variables to the table
  // 5) Pointing to a new start table using s_tb 
  // 6) Points to parent table
  void add_function(GlobalTable * parent,string id_name, int param_count, string retr_type);
  void add_task(GlobalTable * parent,string id_name, int param_count, string retr_type);
  void add_type(GlobalTable * parent,string id_name);
  // Pending 
  void add_start(GlobalTable * parent) ;
};

template <class T>
class NCLTable{
public:
  IdentifierTable<NCLTable<T>> i_tb ;
  vector<NCLTable<NCLTable<T>>> ncl_tb ;
  T * p_tb ;
  NCLTable(){
    i_tb.p_tb = this;
  }
  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to current existing parent
  void add_ncltable(NCLTable<T> * parent);
};

class StartTable {
  public:
    IdentifierTable<StartTable> i_tb ;
    vector<NCLTable<StartTable>> ncl_tb ;
    GlobalTable * p_tb ; // Parent pointer
    StartTable(){
      i_tb.p_tb = this ;
    }
    void add_ncltable(StartTable * parent);
};

template <class T>
class FunctionTable {
public: 
  string name; // function name
  int num_param; // number of parameters
  string return_type; // (number/decimal/letter/text/user-defined/ arrays)

  IdentifierTable<FunctionTable<T>> i_tb ; // pointer to identifier table (both parameters & varaiables in this table)
  vector<NCLTable<FunctionTable<T>>> ncl_tb ; // pointer to NCL Tables 
  T * p_tb ; //Parent pointer
  FunctionTable(){
    i_tb.p_tb = this;
  }
  void add_ncltable(FunctionTable<T> * parent);
};

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
};

template <class T>
class IdentifierTable{
public:
  vector<IdentifierStruct> i_struct;
  T * p_tb;  
  
  void add_variable(string name, bool is_atomic, bool is_array, string datatype);
};

template <class T>
class TypeTable
{
public:
  string name;
  IdentifierTable<TypeTable> i_tb;
  vector<FunctionTable<TypeTable>> f_tb;
  T * p_tb;
  TypeTable(){
    i_tb.p_tb = this;
  }
  void add_method(string name, int num_param, string return_type);
};

template <class T>
class TaskTable
{
public:
  int num_param;
  string name;
  IdentifierTable<TaskTable> i_tb;
  vector<NCLTable<TaskTable>> ncl_tb;
  T * p_tb;
  TaskTable(){
    i_tb.p_tb = this ;
  }
  void add_ncltable(TaskTable<T> * parent);
};

// Global Search Function for an identifier
// Use -> if the identifier name string is sent as input then outputs if it is present or not.
// We need to send info of type = function/ task/ variable declaration.
// We should even mention if the identifier which we are using is assigned with the keyword in or not, then the search is changed according to that
template <class T>
bool search_identifier(T cur_ptr, string id);

template <class T>
bool search_func_identifier(T global_ptr, vector<string>& func_check);

template <class T>
bool search_task_identifier(T global_ptr, vector<string>& task_check);

template <class T>
bool search_attribute(T g_ptr, string attr_name, string class_name);

template <class T>
bool search_type_idenitifer(T g_ptr, string id);

#endif














