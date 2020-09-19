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
    EXPECT_EQ(1, dstack->getCapacity());
}

TEST_F(struct_test, pop) {
    sstack->push("hello");
    sstack->push("world");
    EXPECT_EQ("world", sstack->pop()->getData());
    EXPECT_EQ(1, sstack->getCapacity());
    EXPECT_EQ("hello", sstack->pop()->getData());
    EXPECT_TRUE(nullptr == sstack->pop());

    istack->push(1);
    istack->push(10);
    istack->push(100);
    istack->push(1000);
    EXPECT_NE(2000, istack->pop()->getData());
    EXPECT_NE(nullptr, istack->pop());
    istack->pop();
    EXPECT_EQ(1, istack->pop()->getData());

    dstack->push(1.5);
    dstack->clean();
    EXPECT_EQ(0, dstack->getCapacity());
    EXPECT_EQ(nullptr, dstack->getHead());
    EXPECT_TRUE(nullptr == dstack->pop());
    EXPECT_EQ(0, dstack->getCapacity());
    dstack->push(20.1);
    EXPECT_EQ(1, dstack->getCapacity());
}

TEST_F(struct_test, clean) {
    sstack->clean();
    EXPECT_EQ(sstack->getHead(), nullptr);
    EXPECT_EQ(sstack->getCapacity(), 0);
    
    dstack->clean();
    EXPECT_EQ(dstack->getHead(), nullptr);
    EXPECT_EQ(dstack->getCapacity(), 0);

    istack->clean();
    EXPECT_EQ(istack->getHead(), nullptr);
    EXPECT_EQ(istack->getCapacity(), 0);
}

TEST_F(struct_test, peek) {
    sstack->clean();
    sstack->push("lalaland");
    sstack->push("QQO");
    EXPECT_EQ(sstack->peek()->getData(), "QQO");
    sstack->peek();
    EXPECT_EQ(sstack->getCapacity(), 2);

    dstack->clean();
    dstack->push(20.2);
    dstack->pop();
    EXPECT_EQ(nullptr, dstack->peek());

    istack->push(100);
    istack->clean();
    EXPECT_TRUE(istack->getHead() == nullptr);
    EXPECT_EQ(istack->getCapacity(), 0);
    EXPECT_TRUE(istack->isEmpty());
    istack->push(3);
    EXPECT_EQ(istack->peek()->getData(), 3);
    EXPECT_EQ(istack->getCapacity(), 1);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}