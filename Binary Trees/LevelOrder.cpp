#include <bits/stdc++.h>
#include <TreeNode.cpp>
using namespace std;

vector<int> levelOrder(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            ans.push_back(node->data);
        }
    }
    return ans;
}

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q;
    stack<int> st;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        st.push(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}