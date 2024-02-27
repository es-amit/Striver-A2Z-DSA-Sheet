#include<Node.cpp>
using namespace std;

int findCeil(Node *node, int x){
    int ceil = -1;
    while(node){
        if(node->data == x){
            return node->data;
        }
        if(node->data < x){
            node = node->right;
        }
        else{
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}