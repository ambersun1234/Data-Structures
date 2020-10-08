#include <iostream>
#include <string>

using namespace std;

#ifndef struct_queuep_header
    #include "./queuep.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        queuep<string> *squeuep = new queuep<string>();
        queuep<int>    *iqueuep = new queuep<int>();
        queuep<double> *dqueuep = new queuep<double>();
};

int cmps(string a, string b) {
    // small to large
    return a.compare(b);
}

int cmpi(int a, int b) {
    // small to large
    return (a < b ? -1 : 1);
}

int cmpd(double a, double b) {
    // large to small
    return (a < b ? 1 : -1);
}

TEST_F(struct_test, constructor) {
    EXPECT_EQ(squeuep->getHead(), nullptr);
    EXPECT_EQ(squeuep->getTail(), nullptr);
    EXPECT_EQ(squeuep->getCapacity(), 0);

    EXPECT_TRUE(iqueuep->getHead() == iqueuep->getTail());

    dqueuep->clean();
    EXPECT_EQ(dqueuep->getHead(), nullptr);
    EXPECT_EQ(dqueuep->getTail(), nullptr);
    EXPECT_EQ(dqueuep->getCapacity(), 0);
}

TEST_F(struct_test, insert) {
    squeuep->setFunctionPointer(cmps);
    squeuep->insert("a");
    squeuep->insert("d");
    squeuep->insert("e");
    squeuep->insert("b");
    squeuep->insert("p");
    squeuep->insert("w");
    EXPECT_EQ(squeuep->getHead()->getData(), "a");
    EXPECT_EQ(squeuep->getTail()->getData(), "w");
    EXPECT_EQ(squeuep->getTail()->getNext()->getData(), "a");

    iqueuep->setFunctionPointer(cmpi);
    iqueuep->insert(100);
    iqueuep->insert(20);
    iqueuep->insert(55);
    EXPECT_EQ(iqueuep->getHead()->getData(), 20);
    EXPECT_EQ(iqueuep->getHead(), iqueuep->getTail()->getNext());

    dqueuep->setFunctionPointer(cmpd);
    dqueuep->insert(1.1);
    dqueuep->insert(2.2);
    dqueuep->clean();
    dqueuep->insert(3.3);
    dqueuep->insert(4.4);
    dqueuep->insert(5.5);
    dqueuep->insert(1.1);
    
    EXPECT_EQ(dqueuep->getHead()->getData(), 5.5);
    EXPECT_EQ(dqueuep->getTail()->getData(), 1.1);
    EXPECT_EQ(dqueuep->getTail()->getNext(), dqueuep->getHead());
}

TEST_F(struct_test, find) {
    squeuep->setFunctionPointer(cmps);
    squeuep->insert("hello");
    squeuep->insert("a");
    squeuep->insert("d");
    squeuep->insert("e");
    squeuep->insert("b");
    squeuep->insert("p");
    squeuep->insert("w");
    squeuep->insert("helllo");
    EXPECT_EQ(squeuep->find("hello"), 5);

    iqueuep->setFunctionPointer(cmpi);
    iqueuep->insert(10);
    iqueuep->insert(20);
    iqueuep->insert(50);
    iqueuep->insert(40);
    EXPECT_EQ(iqueuep->find(10), 0);
    EXPECT_EQ(iqueuep->find(50), 3);
    EXPECT_EQ(iqueuep->find(30), -1);
    EXPECT_EQ(iqueuep->getTail()->getNext()->getData(), 10);

    dqueuep->setFunctionPointer(cmpd);
    EXPECT_EQ(dqueuep->find(1.1), -1);
    dqueuep->clean();
    dqueuep->insert(5.5);
    EXPECT_EQ(dqueuep->getHead()->getData(), 5.5);
    EXPECT_EQ(dqueuep->getTail()->getData(), 5.5);
}

TEST_F(struct_test, delete_target) {
    EXPECT_EQ(squeuep->isEmpty(), true);
    squeuep->setFunctionPointer(cmps);
    squeuep->insert("aa");
    squeuep->insert("bb");
    squeuep->insert("cc");
    squeuep->delete_target("aa");
    EXPECT_EQ(squeuep->getTail()->getNext()->getData(), "bb");
    squeuep->delete_target("bb");
    EXPECT_EQ(squeuep->getTail(), squeuep->getHead());
    EXPECT_TRUE(!squeuep->delete_target("c"));
    EXPECT_EQ(squeuep->isEmpty(), false);
    squeuep->delete_target("cc");
    EXPECT_EQ(squeuep->getTail(), nullptr);

    iqueuep->setFunctionPointer(cmpi);
    iqueuep->insert(10);
    EXPECT_EQ(iqueuep->delete_target(100), false);
    EXPECT_EQ(iqueuep->getCapacity(), 1);

    dqueuep->setFunctionPointer(cmpd);
    dqueuep->insert(1.1);
    dqueuep->insert(2.2);
    dqueuep->insert(3.3);
    EXPECT_EQ(dqueuep->getCapacity(), 3);
    EXPECT_EQ(dqueuep->getTail()->getNext(), dqueuep->getHead());
    EXPECT_TRUE(!dqueuep->delete_target(4.4));
    EXPECT_EQ(dqueuep->getCapacity(), 3);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}