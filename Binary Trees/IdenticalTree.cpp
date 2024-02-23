#include <bits/stdc++.h>
#include <TreeNode.cpp>

using namespace std;

bool isSameTree(Node *node1, Node *node2)
{
    if (node1 == NULL && node2 == NULL)
        return true;
    else if (node1 == NULL || node2 == NULL)
        return false;

    return ((node1->data == node2->data) &&
            isSameTree(node1->left, node2->left) &&
            isSameTree(node1->right, node2->right));
}