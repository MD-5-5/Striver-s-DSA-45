#include <iostream>
#include <list>
#include <map>
using namespace std;

class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void MostRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        MostRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            MostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            int key_del = dll.back();
            mp.erase(key_del);
            dll.pop_back();
            n++;
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);

    cout << cache.get(2) << endl; // -1

    cache.put(4, 4);

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}