#include <bits/stdc++.h>
using namespace std;
int solve(int i, vector<int> &nums, int &n, vector<int> &dp)
{
    if (i >= n - 1)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int mini = 1e5;
    for (int j = 1; j <= nums[i]; j++)
    {
        int minJump = solve(i + j, nums, n, dp) + 1;
        mini = min(mini, minJump);
    }
    return dp[i] = mini;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(0, nums, n, dp);
}