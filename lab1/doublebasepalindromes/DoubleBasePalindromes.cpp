//
// Created by kubas1129 on 06.03.17.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    if(max_vaule_exculsive <= 0) return 0;
    uint64_t palindromSum = 0;
    for(long long int i = max_vaule_exculsive; i >0;i--)
    {
        std::string decStr = std::to_string(i);
        if(is_DPalindrome(decStr))
        {
            std::string binStr = toBinary(i);
            if(is_DPalindrome(binStr))
            {
                palindromSum += i;
            }
        }
    }
    return palindromSum;
}

bool is_DPalindrome(std::string str)
{
    std::string reversedStr = reverseDPalindrom(str);

    if(str == reversedStr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string reverseDPalindrom(std::string str)
{
    const char *character = str.c_str();
    std::string tempStr;

    if(str.length() > 1)
    {
        char last = str[str.length()-1];
        tempStr += last;
        if(*character != '\0')
        {
            tempStr += reverseDPalindrom(str.substr(0, str.length()-1));
        }
    }
    else
    {
        tempStr = str;
    }
    return  tempStr;
}

std::string toBinary(int value)
{
    std::string str = "";
    while(value != 0)
    {
        str += value%2 == 0? "0":"1";
        value /= 2;
    }
    return str;
}