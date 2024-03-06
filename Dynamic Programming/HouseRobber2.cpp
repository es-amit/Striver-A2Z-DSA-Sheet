#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &nums)
{
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
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(nums[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(nums[i]);
        }
    }
    return max(solve(n - 1, temp1), solve(n - 1, temp2));
}