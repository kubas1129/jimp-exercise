//
// Created by kubas1129 on 09.04.17.
//

#include "Counts.h"

namespace datastructures{


    Counts::Counts(int para) {
        counts_=para;
    }

    Counts &Counts::operator++() {
        this->counts_++;
        return *this;
    }
}