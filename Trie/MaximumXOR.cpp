#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    Node* links[2];

public:
    bool containsKey(int bit){
        return links[bit] != nullptr;
    }    

    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;

        for(int i = 31;i>= 0;i--){
            int bit = (num >> i ) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    public:
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto it: arr1){
        trie.insert(it);
    } 
    int maxi =0;
    for(auto it: arr2){
        maxi = max(maxi,trie.getMax(it));
    }
    return maxi;
}