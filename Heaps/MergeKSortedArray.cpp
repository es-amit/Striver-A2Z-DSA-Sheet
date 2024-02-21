#include <bits/stdc++.h> 
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0;i<k;i++){

       for(int j=0;j<kArrays[i].size();j++){

           pq.push(kArrays[i][j]);

       }

   }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
