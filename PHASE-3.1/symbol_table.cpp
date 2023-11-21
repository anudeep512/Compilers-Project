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
using namespace std ;

/* -------------------------------------------------------- METHOD TABLE ----------------------------------------------------- */

void MethodTable::addMethod(string name, string type, vector<string> arguments, string return_datatype, bool is_array_return_datatype, bool is_function_atomic){
  method_table_row add ;
  add.arguments = arguments;
  add.is_array_return_datatype = is_array_return_datatype;
  add.is_function_atomic = is_function_atomic ;
  add.name = name ;
  add.return_datatype = return_datatype ;
  add.type = type;
  this->m_tb.push_back(add);
}

string MethodTable::searchMethod(string type, string name, vector<string> arguments){
  for(int i = this->m_tb.size() - 1 ; i >= 0 ;i-- ){
    if(this->m_tb[i].name == name && arguments == this->m_tb[i].arguments){
      return this->m_tb[i].return_datatype ;
    }
  }
  return "" ;
}

void MethodTable::print(){
  for(auto i : this->m_tb){
    cout << i.is_function_atomic << " " << i.type << "::" << i.name << " - " ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << " - " << i.is_array_return_datatype << endl ;
  }
}

/* -------------------------------------------------------- FUNCTION TABLE ----------------------------------------------------- */

void FunctionTable::addFunction(string name, vector<string> arguments, vector<int> is_array, string return_datatype, bool is_array_return_datatype, bool is_function_atomic){
  function_table_row add ;
  add.arguments = arguments;
  add.is_array_return_datatype = is_array_return_datatype;
  add.is_function_atomic = is_function_atomic ;
  add.name = name ;
  add.is_array = is_array ;
  add.return_datatype = return_datatype ;
  this->f_tb.push_back(add);
}

string FunctionTable::searchFunction(string name, vector<string> arguments, vector<int> is_array){
  for(int i = this->f_tb.size() - 1 ; i>=0 ; i-- ){
    if(this->f_tb[i].name == name && arguments == this->f_tb[i].arguments && is_array[i] == this->f_tb[i].is_array[i]){
      return this->f_tb[i].return_datatype ;
    }
  }
  return "" ;
}

void FunctionTable::print(){
  for(auto i : this->f_tb){
    cout << i.is_function_atomic << " " << i.name << " - " ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << " - " << i.is_array_return_datatype << endl ;
  }
}

/* -------------------------------------------------------- TASK TABLE ----------------------------------------------------------- */

void TaskTable::addTask(string name, vector<string> arguments){
  task_table_row add;
  add.arguments = arguments;
  add.name = name;
  this->t_tb.push_back(add);
}

bool TaskTable::searchTask(string name, vector<string> arguments){
  for(int i =this->t_tb.size()-1;i>=0;i--){
    if(this->t_tb[i].name == name && this->t_tb[i].arguments == arguments){
      return true ;
    }
  }
  return false ;
}

void TaskTable::print(){
  for(auto i : this->t_tb){
    cout << i.name << " - " ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << endl ;
  }
}

/* -------------------------------------------------------- VARIABLE TABLE --------------------------------------------------------- */

void VariableTable::addVariable(string name, string datatype, bool is_atomic, bool is_array){
  variable_table_row add;
  add.datatype = datatype;
  add.name = name;
  add.is_array = is_array;
  add.is_atomic = is_atomic;
  cout << scopeLevel << endl ;
  add.scopelevel = scopeLevel;
  this->i_tb.push_back(add);
}

void VariableTable::deleteVariables(){
  int counter = 0;
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].scopelevel == scopeLevel) counter++;
    else break;
  } 
  this->i_tb.erase(this->i_tb.end() - counter, this->i_tb.end());
}

string VariableTable::searchVariable(string name){  
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].name == name) return this->i_tb[i].datatype ;
  }
  return "" ;
}

bool VariableTable::searchDeclaration(string name){
  for(int i = this->i_tb.size() - 1; i >= 0;i--){
    if(this->i_tb[i].name == name && this->i_tb[i].scopelevel== scopeLevel) return true ;
  }
  return false ;
}


void VariableTable::print(){
  for(auto i: this->i_tb){
    cout << i.name << " " << i.datatype << " ,is_array: " << i.is_array << " ,is_atomic: " <<i.is_atomic << " ,scopeLevel: " << i.scopelevel << endl ;
  }
}

/* -------------------------------------------------------- ATTRIBUTE TABLE ---------------------------------------------------------- */

void AttributeTable::addVariable(string name, string type,string datatype, bool is_atomic, bool is_array){
  attribute_table_row add;
  add.datatype = datatype;
  add.is_array = is_array ;
  add.is_atomic = is_atomic ;
  add.name = name ;
  add.type = type ;
  this->i_tb.push_back(add);
}

string AttributeTable::searchAttribute(string name, string type){
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].name == name && this->i_tb[i].type == type) return this->i_tb[i].datatype ;
  }
  return "" ;
}

void AttributeTable::print(){
  for(auto i: this->i_tb){
    cout << "Type: " << i.type << " , " << i.name << " , " << i.datatype << " ,is_array: " << i.is_array << " ,is_atomic: " << i.is_atomic << endl ;
  }
}

/* -------------------------------------------------------- TYPE TABLE ---------------------------------------------------------------- */

void TypeTable::addType(string type){
  type_table_row add ;
  add.name = type ;
  this->c_tb.push_back(add);  
}

bool TypeTable::searchType(string name){
  for(int i = this->c_tb.size() - 1; i >= 0; i--){
    if(this->c_tb[i].name == name) return true ;
  }
  return false ;
}

void TypeTable::print(){
  for(auto i : this->c_tb){
    cout << i.name << endl ;
  }
}

/* -------------------------------------------------------------------------------------------------------------------------------------- */

