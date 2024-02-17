#include<bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeInEveryWindow(vector<int> arr,int k){
    vector<int> ans(arr.size());
    queue<int> q;
    int i = 0;
    int j =0;
    while( j < arr.size()){
        // calculation
        if(arr[j] < 0){
            q.push(arr[i]);
        }
        if(j-i+1 < k){
            j++;
        }
        else if( j- i+1 == k){
            // ans from calculations
            if(q.size() == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
                // slide the window
                if(arr[i] == q.front()){
                    q.pop();
                }
                i++;
                j++;
            }
        }
    }
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> ans(n);
    ans =  FirstNegativeInEveryWindow(arr,k);
    
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }

}