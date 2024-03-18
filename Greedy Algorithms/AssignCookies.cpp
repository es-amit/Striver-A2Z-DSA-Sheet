#include <bits/stdc++.h>
using namespace std;
int assignCookie(vector<int> &g, vector<int> &s)
{
    int cookies = s.size();
    int children = g.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int cnt = 0;
    int i = 0, j = 0;
    while (i < children && j < cookies)
    {
        if (g[i] <= s[j])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}
