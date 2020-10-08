#include <iostream>
#include <string>

using namespace std;

#ifndef struct_tree_header
    #include "./tree.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        tree<string> *stree = new tree<string>();
        tree<int>    *itree = new tree<int>();
        tree<double> *dtree = new tree<double>();
};

TEST_F(struct_test, constructor) {
    EXPECT_TRUE(stree->isEmpty());
    EXPECT_EQ(stree->getCapacity(), 0);
    EXPECT_EQ(stree->getRoot(), nullptr);

    EXPECT_EQ(itree->getRoot(), nullptr);

    EXPECT_TRUE(dtree->isEmpty());
}

TEST_F(struct_test, insert) {
    stree->insert_helper("b");
    stree->insert_helper("a");
    stree->insert_helper("c");
    
    EXPECT_EQ(stree->getRoot()->getData(), "b");
    EXPECT_EQ(stree->getRoot()->getleft()->getData(), "a");
    EXPECT_EQ(stree->getRoot()->getright()->getData(), "c");

    itree->insert_helper(1000);
    itree->insert_helper(500);
    itree->insert_helper(100);
    itree->insert_helper(50);
    itree->insert_helper(10);
    EXPECT_EQ(itree->getRoot()->getData(), 1000);
    EXPECT_TRUE(itree->getRoot()->getright() == nullptr);
    EXPECT_EQ(itree->getCapacity(), 5);

    EXPECT_TRUE(dtree->isEmpty());
    dtree->insert_helper(1.1);
    EXPECT_TRUE(dtree->getRoot()->getleft() == dtree->getRoot()->getright());
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}