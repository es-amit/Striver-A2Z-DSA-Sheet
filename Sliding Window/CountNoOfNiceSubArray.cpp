#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k, int &n)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, odds = 0, cnt = 0;
    while (r < n)
    {
        if (nums[r] & 1)
        {
            odds++;
        }
        while (odds > k)
        {
            if (nums[l] & 1)
            {
                odds--;
            }
            l++;
        }
        if (odds <= k)
        {
            cnt = cnt + (r - l + 1);
        }
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    return solve(nums, k, n) - solve(nums, k - 1, n);
}