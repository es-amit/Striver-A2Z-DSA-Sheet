#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){
        if(n==1){
            return 0;
        }
        if(arr[0] == 0){
            return -1;
        }
        int jumps = 0,max1= 0, range=0;
        for(int i=0;i<n;i++){
            max1 = max(max1,i+arr[i]);
            if(range == i){
                range = max1;
                jumps++;
                if(range >=n-1){
                    return jumps;
                }
            }
        }
        return -1;
    }
int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << minJumps(arr,n);
    
    return 0;
}