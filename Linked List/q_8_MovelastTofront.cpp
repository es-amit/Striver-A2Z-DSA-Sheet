#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

public:
    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

public:
    ListNode(int data, ListNode *next)
    {
        this->data = data;
        this->next = next;
    }
};
ListNode *moveToFront(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    prev->next = nullptr;
    return temp;
}