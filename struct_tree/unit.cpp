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

TEST_F(struct_test, getMaxLevel) {
    stree->insert_helper("pink");
    EXPECT_EQ(stree->getMaxLevel_helper(), 1);
    stree->insert_helper("hello");
    stree->insert_helper("world");
    EXPECT_EQ(stree->getRoot()->getright()->getData(), "world");
    EXPECT_EQ(stree->getMaxLevel_helper(), 2);

    itree->insert_helper(4);
    itree->insert_helper(3);
    itree->insert_helper(2);
    itree->insert_helper(1);
    EXPECT_EQ(itree->getMaxLevel_helper(), 4);
    EXPECT_EQ(itree->getCapacity(), 4);

    EXPECT_EQ(dtree->getMaxLevel_helper(), 0);
    dtree->insert_helper(1.1);
    dtree->insert_helper(2.2);
    dtree->insert_helper(3.3);
    EXPECT_EQ(dtree->getMaxLevel_helper(), 3);
    EXPECT_EQ(dtree->getRoot()->getleft(), nullptr);
}

TEST_F(struct_test, public_search) {
    EXPECT_EQ(stree->search_helper("hello"), false);
    stree->insert_helper("apple");
    stree->insert_helper("pink");
    stree->insert_helper("dig");
    stree->insert_helper("queen");
    EXPECT_EQ(stree->search_helper("queen"), true);

    itree->insert_helper(90);
    itree->insert_helper(65);
    itree->insert_helper(29);
    itree->insert_helper(100);
    itree->insert_helper(945);
    itree->insert_helper(99);
    EXPECT_EQ(itree->getMaxLevel_helper(), 3);

    dtree->insert_helper(1.1);
    dtree->insert_helper(2.2);
    dtree->insert_helper(3.3);
    dtree->clean_helper();
    EXPECT_EQ(dtree->getRoot(), nullptr);
    EXPECT_EQ(dtree->getCapacity(), 0);
}

TEST_F(struct_test, delete_element) {
    stree->insert_helper("hello");
    EXPECT_EQ(stree->getRoot()->getData(), "hello");
    EXPECT_TRUE(!stree->delete_element_helper("world"));
    EXPECT_TRUE(stree->delete_element_helper("hello"));
    EXPECT_EQ(stree->getRoot(), nullptr);

    itree->insert_helper(90);
    itree->insert_helper(65);
    itree->insert_helper(29);
    itree->insert_helper(100);
    itree->insert_helper(945);
    itree->insert_helper(99);
    EXPECT_EQ(itree->delete_element_helper(90), true);
    EXPECT_EQ(itree->getRoot()->getData(), 99);
    EXPECT_TRUE(itree->getRoot()->getright()->getleft() == nullptr);

    EXPECT_TRUE(dtree->delete_element_helper(1.1) == false);
    dtree->insert_helper(9.9);
    dtree->insert_helper(8.8);
    dtree->insert_helper(7.7);
    dtree->insert_helper(6.6);
    dtree->insert_helper(5.5);
    dtree->insert_helper(4.4);
    EXPECT_EQ(dtree->getCapacity(), 6);
    EXPECT_EQ(dtree->getMaxLevel_helper(), 6);
    EXPECT_TRUE(dtree->getRoot()->getright() == nullptr);
}

TEST_F(struct_test, isLeaf) {
    EXPECT_EQ(stree->isLeaf(stree->getRoot()), true);
    stree->insert_helper("b");
    stree->insert_helper("a");
    stree->insert_helper("c");
    EXPECT_EQ(stree->isLeaf(stree->getRoot()), false);

    itree->insert_helper(90);
    itree->insert_helper(65);
    itree->insert_helper(29);
    itree->insert_helper(100);
    itree->insert_helper(945);
    itree->insert_helper(99);
    EXPECT_EQ(itree->isLeaf(itree->search(itree->getRoot(), 99)), true);
    EXPECT_EQ(itree->isLeaf(itree->search(itree->getRoot(), 65)), false);

    EXPECT_EQ(dtree->isLeaf(dtree->getRoot()), true);
}

TEST_F(struct_test, search) {
    EXPECT_EQ(stree->search(stree->getRoot(), "hello"), nullptr);
    stree->insert_helper("b");
    stree->insert_helper("a");
    stree->insert_helper("c");
    EXPECT_EQ(stree->search(stree->getRoot(), "c")->getData(), "c");

    itree->insert_helper(90);
    itree->insert_helper(65);
    itree->insert_helper(29);
    itree->insert_helper(100);
    itree->insert_helper(945);
    itree->insert_helper(99);
    EXPECT_EQ(itree->search(itree->getRoot(), 99)->getleft(), nullptr);
    EXPECT_EQ(itree->search(itree->getRoot(), 90)->getleft()->getData(), 65);

    dtree->insert_helper(9.9);
    dtree->insert_helper(8.8);
    dtree->insert_helper(7.7);
    dtree->insert_helper(6.6);
    EXPECT_EQ(dtree->search(dtree->getRoot(), 8.8), dtree->search_parent(dtree->getRoot(), 7.7));
}

TEST_F(struct_test, search_parent) {
    EXPECT_TRUE(stree->search_parent(stree->getRoot(), "hello") == nullptr);
    stree->insert_helper("b");
    stree->insert_helper("a");
    stree->insert_helper("c");
    EXPECT_EQ(stree->search_parent(stree->getRoot(), "c"), stree->search_parent(stree->getRoot(), "a"));

    itree->insert_helper(90);
    itree->insert_helper(65);
    EXPECT_EQ(itree->search_parent(itree->getRoot(), 65)->getData(), 90);
    itree->insert_helper(29);
    itree->insert_helper(100);
    itree->insert_helper(945);
    itree->insert_helper(99);
    EXPECT_EQ(itree->search_parent(itree->getRoot(), 29), itree->search(itree->getRoot(), 65));
}

TEST_F(struct_test, clean) {
    stree->clean_helper();
    EXPECT_EQ(stree->getRoot(), nullptr);
    stree->insert_helper("b");
    stree->insert_helper("a");
    stree->insert_helper("c");
    EXPECT_EQ(stree->getMaxLevel_helper(), 2);
    EXPECT_EQ(stree->getCapacity(), 3);
    stree->clean_helper();
    EXPECT_EQ(stree->getRoot(), nullptr);
    EXPECT_EQ(stree->getCapacity(), 0);
    EXPECT_EQ(stree->getMaxLevel_helper(), 0);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}