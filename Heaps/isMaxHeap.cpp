#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int countNodes(struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1 + left + right;
}

bool isCBT(struct Node *root, int index, int n)
{
    if (root == nullptr)
    {
        return true;
    }
    if (index >= n)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, index * 2 + 1, n);
        bool right = isCBT(root->right, index * 2 + 2, n);
        return left && right;
    }
}

bool isMaxHeap(struct Node *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return true;
    }
    if (root->right == nullptr)
    {
        return root->data > root->left->data;
    }
    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
    return (left && right && root->data > root->left->data && root->data > root->right->data);
}
bool isHeap(struct Node *tree)
{
    int n = countNodes(tree);
    if (isCBT(tree, 0, n) && isMaxHeap(tree))
    {
        return true;
    }
    return false;
}