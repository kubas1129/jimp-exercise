//
// Created by kubas1129 on 06.04.17.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <iostream>

namespace academia {

    class StudyYear {
    public:
        StudyYear() : year_(1) {};

        StudyYear(int year) : year_(year) {}

        StudyYear &operator++();

        StudyYear &operator--();

        int GetYear()const { return year_;}

        void SetYear(int year) { year_=year;}

        operator int() const { return year_; }

    private:
        int year_;

    };

    std::istream& operator>>(std::istream &is, StudyYear& study_year);
    std::istream& operator<<(std::istream &is, StudyYear& study_year);

    bool operator<(const StudyYear &L, const StudyYear &R);
    bool operator>(const StudyYear &L, const StudyYear &R);
    bool operator==(const StudyYear &L, const StudyYear &R);
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
