#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "symbol_table.hpp"
#include "errors.hpp"
#include "bison.tab.h"
#include "semantics.hpp"
using namespace std;
extern int yylineno;
extern int scopeLevel ;
/*-----------------------------------------------------------------------------SEARCH FUNCTIONS-----------------------------------------------------------------------------*/
// This function is used to search for identifier in any scope given the pointer to that scope table

template <class T>
bool search_current_scope_redeclaration(NCLTable<T> * ncl_tb, string id){
  for(auto i : ncl_tb->i_tb->i_struct){
    if(i->name == id && i->scopeLevel == scopeLevel) return true ;
  }
  else return false ;
}

// This Function is used to search if the Given identifier is already defined in the scope of current declared variable
bool search_global_table_attributes_redeclaration(GlobalTable * g_tb, string id){
  for(auto i: g_tb->i_tb->i_struct){
    if(i->name == id) return true;
  }
  return false ;
}

// This function is used to search identifier given type table pointer
bool search_type_table_attributes_redeclaration(TypeTable * c_tb, string id){
  for(auto i: c_tb->i_tb->i_struct){
    if(i->name == id) return true;
  }
  return false ;
}

// This Function is used to search if the Given currently declared function is already defined or not
bool search_function_redeclaration(GlobalTable * g_tb, string id, vector<IdentifierStruct > args_vec){
  for(auto i: g_tb->f_tb){
    int count = 0;
    if(i->name == id && args_vec.size() == i->num_param){
      for(int j = 0;j<args_vec.size();j++){
        if(i->i_tb->i_struct[j]->datatype == args_vec[j].datatype){
          count++;
        }
      }
    }
    if(count == i->num_param) return true ;
  }
  return false ;
}

bool search_task_redeclaration(GlobalTable * g_tb, string id){
  for(auto i: g_tb->t_tb){
    if(i->name == id){
      return true ;
    }
  }
  return false ;
}

bool search_type_redeclaration(GlobalTable * g_tb, string id){
  for(auto i: g_tb->c_tb){
    if(i->name == id){
      return true ;
    }
  }
  return false ;
}

// This Function is used to search if the Given currently declared method already exists or not in the class
bool search_method_redeclaration(TypeTable * c_tb, string id, vector<IdentifierStruct > args_vec){
  for(auto i: c_tb->m_tb){
    int count = 0;
    if(i->name == id && args_vec.size() == i->num_param){
      for(int j = 0;j<args_vec.size();j++){
        if(i->i_tb->i_struct[j]->datatype == args_vec[j].datatype){
          count++;
        }
      }
    }
    if(count == i->num_param) return true ;
  }
  return false ;
}


bool search_global_table_attribute(GlobalTable *g_tb, string id, bool is_array)
{
  for (auto k : g_tb->i_tb->i_struct)
  {
    if ( k->name == id && k->is_array == is_array)
    {
      return true ;
    }
  }
  return false;
}

bool search_type_attribute(TypeTable *t_tb, string id, bool is_array)
{
  for (auto i : t_tb->i_tb->i_struct)
  {
    if (i->name == id && i->is_array == is_array)
      return true;
  }
  return false;
}

// func_check is a vector where
// func_check[0] = function name
// func_check[i] = arguments data type -> for i >= 2
bool search_function(GlobalTable *g_tb, vector<string> &func_check)
{
  string func_name = func_check[0];

  for (auto i : g_tb->f_tb)
  {
    if (i->name == func_name)
    {
      if (func_check[1] == "null")
        return true;
      if ((func_check.size() - 1) != i->num_param)
      {
        break;
      }

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
bool search_task(GlobalTable *g_tb, vector<string> &task_check)
{
  string task_name = task_check[0];
  for (auto i : g_tb->t_tb)
  {
    if (i->name == task_name)
    {
      if (task_check[1] == "null")
        return true;
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
bool search_type(GlobalTable *g_tb, string id)
{
  for (auto i : g_tb->c_tb)
  {
    if (i->name == id)
      return true;
  }
  // printError(yylineno, TYPE_NOT_FOUND);
  return false;
}

// Global Functions -> Functions
// Class Functions -> Methods
bool search_method(TypeTable * t_tb , vector<string> &method_check)
{
  string method = method_check[0];
      for (auto i : t_tb->m_tb)
      {
        if (i->name == method)
        {
      if (method_check[1] == "null")
        return true;
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

/*-----------------------------------------------------------------------------ADD FUNCTIONS-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------Global Table Functions-----------------------------------------------------------------------------*/

// This function is used to add a new function into the vector f_tb of global table
void GlobalTable::add_function(GlobalTable *parent, string name,vector<IdentifierStruct> args, string return_type)
{

  FunctionTable<GlobalTable> *F_struct = new FunctionTable<GlobalTable>();
  
  F_struct->name = name;
  F_struct->num_param = args.size();
  F_struct->return_type = return_type;
  F_struct->p_tb = parent;
  for(int i = 0;i<args.size();i++){
    F_struct->i_tb->add_variable(args[i].name,args[i].is_atomic,args[i].is_array,args[i].datatype,args[i].dimensions);
  }
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
  I->scopeLevel = scopeLevel;
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

  this->m_tb.push_back(F_struct);
}

// If we have a Type table object then we can perform the following
// TypeTable<T> obj;
// Add a method to its scope -> obj.add_method()
// Add a type attribute to scope -> obj.i_tb.add_variable()

/*-----------------------------------------------------------------------------NCL Table Functions-----------------------------------------------------------------------------*/
template <class T>
void NCLTable<T>::add_ncltable(string name, bool is_atomic, bool is_array, string datatype, vector<int> dims)
{
  IdentifierStruct *I = new IdentifierStruct();
  I->name = name;
  I->is_atomic = is_atomic;
  I->is_array = is_array;
  I->datatype = datatype;
  I->scopeLevel = scopeLevel;
  for (auto a : dims)
    I->dimensions.push_back(a);
  this->i_struct.push_back(I);
}

template <class T>
void NCLTable<T>::pop_ncltable(){
  int count = 0;
  for(auto i : this->i_tb->i_struct){
    if(i->scopeLevel == scopeLevel) count++;
  }
  this->i_tb->i_struct.erase(this->i_tb->i_struct.end() - count,this->i_tb->i_struct.end());
}

// If we have a NCL table object then we can perform the following
// NCLTable<T> obj;
// Add a nested scope -> obj.add_ncltable() -> then the temporary scope variable is added 
// When we exit out of the scope we call this pop_ncl table function which erases all the current state elements

