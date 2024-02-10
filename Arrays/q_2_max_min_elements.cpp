#include<bits/stdc++.h>
using namespace std;

void maxMinElements(int arr[],int n){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        mini = min(mini,arr[i]);
    }
    cout << mini << ' ' << maxi;
}

int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    maxMinElements(arr,n);
    return 0;
}