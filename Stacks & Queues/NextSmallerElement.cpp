#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> arr){
    stack<int> s;
    vector<int> v;
    for(int i= arr.size()-1;i>= 0 ;i--){
        if(s.empty()){
            s.push(arr[i]);
            v.push_back(-1);
            continue;
        }
        else if(!s.empty()  && arr[i] > s.top()){
            v.push_back(s.top());
        }
        else{
            v.push_back(-1);
        }
        s.pop();
        s.push(arr[i]);
        
    }
    reverse(v.begin(),v.end());
    return v;
}

int main(){
    vector<int> arr;
    int n ;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> ans(n);
    ans = NSL(arr);
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
}