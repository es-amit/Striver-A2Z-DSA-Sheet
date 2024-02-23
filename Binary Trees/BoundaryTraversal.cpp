#include <TreeNode.cpp>
using namespace std;
void traverseLeft(Node *root, vector<int> &ans)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if ((root->left == nullptr && root->right == nullptr))
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    ans.push_back(root->data);

    // traverse Left part
    traverseLeft(root->left, ans);

    // traverse the left subtree leaf node

    traverseLeaf(root->left, ans);

    // traverse the right subtree leaf node

    traverseLeaf(root->right, ans);

    // traverse the right subtree

    traverseRight(root->right, ans);

    return ans;
}