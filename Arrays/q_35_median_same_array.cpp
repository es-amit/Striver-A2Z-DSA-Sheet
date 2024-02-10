#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    if (n % 2 != 0)
    {
        return v[n / 2];
    }
    int first = v[(n / 2) - 1];
    int second = v[(n / 2)];
    return (first + second) / 2;
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
    cout << find_median(arr);
    
    return 0;
}