#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b, unordered_map<string, bool> &mp)
{
    if (a.compare(b) == 0)
        return true;

    if (a.length() <= 1)
        return false;

    string temp = a;
    temp.push_back(' ');
    temp.append(b);
    if (mp.find(temp) != mp.end())
        return mp[temp];

    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        bool case1 = solve(a.substr(0, i), b.substr(n - i, i), mp) && solve(a.substr(i, n - i), b.substr(0, n - i), mp);
        bool case2 = solve(a.substr(0, i), b.substr(0, i), mp) && solve(a.substr(i, n - i), b.substr(i, n - i), mp);

        if (case1 || case2)
        {
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}
bool isScramble(string S1, string S2)
{
    unordered_map<string, bool> mp;
    return solve(S1, S2, mp);
}