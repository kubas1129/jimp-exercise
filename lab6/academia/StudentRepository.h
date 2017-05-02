//
// Created by kubas1129 on 06.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <vector>
#include "Student.h"
#include "StudyYear.h"

namespace academia {

    class StudentRepository {
    public:

        StudentRepository() {}
        StudentRepository(std::initializer_list<Student> list);


        unsigned long StudentCount() const { return students_container_.size(); }

        Student& operator[](std::string id);


        std::string GetId(int i) const { return students_container_[i].Id(); }
        std::string GetFirstName(int i) const { return students_container_[i].FirstName(); }
        std::string GetLastName(int i) const { return students_container_[i].LastName(); }
        std::string GetProgram(int i) const { return students_container_[i].Program(); }
        StudyYear GetYear(int i) const { return StudyYear{students_container_[i].Year()}; }




    private:
        std::vector<Student> students_container_;

    };

    bool operator==(const StudentRepository &L, const StudentRepository &R);

}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
