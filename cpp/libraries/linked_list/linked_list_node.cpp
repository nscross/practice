#include <stdlib.h>
#include <stdio.h>
#include "linked_list_node.hpp"

LinkedListNode::LinkedListNode(const int value)
{
    value_ = value;
    next_ = NULL;
    prev_ = NULL;
}

LinkedListNode::~LinkedListNode()
{
    
}
