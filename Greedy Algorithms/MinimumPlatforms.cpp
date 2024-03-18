#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> trains;
    for (int i = 0; i < n; i++)
    {
        trains.push_back({arr[i], dep[i]});
    }

    sort(trains.begin(), trains.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    int platforms = 1;
    pq.push(trains[0].second);

    for (int i = 1; i < n; i++)
    {
        if (pq.top() < trains[i].first)
        {
            pq.pop();
            pq.push(trains[i].second);
        }
        else
        {
            platforms++;
            pq.push(trains[i].second);
        }
    }
    return platforms;
}