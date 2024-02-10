#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
bool isCircular(Node *head)
{
   if(head == nullptr || head->next == head){
       return true;
   }
   Node* temp = head;
   do{
       temp=temp->next;
       if(temp == head){
           return true;
       }
       
   }while(temp!= nullptr);
   return false;
}

