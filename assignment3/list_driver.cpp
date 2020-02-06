# include "linked_list.h"

using std::cout;
using std::endl;

int main()
{
    Linked_List list;
    list.push(1, 1);
    int should_be_one = list.peek(1);
    if(should_be_one != 1)
    {
        cout << "This list broke!" << endl;
    }

    list.push(2, 2);
    list.push(3, 3);
    int should_be_two = list.pop(2);
    if(should_be_two != 2)
    {
        cout << "This list broke!" << endl;
    }

    int should_be_three = list.peek(2);
    if(should_be_three != 3)
    {
        cout << "This list broke!" << endl;
    }
}