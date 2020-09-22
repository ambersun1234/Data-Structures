#include <iostream>

using namespace std;

#define struct_list_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

template<typename itemType>
class dlist {
    private:
        node<itemType> *dlist_head;
        int capacity;

    public:
        dlist();
        ~dlist();

        void insert_head(itemType value);
        void insert_tail(itemType value);
        bool insert_after(itemType value, itemType target);
        bool insert_before(itemType value, itemType target);
        void delete_head();
        void delete_tail();
        void travel();
        void delete_target(itemType value);
        void reverse();
        void pairwise();
        void clean();
        node<itemType>* getHead();
        int getCapacity();
};

template<typename itemType>
dlist<itemType>::dlist() {
    this->dlist_head = nullptr;
    this->capacity = 0;
}

template<typename itemType>
node<itemType>* dlist<itemType>::getHead() {
    return this->dlist_head;
}

template<typename itemType>
int dlist<itemType>::getCapacity() {
    return this->capacity;
}

template<typename itemType>
void dlist<itemType>::insert_head(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->dlist_head;

    newNode->setNext(current);
    this->dlist_head = newNode;
    this->capacity += 1;

    return;
}

template<typename itemType>
void dlist<itemType>::insert_tail(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->dlist_head;

    while (current != nullptr && current->getNext() != nullptr) {
        current = current->getNext();
    }
    if (current == nullptr) this->dlist_head = newNode;
    else current->setNext(newNode);

    this->capacity += 1;

    return;
}

#include <iostream>
using namespace std;

template<typename itemType>
bool dlist<itemType>::insert_after(itemType value, itemType target) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->dlist_head;
    node<itemType> *helper = new node<itemType>(target);

    while (current != nullptr && !(*current == *helper)) {
        current = current->getNext();
    }

    if (current == nullptr) return false;
    else {
        node<itemType> *tmp = current->getNext();
        current->setNext(newNode);
        newNode->setNext(tmp);

        this->capacity += 1;
    }

    delete helper;
    return true;
}