#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "bison.tab.h"
#include "errors.hpp"
#include "semantics.hpp"

using namespace std;

class GlobalTable;
template <class T>
class NCLTable;
class StartTable;
template <class T>
class FunctionTable;
class IdentifierStruct;
template <class T>
class IdentifierTable;
class TypeTable;
class TaskTable;

class IdentifierStruct
{
public:
  string name;     // Identifier name
  bool is_atomic;  // Atomic or Non_atomic type
  bool is_array;   // Simple or Array type
  string datatype; // Datatype of the identifier
  // dimensions[0] = 0 - not an array
  // If array then dimensions[0], represent the size allocated to the array
  int scopeLevel;
  vector<int> dimensions;
};

template <class T>
class IdentifierTable
{
public:
  vector<IdentifierStruct *> i_struct;
  T *p_tb;

  void add_variable(string name, bool is_atomic, bool is_array, string datatype, vector<int> dims);
};

// Whenever we enter scopes of Nested Scope, Conditional, loop scopes then we use this table
template <class T>
class NCLTable
{
public:
  IdentifierTable<NCLTable<T> > * i_tb;
  T *p_tb;
  NCLTable()
  {
    i_tb = new IdentifierTable<NCLTable<T> >();
    i_tb->p_tb = this;
  }
  void add_ncltable(string name, bool is_atomic, bool is_array, string datatype, vector<int> dims);
  void pop_ncltable();
};


class StartTable
{
public:
  NCLTable<StartTable> * ncl_tb;
  GlobalTable *p_tb;
  StartTable()
  {
    ncl_tb = new NCLTable<StartTable>();
    ncl_tb->p_tb = this;
  }
};

class GlobalTable
{
public:
  vector<TypeTable *> c_tb;
  vector<TaskTable *> t_tb;
  vector<FunctionTable<GlobalTable> *> f_tb;
  IdentifierTable<GlobalTable> *i_tb;
  StartTable *s_tb;
  int *p_tb;
  GlobalTable()
  {
    i_tb = new IdentifierTable<GlobalTable>();
    p_tb = NULL;
    s_tb = new StartTable() ;
    i_tb->p_tb = this;
  }
  void add_function(GlobalTable *parent, string id_name, int param_count, string retr_type);
  void add_task(GlobalTable *parent, string id_name, int param_count, string retr_type);
  void add_type(GlobalTable *parent, string id_name);
  void add_start(GlobalTable *parent);
};

template <class T>
class FunctionTable
{
public:
  string name;        // function name
  int num_param;      // number of parameters
  string return_type; // (number/decimal/letter/text/user-defined/ arrays)

  IdentifierTable<FunctionTable<T> > *i_tb;     // pointer to identifier table (both parameters & varaiables in this table)
  NCLTable<FunctionTable<T> > * ncl_tb; // pointer to NCL Tables
  T *p_tb;                                     // Parent pointer
  FunctionTable()
  {
    i_tb = new IdentifierTable<FunctionTable>();
    ncl_tb = new NCLTable<FunctionTable<T> >();
    i_tb->p_tb = this;
    ncl_tb->p_tb = this;
  }
};

class TypeTable
{
public:
  string name;
  IdentifierTable<TypeTable> *i_tb;
  vector<FunctionTable<TypeTable> *> m_tb;
  GlobalTable *p_tb;
  TypeTable()
  {
    i_tb = new IdentifierTable<TypeTable>();
    i_tb->p_tb = this;
  }
  void add_method(string name, int num_param, string return_type);
};

class TaskTable
{
public:
  int num_param;
  string name;
  IdentifierTable<TaskTable> *i_tb;
  NCLTable<TaskTable> * ncl_tb;
  GlobalTable *p_tb;
  TaskTable()
  {
    i_tb = new IdentifierTable<TaskTable>();
    i_tb->p_tb = this ;
    ncl_tb = new NCLTable<TaskTable>();
    ncl_tb->p_tb = this ;
  }
};

// Global Search Function for an identifier
// Use -> if the identifier name string is sent as input then outputs if it is present or not->
// We need to send info of type = function/ task/ variable declaration->
// We should even mention if the identifier which we are using is assigned with the keyword in or not, then the search is changed according to that
template <class T>
bool search_identifier_out(T *cur_ptr, string id, bool is_array, vector<int> dims);

bool search_global_table(GlobalTable *cur_ptr, string id);


template <class T>
bool search_identifier_out_for_error(T *cur_ptr, string id);

bool search_func_identifier(GlobalTable *global_ptr, vector<string> &func_check);

bool search_task_identifier(GlobalTable *global_ptr, vector<string> &task_check);

bool search_attribute_type(GlobalTable *global_ptr, string id, string class_name, bool is_array, vector<int> dims);

bool search_type_idenitifer(GlobalTable *g_ptr, string id);

bool search_method(GlobalTable *global_ptr, string class_name, vector<string> &method_check);

#endif

// YACC Work
// Values that need to be passed from bottom to top
// constant values
// passing identifiers from top to bottom
