#include <iostream>
#include <string>

using namespace std;

#ifndef struct_queuec_header
    #include "./queuec.hpp"
#endif

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

#include "gtest/gtest.h"

class struct_test : public testing::Test {
    protected:
        queue<string> *squeue = new queue<string>();
        queue<int>    *iqueue = new queue<int>();
        queue<double> *dqueue = new queue<double>();
};

TEST_F(struct_test, constructor) {
    EXPECT_TRUE(squeue->getHead() == nullptr);
    EXPECT_TRUE(squeue->getTail() == nullptr);
    EXPECT_EQ(squeue->getCapacity(), 0);

    EXPECT_TRUE(dqueue->getHead() == nullptr);
    EXPECT_TRUE(dqueue->getTail() == nullptr);
    EXPECT_EQ(dqueue->getCapacity(), 0);

    EXPECT_TRUE(iqueue->getHead() == nullptr);
    EXPECT_TRUE(iqueue->getTail() == nullptr);
    EXPECT_EQ(iqueue->getCapacity(), 0);
}

TEST_F(struct_test, enqueue) {
    squeue->enqueue("hello");
    EXPECT_EQ("hello", squeue->front());
    EXPECT_EQ("hello", squeue->rear());
    EXPECT_TRUE(squeue->getTail() == squeue->getHead());
    squeue->enqueue("world");
    EXPECT_EQ("hello", squeue->front());
    EXPECT_EQ("world", squeue->rear());
    EXPECT_EQ(squeue->getCapacity(), 2);
    EXPECT_EQ(squeue->getHead()->getPrevious(), squeue->getTail());
    EXPECT_EQ(squeue->getTail()->getNext(), squeue->getHead());

    iqueue->enqueue(100);
    EXPECT_TRUE(iqueue->getHead() == iqueue->getTail());
    iqueue->clean();
    EXPECT_TRUE(iqueue->getHead() == nullptr);
    EXPECT_TRUE(iqueue->getTail() == nullptr);

    dqueue->enqueue(22.2);
    dqueue->enqueue(33.3);
    EXPECT_EQ(dqueue->getHead()->getPrevious(), dqueue->getTail());
}

TEST_F(struct_test, dequeue) {
    squeue->clean();
    EXPECT_EQ(squeue->getHead(), nullptr);
    squeue->enqueue("hello");
    squeue->dequeue();
    EXPECT_EQ(squeue->getTail(), nullptr);
}

TEST_F(struct_test, front) {
    squeue->clean();
    squeue->enqueue("world");
    squeue->enqueue("hello");
    squeue->enqueue("pink");
    EXPECT_EQ(squeue->front(), "world");
    EXPECT_EQ(squeue->getCapacity(), 3);
}

TEST_F(struct_test, rear) {
    squeue->clean();
    squeue->enqueue("world");
    squeue->enqueue("hello");
    squeue->enqueue("pink");
    EXPECT_EQ(squeue->rear(), "pink");
    EXPECT_EQ(squeue->getCapacity(), 3);

    iqueue->clean();
    iqueue->enqueue(10);
    iqueue->clean();
    iqueue->enqueue(22);
    EXPECT_EQ(iqueue->rear(), 22);
    EXPECT_EQ(iqueue->getHead(), iqueue->getTail());

    dqueue->clean();
    dqueue->enqueue(22.2);
    dqueue->enqueue(33.3);
    dqueue->dequeue();
    EXPECT_EQ(dqueue->getCapacity(), 1);
    EXPECT_TRUE(dqueue->getHead() == dqueue->getTail());
}

TEST_F(struct_test, reverse) {
    squeue->clean();
    squeue->enqueue("apple");
    squeue->enqueue("banana");
    squeue->enqueue("client");
    squeue->enqueue("drink");
    squeue->enqueue("epoxy");
    node<string> *origin_head = squeue->getHead(), *origin_tail = squeue->getTail();
    squeue->reverse();
    EXPECT_EQ(origin_head, squeue->getTail());
    EXPECT_EQ(origin_tail, squeue->getHead());
    EXPECT_EQ(squeue->getHead()->getData(), "epoxy");
    EXPECT_EQ(squeue->getHead()->getNext()->getData(), "drink");
    EXPECT_EQ(squeue->getHead()->getNext()->getNext()->getData(), "client");
    EXPECT_EQ(squeue->getTail()->getData(), "apple");
    EXPECT_TRUE(squeue->getHead()->getPrevious() == squeue->getTail());

    dqueue->clean();
    dqueue->enqueue(22.2);
    dqueue->enqueue(33.3);
    dqueue->dequeue();
    dqueue->enqueue(66.6);
    EXPECT_EQ(dqueue->getHead()->getPrevious(), dqueue->getTail());
    dqueue->reverse();
    EXPECT_EQ(dqueue->getTail()->getData(), 33.3);
    EXPECT_EQ(dqueue->getCapacity(), 2);

    iqueue->enqueue(10);
    iqueue->clean();
    iqueue->enqueue(20);
    iqueue->enqueue(30);
    iqueue->enqueue(40);
    iqueue->reverse();
    iqueue->dequeue();
    EXPECT_EQ(iqueue->getHead()->getData(), 30);
    EXPECT_EQ(iqueue->getTail()->getData(), 20);
    EXPECT_EQ(iqueue->getCapacity(), 2);
    EXPECT_TRUE(iqueue->getHead()->getPrevious() == iqueue->getTail());
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}