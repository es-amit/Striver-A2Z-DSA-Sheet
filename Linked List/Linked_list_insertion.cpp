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
Node* InsertionHead(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    return new Node(val,head);
}

Node* InsertionTail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp  = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp ->next = newNode;
    return head;

}

Node* InsertionAtK(Node* head,int elem,int k){
    if(head == NULL){
        if(k == 1)
            return new Node(elem);
        else
            return nullptr;
    }
    if(k== 1){
        return new Node(elem,head);
    }
    int cnt =0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* newNode= new Node(elem);
            newNode ->next = temp ->next;
            temp ->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node* InsertionBeforeX(Node* head,int elem,int x){
    if(head == NULL){
        return new Node(elem);
    }
    if(head ->data == x){
        return new Node(elem,head);
    }
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data <= x){
            Node* newNode= new Node(elem);
            newNode ->next = temp ->next;
            temp ->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}



int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    head = InsertionBeforeX(head,10,12);
    print(head);
    return 0;
}
