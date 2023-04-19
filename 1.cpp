#include <iostream>

using namespace std;

// не уверен, что это в задании просят, т.к. не факт, что правильно понял

struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

void inord(ListNode* root){
    if (root == nullptr){
        return;
    }
    preord(root->left);
    cout << root->key;
    preord(root->right);
}

void preord(ListNode* root){
    if (root == nullptr){
        return;
    }
    cout << root->key;
    preord(root->left);
    preord(root->right);
}

void postord(ListNode* root){
    if (root == nullptr){
        return;
    }
    cout << root->key;
    preord(root->right);
    preord(root->left);
}