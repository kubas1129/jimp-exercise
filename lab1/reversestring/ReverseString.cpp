//
// Created by kubas1129 on 05.03.17.
//

#include "ReverseString.h"

std::string reverse(std::string str)
{
    const char *character = str.c_str();
    std::string tempStr;

    if(str.length() > 1)
    {
        char last = str[str.length()-1];
        tempStr += last;
        if(*character != '\0')
        {
            tempStr += reverse(str.substr(0, str.length()-1));
        }
    }
    else
    {
        tempStr = str;
    }
    return  tempStr;
}