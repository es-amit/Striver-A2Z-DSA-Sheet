
#include <bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int n) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    map<int,int> mpp;
    int rank = 1;
    while(!pq.empty()){
        if(mpp.find(pq.top()) == mpp.end()){
            mpp[pq.top()] = rank;
            rank++;
        }
        pq.pop();
    }

    for(int i=0;i<n;i++){
        arr[i] = mpp[arr[i]];
    }
    return arr;
}