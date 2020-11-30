# Binary search tree

## Overview
binary search tree implementation based on singly linked list

## Functions
+ `getRoot`
    + get root pointer
+ `getCapacity`
    + get current tree capacity
+ `isEmpty`
    + checkout tree is empty or not
+ `clean`
    + clean all data in binary search tree
+ `insert`
    + insert new element to binary search tree
+ `search`
    + search the given element whether it's in tree or not, return pointer
+ `search_parent`
    + search the given element parent whether it's in tree or not, return pointer
+ `getMaxLevel`
    + get binary tree max level
+ `inorder`
    + inorder travel
+ `preorder`
    + preorder travel
+ `postorder`
    + postorder
+ `isLeaf`
    + checkout whether current node is leaf or not

## Test
```=1
make unit tree
make test tree
```

> run the above command at root directory

## Note
+ level `i` have max $2^{i-1}$ nodes, where i $\geq$ 1
+ height `k` binary tree have max $2^{k} - 1$ nodes
+ $n_0$ denote degree 0 node number, $n_2$ denote degree 2 node number
    + then $n_0 = n_2 + 1$
+ let `b` be the total branch number, `n` be the total node number
    + then $n = b + 1$
