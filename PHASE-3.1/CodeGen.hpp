#include <bits/stdc++.h>

std::string FuncDeclGen(std::vector<std::string> &input)
{
    std::map<std::string, std::string> map;

    map["number"] = "int";
    map["letter"] = "char";
    map["decimal"] = "float";
    map["text"] = "string";

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
                if (map.find(input[i]) != map.end())
                {
                    output = map[input[i + 1]] + " " + output;
                }

                else
                {
                    output = input[i + 1] + " " + output;
                }

                i++;
            }
        }

        else if (input[i] == ",")
        {
            output += ", ";
        }

        else
        {
            if (map.find(input[i]) != map.end())
            {
                output += map[input[i]];
            }

            else
                output += input[i];
            output += " ";
        }
    }

    return output;
}