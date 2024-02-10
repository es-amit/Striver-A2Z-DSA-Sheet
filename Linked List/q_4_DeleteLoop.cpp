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
void removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    Node *fast = head;
    Node *slow = head;
    Node *prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head;
            while (slow != fast)
            {
                prev = prev->next;
                fast = fast->next;
                slow = slow->next;
            }
            prev->next = nullptr;
        }
    }
}