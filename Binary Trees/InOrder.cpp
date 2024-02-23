#include <bits/stdc++.h>
#include <TreeNode.cpp>
using namespace std;

void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    inorderTraversal( root->left);
    cout << root ->data << ' ';
    inorderTraversal(root->right); 
}
vector<int> inorderIterative(Node* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        stack<Node*> st;
        Node* node = root;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }