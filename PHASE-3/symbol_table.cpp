#include <bits/stdc++.h>
#include "symbol_table.hpp"
using namespace std;

template <class T>
bool search_identifier(T curr_ptr, string id)
{
  for (auto i : curr_ptr.i_tb.i_struct)
  {
    if (i.id_name == id)
      return true;
  }
  if (curr_ptr.p_tb == NULL)
    return false;
  else
    return search_identifier(*(curr_ptr.p_tb), id);
}

template <class T>
bool search_func_identifier(T global_ptr, vector<string> &func_check)
{
  string func_name = func_check[0];

  for (auto i : global_ptr.f_tb)
  {
    if (i.id_name == func_name)
    {
      if((func_check.size()-1) != i.num_param){
         return false;
      } 
      
      int a = 1;
      

      for (auto j : i.i_tb.i_struct)
      {
        if (j.datatype != func_check[a])
        {
          return false;
        }
        
        else{
           a++;
           
           if(a> i.num_param){
              return true;
           }
           
        }
      }
    }
  }
  return false;
}

template <class T>
bool search_task_identifier(T global_ptr, vector<string> &task_check)
{

  string task_name = task_check[0];

  for (auto i : global_ptr.t_tb)
  {
    if (i.id_name == task_name)
    {
      if((task_check.size()-1) != i.num_param){
         return false;
      } 
      
      int a = 1;

      for (auto j : i.i_tb.i_struct)
      {

        if (j.datatype != task_check[a])
        {
          return false;
        }
        else
        {
          a++;
          if (a > i.num_param)
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}

/*
  Semantics required for class function:
    -  Check if a class with given name exists
    -  Whenever an attribute is accessed, check if there is an attribute with that identifier
    -  Whenever a class method is accessed, search of there is a function with that name and those parameters
*/
template <class T>
bool seach_type_idenitifer(T g_ptr, string id)
{
  for (auto i : g_ptr.c_tb)
  {
    if (i.type_name == id)
      return true;
  }

  return false;
}

template <class T>
bool search_attribute(T g_ptr, string attr_name, string class_name)
{
  for (auto i : g_ptr.c_tb)
  {
    if (i.type_name == class_name)
    {
      for (auto j : i.i_tb.i_struct)
      {
        if (j.id_name == attr_name)
          return true;
      }
      return false;
    }
  }

  return false;
}

template <class T>
bool search_method(T global_ptr, string class_name, vector<string> &method_check)
{
  string method = method_check[0];

  for (auto k : global_ptr.c_tb)
  {
    if (k.type_name == class_name)
    {
      for (auto i : k.f_tb)
      {
        if (i.id_name == method)
        {
           if(method_check.size() - 1 != i.num_param)
           {
           	break;
           }
           
          int a = 1;

          for (auto j : i.i_tb.i_struct)
          {

            if (j.datatype != method_check[a])
            {
              return false;
            }
            else
            {
              a++;
              if (a > i.num_param)
              {
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}


template <class T>
bool search_NCL_identifers()
