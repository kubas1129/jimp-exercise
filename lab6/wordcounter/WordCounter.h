//
// Created by kubas1129 on 09.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H


#include <set>
#include <vector>
#include <algorithm>
#include "Word.h"
#include "Counts.h"

namespace datastructures {


    class WordCounter {
    private:
        std::vector<std::pair<Word, Counts>> dictionary_;
        unsigned int distinct_size_,total_size_;
    public:


        WordCounter();
        WordCounter(std::initializer_list<datastructures::Word> init);

        unsigned int DistinctWords() const;
        unsigned int TotalWords() const;

        std::set<datastructures::Word> Words();

        int operator[](std::string para);

        WordCounter &operator++();

        void AddPair(Word w, Counts c);

        WordCounter FromInputStream(std::istream *input);

        bool IsInDictionary(std::string word, int &it);

        void Sort();

        friend std::ostream& operator<<(std::ostream &os, WordCounter &wc);

    };

    bool operator==(const Word &L, const Word &R);
    bool operator==(const std::set<Word> &L, const unsigned int R);
    bool operator==(const Counts &L, const int &R);

    bool operator<(const Word &L,const Word &R);

    bool operator<(const Counts &L,const Counts &R);
    bool operator>(const Counts &L,const Counts &R);





}
#endif //JIMP_EXERCISES_WORDCOUNTER_H
