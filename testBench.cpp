#include <iostream>
#include "Node.hpp"
#include "Link.hpp"
#include "Hash.hpp"

using namespace std;

int main(){
    Hash table = Hash(8);
    table.insert(48);
    table.insert(55);
    table.insert(0);
    table.insert(4);
    cout << table << endl;
    table.insert(12);
    table.insert(16);
    table.remove(55);
    cout << table.lookup(16) << endl;
    cout << table;
}