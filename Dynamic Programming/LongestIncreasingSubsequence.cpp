#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int> &nums, int &n, int prev_ind, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int len = 0 + solve(ind + 1, nums, n, prev_ind, dp);

    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        len = max(len, 1 + solve(ind + 1, nums, n, ind, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}
int lengthOfLISMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    return solve(0, nums, n, -1, dp);
}

int lengthOfLISTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev_ind = i - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[i + 1][prev_ind + 1];
            if (prev_ind == -1 || nums[i] > nums[prev_ind])
            {
                len = max(len, 1 + dp[i + 1][i + 1]);
            }
            dp[i][prev_ind + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}

int lengthOfLISmostOptimized(vector<int> &nums)
{
    vector<int> temp;
    int n = nums.size();
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}