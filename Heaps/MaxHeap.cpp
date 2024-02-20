#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        vector<int> heap;
        int size;

        MaxHeap(){
            size = 0;
        }

        void push(int val){
            heap.push_back(val);
            size++;
            int index = size -1;
            while(index > 0){
                int parent = (index - 1) /2;
                if(heap[parent] < heap[index]){
                    swap(heap[parent],heap[index]);
                    index=  parent;
                }
                else{
                    break;
                }
            }
        }
        void print(){
            for(int i= 0;i<size;i++){
                cout << heap[i] << ' ';
            }
            cout << endl;
        }

        int pop(){
            if(size== 0){
                return -1;
            }
            int temp = heap[0];
            // step -1 last element put into the heap root
            heap[0] = heap[size-1];
            size--;
            heap.pop_back();
            // place the last element to its correct pos
            int i = 0;
            while(i < size){
                int leftIndex = 2*i+1;
                int rightIndex = 2*i+2;
                if(heap[leftIndex] >= heap[rightIndex]){
                    if(leftIndex < size && heap[leftIndex] > heap[i]){
                        swap(heap[leftIndex],heap[i]);
                        i = leftIndex;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(rightIndex < size && heap[rightIndex] > heap[i]){
                        swap(heap[rightIndex],heap[i]);
                        i = rightIndex;
                    }
                    else{
                        break;
                    }
                }
            }
            return temp;
        }
};

void heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2* i+2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    
}

void heapSort(vector<int> &arr, int n){
    int temp = n;
    while(temp > 0){
        swap(arr[temp],arr[0]);
        temp--;
        heapify(arr,temp,0);
    }
}


int main(){
    MaxHeap h;
    // h.push(1);
    // h.push(2);
    // h.push(3);
    // h.push(4);
    // h.push(5);
    // h.push(6);

    // h.print();

    // cout << h.pop() << endl;

    // h.print();

    vector<int> arr = {4,30,62,11,90,12};
    int n = arr.size();
    // for(int i= (n/2)-1; i>= 0 ;i--){
    //     heapify(arr,n,i);
    // }

    heapSort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }

    

}