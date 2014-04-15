#ifndef CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_HPP_
#define CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_HPP_

#include "linked_list_node.hpp"

class LinkedList
{
 public:
    LinkedList();
    ~LinkedList();
 
    int Length();
    void Add(const int input);
    bool Remove(int* output);
    
 private:
    LinkedListNode* head_;
    LinkedListNode* tail_;     
};

#endif  //  CPP_LIBRARIES_LINKED_LIST_LINKED_LIST_HPP_