#include <bits/stdc++.h>
using namespace std;
int maxElement(vector<int> &arr, int i, int j)
{
    int maxi = arr[i];
    for (int k = i + 1; k <= j; k++)
    {
        maxi = max(arr[k], maxi);
    }
    return maxi;
}

int solve(vector<int> &arr, int partitions, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return arr[i];

    if (j - i + 1 <= partitions) // If number of elements between i and j is
                                 // less than or equal to partitions
        return (j - i + 1) * maxElement(arr, i, j);

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    for (int p = 1; p <= partitions && i + p <= j; p++)
    {
        int temp = p * maxElement(arr, i, i + p - 1) +
                   solve(arr, partitions, i + p, j, dp);
        maxi = max(maxi, temp);
    }
    return dp[i][j] = maxi;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(arr, k, 0, n - 1, dp);
}