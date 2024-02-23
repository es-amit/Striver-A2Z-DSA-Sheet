#include <TreeNode.cpp>
using namespace std;
int height(Node *root)
{
    if (root == nullptr)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}
bool isBalanced(Node *root)
{
    return height(root) != -1;
}