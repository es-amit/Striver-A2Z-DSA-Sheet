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
Node *removeDuplicates(Node *head)
{
    if(head == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    while(temp != nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp ->data){
            Node* duplicate = nextNode;
            delete duplicate;
            nextNode = nextNode ->next;
        }
        temp ->next = nextNode;
        temp = temp->next;
    }
    return head;
}