#include "semantics.hpp"
#include "errors.hpp"
#include "symbol_table.hpp"

// This is required in semantic analysis for typechecking
// We don't have operator overloading 
// We even don't have move operator and = operation
bool is_coercible(string dt1, string dt2, string op){
  if(op == "#") return true ; // Resultant expression is changed to string
  if(dt1 == "text" && dt2 =="text" && (op == ">" || op == "<" || op == "<=" || op == ">=" || op == "==" || op == "!=")){
    return true ;
  }
  else if(dt1 != "text" && dt2 != "text" && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op =="&&" || op == "||" || op == ">" || op == "<" || op == "<=" || op == ">=" || op == "==" || op == "!=")){
    return true ;
  }
  else if(dt1 == "number" && dt2 == "number" && op == "%"){
    return true ;
  }
  return false ;
}

bool assignment_check(string dt1 , string dt2){
  if(dt1 == "text" && dt2 == "text") {
    return true ;
  }
  else if(dt1 != "text" && dt2 != "text" && (dt1 == "number" || dt1 == "decimal" || dt1 == "letter" || dt1 == "bool") && (dt2 == "number" || dt2 == "decimal" || dt2 == "letter" || dt2 == "bool")){
    return true ;
  }

  return false ;
}

