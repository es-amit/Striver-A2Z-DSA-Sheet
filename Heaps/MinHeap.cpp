#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    public:
    vector<int> heap;
    int size;

    MinHeap()
    {
        size = 0;
    }

    void push(int val)
    {
        heap.push_back(val);
        size++;
        int index = size - 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << ' ';
        }
        cout << endl;
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        int temp = heap[0];
        // step -1 last element put into the heap root
        heap[0] = heap[size - 1];
        size--;
        heap.pop_back();
        // place the last element to its correct pos
        int i = 0;
        while (i < size)
        {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (heap[leftIndex] <= heap[rightIndex])
            {
                if (leftIndex < size && heap[leftIndex] < heap[i])
                {
                    swap(heap[leftIndex], heap[i]);
                    i = leftIndex;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (rightIndex < size && heap[rightIndex] < heap[i])
                {
                    swap(heap[rightIndex], heap[i]);
                    i = rightIndex;
                }
                else
                {
                    break;
                }
            }
        }
        return temp;
    }
};

void heapify(vector<int> &arr,int n,int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2* i+2;
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
    
}

int main()
{
    MinHeap h;
    h.push(6);
    h.push(5);
    h.push(3);
    h.push(4);
    h.push(2);
    h.push(32);
    h.push(51);

    h.print();

}
