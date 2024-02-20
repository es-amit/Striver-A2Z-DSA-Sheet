#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr,int k){
    int i = 0;
    int j = 0;
    int sum =0;
    int maxi = 0;
    while(j < arr.size()){
        sum = sum + arr[j];
        if(sum < k){
            j++;
        }
        else if(sum == k){
            maxi = max(maxi,j-i+1);
            j++;
        }
        else if(sum > k){
            while(sum > k){
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }
    return maxi;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << solve(arr,k);
}