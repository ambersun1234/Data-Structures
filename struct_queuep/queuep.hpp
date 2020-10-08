#include <iostream>
#include <functional>

using namespace std;

#define struct_queuep_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

template<typename itemType>
class queuep {
    private:
        node<itemType> *queue_head;
        node<itemType> *queue_tail;
        int capacity;

        function<int(itemType, itemType)> callback = nullptr;

    private:
        void set2nullptr();
        void set2circular();

    public:
        queuep();
        ~queuep();

        bool isEmpty();
        void clean();
        void insert(itemType value);
        void travel();
        bool delete_target(itemType value);
        int find(itemType value);

        node<itemType>* getHead();
        node<itemType>* getTail();
        int getCapacity();

        void setFunctionPointer(function<int(itemType, itemType)> callback);
};

template<typename itemType>
queuep<itemType>::queuep() {
    this->queue_head = nullptr;
    this->queue_tail = nullptr;
    this->capacity = 0;
}

template<typename itemType>
queuep<itemType>::~queuep() {
    this->clean();
}

template<typename itemType>
void queuep<itemType>::setFunctionPointer(function<int(itemType, itemType)> callback) {
    this->callback = callback;
}

template<typename itemType>
void queuep<itemType>::travel() {
    node<itemType> *current = this->queue_head;

    if (current == nullptr) return;
    cout << current << ' ' << current->getData() << endl;
    current = current->getNext();

    while (current != this->queue_head) {
        cout << current << ' ' << current->getData() << endl;
        current = current->getNext();
    }

    return;
}

template<typename itemType>
bool queuep<itemType>::isEmpty() {
    return this->capacity == 0;
}

template<typename itemType>
void queuep<itemType>::set2nullptr() {
    if (this->queue_tail != nullptr) this->queue_tail->setNext(nullptr);
    return;
}

template<typename itemType>
void queuep<itemType>::set2circular() {
    if (this->queue_tail != nullptr) this->queue_tail->setNext(this->queue_head);
    return;
}

template<typename itemType>
void queuep<itemType>::insert(itemType value) {
    if (this->callback == nullptr) {
        cout << "WARNING: compare function not set" << endl;
        return;
    }

    node<itemType> *newNode = new node<itemType>(value);
    node<itemType> *current = this->queue_head;
    node<itemType> *previous = nullptr;
    
    // set tail next to nullptr for convience
    this->set2nullptr();

    while (current != nullptr && this->callback(current->getData(), newNode->getData()) < 0) {
        previous = current;
        current = current->getNext();
    }
    
    if (previous == nullptr && current == nullptr) {
        this->queue_head = newNode;
        this->queue_tail = newNode;
        newNode->setNext(newNode);
    }
    else if (previous == nullptr) {
        this->queue_head = newNode;
    }
    else {
        previous->setNext(newNode);
    }
    newNode->setNext(current);

    //-----------
    if (current == nullptr) {
        this->queue_tail = newNode;
    }
    // store back queue_tail
    this->set2circular();

    this->capacity += 1;

    return;
}

template<typename itemType>
int queuep<itemType>::find(itemType value) {
    node<itemType> *helper = new node<itemType>(value);
    node<itemType> *current = this->queue_head;
    bool flag = false;
    int counter = 0;

    this->set2nullptr();
    while (current != nullptr) {
        flag = (*current == *helper);
        if (flag) break;
        current = current->getNext();
        counter += 1;
    }
    this->set2circular();

    delete helper; 

    return (flag ? counter : -1);
}

template<typename itemType>
bool queuep<itemType>::delete_target(itemType value) {
    node<itemType> *helper = new node<itemType>(value);
    node<itemType> *previous = this->queue_tail;
    node<itemType> *current = this->queue_head;
    bool flag = false;

    this->set2nullptr();
    while (current != nullptr) {
        flag = (*current == *helper);
        if (flag) break;
        previous = current;
        current = current->getNext();
    }
    this->set2circular();

    // only if previous == tail, head = current->getNext()
    // only if current == tail, tail = previous
    if (flag) {
        previous->setNext(current->getNext());

        if (previous == this->queue_tail) this->queue_head = current->getNext();
        if (current == this->queue_tail) this->queue_tail = previous;

        delete current;

        this->capacity -= 1;
    }

    if (this->capacity == 0) {
        this->queue_head = this->queue_tail = nullptr;
    }

    return flag;
}

template<typename itemType>
void queuep<itemType>::clean() {
    node<itemType> *current = this->queue_head;
    node<itemType> *tmp = nullptr;

    if (this->queue_tail != nullptr) {
        this->queue_tail->setNext(nullptr);
    }

    while (current != nullptr) {
        tmp = current->getNext();

        delete current;
        current = tmp;
    }

    this->queue_head = nullptr;
    this->queue_tail = nullptr;
    this->capacity = 0;

    return;
}

template<typename itemType>
node<itemType>* queuep<itemType>::getHead() {
    return this->queue_head;
}

template<typename itemType>
node<itemType>* queuep<itemType>::getTail() {
    return this->queue_tail;
}

template<typename itemType>
int queuep<itemType>::getCapacity() {
    return this->capacity;
}