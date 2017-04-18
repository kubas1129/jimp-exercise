//
// Created by kubas1129 on 02.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>


namespace pool {


    class TextPool{

    public:

        //Domyslny konsruktor
        TextPool() {};

        //Konstruktor z lista inizjalizacyjna
        TextPool(std::initializer_list<std::string> init_list);

        //konstruktor przenoszacy
        TextPool(TextPool &&textpool);
        //operator przypisania przenoszacy
        TextPool &operator=(TextPool &&textpool);

        //Usuwamy kopiujacy
        TextPool(const TextPool &textpool) = delete;
        //Usuwamy przypisania kopiujacy
        TextPool &operator=(const TextPool &textpool) = delete;

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set<std::string> pool_;

        void Move(TextPool &&textpool);
    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
