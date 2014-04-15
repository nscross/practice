#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "linked_list_node.hpp"
#include "linked_list.hpp"

TEST(LinkedListNode, Constructor){
    LinkedListNode* lln = new LinkedListNode(6);
    
    bool is_not_null = false;
    
    if (lln != NULL)
    {
        is_not_null = true;    
    }
    
    EXPECT_EQ(true, is_not_null);   
    
    delete lln;
}

TEST(LinkedListNode, GetValue){
    LinkedListNode* lln = new LinkedListNode(6);
        
    EXPECT_EQ(6, lln->value_);   
    
    delete lln;
}

TEST(LinkedList, Constructor) {
    LinkedList* ll;
    
    ll = new LinkedList();
    
    bool is_not_null = false;
    
    if (ll != NULL)
    {
        is_not_null = true;
    }
    
    EXPECT_EQ(true, is_not_null);   
    delete ll;    
}

TEST(LinkedList, CheckEmptyLength) {
    LinkedList* ll;
    
    ll = new LinkedList();    
    
    EXPECT_EQ(0, ll->Length());       
    delete ll;
}

TEST(LinkedList, Add) {
    LinkedList* ll;
    
    ll = new LinkedList();    
    
    ll->Add(5);
    
    EXPECT_EQ(1, ll->Length());   

    delete ll;
}

TEST(LinkedList, RemoveZeroLen) {
    LinkedList* ll;
    
    ll = new LinkedList();    
          
    int actual_value = -1;
    bool success = ll->Remove(&actual_value);
    
    EXPECT_EQ(false, success);        
    EXPECT_EQ(-1, actual_value);
    delete ll;
}

TEST(LinkedList, Remove) {
    LinkedList* ll;
    
    ll = new LinkedList();    
    
    ll->Add(5);
    
    int actual_value = -1;
    bool success = ll->Remove(&actual_value);
    
    EXPECT_EQ(true, success);        
    EXPECT_EQ(5, actual_value);    
    delete ll;
}

TEST(LinkedList, AddMultipleRemoveMultiple) {
    LinkedList* ll;
    
    ll = new LinkedList();    
    
    ll->Add(5);
    ll->Add(6);
    
    EXPECT_EQ(2, ll->Length());
    
    int actual_value = -1;
    bool success = false;
    success = ll->Remove(&actual_value);
    
    EXPECT_EQ(1, ll->Length());
    EXPECT_EQ(true, success);        
    EXPECT_EQ(5, actual_value);  

    success = ll->Remove(&actual_value);
    
    EXPECT_EQ(0, ll->Length());    
    EXPECT_EQ(true, success);        
    EXPECT_EQ(6, actual_value);  
    
    delete ll;
}
