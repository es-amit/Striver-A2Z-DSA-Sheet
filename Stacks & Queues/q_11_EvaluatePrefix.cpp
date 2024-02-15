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

int evaluatePrefix(string s) {
    stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--) {
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
    string s = "+9*26";
    cout << evaluatePrefix(s);
    return 0;
}
