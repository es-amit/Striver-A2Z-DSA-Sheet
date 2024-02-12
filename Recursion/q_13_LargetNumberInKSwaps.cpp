#include <bits/stdc++.h>
using namespace std;
void solve(string &s, int k, string &res, int start)
{
    if (k == 0 || start == s.size() - 1)
    {
        return;
    }
    char maxChar = *max_element(s.begin() + start + 1, s.end());
    for (int i = start + 1; i < s.size(); i++)
    {
        if (s[i] == maxChar && s[start] < s[i])
        {
            swap(s[start], s[i]);

            if (s.compare(res) > 0)
            {
                res = s;
            }

            // Recur with k-1 swaps and start position incremented by 1.
            solve(s, k - 1, res, start + 1);

            // Backtrack: Undo the swap.
            swap(s[start], s[i]);
        }
    }
    return;
}
string findMaximumNum(string str, int k)
{
    string res = str;
    solve(str, k, res, 0);
    return res;
}