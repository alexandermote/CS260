#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head;
    Node *tail;
    public:
        /* Linked_List()
        {
            cpp gives us a constructor for free UNLESS we define our own
        }
        */

        bool enqueue(int val) // create a new node with val, add node to tail, tell me how you did
        {
            Node *add_node = new Node();
            if (add_node == NULL)
            {
                return false;
            }
            add_node->data = val;
            tail->next = add_node;
            if (head == NULL)
            {
                head = add_node;
            }
            tail = add_node;
            return true;

        }

        int dequeue() // fetch head data, update the list, free the old node, return data
        {
            Node *old_and_busted_joint = head;
            int val = head->data;
            head = head->next;
            free(old_and_busted_joint);
            return val;
        }
        // tail functions should also be added
};

int main()
{
    Linked_List list;

    list.enqueue(1);
    int should_be_one = list.dequeue();

    if (should_be_one != 1)
    {
        cout << should_be_one << endl << "This line broke!" << endl;
    }
    
    list.enqueue(1);
    list.enqueue(2);

    int should_still_be_one = list.dequeue();

    if (should_be_one != 1)
    {
        cout << should_still_be_one << endl << "This line broke!" << endl;
    }

    int should_be_two = list.dequeue();

    if (should_be_two != 2)
    {
        cout << should_be_two << endl << "This line broke!" << endl;
    }
}