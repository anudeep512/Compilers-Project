#include "codegen.hpp"
#include <iostream>
using namespace std ;

// void drawGraph(string xlabel, string ylabel, double x[], double y1[])
// {
//     plt::figure_size(1200, 780); // Set this size once
//     plt::plot(x,y1);
//     // plt::plot(x,y2);
//     plt::xlabel(xlabel);
//     plt::ylabel(ylabel);
//     plt::title("Graph");
//     plt::show();
// }

void Timer::start(){
    this->st = high_resolution_clock::now();
}

void Timer::stop(){
    this->end = high_resolution_clock::now();
    this->t += duration_cast<microseconds>(this->end - this->st).count();
}

double Timer::time(){
    double tmp =  this->t;
    this->t = 0;
    return tmp;
}     

string changer(char *variable)
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
