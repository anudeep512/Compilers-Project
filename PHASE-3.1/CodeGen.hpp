#include <bits/stdc++.h>

std::string changer(std::string variable)
{
    std::map<std::string, std::string> map;
    std::string ans;

    map["int"] = "number";
    map["char"] = "letter";
    map["float"] = "decimal";
    map["string"] = "text";

    if (map.find(variable) != map.end())
    {
        ans = map[variable];
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

    return output;
}