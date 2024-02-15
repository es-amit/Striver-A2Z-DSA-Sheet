#include <bits/stdc++.h>
using namespace std;
class Queue
{

    int front, rear;
    vector<int> arr;
    int cnt;

public:
    Queue()
    {
        cnt = 0;
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (cnt == arr.size())
        {
            return;
        }
        arr[rear % arr.size()] = e;
        rear += 1;
        cnt++;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (cnt == 0)
        {
            return -1;
        }
        int first = arr[front % arr.size()];
        front++;
        cnt--;
        return first;
    }
};