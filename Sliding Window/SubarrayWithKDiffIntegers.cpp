#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k, int &n)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, cnt = 0;
    unordered_map<int, int> mpp;
    while (r < n)
    {
        mpp[nums[r]]++;
        int mapSize = mpp.size();
        cout << mapSize << endl;
        while (mapSize > k)
        {
            mpp[nums[l]]--;
            if (mpp[nums[l]] == 0)
            {
                mpp.erase(nums[l]);
                mapSize--;
            }
            l++;
        }
        if (mapSize <= k)
        {
            cnt = cnt + (r - l + 1);
        }
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    return solve(nums, k, n) - solve(nums, k - 1, n);
}