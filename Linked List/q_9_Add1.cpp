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
Node* reverseList(Node *head)
    {
        // code here
        // return head of reversed list
        if(head == nullptr || head-> next == nullptr){
            return head;
        }
        Node* newHead = reverseList(head->next);
        Node* front = head->next;
        front->next= head;
        head->next = nullptr;
        return newHead;
    }
    Node* addOne(Node *head) 
    {
       if(head == nullptr) return nullptr;
       head = reverseList(head);
       int carry = 1;
       Node* temp =head;
       while(temp != nullptr){
           temp ->data += carry;
           if(temp->data < 10){
               carry =0;
               head = reverseList(head);
               return head;
           }
           temp -> data = 0;
           carry = 1;
           temp =  temp->next;
       }
       head = reverseList(head);
       if(carry != 0){
           Node* newNode = new Node(1);
           newNode -> next = head;
           return newNode;
       }
       return head;
    }