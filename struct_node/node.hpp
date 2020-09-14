#include <iostream>

#define struct_node_header

using namespace std;

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
};