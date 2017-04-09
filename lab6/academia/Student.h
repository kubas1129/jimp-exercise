//
// Created by kubas1129 on 06.04.17.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <string>
#include "StudyYear.h"

namespace academia {


    class Student {
    public:

    private:
        std::string id_;
        std::string first_name_;
        std::string last_name;
        StudyYear year;

    };

}

#endif //JIMP_EXERCISES_STUDENT_H
