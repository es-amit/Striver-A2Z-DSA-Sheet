#include <Node.cpp>
using namespace std;
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    Node *temp = root;
    int pred = -1;
    int succ = -1;
    while (temp && temp->data != key)
    {

        if (temp->data > key)
        {

            succ = temp->data;

            temp = temp->left;
        }

        else
        {

            pred = temp->data;

            temp = temp->right;
        }
    }

    // finding pred
    if (temp)
    {
        Node *leftTree = temp->left;
        while (leftTree != nullptr)
        {
            pred = leftTree->data;
            leftTree = leftTree->right;
        }
        Node *rightTree = temp->right;
        while (rightTree != nullptr)
        {
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
    }

    return {pred, succ};
}