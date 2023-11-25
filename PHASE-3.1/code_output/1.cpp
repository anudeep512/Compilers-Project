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
class pt
{
public:
    float x,  y; 
	pt() = default;
	pt(const pt&) = default;
	pt& operator = (const pt&) = default;
	~pt() = default;
};

       
float dist(pt ab , pt b ) 
{
    float d =  ((ab-> x