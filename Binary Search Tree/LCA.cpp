#include <Node.cpp>
using namespace std;


Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == nullptr)
        return nullptr;
    if (root->data > p->data && root->data > q->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    if (root->data < p->data && root->data < q->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}