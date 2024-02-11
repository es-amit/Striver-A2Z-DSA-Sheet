#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int elem){
    if(s.size() == 0){
        s.push(elem);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s,elem);
    s.push(temp);
}
void reverseStack(stack<int> &s) {
    if(s.size() == 1){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insert(s, temp);
    return;

}

int main(){
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(8);
    s.push(3);
    s.push(4);
    reverseStack(s);
}