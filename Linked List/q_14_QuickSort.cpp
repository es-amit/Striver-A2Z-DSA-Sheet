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
Node* getTail(Node* head){
    Node* temp = head;
    while(temp ->next!= nullptr){
        temp = temp->next;
    }
    return temp;
}
Node* partition(Node* head,Node* tail){
    Node* pivot = head;
    Node* prev = head;
    Node* curr = head->next;
    while(curr != tail->next){
        if(pivot->data > curr->data){
            swap(prev->next->data,curr->data);
            prev = prev->next;
        }
        curr= curr->next;
    }
    swap(prev->data,pivot->data);
    return prev;
    
}
void solveSort(Node* head,Node* tail){
    if(head == nullptr || head->next == nullptr || head== tail) return;
    
    Node* pivot = partition(head,tail);
    solveSort(head,pivot);
    solveSort(pivot->next, tail);
}
void quickSort(struct Node **headRef) {
    Node* head = *headRef;
    if(head == nullptr || head->next == nullptr) return;
    Node* tail = getTail(head);
    solveSort(head,tail);
}