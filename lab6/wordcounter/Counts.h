//
// Created by kubas1129 on 09.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H


namespace datastructures {


    class Counts {
    private:
        int counts_;
    public:
        Counts() { counts_ = 1; }
        Counts(int para);

        int GetCounts() const { return counts_; }

        Counts &operator++();

    };


}
#endif //JIMP_EXERCISES_COUNTS_H
