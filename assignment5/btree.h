#include <iostream>

using std::cout;
using std::endl;

struct Btree_Node
{
    int data;
    Btree_Node *left;
    Btree_Node *right;

    void print_node(Btree_Node *cur)
    {
        cout << cur->data << endl; // node value
    }

    void print_tree(Btree_Node *root, int order)
    {
        // do we even have a tree?
        if (root == NULL)
        {
            cout << "This tree is empty." << endl;
        }
        // baby we got a tree going

        if (order == 1)
        {
            print_node(root); // pre-order
        }

        if (root->left != NULL)
        {
            print_tree(root->left, order); // repeat function for left child
        }

        if (order == 2)
        {
            print_node(root); // in-order
        }

        if (root->right != NULL)
        {
            print_tree(root->right, order); // repeat function for right child
        }

        if (order == 3)
        {
            print_node(root); // post-order
        }
    }

    public:
        bool search(Btree_Node *root, int val)
        {
            if (root->data == val)
            {
                return true;
            }
            if (root->data > val)
            {
                if (root->left == NULL)
                {
                    return false;
                }
                return search(root->left, val);
            }
            if (root->data < val)
            {
                if (root->right == NULL)
                {
                    return false;
                }
                return search(root->right, val);
            }
        }
        bool add(Btree_Node *root, int val)
        {
            Btree_Node *new_node = new Btree_Node();

            if (new_node == NULL)
            {
                return false;
            }

            if (root == NULL) // highly unlikely that this will come up but just in case ¯\_(ツ)_/¯
            {
                new_node->data = val;
                root = new_node;
                return true;                
            }

            if (root->data >= val)
            {
                if (root->left == NULL)
                {
                    new_node->data = val;
                    root->left = new_node;
                    return true;
                }
                return add(root->left, val);
            }

            if (root->data < val)
            {
                if (root->right == NULL)
                {
                    new_node->data = val;
                    root->right = new_node;
                    return true;
                }
                return add(root->right, val);
            }
        }
        int remove(Btree_Node *node)
        {
            int val = node->data;
            if (node->left == NULL && node->right == NULL)
            {
                free(node);
            }
            Btree_Node *current_node;
            if (node->left != NULL)
            {
                current_node = node->left;
                while (current_node->right != NULL)
                {
                    current_node = current_node->right;
                }
                int new_val = current_node->data;
                free(current_node);
                node->data = new_val;
                node->left = NULL;
            }
            else
            {
                current_node = node->right;
                while (current_node->left != NULL)
                {
                    current_node = current_node->left;
                }
                int new_val = current_node->data;
                free(current_node);
                node->data = new_val;
                node->right = NULL;
            }
            
            return val;
        }
        void pre_order(Btree_Node *node)
        {
            print_tree(node, 1);
        }

        void in_order(Btree_Node *node)
        {
            print_tree(node, 2);
        }

        void post_order(Btree_Node *node)
        {
            print_tree(node, 3);
        }
};