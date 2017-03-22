//
// Created by kubas1129 on 21.03.17.
//

#include <vector>
#include "SmartTree.h"


namespace datastructures
{


    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        return leaf;
    }

    std::unique_ptr<SmartTree>InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        if(tree != nullptr && left_subtree != nullptr)
        {
            tree->left = move(left_subtree);
        }
        return tree;
    }

    std::unique_ptr<SmartTree>InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        if(tree != nullptr && right_subtree != nullptr)
        {
            tree->right = move(right_subtree);
        }
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        PrintTree(unique_ptr,  out);
    }

    void PrintTree(const std::unique_ptr<SmartTree> &tree, std::ostream *out) {

        bool add_to_stream = false;

        if (tree->left != nullptr || tree->right != nullptr) {

            if(tree->left != nullptr)
            {
                PrintTree(tree->left, out);
                if(!add_to_stream)
                {
                    *(out) << tree->value << ", ";
                    add_to_stream = true;
                }

            }
            if(tree->right != nullptr)
            {
                PrintTree(tree->right, out);
                if(!add_to_stream)
                {
                    *(out) << tree->value << ", ";
                    add_to_stream = true;
                }
            }
        }
        if(!add_to_stream)
        {
            *(out) << tree->value << ", ";
        }
    }



    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::string str_tree = "";
        SaveTreeToStr(tree, str_tree);
        return str_tree;
    }

    void SaveTreeToStr(const std::unique_ptr<SmartTree> &tree, std::string &str_tree) {

        std::string str_value = std::to_string(tree->value);

        str_tree += "[" + str_value;

        if(tree != nullptr)
        {
            if(tree->left != nullptr)
            {
                str_tree += " ";
                SaveTreeToStr(tree->left, str_tree);
            }
            else
            {
                str_tree += " [none]";
            }
            if(tree->right != nullptr)
            {
                str_tree += " ";
                SaveTreeToStr(tree->right, str_tree);
            }
            else
            {
                str_tree += " [none]";
            }
        }

        str_tree += "]";
    }


    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        int index = 1;
        return LoadTreeFromStr(tree, index);
    }


    std::unique_ptr<SmartTree> LoadTreeFromStr(const std::string &str_tree, int &i) {


        std::string temp = "";

        while(str_tree[i] != ' ' || str_tree[i] != ']')
        {
            if(str_tree[i] != '[')
            {
                temp += str_tree[i];
            }
            i++;
        }

        if(temp != "none")
        {
            std::unique_ptr<SmartTree> ptr_tree = std::make_unique<SmartTree>();
            ptr_tree->value = std::stoi(temp);

            if(str_tree[i] == ']') return ptr_tree;

            i++;
            ptr_tree->left = LoadTreeFromStr(str_tree, i);
            i++;
            ptr_tree->right = LoadTreeFromStr(str_tree, i);

            return ptr_tree;
        }
        else
        {
            return nullptr;
        }
    }

}