//
// Created by kubas1129 on 05.03.17.
//

#include <iostream>
#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10])
{
    for(int i = 0; i < 10;i++)
    {
        for(int k = 0;k < 10;k++)
        {
            tab[i][k] = (i+1) * (k+1);
        }
    }
}

void ShowTable(int tab[][10])
{
    for(int i = 0; i < 10;i++)
    {
        for(int k = 0;k < 10;k++)
        {
            std::cout << (tab[i][k] < 10? " ":"") << tab[i][k] << " | ";
        }
        std::cout << std::endl;
    }
}
