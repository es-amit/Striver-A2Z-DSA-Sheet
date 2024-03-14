#include <bits/stdc++.h>
using namespace std;
int maxCoinsHelper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int maxCoins = INT_MIN;

    // Iterate through each possible balloon to burst last
    for (int k = i; k <= j; k++)
    {
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i - 1] * nums[k] * nums[j + 1];

        // Recursively calculate the maximum coins for the remaining
        // balloons
        int remainingCoins =
            maxCoinsHelper(i, k - 1, nums, dp) + maxCoinsHelper(k + 1, j, nums, dp);

        // Update the maximum coins
        maxCoins = max(maxCoins, coins + remainingCoins);
    }

    return dp[i][j] = maxCoins;
}

// Function to calculate the maximum coins obtained
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // Call the helper function to compute the maximum coins
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return maxCoinsHelper(1, n, nums, dp);
}