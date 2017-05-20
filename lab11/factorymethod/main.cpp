//
// Created by kubas1129 on 18.05.17.
//
#include<iostream>
#include <vector>
#include "FactoryMethod.h"

using namespace factoryMethod;

int main()
{

    std::cout<<Sum<int>(4.3, 4) << std::endl;

    const std::vector<int> &vector = {1, 3, 4};
    std::cout << Mean<double>(vector) << std::endl;

    int liczba=12;
    int *pointer = &liczba;

    std::cout << GetFromPointer(pointer);

    return 0;
}
