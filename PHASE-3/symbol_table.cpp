#include <bits/stdc++.h>
#include "symbol_table.hpp"
using namespace std;

template <class T>
bool search_identifier(T curr_ptr, string id){
  for(auto i: curr_ptr.i_tb.i_struct){
    if(i.id_name == id) return true ;
  }
  if(curr_ptr.p_tb == NULL) return false;
  else return search_identifier(*(curr_ptr.p_tb),id); 
}


