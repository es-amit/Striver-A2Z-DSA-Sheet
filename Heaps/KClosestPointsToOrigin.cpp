#include<bits/stdc++.h>
using namespace std;
class compare{
    public:
    bool operator()(const pair<int,vector<int>>& a,const pair<int,vector<int>> &b){
        return a.first < b.first;
    }

};
class Solution {
public:
    typedef pair<int,vector<int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<p,vector<p>,compare> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y=points[i][1];
            int dist = pow(x,2) + pow(y,2);
            vector<int> temp;
            temp.push_back(x);
            temp.push_back(y);
            pq.push(make_pair(dist,temp));
            if(pq.size() >k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};