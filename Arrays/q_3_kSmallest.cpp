#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    
}

int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << kthSmallest(arr,0,n-1,3);
    return 0;
}