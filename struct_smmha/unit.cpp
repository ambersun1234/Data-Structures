#include <iostream>
#include <string>

using namespace std;

#ifndef struct_smmha_header
    #include "./smmha.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        smmha<string> *ssmmha = new smmha<string>(10);
        smmha<int>    *ismmha = new smmha<int>(10);
        smmha<double> *dsmmha = new smmha<double>(20);
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(ssmmha->getCurrent(), 1);
    EXPECT_EQ(ssmmha->getSize(), 10);

    EXPECT_EQ(ismmha->getLength(), ssmmha->getLength());
    EXPECT_EQ(ismmha->getCurrent(), 1);

    EXPECT_EQ(dsmmha->getSize(), 20);
}

TEST_F(struct_test, getParent) {
    EXPECT_EQ(ssmmha->getParent(10), 4);
    EXPECT_EQ(ismmha->getParent(3), 1);
    EXPECT_EQ(dsmmha->getParent(4), 1);
    EXPECT_EQ(dsmmha->getParent(14), 6);
}

TEST_F(struct_test, getLeftChild) {
    EXPECT_EQ(ssmmha->getLeftChild(1), 3);
    EXPECT_EQ(ismmha->getLeftChild(6), 13);
    EXPECT_EQ(dsmmha->getLeftChild(4), 9);
}

TEST_F(struct_test, getRightChild) {
    EXPECT_EQ(ssmmha->getRightChild(1), 4);
    EXPECT_EQ(ismmha->getRightChild(4), 10);
    EXPECT_EQ(dsmmha->getRightChild(2), 6);
}

TEST_F(struct_test, getSibling) {
    EXPECT_EQ(ssmmha->getSibling(1), 2);
    EXPECT_EQ(ismmha->getSibling(10), 9);
    EXPECT_EQ(dsmmha->getSibling(7), 8);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}