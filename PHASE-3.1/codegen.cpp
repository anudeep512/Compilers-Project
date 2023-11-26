#include <map>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include "codegen.hpp"
#include "codegen.hpp">
#include "matplotlibcpp.h" 
#include <chrono>


using namespace std;
using namespace chrono;

namespace plt = matplotlibcpp;
void drawGraph(string xlabel, string ylabel, double *x, double *y)
{
    int xx = sizeof(x)/sizeof(x[0]);
    int yy = sizeof(y)/sizeof(y[0]);
    vector<double> X ;
    for(int i = 0;i<xx;i++){
        X.push_back(x[i]);
    }
    vector<double> Y ;
    for(int i = 0; i < yy  ;i++){
        Y.push_back(y[i]);
    }

    plt::figure_size(1200, 780); // Set this size once
    plt::plot(X,Y);
    // plt::plot(x,y2);
    plt::xlabel(xlabel);
    plt::ylabel(ylabel);
    plt::title("Graph");
    plt::show();
}


std::string changer(char *variable)
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

    return std::string(ans);
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