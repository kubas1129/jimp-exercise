//
// Created by kubas1129 on 18.05.17.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <numeric>

namespace factoryMethod {


    class MyType{
    public:
        MyType() {}

        std::string SayHello() { return "hello"; }
    };

    template <class T>
    T Create()
    {
        return T{};
    }


    template <class T>
    T Sum(T a, T b)
    {
        return a+b;
    }


    template <class P, class R>
    R GetFromPointer(P ptr)
    {
        return *ptr;
    };


    template<class R, class V>
    R Mean(const V &vector)
    {
        typename V::value_type init {};
        auto value = std::accumulate(vector.begin(), vector.end(), init);

        return value/vector.size();
    };


}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
