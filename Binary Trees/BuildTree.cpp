#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


Node* buildTree(vector<int> &arr,int i,Node* root){
    if(i >= arr.size()){
        return NULL;
    }
    root = new Node(arr[i]);
    root ->left =buildTree(arr, 2*i+1, root->left);
    root ->right = buildTree(arr, 2*i+2, root->right);
    return root;
}
Node* createTree(vector<int>&arr){
    Node* root;
    root = buildTree(arr, 0, root);
    return root;
}









int main(){
    vector<int> arr ={1,2,3,4,5,6,7};
    Node* root = createTree(arr);
}