//
// Created by kubas1129 on 03.04.17.
//
#include <iostream>
#include <sstream>
#include "Matrix.h"


namespace algebra{

    /////////////////////////////////CONSTRUCTORS///////////////////////////////////////

    Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> init) {

        this->size_.first = init.size();                                                  //rows
        this->size_.second = init.begin()->size();                                        //columns

        for(const auto v : init)
        {
            this->values_.push_back(v);
        }
    }


    Matrix::Matrix(unsigned long rows, unsigned long columns) {
        this->size_.first = rows;                                                  //rows
        this->size_.second = columns;
    }




    ////////////////////////////// USABLE MEHTODS ////////////////////////////////////////////

    std::pair<unsigned long, unsigned long> Matrix::Size() const {
        return this->size_;
    }

    std::string Matrix::Print() const {


        std::string str_out = "";

        str_out += "[";
        for (int i = 0; i < this->size_.first; i++) {
            for (int j = 0; j < this->size_.second; j++) {
                std::ostringstream real, imaginary;
                real << this->values_[i][j].real();
                imaginary << this->values_[i][j].imag();
                str_out += real.str() + "i" + imaginary.str();
                if (j < this->size_.second - 1) str_out += ", ";

            }
            if (i < this->size_.first - 1) str_out += "; ";
        }
        str_out += "]";
        return str_out;
    }


    std::vector<std::complex<double>> Matrix::CreateColumnForRow(unsigned long rows) const{
        std::vector<std::complex<double>> cols;

        for(int i = 0; i < rows;i++)
        {
            cols.push_back(std::complex<double>(0.,0.));
        }
        return cols;
    }


    std::complex<double> Matrix::CountMultiply(int i, int j, const std::vector<std::vector<std::complex<double>>> &value1,
                                               const std::vector<std::vector<std::complex<double>>> &value2, unsigned long iter) const {

        std::complex<double> value;

        for(int k = 0; k < iter;k++)
        {
            value += value1[i][k] * value2[k][j];
        }

        return value;
    }


    /////////////////////////////////// MATH METHODS ///////////////////////////////////////

    Matrix Matrix::Add(const Matrix &matrix) const{

        if(this->size_ == matrix.size_)
        {
            Matrix add_matrix(this->size_.first, this->size_.second);

            //Init new matrix with rows and columns
            for (int i = 0; i < add_matrix.size_.first; i++) {
                add_matrix.values_.push_back(CreateColumnForRow(add_matrix.size_.first));
            }

            for (int i = 0; i < add_matrix.size_.first; i++) {
                for(int j = 0; j < add_matrix.size_.second;j++)
                {
                    add_matrix.values_[i][j] = std::complex<double>(this->values_[i][j].real() + matrix.values_[i][j].real(), this->values_[i][j].imag() + matrix.values_[i][j].imag());
                }
            }
            return add_matrix;
        }
        else
        {
            return Matrix();
        }
    }


    Matrix Matrix::Mul(const Matrix &matrix)  const {

        if(this->size_.second == matrix.size_.first) {

            Matrix mul_matrix(this->size_.first, matrix.size_.second);

            //Init new matrix with rows and columns
            for (int i = 0; i < mul_matrix.size_.first; i++) {
                mul_matrix.values_.push_back(CreateColumnForRow(mul_matrix.size_.second));
            }

            for (int i = 0; i < mul_matrix.size_.first; i++) {
                for (int j = 0; j < mul_matrix.size_.second; j++) {
                    mul_matrix.values_[i][j] = CountMultiply(i, j, this->values_, matrix.values_, this->size_.second);
                }
            }

            return mul_matrix;
        }
        else
        {
            return Matrix();
        }
    }


    Matrix Matrix::Sub(const Matrix &matrix) const {
        if(this->size_ == matrix.size_)
        {
            Matrix add_matrix(this->size_.first, this->size_.second);

            //Init new matrix with rows and columns
            for (int i = 0; i < add_matrix.size_.first; i++) {
                add_matrix.values_.push_back(CreateColumnForRow(add_matrix.size_.first));
            }

            for (int i = 0; i < add_matrix.size_.first; i++) {
                for(int j = 0; j < add_matrix.size_.second;j++)
                {
                    add_matrix.values_[i][j] = std::complex<double>(this->values_[i][j].real() - matrix.values_[i][j].real(), this->values_[i][j].imag() - matrix.values_[i][j].imag());
                }
            }
            return add_matrix;
        }
        else
        {
            return Matrix();
        }
    }

    Matrix Matrix::Pow(int power) {
        if(this->size_.first == this->size_.second)
        {
            if (power == 0)
            {
                Matrix temp(this->size_.first,this->size_.second);
                for (int i = 0; i < temp.size_.first; i++) {
                    temp.values_.push_back(CreateColumnForRow(temp.size_.first));
                }

                for(int i = 0; i < temp.size_.first;i++)
                {
                    temp.values_[i][i] = 1;
                }

                return temp;
            }
            else if (power == 1)
            {
                return *this;
            }
            else
            {
                Matrix temp(this->size_.first,this->size_.second);
                temp.values_ = this->values_;


                for(int i = 1; i < power;i++)
                {
                    temp = temp.Mul(*this);
                }
                return temp;
            }
        }
        else
        {
            return Matrix();
        }

    }


    ///////////////////////DESTRUCTOR////////////////////////////////

    Matrix::~Matrix() {

    }

}