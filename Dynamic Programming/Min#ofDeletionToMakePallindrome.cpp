#include <bits/stdc++.h>
using namespace std;
int lcs(int n, int m, string text1, string text2, vector<vector<int>> &dp)
{
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int minDeletions(string s1, int n)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return n - lcs(n, n, s1, s2, dp);
}