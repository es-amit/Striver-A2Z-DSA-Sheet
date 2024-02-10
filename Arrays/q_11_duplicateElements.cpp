#include<bits/stdc++.h>
using namespace std;

int duplicateElemets(int nums[],int n){
    for(int i =0;i<n;i++){
        int idx= abs(nums[i]);
        if(nums[idx]<0){
            return idx;
        }
        nums[idx] = -nums[idx];
    }
    return n;
    
}
int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << duplicateElemets(arr,n);
    return 0;
}