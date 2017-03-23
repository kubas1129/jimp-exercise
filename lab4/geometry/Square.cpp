//
// Created by kubas1129 on 23.03.17.
//

#include "Square.h"

namespace geometry {


    geometry::Square::Square(Point p1, Point p2, Point p3, Point p4) {

        if(p1.Distance(p2) == p3.Distance(p4) && p2.Distance(p3) == p1.Distance(p4))
        {
            a_ = p1.Distance(p2);
        } else {
            a_ = 0;
        }

    }

    double Square::Circumference() {
        return 4*a_;
    }

    double Square::Area() {
        return a_*a_;
    }


}