#include "semantics.hpp"
#include "errors.hpp"
#include "symbol_table.hpp"

void printArgs(vector<string> datatypes, vector<int> array, vector<int> atomic){
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl ;
  cout << "Arguments Passage: " << endl ;
  cout << "Datatypes are: " << endl ;
  for(auto i: datatypes){
    cout << i << " , " ;
  }
  cout << endl ;
  for(auto i: array){
    cout << i << " , " ;
  }
  cout << endl ;
  for(auto i: atomic){
    cout << i << " , " ;
  }
  cout << endl ;
}

// This is required in semantic analysis for typechecking
// We don't have operator overloading 
// We even don't have move operator and = operation
vector<string> to_string_vec(vector<char*> vec)
{
  vector<string> ans;
  for(auto i : vec)
  {
    ans.push_back(string(i));
  }
  return ans;
}

char* cstr(string str) {

  char* cstr = new char[str.length() + 1];
  std::strcpy(cstr, str.c_str());

  return cstr;
}

string is_coercible_rhs(string dt1, string dt2, string op){
  // cout << "is_coercible_rhs: " << dt1 << " "<<dt2 << " " << op << endl ;
  if(op == "#" && (dt1 == "number" || dt1 == "decimal" || dt1 == "letter" || dt1 == "bool" || dt1 == "text") && (dt2 == "number" || dt2 == "decimal" || dt2 == "letter" || dt2 == "bool" || dt2 == "text")){ 
    return "text" ; // Resultant expression is changed to string
  }
  string res = dt1 + dt2 ;
  if(res == "texttext" && (op == ">" || op == "<" || op == "<=" || op == ">=" || op == "==" || op == "!=")){
    // cout << "INNNN THIISSSS" << endl ;
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
  
  return "" ;
}

bool is_primitive(string dt){

  if(dt != "text" && dt != "letter" && dt != "number" && dt != "decimal" && dt != "bool"){
    return false ;
  }
  return true ;
}


// flag = 0 : = 
// flag = 1 : Remaining 
bool assignment(string dt1 , string dt2, int flag){
if(flag == 0){
    if(dt1 == dt2){
      return true ;
    }
    if(dt1 == "text" && dt2 == "text") {
      return true ;
    }
    else if(dt1 != "text" && dt2 != "text" && (dt1 == "number" || dt1 == "decimal" || dt1 == "letter" || dt1 == "bool") && (dt2 == "number" || dt2 == "decimal" || dt2 == "letter" || dt2 == "bool")){
      return true ;
    }
}else {
    if(!is_primitive(dt1)){
      return false;
    }
    if(!is_primitive(dt2)){
      return false ;
    } 
    if(dt1 == "text" || dt2 == "text"){
      return false ;
    }
    if((dt1 ==  "number" || dt1 == "decimal" || dt1 == "letter" || dt1 == "bool") && (dt2 == "number" || dt2 == "decimal" || dt2 == "letter" || dt2 == "bool")){
      return true ;
    }
}
  return false ;
}

// This function can be used to check the relation between two datatypes
bool compatibility(string dt1, string dt2){
  if(dt1 == dt2) return true ;
  if((dt1 == "text" && dt2 != "text") || (dt1 != "text" && dt2 == "text")){
    return false;
  }
  string s1 = dt1 + dt2 ;
  if(s1 == "numberdecimal" || s1 == "decimalnumber"){
    return true ;
  }else if(s1 == "numberbool" || s1 == "boolnumber"){
    return true ;
  }else if(s1 == "numberletter" || s1 == "letternumber"){
    return true ;
  }else if(s1 == "decimalbool" || s1 == "booldecimal"){
    return true ;
  }else if(s1 == "decimalletter" || s1 == "letterdecimal"){
    return true ;
  }else if(s1 == "boolletter" || s1 == "letterbool"){
    return true ;
  }
  return false ;
}

bool compatibility_calls(vector<string> arg1, vector<string> arg2){
  if(arg1.size() != arg2.size()){
    return false ;
  }else {
    bool a = true ;
    for(int i = 0; i < arg1.size(); i++){
      // cout << arg1[i] << " " << arg2[i] << endl  ;
      a = a & compatibility(arg1[i],arg2[i]);
    }
    return a; 
  }
}





