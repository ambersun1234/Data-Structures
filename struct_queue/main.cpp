#include <iostream>
#include <string>

using namespace std;

#ifndef struct_queue_header
    #include "./queue.hpp"
#endif

#ifndef struct_node_header
    #include "../struct_node/node.hpp"
#endif

typedef uint64_t hash_t;
constexpr hash_t prime = 0x100088001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_runtime(string str) {
    hash_t ret{basis};

    for (char &c : str) {
        ret ^= c;
        ret *= prime; 
    } 
    return ret; 
}

constexpr hash_t hash_compiletime(char const* str, hash_t last_value = basis) {
    return *str ? hash_compiletime(str + 1, (*str ^ last_value) * prime) : last_value;
}

bool exists(queue<string> *tmp) {
    if (tmp == nullptr) {
        cout << "No queue constructed" << endl;
    }
    return (tmp == nullptr ? false : true);
}


int main(int argc, const char *argv[]) {
    queue<string> *myqueue = nullptr;
    string command;
    string input;

    while (true) {
        cout << ">: ";
        cin >> command;
        switch (hash_runtime(command)) {
            case hash_compiletime("new"): {
                myqueue = new queue<string>();
                cout << "New Queue done" << endl;
                break;
            }
            case hash_compiletime("eq"): {
                if (!exists(myqueue)) break;
                
                cout << "Please input your data: ";
                cin >> input;
                myqueue->enqueue(input);
                break;
            }

            case hash_compiletime("dq"): {
                if (!exists(myqueue)) break;

                myqueue->dequeue();
                if (myqueue->getCapacity() == 0) {
                    cout << "After dequeue, there is no element in queue" << endl;
                } else {
                    cout << "After dequeue head value is: " << myqueue->getHead()->getData() << " capacity is: " << myqueue->getCapacity() << endl;
                }
                break;
            }

            case hash_compiletime("front"): {
                if (!exists(myqueue)) break;

                cout << "Front data is: " << myqueue->front() << endl;
                break;
            }

            case hash_compiletime("rear"): {
                if (!exists(myqueue)) break;

                cout << "Rare data is: " << myqueue->rear() << endl;
                break;
            }

            case hash_compiletime("travel"): {
                if (!exists(myqueue)) break;

                myqueue->travel();
                cout << endl;
                break;
            }

            case hash_compiletime("clean"): {
                if (!exists(myqueue)) break;

                myqueue->clean();
                cout << "Queue clean done" << endl;
                break;
            }

            case hash_compiletime("head"): {
                if (!exists(myqueue)) break;

                cout << "current Queue head pointer is: " << myqueue->getHead() << endl;
                break;
            }

            case hash_compiletime("tail"): {
                if (!exists(myqueue)) break;

                cout << "current Queue tail pointer is: " << myqueue->getTail() << endl;
                break;
            }

            case hash_compiletime("capacity"): {
                if (!exists(myqueue)) break;

                cout << "current Queue capacity is: " << myqueue->getCapacity() << endl;
                break;
            }

            case hash_compiletime("reverse"): {
                if (!exists(myqueue)) break;

                myqueue->reverse();
                cout << "reverse result: ";
                myqueue->travel();
                cout << endl;
                break;
            }

            case hash_compiletime("exit"): {
                cout << "Bye" << endl;
                break;
            }
            
            default: {
                cout << "User help manual" << endl;
                cout << "command as follow you can use:" << endl;
                cout << "new:" << endl;
                cout << "\tnew Queue" << endl;
                cout << "eq:" << endl;
                cout << "\tinsert new element into queue(at rear position)" << endl;
                cout << "dq:" << endl;
                cout << "\tdelete element from queue(at front position)" << endl;
                cout << "front:" << endl;
                cout << "\tget front element from queue without deletion" << endl;
                cout << "rear:" << endl;
                cout << "\tget rear front element from queue without deletion" << endl;
                cout << "travel:" << endl;
                cout << "\ttravel all queue from head to tail" << endl;
                cout << "clean:" << endl;
                cout << "\tclean all Queue data" << endl;
                cout << "head:" << endl;
                cout << "\tcheckout Queue head pointer" << endl;
                cout << "tail:" << endl;
                cout << "\tcheckout Queue tail pointer" << endl;
                cout << "capacity:" << endl;
                cout << "\tcheckout current Queue capacity" << endl;
                cout << "reverse:" << endl;
                cout << "\treverse queue" << endl;
                cout << "exit:" << endl;
                cout << "\texit the console" << endl;
                break;
            }
        }

        if (command == "exit") {
            break;
        }
    }
    return 0;
}