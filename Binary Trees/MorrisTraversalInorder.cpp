#include <TreeNode.cpp>
using namespace std;
vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}