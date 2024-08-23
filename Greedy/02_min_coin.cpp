#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/min-coin5549/1

class Solution
{
    int dp[101][10002];
    int f(vector<int> &nums, int amt, int i)
    {
        if (amt == 0)
        {
            return 0;
        }
        if (i == nums.size())
        {
            return 1e7;
        }
        if (dp[i][amt] != -1)
        {
            return dp[i][amt];
        }

        int opt1 = f(nums, amt, i + 1);
        int opt2 = nums[i] <= amt ? 1 + f(nums, amt - nums[i], i) : 1e7;

        return dp[i][amt] = min(opt1, opt2);
    }

public:
    int MinCoin(vector<int> nums, int amount)
    {
        memset(dp, -1, sizeof dp);
        int ans = f(nums, amount, 0);
        return ans >= 1e7 ? -1 : ans;
    }
};

int main(){
    

    return 0;
}