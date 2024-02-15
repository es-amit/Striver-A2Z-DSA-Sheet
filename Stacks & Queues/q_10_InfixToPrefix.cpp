#include <bits/stdc++.h>
using namespace std;
int prec(char ch){
	if(ch == '^') return 3;
	if(ch == '*' || ch == '/') return 2;
	if(ch == '+' || ch == '-') return 1;
	return 0;
	
}
string infixToPrefix(string exp){
    reverse(exp.begin(),exp.end());
	stack<char> st;
	string ans="";
	for(int i=0;i<exp.size();i++){
		char input = exp[i];
		// if this is operand
		if((input >= 'A' && input <= 'Z') || (input >= 'a' && input <= 'z') || (input >= '0' && input <= '9')){
			ans.push_back(input);
		}
		// if this is an operator
		else{
			if(input == ')'){
				st.push(input);
			}
			else if (input == '('){
				while(st.top() != ')'){
					ans.push_back(st.top());
					st.pop();
				}
				st.pop();		// removes ) also
			}
			// this is an operator
			else{
				while(!st.empty() && prec(input) < prec(st.top())){
					ans.push_back(st.top());
					st.pop();
				}
				st.push(input);
			}
		}
	}
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;

}

int main(){
    string s = "x+y*z/w+u";
    cout << infixToPrefix(s);
}