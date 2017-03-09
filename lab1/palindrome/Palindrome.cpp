//
// Created by kubas1129 on 05.03.17.
//

#include "Palindrome.h"

bool IsPalindrome(std::string str)
{
    str = ToLower(str);
    std::string reverse_str = reverse(str);

    if(str == reverse_str)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string ToLower(std::string str)
{
    for(int i = 0; i < str.length();i++)
    {
        if(str[i] >= 65 && str[i] <= 90) str[i] += 32;
    }
    return  str;
}




