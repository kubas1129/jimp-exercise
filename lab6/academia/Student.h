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

        Student(): id_(""), first_name_(""), last_name_(""), program_("") {}
        Student(std::string id,std::string firstname, std::string lastname,std::string program, int year) : id_(id), first_name_(firstname), last_name_(lastname), program_(program), year_(StudyYear(year)) {}

        std::string Id() const { return this->id_; }
        std::string FirstName() const { return first_name_; }
        std::string LastName() const { return last_name_; }
        std::string Program() const { return program_; }
        StudyYear Year() const { return StudyYear{year_}; }

        void ChangeLastName(std::string lastname) { last_name_ = lastname; }

    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;

    };

    bool operator==(const Student &L, const Student &R);

}

#endif //JIMP_EXERCISES_STUDENT_H
