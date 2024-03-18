#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
static bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> v;
    for (int i = 0; i < n; i++)
    {
        double perUnitVal = (1.0 * arr[i].value) / arr[i].weight;
        v.push_back({perUnitVal, arr[i]});
    }

    sort(v.begin(), v.end(), cmp);

    double totalVal = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second.weight > W)
        {
            totalVal += v[i].first * W;
            W = 0;
        }
        else
        {
            totalVal += v[i].second.value;
            W -= v[i].second.weight;
        }
    }
    return totalVal;
}