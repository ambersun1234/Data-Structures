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

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}