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

void MethodTable::addMethod(string name, string type, vector<string> arguments,  vector<int> is_array,vector<int> is_atomic,string return_datatype, bool is_array_return_datatype){
  method_table_row add ;
  add.arguments = arguments;
  add.is_array_return_datatype = is_array_return_datatype;
  add.name = name ;
  add.is_array = is_array ;
  add.is_atomic = is_atomic ;
  add.return_datatype = return_datatype ;
  add.type = type;
  this->m_tb.push_back(add);
}

string MethodTable::searchMethod(string name, string type, vector<string> arguments,  vector<int> is_array,vector<int> is_atomic){

  for(int i = this->m_tb.size() - 1 ; i >= 0 ;i-- ){
    if(this->m_tb[i].type == type && this->m_tb[i].name == name && arguments == this->m_tb[i].arguments && is_array == this->m_tb[i].is_array && is_atomic == this->m_tb[i].is_atomic){
      return this->m_tb[i].return_datatype ;
    }
  }
  return "" ;
}

vector<string> MethodTable::rhsSearchMethod(string name, string type,vector<string> arguments, vector<int> is_array,vector<int> is_atomic){
  vector<string> a ;
  for(int i = this->m_tb.size() - 1 ; i>=0 ; i-- ){
    // cout << "Here: " ;    
    // for(auto i: this->m_tb[i].arguments){
    //   cout << i << " " ;
    // }
    // cout << endl ;
    if(this->m_tb[i].name == name && this->m_tb[i].type == type && compatibility_calls(arguments, this->m_tb[i].arguments) && is_array == this->m_tb[i].is_array && is_atomic == this->m_tb[i].is_atomic){
      a.push_back(this->m_tb[i].return_datatype);
      a.push_back(to_string(this->m_tb[i].is_array_return_datatype));
      break ;
    }
  }
  return a ;
}

void MethodTable::print(){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Methods are: " << endl ;
  for(auto i : this->m_tb){
    cout << i.type << "::" << i.name << " - " ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << ", is_return_array: " << i.is_array_return_datatype << endl ;
    for(auto j: i.is_array){
      cout << j <<", " ;
    }
    cout << endl ;
    for(auto j: i.is_atomic){
      cout << j << ", ";
    }
    cout << endl ;
  }
}

/* -------------------------------------------------------- FUNCTION TABLE ----------------------------------------------------- */

void FunctionTable::addFunction(string name, vector<string> arguments, vector<int> is_array, vector<int> is_atomic,string return_datatype, bool is_array_return_datatype){
  function_table_row add ;
  add.arguments = arguments;
  add.is_array_return_datatype = is_array_return_datatype;
  add.name = name ;
  add.is_array = is_array ;
  add.is_atomic = is_atomic ;
  add.return_datatype = return_datatype ;
  this->f_tb.push_back(add);
}

string FunctionTable::searchFunction(string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic){
  for(int i = this->f_tb.size() - 1 ; i>=0 ; i-- ){
    if(this->f_tb[i].name == name && arguments == this->f_tb[i].arguments && is_array == this->f_tb[i].is_array && is_atomic == this->f_tb[i].is_atomic){
      return this->f_tb[i].return_datatype ;
    }
  }
  return "" ;
}

vector<string> FunctionTable::rhsSearchFunction(string name, vector<string> arguments, vector<int> is_array,vector<int> is_atomic){
  vector<string> a ;
  for(int i = this->f_tb.size() - 1 ; i>=0 ; i-- ){
    if(this->f_tb[i].name == name && compatibility_calls(arguments, this->f_tb[i].arguments) && is_array == this->f_tb[i].is_array && is_atomic == this->f_tb[i].is_atomic){
      a.push_back(this->f_tb[i].return_datatype);
      a.push_back(to_string(this->f_tb[i].is_array_return_datatype));
      break ;
    }
  }
  return a ;
}


void FunctionTable::print(){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Functions are: " << endl ;
  for(auto i : this->f_tb){
    cout << i.name << endl ;
    cout << " args type: " ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << endl ;
    cout << " args is_atomic: ";
    for(auto j : i.is_atomic){
      cout << j << ", ";
    }
    cout << endl ;
    cout << " args is_array: ";
    for(auto j : i.is_array){
      cout << j << ", ";
    }
    cout << endl ;
    cout << " return_is_array: " << i.is_array_return_datatype << endl ;
  }
}

