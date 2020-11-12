#include <iostream>
#include "Link.hpp"
#include "Node.hpp"

Link::Link(){
    this->head = NULL;
}

Link::Link(Node* l){
    this->head = l;
}

Link::~Link(){
    delete this->head;
}

void Link::push(int point){
    Node* NEW = new Node(point);
    NEW->next = this->head;
    this->head = NEW;
}

void Link::append(int point){
    if(this->head == NULL){push(point); return;}
    Node* NEW = new Node(point);
    Node* temp = this->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = NEW;
}

void Link::remove(int loc){
    Node* temp = this->head;
    for(int i = 0; i < loc-1; i++){
        temp = temp->next;
    }
    if((loc != 0)&&(temp->next != NULL)&&(temp->next->next != NULL)){
        temp->next = temp->next->next;
        //cout << "A";
        return;
    }
    else{
        temp->next = NULL;
        if(loc == 0){
            this->head = NULL;
            //cout << "C";
        }
        //cout << "B";
        return;
    }
    
}

int Link::search(int point){
    Node* temp = this->head;
    int iter = 0;
    while(temp != NULL){
        if(temp->data == point){
            return iter;
        }
        temp = temp->next;
        iter++;
    }
    return -1;
}

int Link::pullFirst(){
    if(this->head == NULL){
        return -1;
    }
    int out = this->head->data;
    this->head = this->head->next;
    return out;
}