#include<bits/stdc++.h>
using namespace std;
void placeOnRightPlace(stack<int> &st, int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    if(st.top() <= data){
        st.push(data);
        return;
    }
    int temp = st.top();
    st.pop();
    placeOnRightPlace(st,data);
    st.push(temp);
    return;
}
void sort(stack<int> &s)
{
   if(s.size() == 1){
       return;
   }
   int temp = s.top();
   s.pop();
   sort(s);
   placeOnRightPlace(s,temp);
   return;
}
