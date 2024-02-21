#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
void inorderTraversal(Node *root, vector<int> &inorder)
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
void convertMaxHeap(Node *root, vector<int> &inorder, int &ind)
{
    if (root == nullptr)
    {
        return;
    }

    convertMaxHeap(root->left, inorder, ind);
    convertMaxHeap(root->right, inorder, ind);
    root->data = inorder[ind];
    ind++;
}
void convertToMaxHeapUtil(Node *root)
{
    vector<int> inorder;
    int i = 0;
    inorderTraversal(root, inorder);
    convertMaxHeap(root, inorder, i);
}