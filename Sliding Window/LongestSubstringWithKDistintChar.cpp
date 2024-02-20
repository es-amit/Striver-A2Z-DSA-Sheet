#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str)
{
    int i=0;
    int j = 0;
    unordered_map<char,int> mpp;
    int maxi = INT_MIN;
    while(j < str.size()){
        char ch = str[j];
        mpp[ch]++;
        if(mpp.size() < k){
            j++;
        }
        else if(mpp.size() == k){
            maxi = max(maxi,j-i+1);
            j++;
        }
        else if(mpp.size() > k){
            while(mpp.size() >k){
                mpp[str[i]]--;
                if(mpp[str[i]] == 0){
                    mpp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}


