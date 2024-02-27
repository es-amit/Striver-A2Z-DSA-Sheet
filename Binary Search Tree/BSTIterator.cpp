#include<Node.cpp>
using namespace std;

class BSTIterator {
public:
    stack<Node*> st;
    void pushAll(Node* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(Node* root) {
        pushAll(root);
    }
    
    int next() {
        Node* tmp = st.top();
        st.pop();
        pushAll(tmp->right);
        return tmp->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};