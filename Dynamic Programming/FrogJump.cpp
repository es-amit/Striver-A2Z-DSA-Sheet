#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}
int frogJumpMemo(int n, vector<int> &heights)
{

    vector<int> dp(n, -1);
    return solve(n - 1, heights, dp);
}

int frogJumpTabular(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int fj = dp[i-1] + abs(heights[i] - heights[i-1]);
        int sj = INT_MAX;
        if(i > 1){
            sj = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(fj,sj);
    }
    return dp[n-1];
} 