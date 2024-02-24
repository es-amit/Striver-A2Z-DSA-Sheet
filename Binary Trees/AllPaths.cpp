#include <TreeNode.cpp>
#include <bits/stdc++.h>
using namespace std;
void solve(Node *root, vector<string> &res, string path)
{
    if (root == nullptr)
        return;
    path += to_string(root->data) + " ";
    if (root->left == nullptr && root->right == nullptr)
    {
        res.push_back(path);
        return;
    }
    solve(root->left, res, path);
    solve(root->right, res, path);
}
vector<string> allRootToLeaf(Node *root)
{
    string path = "";
    vector<string> ans;
    solve(root, ans, path);
    return ans;
}