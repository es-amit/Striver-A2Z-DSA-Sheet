#include<bits/stdc++.h>
using namespace std;


void mergeArrays(vector<int>& arr1, vector<int>& arr2,int n,int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right <m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left],arr2[right]);
            right ++;
            left --;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

void swapIfGreater(vector<int>& arr1, vector<int>& arr2,int left,int right){
    if(arr1[left] > arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}
void mergeWithOptimal(vector<int>& arr1, vector<int>& arr2,int n,int m){
    int len = n+m;
    int gap = (len)/2 + (len)%2;
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            if(left < n && right >= n){
                swapIfGreater(arr1,arr2,left,right-n);
                
            }
            else if(left >= n){
                swapIfGreater(arr1,arr2,left-n,right -n);
            }
            else{
                swapIfGreater(arr1,arr2,left,right);
            }
            left++;
            right++;
        }
        if(gap == 1){
            break;
        }
        gap = gap/2 + gap%2;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}


int main(){
    int n,m;
    cin >>n >> m;
    vector<int> arr1(n), arr2(m);
    for(int i =0;i<n;i++){
        cin >> arr1[i];
    }
    for(int i =0;i<m;i++){
        cin >> arr2[i];
    }

    mergeWithOptimal(arr1,arr2,n,m);

    for(int i =0;i<n;i++){
        cout << arr1[i] << ' ';
    }
    cout << endl;
    for(int i =0;i<m;i++){
        cout << arr2[i] << ' ';
    }
    return 0;
}