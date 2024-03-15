#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    Node *links[2];

public:
    bool containsKey(int bit)
    {
        return links[bit] != nullptr;
    }

    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
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

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int q = queries.size();
    vector<pair<int, pair<int, int>>> oQ;
    for (int i = 0; i < q; i++)
    {
        oQ.push_back({queries[i][1], {queries[i][0], i}});
    }

    sort(oQ.begin(), oQ.end());
    vector<int> ans(q, 0);
    int ind = 0;
    Trie trie;
    for (int i = 0; i < q; i++)
    {
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int qInd = oQ[i].second.second;

        while (ind < n && arr[ind] <= ai)
        {
            trie.insert(arr[ind]);
            ind++;
        }
        if (ind == 0)
            ans[qInd] = -1;
        else
            ans[qInd] = trie.getMax(xi);
    }
    return ans;
}