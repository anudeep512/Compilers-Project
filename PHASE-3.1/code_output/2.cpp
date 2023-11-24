#include <bits/stdc++.h>
#include "matplotlibcpp.h"

using namespace std;


Timer get;
     
int factorial(int b ) 
{
    int res =  1,  i; 
   
    for (( i =  1 ) ; (i<=  b ); ( i +=  1)  )
    {
         res*=  i; 
    }

    return  res;  
}


      
int add(int a , int b )
{
    int c =  (a +  b); 
    return  c;
}

      
int add(float a , int b )
{
    float c =  (a +  b);  // RHS error
    return  c;
}

// function overloading
      
float add(float a , float b )
{
    float c =  (a +  b); 
    {
        int x =  (a -  b); 
         c=  (x +  2* b);  // should update the c value in this scope, is it updating?
    }
    return  c;
}

  
void parallelFact (int tid ) 
{
    int thr =  tid ; 
     factorial(thr) ;
}


int main()  { 
    int n =  (a* b* c* d* e +  1); 
    int num[ n] ; 

    for ( int i =  0 ; (i <  n) ; i +=  1) {
        num[ i]  =  i ; 
    }

    int thr =  5,   runs=  4;  

         
	for(int i = 0; i < runs; i++) {
		get.begin();
		thread threads[thr];

	for(int i = 0; i < thr; i++) {
		threads[i] = thread(parallelFact, i+1 , add(a, b) );
	}
	for(int i = 0; i < thr; i++) {
		threads[i].join();
	}
		get.stop();
	}
	double t = get.time()/runs;
 

    int res1 =   add(  add( 10.100000,  2.100000) ,  num[1]) ; 

    float res2 =   add( 10.300000,  2.300000) ;  // function overloading

	return 0;

}
