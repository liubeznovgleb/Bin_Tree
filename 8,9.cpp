#include <iostream>

using namespace std;

struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

void delete_1(ListNode* del){       // удаление элемента по узлу
    ListNode* x = del->left;
    while (x->right != nullptr)
    {
        x = x->right;
    }
    if (del->key < del->p->key)
    {
        del->p->left = x;
        x->left = del->left;
        x->right = del->right;
    }
    else
    {
        del->p->right = x;
        x->left = del->left;
        x->right = del->right;
    }
}

void delete_2(ListNode* root, int key){         // удаление элемента по ключу (просто функция поиска элемента по ключу + функция delete_1)
    while (root->key != key)
    {
        if (key < root->key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    delete_1(root);
}

ListNode* Node_to_delete(ListNode*tmp){
while (tmp->right!=nullptr or tmp->left!=nullptr){
        if (tmp->left!=nullptr){
            tmp = tmp->left;
        } else {tmp = tmp->right;}
    }
    return tmp;
}

void delete_tree(ListNode* root){
    if (root == nullptr){
        return;
    }
    ListNode* del;
    ListNode* tmp = root;
    del = nullptr;
    while (del!=root){
        del = Node_to_delete(tmp);
        tmp = del->p;
        delete_1(tmp);
    }
    delete_1(tmp);
}