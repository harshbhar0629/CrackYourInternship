#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/coin-change/

class Solution
{
    int dp[15][10005];
    int f(int i, int amnt, vector<int> &coins)
    {
        if (amnt == 0)
        {
            return 0;
        }
        if (i == coins.size())
        {
            return 1e8;
        }
        if (dp[i][amnt] != -1)
        {
            return dp[i][amnt];
        }

        int opt1 = f(i + 1, amnt, coins);
        int opt2 = 1e8;
        if (coins[i] <= amnt)
        {
            opt2 = 1 + f(i, amnt - coins[i], coins);
        }

        return dp[i][amnt] = min(opt1, opt2);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof dp);
        int ans = f(0, amount, coins);
        return (ans >= 1e8) ? -1 : ans;
    }
};

int main(){
    

    return 0;
}