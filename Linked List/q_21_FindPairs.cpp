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
Node* findTail(Node* head){
        Node* fast = head;
        while(fast ->next != nullptr && fast->next->next != nullptr){
            fast =fast->next->next;
        }
        if(fast ->next == nullptr){
            return fast;
        }
        return fast->next;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int k)
    {
       vector<pair<int, int>> ans;
        if(head == nullptr) return ans;
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right-> data){
            if(left->data + right-> data == k){
                ans.push_back({left->data,right->data});
                left = left->next;
                right= right->prev;
            }
            else if(left->data + right-> data < k){
                left = left->next;
            }
            else{
                right= right->prev;
            }
        }
        return ans;
       
    }