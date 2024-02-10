#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeInterval(vector<vector<int>> arr,int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && start <= ans.back()[1] ){
            if(end > ans.back()[1]){
                ans.back()[1] = end;
            }
            else{
                // do nothing, eat 5 star
            }
        }
        else{
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    int n = arr.size();
    vector<vector<int>> ans = mergeInterval(arr,n);

    for(int i=0;i<ans.size();i++){
        for(int j = 0;j<2;j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}