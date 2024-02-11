#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mpp;
void solve(string op,int index,int sz,string ip){
    if(mpp[op]>0) return;
    if(op.size() != 0) mpp[op]++;
    if(index == sz){
        return;
    }
    op+=ip[index];
    solve(op,index+1,sz,ip);
    op.pop_back();
    solve(op,index+1,sz,ip);
    return;
}
string moreSubsequence(int n, int m, string a, string b)
{
    solve("",0,n,a);
    int countA = mpp.size();
    mpp.clear();
    solve("",0,m,b);
    int countB = mpp.size();
    if(countA >= countB) return a;
    return b;
}