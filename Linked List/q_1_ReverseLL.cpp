#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    
    public:
    Node(int data,Node* next){
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
void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << ' ';
        temp = temp-> next;
    }
    
}
Node* ReverseIterative(Node *head)
{
    if(head == nullptr || head-> next == nullptr){
        return head;

    }
    Node* prev = nullptr;
    Node* temp = head;
    Node* front = head->next;
    while(temp != nullptr){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;

}
Node* ReverseRecursive(Node *head)
{
    if(head == nullptr || head-> next == nullptr){
        return head;
    }
    Node* newHead = ReverseRecursive(head->next);
    Node* front = head->next;
    front->next= head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4,5 ,6};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    head = ReverseIterative(head);
    print(head);
    return 0;
}