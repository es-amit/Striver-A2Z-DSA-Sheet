#include <bits/stdc++.h>
using namespace std;
vector<int> findStockSpans(vector<int> &prices)
{
    vector<int> v;
    stack<pair<int, int>> st;
    for (int i = 0; i < prices.size(); i++)
    {
        if (st.empty())
        {
            v.push_back(-1);
        }
        else if (!st.empty() && prices[i] < st.top().first)
        {
            v.push_back(st.top().second);
        }
        else if (!st.empty() && prices[i] >= st.top().first)
        {
            while (!st.empty() && prices[i] > st.top().first)
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        st.push({prices[i], i});
    }
    for (int i = 0; i < prices.size(); i++)
    {
        v[i] = i - v[i];
    }
    return v;
}

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && price >= st.top().first)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
