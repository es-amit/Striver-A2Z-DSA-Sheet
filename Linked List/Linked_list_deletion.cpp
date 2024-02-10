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

Node* DeleteHead(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* DeleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next != nullptr){
        temp  =temp->next;
    }
    delete(temp->next);
    temp->next= nullptr;
    return head;
}
Node* DeleteElementAtK(Node* head,int k){
    if(head == nullptr){
        return head;
    }
    if(k == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while (temp!=nullptr)
    {
        cnt++;
        if(cnt == k){
            prev ->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* DeleteValue(Node* head,int val){
    if(head == nullptr){
        return head;
    }
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != nullptr)
    {
        if(temp->data == val){
            prev ->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}



int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    head = DeleteValue(head,7);
    print(head);
    return 0;
}
