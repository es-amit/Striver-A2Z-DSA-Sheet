#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap,int i){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	if(left < heap.size() && heap[left] >= heap[largest]){
		largest = left;
	}
	
	if(right < heap.size() && heap[right] >= heap[largest]){
		largest = right;
	}

	if(largest != i){
		swap(heap[largest],heap[i]);
		heapify(heap, largest);
	}
	return;
	
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	for(int i = (n/2)-1;i>=0;i--){
		heapify(arr, i);
	}
	return arr;
}