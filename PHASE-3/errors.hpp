#ifndef _ERRORS_HPP_
#define _ERRORS_HPP_

#include "semantics.hpp"
#include "symbol_table.hpp"

#define REDECLARATION_ERROR 1
#define VARIABLE_NOT_FOUND 2
#define ARRAY_OUT_OF_BOUNDS 3
#define TYPE_NOT_FOUND 3
#define FUNCTION_NOT_FOUND 4
#define METHOD_NOT_FOUND 5
#define TYPE_ATTR_NOT_FOUND 6
#define TYPE_ERROR_RHS 7
#define TYPE_ERROR_RHS_LHS 8
#define LEVEL_ERROR 9 // Need to look into this might be handled in RHS error
#define PREDICATE_ERROR 10
// Redeclaration error
// Variable not found
// Array out of bounds
// Type doesn't exist
// Function doesn't exist
// Method doesn't exist (id->func())
// Access variable doesn't exist (id->id)
// Type error in RHS
// Type error when LHS = RHS
// Level error (i.e., int ** = int *)
// For Type check function we send the value of argument "operator" as: -, +, <, <=, >=, >, ^, /, &&, || i.e., all_ops
// Predicate expressions which are non-coersible with integer Error :: (i.e., no strings)

void printError(int lineNumber, int errorType){
  string errorStr = ""; 
  if(errorType == REDECLARATION_ERROR){
    errorStr = "Redeclaration error at line: ";
  }else if(errorType == VARIABLE_NOT_FOUND){
    errorStr = "Variable not found error at line: ";
  }else if(errorType == ARRAY_OUT_OF_BOUNDS){
    errorStr = "Array access out of bounds at line: ";
  }else if(errorType = TYPE_NOT_FOUND){
    errorStr = "Type was not found at line: ";
  }else if(errorType == FUNCTION_NOT_FOUND){
    errorStr = "Function not found at line: " ;
  }else if(errorType == METHOD_NOT_FOUND){
    errorStr = "Method not found at line: ";
  }else if(errorType == TYPE_ATTR_NOT_FOUND){
    errorStr = "Access attribute not found at line: ";
  }else if(errorType == TYPE_ERROR_RHS){
    errorStr = "Type error in RHS at line: ";
  }else if(errorType == TYPE_ERROR_RHS_LHS){
    errorStr = "Type error in LHS = RHS at line: ";
  }else if(errorType == LEVEL_ERROR){
    errorStr = "Level error in at line: " ;
  }else if(errorType == PREDICATE_ERROR){
    errorStr = "Error in predicate types at line: " ;
  }

  cout << errorStr << lineNumber << endl ;
}

#endif
