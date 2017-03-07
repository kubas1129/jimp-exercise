//
// Created by kubas1129 on 05.03.17.
//

#include "Palindrome.h"

bool is_palindrome(std::string str)
{
    str = toLower(str);
    std::string reversedStr = reversePalindrom(str);

    if(str == reversedStr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string toLower(std::string str)
{
    for(int i = 0; i < str.length();i++)
    {
        if(str[i] >= 65 && str[i] <= 90) str[i] += 32;
    }
    return  str;
}

std::string reversePalindrom(std::string str)
{
    const char *character = str.c_str();
    std::string tempStr;

    if(str.length() > 1)
    {
        char last = str[str.length()-1];
        tempStr += last;
        if(*character != '\0')
        {
            tempStr += reversePalindrom(str.substr(0, str.length()-1));
        }
    }
    else
    {
        tempStr = str;
    }
    return  tempStr;
}




