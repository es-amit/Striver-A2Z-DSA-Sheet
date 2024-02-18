#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            if (!st.empty() && s[st.top()] == '(')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
    }
    int maxi = INT_MIN;
    int curr = s.size();
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        maxi = max(maxi, curr - top - 1);
        curr = top;
    }
    return max(maxi, curr);
}