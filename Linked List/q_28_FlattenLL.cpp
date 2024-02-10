#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* bottom;
    Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

Node* merge2Lists(Node* l1,Node* l2){
    Node* dummyNode= new Node(-1);
    Node* temp = dummyNode;
    while(l1 != nullptr && l2 != nullptr){
        if(l1 -> data < l2 -> data){
            temp -> bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
        else{
            temp -> bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
        temp -> bottom = nullptr;
    }
    if(l1) temp -> bottom = l1;
    else temp -> bottom = l2;
    return dummyNode -> bottom;
}
Node *flatten(Node *root)
{
    if(root == nullptr || root -> next == nullptr) return root;
    Node* mergeHead = flatten(root -> next);
    return merge2Lists(root,mergeHead);
   
}