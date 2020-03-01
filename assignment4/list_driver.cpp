# include "linked_list.h"

using std::cout;
using std::endl;

int main()
{
    Linked_List list;
    list.push(1);
    bool true_one = list.peek(1);
    if(true_one != true)
    {
        cout << "This list broke!" << endl;
    }
    else
    {
        cout << "1 added to position " << list.search(1) << endl;
    }

    list.push(3);
    bool true_three = list.peek(3);
    if(true_three != true)
    {
        cout << "This list broke!" << endl;
    }
    else
    {
        cout << "3 added to position " << list.search(3) << endl;
    }

    list.push(2);
    bool true_two = list.peek(2);
    if(true_two != true)
    {
        cout << "This list broke!" << endl;
    }
    else
    {
        cout << "2 added to position " << list.search(2) << ". 3 is now in position " << list.search(3) << endl;
    }

    int should_be_two = list.pop(2);
    if(should_be_two != 2)
    {
        cout << should_be_two << " This list broke!" << endl;
    }
    else
    {
        cout << should_be_two << " removed. 3 is now in position " << list.search(3) << endl;
    }
    
}