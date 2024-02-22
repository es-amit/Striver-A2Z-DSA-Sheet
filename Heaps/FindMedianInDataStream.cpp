#include <bits/stdc++.h>
using namespace std;

int signum(int a,int b){
	if(a == b){
		return 0;
	}
	else if (a > b){
		return 1;
	}
	return -1;
}
void Median(int elem,priority_queue<int> &maxHeap,priority_queue<int,vector<int>,greater<int>> &minHeap,int &median){
        switch (signum(maxHeap.size(), minHeap.size())) {
        case 0:
            if (elem > median){
				minHeap.push(elem);
				median = minHeap.top();
			}
			else{
				maxHeap.push(elem);
				median = maxHeap.top();
			}
			break;
        case 1:
			if (elem > median){
				minHeap.push(elem);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			else{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(elem);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			break;
		case -1:
			if (elem > median){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(elem);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			else{
				maxHeap.push(elem);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			break;
	}
	return;
}

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	vector<int> ans;
	int med = 0;
	for(int i= 0;i<n;i++){
		Median(arr[i],maxHeap,minHeap,med);
		ans.push_back(med);
	}
	return ans;
}
