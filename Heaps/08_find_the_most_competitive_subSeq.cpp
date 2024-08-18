#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-most-competitive-subsequence/

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (!ans.empty() and nums[i] < ans.back() and (n - i - 1) >= (k - ans.size()))
            {
                ans.pop_back();
            }

            if (ans.size() < k)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

int main(){
    

    return 0;
}