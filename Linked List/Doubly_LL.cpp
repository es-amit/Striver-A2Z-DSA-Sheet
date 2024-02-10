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

Node* DeleteHead(Node* head){
    if(head == nullptr || head ->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* prev = head;
    head = head->next;
    head-> prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
Node * deleteLastNode(Node *head) {
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* secondLast = tail->prev;
    tail->prev = nullptr;
    secondLast->next = nullptr;
    delete tail;
    return head;
}

Node* deleteKthElement(Node* head,int k){
    if(head == nullptr){
        return nullptr;
    }
    if(k == 1){
        return DeleteHead(head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            Node* back = temp->prev;
            Node* front = temp->next;
            if(back == nullptr && front == nullptr){
                delete temp;
                return nullptr;
            }
            else if(back == nullptr){
                return DeleteHead(head);
            }
            else if(front == nullptr){
                return deleteLastNode(head);
            }
            back -> next= front;
            front->prev = back;
            temp ->next = nullptr;
            temp ->prev = nullptr;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node* deleteElement(Node* head,int elem){
    if(head == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        if(temp->data == elem){
            Node* back = temp->prev;
            Node* front = temp->next;
            if(front == nullptr){
                return deleteLastNode(head);
            }
            back -> next= front;
            front->prev = back;
            temp ->next = nullptr;
            temp ->prev = nullptr;
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
    head= deleteElement(head,7);
    print(head);
    return 0;
}
