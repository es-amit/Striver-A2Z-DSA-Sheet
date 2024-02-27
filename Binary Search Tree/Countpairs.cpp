#include <Node.cpp>
using namespace std;
void inorder(Node *root, vector<int> &in)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> inorder1, inorder2;
    inorder(root1, inorder1);
    inorder(root2, inorder2);
    int i = 0;
    int j = inorder2.size() - 1;
    int count = 0;
    while (i < inorder1.size() && j >= 0)
    {
        if (inorder1[i] + inorder2[j] == x)
        {
            count++;
            i++;
            j--;
        }
        else if (inorder1[i] + inorder2[j] < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;
}