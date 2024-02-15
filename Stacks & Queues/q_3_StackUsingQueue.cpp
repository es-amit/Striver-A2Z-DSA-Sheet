#include<bits/stdc++.h>
using namespace std;

class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
        if(isEmpty()) return -1;
        int last = q1.front();
        q1.pop();
        return last;
    }

    int top() {
        if(isEmpty()) return -1;
        return q1.front();
    }
};