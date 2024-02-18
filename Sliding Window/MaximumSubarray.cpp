#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    list<int> l;
    vector<int> ans;
    while (j < nums.size())
    {
        // calculations
        while (!l.empty() && l.back() < nums[j])
        {
            l.pop_back();
        }
        l.push_back(nums[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            // slide the window
            if (nums[i] == l.front())
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}