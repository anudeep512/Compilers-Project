#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
class GlobalTable{
public:
  vector<TypeTable<GlobalTable>> c_tb ;
  vector<TaskTable<GlobalTable>> t_tb ;
  vector<FunctionTable<GlobalTable>> f_tb ;
  IdentifierTable<GlobalTable> i_tb ;
  StartTable<GlobalTable> s_tb ;
  T * p_tb ;

  // Adding can be:
  // 1) Adding a new class-table object to vector c_tb
  // 2) Adding a new task-table object to t_tb
  // 3) Adding a new function-table object to f_tb
  // 4) Pointing to an identifier table and then adding variables to the table
  // 5) Pointing to a new start table using s_tb 
  // 6) Points to parent table
  int add();

};

template <class T>
class NCLTable{
public:
  IdentifierTable<NCLTable> i_tb ;
  vector<NCLTable<NCLTable>> ncl_tb ;
  T * p_tb ;

  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to 
  int add();
};

template <class T>
class StartTable {
  public:
    IdentifierTable<StartTable> i_tb ;
    vector<NCLTable<StartTable>> ncl_tb ;
    T * p_tb ; // Parent pointer

  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to 
    int add();

};

template <class T>
class FunctionTable {
public: 
  string id_name; // function name
  int num_param; // number of parameters
  string return_type; // (number/decimal/letter/text/user-defined/ arrays)

  IdentifierTable<FunctionTable> i_tb ; // pointer to identifier table (both parameters & varaiables in this table)
  vector<NCLTable<FunctionTable>> ncl_tb ; // pointer to NCL Tables 
  T * p_tb ; //Parent pointer

  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to 
  int add();
};

class IdentifierStruct{
public:
  string id_name;
  bool is_atomic;
  bool is_array;
  /* 
  "number" for number datatype
  "decimal" for decimal datatype
  "letter" for letter datatype
  "text" for text datatype
  class-name" for user-defined datatye
  Any other character would be illegal
  */
  string datatype;
};

template <class T>
class IdentifierTable{
public:
  vector<IdentifierStruct> i_struct;
  T * p_tb;  
  
  int add();
};

template <class T>
class TypeTable
{
public:
  string type_name;
  IdentifierTable<TypeTable> i_tb;
  vector<FunctionTable<TypeTable>> f_tb;
  T * p_tb;

  int add();
};

template <class T>
class TaskTable
{
public:
  int num_param;

  string task_name;
  IdentifierTable<TaskTable> i_tb;
  vector<NCLTable<TaskTable>> ncl_tb;
  T * p_tb;

  int add();

};

// Global Search Function for an identifier
// Use -> if the identifier name string is sent as input then outputs if it is present or not.
// We need to send info of type = function/ task/ variable declaration.
// We should even mention if the identifier which we are using is assigned with the keyword in or not, then the search is changed according to that
template <class T>
bool search_identifier(T cur_ptr, string id);

template <class T>
void add_identifier(IdentifierTable<T> & i_tb);
template <class T>
bool search_attribute(T g_ptr, string attr_name, string class_name);

template <class T>
bool seach_type_idenitifer(T g_ptr, string id);

#endif














