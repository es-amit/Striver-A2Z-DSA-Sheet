#include<Node.cpp>
using namespace std;
int Floor(Node *node, int x)
{
	int floor = -1;
    while(node){
        if(node->data == x){
            return node->data;
        }
        if(node->data < x){
            floor = node->data;
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
    return floor;
}
