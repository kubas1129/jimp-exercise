//
// Created by kubas1129 on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <vector>

namespace algebra {


    class Matrix {

    public:
        Matrix() {};

        Matrix(unsigned long m, unsigned long n){
            size_.first = m;
            size_.second = n;
        }

        Matrix(std::initializer_list<std::vector<std::complex<double>>> init);

        Matrix(const char* tab);


        std::pair<unsigned long, unsigned long> Size() const;

        std::string Print() const;

        Matrix Add(const Matrix &matrix) const;

        Matrix Mul(const Matrix &matrix) const;

        ~Matrix();

    private:
        std::complex<double> **values_;
        std::pair<unsigned long, unsigned long> size_; //first=rows, second=columns


    };

}
#endif //JIMP_EXERCISES_MATRIX_H
