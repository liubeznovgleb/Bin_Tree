#include<iostream>
using namespace std;
struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

ListNode * search(ListNode *root, int key){
    if ((root == nullptr) || (key == root -> key)){
        return root;
    }
    if (key < root -> key){
        return search(root -> left, key);
    }
    else{
        return search(root -> right, key);
    }
}