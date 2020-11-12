#include <iostream>
#include "Link.hpp"
#include "Node.hpp"
#include "Hash.hpp"

using namespace std;

Hash::Hash(int val){
    this->bucket = val;
    this->size = 0;
    this->table = new Link[val];
}

Hash::~Hash(){
    delete[] this->table;
}

void Hash::insert(int key){
    int iter = hashF(key);
    this->table[iter].append(key);
    this->size++;

    //Automatically update table size
    if(reload()){
        rebuild();
    }
}

void Hash::remove(int key){
    int iter = hashF(key);
    int loc = this->table[iter].search(key);
    this->table[iter].remove(loc);
    this->size--;
}

void Hash::rebuild(){
    int buck = this->bucket+1;
    Link* T = new Link[buck];
    int pull; int b;
    for(int i = 0; i < this->bucket; i++){
        pull = this->table[i].pullFirst();
        while(pull != -1){
            b = pull%buck;
            T[b].append(pull);
            pull = this->table[i].pullFirst();
        }
    }
    this->bucket = buck;
    delete[] this->table;
    this->table = T;
}

int Hash::lookup(int key){
    int iter = hashF(key);
    return iter;
}

int Hash::hashF(int value){
    return value % this->bucket;
}

double Hash::loadFactor(){
    return ((double)this->size)/this->bucket;
}

bool Hash::reload(){
    return loadFactor() > 0.5;
}