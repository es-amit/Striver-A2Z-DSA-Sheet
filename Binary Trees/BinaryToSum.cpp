#include <TreeNode.cpp>
using namespace std;
int solve(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        int leafNode = root->data;
        root->data = 0;
        return leafNode;
    }
    int leftAns = 0;
    int rightAns = 0;
    if (root->left)
    {
        leftAns = solve(root->left);
    }
    if (root->right)
    {
        rightAns = solve(root->right);
    }
    int currData = root->data;
    root->data = leftAns + rightAns;
    return currData + root->data;
}