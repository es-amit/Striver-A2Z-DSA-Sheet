#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}
int upperBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
vector<int> find(int arr[], int n, int x)
{
    int first = lowerBound(arr, n, x);
    if (first == -1)
    {
        return {-1, -1};
    }
    int last = upperBound(arr, n, x);
    return {first, last};
}
int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = find(arr, n, x);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
