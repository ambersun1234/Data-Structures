#include <iostream>

using namespace std;

#define struct_tree_header

#ifndef struct_treenode_header
    #include "../struct_tree_node/node.hpp"
#endif

template<typename itemType>
class tree {
    private:
        node<itemType> *root;
        int capacity;

    private:
        void clean(node<itemType> *&root);
        bool delete_element(node<itemType> *&root, node<itemType> *target);
        node<itemType>* insert(node<itemType> *root, node<itemType> *newNode);
        node<itemType>* search(node<itemType> *root, itemType value);

    public:
        tree();
        ~tree();

        bool isEmpty();

        void clean_helper();
        void insert_helper(itemType value);
        bool delete_element_helper(itemType value);
        bool search_helper(itemType value);

        void infix();
        void postfix();
        void prefix();

        node<itemType>* getRoot();
        int getCapacity();
};

template<typename itemType>
tree<itemType>::tree() {
    this->root = nullptr;
    this->capacity = 0;
}

template<typename itemType>
tree<itemType>::~tree() {
    this->clean();
}

template<typename itemType>
node<itemType>* tree<itemType>::getRoot() {
    return this->root;
}

template<typename itemType>
int tree<itemType>::getCapacity() {
    return this->capacity;
}

template<typename itemType>
bool tree<itemType>::isEmpty() {
    return this->root == nullptr && this->capacity == 0;
}

template<typename itemType>
void tree<itemType>::clean_helper() {
    return this->clean(this->root);
}

template<typename itemType>
bool tree<itemType>::search_helper(itemType value) {
    return this->search(this->root, value) != nullptr;
}

template<typename itemType>
void tree<itemType>::insert_helper(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    this->insert(this->root, newNode);

    if (this->capacity == 0) this->root = newNode;
    this->capacity += 1;

    return;
}

template<typename itemType>
bool tree<itemType>::delete_element_helper(itemType value) {
    node<itemType> *result = this->search(value);

    if (result == nullptr) return false;
    else return this->delete_element(this->root, result);
}

template<typename itemType>
void tree<itemType>::clean(node<itemType> *&root) {
    if (root == nullptr) return;

    this->clean(root->getleft());
    this->clean(root->getright());

    delete root;
    root = nullptr;

    return;
}

template<typename itemType>
node<itemType>* tree<itemType>::search(node<itemType> *root, itemType value) {
    if (root == nullptr) return nullptr;

    if (root->getData() == value) return root;
    else if (root->getData() > value) this->search(root->getleft(), value);
    else this->search(root->getright(), value);
}

template<typename itemType>
bool tree<itemType>::delete_element(node<itemType> *&root, node<itemType> *target) {
    return true;
}

template<typename itemType>
node<itemType>* tree<itemType>::insert(node<itemType> *root, node<itemType> *newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (root->getData() > newNode->getData()) root->setleft(this->insert(root->getleft(), newNode));
    else root->setright(this->insert(root->getright(), newNode));

    return nullptr;
}