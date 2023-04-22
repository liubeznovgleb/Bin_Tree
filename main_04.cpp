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
    ///ВОТ ЗДЕСЬ Я НАЧАЛ ПОПРАВЛЯТЬ!
    if (cur_el==nullptr){
        cout<<"tree is empty";
        return;
    }
    ///ВОТ ЗДЕСЬ ЗАКОНЧИЛ!
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
    cout << root->key << " ";
    preord(root->left);
    preord(root->right);
}

void inord(ListNode* root){
    if (root == nullptr){
        return;
    }
    preord(root->left);
    cout << root->key << " ";
    preord(root->right);
}

void postord(ListNode* root){
    if (root == nullptr){
        return;
    }
    cout << root->key << " ";
    preord(root->right);
    preord(root->left);
}
// 2 - добавление элемента
void add(ListNode* root, int key){
    ListNode *elem = new ListNode;
    elem -> key = key;
    elem -> data = key;
    elem -> left = nullptr;
    elem -> right = nullptr;
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
// 3 - удаление элемента (по значению/узлу)
void delete_1(ListNode* del){
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
void delete_list(ListNode* del){
    if (del->p == nullptr){
        delete del;
        return;
    }
    if (del->key>=del->p->key){
            del->p->right = nullptr;
        } 
        else {del->p->left = nullptr;}
    delete del;
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
    if (root == nullptr){
        return root;
    }
    while (root -> left != nullptr){
        root = root -> left;
    }
return root;
}
//7 - поиск максимального элемента
ListNode * find_maximum(ListNode *root){
    if (root == nullptr){
        return root;
    }
    while (root -> right != nullptr){
        root = root -> right;
    }
return root;
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
        delete_list(del);
    }
    if (root == root_whole){
        root_whole = nullptr;
    }
}

//10 - cоздание дерева из массива
ListNode* convert_to_tree(int* a,int N,int root_index){
    ListNode* root = create_tree_element(root_index);
    bool already_there = 1;
    for (int i=0;i<=N-1;i+=1){
        if(a[i]==a[root_index-1] and already_there == 1){
            already_there = 0;
        } 
        else{
            ListNode *el = create_tree_element(a[i]);
            insert_into_tree(root,el);
        }
    }
    return root;
}

int main(){
    int const N = 7;
    //создаем массив из элементов, которые будем подавать в дерево
    int a[N] = {3, 7, 18, 29, 2, 89, 17};
    //создаем дерево
     ListNode* root = convert_to_tree(a,N,25);
    //печатаем, каким дерево было изначально 
    print_tree(root);
    // ДАЛЕЕ ВЫЗОВ ФУНКЦИЙ
    //1
    cout << 1 << endl;
    cout << "preord" << endl;
    preord(root);
    cout << endl;
    cout << "inord" << endl;
    inord(root);
    cout << endl;
    cout << "postord" << endl;
    postord(root);
    cout << endl;
    //2
    cout << 2 << endl;
    add(root, 100);
    print_tree(root);   
    //4
    cout << 4 << " height" << endl;
    cout << height(root);
    // 5
    cout << 5 << endl;
    cout << search(root, 18) -> key << " Search element"<< endl;
    //6
    cout << 6 << endl;
    cout << find_minimum(root) -> key << " Search min el" << endl;
    // 7 
    cout << 7 << endl;
    cout << find_maximum(root) -> key << " Search max el" << endl;
    //8
    cout << 8 << " delete part of tree" << endl;
    delete_tree(root,root -> left);
    //Далее печатаем дерево, чтобы увидеть, что изменилось
    print_tree(root);
    //9
    cout << 9 << " delete tree" << endl;
    delete_tree(root,root);
    print_tree(root); 
}
