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

    public:
        queuep();
        ~queuep();

        void clean();

        node<itemType>* getHead();
        node<itemType>* getTail();
        int getCapacity();
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
void queuep<itemType>::clean() {
    node<itemType> *current = this->queue_head;
    node<itemType> *tmp = nullptr;

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