#include <Node.cpp>
using namespace std;
void inorder(struct Node *root, vector<int> &in)
{
    if (root == nullptr)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
float findMedian(struct Node *root)
{
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    if (n % 2 == 0)
    {
        return (in[n / 2] + in[(n / 2) - 1]) / 2.0;
    }
    return in[n / 2];
}