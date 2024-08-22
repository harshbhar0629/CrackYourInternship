#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/burst-balloons/

class Solution
{
    int dp[305][305];
    int f(int i, int j, vector<int> &nums)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = -1e8;
        for (int k = i; k < j; k++)
        {
            int burstLeft = f(i, k, nums);
            int burstRight = f(k + 1, j, nums);
            ans = max(ans, burstLeft + burstRight + nums[i - 1] * nums[k] * nums[j]);
        }

        return dp[i][j] = ans;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        memset(dp, -1, sizeof dp);
        return f(1, nums.size() - 1, nums);
    }
};

int main(){
    

    return 0;
}