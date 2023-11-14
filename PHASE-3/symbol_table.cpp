#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "symbol_table.hpp"
#include "errors.hpp"
using namespace std;
extern int yylineno;
/*-----------------------------------------------------------------------------SEARCH FUNCTIONS-----------------------------------------------------------------------------*/
// This function is used to search for identifier in any scope given the pointer to that scope table
template <class T>
bool search_identifier(T *curr_ptr, string id, bool is_array, vector<int> dims)
{
  for (auto i : curr_ptr->i_tb->i_struct)
  {
    if (i->name == id && is_array == false)
      return true;
    else if (i->name == id && is_array == true)
    {
      if (dims.size() <= i->dimensions.size())
      {
        for (int j = 0; j < dims.size(); j++)
        {
          if (dims[j] >= i->dimensions[j])
          {
            // printError(yylineno, ARRAY_OUT_OF_BOUNDS);
            return false;
          }
        }
        return true;
      }
      else
      {
        // printError(yylineno, ARRAY_OUT_OF_BOUNDS);
        return false;
      }
    }
  }
  if (curr_ptr->p_tb == NULL)
  {
    // printError(yylineno, VARIABLE_NOT_FOUND);
    return false;
  }
  else
    return search_identifier(curr_ptr->p_tb, id);
}

bool search_attribute_type(GlobalTable *global_ptr, string id, string class_name, bool is_array, vector<int> dims)
{

  for (auto k : global_ptr->c_tb)
  {
    if (k->name == class_name)
    {
      for (auto i : k->i_tb->i_struct)
      {
        if (i->name == id && is_array == false)
          return true;
        else if (i->name == id && is_array == true)
        {
          if (dims.size() <= i->dimensions.size())
          {
            for (int j = 0; j < dims.size(); j++)
            {
              if (dims[j] >= i->dimensions[j])
              {
                // printError(yylineno, ARRAY_OUT_OF_BOUNDS);
                return false;
              }
            }
            return true;
          }
          else
          {
            // printError(yylineno, TYPE_ATTR_NOT_FOUND);
            return false;
          }
        }
      }
    }
  }
  return false;
}

// func_check is a vector where
// func_check[0] = function name
// func_check[i] = arguments data type -> for i >= 2
bool search_func_identifier(GlobalTable *global_ptr, vector<string> &func_check)
{
  string func_name = func_check[0];

  for (auto i : global_ptr->f_tb)
  {
    if (i->name == func_name)
    {
      if ((func_check.size() - 1) != i->num_param)
      {
        break;
      }
      if (func_check[1] == "null")
        return true;
      int a = 1;
      for (auto j : i->i_tb->i_struct)
      {
        if (j->datatype != func_check[a])
        {
          break;
        }
        else
        {
          a++;
          if (a > i->num_param)
          {
            return true;
          }
        }
      }
    }
  }
  // printError(yylineno, FUNCTION_NOT_FOUND);
  return false;
}

