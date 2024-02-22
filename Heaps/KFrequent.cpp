#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    typedef pair<int, int> p;

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;

        // Count frequency of each number
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        // Create a min heap to store the top k frequent elements
        priority_queue<p, vector<p>, compare> pq;

        // Insert elements into the min heap
        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k)
            {
                pq.pop(); // Ensure the size of the heap remains k
            }
        }

        // Extract the top k frequent elements from the heap
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};