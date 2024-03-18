#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    Node* links[26];
    int countPrefix = 0;
    
    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    void incrementPrefix(){
        countPrefix++;
    }
};

class Trie{
    private:
    Node* root;
    
    public:
    Trie(){
        root =  new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i],new Node());
            }
            node = node->get(word[i]);
            node -> incrementPrefix();
        }
    }
    
    string findUniquePrefix(string word){
        Node* node =root;
        string prefix;
        for(char ch: word){
            node = node->get(ch);
            prefix.push_back(ch);
            if(node -> countPrefix == 1){
                break;
            }
        }
        return prefix;
    }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(arr[i]);
        }
        
        vector<string> ans;
        for(int i=0;i<n;i++){
            string temp = trie.findUniquePrefix(arr[i]);
            ans.push_back(temp);
        }
        return ans;
    }
    
};