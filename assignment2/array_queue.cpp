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
            if (size = capacity)
            {
                return false;
            }
            if (front != back)
            {
                back++;
            }
            array[back % capacity] = val;
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