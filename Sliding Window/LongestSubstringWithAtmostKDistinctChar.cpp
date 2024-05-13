#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string s, int k)
{
    int l = 0, r = 0, maxLen = -1;
    map<char, int> mpp;
    while (r < s.length())
    {
        mpp[s[r]]++;
        if (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l++;
        }
        if (mpp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}