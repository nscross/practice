#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.hpp"

BinaryTree::BinaryTree()
{
    root_ = NULL;    
}

BinaryTree::~BinaryTree()
{
    if (root_ != NULL)
    {
        delete root_;
        root_ = NULL;
    }
}

int BinaryTree::Height()
{
    int calculated_height = 0;
    
    if(root_ != NULL)
    {
        calculated_height = HeightRec(root_, 1); 
    }
    return calculated_height;    
}

int BinaryTree::HeightRec(const BinaryTreeNode* node, const int current_height)
{
    int left_height = current_height;
    int right_height = current_height;
    
    if (node->left_ != NULL)
    {
        left_height = HeightRec(node->left_, current_height + 1);        
    }
    
    if (node->right_ != NULL)
    {
        right_height = HeightRec(node->right_, current_height + 1);
    }
    
    return left_height > right_height ? left_height : right_height;    
}

void BinaryTree::GetSortedArray(const int max_len, int* output_array, int* current_ndx)
{
    *current_ndx = 0;
    
    if(root_ != NULL)
    {
        GetSortedArrayRec(root_, max_len, output_array, current_ndx); 
    }
    else
    {
       
    }
        
}

void BinaryTree::GetSortedArrayRec(
    const BinaryTreeNode* node,
    const int max_len,
    int* output_array,
    int* current_ndx)
{
    if (node->left_ != NULL)
    {
        GetSortedArrayRec(node->left_, max_len, output_array, current_ndx);         
    }    
    
    if (*current_ndx < max_len)
    {    
        *(output_array + *current_ndx) = node->value_;
        (*current_ndx)++;        
    }    
    
    if (node->right_ != NULL)
    {
        GetSortedArrayRec(node->right_, max_len, output_array, current_ndx);             
    }   
}

void BinaryTree::Print()
{
    if(root_ != NULL)
    {
        PrintRec(root_); 
    }
    else
    {
        printf("");
    }
}

void BinaryTree::PrintRec(const BinaryTreeNode* node)
{   
    if (node->left_ != NULL)
    {
        PrintRec(node->left_);         
    }
    
    printf("%d,", node->value_);
    
    if (node->right_ != NULL)
    {
        PrintRec(node->right_);        
    }    
}

void BinaryTree::Add(const int input)
{
    if (root_ == NULL)
    {
        root_ = new BinaryTreeNode(input);
    }
    else
    {
        AddRec(input, root_);
    }
}

void BinaryTree::AddRec(const int input, BinaryTreeNode* node)
{
    if (input <= node->value_)
    {
        if (node->left_ == NULL)
        {
            node->left_ = new BinaryTreeNode(input);
        }
        else
        {
            AddRec(input, node->left_);
        }        
    }
    
    else if (input > node->value_)
    {
        if (node->right_ == NULL)
        {
            node->right_ = new BinaryTreeNode(input);
        }
        else
        {
            AddRec(input, node->right_);
        }        
    }
}

std::ostream& operator<<(std::ostream &strm, const BinaryTree &bt)
{
  if (bt.root_ != NULL)
  {
  return strm << "BT(Not NULL)";
  /*
    int height = bt.Height();
    
    if (height > 0)
    {
        int* output_array = new int[height * 3]();
    }
    return strm << 
    */
  }
  else
  {
    return strm << "BT(NULL)";
  }
}
