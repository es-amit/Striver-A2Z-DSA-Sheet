#include <Node.cpp>
using namespace std;
void inorderTrav(Node *root, vector<int> &inorder)
{
    if (root == nullptr)
        return;

    inorderTrav(root->left, inorder);
    inorder.push_back(root->data);
    inorderTrav(root->right, inorder);
}

vector<int> mergeTwoArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        ans.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
Node *inorderToBST(int s, int e, vector<int> &inorder)
{
    if (s > e)
        return nullptr;
    int mid = (s + e) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = inorderToBST(s, mid - 1, inorder);
    root->right = inorderToBST(mid + 1, e, inorder);
    return root;
}
Node* mergeBST(Node *root1, Node *root2)
{
    vector<int> inorder1, inorder2;
    inorderTrav(root1, inorder1);
    inorderTrav(root2, inorder2);

    vector<int> mergeArray=  mergeTwoArrays(inorder1, inorder2);

    return inorderToBST(0,mergeArray.size()-1,mergeArray);


}