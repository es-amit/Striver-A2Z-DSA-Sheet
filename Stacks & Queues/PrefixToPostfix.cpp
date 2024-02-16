#include <bits/stdc++.h>
using namespace std;

string preToPost(string s) {
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--){
        char ch = s[i];
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
			st.push(string(1, ch)); 
		}
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string res = op1+op2+string(1, ch);
            st.push(res);
        }
    }
    return st.top();
}