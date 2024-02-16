#include <bits/stdc++.h>
using namespace std;
string postToInfix(string s) {
    stack<string> st;
	for(int i = 0;i<s.size();i++){
		char ch = s[i];
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
			st.push(string(1, ch)); 
		}
		else{
			string op2 = st.top();
			st.pop();
			string op1 = st.top();
			st.pop();
			string res = "(";
			res = res + op1 + string(1,ch) + op2 + ')';
			st.push(res);
		}
	}
	return st.top();
}