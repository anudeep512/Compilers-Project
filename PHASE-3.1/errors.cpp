#include "errors.hpp"

void printError(int lineNumber, int errorType){
  string errorStr = ""; 
  if(errorType == VARIABLE_REDECLARATION_ERROR){
    errorStr = "Variable Redeclaration error at line: ";
  }else if(errorType == VARIABLE_NOT_FOUND){
    errorStr = "Variable not found error at line: ";
  }else if(errorType == TYPE_NOT_FOUND){
    errorStr = "Type was not found at line: ";
  }else if(errorType == FUNCTION_NOT_FOUND){
    errorStr = "Function not found at line: " ;
  }else if(errorType == METHOD_NOT_FOUND){
    errorStr = "Method not found at line: ";
  }else if(errorType == TYPE_ATTR_NOT_FOUND){
    errorStr = "Access attribute not found for the object type at line: ";
  }else if(errorType == TYPE_ERROR_RHS){
    errorStr = "Type error in RHS at line: ";
  }else if(errorType == TYPE_ERROR_RHS_LHS){
    errorStr = "Type error in LHS = RHS at line: ";
  }else if(errorType == LEVEL_ERROR){
    errorStr = "Level error in at line: " ;
  }else if(errorType == PREDICATE_ERROR){
    errorStr = "Error in predicate types at line: " ;
  }else if(errorType == TASK_NOT_FOUND){
    errorStr = "Task not found at line: " ;
  }else if(errorType == TYPE_REDECLARATION){
    errorStr = "Type redeclaration at line: " ;
  }else if(errorType == FUNCTION_REDECLARATION_ERROR){
    errorStr = "Function redeclaration at line: " ;
  }else if(errorType == RETURN_TYPE_ERROR){
    errorStr = "return type mismatch at line: " ;
  }else if(errorType == IN_SCOPE_ERROR){
    errorStr = "Insuitable position of IN at line: " ;
  }else if(errorType == TYPE_REDECLARATION){
    errorStr = "Type redeclaration at line: " ;
  }else if(errorType == TASK_REDECLARATION_ERROR){
    errorStr = "Task redeclaration at line: " ;
  }else if(errorType == TYPE_ATTR_REDECLARATION){
    errorStr = "Type attribute redeclaration at line: " ;
  }else if(errorType == START_ERROR_LESS){
    errorStr = "Should have atleast one START code block in the code" ;
  }else if(errorType == START_ERROR_MORE){
    errorStr = "More than one defination of start at line: " ;
  } else if(errorType == METHOD_REDECLARATION_ERROR){
    errorStr = "Method redeclaration error at line: " ;
  }

  std::cout << errorStr << lineNumber << std::endl ;
}
