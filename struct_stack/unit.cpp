#include <iostream>
#include <string>

using namespace std;

#ifndef struct_stack_header
    #include "./stack.hpp"
#endif

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        stack<string> *sstack = new stack<string>();
        stack<int>    *istack = new stack<int>();
        stack<double> *dstack = new stack<double>();
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(0, sstack->getCapacity());
    EXPECT_EQ(0, istack->getCapacity());
    EXPECT_EQ(0, dstack->getCapacity());
    EXPECT_TRUE(sstack->getHead() == nullptr);
    EXPECT_TRUE(istack->getHead() == nullptr);
    EXPECT_TRUE(dstack->getHead() == nullptr);
}

TEST_F(struct_test, push) {
    sstack->push("hello");
    sstack->push("world");
    EXPECT_EQ(2, sstack->getCapacity());

    istack->push(1);
    istack->push(10);
    istack->push(100);
    istack->push(1000);
    EXPECT_EQ(4, istack->getCapacity());

    dstack->push(1.5);
    dstack->clean();
    dstack->push(20.1);
    EXPECT_EQ(2, dstack->getCapacity());
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}