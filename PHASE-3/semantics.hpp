#ifndef _SEMANTICS_HPP_
#define _SEMANTICS_HPP_

#include "errors.hpp"
#include "symbol_table.hpp"

bool is_coercible(string dt1, string dt2, string op);
bool assignment_check(string dt1, string dt2);

#endif

