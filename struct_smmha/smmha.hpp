#define struct_smmha_header

#include "gtest/gtest_prod.h"

template<typename itemType>
class smmha {
    private:
        itemType *tree;
        int length;
        int size;
        int current;

        int getParent(int current);
        int getLeftChild(int current);
        int getRightChild(int current);
        int getSibling(int current);
        int checkWay(int parent, int current);

        FRIEND_TEST(struct_test , getParent); // must be in the same namespace
        FRIEND_TEST(struct_test , getLeftChild); // must be in the same namespace
        FRIEND_TEST(struct_test , getRightChild); // must be in the same namespace
        FRIEND_TEST(struct_test , getSibling); // must be in the same namespace
        FRIEND_TEST(struct_test , checkWay); // must be in the same namespace

    public:
        smmha(int size);
        int getLength();
        int getSize();
        int getCurrent();
};

template<typename itemType>
smmha<itemType>::smmha(int size) {
    this->length = 0;
    this->current = 1;
    this->size = size;
    this->tree = new itemType[this->size + 1]();
}

template<typename itemType>
int smmha<itemType>::getLength() {
    return this->length;
}

template<typename itemType>
int smmha<itemType>::getSize() {
    return this->size;
}

template<typename itemType>
int smmha<itemType>::getCurrent() {
    return this->current;
}

template<typename itemType>
int smmha<itemType>::getParent(int current) {
    return (current - 1) / 2;
}

template<typename itemType>
int smmha<itemType>::getLeftChild(int current) {
    return current * 2 + 1;
}

template<typename itemType>
int smmha<itemType>::getRightChild(int current) {
    return current * 2 + 2;
}

template<typename itemType>
int smmha<itemType>::getSibling(int current) {
    int p = this->getParent(current);
    return this->checkWay(p, current) == 0 ? this->getRightChild(p) : this->getLeftChild(p);
}

template<typename itemType>
int smmha<itemType>::checkWay(int parent, int current) {
    return (this->getLeftChild(parent) == current ? 0 : 1);
    // 0: left child
    // 1: right child
}