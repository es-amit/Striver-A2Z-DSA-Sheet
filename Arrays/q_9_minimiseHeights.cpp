#include <bits/stdc++.h>
using namespace std;

int minimiseHeights2(int arr[], int n, int k)
{
    // 1) sort the array
    sort(arr, arr + n);
    // initialise the result with last - first element
    int result = arr[n - 1] - arr[0];

    int maxi;
    int mini;
    // 3) iterate over the array
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
        }
        else
        {
            maxi = arr[n - 1] - k;
        }

        // taking out the mini
        mini = min(arr[i] - k, arr[0] + k);

        if (mini < 0)
        {
            continue;
        }
        result = min(result, maxi - mini);
    }
    return result;
}
int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minimiseHeights2(arr, n, k);

    return 0;
}