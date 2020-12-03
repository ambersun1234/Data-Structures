#include <iostream>

using namespace std;

#define struct_queuec_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

/*
 * implement circular queue with doubly linked list
 */

template<typename itemType>
class queue {
    private:
        node<itemType> *queue_head;
        node<itemType> *queue_tail;
        int capacity;

    public:
        queue();
        ~queue();

        node<itemType>* getHead();
        node<itemType>* getTail();
        int getCapacity();

        itemType front();
        itemType rear();
        void enqueue(itemType value);
        void dequeue();
        void clean();
        bool isEmpty();
        void travel();
        void reverse();
};

template<typename itemType>
queue<itemType>::queue() {
    this->queue_head = nullptr;
    this->queue_tail = nullptr;
    this->capacity = 0;
}

template<typename itemType>
node<itemType>* queue<itemType>::getHead() {
    return this->queue_head;
}

template<typename itemType>
node<itemType>* queue<itemType>::getTail() {
    return this->queue_tail;
}

template<typename itemType>
int queue<itemType>::getCapacity() {
    return this->capacity;
}

template<typename itemType>
void queue<itemType>::clean() {
    if (this->isEmpty()) return;

    node<itemType> *current = this->queue_head;
    current->getPrevious()->setNext(nullptr);

    while (current != nullptr) {
        node<itemType> *tmp = current;
        current = current->getNext();

        delete tmp;
    }

    this->queue_head = nullptr;
    this->queue_tail = nullptr;
    this->capacity = 0;
    return;
}

template<typename itemType>
void queue<itemType>::reverse() {
    if (this->isEmpty()) return;

    node<itemType> *current = this->queue_head;
    node<itemType> *backup = nullptr;
    node<itemType> *backupNext = nullptr;

    while (true) {
        node<itemType> *tmp = nullptr;
        backup = current;
        backupNext = current->getNext();

        tmp = current->getNext();
        current->setNext(current->getPrevious());
        current->setPrevious(tmp);

        /* if backupNext is origin head
         * which means backup is origin tail
         * which will next become reverse head
         */
        if (backupNext == this->queue_head) break;
        current = backupNext;
    }

    // currently variable current is at old this->queue_tail position
    this->queue_tail = backupNext;
    this->queue_head = backup;
    return;
}

template<typename itemType>
void queue<itemType>::travel() {
    if (this->isEmpty()) return;
    
    node<itemType> *current = this->queue_head;
    cout << current->getData();
    current = current->getNext();

    while (current != this->queue_head) {
        cout << ' ' << current->getData();
        current = current->getNext();
    }
    return;
}

template<typename itemType>
itemType queue<itemType>::front() {
    return this->queue_head->getData();
}

template<typename itemType>
itemType queue<itemType>::rear() {
    return this->queue_tail->getData();
}

template<typename itemType>
bool queue<itemType>::isEmpty() {
    return this->queue_head == nullptr && this->queue_tail == nullptr && this->capacity == 0;
}

template<typename itemType>
void queue<itemType>::enqueue(itemType value) {
    // enqueue insert at rear position
    node<itemType> *newNode = new node<itemType>(value);

    if (this->isEmpty()) {
        // queue is empty
        newNode->setNext(newNode);
        newNode->setPrevious(newNode);

        this->queue_head = newNode;
        this->queue_tail = newNode;
        this->capacity += 1;
    } else {
        this->queue_tail->setNext(newNode);
        newNode->setPrevious(this->queue_tail);
        newNode->setNext(this->queue_head);

        this->queue_tail = newNode;
        this->queue_head->setPrevious(this->queue_tail);
        this->capacity += 1;
    }
}
#include <iostream>
using namespace std;
template<typename itemType>
void queue<itemType>::dequeue() {
    // dequeue at front position
    if (this->isEmpty()) return;
    else {
        node<itemType> *headNext = this->queue_head->getNext();
        this->queue_tail->setNext(headNext);
        headNext->setPrevious(this->queue_tail);

        node<itemType> *tmp = this->queue_head;
        delete tmp;

        this->queue_head = headNext;
        this->capacity -= 1;

        if (this->queue_head == this->queue_tail && 
            this->queue_head != nullptr &&
            this->capacity == 0) {
            // no element left
            this->queue_head = nullptr;
            this->queue_tail = nullptr;
        }
        return;
    }
}