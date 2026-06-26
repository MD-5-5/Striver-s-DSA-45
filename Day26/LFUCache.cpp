#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, freq;
    Node *next, *prev;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct DoublyList {
    int size;
    Node *head, *tail;

    DoublyList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node) {
        Node *first = head->next;
        node->next = first;
        node->prev = head;
        head->next = node;
        first->prev = node;
        size++;
    }

    void remove(Node *node) {
        Node *left = node->prev;
        Node *right = node->next;
        left->next = right;
        right->prev = left;
        size--;
    }
};

class LFUCache {
    map<int, Node*> cache;
    map<int, DoublyList*> freqList;

    int capacity;
    int currSize;
    int minFreq;

public:
    LFUCache(int cap) {
        capacity = cap;
        currSize = 0;
        minFreq = 0;
    }

    void update(Node *node) {
        cache.erase(node->key);

        freqList[node->freq]->remove(node);

        if (node->freq == minFreq && freqList[node->freq]->size == 0)
            minFreq++;

        DoublyList *nextList;

        if (freqList.count(node->freq + 1))
            nextList = freqList[node->freq + 1];
        else
            nextList = new DoublyList();

        node->freq++;

        nextList->addFront(node);

        freqList[node->freq] = nextList;
        cache[node->key] = node;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;

        Node *node = cache[key];
        update(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (cache.count(key)) {
            Node *node = cache[key];
            node->value = value;
            update(node);
            return;
        }

        if (currSize == capacity) {
            DoublyList *list = freqList[minFreq];
            Node *del = list->tail->prev;

            cache.erase(del->key);
            list->remove(del);
            currSize--;
        }

        currSize++;
        minFreq = 1;

        DoublyList *list;

        if (freqList.count(1))
            list = freqList[1];
        else
            list = new DoublyList();

        Node *node = new Node(key, value);

        list->addFront(node);

        cache[key] = node;
        freqList[1] = list;
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << " ";

    cache.put(3, 3);

    cout << cache.get(2) << " ";
    cout << cache.get(3) << " ";

    cache.put(4, 4);

    cout << cache.get(1) << " ";
    cout << cache.get(3) << " ";
    cout << cache.get(4) << " ";

    return 0;
}