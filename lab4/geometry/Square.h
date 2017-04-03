//
// Created by kubas1129 on 23.03.17.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"

namespace geometry {


    class Square {

    public:

        Square(Point p1, Point p2, Point p3, Point p4);

        double Circumference();

        double Area();

    private:

        double a_;

    };

}

#endif //JIMP_EXERCISES_SQUARE_H
