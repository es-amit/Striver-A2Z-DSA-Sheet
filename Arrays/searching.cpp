#include <bits/stdc++.h>
using namespace std;

int findMinInSortedArray(vector<int> v)
{
    int n = v.size();
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        // check whether array is sorted or not
        if(v[low] == v[mid] && v[mid] == v[high]){
            low +=1;
            high -=1;
        }
        if(v[low]<= v[high]){
            ans = min(ans,v[low]);
            break;
        }
        // check which half is sorted
        if(v[low] <= v[mid]){
            ans = min(ans,v[low]);
            low= mid+1;
        }
        else{
            ans = min(ans,v[mid]);
            high = mid-1;
        }
    }
    return ans;
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
    cout << findMinInSortedArray(arr);
    
    return 0;
}