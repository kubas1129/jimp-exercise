//
// Created by kubas1129 on 13.03.17.
//

#include "GreatestProduct.h"


int GreatestProduct(const std::vector<int> &numbers, int k)
{

    int value_1=0, value_2=0;

    for(int v : numbers)
    {
        if(value_1 > value_2)
        {
            int temp = value_1;
            value_1 = value_2;
            value_2 = temp;
        }
        if(v > value_1) value_1 = v;
    }
    std::cout << "zmienna1: " << value_1 << ", zmienna2: " << value_2 << std::endl;
    return value_1 * value_2;
}

