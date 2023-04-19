#include<iostream>
using namespace std;

struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

ListNode * find_maximum(ListNode *root){
    while (root -> right != nullptr){
        root = root -> right;
    }
return root;
}