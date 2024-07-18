#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/3sum/description/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    st.insert({nums[i], nums[j], nums[k]});
                }
                if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        vector<vector<int>> res;
        for (auto it : st)
        {
            res.push_back(it);
        }

        return res;
    }
};

int main(){
    

    return 0;
}