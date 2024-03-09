#include <bits/stdc++.h>
using namespace std;
int solve(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    // if s1 gets empty then we have to insert all remaining elements of s2
    if (n == 0)
        return m;
    // if s2 gets empty then we have to delete all remaining elements of s1
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = solve(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        // case 1 insert the char if don't match
        int insertion = 1 + solve(s1, s2, n, m - 1, dp);

        // case 2 delete the char if don't match
        int deletion = 1 + solve(s1, s2, n - 1, m, dp);

        // case 3 replace the char if don't match
        int replace = 1 + solve(s1, s2, n - 1, m - 1, dp);

        return dp[n][m] = min(insertion, min(replace, deletion));
    }
}
int minDistanceMemo(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(word1, word2, n, m, dp);
}

int minDistanceTabulation(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j < m + 1; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insertion = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(insertion, min(deletion, replace));
            }
        }
    }
    return dp[n][m];
}