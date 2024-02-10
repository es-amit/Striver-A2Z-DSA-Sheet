#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
        int carry = 0,multi = 0;
        vector<int> ans;
        ans.push_back(1);
        
        for(int i=2;i<=N;i++){
            
            for(int j=0;j<ans.size();j++){
                multi = (ans[j]*i) +carry;
                ans[j] = multi % 10;
                carry = multi /10;
            }
            while(carry != 0){
                ans.push_back(carry%10);
                carry = carry/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main(){
    int n;
    cin >>n;
    vector<int> ans = factorial(n);
    for(int i =0 ;i<n;i++){
        cout << ans[i];
    }
    return 0;
}