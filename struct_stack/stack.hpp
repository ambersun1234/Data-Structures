#include <iostream>

using namespace std;

#define struct_stack_header

#ifndef struct_node_header
    #include "../struct_node/node.hpp";
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
        itemType peek();
};