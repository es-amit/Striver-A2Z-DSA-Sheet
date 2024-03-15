#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

int countDistinctSubstrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();
    for (int i = 0; i < s.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}