#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n){
    int buy = arr[0];
    int profit = 0;
    for(int i=1;i<n;i++){
        int cost = arr[i] -buy;
        profit = max(profit,cost);
        buy = min(buy,arr[i]);
    }
    return profit;
}
int main(){
    int n;
    cin >>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << maxProfit(arr,n);
    return 0;
}