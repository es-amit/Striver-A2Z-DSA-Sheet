#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int capacity;

    unordered_map<int, Node *> mpp;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *temp = mpp[key];
            int res = temp->value;
            mpp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
        newNode->prev = head;
    }
    void deleteNode(Node *delNode)
    {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *exisitingNode = mpp[key];
            mpp.erase(key);
            deleteNode(exisitingNode);
        }
        if (mpp.size() == capacity)
        {
            Node *leastNode = tail->prev;
            mpp.erase(leastNode->key);
            deleteNode(leastNode);
        }
        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */