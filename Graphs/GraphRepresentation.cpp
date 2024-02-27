#include<bits/stdc++.h>
using namespace std;
void adjacenyMatrix(int n,int m,vector<vector<int>> &graph){
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}
void adjacencyList(int n,int m,map<int,vector<int>> &graph){
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph;
    adjacenyMatrix(n,m,graph);
    map<int,vector<int>> list;
    adjacencyList(n,m,list);
}