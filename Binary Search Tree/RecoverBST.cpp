#include <Node.cpp>
using namespace std;
class Solution
{
public:
    Node *first;
    Node *prev;
    Node *middle;
    Node *last;
    void inorder(Node *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);
        if (prev != nullptr && root->data < prev->data)
        {
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(Node *root)
    {
        first = last = middle = nullptr;
        inorder(root);
        if (first && last)
            swap(first->data, last->data);
        else
        {
            swap(first->data, middle->data);
        }
    }
};