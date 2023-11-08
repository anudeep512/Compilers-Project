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


template <class T>
bool search_task_identifier(T global_ptr, vector<string>& task_check){

   string task_name = task_check[0];
   
   for(auto i: global_ptr.t_tb){
      if(i.id_name == task_name){
         int a = 1;
         
         for(auto j: global_ptr.t_tb.i_tb.i_struct){
            
            if(j.datatype != task_check[a]){
               return false;
            } else {
              a++; 
              if(a > global_ptr.t_tb.num_param){
                  break;
              }
            } 
         }
      }
   }
   return true;
  
}



/*
  Semantics required for class function:
    -  Check if a class with given name exists
    -  Whenever an attribute is accessed, check if there is an attribute with that identifier
    -  Whenever a class method is accessed, search of there is a function with that name and those parameters
*/
template <class T>
bool seach_type_idenitifer(T g_ptr, string id){
  for(auto i: g_ptr.c_tb){
    if(i.type_name == id) return true;
  }

  return false;
}

template <class T>
bool search_attribute(T g_ptr, string attr_name, string class_name)
{
  for(auto i:g_ptr.c_tb){
    if(i.type_name == class_name){
      for(auto j : i.i_tb.i_struct)
      {
        if(j.id_name == attr_name) return true;
      }
      return false;
    }
  }

  return false;
}