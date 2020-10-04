# Circular Queue - array version

# Overview
circular queue implementation based on array

## Functions
+ `isFull`
    + checkout array is full or not
+ `isEmpty`
    + checkout array is empty or not
+ `getFp`
    + get front position
+ `getRp`
    + get rear position
+ `enFront`
    + insert element at front position
+ `enRear`
    + insert element at rear position
+ `getFront`
    + get element from front position and remove it
+ `getRear`
    + get element from rear position and remove it
+ `peekFront`
    + get element from front position without remove it
+ `peekRear`
    + get element from rear position without remove it
+ `getSize`
    + get queue size
+ `getCapacity`
    + get queue current size
+ `clean`
    + clean all queue data and position

## Run
```=1
make compile queuea
make run queuea
```

## Test
```=1
make unit queuea
make test queuea
```

> run the above command at root directory
