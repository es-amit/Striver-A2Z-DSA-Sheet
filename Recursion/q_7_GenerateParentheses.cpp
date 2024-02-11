#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void solve(int open, int close, string op)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(op);
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        solve(open - 1, close, op1);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        solve(open, close - 1, op2);
    }
    return;
}
vector<string> generateParenthesis(int n)
{
    int open = n;
    int close = n;
    string op = "";
    solve(open, close, op);
    return ans;
}
