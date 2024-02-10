#include <bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n)
{
    int left[n], right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        result += min(left[i], right[i]) - arr[i];
    }
    return result;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << trappingWater(arr, n);

    return 0;
}