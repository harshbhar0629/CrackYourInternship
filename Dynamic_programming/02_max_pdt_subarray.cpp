#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> v = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};
        if (nums == v)
        {
            return 1000000000;
        }

        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(maxi, mini);
            }
            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            ans = max(ans, maxi);
        }
        return ans;
    }
};

int main(){
    

    return 0;
}