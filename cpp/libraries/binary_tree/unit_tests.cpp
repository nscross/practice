#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "binary_tree_node.hpp"
#include "binary_tree.hpp"

TEST(BinaryTreeNode, Constructor){
    BinaryTreeNode* btn = new BinaryTreeNode(6);
    
    bool is_not_null = false;
    
    if (btn != NULL)
    {
        is_not_null = true;    
    }
    
    EXPECT_EQ(true, is_not_null);   
    EXPECT_EQ(NULL, btn->left_);   
    EXPECT_EQ(NULL, btn->right_);   
    EXPECT_EQ(6, btn->value_);  
    
    delete btn;
}

TEST(BinaryTreeNode, GetValue){
    BinaryTreeNode* btn = new BinaryTreeNode(3);
        
    EXPECT_EQ(3, btn->value_);   
    
    delete btn;
}

TEST(BinaryTreeNode, TestEquals){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(true, *btn1 == *btn2);  
    EXPECT_EQ(false, *btn1 == *btn3);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTreeNode, TestNotEquals){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(false, *btn1 != *btn2);  
    EXPECT_EQ(true, *btn1 != *btn3);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTreeNode, TestGreaterThan){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(false, *btn1 > *btn2);  
    EXPECT_EQ(true, *btn1 > *btn3);   
    EXPECT_EQ(false, *btn3 > *btn1);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTreeNode, TestGreaterThanOrEquals){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(true, *btn1 >= *btn2);  
    EXPECT_EQ(true, *btn1 >= *btn3);   
    EXPECT_EQ(false, *btn3 >= *btn1);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTreeNode, TestLessThan){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(false, *btn1 < *btn2);  
    EXPECT_EQ(false, *btn1 < *btn3);   
    EXPECT_EQ(true, *btn3 < *btn1);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTreeNode, TestLessThanOrEquals){
    BinaryTreeNode* btn1 = new BinaryTreeNode(6);    
    BinaryTreeNode* btn2 = new BinaryTreeNode(6);
    BinaryTreeNode* btn3 = new BinaryTreeNode(5);
        
    EXPECT_EQ(true, *btn1 <= *btn2);  
    EXPECT_EQ(false, *btn1 <= *btn3);   
    EXPECT_EQ(true, *btn3 <= *btn1);       
    
    delete btn1;
    delete btn2;
    delete btn3;
}

TEST(BinaryTree, Constructor) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bool is_not_null = false;
    
    if (bt != NULL)
    {
        is_not_null = true;
    }
    
    EXPECT_EQ(true, is_not_null);       
    delete bt;    
}

TEST(BinaryTree, EmptyHeight) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    EXPECT_EQ(0, bt->Height());       
    delete bt;    
}

TEST(BinaryTree, HeightJustRoot) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bt->Add(50);
    
    EXPECT_EQ(1, bt->Height());       
    delete bt;    
}

TEST(BinaryTree, HeightThreeOfTheSame) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(50);    
    bt->Add(50);
    
    EXPECT_EQ(3, bt->Height());       
    delete bt;    
}

TEST(BinaryTree, HeightTriangle) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(45);    
    bt->Add(60);
    
    EXPECT_EQ(2, bt->Height());       
    delete bt;    
}

TEST(BinaryTree, HeightThreeRights) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(60);    
    bt->Add(70);
    
    EXPECT_EQ(3, bt->Height());       
    delete bt;    
}
/*
TEST(BinaryTree, Print) {
    BinaryTree* bt;
    
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(60);    
    bt->Add(70);
    
    bt->Print();
    EXPECT_EQ(3, bt->Height());       
    delete bt;    
}
*/

TEST(BinaryTree, GetSortedArrayEmpty) {
    BinaryTree* bt;
    int expected_array[] = {50, 60, 70};
    int actual_array[3] = {0};
    bt = new BinaryTree();
        
    int actual_len = 0;
    bt->GetSortedArray(3, actual_array, &actual_len);
    EXPECT_EQ(0, actual_len);
    
    for(int ndx = 0; ndx < actual_len; ndx++)
    {
        EXPECT_EQ(expected_array[ndx], actual_array[ndx]);
    }
    
    delete bt;    
}

TEST(BinaryTree, GetSortedArrayAllRight) {
    BinaryTree* bt;
    int expected_array[] = {50, 60, 70};
    int actual_array[3] = {0};
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(60);    
    bt->Add(70);
    
    int actual_len = 0;
    bt->GetSortedArray(3, actual_array, &actual_len);
    EXPECT_EQ(3, actual_len);
    
    for(int ndx = 0; ndx < actual_len; ndx++)
    {
        EXPECT_EQ(expected_array[ndx], actual_array[ndx]);
    }
    
    delete bt;    
}

TEST(BinaryTree, GetSortedArrayTriangle) {
    BinaryTree* bt;
    int expected_array[] = {35, 50, 60};
    int actual_array[3] = {0};
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(35);    
    bt->Add(60);
    
    int actual_len = 0;
    bt->GetSortedArray(3, actual_array, &actual_len);
    EXPECT_EQ(3, actual_len);
    
    for(int ndx = 0; ndx < actual_len; ndx++)
    {
        EXPECT_EQ(expected_array[ndx], actual_array[ndx]);
    }
    
    delete bt;    
}

TEST(BinaryTree, GetSortedArrayAllLeft) {
    BinaryTree* bt;
    int expected_array[] = {50, 50, 50};
    int actual_array[3] = {0};
    bt = new BinaryTree();
    
    bt->Add(50);    
    bt->Add(50);    
    bt->Add(50);
    
    int actual_len = 0;
    bt->GetSortedArray(3, actual_array, &actual_len);
    EXPECT_EQ(3, actual_len);
    
    for(int ndx = 0; ndx < actual_len; ndx++)
    {
        EXPECT_EQ(expected_array[ndx], actual_array[ndx]);
    }
    
    delete bt;    
}

TEST(BinaryTree, GetSortedArrayRandom) {
    BinaryTree* bt;
    int expected_array[] = {18, 33, 43, 46, 60, 78, 79};
    int actual_array[7] = {0};
    bt = new BinaryTree();
    
    bt->Add(33);    
    bt->Add(43);    
    bt->Add(18);
    bt->Add(79);
    bt->Add(78);
    bt->Add(60);
    bt->Add(46);
    
    int actual_len = 0;
    bt->GetSortedArray(3, actual_array, &actual_len);
    EXPECT_EQ(3, actual_len);
    
    for(int ndx = 0; ndx < actual_len; ndx++)
    {
        EXPECT_EQ(expected_array[ndx], actual_array[ndx]);
    }
    
    delete bt;    
}