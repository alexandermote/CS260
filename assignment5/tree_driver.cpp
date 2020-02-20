# include "btree.h"

int main()
{
    // create basic tree
    Btree_Node *root = new Btree_Node();
    root->data = 4;
      Btree_Node *left = new Btree_Node();
      left->data = 2;
      Btree_Node *right = new Btree_Node();
      right->data = 6;

    root->left = left;
    root->right = right;

    bool should_be_true = root->search(root, 6);
    if(should_be_true != true)
    {
        cout << should_be_true << " This line broke!" << endl;
    }

    bool should_be_false = root->search(root, 9);
    if(should_be_false != false)
    {
        cout << should_be_false << " This line broke!" << endl;
    }

    should_be_true = root->add(root, 5);
    if(should_be_true != true)
    {
        cout << should_be_true << " This line broke!" << endl;
    }

    should_be_true = root->search(root, 5);
    if(should_be_true != true)
    {
        cout << should_be_true << " This line broke!" << endl;
    }

    root->pre_order(root); // should print "4, 2, 6, 5"
    cout << endl;
    root->in_order(root); // should print "2, 4, 5, 6"
    cout << endl;
    root->post_order(root); // should print "2, 5, 6, 4"
    cout << endl;

    int should_be_six = root->remove(root->right);
    if(should_be_six != 6)
    {
        cout << should_be_six << " This line broke!" << endl;
    }

    root->in_order(root); // should print "2, 4, 5"
}