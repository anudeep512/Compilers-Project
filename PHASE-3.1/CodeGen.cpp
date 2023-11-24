#include <map>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include "CodeGen.hpp"
// #include "matplotlibcpp.h" 
#include <chrono>


using namespace std;
using namespace chrono;

// namespace plt = matplotlibcpp;
// void drawGraph(string xlabel, string ylabel, double *x, double *y1)
// {
//     plt::figure_size(1200, 780); // Set this size once
//     plt::plot(x,y1);
//     // plt::plot(x,y2);
//     plt::xlabel(xlabel);
//     plt::ylabel(ylabel);
//     plt::title("Graph");
//     plt::show();
// }

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

char *changer(char *variable)
{
    std::map<std::string, std::string> map;
    char *ans;

    map["int"] = "number";
    map["char"] = "letter";
    map["float"] = "decimal";
    map["string"] = "text";

    map["number"] = "int";
    map["letter"] = "char";
    map["text"] = "string";
    map["decimal"] = "float";

    if (map.find(std::string(variable)) != map.end())
    {
        ans = &map[variable][0];
    }

    else
    {
        ans = variable;
    }

    return ans;
}



std::string FuncDeclGen(std::vector<std::string> &input)
{
    std::string output = "";
    bool colon = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == "func")
        {
            output += input[i + 1];
            i += 1;
        }

        else if (input[i] == ":")
        {
            if (colon == 0)
            {
                output += "(";
                colon = 1;
            }

            else if (colon == 1)
            {
                output += ")";
                output = input[i + 1] + " " + output;

                i++;
            }
        }

        else if (input[i] == ",")
        {
            output += ", ";
        }

        else
        {
            output += input[i];
            output += " ";
        }
    }

    return output ;
}