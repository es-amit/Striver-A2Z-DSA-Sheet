#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> matrix, int n, int m)
{
    // code here
    int cntMax = 0, ind = -1;
    for (int i = 0; i < n; i++)
    {
        int firstOccurance = lowerBound(matrix[i], m, 1);
        int cnt_Ones = m - firstOccurance;
        if (cnt_Ones > cntMax)
        {
            cntMax = cnt_Ones;
            ind = i;
        }
    }
    return ind;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << rowWithMax1s(matrix, n, m);
    return 0;
}