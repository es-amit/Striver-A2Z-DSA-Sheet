#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void generate(string ip,string op){
    if(ip.size() == 0){
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    // took element in 2nd string
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    generate(ip, op1);
    generate(ip, op2);
    return;
}
vector<string> generateSubsequences(string s)
{
    if(s.size() == 0) return ans;
    generate(s, "");
    return ans;
}