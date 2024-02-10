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
int getLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
Node* getTail(Node* head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp;
}
Node* newHead(Node* head,int N){
    Node* temp = head;
    while(N > 0){
        N--;
        temp = temp->next;
    }
    return temp;
}
Node* RotateByN(Node* head,int N){
    if(head == nullptr || head->next == nullptr) return head;
    N = N % getLength(head);
    Node* tail = getTail(head);
    Node* temp = newHead(head,N);
    tail->next = head;
    head->prev = tail;
    (temp->prev)->next = nullptr;
    temp->prev = nullptr;
    return temp;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    head = RotateByN(head,11);
    print(head);
    return 0;
}
