#include <Node.cpp>
using namespace std;
bool solve(Node *root, int mini, int maxi)
{
    if (root == nullptr)
        return false;

    if (mini == maxi)
        return true;
    bool left = solve(root->left, mini, root->data - 1);
    bool right = solve(root->right, root->data + 1, maxi);
    return left || right;
}
bool isDeadEnd(Node *root)
{
    return solve(root, 1, INT_MAX);
}