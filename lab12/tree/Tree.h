//
// Created by kubas1129 on 25.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>


namespace tree {


    template <class T>
    class Tree;

    template <class T>
    struct Node{
    public:
        T value;
        std::unique_ptr<Tree<T>> left;
        std::unique_ptr<Tree<T>> right;


    };




    template <class T>
    class Tree{
    public:
        void SetRoot(Node<T> node) {
            root = std::make_unique(node);
        }

        void Insert(Node<T> node){

        }

    private:
        std::unique_ptr<Node<T>> root;
    };

}

#endif //JIMP_EXERCISES_TREE_H
