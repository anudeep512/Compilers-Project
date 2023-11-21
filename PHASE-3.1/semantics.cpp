#include "semantics.hpp"
#include "errors.hpp"
#include "symbol_table.hpp"

// This is required in semantic analysis for typechecking
// We don't have operator overloading 
// We even don't have move operator and = operation
std::vector<std::string>

to_string_vec(std::vector<char*> vec)
{
   std::vector<std::vector> ans;
   
   for(auto i : vec)
   {
      ans.push_back(std::string(i));
   }
   
   return ans;
}
s

string is_coercible_rhs(string dt1, string dt2, string op){
  if(op == "#" && (dt1 == "number" || dt1 == "decimal" || dt1 == "letter" || dt1 == "bool" || dt1 == "text") && (dt2 == "number" || dt2 == "decimal" || dt2 == "letter" || dt2 == "bool" || dt2 == "text")){ 
    return "text" ; // Resultant expression is changed to string
  }
  string res = dt1 + dt2 ;
  if(dt1 == "texttext" && (op == ">" || op == "<" || op == "<=" || op == ">=" || op == "==" || op == "!=")){
    return "bool" ;
  }else if(res == "numbernumber" && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%")){
    return "number";
  }else if(res == "numbernumber" && (op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" )){
    return "bool" ;
  }else if(res == "decimaldecimal" && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^")){
    return "decimal";
  }else if(res == "decimaldecimal" && (op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" )){
    return "bool" ;
  }else if(res == "boolbool" && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%")){
    return "number";
  }else if(res == "boolbool" && (op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" )){
    return "bool";
  }else if(res == "letterletter" && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%")){
    return "number";
  }else if(res == "letterletter" && (op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" )){
    return "bool";
  }
  else if((res == "numberbool" || res == "boolnumber") && (op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%")){
    return "number" ;
  }
  else if((res == "numberbool" || res == "boolnumber")&&(op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" )){
    return "bool";
  }
  else if((res == "numberdecimal")||(res == "decimalnumber") && ((op == "/" || op == "*" || op == "+" || op == "-" || op == "^"))){
    return "decimal";
  }
  else if((res=="numberdecimal"||res=="decimalnumber") && ((op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" ))){
    return "bool" ;
  }
  else if((res == "numberletter")||(res == "letternumber") && ((op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%"))){
    return "number";
  }
  else if((res=="numberletter"||res=="letternumber") && ((op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" ))){
    return "bool" ;
  }
  else if((res == "booldecimal")||(res == "decimalbool") && ((op == "/" || op == "*" || op == "+" || op == "-" || op == "^"))){
    return "decimal";
  }
  else if((res=="booldecimal"||res=="decimalbool") && ((op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" ))){
    return "bool" ;
  }
  else if((res == "boolletter")||(res == "letterbool") && ((op == "/" || op == "*" || op == "+" || op == "-" || op == "^" || op == "%"))){
    return "number";
  }
  else if((res=="boolletter"||res=="letterbool") && ((op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" ))){
    return "bool" ;
  }
  else if((res == "decimalletter")||(res == "letterdecimal") && ((op == "/" || op == "*" || op == "+" || op == "-" || op == "^"))){
    return "decimal";
  }
  else if((res=="decimalletter"||res=="letterdecimal") && ((op =="&&" || op == "||" || op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=" ))){
    return "bool" ;
  }
  
  return "wrong" ;
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

// given 2 datatypes we get output as the resultant datatype of conversion
// i.e., for type checking 
string is_coercible_simple(string dt1, string dt2){

}






