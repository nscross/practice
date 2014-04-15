#include <stdio.h>
#include <stdlib.h>

#include "linked_list.hpp"

LinkedList::LinkedList()
{
    head_ = NULL;
    tail_ = NULL;
}

LinkedList::~LinkedList()
{
    LinkedListNode* itr_node = head_;
    
    if (itr_node != NULL)
    {
        LinkedListNode* itr_node_to_del = itr_node;
        itr_node = itr_node->next_;
        delete itr_node_to_del;
                
        while(itr_node != NULL && itr_node->next_ != NULL)
        {   
            itr_node_to_del = itr_node;
            itr_node = itr_node->next_;
            delete itr_node_to_del;
        }
    }
    
    head_ = NULL;
    tail_ = NULL;
}

int LinkedList::Length()
{
    int length_of_list = 0;
    
    LinkedListNode* itr_node = head_;
    
    if (itr_node != NULL)
    {   
        length_of_list++;    
        while(itr_node->next_ != NULL)
        {
            length_of_list++;
            itr_node = itr_node->next_;
        }        
    }  
    
    return length_of_list;
}

void LinkedList::Add(const int input)
{
    LinkedListNode* itr_node = head_;
    
    if (itr_node == NULL)
    {
        head_ = new LinkedListNode(input);
    }
    else
    {
        while(itr_node->next_ != NULL)
        {
            itr_node = itr_node->next_;
        }
        
        itr_node->next_ = new LinkedListNode(input);
    }
}

bool LinkedList::Remove(int* output)
{
    LinkedListNode* itr_node = head_;
    bool is_successful = false;
    
    if (itr_node != NULL)
    {      
        *output = itr_node->value_;
        head_ = itr_node->next_;
        delete itr_node;        
        is_successful = true;
    }
    
    return is_successful;
}