#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt)
{
    int k = pat.size();
    map<char, int> mpp;
    for (int i = 0; i < k; i++)
    {
        mpp[pat[i]]++;
    }

    int i = 0;
    int j = 0;
    int count = mpp.size();
    int ans = 0;
    while (j < txt.size())
    {
        // calculations
        char ch = txt[j];
        if (mpp.find(ch) != mpp.end())
        {
            mpp[ch]--;
            if (mpp[ch] == 0)
            {
                count--;
            }
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            // ans from calculations

            if (count == 0)
            {
                ans++;
            }
            // slide the window
            char ch1 = txt[i];
            if (mpp.find(ch1) != mpp.end())
            {
                mpp[txt[i]]++;
                if (mpp[txt[i]] == 1)
                    count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}