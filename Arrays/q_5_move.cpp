#include<bits/stdc++.h>
using namespace std;

void moveNegativeAndPostive(int arr[], int n)
{
    int i =0, j = n-1;
    while (i<j) 
    {
        if(arr[i]<0){
            i++;
        }
        else{
            if(arr[j] < 0){
                swap(arr[i],arr[j]);
                i++,j--;
            }
            else{
                j--;
            }
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
    moveNegativeAndPostive(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}