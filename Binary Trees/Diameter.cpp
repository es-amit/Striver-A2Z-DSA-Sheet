#include <TreeNode.cpp>
using namespace std;

int solve(Node *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    int lh = solve(root->left, diameter);
    int rh = solve(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root)
{
    int diameter = 0;
    solve(root, diameter);
    return diameter;
}