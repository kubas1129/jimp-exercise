//
// Created by kubas1129 on 23.03.17.
//

#ifndef JIMP_EXERCISES_NAME_H
#define JIMP_EXERCISES_NAME_H

#include <string>

namespace name {


    class Name {

    public:

        Name(std::string first_name, std::string second_name, std::string third_name, std::string surname) : First_Name(first_name),
        Second_Name(second_name), Third_Name(third_name), SurName(surname) {}
        Name(std::string full_name);

    private:
        std::string First_Name;
        std::string Second_Name;
        std::string Third_Name;
        std::string SurName;

    };

}

#endif //JIMP_EXERCISES_NAME_H
