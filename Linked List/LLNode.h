
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
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

#endif // LINKEDLIST_H