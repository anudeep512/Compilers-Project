#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <fstream>
#include <sstream>
#include <usleep>
#include <time>
#include "matplotlibcpp.h"

using namespace std;


 mutex mtx[100000];
int mut = 0;
atomic <> counter =  0;  // global int

class myType 
{
public:
     count;  
     data[ 100] ;  

            
	void printMsg( msg ,  c )
    { 
        if ( ( c==  0)) 
        {
             =  c; 
        }
         str =  ("Message from myType: " +  msg+ "\n"); 
        cout <<  str; 
        return  ; 
    }

	myType() = default;
	myType(const myType&) = default;
	myType& operator = (const myType&) = default;
	~myType() = default;
};

    

     i =  0; 
    myType obj ; 
     obj-> printMsg( ("Hello from the main thread"), 100 )