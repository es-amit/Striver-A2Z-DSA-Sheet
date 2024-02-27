#include <Node.cpp>
using namespace std;
void inorder(Node *root, vector<int> &in)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void inorderToBST(Node *root, vector<int> &in, int &i)
{
    if (root == nullptr)
    {
        return;
    }
    inorderToBST(root->left, in, i);
    root->data = in[i++];
    inorderToBST(root->right, in, i);
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> in;
    inorder(root, in);

    sort(in.begin(), in.end());
    int i = 0;
    inorderToBST(root, in, i);
    return root;
}