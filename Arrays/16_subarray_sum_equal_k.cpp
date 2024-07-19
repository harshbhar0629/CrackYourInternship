#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            int remove = prefixSum - k;
            cnt += mp[remove];
            mp[prefixSum]++;
        }

        return cnt;
    }
};

int main(){
    

    return 0;
}