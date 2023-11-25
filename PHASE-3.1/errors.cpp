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
  } else if(errorType == NOT_AN_ARRAY){
    errorStr = "Variable not an array error at line: " ;
  } else if(errorType == CANNOT_USE_TID){
    errorStr = "TID cannot be used in the current scope at line: " ;
  } else if(errorType == MODULO_ASSIGNMENT_ERROR){
    errorStr = "Modulo assignment type error at line: " ;
  } else if(errorType == ARRAY_CANNOT_HAVE_NON_INTEGERS){
    errorStr = "Arrays cannot have non number datatypes inside indexing at line: " ;
  } else if(errorType == MAKE_PARALLEL_ERROR){
    errorStr = "Make parallel accepts only type numbers in first two arguments for calling at line: " ;
  }else if(errorType == ARRAY_CANNOT_BE_ACCESSED_USING_ARROW){
    errorStr = "Arrays cannot be accessed using arrow operator at line: " ;
  } else if(errorType == INVALID_USE_OF_RETURN){
    errorStr = "Invalid use of return at line: " ;
  } else if(errorType == FUNCTION_MUST_HAVE_1_RETURN){
    errorStr = "The Function must have atleast one return statement, error at line: " ;
  } else if(errorType == USER_DEFINED_ARRAY_ERROR){
    errorStr = "Cannot create atomic user defined arrays, error at line: " ;
  } else if(errorType == THE_ARRAY_SHOULD_BE_ACCESSED_FULLY){
    errorStr = "The array should be accessed fully, error at line: " ;
  }else if(errorType == INCOMPITABLE_ARRAY_DIMS){
    errorStr = "The array Level uncompitable for returnFretur, error at line: " ;
  } else if(errorType == NOT_STRING){
    errorStr = "Not string passed to input/ output, error at line: " ;
  }  

  std::cout << errorStr << lineNumber << std::endl ;
}
