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
    squeuea->enFront("lala");
    EXPECT_EQ(squeuea->isEmpty(), false);
    squeuea->enFront("lalaland");
    squeuea->enFront("aa");
    squeuea->enFront("bb");
    EXPECT_EQ(squeuea->getFront(), "bb");
    EXPECT_EQ(squeuea->getCapacity(), 3);

    iqueuea->enRear(10);
    iqueuea->enRear(20);
    iqueuea->enRear(30);
    iqueuea->enRear(40);
    iqueuea->enRear(50);
    EXPECT_EQ(iqueuea->getCapacity(), 5);
    EXPECT_EQ(iqueuea->getFront(), 10);
    EXPECT_EQ(iqueuea->getCapacity(), 4);
    EXPECT_EQ(iqueuea->getFront(), 20);
    EXPECT_EQ(iqueuea->getCapacity(), 3);
    EXPECT_EQ(iqueuea->getFront(), 30);
    EXPECT_EQ(iqueuea->getCapacity(), 2);
    EXPECT_EQ(iqueuea->getFront(), 40);
    EXPECT_EQ(iqueuea->getCapacity(), 1);
    EXPECT_EQ(iqueuea->getFront(), 50);
    EXPECT_TRUE(iqueuea->isEmpty());

    dqueuea->enFront(1.1);
    EXPECT_EQ(dqueuea->getCapacity(), 1);
    EXPECT_EQ(dqueuea->getFront(), 1.1);
    EXPECT_EQ(dqueuea->getCapacity(), 0);
    dqueuea->clean();
    dqueuea->enFront(2.2);
    EXPECT_EQ(dqueuea->peekFront(), 2.2);
    EXPECT_EQ(dqueuea->getCapacity(), 1);
}

TEST_F(struct_test, enRear) {
    squeuea->enRear("hello");
    squeuea->enRear("world");
    EXPECT_EQ(squeuea->peekFront(), "hello");
    EXPECT_EQ(squeuea->getCapacity(), 2);

    EXPECT_TRUE(iqueuea->isEmpty());
    iqueuea->enFront(10);
    iqueuea->enRear(20);
    iqueuea->enRear(30);
    iqueuea->enRear(40);
    iqueuea->enFront(50);
    iqueuea->enRear(210);
    EXPECT_EQ(iqueuea->getCapacity(), iqueuea->getSize());
    EXPECT_TRUE(iqueuea->isFull());
    EXPECT_EQ(iqueuea->getFront(), 50);
    EXPECT_EQ(iqueuea->getRear(), 40);
}

TEST_F(struct_test, getRear) {
    squeuea->enFront("world");
    squeuea->enRear("hello");
    EXPECT_EQ(squeuea->getRear(), "hello");
    EXPECT_EQ(squeuea->getCapacity(), 1);

    iqueuea->enRear(10);
    iqueuea->clean();
    iqueuea->enRear(20);
    iqueuea->enRear(30);
    iqueuea->enRear(40);
    iqueuea->enRear(50);
    iqueuea->enRear(10);
    EXPECT_EQ(iqueuea->getCapacity(), 5);
    EXPECT_EQ(iqueuea->getRear(), 10);
    EXPECT_EQ(iqueuea->getRear(), 50);
    EXPECT_EQ(iqueuea->getRear(), 40);
    EXPECT_EQ(iqueuea->getFront(), 20);
    EXPECT_EQ(iqueuea->getCapacity(), 1);

    dqueuea->enRear(1.1);
    dqueuea->enFront(2.2);
    dqueuea->enRear(3.3);
    EXPECT_EQ(dqueuea->getCapacity(), 3);
    EXPECT_EQ(dqueuea->getFront(), 2.2);
    EXPECT_EQ(dqueuea->getCapacity(), 2);
    EXPECT_EQ(dqueuea->getRear(), 3.3);
    EXPECT_EQ(dqueuea->getFront(), 1.1);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}