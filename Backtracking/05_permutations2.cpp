#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/permutations-ii/description/

class Solution
{

    void f(vector<int> nums, vector<vector<int>> &res, int i)
    {
        if (i >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++)
        {
            if (k != i and nums[k] == nums[i])
                continue;
            swap(nums[i], nums[k]);
            f(nums, res, i + 1);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        f(nums, res, 0);
        return res;
    }
};

int main(){
    

    return 0;
}