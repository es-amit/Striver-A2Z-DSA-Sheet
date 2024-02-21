#include <bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	int cost = 0;
	while(pq.size()>=2){
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		int sum = first + second;
		cost = cost + sum;
		pq.push(sum);
	}
	return cost;
}

