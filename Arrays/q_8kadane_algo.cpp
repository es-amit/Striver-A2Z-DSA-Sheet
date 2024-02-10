#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{

    long long maxi = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (long long)arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxi < 0)
    {
        // all elements are -ve so return maximum one
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, (long long)arr[i]);
        }
    }
    return maxi;
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
    cout << maxSubarraySum(arr, n);
    
    return 0;
}