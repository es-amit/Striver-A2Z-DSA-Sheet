#include <TreeNode.cpp>
using namespace std;

void nodeToParentRelation(Node *root, unordered_map<Node *, Node *> &nodeToParent)
{
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = nullptr;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->left)
        {
            q.push(front->left);
            nodeToParent[front->left] = front;
        }
        if (front->right)
        {
            q.push(front->right);
            nodeToParent[front->right] = front;
        }
    }
}
void findDistance(Node *root, unordered_map<Node *, Node *> &nodeToParent, vector<int> &ans, int &k, unordered_map<Node *, bool> &visited)
{
    if (root == nullptr || visited[root])
    {
        return;
    }
    visited[root] = true;
    if (k == 0)
    {
        ans.push_back(root->data);
        return;
    }

    k--;
    // left call
    findDistance(root->left, nodeToParent, ans, k, visited);
    // right call
    findDistance(root->right, nodeToParent, ans, k, visited);
    // parent call
    findDistance(nodeToParent[root], nodeToParent, ans, k, visited);

    k++;
    return;
}
vector<int> distanceK(Node *root, Node *target, int k)
{
    unordered_map<Node *, Node *> nodeToParent;
    nodeToParentRelation(root, nodeToParent);
    vector<int> ans;
    unordered_map<Node *, bool> visited;
    findDistance(target, nodeToParent, ans, k, visited);
    return ans;
}