#include <iostream>
#include <string>

using namespace std;

#ifndef struct_heap_header
    #include "./heap.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        heap<string> *sheap = new heap<string>(1, 15); // min heap
        heap<int>    *iheap = new heap<int>(1, 10); // min heap
        heap<double> *dheap = new heap<double>(0, 10); // max heap
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(sheap->getSize(), 15);
    EXPECT_EQ(sheap->getType(), 1);
    EXPECT_TRUE(!sheap->isFull());

    EXPECT_EQ(iheap->getType(), 1);
    EXPECT_TRUE(iheap->getCount() == 0);
    EXPECT_EQ(iheap->isLeaf(1), true);

    EXPECT_TRUE(dheap->getType() == 0);
    EXPECT_TRUE(dheap->isEmpty());
}

TEST_F(struct_test, insert) {
    sheap->insert("a");
    sheap->insert("b");
    sheap->insert("c");
    sheap->insert("d");
    sheap->insert("e");
    EXPECT_EQ(sheap->getter(5), "e");
    EXPECT_EQ(sheap->getter(1), "a");
    EXPECT_EQ(sheap->getter(3), "c");

    for (int i = 10; i > 0; i--) {
        iheap->insert(i);
    }
    EXPECT_EQ(iheap->insert(11), false);
    EXPECT_EQ(iheap->getter(9), 7);
    EXPECT_EQ(iheap->getter(10), 8);
    EXPECT_EQ(iheap->getter(5), 3);
    EXPECT_EQ(iheap->getCount(), 10);
    EXPECT_TRUE(!iheap->isLeaf(1));

    for (int i = 10; i > 0; i--) {
        double tmp = 1.1 * (double)i;
        dheap->insert(tmp);
    }
    EXPECT_DOUBLE_EQ(dheap->getter(9), 2.2);
    EXPECT_DOUBLE_EQ(dheap->getter(10), 1.1);
    EXPECT_DOUBLE_EQ(dheap->getter(5), 6.6);
    EXPECT_EQ(dheap->getCount(), 10);
}

TEST_F(struct_test, getCount) {
    EXPECT_EQ(sheap->getCount(), 0);
    for (char i = 'a'; i < 'z'; i++) {
        string tmp;
        tmp += i;
        sheap->insert(tmp);
    }
    EXPECT_EQ(sheap->getCount(), sheap->getSize());

    for (int i = 0; i < 10; i++) {
        iheap->insert(i);
        EXPECT_EQ(iheap->getCount(), i + 1);
    }

    for (int i = 0; i < 10; i++) {
        double tmp = 1.1 * i;
        dheap->insert(tmp);
        EXPECT_EQ(dheap->getCount(), i + 1);
    }
    for (int i = 9; i >= 0; i--) {
        dheap->remove();
        EXPECT_EQ(dheap->getCount(), i);
    }
}

TEST_F(struct_test, isLeaf) {
    for (char i = 'a'; i < 'l'; i++) {
        string tmp;
        tmp += i;
        sheap->insert(tmp);
    }
    for (int i = 1; i < 6; i++) EXPECT_TRUE(!sheap->isLeaf(i));
    for (int i = 6; i < sheap->getSize(); i++) EXPECT_TRUE(sheap->isLeaf(i));

    for (int i = 1; i < iheap->getSize(); i++) EXPECT_EQ(iheap->isLeaf(i), true);
    EXPECT_TRUE(iheap->isEmpty());
    EXPECT_TRUE(!iheap->isFull());
}

TEST_F(struct_test, isEmpty) {
    EXPECT_TRUE(sheap->isEmpty());
    for (char i = 'a'; i < 'p'; i++) {
        string tmp;
        tmp += i;
        sheap->insert(tmp);
        EXPECT_EQ(sheap->isEmpty(), false);
    }
    EXPECT_EQ(sheap->isEmpty(), false);
}

TEST_F(struct_test, isFull) {
    EXPECT_TRUE(!dheap->isFull());
    for (double i = 1; i < 10; i++) {
        dheap->insert(i);
        EXPECT_EQ(dheap->isFull(), false);
    }
    dheap->insert(10.0);
    EXPECT_EQ(dheap->isFull(), true);
}

TEST_F(struct_test, getter) {
    for (char i = 'a'; i < 'l'; i++) {
        string tmp;
        tmp += i;
        sheap->insert(tmp);
    }
    EXPECT_EQ(sheap->getter(10), "j");
    EXPECT_EQ(sheap->getter(11), "k");
    sheap->remove();
    EXPECT_EQ(sheap->getter(1), "b");
    EXPECT_EQ(sheap->getter(2), "d");
    EXPECT_EQ(sheap->getter(3), "c");
    EXPECT_EQ(sheap->getter(4), "h");
    EXPECT_EQ(sheap->getter(5), "e");
    EXPECT_EQ(sheap->getter(6), "f");
    EXPECT_EQ(sheap->getter(7), "g");
    EXPECT_EQ(sheap->getter(8), "k");
    EXPECT_EQ(sheap->getter(9), "i");
    EXPECT_EQ(sheap->getter(10), "j");
}

TEST_F(struct_test, remove) {
    for (char i = 'a'; i < 'l'; i++) {
        string tmp;
        tmp += i;
        sheap->insert(tmp);
    }
    EXPECT_EQ(sheap->getter(10), "j");
    EXPECT_EQ(sheap->getter(11), "k");
    sheap->remove();
    EXPECT_EQ(sheap->getter(1), "b");
    EXPECT_EQ(sheap->getter(2), "d");
    EXPECT_EQ(sheap->getter(3), "c");
    EXPECT_EQ(sheap->getter(4), "h");
    EXPECT_EQ(sheap->getter(5), "e");
    EXPECT_EQ(sheap->getter(6), "f");
    EXPECT_EQ(sheap->getter(7), "g");
    EXPECT_EQ(sheap->getter(8), "k");
    EXPECT_EQ(sheap->getter(9), "i");
    EXPECT_EQ(sheap->getter(10), "j");

    for (int i = 10; i > 0; i--) {
        iheap->insert(i);
    }
    EXPECT_EQ(iheap->getter(9), 7);
    EXPECT_EQ(iheap->getter(10), 8);
    EXPECT_EQ(iheap->getter(5), 3);
    EXPECT_EQ(iheap->getCount(), 10);
    iheap->remove();
    EXPECT_EQ(iheap->getter(1), 2);
    EXPECT_EQ(iheap->getter(2), 3);
    EXPECT_EQ(iheap->getter(5), 8);
    EXPECT_EQ(iheap->getter(9), 7);
}