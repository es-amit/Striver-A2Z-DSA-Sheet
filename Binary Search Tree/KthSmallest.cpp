#include <Node.cpp>
using namespace std;

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
int KthSmallestElement(Node *root, int K)
{
    int i = 0;
    return solve(root, i, K);
}