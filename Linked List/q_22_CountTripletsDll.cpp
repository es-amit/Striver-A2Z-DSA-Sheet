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

Node* getTail(Node* head){
    Node* temp = head;
    while(temp ->next != nullptr){
        temp = temp->next;
    }
    return temp;
}
int GetCounts(Node* first,Node* last,int x){
    int cnt =0;
    while(first != NULL && last != NULL && 
           first != last && last->next != first){
        if(first ->data + last->data == x){
            cnt++;
            first = first->next;
            last = last->prev;
        }
        else if(first ->data + last->data < x){
            first = first->next;
        }
        else{
            last= last->prev;
        }
    }
    return cnt;
}
int countTriplets(Node* head,int x){
    if(head == nullptr) return 0;
    Node* current = head;
    Node* first;
    Node* last = getTail(head);
    int cnt =0;
    while(current->next != nullptr){
        first = current ->next;
        cnt += GetCounts(first,last,x-current->data);
        current = current ->next;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl << countTriplets(head,15);
    return 0;
}
