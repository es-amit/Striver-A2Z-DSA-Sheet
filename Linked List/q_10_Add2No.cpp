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
Node *reverseList(Node *head)
{
    // code here
    // return head of reversed list
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverseList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
Node *addTwoLists(Node *head1, Node *head2)
{
    Node *t1 = reverseList(head1);
    Node *t2 = reverseList(head2);
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    int carry = 0;
    while (t1 != nullptr || t2 != nullptr)
    {
        int sum = carry;
        if (t1)
            sum += t1->data;
        if (t2)
            sum += t2->data;
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = newNode;
        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    dummyNode = dummyNode->next;
    return reverseList(dummyNode);
}