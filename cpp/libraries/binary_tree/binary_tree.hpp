#ifndef CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_HPP_
#define CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_HPP_
#include <string>
#include <iostream>
#include "binary_tree_node.hpp"

class BinaryTree
{
 public:
    BinaryTree();
    ~BinaryTree();
 
    int Height();
    void Add(const int input);
    friend std::ostream& operator<<(std::ostream &strm, const BinaryTree &bt);  
    void Print();
    void GetSortedArray(const int max_len,
        int* output_array,
        int* current_ndx);
 private:
    BinaryTreeNode* root_;
    int HeightRec(const BinaryTreeNode* node, const int current_height);
    void AddRec(const int input, BinaryTreeNode* node);
    void PrintRec(const BinaryTreeNode* node);
    void GetSortedArrayRec(const BinaryTreeNode* node,
        const int max_len,
        int* output_array,
        int* current_ndx);
};

#endif  //  CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_HPP_