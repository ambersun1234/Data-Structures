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
    EXPECT_TRUE(sheap->getCount() == 0);

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
}