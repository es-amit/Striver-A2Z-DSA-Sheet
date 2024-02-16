#include <bits/stdc++.h>
using namespace std;
bool knows(int a, int b, vector<vector<int>> &M)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    return false;
}
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b, M) == true)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    // verify the answer
    int celebrity = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i != celebrity)
        {
            if (knows(celebrity, i, M) != false || knows(i, celebrity, M) != true)
            {
                return -1;
            }
        }
    }
    return celebrity;
}