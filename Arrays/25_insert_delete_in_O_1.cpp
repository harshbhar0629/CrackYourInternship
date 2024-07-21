#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection
{
    vector<pair<int, int>> v;
    unordered_map<int, vector<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val)
    {
        bool ans = true;
        if (mp[val].size() > 0)
        {
            ans = false;
        }
        // {ele, index in map[val]}
        v.emplace_back(val, mp[val].size());
        // {val -> index in vector}
        mp[val].emplace_back(v.size() - 1);
        return ans;
    }

    bool remove(int val)
    {
        if (mp[val].size() == 0)
        {
            return false;
        }

        // get idx of last ele in vector
        auto last = v.back();
        int idx = mp[val].back();
        mp[last.first][last.second] = idx;
        v[idx] = last;
        v.pop_back();
        mp[val].pop_back();
        if (mp[val].size() == 0)
        {
            mp.erase(val);
        }

        return true;
    }

    int getRandom()
    {
        int idx = std::rand() % v.size();
        return v[idx].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    

    return 0;
}