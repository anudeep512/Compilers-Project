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


template <class T>
bool search_func_identifier(T global_ptr, vector<string>& func_check ){
   string func_name = func_check[0];
   
   for(auto i: global_ptr.f_tb){
      if(i.id_name == func_name){
         int a = 1;
         
         for(auto j: global_ptr.f_tb.i_tb.i_struct){
            if( j.datatype == func_check[a]){
               a++;
            }
            
            else if(a > global_ptr.f_tb.num_param){
               break;
            }
            
            else{return false}
         }
      }
   }
   return false;
   
}
