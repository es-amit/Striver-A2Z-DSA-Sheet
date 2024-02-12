#include<bits/stdc++.h>
using namespace std;
vector<string> allPaths;
void solve(vector<vector<int>> &m, int n, int i, int j, string path)
{
    if (i >= n || j >= n || i < 0 || j < 0 || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        allPaths.push_back(path);
        return;
    }
    m[i][j] = 0;
    // right
    solve(m, n, i, j + 1, path + 'R');
    // down
    solve(m, n, i + 1, j, path + 'D');
    // Left
    solve(m, n, i, j - 1, path + 'L');
    // up
    solve(m, n, i - 1, j, path + 'U');

    m[i][j] = 1;
    return;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    solve(m, n, 0, 0, "");
    return allPaths;
}