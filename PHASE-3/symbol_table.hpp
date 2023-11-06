#ifndef _SYMBOL_TABLE_HPP
#define _SYMBOL_TABLE_HPP

#include <iostream>


class GlobalTable{
public:
  vector<ClassTable > c_tb ;
  vector<TaskTable > t_tb ;
  vector<FunctionTable > f_tb ;
  IdentifierTable i_tb ;
  StartTable s_tb ;
  auto p_tb ;

  // Adding can be:
  // 1) Adding a new class-table object to vector c_tb
  // 2) Adding a new task-table object to t_tb
  // 3) Adding a new function-table object to f_tb
  // 4) Pointing to an identifier table and then adding variables to the table
  // 5) Pointing to a new start table using s_tb 
  // 6) Points to parent table
  int add();
  int del();

};

class NCLTable{
public:
  IdentifierTable i_tb ;
  vector<NCLTable> ncl_tb ;
  auto p_tb ;

  // Adding can be:
  // 1) Pointing to an identifier table and then adding variables to the table
  // 2) Adding a new ncl-table object to 
  int add();
  int del();
}

// Global Search Function for an identifier
// Use -> if the identifier name string is sent as input then outputs if it is present or not.
// We need to send info of type = function/ task/ variable declaration.
// We should even mention if the identifier which we are using is assigned with the keyword in or not, then the search is changed according to that
bool search();

#endif
