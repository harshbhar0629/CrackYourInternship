#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/word-wrap1646/1
class Solution
{
    int dp[505];
    int f(vector<int> &nums, int k, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = 1e9;
        int sum = 0;

        for (int idx = i; idx <= j; idx++)
        {
            sum += nums[idx];
            if (sum <= k and idx == j)
            {
                return dp[i] = 0;
            }
            if (sum <= k)
            {
                int v = (k - sum) * (k - sum);
                ans = min(ans, v + f(nums, k, idx + 1, j));
                sum++;
            }
        }

        return dp[i] = ans;
    }

public:
    int solveWordWrap(vector<int> nums, int k)
    {
        memset(dp, -1, sizeof dp);
        return f(nums, k, 0, nums.size() - 1);
    }
};

int main(){
    

    return 0;
}