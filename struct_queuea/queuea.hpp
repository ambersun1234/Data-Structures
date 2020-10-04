#include <iostream>
#include <string>
#include <cxxabi.h>

using namespace std;

#define struct_queuea_header

template<typename itemType>
class queuea {
    private:
        itemType *queue;
        int capacity;
        int front_pos, rear_pos;
        int size;

    public:
        queuea(int size);
        ~queuea();

        bool isFull();
        bool isEmpty();

        int getFp();
        int getRp();

        bool enFront(itemType value);
        bool enRear(itemType value);
        itemType getFront();
        itemType getRear();
        itemType peekFront();
        itemType peekRear();
        int getSize();
        int getCapacity();

        void adjust_position();

        void clean();

    private:
        string get_current_template_type();
};

template<typename itemType>
queuea<itemType>::queuea(int size) {
    this->queue = new itemType[size];
    this->size = size;
    this->front_pos = 0;
    this->rear_pos = 0;
}

template<typename itemType>
queuea<itemType>::~queuea() {
    delete[] this->queue;
}

template<typename itemType>
void queuea<itemType>::clean() {
    delete[] this->queue;
    this->queue = new itemType[this->size];

    this->capacity = 0;
    this->front_pos = 0;
    this->rear_pos = 0;
}

template<typename itemType>
int queuea<itemType>::getCapacity() {
    return this->capacity;
}

template<typename itemType>
int queuea<itemType>::getSize() {
    return this->size;
}

template<typename itemType>
int queuea<itemType>::getFp() {
    return this->front_pos;
}

template<typename itemType>
int queuea<itemType>::getRp() {
    return this->rear_pos;
}

template<typename itemType>
bool queuea<itemType>::isEmpty() {
    return this->capacity == 0;
}

template<typename itemType>
bool queuea<itemType>::isFull() {
    return this->size == this->capacity;
}

template<typename itemType>
itemType queuea<itemType>::peekFront() {
    int tmp = this->front_pos;
    return this->queue[tmp];
}

template<typename itemType>
itemType queuea<itemType>::peekRear() {
    int tmp = this->rear_pos;
    return this->queue[tmp];
}

template<typename itemType>
itemType queuea<itemType>::getFront() {
    itemType result = this->peekFront();
    if (this->capacity == 0) return result;

    this->front_pos += 1;
    this->capacity -= 1;
    
    this->adjust_position();

    return result;
}

template<typename itemType>
itemType queuea<itemType>::getRear() {
    itemType result = this->peekRear();
    if (this->capacity == 0) return result;

    this->rear_pos -= 1;
    this->capacity -= 1;

    this->adjust_position();
    
    return result;
}

template<typename itemType>
bool queuea<itemType>::enFront(itemType value) {
    if (this->isFull()) return false;

    this->front_pos = this->front_pos - 1;

    this->adjust_position();

    this->queue[this->front_pos] = value;

    if (this->capacity == 0) {
        this->rear_pos = this->front_pos;
    }
    
    this->capacity += 1;

    return true;
}

template<typename itemType>
bool queuea<itemType>::enRear(itemType value) {
    if (this->isFull()) return false;

    this->rear_pos = this->rear_pos + 1;

    this->adjust_position();

    this->queue[this->rear_pos] = value;

    if (this->capacity == 0) {
        this->front_pos = this->rear_pos;
    }
    
    this->capacity += 1;

    return true;
}

template<typename itemType>
void queuea<itemType>::adjust_position() {
    if (this->front_pos < 0) this->front_pos = this->size - 1;
    else if (abs(this->front_pos) + 1 > this->size) this->front_pos = 0;

    if (this->rear_pos < 0) this->rear_pos = this->size - 1;
    else if (abs(this->rear_pos) + 1 > this->size) this->rear_pos = 0;

    return;
}

template<typename itemType>
string queuea<itemType>::get_current_template_type() {
    string tname = typeid(itemType).name();
    int status;
    char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);

    if (status == 0) {
        tname = demangled_name;
        delete demangled_name;
    }
    return tname;
}