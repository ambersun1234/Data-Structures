#define struct_node_header

template<typename itemType>
class node {
    private:
        itemType data;
        node<itemType> *next;
        node<itemType> *previous;
        node<itemType> *head;
        node<itemType> *tail;

    public:
        node();
        node(itemType input);
        ~node();
        itemType getData();
        node<itemType>* getPrevious();
        node<itemType>* getNext();
        void setNext(node<itemType>*);
        void setPrevious(node<itemType>*);
};

template<typename itemType>
node<itemType>::node() {
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
    this->next = nullptr;
    this->previous = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename itemType>
itemType node<itemType>::getData() {
    return this->data;
}

template<typename itemType>
node<itemType>* node<itemType>::getPrevious() {
    return this->previous;
}

template<typename itemType>
node<itemType>* node<itemType>::getNext() {
    return this->next;
}

template<typename itemType>
void node<itemType>::setPrevious(node<itemType>* tmp) {
    this->previous = tmp;
}

template<typename itemType>
void node<itemType>::setNext(node<itemType>* tmp) {
    this->next = tmp;
}