#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(string op,int ones,int zeros,int n){
    if(n == 0) {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back('0');
    solve(op1, ones, zeros++, n-1);
    if(op2.back() != '1'){
        op2.push_back('1');
        solve(op2, ones++, zeros, n-1);
    }
    return;
}
vector<string> generateString(int n) {
    int ones = 0;
    int zeros= 0;
    solve("", ones, zeros, n);
    return ans;
}