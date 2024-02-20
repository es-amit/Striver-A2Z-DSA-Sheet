#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string s)
{
    if(s.size() == 0) return 0;
    int i =0;
    int j = 0;
    unordered_map<char,int> mpp;
    int maxi = INT_MIN;
    while(j < s.size()){
        mpp[s[j]]++;
        if(mpp.size() == j-i+1){
            maxi = max(maxi,j-i+1);
            j++;
        }
        else if(mpp.size() < j-i+1){
            while(mpp.size() < j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}