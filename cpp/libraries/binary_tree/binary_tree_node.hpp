#ifndef CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_NODE_HPP_
#define CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_NODE_HPP_

class BinaryTreeNode
{
 public:
    BinaryTreeNode(const int value);
    ~BinaryTreeNode();   
       
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;
    int value_;    
    
    friend bool operator== (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ == node2.value_;
    }
    
    friend bool operator!= (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ != node2.value_;
    }

    friend bool operator> (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ > node2.value_;
    }
    
    friend bool operator<= (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ <= node2.value_;
    }
 
    friend bool operator< (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ < node2.value_;    
    }
    
    friend bool operator>= (BinaryTreeNode &node1, BinaryTreeNode &node2)
    {
        return node1.value_ >= node2.value_;
    }    
    
         
};

#endif  //  CPP_LIBRARIES_BINARY_TREE_BINARY_TREE_NODE_HPP_