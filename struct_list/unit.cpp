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
        dlist<string> *sdlist = new dlist<string>();
        dlist<int>    *idlist = new dlist<int>();
        dlist<double> *ddlist = new dlist<double>();
};

TEST_F(struct_test, constructor) {
    EXPECT_EQ(sdlist->getHead(), nullptr);
    EXPECT_EQ(sdlist->getCapacity(), 0);

    EXPECT_TRUE(idlist->getHead() == nullptr);
    EXPECT_TRUE(idlist->getCapacity() == 0);

    EXPECT_EQ(ddlist->getHead(), nullptr);
    EXPECT_EQ(ddlist->getCapacity(), 0);
}

TEST_F(struct_test, insert_head) {
    sdlist->insert_head("hello");
    sdlist->insert_head("world");
    EXPECT_EQ(sdlist->getHead()->getData(), "world");
    EXPECT_EQ(sdlist->getHead()->getNext()->getData(), "hello");

    idlist->insert_head(1);
    idlist->insert_head(11);
    EXPECT_EQ(idlist->getHead()->getNext()->getData(), 1);
    EXPECT_EQ(idlist->getHead()->getNext()->getNext(), nullptr);

    ddlist->insert_head(2.2);
    EXPECT_EQ(ddlist->getCapacity(), 1);
}

TEST_F(struct_test, insert_tail) {
    EXPECT_EQ(sdlist->getCapacity(), 0);
    sdlist->insert_head("hello");
    sdlist->insert_tail("world");
    sdlist->insert_head("pink");
    EXPECT_EQ(sdlist->getHead()->getData(), "pink");
    EXPECT_EQ(sdlist->getHead()->getNext()->getData(), "hello");

    idlist->insert_tail(30);
    idlist->insert_tail(20);
    idlist->insert_tail(10);
    EXPECT_EQ(idlist->getHead()->getData(), 30);
    EXPECT_EQ(idlist->getCapacity(), 3);

    ddlist->insert_tail(22.2);
    ddlist->insert_head(33.3);
    ddlist->insert_tail(11.1);
    EXPECT_EQ(ddlist->getHead()->getData(), 33.3);
    EXPECT_EQ(ddlist->getHead()->getNext()->getData(), 22.2);
}

TEST_F(struct_test, insert_after) {
    sdlist->insert_head("world");
    sdlist->insert_head("hello");
    sdlist->insert_after("pink", "hello");
    EXPECT_EQ(sdlist->getHead()->getData(), "hello");
    EXPECT_EQ(sdlist->getHead()->getNext()->getData(), "pink");
    EXPECT_EQ(sdlist->getCapacity(), 3);
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}