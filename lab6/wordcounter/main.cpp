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
    std::ifstream is("helo");
    WordCounter wc;
    wc.FromInputStream(&is);

    return 0;
}