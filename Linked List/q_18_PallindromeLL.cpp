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

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    Node *temp = head;
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
}
Node *ConvertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], nullptr);
        temp->next = newNode;
        temp = newNode;
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
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *temp = head;
    Node *front = head->next;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool isPalindromeOptimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    // step-1 find the middle
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // step-2 reverse the half
    Node *newHead = reverseLinkedList(slow->next);

    // step-3 comparing the second half with first half
    Node *first = head;
    Node *second = newHead;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            newHead = reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    newHead = reverseLinkedList(newHead);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    Node *head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    cout << isPalindromeOptimal(head);
    cout << endl;
    return 0;
}