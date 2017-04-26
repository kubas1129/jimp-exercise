//
// Created by kubas1129 on 24.04.17.
//

#include "Point.h"

#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point():x_(0),y_(0){
    std::cout << "Konstruktor bezparametrowy klasy Point" << endl;
}

Point::Point(double x, double y){
    std::cout << "Konstruktor parametrowy klasy Point" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point(){
    std::cout << "Destruktor klasy Point";
    std::cout << endl;
}

double Point::Distance(const Point &other) const{
    std::cout << "Distance klasy Point2D" << endl;
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    x_=x;
}

void Point::SetY(double y) {
    y_=y;
}

double Point3D::Distance(const Point3D &point3d) const {
    std::cout << "Distance klasy Point3D" << endl;
    return sqrt(pow(GetX()-point3d.GetX(),2)+pow(GetY()-point3d.GetY(),2)+pow(GetZ()-point3d.GetZ(),2));
}

Point3D::Point3D(){
    x_=0;
    y_=0;
    z_=0;
    std::cout << "Konstruktor bezparametrowy Point3D" << endl;
}

Point3D::Point3D(double x, double y, double z) {
    x_=x;
    y_=y;
    z_=z;
    std::cout << "Konstruktor parametrowy Point3D" << endl;
}

Point3D::~Point3D() {
    std::cout << "Destruktor Point3D" << endl;
}

std::ostream &operator<<(std::ostream &os, Point &point) {
    os << "Punkt (" << point.GetX() << "," << point.GetY() << ")" << std::endl;
    return os;
}
