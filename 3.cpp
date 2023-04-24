#include <iostream>

using namespace std;

struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};

void delete_1(ListNode *node) {         // удаление элемента по узлу
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
        if (node->p != nullptr) {
            if (node->p->left == node) node->p->left = nullptr;
            else node->p->right = nullptr;
        }
        delete node;
    }
    else if (node->left == nullptr || node->right == nullptr) {
        ListNode *child = (node->left != nullptr) ? node->left : node->right;
        if (node->p != nullptr) {
            if (node->p->left == node) node->p->left = child;
            else node->p->right = child;
        }
        child->p = node->p;
        delete node;
    }
    else {
        ListNode *minNode = node->right;
        while (minNode->left != nullptr) minNode = minNode->left;
        node->key = minNode->key;
        node->data = minNode->data;
        delete_1(minNode);
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