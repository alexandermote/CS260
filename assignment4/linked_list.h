# include <iostream>

using std::endl;
using std::cout;

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
    Node *head = NULL;
    public:
        /* Linked_List()
        {
            cpp gives us a constructor for free UNLESS we define our own
        }
        */

        bool push(int val) // create a new node with val, add in correctly ordered position, tell me how you did
        {
            Node *add_node = new Node();
            if (add_node == NULL)
            {
                return false;
            }
            add_node->data = val;
            if (head == NULL)
            {
                head = add_node;
                return true;
            }
            Node *current_node = head;
            Node *prev_node;
            while (val > current_node->data)
            {
                prev_node = current_node;
                current_node = prev_node->next;
                if (current_node == NULL)
                {break;}
            }
            add_node->next = current_node;
            prev_node->next = add_node;
            return true;

        } // This function has a runtime of O(n)

        int pop(int val) // fetch position data, update the list, free the old node, return data
        {
            Node *current_node = head;
            Node *prev_node;
            while (val != current_node->data)
            {
                prev_node = current_node;
                current_node = prev_node->next;
            }
            int output_val = current_node->data;
            if (prev_node != NULL)
            {prev_node->next = current_node->next;}
            else
            {head = current_node->next;}
            free(current_node);
            return output_val;
        } // This function has a runtime of O(n)

        bool peek(int val) // return whether a specific value is in our list without altering the list
        {
            Node *current_node = head;
            while (val != current_node->data)
            {
                if (current_node->next == NULL)
                {return false;}
                current_node = current_node->next;
            }
            return true;
        } // This function has a runtime of O(n)

        int search(int val) // return the position of a specific value in our list (returns 0 if not in list)
        {
            Node *current_node = head;
            int position = 1;
            while (val != current_node->data)
            {
                if (current_node->next == NULL)
                {
                    position = 0;
                    break;
                }
                current_node = current_node->next;
                position++;
            }
            if (head == NULL)
            {position = 0;}
            return position;
        } // This function has a runtime of O(n)
};