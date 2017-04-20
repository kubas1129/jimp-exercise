//
// Created by kubas1129 on 20.04.17.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H


#include <cstdio>
#include <vector>
#include <memory>
#include <random>
using ::std::default_random_engine;
using ::std::uniform_int_distribution;
using ::std::make_unique;

namespace arrays {



    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill : public ArrayFill{
    public:
        IncrementalFill(int value = 0, int step=1) : value_{value}, step_(step) {}
        virtual int Value(int index) const override;
    private:
        int value_;
        int step_;
    };

    class RandomFill : public ArrayFill{
    public:
        RandomFill(std::unique_ptr<default_random_engine> generator, std::unique_ptr<uniform_int_distribution<int>> dist) {
            generator_ = move(generator);
            distribution_ = move(dist);
        }
        virtual int Value(int index) const override;
    private:
        std::unique_ptr<default_random_engine> generator_;
        std::unique_ptr<uniform_int_distribution<int>> distribution_;
    };

    class SquaredFill : public ArrayFill {
    public:
        SquaredFill(int a=1, int b=0) : a_{a}, b_{b} {}
        virtual int Value(int index) const override;
    private:
        int a_,b_;
    };


    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);


}
#endif //JIMP_EXERCISES_ARRAYFILL_H
