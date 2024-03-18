#include <bits/stdc++.h>
using namespace std;
bool solve(int i, vector<int> &nums, int &n, vector<int> &dp)
{
    if (i >= n - 1)
    {
        return true;
    }
    if (dp[i] != -1)
        return dp[i];

    for (int jump = 1; jump <= nums[i]; jump++)
    {
        if (solve(i + jump, nums, n, dp) == true)
        {
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(0, nums, n, dp);
}