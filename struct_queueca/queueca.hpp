#include <iostream>

using namespace std;

#define struct_queueca_header

template<typename itemType>
class queueca {
    private:
        itemType *root;
        int size;
        int count;
        int front;
        int rear;

        int bound(int index);

        void increaseRear();
        void increaseFront();
        void decreaseRear();
        void decreaseFront();

    public:
        queueca(int size);
        ~queueca();

        // bool enFront(itemType value);
        bool enRear(itemType value);

        bool removeFront();
        // bool removeRear();

        itemType getter(int index);
        int getCount();
        int getSize();
        int getFrontIndex();
        int getRearIndex();
        bool isEmpty();
        bool isFull();
};

template<typename itemType>
queueca<itemType>::queueca(int size) {
    this->root = new itemType[size]();
    this->size = size;
    this->count = 0;
    this->front = 0;
    this->rear = 0;
}

template<typename itemType>
queueca<itemType>::~queueca() {
    delete[] this->root;
    this->root = nullptr;

    this->size = 0;
    this->count = 0;
    this->front = 0;
    this->rear = 0;
}

template<typename itemType>
bool queueca<itemType>::isEmpty() {
    return this->count == 0;
}

template<typename itemType>
bool queueca<itemType>::isFull() {
    return this->count == this->size;
}

template<typename itemType>
itemType queueca<itemType>::getter(int index) {
    return this->root[index];
}

template<typename itemType>
void queueca<itemType>::increaseFront() {
    this->front += 1;
    this->front = this->bound(this->front);
    return;
}

template<typename itemType>
void queueca<itemType>::increaseRear() {
    this->rear += 1;
    this->rear = this->bound(this->rear);
    return;
}

template<typename itemType>
void queueca<itemType>::decreaseFront() {
    this->front -= 1;
    this->front = this->bound(this->front);
    return;
}

template<typename itemType>
void queueca<itemType>::decreaseRear() {
    this->rear -= 1;
    this->rear = this->bound(this->rear);
    return;
}

template<typename itemType>
int queueca<itemType>::bound(int index) {
    if (index >= this->size) index = 0;
    if (index < 0) index = this->size - 1;

    return index;
}

template<typename itemType>
bool queueca<itemType>::enRear(itemType value) {
    if (this->count >= this->size) return false;

    this->root[this->rear] = value;
    this->increaseRear();
    this->count += 1;
    return true;
}

// template<typename itemType>
// bool queueca<itemType>::enFront(itemType value) {
//     if (this->count >= this->size) return false;

//     this->root[this->front] = value;
//     this->increaseFront();
//     this->count += 1;
//     return true;
// }

template<typename itemType>
bool queueca<itemType>::removeFront() {
    if (this->count < 0) return false;

    this->decreaseFront();
    this->count -= 1;
    return true;
}

// template<typename itemType>
// bool queueca<itemType>::removeRear() {
//     if (this->count < 0) return false;

//     this->decreaseRear();
//     this->count -= 1;
//     return true;
// }

template<typename itemType>
int queueca<itemType>::getCount() {
    return this->count;
}

template<typename itemType>
int queueca<itemType>::getSize() {
    return this->size;
}

template<typename itemType>
int queueca<itemType>::getFrontIndex() {
    return this->front;
}

template<typename itemType>
int queueca<itemType>::getRearIndex() {
    return this->rear;
}