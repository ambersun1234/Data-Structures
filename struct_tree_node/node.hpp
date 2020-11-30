#define struct_treenode_header

template<typename itemType>
class node {
    private:
        itemType data;
        node<itemType> *left;
        node<itemType> *right;

    public:
        node(itemType input);
        ~node();
        void setData(itemType value);
        itemType getData();
        node<itemType>* getleft();
        node<itemType>* getright();
        void setright(node<itemType>* tmp);
        void setleft(node<itemType>* tmp);
};

template<typename itemType>
node<itemType>::node(itemType input) {
    this->data = input;
    this->right = nullptr;
    this->left = nullptr;
}

template<typename itemType>
node<itemType>::~node() {
    this->right = nullptr;
    this->left = nullptr;
}

template<typename itemType>
itemType node<itemType>::getData() {
    return this->data;
}

template<typename itemType>
void node<itemType>::setData(itemType value) {
    this->data = value;
}

template<typename itemType>
node<itemType>* node<itemType>::getleft() {
    return this->left;
}

template<typename itemType>
node<itemType>* node<itemType>::getright() {
    return this->right;
}

template<typename itemType>
void node<itemType>::setleft(node<itemType>* tmp) {
    this->left = tmp;
}

template<typename itemType>
void node<itemType>::setright(node<itemType>* tmp) {
    this->right = tmp;
}
