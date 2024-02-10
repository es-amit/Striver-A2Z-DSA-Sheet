#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long>& a, long long n, long long m){
        sort(a.begin(),a.end());
        long long ans= LONG_MAX;
        for(int i=0;i<n-m+1;i++){
            long long maxElem = a[i+m-1];
            ans = min(maxElem - a[i],ans);
        }
        return ans;
    
    }
int main()
{
    long long n,m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMinDiff(arr, n,m);

    return 0;
}