#include <iostream>
#include <string>

using std::string;

class Hash_Table{
    int size;
    int capacity;
    string *values;

    int hash(string val);
    int backup_hash(string val);
    void grow();

    public:
        Hash_Table();
        
        bool add(string val);
        string remove(string val);
        string get(string val);
        bool contains(string val);
        void print();
};