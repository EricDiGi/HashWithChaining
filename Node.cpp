#include <iostream>
#include "Node.hpp"

using namespace std;

Node::Node(){
    this->data = 0;
    this->next = NULL;
}

Node::Node(int data){
    this->data = data;
    this->next = NULL;
}

Node::~Node(){
    this->next = NULL;
}