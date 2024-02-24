#include <TreeNode.cpp>
using namespace std;
bool solve(Node *r1, Node *r2)
{
    if (r1 == nullptr && r2 == nullptr)
        return true;
    if (r1 == nullptr || r2 == nullptr)
        return false;
    if (r1->data != r2->data)
        return false;
    bool left = solve(r1->left, r2->right);
    bool right = solve(r1->right, r2->left);
    return left && right;
}
bool isSymmetric(Node *root)
{
    return solve(root, root);
}