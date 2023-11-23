#ifndef _SEMANTICS_HPP_
#define _SEMANTICS_HPP_

#include "errors.hpp"
#include "symbol_table.hpp"
using namespace std ;
string is_coercible_rhs(string dt1, string dt2, string op);
bool assignment_check(string dt1, string dt2);
bool compatibility(string dt1, string dt2);
vector<string> to_string_vec(vector<char*> vec) ;
#endif

