#include "errors.hpp"

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
  }else if(errorType == NUMBER_OF_PARAM_MISMATCH){
    errorStr = "Number of parameters to function call didn't match: " ;
  }else if(errorType == TASK_NOT_FOUND){
    errorStr = "Task not found at line: " ;
  }

  cout << errorStr << lineNumber << endl ;
}
