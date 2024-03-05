#include <bits/stdc++.h>
using namespace std;

int fiboMemo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp);
}

void fiboTable(int n)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}

void fiboOptimize()
{
    int n = 5;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
}