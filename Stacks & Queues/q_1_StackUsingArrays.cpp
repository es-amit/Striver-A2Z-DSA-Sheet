
#include <bits/stdc++.h>
using namespace std;
// Stack class.

class Stack
{

public:
    int Top;

    int *arr;

    int capacity;

    Stack(int capacity)
    {

        // Write your code here.

        this->capacity = capacity;

        arr = new int[capacity];

        Top = -1;
    }

    void push(int num)
    {

        // Write your code here.

        if (isFull())

            return;

        Top++;

        arr[Top] = num;
    }

    int pop()
    {

        // Write your code here.

        if (isEmpty())

            return -1;

        int val = arr[Top];

        Top--;

        return val;
    }

    int top()
    {

        // Write your code here.

        if (isEmpty())

            return -1;

        else

            return arr[Top];
    }

    int isEmpty()
    {

        // Write your code here.

        if (Top == -1)

            return 1;

        else

            return 0;
    }

    int isFull()
    {

        // Write your code here.

        if (Top == capacity - 1)

            return 1;

        else

            return 0;
    }
};
