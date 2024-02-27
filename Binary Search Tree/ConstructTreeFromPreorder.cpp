#include <Node.cpp>
using namespace std;
Node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return nullptr;
    }
    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return nullptr;
    }
    Node *root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return solve(preorder, INT_MIN, INT_MAX, i);
}