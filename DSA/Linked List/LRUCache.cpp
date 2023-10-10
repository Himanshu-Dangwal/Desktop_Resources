#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key, value;
        Node *prev;
        Node *next;

        Node(int k, int val)
        {
            key = k;
            value = val;
            prev = next = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *resNode)
    {
        Node *prevNode = resNode->prev;
        Node *nextNode = resNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return resNode->value; // Corrected variable name here
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *resNode = mp[key];
            deleteNode(resNode);
            mp.erase(key);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

int main()
{
}