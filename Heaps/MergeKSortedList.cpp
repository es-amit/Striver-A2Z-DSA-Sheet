#include<bits/stdc++.h>
using namespace std;


class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }

    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val,ListNode* next){
        this->val = val;
        this->next = next;
    }

};

typedef pair<int, ListNode*> ppi;
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
        {

            pq.push({lists[i]->val, lists[i]});
        }
    }
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while (!pq.empty())
    {
        ppi elem = pq.top();
        pq.pop();
        if (elem.second->next)
        {
            pq.push({elem.second->next->val, elem.second->next});
        }
        if (temp)
        { // Check if temp is not null
            temp->next = elem.second;
            temp = temp->next;
        }
    }
    return dummyNode->next;
}