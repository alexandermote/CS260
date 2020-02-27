#include "hash_driver.cpp"

using std::cout;
using std::endl;

int main()
{
    cout << "Creating new hash table:" << endl;
    Hash_Table *myhash = new Hash_Table;
    cout << "Hash table created? " << (myhash != NULL) << endl;

    string new_val;

    cout << "Adding values a-j" << endl;
    bool success = false;
    for (int i = 0; i < 10; i++)
    {
        new_val = "";
        new_val += ('a' + i);
        success = myhash->add(new_val);
        if (success)
        {cout << "Added " << new_val << " successfully." << endl;}
        else
        {cout << "Could not add " << new_val << " successfully." << endl;}
    }

    myhash->print();
    
    string query2 = myhash->get("a");
    cout << "query 'a': " << query2 << endl;

    bool has_g = myhash->contains("g");
    cout << "Is 'g' in our array? " << has_g << endl;

    bool has_a = myhash->contains("l");
    cout << "Is 'l' in our array? " << has_a << endl;

    myhash->add("bruh"); // should go to spot 14 (backup hash)
    myhash->add("broh"); // should go to spot 11 (dumb backup)

    myhash->print();

    myhash->add("breh"); // should grow our list

    myhash->print();
}