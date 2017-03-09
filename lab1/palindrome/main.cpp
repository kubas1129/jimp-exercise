//
// Created by kubas1129 on 05.03.17.
//

#include "Palindrome.h"

int main()
{
    for(;;)
    {
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "1. Sprawdz Palindrom" << std:: endl;
        char choosed;
        std::cin >> choosed;
        switch (choosed)
        {
            case '0': return 0;
            case '1': std::cout << "Sprawdz"; break;
            default: return 1;
        }
        std::string text;
        std::cout << "Podaj wyraz: ";
        std::cin >> text;
        std::cout << std::endl;
        std::cout << "Wyraz " << text << (IsPalindrome(text)? " jest palindromem.":" nie jest palindromem.") << std::endl;
    }
}