#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank;
        vector<int> parent;
        vector<int> size;

        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=1;i<=n;i++){
                parent[i] = i;
            }
            size.resize(n+1,1);
        }

        int findUParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] == rank[ulp_v]){
                parent[ulp_v] = ulp_u;
                rank[ulp_u] ++;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
        
};

