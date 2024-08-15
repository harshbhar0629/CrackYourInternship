#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto ele : nums)
        {
            mp[ele]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        while (k--)
        {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main(){
    

    return 0;
}