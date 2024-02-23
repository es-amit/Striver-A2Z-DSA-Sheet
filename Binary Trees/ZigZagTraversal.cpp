#include <bits/stdc++.h>
#include <TreeNode.cpp>
using namespace std;

vector<int> zigZagTraversal(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // direction change
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            res.push_back(i);
        }
    }
    return res;
}