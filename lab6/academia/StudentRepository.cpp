//
// Created by kubas1129 on 06.04.17.
//

#include <sstream>
#include "StudentRepository.h"

namespace academia {

    academia::StudentRepository::StudentRepository(std::initializer_list<academia::Student> list) {

        for(auto &v : list)
        {
            students_container_.push_back(v);
        }
    }

    Student &StudentRepository::operator[](std::string id) {

        for(auto &v : students_container_)
        {
            if(v.Id() == id) return v;
        }
    }

    bool operator==(const StudentRepository &L, const StudentRepository &R) {

        if(L.StudentCount() == R.StudentCount())
        {
            for(int i = 0; i < L.StudentCount();i++)
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
}