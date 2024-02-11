#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int elem){
	if(s.size() == 0 || s.top() <= elem){
		s.push(elem);
		return;
	}
	int val = s.top();
	s.pop();
	insert(s,elem);
	s.push(val);
	return;
}
void sort(stack<int> &s){
	if(s.size() == 1){
		return;
	}
	int temp = s.top();
	s.pop();
	sort(s);
	insert(s, temp);
	return;
}

stack<int> sortStack(stack<int> &s)
{
	if(s.empty()) return s;
	sort(s);
	return s;
}

int main(){
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(8);
    s.push(3);
    s.push(4);
    s = sortStack(s);
}