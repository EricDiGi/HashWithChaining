#ifndef Hash_HPP
#define Hash_HPP

#include "Link.hpp"
#include "Node.hpp"
#include <iostream>

class Hash{
    private:
        int bucket;
        int size;
        Link* table;
    public:
        Hash(int val);
        ~Hash();
        void insert(int key);
        void remove(int key);
        int lookup(int key);
        void rebuild();
        //void resize(int size);

        int hashF(int value);
        double loadFactor();
        bool reload();

        friend std::ostream &operator<< (std::ostream &out, const Hash &t){
            out << "size: " << t.size << "\t buckets: " << t.bucket << endl;
            for(int i = 0; i < t.bucket; i++){
                out << i << ": " << t.table[i];
            }
            return out;
        }
};

#endif