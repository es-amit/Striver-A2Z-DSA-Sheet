#include <TreeNode.cpp>

using namespace std;

bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->data != root2->data)
        return false;

    bool leftAns = isIsomorphic(root1->left, root2->left);
    bool rightAns = isIsomorphic(root1->right, root2->right);
    bool leftToRight = isIsomorphic(root1->left, root2->right);
    bool rightToLeft = isIsomorphic(root1->right, root2->left);

    return (leftAns && rightAns) || (leftToRight && rightToLeft);
}