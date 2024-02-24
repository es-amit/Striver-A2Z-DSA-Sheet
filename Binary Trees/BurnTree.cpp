#include <TreeNode.cpp>
using namespace std;
Node *createNodeToParent(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = nullptr;
    queue<Node *> q;
    q.push(root);
    nodeToParent[root] = nullptr;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
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
    return res;
}
int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                flag = 1;
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if (temp->right && !visited[temp->right])
            {
                flag = 1;
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if (nodeToParent[temp] && !visited[nodeToParent[temp]])
            {
                flag = 1;
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = true;
            }
        }
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createNodeToParent(root, target, nodeToParent);

    return burnTree(targetNode, nodeToParent);
}