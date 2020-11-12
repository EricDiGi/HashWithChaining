#ifndef Node_HPP
#define Node_HPP

#include  <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node();
        Node(int data);
        ~Node();
};

#endif