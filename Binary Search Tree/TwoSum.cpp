#include<Node.cpp>
using namespace std;

void inorderTrav(Node *root, vector<int> &inorder)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}
bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    inorderTrav(root, inorder);

    // 2 pointer approach
    int i = 0;
    int j = inorder.size() - 1;
    while (i < j)
    {
        if (inorder[i] + inorder[j] == k)
        {
            return true;
        }
        else if (inorder[i] + inorder[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}