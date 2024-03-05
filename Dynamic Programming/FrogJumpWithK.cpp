#include <bits/stdc++.h>
using namespace std;
int solve(int n, int &k, vector<int> &height, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int mini = INT_MAX;
    int i = 1;
    while (i <= k && n - i >= 0)
    {
        int steps = solve(n - i, k, height, dp) + abs(height[n] - height[n - i]);
        mini = min(mini, steps);
        i++;
    }
    return dp[n] = mini;
}
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, -1);
    return solve(n - 1, k, height, dp);
}
int minimizeCostTopDown(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 1;i<n;i++){
        int mini = INT_MAX;
        int j = 1;
        while(j <= k && i-j >= 0){
            int steps = dp[i-j] + abs(height[i] - height[i-j]);
            mini = min(mini,steps);
            j++;
        }
        dp[i] = mini;
    }
    return dp[n-1];
}