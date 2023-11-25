#ifndef _SEMANTICS_HPP_
#define _SEMANTICS_HPP_

#include "errors.hpp"
#include "symbol_table.hpp"
using namespace std ;
string is_coercible_rhs(string dt1, string dt2, string op);
bool assignment(string dt1 , string dt2, int flag);
bool compatibility(string dt1, string dt2);
vector<string> to_string_vec(vector<char*> vec) ;
char* cstr(string str) ;
void printArgs(vector<string> datatypes, vector<int> array, vector<int> atomic);
bool compatibility_calls(vector<string> arg1, vector<string> arg2);
#endif

