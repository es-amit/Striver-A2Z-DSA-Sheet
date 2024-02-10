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
Node *findIntersection(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *t1 = head1;
    Node *t2 = head2;
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data == t2->data)
        {
            Node *newNode = new Node(t1->data);
            temp->next = newNode;
            temp = temp->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->data < t2->data)
        {
            t1 = t1->next;
        }
        else
        {
            t2 = t2->next;
        }
    }
    return dummyNode->next;
}