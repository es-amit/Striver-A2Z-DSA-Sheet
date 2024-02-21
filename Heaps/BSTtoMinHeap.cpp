#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{

public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
void inorderTraversal(BinaryTreeNode *root, vector<int> &inorder)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
    return;
}
void convertMinHeap(BinaryTreeNode *root, vector<int> &inorder, int &ind)
{
    if (root == nullptr)
    {
        return;
    }
    root->data = inorder[ind];
    ind++;
    convertMinHeap(root->left, inorder, ind);
    convertMinHeap(root->right, inorder, ind);
}
BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> inorder;
    int i = 0;
    inorderTraversal(root, inorder);
    convertMinHeap(root, inorder, i);
    return root;
}