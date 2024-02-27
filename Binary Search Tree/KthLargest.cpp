#include <Node.cpp>
using namespace std;
int countNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
}
int solve(Node *root, int &i, int k)
{
    if (root == nullptr)
        return -1;

    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return solve(root->right, i, k);
}
int kthLargest(Node *root, int K)
{
    int n = countNodes(root);
    int i = 0;
    return solve(root, i, n - K + 1);
}