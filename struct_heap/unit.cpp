#include <iostream>
#include <string>

using namespace std;

#ifndef struct_heap_header
    #include "./heap.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        heap<string> *sheap = new heap<string>(1, 10);
        heap<int>    *iheap = new heap<int>(1, 10);
        heap<double> *dheap = new heap<double>(0, 10);
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(sheap->getSize(), 10);
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

TEST_F(struct_test, remove) {
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
}