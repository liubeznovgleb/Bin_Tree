#include <iostream>

using namespace std;

struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

void add(ListNode* root, int key){
    if (root == nullptr){
        ListNode* add = new ListNode;
        add->key = key;
        add->p = root->p;
        if (key < root->p->key)
        {
            root->p->left = add;
        }
        else
        {
            root->p->right = add;
        }
        return;
    }
    if (key < root->key){
        add(root->left, key);
    }
    else{
        add(root->right, key);
    }
}