#include <iostream>

using namespace std;

#define struct_tree_header

#ifndef struct_treenode_header
    #include "../struct_tree_node/node.hpp"
#endif

#include "gtest/gtest_prod.h"

template<typename itemType>
class tree {
    private:
        node<itemType> *root;
        int capacity;

    private:
        void clean(node<itemType> *root);
        node<itemType>* delete_element(node<itemType> *root, node<itemType> *target);
        node<itemType>* insert(node<itemType> *root, node<itemType> *newNode);
        node<itemType>* search(node<itemType> *root, itemType value);
        node<itemType>* search_parent(node<itemType> *root, itemType value);
        int getMaxLevel(node<itemType> *root);
        node<itemType>* findSmallest(node<itemType> *root);

        void inorder(node<itemType> *root);
        void postorder(node<itemType> *root);
        void preorder(node<itemType> *root);

        // set friend test
        FRIEND_TEST(struct_test , isLeaf); // must be in the same namespace
        FRIEND_TEST(struct_test , search); // must be in the same namespace
        FRIEND_TEST(struct_test , search_parent); // must be in the same namespace

    public:
        tree();
        ~tree();

        bool isEmpty();
        bool isLeaf(node<itemType> *root);

        void clean_helper();
        void insert_helper(itemType value);
        bool delete_element_helper(itemType value);
        bool search_helper(itemType value);
        int getMaxLevel_helper();

        void inorder_helper();
        void postorder_helper();
        void preorder_helper();

        int getChildNum(node<itemType> *root);
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
bool tree<itemType>::isLeaf(node<itemType> *root) {
    if (root == nullptr) return true;
    return (root->getleft() == nullptr && root->getright() == nullptr);
}

template<typename itemType>
int tree<itemType>::getChildNum(node<itemType> *root) {
    if (root == nullptr) return 0;
    return (root->getleft() == nullptr ? 0 : 1) + (root->getright() == nullptr ? 0 : 1);
}

template<typename itemType>
void tree<itemType>::clean_helper() {
    this->clean(this->root);

    this->root = nullptr;
    this->capacity = 0;
    return;
}

template<typename itemType>
void tree<itemType>::clean(node<itemType> *root) {
    if (root == nullptr) return;

    this->clean(root->getleft());
    this->clean(root->getright());

    delete root;
    root = nullptr;

    return;
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
    node<itemType> *result = this->search(this->root, value);

    if (result == nullptr) return false;
    this->root = this->delete_element(this->root, result);
    return true;
}

template<typename itemType>
int tree<itemType>::getMaxLevel_helper() {
    return this->getMaxLevel(this->root);
}

template<typename itemType>
int tree<itemType>::getMaxLevel(node<itemType> *root) {
    if (root == nullptr) return 0;

    return max(this->getMaxLevel(root->getleft()), this->getMaxLevel(root->getright())) + 1;
}

template<typename itemType>
node<itemType>* tree<itemType>::findSmallest(node<itemType> *root) {
    /* find target right smallest data, and return it
     * it's guarantee that root will have it's right children
     * since delete_element function if statement
     */
    node<itemType> *smallest = root->getright();
    node<itemType> *previous = nullptr;

    while (smallest->getleft() != nullptr) {
        previous = smallest;
        smallest = smallest->getleft();
    }

    previous->setleft(smallest->getright());
    return smallest;
}

template<typename itemType>
node<itemType>* tree<itemType>::search_parent(node<itemType> *root, itemType value) {
    if (root == nullptr) return nullptr;

    if (root->getleft() != nullptr && root->getleft()->getData() == value) return root;
    if (root->getright() != nullptr && root->getright()->getData() == value) return root;

    else if (root->getData() > value) return this->search_parent(root->getleft(), value);
    else return this->search_parent(root->getright(), value);
}

template<typename itemType>
node<itemType>* tree<itemType>::search(node<itemType> *root, itemType value) {
    if (root == nullptr) return nullptr;

    if (root->getData() == value) return root;
    if (root->getData() > value) return this->search(root->getleft(), value);
    
    return this->search(root->getright(), value);
}

template<typename itemType>
node<itemType>* tree<itemType>::delete_element(node<itemType> *root, node<itemType> *target) {
    if (root == nullptr) return nullptr;

    // no children
    if (root == target) {
        if (this->isLeaf(target) || this->getChildNum(target) == 1) {
            node<itemType>* parent = this->search_parent(this->root, target->getData());

            if (parent == nullptr) return nullptr;
            return (parent->getleft() == target ? target->getright() : target->getleft());
        }
        else {
            // guarantee that smallest is not nullptr
            node<itemType> *smallest = this->findSmallest(root);

            smallest->setleft(target->getleft());
            smallest->setright(target->getright());

            delete target;
            return smallest;
        }
    }

    if (root->getData() > target->getData()) root->setleft(this->delete_element(root->getleft(), target));
    if (root->getData() < target->getData()) root->setright(this->delete_element(root->getright(), target));
    
    return root;
}

template<typename itemType>
node<itemType>* tree<itemType>::insert(node<itemType> *root, node<itemType> *newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (root->getData() > newNode->getData()) root->setleft(this->insert(root->getleft(), newNode));
    else root->setright(this->insert(root->getright(), newNode));

    return root;
}

template<typename itemType>
void tree<itemType>::inorder_helper() {
    this->inorder(this->root);
    cout << endl;
    return;
}

template<typename itemType>
void tree<itemType>::inorder(node<itemType> *root) {
    if (root == nullptr) return;

    this->inorder(root->getleft());
    cout << ' ' << root->getData();
    this->inorder(root->getright());
}

template<typename itemType>
void tree<itemType>::preorder_helper() {
    this->preorder(this->root);
    cout << endl;
    return;
}

template<typename itemType>
void tree<itemType>::preorder(node<itemType> *root) {
    if (root == nullptr) return;

    cout << ' ' << root->getData();
    this->inorder(root->getleft());
    this->inorder(root->getright());
}

template<typename itemType>
void tree<itemType>::postorder_helper() {
    this->postorder(this->root);
    cout << endl;
    return;
}

template<typename itemType>
void tree<itemType>::postorder(node<itemType> *root) {
    if (root == nullptr) return;

    this->inorder(root->getleft());
    this->inorder(root->getright());
    cout << ' ' << root->getData();
}