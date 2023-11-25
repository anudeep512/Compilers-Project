#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <iostream>
#include <vector>
#include <string>
#include "bison.tab.h"
#include "errors.hpp"
#include "semantics.hpp"

using namespace std;

typedef struct {
  string name ;
  string type ;
  vector<string> arguments ;
  vector<int> is_array ;
  vector<int> is_atomic ;
  string return_datatype ;
  bool is_array_return_datatype ;
} method_table_row ;

typedef struct {
  string name ;
  vector<string> arguments ;
  vector<int> is_array ;
  vector<int> is_atomic ;
  string return_datatype ;
  bool is_array_return_datatype ;
} function_table_row;

typedef struct {
  string name ;
  vector<string> arguments ;
  vector<int> args_atomic ;
  vector<int> args_is_array ;
} task_table_row ;

typedef struct {
  string name ;
  string datatype ;
  bool is_atomic ;
  bool is_array ;
  int scopelevel ;
  int arrayLevel ;
} variable_table_row ;

typedef struct{
  string name ;
  string type ;
  string datatype ;
  bool is_array ;
  bool is_atomic;
  int arrayLevel ;
} attribute_table_row;

typedef struct{
  string name ;
} type_table_row ;

class MethodTable{
public:
  vector<method_table_row> m_tb ;
  void addMethod(string name, string type, vector<string> arguments, vector<int> is_array,vector<int> is_atomic, string return_datatype, bool is_array_return_datatype);
  string searchMethod(string type, string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic);
  vector<string> rhsSearchMethod(string name,string type, vector<string> arguments, vector<int> is_array,vector<int> is_atomic);
  void print();
};

class FunctionTable{
public:
  vector<function_table_row> f_tb ;
  void addFunction(string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic,string return_datatype, bool is_array_return_datatype);
  string searchFunction(string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic);
  vector<string> rhsSearchFunction(string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic);
  void print();
};

class TaskTable{
public:
  vector<task_table_row> t_tb ;
  void addTask(string name, vector<string> arguments,  vector<int> is_array, vector<int> is_atomic);
  bool searchTask(string name, vector<string> arguments,  vector<int> is_array, vector<int> is_atomic);
  void print();
};

class VariableTable{
public:
  vector<variable_table_row> i_tb ;
  void addVariable(string name, string datatype, bool is_atomic, bool is_array, int arrayLevel); // Scope Level is setted automatically
  void deleteVariables(); // Delete all the variables in the current before exiting it
  string searchVariable(string name); // Start traversing from below and return its datatype 
  bool searchDeclaration(string name);
  vector<string> rhsSearchVariable(string name);
  void print();
};

class AttributeTable{
public:
  vector<attribute_table_row> i_tb ;
  void addVariable(string name, string type,string datatype, bool is_atomic, bool is_array, int arrayLevel);
  string searchAttribute(string name, string type); // Starts traversing from below and returns the variable datatype
  vector<string> rhsSearchAttribute(string name, string type);
  void print();
};

class TypeTable{
public:
  vector<type_table_row> c_tb ;
  void addType(string type);
  bool searchType(string name);
  void print();
};


#endif


