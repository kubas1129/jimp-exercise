//
// Created by kubas1129 on 06.04.17.
//

#include "Point.h"


namespace point {

    using ::std::istream;
    using ::std::ws;

    void CheckNextChar(char c, istream* is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw runtime_error("invalid character");
        }
        is->ignore();
    }

    void IgnoreWhitespace(istream* is) {
        (*is) >> ws;
    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }

    istream& operator>>(istream & input, Point& p){
        CheckNextChar('(', &input);
        p.SetX(ReadNumber(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        p.SetY(ReadNumber(&input));
        CheckNextChar(')', &input);
        return input;
    }

    std::ostream& operator<<(std::ostream &is, Point& point)
    {
        is << "(" << x_ << "," << y_ << ")";
        return is;
    }

}