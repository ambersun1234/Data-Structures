#define struct_stack_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

template<typename itemType>
class stack {
    private:
        node<itemType> *stack_head;
        int capacity;

    public:
        stack();
        stack(itemType value);
        ~stack();
        void push(itemType value);
        node<itemType>* pop();
        bool isEmpty();
        node<itemType>* peek();
};

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

#ifndef struct_stack_header
    #include "../struct_stack/stack.hpp"
#endif

template<typename itemType>
stack<itemType>::stack() {
    this->stack_head = nullptr;
    this->capacity = 0;
}

template<typename itemType>
stack<itemType>::stack(itemType value) {
    this->stack_head = nullptr;
    this->capacity = 0;
}

template<typename itemType>
stack<itemType>::~stack() {
    node<itemType> *current = this->stack_head;

    while (current != nullptr) {
        node<itemType> *tmp = current->getNext();

        delete current;
        current = tmp;
    }
}

template<typename itemType>
void stack<itemType>::push(itemType value) {
    node<itemType> *newNode = new node<itemType>(value);

    if (this->stack_head == nullptr) {
        (void)0;
    } else {
        node<itemType> *tmp = this->stack_head;
        newNode->setNext(tmp);
    }
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
    if (this->isEmpty()) {
        // empty in stack
        return nullptr;
    } else {
        // can pop from stack
        node<itemType> *tmp = this->stack_head;
        this->stack_head = tmp->getNext();
        this->capacity -= 1;

        return tmp;
    }
}

template<typename itemType>
node<itemType>* stack<itemType>::peek() {
    if (this->isEmpty()) {
        // empty in stack
        return nullptr;
    } else {
        node<itemType> *tmp = this->stack_head;

        return tmp;
    }
}