#include <iostream>

#ifndef struct_node_header
    #include "node.hpp"
#endif

using namespace std;

template<typename itemType>
node<itemType>::node() {
    this->data = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename itemType>
node<itemType>::node(itemType input) {
    this->data = input;
    this->next = nullptr;
    this->previous = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename itemType>
node<itemType>::~node() {
    this->data = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
}