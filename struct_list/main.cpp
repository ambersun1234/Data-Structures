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

bool exists(list<string> *tmp) {
    if (tmp == nullptr) {
        cout << "No list constructed" << endl;
    }
    return (tmp == nullptr ? false : true);
}


int main(int argc, const char *argv[]) {
    list<string> *mylist = nullptr;
    string command;
    string input, input2;

    while (true) {
        cout << ">: ";
        cin >> command;
        switch (hash_runtime(command)) {
            case hash_compiletime("new"): {
                mylist = new list<string>();
                cout << "New list done" << endl;
                break;
            }

            case hash_compiletime("ih"): {
                cout << "Please input data: ";
                cin >> input;
                mylist->insert_head(input);
                cout << "Insert head done" << endl;
                break;
            }

            case hash_compiletime("it"): {
                cout << "Please input data: ";
                cin >> input;
                mylist->insert_tail(input);
                cout << "Insert tail done" << endl;
                break;
            }

            case hash_compiletime("ia"): {
                cout << "Please input data: ";
                cin >> input;
                cout << "Please input target: ";
                cin >> input2;
                mylist->insert_after(input, input2);
                cout << "Insert after done" << endl;
                break;
            }

            case hash_compiletime("ib"): {
                cout << "Please input data: ";
                cin >> input;
                cout << "Please input target: ";
                cin >> input2;
                mylist->insert_before(input, input2);
                cout << "Insert before done" << endl;
                break;
            }

            case hash_compiletime("dh"): {
                mylist->delete_head();
                cout << "Delete head done" << endl;
                break;
            }

            case hash_compiletime("dt"): {
                mylist->delete_tail();
                cout << "Delete tail done" << endl;
                break;
            }

            case hash_compiletime("de"): {
                cout << "Please input data: ";
                cin >> input;
                mylist->delete_target(input);
                cout << "Target delete done" << endl;
                break;
            }

            case hash_compiletime("reverse"): {
                mylist->reverse();
                cout << "Reverse done" << endl;
                mylist->travel();
                break;
            }

            case hash_compiletime("pairwise"): {
                mylist->pairwise();
                cout << "Pairwise done" << endl;
                mylist->travel();
                break;
            }

            case hash_compiletime("travel"): {
                mylist->travel();
                break;
            }

            case hash_compiletime("clean"): {
                mylist->clean();
                cout << "list clean done" << endl;
                break;
            }

            case hash_compiletime("head"): {
                cout << "current list head pointer is: " << mylist->getHead() << endl;
                break;
            }

            case hash_compiletime("capacity"): {
                cout << "current list capacity is: " << mylist->getCapacity() << endl;
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
                cout << "\tnew list" << endl;
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
                cout << "\tclean all list data" << endl;
                cout << "head:" << endl;
                cout << "\tcheckout list head pointer" << endl;
                cout << "capacity:" << endl;
                cout << "\tcheckout current list capacity" << endl;
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