#include <iostream>
#include <string>

using namespace std;

#ifndef struct_stack_header
    #include "./stack.hpp"
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

bool exists(stack<string> *tmp) {
    if (tmp == nullptr) {
        cout << "No stack constructed" << endl;
    }
    return (tmp == nullptr ? false : true);
}


int main(int argc, const char *argv[]) {
    stack<string> *mystack = nullptr;
    string command;
    string input;

    while (true) {
        cout << ">: ";
        cin >> command;
        switch (hash_runtime(command)) {
            case hash_compiletime("new"): {
                mystack = new stack<string>();
                cout << "New stack done" << endl;
                break;
            }
            case hash_compiletime("push"): {
                if (!exists(mystack)) break;

                cout << "Please input your data: ";
                cin >> input;
                mystack->push(input);
                break;
            }

            case hash_compiletime("pop"): {
                if (!exists(mystack)) break;

                node<string> *tmp = mystack->pop();
                if (tmp == nullptr) {
                    cout << "There is no value in stack" << endl;
                } else {
                    cout << "Poped value is: " << tmp->getData() << endl;
                }
                break;
            }

            case hash_compiletime("peek"): {
                if (!exists(mystack)) break;

                node<string> *tmp = mystack->peek();
                if (tmp == nullptr) {
                    cout << "There is no value in stack" << endl;
                } else {
                    cout << "Peeked value is: " << tmp->getData() << endl;
                }
                break;
            }

            case hash_compiletime("exit"): {
                cout << "Bye" << endl;
                break;
            }
            
            default:
                cout << "User help manual" << endl;
                cout << "command as follow you can use:" << endl;
                cout << "new:" << endl;
                cout << "\tnew stack" << endl;
                cout << "push:" << endl;
                cout << "\tpush data into stack" << endl;
                cout << "pop:" << endl;
                cout << "\tpop data from the stack" << endl;
                cout << "exit:" << endl;
                cout << "\texit the console" << endl;
                break;
        }

        if (command == "exit") {
            break;
        }
    }
    return 0;
}