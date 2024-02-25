#include <TreeNode.cpp>
using namespace std;
void solve(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    if (root->left)
    {
        solve(root->left);
    }
    if (root->right)
    {
        solve(root->right);
    }
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return;
}
void mirror(Node *node)
{
    if (node == nullptr)
        return;
    solve(node);
}