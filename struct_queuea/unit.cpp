#include <iostream>
#include <string>

using namespace std;

#ifndef struct_queuea_header
    #include "./queuea.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        queuea<string> *squeuea = new queuea<string>(10);
        queuea<int>    *iqueuea = new queuea<int>(5);
        queuea<double> *dqueuea = new queuea<double>(13);
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(squeuea->getSize(), 10);
    EXPECT_EQ(iqueuea->getSize(), 5);
    EXPECT_EQ(dqueuea->getSize(), 13);

    EXPECT_EQ(squeuea->getFp(), 0);
    EXPECT_TRUE(iqueuea->getFp() == iqueuea->getRp());
    EXPECT_EQ(dqueuea->getFp(), dqueuea->getRp());
    EXPECT_TRUE(iqueuea->isEmpty());
}

TEST_F(struct_test, clean) {
    squeuea->clean();
    EXPECT_EQ(squeuea->getCapacity(), 0);

    iqueuea->enFront(100);
    iqueuea->clean();
    EXPECT_EQ(iqueuea->getRp(), 0);
    EXPECT_EQ(iqueuea->getFp(), 0);
}

TEST_F(struct_test, enFront) {
    squeuea->enFront("hello");
    EXPECT_EQ(squeuea->getFp(), 9);
    squeuea->enFront("world");
    EXPECT_EQ(squeuea->getCapacity(), 2);
    EXPECT_EQ(squeuea->peekRear(), "hello");
    EXPECT_EQ(squeuea->getCapacity(), 2);

    iqueuea->enFront(1);
    iqueuea->enFront(2);
    iqueuea->enFront(3);
    iqueuea->enFront(4);
    iqueuea->enFront(5);
    iqueuea->enFront(6);
    EXPECT_TRUE(iqueuea->isFull());
    EXPECT_EQ(iqueuea->peekFront(), 5);

    dqueuea->clean();
    dqueuea->enFront(2.2);
    EXPECT_EQ(dqueuea->getCapacity(), 1);
    dqueuea->enFront(3.3);
    dqueuea->enFront(4.4);
    dqueuea->enFront(5.5);
    EXPECT_EQ(dqueuea->getFront(), 5.5);
    EXPECT_EQ(dqueuea->getRear(), 2.2);
}

TEST_F(struct_test, getFront) {
    EXPECT_EQ(squeuea->getFront(), "");
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}