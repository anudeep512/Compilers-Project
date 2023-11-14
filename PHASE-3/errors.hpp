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
#define PREDICATE_ERROR 10 // Occurs when the perdicate evaluates to String 
#define NUMBER_OF_PARAM_MISMATCH 11
#define TASK_NOT_FOUND 12
#define REDECLARATION_OF_FUNCTION 13
#define RETURN_TYPE_ERROR 14
#define IN_SCOPE_ERROR 15 
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

void printError(int lineNumber, int errorType);

#endif
