//
// Created by kubas1129 on 03.04.17.
//
#include <iostream>
#include <sstream>
#include "Matrix.h"


namespace algebra{


    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> init) {

        size_.first = init.size();                                                  //rows
        size_.second = init.begin()->size();                                        //columns

        values_ = new std::complex<double>*[size_.first];

        for(int i =0; i < size_.first;i++){
            values_[i] = new std::complex<double>[size_.second];
            for(int j = 0;j < size_.second;j++){
                values_[i][j] = init.begin()[i][j];
            }
        }




    }

    Matrix::Matrix(const char *tab) {

    }

    std::pair<unsigned long, unsigned long> Matrix::Size() const {
        return size_;
    }

    std::string Matrix::Print() const {

        std::string str_out = "";

        str_out += "[";
        for(int i =0; i < size_.first;i++){
            for(int j = 0;j < size_.second;j++){
                std::ostringstream real, imaginary;
                real << values_[i][j].real();
                imaginary << values_[i][j].imag();
                str_out += real.str() + "i" + imaginary.str();
                if(j < size_.second-1) str_out += ", ";

            }
            if(i < size_.first-1) str_out += "; ";
        }
        str_out += "]";
        return str_out;
    }

    Matrix Matrix::Add(const Matrix &matrix) const{
        return Matrix();
    }


    Matrix Matrix::Mul(const Matrix &matrix)  const {
        return Matrix();
    }

    Matrix::~Matrix() {
       if(values_ != nullptr){
           if(size_.first > 0 && size_.second > 0) {
               for (int i = 0; i < size_.first; i++) {
                   delete[] values_[i];
               }
               delete[] values_;
           }
        }
    }


}