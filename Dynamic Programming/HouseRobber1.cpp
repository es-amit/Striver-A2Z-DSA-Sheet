#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + solve(n - 2, nums, dp);
        int notpick = solve(n - 1, nums, dp);
        return dp[n] = max(pick, notpick);
    }
    int robMemo(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
    int robTabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
    int robSpaceOptimized(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }
            int notpick = prev;
            int curri = max(pick, notpick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};