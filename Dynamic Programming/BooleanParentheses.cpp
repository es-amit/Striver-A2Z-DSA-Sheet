#include <bits/stdc++.h>
using namespace std;
int mod = 1003;
int solve(string &s, int i, int j, int isTrue, vector<vector<vector<int> > > &dp)
{
    if (i > j)
        return false;

    if (i == j)
    {
        if (isTrue)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    int ans = 0;
    for (int k = i + 1; k <= j; k = k + 2)
    {
        int lf = solve(s, i, k - 1, 0, dp);
        int rf = solve(s, k + 1, j, 0, dp);
        int lt = solve(s, i, k - 1, 1, dp);
        int rt = solve(s, k + 1, j, 1, dp);

        if (s[k] == '&')
        {
            if (isTrue)
            {
                ans = (ans + (lt * rt) % mod) % mod;
            }
            else
            {
                ans = (ans + (lt * rf + lf * rt + lf * rf) % mod) % mod;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ans = (ans + (lt * rf + lf * rt + lt * rt) % mod) % mod;
            }
            else
            {
                ans = (ans + (lf * rf) % mod) % mod;
            }
        }
        else
        {
            if (isTrue)
            {
                ans = (ans + (lf * rt + lt * rf) % mod) % mod;
            }
            else
            {
                ans = (ans + (lf * rf + lt * rt) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ans;
}
int countWays(int n, string s)
{
    vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(n + 1, vector<int>(2, -1)));
    return solve(s, 0, n - 1, 1, dp);
}