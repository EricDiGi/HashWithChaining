#ifndef Link_HPP
#define Link_HPP

#include <iostream>
#include "Node.hpp"

class Link{
    private:
        Node* head;
    public:
        Link();
        Link(Node* l);
        ~Link();
        void push(int point);
        void append(int point);
        void remove(int loc);
        int search(int point);
        int pullFirst();
        friend std::ostream &operator<< (std::ostream &out, const Link &l){
            Node* list = l.head;
            while(list != NULL){
                out << "-->" << list->data;
                list = list->next;
            }
            out << endl;
            return out;
        }
};

#endif