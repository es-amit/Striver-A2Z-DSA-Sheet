#include <bits/stdc++.h>
using namespace std;
vector<int> minPartition(int V)
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int M = 10;
    int i = M - 1;
    vector<int> ans;

    while (V != 0 && i >= 0)
    {
        if (V >= coins[i])
        {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
        else
        {
            i--;
        }
    }
    return ans;
}