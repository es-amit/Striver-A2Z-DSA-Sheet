#include <bits/stdc++.h>
using namespace std;
int totalFruits(int N, vector<int> &fruits)
{
    int l = 0, r = 0, maxLen = 0;
    map<int, int> mpp;
    while (r < N)
    {
        mpp[fruits[r]]++;
        if (mpp.size() > 2)
        {
            mpp[fruits[l]]--;
            if (mpp[fruits[l]] == 0)
            {
                mpp.erase(fruits[l]);
            }
            l++;
        }
        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}