#include <iostream>
using namespace std;
struct ListNode {
    int key; // key to access the data and compare nodes
    int data;
    ListNode *left; // pointer to left node
    ListNode *right; // pointer to right node
    ListNode *p; // parent pointer
};
// создаем элемент дерева со значением int i
ListNode *create_tree_element( int i){
    ListNode *elem = new ListNode;
    elem -> key = i;
    elem -> data = i;
    elem -> left = nullptr;
    elem -> right = nullptr;
    elem -> p = nullptr;
    return elem;
}
void insert_into_tree(ListNode *root, ListNode * elem){
    if (elem -> key < root -> key){
        // идем в левое поддерево
        if (root -> left == nullptr){
            root -> left = elem;
            elem -> p = root;
        }
        else{
            insert_into_tree(root -> left, elem);
        }
    }
    else{
        if (root -> right == nullptr){
            root -> right = elem;
            elem -> p = root;
        }
        else{
            insert_into_tree(root -> right, elem);
        }
    }
}
void print_tree(ListNode *cur_el){
    if (cur_el -> left != nullptr){
        print_tree(cur_el -> left);
    }
    cout << "Value = " << cur_el -> key << endl;
    if (cur_el -> right != nullptr){
        print_tree(cur_el -> right);
    }
}
// ПРОПИСЫВАЕМ ФУНКЦИИ ИЗ ЗАДАНИЯ

// 1 - 3 вида обхода дерева (pre/in/post order) ( + печать)
void preord(ListNode* root){
    if (root == nullptr){
        return;
    }
    cout << root->key;
    preord(root->left);
    preord(root->right);
}

void inord(ListNode* root){
    if (root == nullptr){
        return;
    }
    preord(root->left);
    cout << root->key;
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
// 2 - добавление элемента
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
// 3 - удаление элемента (по значению/узлу)
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
// 4 - вычисление высоты дерева
int height(ListNode* root) {
    if (root == NULL) {
        return -1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
}
// 5 - поиск элемента в дереве по значению 
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
// 6 - поиск минимального элемента
ListNode * find_minimum(ListNode *root){
    while (root -> left != nullptr){
        root = root -> left;
    }
return root;
}
//7 - поиск максимального элемента
ListNode * find_maximum(ListNode *root){
    while (root -> right != nullptr){
        root = root -> right;
    }
return root;
}
//8 - удаление поддерева
// 9 - удаление всего дерева
//10 - cоздание дерева из массива

int main(){
    int N = 7;
    //создаем массив из элементов, которые будем подавать в дерево
    int a[N] = {3, 7, 18, 29, 2, 89, 17};
    //создаем корневой элемент
    ListNode *root = create_tree_element(25);
    for (int i = 0; i < N; i++){
        ListNode *el = create_tree_element(a[i]);
        insert_into_tree(root, el);
    }
    //печатаем, каким дерево было изначально 
    print_tree(root);
    // ДАЛЕЕ ВЫЗОВ ФУНКЦИЙ
    // 5
    cout << 5 << endl;
    cout << search(root, 18) -> key << endl;
    //6
    cout << 6 << endl;
    cout << find_minimum(root) -> key << endl;
    // 7 
    cout << 7 << endl;
    cout << find_maximum(root) -> key << endl;
}