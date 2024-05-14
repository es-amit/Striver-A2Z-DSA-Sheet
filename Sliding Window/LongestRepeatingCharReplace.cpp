#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
    int l = 0, r = 0, maxLen = 0, maxF = 0;
    vector<int> hash(26, 0);
    while (r < s.length())
    {
        hash[s[r] - 'A']++;
        maxF = max(maxF, hash[s[r] - 'A']);
        int len = r - l + 1;
        if (len - maxF > k)
        {
            hash[s[l] - 'A']--;
            l++;
        }
        if (len - maxF <= k)
        {
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;
}