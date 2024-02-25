#include <Node.cpp>
using namespace std;
bool isBST(Node *root, long long min, long long max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool isValidBST(Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;
    return isBST(root, LONG_MIN, LONG_MAX);
}