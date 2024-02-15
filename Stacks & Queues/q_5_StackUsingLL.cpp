#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack
{
    int cnt, top;
    Node *head;

public:
    Stack()
    {
        cnt = 0;
        top = -1;
        head = new Node(-1);
    }

    int getSize()
    {
        return cnt;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void push(int data)
    {
        Node *newNode = new Node(data, head);
        head = newNode;
        top += 1;
        cnt += 1;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        top--;
        cnt--;
    }

    int getTop()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};