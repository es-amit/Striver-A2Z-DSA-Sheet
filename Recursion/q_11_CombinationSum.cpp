#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void solve(vector<int> arr, int k, int sum, vector<int> op, int n)
{
    if (sum == k)
    {
        ans.push_back(op);
        return;
    }
    if (n < 0 || sum > k)
    {
        return;
    }
    // include
    if (arr[n] <= k)
    {
        op.push_back(arr[n]);
        solve(arr, k, sum + arr[n], op, n);
        op.pop_back();
    }
    // exclude

    solve(arr, k, sum, op, n - 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> op;
    solve(candidates, target, 0, op, candidates.size() - 1);
    return ans;
}