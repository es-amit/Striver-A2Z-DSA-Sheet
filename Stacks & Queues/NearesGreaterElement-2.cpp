#include <bits/stdc++.h>
using namespace std;
stack<int> s;
vector<int> NGR(vector<int> &arr, int n)
{
    vector<int> v;
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        int indx = i % n;
        if (s.empty())
        {
            if (i < n)
            {
                v.push_back(-1);
            }
        }
        else if (s.size() > 0 && arr[indx] < s.top())
        {
            if (i < n)
            {
                v.push_back(s.top());
            }
        }
        else if (s.size() > 0 && arr[indx] >= s.top())
        {
            while (s.size() > 0 && arr[indx] >= s.top())
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                if (i < n)
                {
                    v.push_back(-1);
                }
            }
            else
            {
                if (i < n)
                {
                    v.push_back(s.top());
                }
            }
        }
        s.push(arr[indx]);
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> nextGreaterElementII(vector<int> &a)
{
    vector<int> ans = NGR(a, a.size());
    return ans;
}
