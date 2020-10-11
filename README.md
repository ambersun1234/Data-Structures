# Data Structures
![CI](https://github.com/ambersun1234/Data-Structures/workflows/CI/badge.svg?branch=master)

Collection of all data structures implementation with c++

## Clone repo
```=1
git clone --recurse-submodules https://github.com/ambersun1234/Data-Structures
```
## Git hooks
+ enable git hooks by `make all`

## Run
```=1
make compile stack
make run stack
```

## Run test
```=1
make unit stack
make test stack

# replace stack with other data structures(directory name start with struct_*)
```

## Run all test
```=1
make ci
```

## Implementation link
+ [stack - linked list](./struct_stack)
+ [queue - array](./struct_queuea)
+ [list - linked list](./struct_list)
+ [circular queue - doubly linked list](./struct_queue)
+ [circular priority queue - linked list](./struct_queuep)
+ [binary search tree - singly linkes list](./struct_tree)

## License
+ This project is licensed under `Apache-2.0` License - see the [LICENSE](./LICENSE) file for detail
