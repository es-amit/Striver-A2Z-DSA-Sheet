#include <TreeNode.cpp>
using namespace std;
Node *solve(vector<int> &preorder, vector<int> &inorder,
            unordered_map<int, int> &mpp, int &index, int inOrderStart,
            int inOrderEnd)
{
    if (index >= preorder.size() || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }
    int element = preorder[index];
    index++; // Increment index after using it
    Node *root = new Node(element);
    int pos = mpp[element];
    root->left =
        solve(preorder, inorder, mpp, index, inOrderStart, pos - 1);
    root->right = solve(preorder, inorder, mpp, index, pos + 1, inOrderEnd);
    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() || inorder.empty()) // Check for empty input
        return nullptr;

    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    int index = 0; // Initialize index for preorder traversal
    return solve(preorder, inorder, mpp, index, 0,
                 preorder.size() -
                     1); // Update end index for inorder traversal
}