#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *arb;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->arb = nullptr;
    }

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
void insertCopyInBetween(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}
void changearbPointers(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = temp->next;
        if (temp->arb != nullptr)
        {
            copyNode->arb = (temp->arb)->next;
        }
        else
        {
            copyNode->arb = nullptr;
        }
        temp = temp->next->next;
    }
}
Node *getDeepCopy(Node *head)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    Node *temp = head;
    while (temp != nullptr)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
Node *copyList(Node *head)
{
    insertCopyInBetween(head);
    changearbPointers(head);
    return getDeepCopy(head);
}