#include <bits/stdc++.h>
// #include <Node.cpp>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
    public:
    Node(int data,Node* next,Node* prev){
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
    
};

Node* ConvertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i],nullptr,temp);
        temp->next = newNode;
        temp = newNode;
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
Node* InsertHead(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* newNode = new Node(val,head,nullptr);
    head -> prev= newNode;
    return newNode;
}
Node* InsertTail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail =tail->next;
    }
    Node* newNode = new Node(val,nullptr,tail);
    tail ->next = newNode;
    return head;
    
}
Node* InsertAtK(Node* head,int val,int k){
    if(head == nullptr){
        return new Node(val);
    }
    if(k == 1){
        return InsertHead(head,val);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp ->next != nullptr){
        cnt++;
        if(cnt == k){
            Node* back = temp->prev;
            Node* front = temp->next;
            if(front == nullptr){
                return InsertTail(head,val);
            }
            else if(back == nullptr){
                return InsertHead(head,val);
            }
            Node* newNode= new Node(val,front,back);
            back->next = newNode;
            front->prev = newNode;
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
    head = InsertAtK(head,34,3);
    print(head);
    return 0;
}
