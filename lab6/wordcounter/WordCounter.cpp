//
// Created by kubas1129 on 09.04.17.
//

#include <iostream>
#include "WordCounter.h"

namespace datastructures{


    WordCounter::WordCounter() {
        distinct_size_=0;
        total_size_=0;
    }

    WordCounter::WordCounter(std::initializer_list<datastructures::Word> init) {
        distinct_size_=0;
        total_size_=0;

        int iterator=0;
        for(const auto &v : init)
        {
            if(IsInDictionary(v.GetWord(), iterator))
            {
                dictionary_[iterator].second.operator++();
            }
            else
            {
                Word temp_word(v.GetWord());
                Counts temp_counts;
                std::pair<datastructures::Word, datastructures::Counts> pair_(temp_word,temp_counts);
                dictionary_.push_back(pair_);
                distinct_size_++;
            }
            total_size_++;
        }
    }

    unsigned int WordCounter::DistinctWords() const {
        return distinct_size_;
    }

    unsigned int WordCounter::TotalWords() const {
        return total_size_;
    }


    WordCounter &WordCounter::operator++() {

    }

    bool WordCounter::IsInDictionary(std::string word, int &it) {
        it = 0;
        for(const auto &v : dictionary_)
        {
            if(word == v.first.GetWord())
            {
                return true;
            }
            it++;
        }
        return false;
    }

    int WordCounter::operator[](std::string para){
        int iter = 0;
        if(IsInDictionary(para,iter))
        {
            return this->dictionary_[iter].second.GetCounts();
        }
        else
        {
            return 0;
        }
    }

    bool operator==(const std::set<Word> &L, const unsigned int R) {
        if(L.size() == R) return true;
        else return false;
    }

    bool operator<(const Word &L, const Word &R) {
        if(L.GetWord() < R.GetWord()) return true;
        else return false;
    }

    bool operator==(const Counts &L, const int &R) {
        if(L.GetCounts() == R) return true;
        else return false;
    }

    std::ostream &operator<<(std::ostream &os, WordCounter &wc) {
        os << "Slow lacznie: " << wc.TotalWords() << ", a roznych slow" << wc.DistinctWords() << "\n";
        wc.Sort();
        for (const auto &a : wc.dictionary_) {
            os << a.first.GetWord() << " - " << a.second.GetCounts() << " | ";
        }
        return os;
    }

    bool operator<(const Counts &L, const Counts &R) {
        if(L.GetCounts() < R.GetCounts()) return true;
        else return false;
    }

    bool operator>(const Counts &L, const Counts &R) {
        if(L.GetCounts() > R.GetCounts()) return true;
        else return false;
    }

    bool operator==(const Word &L, const Word &R) {
        if(R.GetWord() == L.GetWord()) return true;
        else return false;
    }

    void WordCounter::Sort(){
        struct {
            bool operator()(std::pair<Word, Counts> a, std::pair<Word, Counts> b)
            {
                return a.first < b.first;
            }
        } customLess;
        std::sort(dictionary_.begin(), dictionary_.end(), customLess);
    }

    WordCounter WordCounter::FromInputStream(std::istream *input) {

        std::string content = std::string{std::istreambuf_iterator<char>(*input),std::istreambuf_iterator<char>()};
        WordCounter wc;

        std::string temp="";
        for(const char &v : content)
        {
            if((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z')){
                temp += v;
            }
            else
            {
                if(temp.length() != 0) wc.AddPair(temp, Counts());
                temp = "";
            }
        }


        return wc;
    }

    std::set<datastructures::Word> WordCounter::Words() {
        std::set<Word> words;
        for(const auto &v : dictionary_)
        {
            words.emplace(v.first);
        }
        return words;
    }

    void WordCounter::AddPair(Word w, Counts c) {
        int ind = 0;
        if(IsInDictionary(w.GetWord(),ind))
        {
            dictionary_[ind].second.operator++();
        }
        else
        {
            dictionary_.push_back(std::pair<Word,Counts>(w,c));
            distinct_size_++;
        }
        total_size_++;
    }

    void WordCounter::Print() {
        for(const auto &v : dictionary_)
        {
            std::cout << v.first.GetWord() << " : " << v.second.GetCounts() << ",";
        }
    }
}