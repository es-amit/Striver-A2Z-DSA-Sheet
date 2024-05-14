#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k, int &n)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0;
    int cnt = 0, sum = 0;
    while (r < n)
    {
        sum += nums[r];
        while (sum > k)
        {
            // if(l == n) break;
            sum = sum - nums[l];
            cout << sum << endl;
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int k)
{
    int n = nums.size();
    return solve(nums, k, n) - solve(nums, k - 1, n);
}