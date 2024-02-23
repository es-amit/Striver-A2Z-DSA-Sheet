#include <bits/stdc++.h>
#include <TreeNode.cpp>
using namespace std;

void preorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

vector<int> preorderIterative(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    stack<Node *> st;
    Node *temp = root;
    st.push(temp);
    while (!st.empty())
    {
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->right != nullptr)
        {
            st.push(temp->right);
        }
        if (temp->left != nullptr)
        {
            st.push(temp->left);
        }
    }
    return ans;
}