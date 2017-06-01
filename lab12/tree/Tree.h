//
// Created by kubas1129 on 25.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>


namespace tree {


    template <class T>
    class Tree{
    public:
        Tree();
        Tree(T key);

        void Insert(T key);

        T Value() const { return key_;  }

        size_t Depth() {}
        size_t Size() {}

    private:
        T key_;
        std::unique_ptr<Tree<T>> left_;
        std::unique_ptr<Tree<T>> right_;
    };


    template <class T>
    Tree<T>::Tree(T key) {
        key_ = key;
        left_ = nullptr;
        right_ = nullptr;
    }

    template <class T>
    void Tree<T>::Insert(T key) {
        if(key > key_)
        {
            if(right_ != nullptr)
            {
                right_ = std::make_unique<Tree<T>>(key);
            }
            else
            {
                right_->Insert(key);
            }
        }
        else
        {
            if(left_ != nullptr)
            {
                left_ = std::make_unique<Tree<T>>(key);
            }
            else
            {
                left_->Insert(key);
            }
        }
    }



}

#endif //JIMP_EXERCISES_TREE_H
