#include<bits/stdc++.h>
using namespace std;


int MaxSumSubArray(vector<int> arr,int k){
    int i=0;
    int j = 0;
    int maxi = INT_MIN;
    int sum=0;
    while(j < arr.size()){
        sum = sum + arr[j];
        if((j - i + 1) < k){
            j++;
        }
        else if((j - i+ 1) == k){
            maxi = max(sum,maxi);
            sum = sum -arr[i];
            j++;
            i++;
        }
    }
    return maxi;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << MaxSumSubArray(arr,k);

}