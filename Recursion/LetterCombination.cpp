#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
unordered_map<char, string> dialpad;
void solve(string ip, string op)
{
    if (ip.size() == 0)
    {
        ans.push_back(op);
        return;
    }
    char firstChar = ip[0];
    string str = dialpad[firstChar];
    for (int i = 0; i < str.length(); i++)
    {
        op.push_back(str[i]);
        solve(ip.substr(1), op);
        op.pop_back();
    }
    return;
}
vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
        return {};
    dialpad['2'] = "abc";
    dialpad['3'] = "def";
    dialpad['4'] = "ghi";
    dialpad['5'] = "jkl";
    dialpad['6'] = "mno";
    dialpad['7'] = "pqrs";
    dialpad['8'] = "tuv";
    dialpad['9'] = "wxyz";
    solve(digits, "");
    return ans;
}