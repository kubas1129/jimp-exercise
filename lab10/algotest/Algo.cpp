//
// Created by kubas1129 on 11.05.17.
//

#include <map>
#include <set>
#include "Algo.h"

namespace algo{

    void CopyInto(std::vector<int> arg, int elements, std::vector<int> *buffer) {
        std::copy_n(arg.begin(), elements, std::back_inserter(*buffer));
    }

    bool Contains(std::vector<int> arg, int element) {
        auto result = std::find(arg.begin(), arg.end(), element);
        if(result != arg.end()) return true;
        else return false;
    }

    void InitializeWith(int value, std::vector<int> *arg) {
        std::fill(arg->begin(), arg->end(), value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int value) {
        std::vector<int> arg;
        std::fill_n(std::back_inserter(arg), length, value);
        return arg;
    }

    std::vector<std::string> MapToString(std::vector<double> v) {
        std::vector<std::string> arg;
        std::transform(v.begin(), v.end(), std::back_inserter(arg), [](double i){return std::to_string(i);});
        return arg;
    }

    bool ContainsKey(std::map<std::string, int> arg, std::string value) {
        if(arg.find(value) != arg.end()) return true;
        else return false;
    }

    std::set<std::string> Keys(std::map<std::string,int> arg) {
        std::set<std::string> key;

        

        return key;
    }

    std::vector<int> Values(std::set<std::string> keys) {
        std::vector<int> key;

        //key.emplace_back(keys.value_comp());

        return key;
    }

    bool ContainsValue(std::map<std::string, int> arg, int value) {
        for(auto &v : arg) {
            if(v.second == value) return true;
        }
        return false;
    }
}