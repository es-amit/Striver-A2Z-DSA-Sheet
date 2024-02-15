#include<bits/stdc++.h>
using namespace std;

int evaluate2Num(int op1, int op2, char op) {
    switch (op) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '/':
        return op1 / op2;
    case '*':
        return op1 * op2;
    case '^':
        return pow(op1,op2); 
    default:
        return 0;
    }
}

int evaluatePostfix(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res = evaluate2Num(op1, op2, ch);
            st.push(res);
        }
    }
    return st.top();
}

int main() {
    string s = "231*+9-";
    cout << evaluatePostfix(s);
    return 0;
}
