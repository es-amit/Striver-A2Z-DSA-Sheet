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
Node *merge2Lists(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        temp->next = nullptr;
    }
    if (l1)
        temp->next = l1;
    else
        temp->next = l2;
    return dummyNode->next;
}

Node *findMiddle(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *middle = findMiddle(head);
    Node *firstHead = head;
    Node *secondHead = middle->next;
    middle->next = nullptr;
    firstHead = mergeSort(firstHead);
    secondHead = mergeSort(secondHead);
    return merge2Lists(firstHead, secondHead);
}