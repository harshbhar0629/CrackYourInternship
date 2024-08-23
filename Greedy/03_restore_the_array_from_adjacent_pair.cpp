#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> gp;
        for (auto &it : adjacentPairs)
        {
            gp[it[0]].push_back(it[1]);
            gp[it[1]].push_back(it[0]);
        }

        // finding root
        vector<int> res;
        for (auto &it : gp)
        {
            if (it.second.size() == 1)
            {
                res = {it.first, it.second[0]};
                break;
            }
        }

        while (res.size() < n + 1)
        {
            int last = res.back();
            int prev = res[res.size() - 2];
            auto &adjacent = gp[last];
            int ele = (adjacent[0] != prev) ? adjacent[0] : adjacent[1];
            res.push_back(ele);
        }

        return res;
    }
};

int main(){
    

    return 0;
}