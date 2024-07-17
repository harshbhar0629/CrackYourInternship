#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/two-sum/description/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;

        while (i < n)
        {
            int val = target - nums[i];
            if (mp.count(val) > 0)
            {
                return {mp[val], i};
            }
            mp[nums[i]] = i;
            i++;
        }

        return {0, 1};
    }
};

int main(){
    

    return 0;
}