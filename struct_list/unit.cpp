#include <iostream>
#include <string>

using namespace std;

#ifndef struct_list_header
    #include "./list.hpp"
#endif

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        list<string> *slist = new list<string>();
        list<int>    *ilist = new list<int>();
        list<double> *dlist = new list<double>();
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(slist->getHead(), nullptr);
    EXPECT_EQ(slist->getCapacity(), 0);

    EXPECT_TRUE(ilist->getHead() == nullptr);
    EXPECT_TRUE(ilist->getCapacity() == 0);

    EXPECT_EQ(dlist->getHead(), nullptr);
    EXPECT_EQ(dlist->getCapacity(), 0);
}

TEST_F(struct_test, insert_head) {
    slist->insert_head("hello");
    slist->insert_head("world");
    EXPECT_EQ(slist->getHead()->getData(), "world");
    EXPECT_EQ(slist->getHead()->getNext()->getData(), "hello");

    ilist->insert_head(1);
    ilist->insert_head(11);
    EXPECT_EQ(ilist->getHead()->getNext()->getData(), 1);
    EXPECT_EQ(ilist->getHead()->getNext()->getNext(), nullptr);

    dlist->insert_head(2.2);
    EXPECT_EQ(dlist->getCapacity(), 1);
}

TEST_F(struct_test, insert_tail) {
    EXPECT_EQ(slist->getCapacity(), 0);
    slist->insert_head("hello");
    slist->insert_tail("world");
    slist->insert_head("pink");
    EXPECT_EQ(slist->getHead()->getData(), "pink");
    EXPECT_EQ(slist->getHead()->getNext()->getData(), "hello");

    ilist->insert_tail(30);
    ilist->insert_tail(20);
    ilist->insert_tail(10);
    EXPECT_EQ(ilist->getHead()->getData(), 30);
    EXPECT_EQ(ilist->getCapacity(), 3);

    dlist->insert_tail(22.2);
    dlist->insert_head(33.3);
    dlist->insert_tail(11.1);
    EXPECT_EQ(dlist->getHead()->getData(), 33.3);
    EXPECT_EQ(dlist->getHead()->getNext()->getData(), 22.2);
}

TEST_F(struct_test, insert_after) {
    slist->insert_head("world");
    slist->insert_head("hello");
    slist->insert_after("pink", "hello");
    EXPECT_EQ(slist->getHead()->getData(), "hello");
    EXPECT_EQ(slist->getHead()->getNext()->getData(), "pink");
    EXPECT_EQ(slist->getCapacity(), 3);

    ilist->insert_tail(1);
    ilist->insert_tail(2);
    ilist->insert_before(3, 2);
    EXPECT_EQ(ilist->getHead()->getData(), 1);
    EXPECT_EQ(ilist->getCapacity(), 3);
    ilist->insert_after(4, 5);
    EXPECT_EQ(ilist->getCapacity(), 3);
    EXPECT_EQ(ilist->getHead()->getNext()->getData(), 3);
    EXPECT_EQ(ilist->getCapacity(), 3);
    EXPECT_EQ(ilist->getHead()->getNext()->getNext()->getData(), 2);

    dlist->insert_head(1.1);
    dlist->insert_after(2.2, 1.1);
    dlist->insert_after(3.3, 1.1);
    EXPECT_EQ(dlist->getHead()->getNext()->getData(), 3.3);
    EXPECT_EQ(dlist->getHead()->getData(), 1.1);
    EXPECT_EQ(dlist->getHead()->getNext()->getNext()->getData(), 2.2);
}

TEST_F(struct_test, insert_before) {
    slist->insert_head("hello");
    slist->insert_before("pink", "hello");
    EXPECT_EQ(slist->getHead()->getData(), "pink");
    EXPECT_EQ(slist->getCapacity(), 2);
    slist->insert_before("world", "helllo");
    EXPECT_EQ(slist->getCapacity(), 2);
    EXPECT_EQ(slist->getHead()->getData(), "pink");

    ilist->insert_after(1, 2);
    EXPECT_EQ(ilist->getCapacity(), 0);
    EXPECT_EQ(ilist->getHead(), nullptr);
    ilist->insert_tail(2);
    ilist->insert_before(1, 2);
    EXPECT_EQ(ilist->getCapacity(), 2);
    EXPECT_TRUE(ilist->getHead()->getData() == 1);

    dlist->insert_before(22.2, 33.3);
    EXPECT_EQ(dlist->getCapacity(), 0);
    EXPECT_EQ(dlist->getHead(), nullptr);
    dlist->insert_head(11.1);
    dlist->insert_before(22.2, 33.3);
    EXPECT_EQ(dlist->getHead()->getData(), 11.1);
}

TEST_F(struct_test, delete_head) {
    slist->delete_head();
    EXPECT_EQ(slist->getCapacity(), 0);
    EXPECT_EQ(slist->getHead(), nullptr);
    slist->insert_head("hello");
    slist->insert_head("world");
    slist->insert_before("pink", "hello");
    EXPECT_EQ(slist->getHead()->getData(), "world");
    EXPECT_EQ(slist->getHead()->getNext()->getData(), "pink");
    EXPECT_EQ(slist->getCapacity(), 3);
    slist->delete_head();
    EXPECT_EQ(slist->getHead()->getData(), "pink");
    EXPECT_EQ(slist->getCapacity(), 2);

    ilist->insert_head(10);
    ilist->delete_head();
    EXPECT_EQ(ilist->getCapacity(), 0);
    EXPECT_EQ(ilist->getHead(), nullptr);

    dlist->insert_tail(1.1);
    dlist->insert_tail(1.11);
    dlist->delete_head();
    EXPECT_EQ(dlist->getHead()->getData(), 1.11);
    EXPECT_EQ(dlist->getCapacity(), 1);
    dlist->delete_head();
    EXPECT_EQ(dlist->getHead(), nullptr);
    EXPECT_EQ(dlist->getCapacity(), 0);
}

TEST_F(struct_test, delete_tail) {
    slist->delete_tail();
    EXPECT_EQ(slist->getHead(), nullptr);
    EXPECT_EQ(slist->getCapacity(), 0);
    slist->insert_head("world");
    slist->insert_head("hello");
    EXPECT_EQ(slist->getCapacity(), 2);
    EXPECT_EQ(slist->getHead()->getNext()->getData(), "world");

    ilist->delete_tail();
    EXPECT_EQ(ilist->getCapacity(), 0);
    EXPECT_EQ(ilist->getHead(), nullptr);
    ilist->insert_head(1);
    ilist->insert_head(2);
    EXPECT_EQ(ilist->getHead()->getData(), 2);
    EXPECT_EQ(ilist->getCapacity(), 2);
    ilist->delete_tail();
    ilist->delete_tail();
    EXPECT_EQ(ilist->getCapacity(), 0);
    EXPECT_TRUE(ilist->getHead() == nullptr);

    dlist->insert_head(1.1);
    dlist->insert_tail(2.2);
    dlist->insert_tail(3.3);
    EXPECT_EQ(dlist->getCapacity(), 3);
    EXPECT_EQ(dlist->getHead()->getData(), 1.1);
    dlist->delete_head();
    EXPECT_EQ(dlist->getHead()->getData(), 2.2);
    EXPECT_EQ(dlist->getHead()->getNext()->getData(), 3.3);
    dlist->delete_tail();
    EXPECT_EQ(dlist->getHead()->getData(), 2.2);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}