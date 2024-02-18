#include <bits/stdc++.h>
using namespace std;

void solve(queue<int> &q)
{
    if (q.size() == 1)
    {
        return;
    }
    int temp = q.front();
    q.pop();
    solve(q);
    q.push(temp);
    return;
}
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}