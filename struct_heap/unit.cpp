#include <iostream>
#include <string>

using namespace std;

#ifndef struct_heap_header
    #include "./heap.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        heap<string> *sheap = new heap<string>(0, 10);
        heap<int>    *iheap = new heap<int>(1, 10);
        heap<double> *dheap = new heap<double>(0, 10);
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(sheap->getSize(), 10);
    EXPECT_EQ(sheap->getType(), 0);

    EXPECT_EQ(iheap->getType(), 1);
    EXPECT_TRUE(sheap->getCount() == 0);

    EXPECT_TRUE(dheap->getType() == sheap->getType());
}
