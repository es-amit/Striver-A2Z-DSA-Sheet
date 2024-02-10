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
Node *ConvertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}
Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *findKThNode(Node *temp, int k)
{
    k -= 1;
    while (k > 0 && temp->next != nullptr)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

struct Node *reverseIt(struct Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *kThNode = findKThNode(temp, k);
        if (kThNode == nullptr)
        {
            if (prev)
                prev->next = temp;
            break;
        }
        Node *nextNode = kThNode->next;
        kThNode->next = nullptr;
        reverseLinkedList(temp);
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            prev->next = kThNode;
        }
        prev = temp;
        temp = nextNode;
    }
    return head;
}