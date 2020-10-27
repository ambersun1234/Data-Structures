# Circular Priority Queue

# Overview
circular priority queue implementation based on linked list

## Functions
+ `clean`
    + clean all priority queue data
+ `getHead`
    + get priority queue head pointer
+ `getCapacity`
    + get priority queue capacity
+ `travel`
    + travel through all priority queue
+ `insert`
    + user provide custome **compare function** to tell priority queue how to insert
+ `find`
    + find the given data, return it's position if found else return -1
+ `delete_element`
    + give data, remove the correspond node from circular priority queue
+ `isEmpty`
    + checkout the circular priority queue is empty or not

## Test
```=1
make unit queuep
make test queuep
```

> run the above command at root directory
