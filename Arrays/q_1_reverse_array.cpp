#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[],int n){
    int left = 0;
    int right = n-1;
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
    return;
}
int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    reverseArray(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}