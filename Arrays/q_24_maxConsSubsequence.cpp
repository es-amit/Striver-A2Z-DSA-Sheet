#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
      map<int,int> mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]++;
      }
      int ans =0,cnt = 0;
      for(int i=0;i<mp.size();i++){
          if(mp[i]>0){
              cnt++;
          }
          else{
              ans = max(ans,cnt);
              cnt = 0;
          }
      }
      ans = max(cnt,ans);
      return ans;
    }
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findLongestConseqSubseq(arr,n);
    
    return 0;
}