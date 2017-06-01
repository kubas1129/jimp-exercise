//
// Created by kubas1129 on 30.05.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <unordered_map>

namespace profiling{




    template <class F>
     auto TimeRecorder(F foo){
        auto start = std::chrono::high_resolution_clock::now();
        foo();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        return std::make_pair<decltype(foo()), double>(foo(), elapsed.count());
    };

}


#endif //JIMP_EXERCISES_TIMERECORDER_H
