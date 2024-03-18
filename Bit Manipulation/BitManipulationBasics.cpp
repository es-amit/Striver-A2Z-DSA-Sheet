#include<bits/stdc++.h>
using namespace std;
int getBit(int num,int i){
    return (num >> i) & 1;
}
int setBit(int num,int i){
    return num | (1<<i);
}
int clearBit(int num,int i){
    return num & ~(1<<i);
}

vector<int> bitManipulation(int num, int i){
    vector<int> ans;
    ans.push_back(getBit(num, i-1));
    ans.push_back(setBit(num, i-1));
    ans.push_back(clearBit(num, i-1));
    return ans;
}