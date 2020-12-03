#include <iostream>
#include <string>

using namespace std;

#ifndef struct_queueca_header
    #include "./queueca.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        queueca<string> *squeueca = new queueca<string>(10);
        queueca<int>    *iqueueca = new queueca<int>(10);
        queueca<double> *dqueueca = new queueca<double>(15);
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(squeueca->getCount(), 0);
    EXPECT_EQ(squeueca->getFrontIndex(), squeueca->getRearIndex());
    EXPECT_EQ(squeueca->getSize(), 10);

    EXPECT_TRUE(!iqueueca->getCount());
    EXPECT_EQ(iqueueca->getFrontIndex(), iqueueca->getRearIndex());

    EXPECT_EQ(dqueueca->getFrontIndex(), dqueueca->getRearIndex());
    EXPECT_TRUE(!dqueueca->getCount());
}

TEST_F(struct_test, isEmpty) {
    EXPECT_EQ(squeueca->isEmpty(), true);
    for (char i = 'a'; i < 'k'; i++) {
        string tmp;
        tmp += i;
        squeueca->enRear(tmp);
    }
    EXPECT_TRUE(!squeueca->isEmpty());
    
    
    EXPECT_EQ(iqueueca->isEmpty(), true);
    for (int i = 0; i < 10; i++) iqueueca->enRear(i);
    for (int i = 0; i < 5; i++) iqueueca->removeFront();
    for (int i = 0; i < 3; i++) iqueueca->enRear(i);
    EXPECT_EQ(iqueueca->isFull(), false);

    EXPECT_EQ(dqueueca->isEmpty(), true);
}

TEST_F(struct_test, enFront) {
    for (char i = 'a'; i < 'k'; i++) {
        string tmp;
        tmp += i;
        squeueca->enRear(tmp);
    }
    EXPECT_TRUE(!squeueca->isEmpty());
    EXPECT_EQ(squeueca->getter(9), "j");
    EXPECT_EQ(squeueca->getFrontIndex(), 0);
    EXPECT_EQ(squeueca->getRearIndex(), 0);
    EXPECT_EQ(squeueca->enRear("k"), false);
    EXPECT_EQ(squeueca->getRearIndex(), squeueca->getFrontIndex());
}