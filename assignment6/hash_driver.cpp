#include "hash_table.h"

using std::cout;
using std::endl;

Hash_Table::Hash_Table()
{
    size = 0;
    capacity = 8;
    values = new string[capacity];
    for (int i = 0; i < capacity; i++)
    {
        values[i] = "";
    }
}

// case sensitive "a-to-i" hash
int Hash_Table::hash(string val) // O(len(val))
{
    int atoi = 0;
    for (int i = 0; i < val.length(); i++) // O(len(val))
    {
        atoi += val[i] - 'A';
    }
    return atoi % capacity;
}

int Hash_Table::backup_hash(string val) // O(len(val))
{
    int backup_hash = 0;
    for (int i = 0; i < val.length(); i++) // O(len(val))
    {
        backup_hash += (val[i] - 'A') * i;
    }
    return backup_hash;
}

void Hash_Table::grow() // O(n)
{
    int new_capacity = capacity * 2;
    string *new_values = new string[new_capacity];
    for (int i = 0; i < capacity; i++)
    {
        new_values[i] = values[i];
    }
    for (int i = capacity; i < new_capacity; i++)
    {
        new_values[i] = "";
    }
    capacity = new_capacity;
    values = new_values;
}

// adds a value to the array
bool Hash_Table::add(string val) // O(n)
{
    // do we have room?
    if (size >= (capacity * 0.75))
    {
        grow();
    }
    //use hash to find table location
    int val_hash = hash(val); // O(len(val))

    //collision resolution
    if (values[val_hash] != "")
    {
        int new_hash = backup_hash(val); // O(len(val))
        val_hash = (val_hash + new_hash) % capacity;
    }

    // dumber collision resolution
    while (values[val_hash] != "") // O(n)
    {
        val_hash = (val_hash + 1) % capacity;
    }

    //place value
    values[val_hash] = val;
    size++;
    return true;
}

string Hash_Table::remove(string val) // O(len(val))
{
    int val_hash = hash(val); // O(len(val))
    values[val_hash] = "";
    return val;
}

// returns whatever is currently at the location of the given value
string Hash_Table::get(string val) // O(len(val))
{
    int val_hash = hash(val); // O(len(val))
    return values[val_hash];
}

// returns whether a value is in the array
bool Hash_Table::contains(string val) // O(len(val))
{
    int val_hash = hash(val); // O(len(val))
    return values[val_hash] == val;
}

// prints every value in the array
void Hash_Table::print() // O(n)
{
    for (int i = 0; i < capacity; i++) // O(n)
    {
        cout << values[i] << endl;
    }
}