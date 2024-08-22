#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution
{
    int dp[1001][101][5];
    int f(int i, int k, bool buy, const vector<int> &prices)
    {
        if (i == prices.size() || k == 0)
        {
            return 0;
        }
        if (dp[i][k][buy] != -1)
        {
            return dp[i][k][buy];
        }

        int skipCase = f(i + 1, k, buy, prices);
        int notSkipCase = 0;
        if (buy)
        {
            notSkipCase = max(notSkipCase, prices[i] + f(i + 1, k - 1, false, prices));
        }
        else
        {
            notSkipCase = max(notSkipCase, f(i + 1, k, true, prices) - prices[i]);
        }

        return dp[i][k][buy] = max(skipCase, notSkipCase);
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof dp);
        return f(0, k, false, prices);
    }
};

int main(){
    

    return 0;
}