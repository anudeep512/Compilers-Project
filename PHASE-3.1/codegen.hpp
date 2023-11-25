#ifndef _CODEGEN_HPP
#define _CODEGEN_HPP

#include <iostream>
#include <vector>
#include <string>
// #include "matplotlibcpp.h" 
#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;

// namespace plt = matplotlibcpp;

class Timer {
  public:
    high_resolution_clock::time_point st,end ;
    double t ;
    void start();
    void stop();
    double time();
};


void drawGraph(string xlabel, string ylabel, double *x, double *y1);
string changer(char *variable);
string FuncDeclGen(std::vector<std::string> &input);

#endif
