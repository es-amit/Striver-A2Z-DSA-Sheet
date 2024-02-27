#include <Node.cpp>
using namespace std;
void inorderTrav(Node *root, vector<int> &inorder)
{
    if (root == nullptr)
        return;

    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}
Node *inorderToBST(int s, int e, vector<int> &inorder)
{
    if (s > e)
        return nullptr;
    int mid = (s + e) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = inorderToBST(s, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, e, inorder);
    return root;
}
Node *balanceBST(Node *root)
{
    vector<int> inorder;
    inorderTrav(root, inorder);

    return inorderToBST(0, inorder.size() - 1, inorder);
}