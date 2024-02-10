#include <bits/stdc++.h>
// #include <Node.cpp>
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
int intersectPoint(Node* head1, Node* head2)
{
    if(head1 == nullptr || head2 == nullptr) return -1;
    Node* t1 =head1;
    Node* t2 =head2;
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
        if(t1 == t2){
            if(t1 == nullptr) return -1;
            return t1->data;
        }
        if(t1 == nullptr) t1 = head2;
        if(t2 == nullptr) t2 = head1;
    }
    return -1;
}