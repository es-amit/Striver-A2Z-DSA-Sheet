#include <bits/stdc++.h>
using namespace std;
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n)
{

    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 0;
    int lastIndex = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
