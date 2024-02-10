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
Node *divide(int N, Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *evenHead = new Node(-1);
    Node *oddHead = new Node(-1);
    Node *even = evenHead;
    Node *odd = oddHead;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data % 2 == 0)
        {
            even->next = temp;
            even = temp;
        }
        else
        {
            odd->next = temp;
            odd = temp;
        }
        temp = temp->next;
    }
    odd->next = nullptr;
    even->next = oddHead->next;
    Node *newHead = evenHead->next;
    delete evenHead;
    delete oddHead;
    return newHead;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4,5 ,6};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    head = divide(n,head);
    print(head);
    return 0;
}