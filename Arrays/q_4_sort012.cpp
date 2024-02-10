#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if (arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort012(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}