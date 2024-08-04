#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lru-cache/description/

class LRUCache
{
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> dll;
    int size, capacity;

public:
    LRUCache(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.count(key) == 0)
        {
            return -1;
        }

        // updation required bcoz now it will become recently used
        auto it = mp[key];      // it returns {key, value}
        int value = it->second; // store value
        mp.erase(key);
        dll.erase(it);
        // update in front so that it will become recently used
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (mp.count(key) > 0)
        {
            auto it = mp[key];
            dll.erase(it);
            mp.erase(key);
            size--;
        }

        // check capacity exceeds or not
        if (size == capacity)
        {
            auto last = dll.back();
            dll.pop_back();
            mp.erase(last.first);
            size--;
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{

    return 0;
}