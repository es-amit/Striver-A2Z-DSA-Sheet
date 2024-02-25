#include <Node.cpp>
using namespace std;
int minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}
Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == key)
    {
        // 0 child case
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 child case
        // left child
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child case
        if (root->left != nullptr && root->right != nullptr)
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    root->right = deleteNode(root->right, key);
    return root;
}