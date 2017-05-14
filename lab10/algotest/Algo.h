//
// Created by kubas1129 on 11.05.17.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <vector>
#include <algorithm>

namespace algo {

    void CopyInto(std::vector<int> arg, int elements, std::vector<int>* buffer);

    bool Contains(std::vector<int> arg, int element);

    void InitializeWith(int value, std::vector<int> *arg);

    std::vector<int> InitializedVectorOfLength(int length, int value);

    std::vector<std::string> MapToString(std::vector<double> v);

    bool ContainsKey(std::map<std::string, int> arg, std::string value);

    std::set<std::string> Keys(std::set<std::string> keys);

    std::vector<int> Values(std::set<std::string> keys);

    bool ContainsValue(std::map<std::string, int> arg, int value);

}
#endif //JIMP_EXERCISES_ALGO_H
