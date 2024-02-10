#include<bits/stdc++.h>
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
Node * mergeKLists(Node *arr[], int K)
    {
         priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
         for(int i=0;i<K;i++){
             pq.push({arr[i]->data,arr[i]});
         }
         Node* dummyNode = new Node(-1);
         Node* temp = dummyNode;
         while(!pq.empty()){
             pair<int,Node*> p = pq.top();
             temp -> next = p.second;
             pq.pop();
             if(p.second->next){
                 pq.push({p.second->next->data,p.second->next});
             }
             temp = temp->next;
         }
         return dummyNode ->next;
    }