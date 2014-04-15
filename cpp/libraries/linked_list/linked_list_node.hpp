#ifndef CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_NODE_HPP_
#define CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_NODE_HPP_

class LinkedListNode
{
 public:
    LinkedListNode(const int value);
    ~LinkedListNode();   
       
    LinkedListNode* next_;
    LinkedListNode* prev_;
    int value_;    
         
};

#endif  //  CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_NODE_HPP_