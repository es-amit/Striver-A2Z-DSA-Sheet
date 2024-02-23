#include <TreeNode.cpp>
#include <bits/stdc++.h>
using namespace std;
int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}