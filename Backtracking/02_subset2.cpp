#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subsets-ii/

class Solution
{
    vector<vector<int>> res;
    vector<int> nums;

    void f(int i, vector<int> &v)
    {
        res.push_back(v);
        for (int j = i; j < nums.size(); j++)
        {
            if (j != i and nums[j] == nums[j - 1])
                continue;
            v.push_back(nums[j]);
            f(j + 1, v);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &num)
    {
        vector<int> v;
        this->nums = num;
        sort(nums.begin(), nums.end());
        f(0, v);
        return res;
    }
};

int main(){
    

    return 0;
}