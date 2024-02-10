#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    
    public:
    Node(int data,Node* next,Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
};

Node* reverseDLL(Node * head)
    {
        if(head == nullptr || head ->next == nullptr){
            return head;
        }
        Node* temp = head;
        Node* front = head->next;
        Node* back = nullptr;
        while(temp != nullptr){
            temp->next = back;
            temp -> prev = front;
            back = temp;
            temp = temp-> prev;
            if(temp){
                front = temp->next;
            }
        }
        return back;
    }
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

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    head = reverseDLL(head);
    print(head);
    cout << endl;
    return 0;
}