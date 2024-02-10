#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
int getNthFromLast(Node *head, int n)
{
    if (head == nullptr)
        return -1;
    Node *fast = head;
    for (int i = 1; i <= n - 1; i++)
    {
        if (fast->next == nullptr)
            return -1;
        fast = fast->next;
    }
    Node *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}