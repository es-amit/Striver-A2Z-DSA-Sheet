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

class Queue
{
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int pop()
    {
        if (front == nullptr)
        {
            return -1;
        }
        Node *temp = front;
        int data = front->data;
        front = front->next;
        delete temp;
        return data;
    }

   
};