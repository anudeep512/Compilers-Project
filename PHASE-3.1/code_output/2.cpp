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

      
int add(float a , int b[] )
{
    float d =  (a +  b);  // RHS error
    return  d;
}

// function overloading
       
float add(float a[] , float b )
{
	mtx[mut].lock();

    float c =  (a +  b); 
    {
        int x =  (a -  b); 
         c=  (x +  2* b);  // should update the c value in this scope, is it updating?
    }
    mtx[mut].unlock();
	mut++;
return  c;
}

void  parallelFact(int tid,  )
{
    int thr =  tid ; 
     factorial(thr) ;
}
int hi; 


int main()  { 
    int n =  (a* b* c* d* e +  1); 
     num[ n] ; 

    for ( int i =  0 ; (i <  n) ; i +=  1) {
        num[ i]  =  i ; 
    }

      5  2  Timer get;
for(int i=0;i<:;i++){
	get.begin();
	thread threads[:];
	for(int j=0;j<:;j++){
		threads[j] = thread(j2, 3);
	}
	for(int j=0;i<:;j++)
	{
		threads[j].join();
	}
	get.stop();
}
double t = (get.time()/:);
 

    int res1 =   add( 10,  num[1]) ; 

    float res2 =   add( 10.300000,  2.300000) ;  // function overloading
    drawGraph( "a",b,x,y) ; 

	return 0;

}
 