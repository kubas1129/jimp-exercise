//
// Created by kubas1129 on 06.03.17.
//

#include "DoubleBasePalindromes.h"

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    if(max_vaule_exculsive <= 0) return 0;
    uint64_t palindrom_sum = 0;
    for(uint64_t i = max_vaule_exculsive; i >0;i--)
    {
        std::string dec_str = std::to_string(i);
        if(IsPalindrome(dec_str))
        {
            std::string bin_str = ReverseToBinary(i);
            if(IsPalindrome(bin_str))
            {
                palindrom_sum += i;
            }
        }
    }
    return palindrom_sum;
}

std::string ReverseToBinary(int value)
{
    std::string str;
    while(value != 0)
    {
        str += value%2 == 0? "0":"1";
        value /= 2;
    }
    return reverse(str);
}