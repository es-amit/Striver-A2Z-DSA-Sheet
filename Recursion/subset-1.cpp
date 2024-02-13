#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &num,int sum,int ind,vector<int> &res){
	if(ind == num.size()){
		res.push_back(sum);
		return;
	}
	// not taken
	solve(num, sum, ind+1, res);

	// taken
	solve(num, sum+num[ind], ind+1, res);
	return;
}
vector<int> subsetSum(vector<int> &num){
	vector<int> res;
	solve(num,0,0,res);
	sort(res.begin(),res.end());
	return res;	
}