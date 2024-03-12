#include <bits/stdc++.h>
using namespace std;
bool allStars(string &p, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (p[i] != '*')
        {
            return false;
        }
    }
    return true;
}
bool solve(string &s, string &p, int n, int m, vector<vector<int>> &dp)
{
    // when both strings gets empty
    if (n == 0 && m == 0)
        return true;

    // when only 1st string get empty
    if (m == 0)
        return false;

    // if only true if
    if (n == 0)
        return allStars(p, m);

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s[n - 1] == p[m - 1] || p[m - 1] == '?')
    {
        return dp[n][m] = solve(s, p, n - 1, m - 1, dp);
    }
    else if (p[m - 1] == '*')
    {
        bool exclude = solve(s, p, n - 1, m, dp);
        bool include = solve(s, p, n, m - 1, dp);
        return dp[n][m] = exclude || include;
    }
    return dp[n][m] = false;
}
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(s, p, n, m, dp);
}

bool isMatchTopDown(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] = false;
    }
    for (int j = 1; j <= m; j++)
    {
        if (p[j - 1] == '*')
        {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}