# Heap

## Overview
special form of a complete binary tree

## Functions
+ `insert`
    + insert new value to heap
+ `remove`
    + remove min/max value from heap
+ `traversal`
    + iterate over heap
+ `getter`
    + get value by index
+ `getSize`
    + get heap size
+ `getCount`
    + get current heap value count
+ `getType`
    +  get type(min or max)
+ `getRemoveChild`
    + get the node index that need to remove
+ `getParentLocation`
    + get parent node index based on input
+ `getLeftChildrenLocation`
    + get left child index based on input
+ `getRightChildrenLocation`
    + get right child index based on input
+ `swap`
    + swap 2 node
+ `isEmpty`
    + check heap is empty or not
+ `checkHeapness`
    + check if heap is heapness or not
+ `legal`
    + check child is legal or not(out of bound)
+ `heapnessButtomUp`
    + check heapness buttom up
+ `heapnessTopDown`
    + check heapness top down
+ `isLeaf`
    + check if node is leaf or not
+ `isFull`
    + check heap is full or not
+ `compare`
    + compare 2 node value based on heap type(min, max)

## Test
```=1
make unit heap
make test heap
```
