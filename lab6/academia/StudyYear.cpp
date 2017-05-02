//
// Created by kubas1129 on 06.04.17.
//

#include "StudyYear.h"

namespace academia
{

    StudyYear &StudyYear::operator++() {
        this->year_ ++;
        return *this;
    }

    StudyYear &StudyYear::operator--() {
        this->year_ --;
        return *this;
    }



    std::istream &operator>>(std::istream &is, StudyYear &study_year) {
        study_year.SetYear(is.get());
    }

    bool operator<(const StudyYear &L, const StudyYear &R) {
        if(L.GetYear() < R.GetYear()) return true;
        else return false;
    }

    bool operator>(const StudyYear &L, const StudyYear &R){
        if(L.GetYear() > R.GetYear()) return true;
        else return false;
    }

    bool operator==(const StudyYear &L, const StudyYear &R){
        if(L.GetYear() == R.GetYear()) return true;
        else return false;
    }

    std::ostream &operator<<(std::ostream &is, StudyYear &study_year) {
        is << study_year.GetYear();
        return is;
    }
}