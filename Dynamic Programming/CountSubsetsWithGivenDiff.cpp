#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] <= sum)
    {
        int pick = solve(arr, n - 1, sum - arr[n - 1], dp);
        int notpick = solve(arr, n - 1, sum, dp);
        return dp[n][sum] = pick + notpick;
    }
    else
    {
        int notpick = solve(arr, n - 1, sum, dp);
        return dp[n][sum] = notpick;
    }
}
int countPartitions(int n, int d, vector<int> &arr)
{

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int s1 = (sum + d) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, -1));
    return solve(arr, n, s1, dp);
}
// tabulation

int mod = 1000000007;

int countSub(vector<int> &v, int n, int diff)

{

    int sum = 0;

    for (int i = 0; i < n; i++)

        sum += v[i];

    if (diff > sum)

        return 0;

    if ((diff + sum) % 2 != 0)

        return 0;

    int s2 = (diff + sum) / 2;

    int dp[n + 1][s2 + 1];

    for (int i = 0; i <= n; i++)

        dp[i][0] = 1;

    for (int j = 1; j <= s2; j++)

        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j <= s2; j++)
        {

            if (v[i - 1] > j)

                dp[i][j] = dp[i - 1][j];

            else

                dp[i][j] = (dp[i - 1][j]

                            + dp[i - 1][j - v[i - 1]]) %
                           mod;
        }
    }

    return dp[n][s2] % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{

    // Write your code here.

    return countSub(arr, n, d) % mod;
}