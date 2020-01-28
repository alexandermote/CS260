# include <iostream>

class Array_List
{
    int front = 0;
    int back = 0;
    int capacity;
    int size = 0;
    int *array;

    public:
        Array_List(int new_cap)
        {
            
            capacity = new_cap;
            array = new int[capacity];
        }
        bool enqueue(int val)
        {
            if (size == capacity)
            {
                return false;
            }
            array[back % capacity] = val;
            back++;
            size++;
            return true;
        }

        int dequeue()
        {
            if (size == 0)
            {
                return NULL;
            }
            int result = array[front % capacity];
            front++;
            size--;
            return result;
        }
};

using std::cout;
using std::endl;

int main()
{
    Array_List test = Array_List(5);
    int should_be_null = test.dequeue();
    if (should_be_null != NULL)
    {
        cout << "This list broke!" << endl;
    }
    test.enqueue(1);
    test.enqueue(2);
    test.enqueue(3);
    test.enqueue(4);
    test.enqueue(5);
    bool should_be_false = test.enqueue(6);
    if (should_be_false != false)
    {
        cout << "This list broke!" << endl;
    }
    int should_be_one = test.dequeue();
    if (should_be_one != 1)
    {
        cout << should_be_one << endl;
        cout << "This list broke!" << endl;
    }
}