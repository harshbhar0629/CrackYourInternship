#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subsets/description/

class Solution
{
    vector<vector<int>> ans;
    void f(vector<int> &nums, int i, vector<int> &v)
    {
        if (i == nums.size())
        {
            ans.push_back(v);
            return;
        }

        f(nums, i + 1, v);
        v.push_back(nums[i]);
        f(nums, i + 1, v);
        v.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }

        // vector<int>v;
        // f(nums, 0, v);

        return ans;
    }
};

int main(){
    

    return 0;
}