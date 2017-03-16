//
// Created by kubas1129 on 14.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary);
vector<char> RandomKey(int length);

bool FoundInDictionary(const std::vector<string> &dictionary, string searching);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
