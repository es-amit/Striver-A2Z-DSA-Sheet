#include <bits/stdc++.h>
using namespace std;

int countOccurence(int arr[], int n, int k) {
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int cnt =0 ;
        for(auto it: mp){
            if(it.second > n/k){
                cnt++;
            }
        }
        return cnt;
    }
int main()
{
    int n,k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countOccurence(arr,n,k);
    
    return 0;
}