/* -------------------------------------------------------- TASK TABLE ----------------------------------------------------------- */

void TaskTable::addTask(string name, vector<string> arguments,  vector<int> is_array, vector<int> is_atomic){
  task_table_row add;
  add.arguments = arguments;
  add.name = name;
  add.args_atomic = is_atomic ;
  add.args_is_array = is_array ;
  this->t_tb.push_back(add);
}

bool TaskTable::searchTask(string name, vector<string> arguments, vector<int> is_array, vector<int> is_atomic){
  for(int i =this->t_tb.size()-1;i>=0;i--){
    if(this->t_tb[i].name == name && compatibility_calls(this->t_tb[i].arguments, arguments) && this->t_tb[i].args_atomic == is_atomic && this->t_tb[i].args_is_array == is_array){
      return true ;
    }
  }
  return false ;
}

void TaskTable::print(){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Tasks are: " << endl ;
  for(auto i : this->t_tb){
    cout << i.name << endl ;
    cout << "arguments: " << endl ;
    for(auto j : i.arguments){
      cout << j << ", " ;
    }
    cout << endl ;
  }
}

/* -------------------------------------------------------- VARIABLE TABLE --------------------------------------------------------- */

void VariableTable::addVariable(string name, string datatype, bool is_atomic, bool is_array, int arrayLevel){
  variable_table_row add;
  add.datatype = datatype;
  add.name = name;
  add.is_array = is_array;
  add.is_atomic = is_atomic;
  add.scopelevel = scopeLevel;
  add.arrayLevel = arrayLevel ;
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

vector<string> VariableTable::rhsSearchVariable(string name){
  //  <<"symbol-table.cpp-197 " << name << endl ;
  vector<string> ret ;
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].name == name) {
      ret.push_back(this->i_tb[i].datatype);
      ret.push_back(to_string(this->i_tb[i].is_array)) ;
      ret.push_back(to_string(this->i_tb[i].is_atomic)) ;
      ret.push_back(to_string(this->i_tb[i].arrayLevel));
      break;
    }
  }
  return ret ;
}


bool VariableTable::searchDeclaration(string name){
  for(int i = this->i_tb.size() - 1; i >= 0;i--){
    if(this->i_tb[i].name == name && this->i_tb[i].scopelevel== scopeLevel) return true ;
  }
  return false ;
}


void VariableTable::print(){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Variables are: " << endl ;
  for(auto i: this->i_tb){
    cout << i.name << " " << i.datatype << " ,is_array: " << i.is_array << " ,is_atomic: " <<i.is_atomic << " ,scopeLevel: " << i.scopelevel <<" ,arraylevel: "<<i.arrayLevel << endl ;
  }
}

/* -------------------------------------------------------- ATTRIBUTE TABLE ---------------------------------------------------------- */

void AttributeTable::addVariable(string name, string type,string datatype, bool is_atomic, bool is_array, int arrayLevel){
  attribute_table_row add;
  add.datatype = datatype;
  add.is_array = is_array ;
  add.is_atomic = is_atomic ;
  add.name = name ;
  add.type = type ;
  add.arrayLevel = arrayLevel ;
  this->i_tb.push_back(add);
}

string AttributeTable::searchAttribute(string name, string type){
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].name == name && this->i_tb[i].type == type) return this->i_tb[i].datatype ;
  }
  return "" ;
}

vector<string> AttributeTable::rhsSearchAttribute(string name, string type){
  vector<string> ret ;
  for(int i = this->i_tb.size() - 1; i >= 0; i--){
    if(this->i_tb[i].name == name && this->i_tb[i].type == type) {
      ret.push_back(this->i_tb[i].datatype);
      ret.push_back(to_string(this->i_tb[i].is_array)) ;
      ret.push_back(to_string(this->i_tb[i].is_atomic)) ;
      ret.push_back(to_string(this->i_tb[i].arrayLevel)) ;
      break ;
    }
  }
  return ret ;
}

void AttributeTable::print(){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Attribute Table: "<< endl ;
  for(auto i: this->i_tb){
    cout << i.name << " , " << "Type: " << i.type << " , " << i.datatype << " ,is_array: " << i.is_array << " ,is_atomic: " << i.is_atomic << endl ;
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
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Types are: " << endl ;
  for(auto i : this->c_tb){
    cout << i.name << endl ;
  }
}

/* -------------------------------------------------------------------------------------------------------------------------------------- */

