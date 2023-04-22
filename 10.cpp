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
        return;
    }
    if (key < root->key){
        add(root->left, key);
    }
    else{
        add(root->right, key);
    }
}

void bubble_sort(){}

void convert_to_tree(int* a,int begin,int end){
    ListNode* root = new ListNode;
    bubble_sort(a,begin,end);
    if ((end-begin)<=3){
        for (int i=0;i<=2;i+=1){
        add(root,a[i]);}
    } else{
        add(root,a[(N-1)/2]);
        convert_to_tree(&(a[((N-1)/2)/2]),((N-1)/2));
        convert_to_tree(&(a[(((N-1)/2)+N-1)/2]));
    }
    return root;
}