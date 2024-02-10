#include<bits/stdc++.h>
using namespace std;

void rightRotate(int arr[],int n,int outofPlace,int curr){
    int temp = arr[curr];
    for(int i=curr;i>outofPlace;i--){
        arr[i] = arr[i-1];
    }
    arr[outofPlace] = temp;
}
void rearrangeArray(int arr[],int n){
    int outofPlace = -1;
    for(int i = 0;i<n;i++){
        if(outofPlace>=0){
            if((arr[i] >=0 && arr[outofPlace]<0)||(arr[i] <0 && arr[outofPlace]>=0)){
                rightRotate(arr,n,outofPlace,i);
            }
            if(i - outofPlace >=2){
                outofPlace+=2;
            }
            else{
                outofPlace = -1;
            }
        }
        if(outofPlace == -1){
            if((arr[i] >=0 && i%2==0) || (arr[i] <0 && i%2!=0)){
                outofPlace = i;
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
    rearrangeArray(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    return 0;
}