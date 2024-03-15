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

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return false;
            }
            node = node->moveToNext(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!(node->containsKey(prefix[i])))
            {
                return false;
            }
            node = node->moveToNext(prefix[i]);
        }
        return true;
    }
};