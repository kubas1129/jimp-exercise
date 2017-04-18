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

        Matrix(unsigned long rows, unsigned long columns);

        Matrix(std::initializer_list<std::vector<std::complex<double>>> init);

        //Usable methods
        std::pair<unsigned long, unsigned long> Size() const;

        std::string Print() const;

        std::vector<std::complex<double>> CreateColumnForRow(unsigned long rows) const;

        std::complex<double> CountMultiply(int i, int j, const std::vector<std::vector<std::complex<double>>> &value1, const std::vector<std::vector<std::complex<double>>> &value2,
                                           unsigned long iter) const;

        //Math Method
        Matrix Add(const Matrix &matrix) const;

        Matrix Mul(const Matrix &matrix) const;

        Matrix Sub(const Matrix &matrix) const;

        Matrix Pow(int power);

        ~Matrix();

    private:
        std::vector<std::vector<std::complex<double>>> values_;
        std::pair<unsigned long, unsigned long> size_; //first=rows, second=columns
    };

}
#endif //JIMP_EXERCISES_MATRIX_H
