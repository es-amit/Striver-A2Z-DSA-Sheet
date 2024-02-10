#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n)
{
    long long maxi = LONG_MIN;
    long long prefix = 1;
    long long suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }
        prefix = prefix * (long long)arr[i];
        suffix = suffix * (long long)arr[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr, n);

    return 0;
}