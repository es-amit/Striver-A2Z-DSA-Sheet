#include <TreeNode.cpp>
using namespace std;

void flatten(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}