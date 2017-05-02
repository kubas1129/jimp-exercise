//
// Created by kubas1129 on 06.04.17.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

namespace point {


    class Point {

    public:

        void SetX(double x);
        void SetY(double y);


    private:
        double x_, y_;
    };

    std::istream& operator>>(std::istream &is, Point& point);
    std::istream& operator<<(std::istream &is, Point& point);


}
#endif //JIMP_EXERCISES_POINT_H
