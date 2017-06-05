//
// Created by Mateusz on 04.06.2017.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include <memory>
#include <iostream>
#include <vector>

namespace tree{
    template<class T>
    class Tree {
    public:
        Tree();
        Tree(T value);
        void Insert(T value);
        T Value();
        std::unique_ptr<Tree> Left();
        std::unique_ptr<Tree> Right();
        int Size();
        Tree Root();
        size_t Depth();


    private:
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        int size_;
        int depth_;
        T value_;
    };

    template<class T>
    Tree Tree<T>::Root(){
        return *this;
    }

    template<class T>
    Tree<T>::Tree():size_(0),depth_(0) {
        value_ = nullptr;
        left_ = nullptr;
        right_ = nullptr;
    }

    template<class T>
    Tree<T>::Tree(T value):size_(1),depth_(1){
        value_ = value;
        left_ = nullptr;
        right_ = nullptr;
    }

    template<class T>
    void Tree<T>::Insert(T value) {
        if (value > value_) {
            if (!right_)
                right_ = std::make_unique<Tree<T>>(value);
            else
                right_->Insert(value);
        }else {
            if (!left_)
                left_ = std::make_unique<Tree<T>>(value);
            else
                left_->Insert(value);
        }
        size_++;
    }
    //get_value
    template<class T>
    T Tree<T>::Value(){
        return value_;
    }
    template<class T>
    std::unique_ptr<Tree<T>> Tree<T>::Left() {
        return left_;
    }
    template<class T>
    std::unique_ptr<Tree<T>> Tree<T>::Right(){
        return right_;
    }

    template<class T>
    int Tree<T>::Size(){
        return size_;
    }

    template <class T>
    size_t Tree<T>::Depth(){
        if(left_ && right_)
            return 1+std::max(left_->Depth(),right_->Depth());
        else{
            if(left_)
                return 1+left_->Depth();
            if(right_)
                return 1+right_->Depth();
            return 1;
        }

    }


    /*template<class T>
    void Tree<T>::PrintTreeInOrder(const std::unique_ptr<Tree> &unique_ptr) {
        if (unique_ptr != nullptr) {
            PrintTreeInOrder(unique_ptr->left_);
            roots_.push_back(unique_ptr->value_);
            PrintTreeInOrder(unique_ptr->right_);
        }

    };*/

    template<class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(T value);
        void operator++();
        int operator*();
        int *iterator_;
        void PrintTreeInOrder(std::unique_ptr<Tree<T>> &uniq);
    private:
        std::vector<int> iterator_vector;
        int number_;

    };

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(T value):number_(0){
        PrintTreeInOrder(*std::make_unique<Tree<T>>(value));
        *iterator_=iterator_vector.at(0);

    };

    template<class T>
    void InOrderTreeIterator<T>::PrintTreeInOrder(std::unique_ptr<Tree<T>> &uniq) {
        if (uniq != nullptr) {
            PrintTreeInOrder(*uniq->Left());
            iterator_vector.push_back(uniq->Value());
            PrintTreeInOrder(*uniq->Right());
        }
    }

    template<class T>
    void InOrderTreeIterator<T>::operator++() {

        *iterator_=iterator_vector[number_+1];
    }
    template <class T>
    int InOrderTreeIterator<T>::operator*() {
        return *iterator_;
    }

    bool operator!=(const InOrderTreeIterator<int> &fir_arg, const InOrderTreeIterator<int> &sec_arg) {
        bool n=true;
        if(*fir_arg.iterator_!=*sec_arg.iterator_)
            n=true;
        else
            n= false;
        return n;
    }
    template <class T>
    class InOrderTreeView{
    public:

    };





}

#endif //JIMP_EXERCISES_TREEITERATORS_H
