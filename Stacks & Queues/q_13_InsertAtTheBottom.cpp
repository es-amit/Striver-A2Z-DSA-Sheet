#include<bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &s,int data){
    if(s.size() == 0){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s,data);
    s.push(temp);
    return;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);


    insertAtBottom(s,9);
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

}