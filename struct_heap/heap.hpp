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
        bool legal(int current);

        void heapnessButtomUp(int truePos);
        void heapnessTopDown(int truePos);

    public:
        heap(int type, int size); // 0: max-heap, 1: min-heap
        ~heap();

        bool insert(itemType newValue);
        bool remove();
        void traversal();

        itemType getter(int index);
        int getSize();
        int getCount();
        int getType();
        int getRemoveChild(int current);
        bool isEmpty();
        bool checkHeapness(int current);
        bool isLeaf(int current);
        bool isFull();
};

template<typename itemType>
heap<itemType>::heap(int type, int size) {
    this->root = new itemType[size + 1]();
    this->type = type;
    this->size = size + 1;
    this->count = 0;
}

template<typename itemType>
heap<itemType>::~heap() {
    delete[] this->root;
    this->type = 0;
    this->count = 0;
    this->size = 0;
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
void heap<itemType>::heapnessTopDown(int truePos) {
    int iterator = 1;
    while (iterator <= truePos) {
        bool heapness = this->checkHeapness(iterator);
        if (heapness) return;

        int tmp = this->getRemoveChild(iterator);
        this->swap(iterator, tmp);
        iterator = tmp;
    }
    
    return;
}

template<typename itemType>
void heap<itemType>::heapnessButtomUp(int truePos) {
    int iterator = truePos;
    while (iterator > 1) {
        int parent = this->getParentLocation(iterator);
        if (this->compare(parent, iterator)) {
            this->swap(parent, iterator);
        }
        iterator = parent;
    }
    return;
}

template<typename itemType>
bool heap<itemType>::insert(itemType newValue) {
    if (this->count + 1 >= this->size) return false;

    // insert value
    int truePos = this->count + 1;
    this->root[truePos] = newValue;

    // check if min or max heap
    this->heapnessButtomUp(truePos);

    this->count += 1;
    return true;
}

template<typename itemType>
bool heap<itemType>::remove() {
    this->root[1] = this->root[this->count];
    this->count -= 1;

    // trickle down
    this->heapnessTopDown(this->count);

    return true;
}

template<typename itemType>
itemType heap<itemType>::getter(int index) {
    if (index >= this->size) return this->root[0];
    else return this->root[index];
}

template<typename itemType>
void heap<itemType>::traversal() {
    cout << this->root[1];
    
    for (int i = 2; i < this->size; i++) cout << " " << this->root[i];
    cout << endl;
    return;
}

template<typename itemType>
bool heap<itemType>::compare(int parent, int current) {
    if (current == 0) return false; // means parent only have one or zero child
    if (this->type == 0) return this->root[parent] < this->root[current]; // max-heap
    else return this->root[parent] > this->root[current]; // min-heap
}

template<typename itemType>
bool heap<itemType>::isEmpty() {
    return this->count == 0;
}

template<typename itemType>
bool heap<itemType>::isFull() {
    return (this->count + 1) == this->size;
}

template<typename itemType>
bool heap<itemType>::legal(int current) {
    if (current >= this->count) return false;
    return true;
}

template<typename itemType>
bool heap<itemType>::checkHeapness(int current) {
    int left = this->getLeftChildrenLocation(current);
    int right = this->getRightChildrenLocation(current);

    bool fleft = this->legal(left) ? this->compare(current, left) : false;
    bool fright = this->legal(right) ? this->compare(current, right) : false;

    if (fleft || fright) return false;
    else return true;
}

template<typename itemType>
int heap<itemType>::getRemoveChild(int current) {
    int left = this->getLeftChildrenLocation(current);
    int right = this->getRightChildrenLocation(current);

    if (this->type == 0) return (this->root[left] > this->root[right] ? left : right);
    else  return (this->root[left] < this->root[right] ? left : right);
}

template<typename itemType>
bool heap<itemType>::isLeaf(int current) {
    int left = this->getLeftChildrenLocation(current);
    int right = this->getRightChildrenLocation(current);

    // if (left > this->count && right > this->count) return true;
    if (!this->legal(left) && !this->legal(right)) return true;
    else return false;
}

template<typename itemType>
int heap<itemType>::getSize() {
    return this->size - 1;
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
