//
// Created by kubas1129 on 27.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia {


    class Pesel {
    public:
        Pesel(std::string pesel);


    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:

        AcademiaDataValidationError(std::string message): std::runtime_error(message) {}

    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(std::string str): AcademiaDataValidationError("Invalid PESEL(" + str + ") character set") {}
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string str, unsigned long len): AcademiaDataValidationError("Invalid PESEL(" + str + ") length: " + std::to_string(len)) {}
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(std::string str, int num): AcademiaDataValidationError("Invalid PESEL(" + str + ") checksum: " + std::to_string(num)) {}
    };

}
#endif //JIMP_EXERCISES_PESEL_H
