#include<bits/stdc++.h>
using namespace std;

void mergeInterval(vector<int>& arr,int n){
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(),arr.end());
        return;
    }
    for(int i = n-1;i>ind;i--){
        if(arr[i] > arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin()+ind+1,arr.end());

}
int main(){
    vector<int> arr = {2,1,5,4,3,0,0};
    int n = arr.size();
    mergeInterval(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }


    return 0;
}