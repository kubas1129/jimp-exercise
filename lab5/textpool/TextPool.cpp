//
// Created by kubas1129 on 02.04.17.
//

#include "TextPool.h"


namespace pool{


    TextPool::TextPool(std::initializer_list<std::string> init_list) {

        for(auto &v : init_list)
        {
            pool_.emplace(v);
        }
    }

    std::experimental::string_view TextPool::Intern(const std::string &str) {

        std::experimental::string_view str_view;

        for(const auto &v : pool_)
        {
            if(v == str) {
                str_view = v;
                return str_view;
            }
        }

        pool_.emplace(str);

        for(const auto &v : pool_)
        {
            if(v == str) {
                str_view = v;
                return str_view;
            }
        }

    }

    size_t TextPool::StoredStringCount() const {
        return pool_.size();
    }


    TextPool::TextPool(TextPool &&textpool) {
        Move(std::move(textpool));
    }

    void TextPool::Move(TextPool &&textpool) {
        swap(pool_, textpool.pool_);
    }

    TextPool &TextPool::operator=(TextPool &&textpool) {
        if(this == &textpool)
        {
            return *this;
        }
        std::swap(pool_, textpool.pool_);
    }
}