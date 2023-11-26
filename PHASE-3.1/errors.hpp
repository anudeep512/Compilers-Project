#ifndef _ERRORS_HPP_
#define _ERRORS_HPP_

#include "semantics.hpp"
#include "symbol_table.hpp"

#define VARIABLE_REDECLARATION_ERROR 1
#define VARIABLE_NOT_FOUND 2
#define TYPE_NOT_FOUND 3
#define FUNCTION_NOT_FOUND 4
#define METHOD_NOT_FOUND 5
#define TYPE_ATTR_NOT_FOUND 6
#define TYPE_ERROR_RHS 7

#define TYPE_ERROR_RHS_LHS 8
#define LEVEL_ERROR 9 // Need to look into this might be handled in RHS error
#define PREDICATE_ERROR 10 // Occurs when the perdicate evaluates to String 
#define TASK_NOT_FOUND 12
#define FUNCTION_REDECLARATION_ERROR 13
#define RETURN_TYPE_ERROR 14
#define IN_SCOPE_ERROR 15 
#define TYPE_REDECLARATION 16
#define TASK_REDECLARATION_ERROR 17
#define TYPE_ATTR_REDECLARATION 18
#define START_ERROR_LESS 19
#define START_ERROR_MORE 20
#define METHOD_REDECLARATION_ERROR 21
#define NOT_AN_ARRAY 22
#define CANNOT_USE_TID 23
#define MODULO_ASSIGNMENT_ERROR 24
#define ARRAY_CANNOT_HAVE_NON_INTEGERS 25
#define MAKE_PARALLEL_ERROR 26
#define ARRAY_CANNOT_BE_ACCESSED_USING_ARROW 27
#define INVALID_USE_OF_RETURN 28
#define FUNCTION_MUST_HAVE_1_RETURN 29
#define USER_DEFINED_ARRAY_ERROR 30
#define THE_ARRAY_SHOULD_BE_ACCESSED_FULLY 31
#define INCOMPITABLE_ARRAY_DIMS 32
#define NOT_STRING 33
#define ARRAY_SHOULD_BE_ARGUMENT 34
/*
  start error -> > 1 starts or 0 start
*/
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
