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

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}