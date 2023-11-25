#ifndef _CODEGEN_HPP
#define _CODEGEN_HPP

#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

class Timer{
    public:
        high_resolution_clock::time_point start, end;
        double t;
        void begin(){
            start = high_resolution_clock::now();
        }
        void stop(){
            end = high_resolution_clock::now();
            t += duration_cast<microseconds>(end - start).count();
        }
        double time(){
            double tmp =  t;
            t = 0;
            return tmp;
        }     
};


std::string changer(char *variable);
std::string FuncDeclGen(std::vector<std::string> &input);

#endif