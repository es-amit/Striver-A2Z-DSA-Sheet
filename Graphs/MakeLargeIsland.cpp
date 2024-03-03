#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
  public:
    bool isValid(int nrow,int ncol,int n){
        if(nrow >=0  && nrow < n && ncol >=0 && ncol < n){
            return true;
        }
        return false;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col] == 0) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                for(int ind =0 ;ind<4;ind++){
                    int nrow = row + drow[ind];
                    int ncol = col + dcol[ind];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        int node = row *n+col;
                        int adjNode = nrow *n +ncol;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        
        
        int maxi = 0;
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col] == 1) continue;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                set<int> components;
                for(int ind =0 ;ind<4;ind++){
                    int nrow = row + drow[ind];
                    int ncol = col + dcol[ind];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        components.insert(ds.findUParent(nrow*n + ncol));
                    }
                }
                
                int sizeTotal = 0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi,sizeTotal+1);
            }
            
        }
        for(int i=0;i< n*n;i++){
            maxi =max(maxi,ds.size[ds.findUParent(i)]);
        }
        return maxi;
    }
};