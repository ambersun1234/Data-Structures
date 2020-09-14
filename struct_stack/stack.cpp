#include <iostream>

using namespace std;

#ifndef struct_node_header
    #include "../struct_node/node.hpp";
#endif

#ifndef struct_stack_header
    #include "../struct_stack/stack.hpp";
#endif

template<typename itemType>
stack<itemType>::stack() {
    this->stack_head = new node<itemType>();
    this->capacity = 1;
}

template<typename itemType>
stack<itemType>::stack(itemType value) {
    this->stack_head = new node<itemType>(value);
    this->capacity = 1;
}

template<typename itemType>
stack<itemType>::~stack() {
    node<itemType> *current = this->stack_head;

    while (current != nullptr) {
        node<itemType> *tmp = current->next;

        delete current;
        current = tmp;
    }
}

template<typename itemType>
void stack<itemType>::push(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *tmp = this->stack_head;

    newNode->next = tmp;
    this->stack_head = newNode;
    this->capacity += 1;

    return;
}

template<typename itemType>
bool stack<itemType>::isEmpty() {
    if (this->capacity == 0 && this->stack_head == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<typename itemType>
node<itemType>* stack<itemType>::pop() {
    if (!this->isEmpty()) {
        // empty in stack
        return nullptr;
    } else {
        // can pop from stack
        node<itemType> *tmp = this->stack_head;
        this->stack_head = tmp->next;
        this->capacity -= 1;

        return tmp;
    }
}

template<typename itemType>
itemType stack<itemType>::peek() {
    if (!this->isEmpty()) {
        // empty in stack
        return nullptr;
    } else {
        itemType tmp = this->stack_head->data;

        return tmp;
    }
}