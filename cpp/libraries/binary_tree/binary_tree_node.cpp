#include <stdlib.h>
#include <stdio.h>
#include "binary_tree_node.hpp"

BinaryTreeNode::BinaryTreeNode(const int value)
{
    value_ = value;
    left_ = NULL;
    right_ = NULL;
}

BinaryTreeNode::~BinaryTreeNode()
{
    if(left_ != NULL)
    {
        delete left_;
        left_ = NULL;
    }
    
    if(right_ != NULL)
    {
        delete right_;
        right_ = NULL;
    }
}
