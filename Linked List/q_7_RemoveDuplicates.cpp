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
Node *removeDuplicates(Node *head)
{
    unordered_map<int, bool> mpp;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (mpp.find(temp->data) != mpp.end())
        {
            Node *dummyNode = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete dummyNode;
        }
        else
        {
            mpp[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}