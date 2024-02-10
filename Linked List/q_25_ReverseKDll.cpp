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
Node* reverseDLL(Node* head)
{   
    if(head == nullptr || head -> next == nullptr) {
        return head;
    }
    Node* last = NULL;
    Node* current = head;
    while(current != nullptr){
        last = current -> prev;
        current-> prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last -> prev;
}
Node *findKThNode(Node *temp, int k)
{
    k -= 1;
    while (k > 0 && temp -> next != nullptr)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *reverseIt(Node *head, int k)
{
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *kThNode = findKThNode(temp, k);
        if (kThNode == nullptr)
        {
            if (prev)
                prev->next = temp;
            break;
        }
        Node *nextNode = kThNode->next;
        kThNode->next = nullptr;
        if(nextNode != nullptr) nextNode -> prev = nullptr;
        reverseDLL(temp);
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            prev->next = kThNode;
            kThNode ->prev = prev;
        }
        prev = temp;
        temp = nextNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4,5,6,7,8};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
    print(head);
    cout << endl;
    head = reverseIt(head,3);
    print(head);
    return 0;
}

