#include <bits/stdc++.h>
#include <TreeNode.cpp>
using namespace std;

vector<int> postOrderIterative2Stacks(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != nullptr)
        {
            st1.push(root->left);
        }
        if (root->right != nullptr)
        {
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

void postorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << ' ';
}

vector<int> postOrderTravUsing1Stack(Node *cur)
{

    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;

    stack<Node *> st;
    while (cur != NULL || !st.empty())
    {

        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}