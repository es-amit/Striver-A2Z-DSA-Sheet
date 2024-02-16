#include <bits/stdc++.h>
using namespace std;
string prefixToInfixConversion(string &s){
	stack<string> st;
	for(int i = s.size()-1;i>= 0;i--){
		char ch = s[i];
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
			st.push(string(1, ch)); 
		}
		else{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			string res = "(";
			res = res + op1 + string(1,ch) + op2 + ')';
			st.push(res);
		}
	}
	return st.top();
}
