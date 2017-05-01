//
// Created by kubas1129 on 27.04.17.
//

#include "Pesel.h"
#include<iostream>
using namespace academia;

int main() {
    try{
        Pesel p = Pesel("00000000001");
    }
    catch(std::runtime_error e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}