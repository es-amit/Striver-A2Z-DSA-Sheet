#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int solve(int n, int arr[], int k, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }

    if (dp[n][k] != -1)
        return dp[n][k];

    int notTake = solve(n - 1, arr, k, dp) % MOD;
    int take = 0;
    if (arr[n] <= k)
        take = solve(n - 1, arr, k - arr[n], dp) % MOD;

    return dp[n][k] = (notTake + take) % MOD;
}

int perfectSum(int arr[], int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, arr, k, dp);
}