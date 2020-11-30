#include <iostream>

using namespace std;

#define struct_heap_header

template<typename itemType>
class heap {
    private:
        itemType *root; // use location 1~n array only
        int type;
        int size;
        int count;

        bool compare(int parent, int current);
        int getParentLocation(int current);
        int getLeftChildrenLocation(int current);
        int getRightChildrenLocation(int current);
        bool swap(int parent, int current);

    public:
        heap(int type, int size); // 0: max-heap, 1: min-heap

        bool insert(itemType newValue);

        int getSize();
        int getCount();
        int getType();
};

template<typename itemType>
heap<itemType>::heap(int type, int size) {
    this->root = new itemType[size];
    this->type = type;
    this->size = size;
    this->count = 0;
}

template<typename itemType>
bool heap<itemType>::swap(int parent, int current) {
    itemType tmp;
    tmp = this->root[parent];
    this->root[parent] = this->root[current];
    this->root[current] = tmp;

    return true;
}

template<typename itemType>
bool heap<itemType>::insert(itemType newValue) {
    if (count > size) return false;

    // insert value
    this->root[this->current] = newValue;

    // check if min or max heap
    int iterator = this->current;
    while (iterator > 0) {
        int parent = this->getParentLocation(iterator);
        if (this->compare(parent, iterator)) {
            this->swap(parent, iterator);
        }
        iterator = this->getParentLocation(iterator);
    }

    this->current += 1;
    return true;
}

template<typename itemType>
bool heap<itemType>::compare(int parent, int current) {
    if (this->type == 0) return this->root[current] > this->root[parent];
    else return this->root[parent] < this->root[current];
}

template<typename itemType>
int heap<itemType>::getSize() {
    return this->size;
}

template<typename itemType>
int heap<itemType>::getCount() {
    return this->count;
}

template<typename itemType>
int heap<itemType>::getType() {
    return this->type;
}

template<typename itemType>
int heap<itemType>::getParentLocation(int current) {
    return int(current / 2);
}

template<typename itemType>
int heap<itemType>::getLeftChildrenLocation(int current) {
    return current * 2;
}

template<typename itemType>
int heap<itemType>::getRightChildrenLocation(int current) {
    return current * 2 + 1;
}
