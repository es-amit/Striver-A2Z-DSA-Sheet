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

void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    inorderTraversal( root->left);
    cout << root ->data << ' ';
    inorderTraversal(root->right); 
}

void preorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root ->data << ' ';
    preorderTraversal( root->left);
    preorderTraversal(root->right); 
}

void postorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right); 
    cout << root ->data << ' ';
}
vector<int> levelOrder(Node * root){
    vector<int> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *node = q.front();
            q.pop();
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            ans.push_back(node->data);
        }
        
    }
    return ans;
}

int main(){
    vector<int> arr ={1,2,3,4,5,6,7};
    Node* root = createTree(arr);

    preorderTraversal(root);
    cout << endl;
    inorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
}