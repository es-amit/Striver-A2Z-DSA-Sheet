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
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast ->next != head){
        slow = slow->next;
        fast = fast->next;
        if(fast ->next == head) break;
        fast = fast->next;
    }
    Node* temp = slow ->next;
    slow ->next = head;
    *head1_ref = head;
    fast ->next = temp;
    *head2_ref = temp;
}