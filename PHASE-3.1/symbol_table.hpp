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
  string return_datatype ;
  bool is_array_return_datatype ;
  bool is_function_atomic;
} method_table_row ;

typedef struct {
  string name ;
  vector<string> arguments ;
  vector<int> is_array ;
  string return_datatype ;
  bool is_array_return_datatype ;
  bool is_function_atomic;
} function_table_row;

typedef struct {
  string name ;
  vector<string> arguments ;
} task_table_row ;

typedef struct {
  string name ;
  string datatype ;
  bool is_atomic ;
  bool is_array ;
  int scopelevel ;
} variable_table_row ;

typedef struct{
  string name ;
  string type ;
  string datatype ;
  bool is_array ;
  bool is_atomic;
} attribute_table_row;

typedef struct{
  string name ;
} type_table_row ;

class MethodTable{
public:
  vector<method_table_row> m_tb ;
  void addMethod(string name, string type, vector<string> arguments, string return_datatype, bool is_array_return_datatype, bool is_function_atomic);
  string searchMethod(string type, string name, vector<string> arguments);
  void print();
};

class FunctionTable{
public:
  vector<function_table_row> f_tb ;
  void addFunction(string name, vector<string> arguments, vector<int> is_array,string return_datatype, bool is_array_return_datatype, bool is_function_atomic);
  string searchFunction(string name, vector<string> arguments, vector<int> is_array);
  void print();
};

class TaskTable{
public:
  vector<task_table_row> t_tb ;
  void addTask(string name, vector<string> arguments);
  bool searchTask(string name, vector<string> arguments);
  void print();
};

class VariableTable{
public:
  vector<variable_table_row> i_tb ;
  void addVariable(string name, string datatype, bool is_atomic, bool is_array); // Scope Level is setted automatically
  void deleteVariables(); // Delete all the variables in the current before exiting it
  string searchVariable(string name); // Start traversing from below and return its datatype 
  bool searchDeclaration(string name);
  void print();
};

class AttributeTable{
public:
  vector<attribute_table_row> i_tb ;
  void addVariable(string name, string type,string datatype, bool is_atomic, bool is_array);
  string searchAttribute(string name, string type); // Starts traversing from below and returns the variable datatype
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


