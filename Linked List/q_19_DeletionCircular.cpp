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
void deleteNode(struct Node **head, int key)
{
    if (*head == nullptr)
        return;
    Node *prev = (*head);
    Node *temp = (*head)->next;
    while (temp != *head)
    {
        if (temp->data == key)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if ((*head)->data == key)
    {
        Node *last = (*head);
        while (last->next != *head)
            last = last->next;
        last->next = (*head)->next;
        delete *head;
        *head = last->next;
    }
}

/* Function to reverse the linked list */
void reverse(struct Node **head)
{
    if (*head == nullptr || (*head)->next == *head)
        return;

    Node *temp = *head;
    Node *prev = nullptr;
    Node *front = (*head)->next;

    do
    {
        temp->next = prev;
        prev = temp;
        temp = front;
        front = temp->next;
    } while (temp != *head);

    temp->next = prev;
    *head = prev;
}