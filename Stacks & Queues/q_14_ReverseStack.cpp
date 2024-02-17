#include <bits/stdc++.h>
using namespace std;
void addFront(stack<int> &st, int data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    addFront(st, data);
    st.push(temp);
    return;
}
void Reverse(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int data = st.top();
    st.pop();
    Reverse(st);
    addFront(st, data);
    return;
}