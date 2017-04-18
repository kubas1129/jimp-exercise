//
// Created by kubas1129 on 09.04.17.
//

#include <iostream>
#include <fstream>
#include "WordCounter.h"
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;

int main()
{
    std::ifstream is("/home/kubas1129/helo.txt");
    WordCounter wc;
    wc = wc.FromInputStream(&is);
    wc.Print();


    return 0;
}