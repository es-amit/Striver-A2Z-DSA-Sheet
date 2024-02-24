#include <TreeNode.cpp>
using namespace std;
Node *solve(vector<int> &postorder, vector<int> &inorder,
            unordered_map<int, int> &mpp, int &index, int inOrderStart,
            int inOrderEnd)
{
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }
    int element = postorder[index];
    index--; // Increment index after using it
    Node *root = new Node(element);
    int pos = mpp[element];
    root->right = solve(postorder, inorder, mpp, index, pos + 1, inOrderEnd);
    root->left = solve(postorder, inorder, mpp, index, inOrderStart, pos - 1);
    return root;
}
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (postorder.empty() || inorder.empty()) // Check for empty input
        return nullptr;

    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    int index = postorder.size() - 1;                                      // Initialize index for preorder traversal
    return solve(postorder, inorder, mpp, index, 0, postorder.size() - 1); // Update end index for inorder traversal
}