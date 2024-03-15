#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];
    bool flag;

    Node()
    {
        flag = false;
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *moveToNext(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->moveToNext(word[i]);
        }
        node->setEnd();
    }
    bool checkPrefixIfExists(string word)
    {
        bool fl = true;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->moveToNext(word[i]);
                if (node->isEnd() == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;
    for (auto &it : a)
    {
        trie.insert(it);
    }

    string longest = "";
    for (auto it : a)
    {
        if (trie.checkPrefixIfExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}