//
// Created by kubas1129 on 11.03.17.
//

#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <string>
#include <map>
#include <sstream>
#include <iostream>

std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);
std::map<char,int> MakeCryptTable();
void PrintMap(const std::map<char,int> &v);


#endif //JIMP_EXERCISES_POLYBIUS_H
