#include <iostream>

using namespace std;

#define struct_list_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

template<typename itemType>
class list {
    private:
        node<itemType> *list_head;
        int capacity;

    public:
        list();
        ~list();

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
        node<itemType>* searchElement(itemType value);
        void clean();
        node<itemType>* getHead();
        int getCapacity();
};

template<typename itemType>
list<itemType>::list() {
    this->list_head = nullptr;
    this->capacity = 0;
}

template<typename itemType>
node<itemType>* list<itemType>::getHead() {
    return this->list_head;
}

template<typename itemType>
int list<itemType>::getCapacity() {
    return this->capacity;
}

template<typename itemType>
void list<itemType>::insert_head(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->list_head;

    newNode->setNext(current);
    this->list_head = newNode;
    this->capacity += 1;

    return;
}

template<typename itemType>
void list<itemType>::insert_tail(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->list_head;

    while (current != nullptr && current->getNext() != nullptr) {
        current = current->getNext();
    }
    if (current == nullptr) this->list_head = newNode;
    else current->setNext(newNode);

    this->capacity += 1;

    return;
}

template<typename itemType>
bool list<itemType>::insert_after(itemType value, itemType target) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->list_head;
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

template<typename itemType>
bool list<itemType>::insert_before(itemType value, itemType target) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->list_head;
    node<itemType> *previous = nullptr;
    node<itemType> *helper = new node<itemType>(target);

    while (current != nullptr && !(*current == *helper)) {
        previous = current;
        current = current->getNext();
    }

    if (current == nullptr) return false;
    else if (previous == nullptr) {
        newNode->setNext(current);
        this->list_head = newNode;

        this->capacity += 1;
    }
    else {
        node<itemType> *tmp = previous->getNext();
        previous->setNext(newNode);
        newNode->setNext(tmp);

        this->capacity += 1;
    }

    delete helper;
    return true;
}

template<typename itemType>
void list<itemType>::travel() {
    if (this->list_head == nullptr) {
        return;
    }

    node<itemType> *current = this->list_head->getNext();
    cout << this->list_head->getData();

    while (current != nullptr) {
        cout << ' ' << current->getData();
        current = current->getNext();
    }
    cout << endl;
    return;
}

template<typename itemType>
void list<itemType>::delete_head() {
    node<itemType> *head = this->list_head;

    if (this->list_head != nullptr) {
        this->list_head = this->list_head->getNext();
        this->capacity -= 1;
    }
    else {
        this->list_head = nullptr;
    }

    delete head;
    return;
}

template<typename itemType>
void list<itemType>::delete_tail() {
    node<itemType> *current = this->list_head;
    node<itemType> *previous = nullptr;

    while (current != nullptr && current->getNext() != nullptr) {
        previous = current;
        current = current->getNext();
    }

    if (current == nullptr) return;
    else if (previous == nullptr) {
        delete current;
        this->list_head = nullptr;
        this->capacity = 0;
    }
    else {
        previous->setNext(current->getNext());
        this->capacity -= 1;
    }
    return;
}

template<typename itemType>
node<itemType>* list<itemType>::searchElement(itemType value) {
    node<itemType> *current = this->list_head;
    node<itemType> *helper = new node<itemType>(value);

    while (current != nullptr) {
        if (*current == *helper) {
            break;
        }
        current = current->getNext();
    }

    delete helper;

    return current;
}

template<typename itemType>
void list<itemType>::delete_target(itemType value) {
    node<itemType> *target_node = this->searchElement(value);

    if (target_node == nullptr) return;

    node<itemType> **indirect = &this->list_head;
    while ((*indirect) != target_node) {
        node<itemType> *tmp = ((*indirect)->getNext());
        indirect = &tmp;
    }
    this->capacity -= 1;

    (*indirect) = target_node->getNext();
    delete target_node;

    return;
}

template<typename itemType>
void list<itemType>::reverse() {
    node<itemType> *current = this->list_head;
    node<itemType> *previous = nullptr;

    while (current != nullptr) {
        node<itemType> *tmp = current->getNext();

        current->setNext(previous);
        previous = current;
        current = tmp;
    }
    this->list_head = previous;
    return;
}

template<typename itemType>
void list<itemType>::pairwise() {
    node<itemType> *current = this->list_head;

    while (current != nullptr && current->getNext() != nullptr) {
        itemType value1 = current->getData();
        current->setData(current->getNext()->getData());
        current->getNext()->setData(value1);

        current = current->getNext()->getNext();
    }

    return;
}

template<typename itemType>
void list<itemType>::clean() {
    node<itemType> *current = this->list_head;

    while (current != nullptr) {
        node<itemType> *tmp = current->getNext();

        delete current;

        current = tmp;
    }
    this->capacity = 0;
    this->list_head = nullptr;

    return;
}