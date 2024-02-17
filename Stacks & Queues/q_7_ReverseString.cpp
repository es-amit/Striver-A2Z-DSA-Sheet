#include<bits/stdc++.h>
using namespace std;
char* reverse(char *S, int len)
{
    stack<int> st;
    for(int i=0;i<len;i++){
        st.push(S[i]);
    }
    for(int i=0;i<len;i++){
        S[i] = st.top();
        st.pop();
    }
    return S;
}