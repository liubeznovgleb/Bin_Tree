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


//Функция для 8 и 9 заданий одна, Node_to_delete это отдельная функция,
//которая отвечает за поиск листа для удаления
ListNode* Node_to_delete(ListNode*tmp){
while (tmp->right!=nullptr or tmp->left!=nullptr){
        if (tmp->left!=nullptr){
            tmp = tmp->left;
        } else {tmp = tmp->right;}
    }
return tmp;
}


//Основная функция. На вход принимает аргументы - корень целого дерева
// и корень поддерева, которое надо удалить
void delete_tree(ListNode* (&root_whole), ListNode* root){
    //случай nullptr
    if (root == nullptr){
        return;
    }
    ListNode* del;
    ListNode* tmp = root;
    del = nullptr;
    while (del!=root){
        del = Node_to_delete(tmp);
        tmp = del->p;
        delete_1(del);
    }
    if (root == root_whole){
        root_whole = nullptr;
    }
}