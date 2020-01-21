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
    int size;
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

    list.enqueue(42);
    int output = list.dequeue();

    cout << output << endl;
}