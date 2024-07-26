#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[n - 2] * nums[0]);
        return ans;
    }
};

int main(){
    

    return 0;
}