#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(Node* root,int val){
    if(root == nullptr){
        root = new Node(val);
        return root;
    }
    if(val > root->data){
        root->right = insert(root->right,val);
    }
    else{
        root->left = insert(root->left ,val);
    }
    return root;
}

void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root ->data << ' ';
    inorder(root->right);
}

int main(){
    int data;
    cin >> data;
    Node* root = nullptr;
    while(data != -1){
        insert(root,data);
        cin >> data;
    }

    inorder(root);
}