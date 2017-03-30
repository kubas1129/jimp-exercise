//
// Created by kubas1129 on 21.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <ostream>
#include <string>
#include <memory>

namespace datastructures
{

    struct SmartTree
    {
        int value{0};
        std::unique_ptr<SmartTree> left;
        std::unique_ptr<SmartTree> right;
    };

    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

    void PrintTree(const std::unique_ptr<SmartTree> &tree, std::ostream *out);

    void SaveTreeToStr(const std::unique_ptr<SmartTree> &tree, std::string &str_tree);
    std::unique_ptr<SmartTree> LoadTreeFromStr(const std::string &str_tree, int &i);
}

#endif //JIMP_EXERCISES_SMARTTREE_H
