//
// Created by kubas1129 on 09.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {


    class Word {
    private:
        std::string word_;

    public:
        Word(std::string word) : word_(word) {};

        std::string GetWord() const { return word_;}

    };



}
#endif //JIMP_EXERCISES_WORD_H
