#include <iostream>
#include <string>

using namespace std;

#ifndef struct_list_header
    #include "./list.hpp"
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

bool exists(dlist<string> *tmp) {
    if (tmp == nullptr) {
        cout << "No dlist constructed" << endl;
    }
    return (tmp == nullptr ? false : true);
}


int main(int argc, const char *argv[]) {
    dlist<string> *mydlist = nullptr;
    string command;
    string input;

    while (true) {
        cout << ">: ";
        cin >> command;
        switch (hash_runtime(command)) {
            case hash_compiletime("new"): {
                mydlist = new dlist<string>();
                cout << "New dlist done" << endl;
                break;
            }

            case hash_compiletime("clean"): {
                mydlist->clean();
                cout << "dlist clean done" << endl;
                break;
            }

            case hash_compiletime("head"): {
                cout << "current dlist head pointer is: " << mydlist->getHead() << endl;
                break;
            }

            case hash_compiletime("capacity"): {
                cout << "current dlist capacity is: " << mydlist->getCapacity() << endl;
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
                cout << "\tnew dlist" << endl;
                cout << "ih:" << endl;
                cout << "\tinsert data to list head" << endl;
                cout << "it:" << endl;
                cout << "\tinsert data to list tail" << endl;
                cout << "ia:" << endl;
                cout << "\tinsert data after element" << endl;
                cout << "ib:" << endl;
                cout << "\tinsert data before element" << endl;
                cout << "dh:" << endl;
                cout << "\tdelete data from list head" << endl;
                cout << "dt:" << endl;
                cout << "\tdelete data from list tail" << endl;
                cout << "de:" << endl;
                cout << "\tdelete specific element from list" << endl;
                cout << "travel:" << endl;
                cout << "\ttravel all list from head to tail" << endl;
                cout << "reverse:" << endl;
                cout << "\treverse list from head to tail" << endl;
                cout << "pairwise:" << endl;
                cout << "\tpairwise element in list" << endl;
                cout << "clean:" << endl;
                cout << "\tclean all dlist data" << endl;
                cout << "head:" << endl;
                cout << "\tcheckout dlist head pointer" << endl;
                cout << "capacity:" << endl;
                cout << "\tcheckout current dlist capacity" << endl;
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