// func_check is a vector where
// func_check[0] = function name
// func_check[i] = arguments data type -> for i >= 1
bool search_task_identifier(GlobalTable *global_ptr, vector<string> &task_check)
{
  string task_name = task_check[0];
  for (auto i : global_ptr->t_tb)
  {
    if (i->name == task_name)
    {
      if ((task_check.size() - 1) != i->num_param)
      {
        // printError(yylineno, NUMBER_OF_PARAM_MISMATCH);
        return false;
      }

      int a = 1;

      for (auto j : i->i_tb->i_struct)
      {
        if (j->datatype != task_check[a])
        {
          // printError(yylineno, TYPE_ERROR_RHS);
          return false;
        }
        else
        {
          a++;
          if (a > i->num_param)
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

/*
  Semantics required for class function:
    -  Check if a class with given name exists
    -  Whenever an attribute is accessed, check if there is an attribute with that identifier
    -  Whenever a class method is accessed, search of there is a function with that name and those parameters
*/
bool search_type_idenitifer(GlobalTable *global_ptr, string id)
{
  for (auto i : global_ptr->c_tb)
  {
    if (i->name == id)
      return true;
  }
  // printError(yylineno, TYPE_NOT_FOUND);
  return false;
}

// Global Functions -> Functions
// Class Functions -> Methods
bool search_method(GlobalTable *global_ptr, string class_name, vector<string> &method_check)
{
  string method = method_check[0];

  for (auto k : global_ptr->c_tb)
  {
    if (k->name == class_name)
    {
      for (auto i : k->f_tb)
      {
        if (i->name == method)
        {
          // For Handling function overloading
          if (method_check.size() - 1 != i->num_param)
          {
            break;
          }

          int a = 1;

          for (auto j : i->i_tb->i_struct)
          {
            if (j->datatype != method_check[a])
            {
              // printError(yylineno, TYPE_ERROR_RHS);
              return false;
            }
            else
            {
              a++;
              if (a > i->num_param)
              {
                return true;
              }
            }
          }
        }
      }
      // printError(yylineno, METHOD_NOT_FOUND);
      return false;
    }
  }
  return false;
}

/*-----------------------------------------------------------------------------ADD FUNCTIONS-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------Global Table Functions-----------------------------------------------------------------------------*/

// This function is used to add a new function into the vector f_tb of global table
void GlobalTable::add_function(GlobalTable *parent, string name, int num_param, string return_type)
{

  FunctionTable<GlobalTable> *F_struct = new FunctionTable<GlobalTable>();
  F_struct->name = name;
  F_struct->num_param = num_param;
  F_struct->return_type = return_type;
  F_struct->p_tb = parent;
  this->f_tb.push_back(F_struct);
}

// This function is used to add a new task into global table
void GlobalTable::add_task(GlobalTable *parent, string name, int num_param, string return_type)
{

  TaskTable *T_struct = new TaskTable();
  T_struct->name = name;
  T_struct->num_param = num_param;
  T_struct->p_tb = parent;
  this->t_tb.push_back(T_struct);
}

// This function is used to add a new type into global table
void GlobalTable::add_type(GlobalTable *parent, string name)
{

  TypeTable *Ty_struct = new TypeTable();
  Ty_struct->name = name;
  Ty_struct->p_tb = parent;
  this->c_tb.push_back(Ty_struct);
}

// This function is used to add start into global table
void GlobalTable::add_start(GlobalTable *parent)
{
  StartTable *start_struct = new StartTable();
  start_struct->p_tb = parent;
  this->s_tb = start_struct;
}

// So after creation of the Global table object we can perform the following operations on global table
// We have "GlobalTable obj" as the object to work upon
// Add a function -> call: obj.add_function()
// Add a type -> call: obj.add_type()
// Add start -> call: obj.add_start()
// Add a task -> call: obj.add_task()
// Add a global variable -> call: obj.i_tb.add_variable()

/*-----------------------------------------------------------------------------Identifier Table Functions-----------------------------------------------------------------------------*/
// This function is used to insert an identifier into i_tb
template <class T>
void IdentifierTable<T>::add_variable(string name, bool is_atomic, bool is_array, string datatype, vector<int> dims)
{

  IdentifierStruct *I = new IdentifierStruct();
  I->name = name;
  I->is_atomic = is_atomic;
  I->is_array = is_array;
  I->datatype = datatype;
  for (auto a : dims)
    I->dimensions.push_back(a);
  this->i_struct.push_back(I);
}

// If we have a Identifier table object then we can perform the following
// IdentifierTable<T> obj;
// Add a method to its scope -> obj.add_method()
// Add a type attribute to scope -> obj.i_tb.add_variable()

/*-----------------------------------------------------------------------------Type Table Functions-----------------------------------------------------------------------------*/
// This function is used to insert a method into Type table
void TypeTable::add_method(string name, int num_param, string return_type)
{

  FunctionTable<TypeTable> *F_struct = new FunctionTable<TypeTable>();
  F_struct->name = name;
  F_struct->num_param = num_param;
  F_struct->return_type = return_type;

  this->f_tb.push_back(F_struct);
}

// If we have a Type table object then we can perform the following
// TypeTable<T> obj;
// Add a method to its scope -> obj.add_method()
// Add a type attribute to scope -> obj.i_tb.add_variable()

/*-----------------------------------------------------------------------------NCL Table Functions-----------------------------------------------------------------------------*/
template <class T>
void NCLTable<T>::add_ncltable(NCLTable<T> *parent)
{
  NCLTable<NCLTable<T>> *child = new NCLTable<NCLTable<T>>();
  child->p_tb = parent;
  this->ncl_tb.push_back(child);
}

// If we have a NCL table object then we can perform the following
// NCLTable<T> obj;
// Add a nested scope -> obj.add_ncltable()
// Add a type attribute to scope -> obj.i_tb.add_variable()

/*-----------------------------------------------------------------------------Start Table Functions-----------------------------------------------------------------------------*/
void StartTable::add_ncltable(StartTable *parent)
{
  NCLTable<StartTable> *child = new NCLTable<StartTable>;
  child->p_tb = parent;
  this->ncl_tb.push_back(child);
}

// If we have a Start Table object then we can perform the following
// StartTable obj;
// Add a method to its scope -> obj.add_ncltable()
// Add a type attribute to start scope -> obj.i_tb.add_variable()
// Adding nested scope to another ncl table -> obj.ncl_table[i].add_ncltable()

/*-----------------------------------------------------------------------------Function Table Functions-----------------------------------------------------------------------------*/
template <class T>
void FunctionTable<T>::add_ncltable(FunctionTable<T> *parent)
{
  NCLTable<FunctionTable<T>> *child = new NCLTable<FunctionTable<T>>();
  child->p_tb = parent;
  this->ncl_tb.push_back(child);
}

// If we have a Start Table object then we can perform the following
// FunctionTable<T> obj;
// Add a type attribute to start scope -> obj.i_tb.add_variable()
// Adding nested scope to another ncl table -> obj.ncl_table[i].add_ncltable()

/*-----------------------------------------------------------------------------Task Table Functions-----------------------------------------------------------------------------*/
void TaskTable::add_ncltable(TaskTable *parent)
{
  NCLTable<TaskTable> *child;
  child->p_tb = parent;
  this->ncl_tb.push_back(child);
}

// If we have a Start Table object then we can perform the following
// TaskTable<T> obj;
// Add a type attribute to start scope -> obj.i_tb.add_variable()
// Adding nested scope to another ncl table -> obj.ncl_table[i].add_ncltable()
