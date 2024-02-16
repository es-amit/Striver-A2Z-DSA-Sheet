#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;

    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;  
        cnt = 1;    
    }
};

class List{
    public:
    int size;
    Node* head;
    Node* tail;

    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode -> next = temp;
        head->next = newNode;
        temp ->prev = newNode;
        newNode ->prev = head;
        size++;
    }
    void deleteNode(Node* delNode){
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};
class LFUCache {
public:
    map<int,List*> freqListMap;
    map<int,Node*> keyNode;
    int maxSizeCache;
    int minFreq;
    int currSize;
    LFUCache(int capacity) {
        maxSizeCache= capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); 
        freqListMap[node->cnt]->deleteNode(node); 
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addNode(node); 
        freqListMap[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int res = node->value;
            updateFreqListMap(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
            return;
        }
        else{
            if(currSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                currSize--;
            }
            currSize += 1;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq = freqListMap[minFreq]; 
            }
            Node *newNode = new Node(key,value);
            listFreq -> addNode(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = listFreq; 

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */