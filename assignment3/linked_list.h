# include <iostream>

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

        bool push(int val, int pos) // create a new node with val, add in certain position, tell me how you did
        {
            Node *add_node = new Node();
            if (add_node == NULL)
            {
                return false;
            }
            add_node->data = val;
            Node *current_node = head;
            Node *prev_node;
            for (int i = 0; i < pos; i++)
            {
                prev_node = current_node;
                current_node = prev_node->next;
            }
            prev_node->next = add_node;
            add_node->next = current_node;
            return true;

        }

        int pop(int pos) // fetch position data, update the list, free the old node, return data
        {
            Node *current_node = head;
            Node *prev_node;
            for (int i = 0; i < pos; i++)
            {
                prev_node = current_node;
                current_node = prev_node->next;
            }
            prev_node->next = current_node->next;
            int val = current_node->data;
            free(current_node);
            return val;
        }

        int peek(int pos) // return the value of a node at a certain position without altering the list
        {
            Node *current_node = head;
            for (int i = 0; i < pos; i++)
            {
                current_node = current_node->next;
            }
            int val = current_node->data;
            return val;
        }
};