#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char ch = st.top();
            st.pop();
            if ((s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '['))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}