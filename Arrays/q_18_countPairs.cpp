#include<bits/stdc++.h>
using namespace std;

int countPairs(int arr[],int n,int k){
    int cnt= 0;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = k-a;
        if(mpp.find(more) != mpp.end()){
            cnt += mpp[more];
        }
        mpp[more]++;
    }
    return cnt;
}
int main(){
    int n, k;
    cin >>n >> k;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << countPairs(arr,n,k);
    return 0;
}