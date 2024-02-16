#include <bits/stdc++.h>
using namespace std;
vector<int> NSR(vector<int> &heights, int n)
{
    vector<int> v;
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            v.push_back(n);
        }
        else if (!st.empty() && heights[i] > st.top().first)
        {
            v.push_back(st.top().second);
        }
        else if (!st.empty() && heights[i] <= st.top().first)
        {
            while (!st.empty() && heights[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(n);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        st.push({heights[i], i});
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> NSL(vector<int> &heights, int n)
{
    vector<int> v;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            v.push_back(-1);
        }
        else if (!st.empty() && heights[i] > st.top().first)
        {
            v.push_back(st.top().second);
        }
        else if (!st.empty() && heights[i] <= st.top().first)
        {
            while (!st.empty() && heights[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        st.push({heights[i], i});
    }
    return v;
}
int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nsr(n);
    vector<int> nsl(n);
    nsr = NSR(heights, n);
    nsl = NSL(heights, n);
    int width[n];
    for (int i = 0; i < n; i++)
    {
        width[i] = nsr[i] - nsl[i] - 1;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, width[i] * heights[i]);
    }
    return ans;
}