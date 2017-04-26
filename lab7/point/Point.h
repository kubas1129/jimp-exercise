//
// Created by kubas1129 on 24.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H


#include <ostream>

class Point {
public:
    //Konstruktor bezparametrowy
    Point();
    //Konstruktor parametrowy
    Point(double x, double y);
    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point();

    //Metody nie modyfikujące stanu obiektu (const na końcu metody)
    //nie mogą zmodyfikować tego obiektu.
    void ToString(std::ostream *out) const;
    double Distance(const Point &other) const;


    //metody akcesorów są publiczne i tylko w przy ich pomocy
    //można się dostać z zewnątrz do pól klasy
    double GetX() const;
    double GetY() const;

    //metody seterów pozwalające zmienić stan obiektu
    //po jego zainicjalizowaniu
    void SetX(double x);
    void SetY(double y);
protected:
    //w przeciwienstwie do pythona C++ wymaga jawnej deklaracji składowych pól klasy:
    double x_, y_;
};

std::ostream& operator<<(std::ostream &os, Point& point);

class Point3D : public Point{

public:

    Point3D();
    Point3D(double x, double y, double z);

    double Distance(const Point3D &point3d) const;

    double GetZ() const { return z_; }

    void SetZ(double z) { z_=z; }

    ~Point3D();


private:
    double z_;
};


#endif //JIMP_EXERCISES_POINT_H
