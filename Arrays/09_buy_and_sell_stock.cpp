#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution
{
    int dp[30005][2];
    int f(vector<int> &p, int i, int isAvail)
    {
        if (i == p.size())
        {
            return 0;
        }
        if (dp[i][isAvail] != -1)
        {
            return dp[i][isAvail];
        }

        int ans = f(p, i + 1, isAvail);
        if (isAvail)
        {
            ans = max(ans, p[i] + f(p, i + 1, 0));
        }
        else
        {
            ans = max(ans, f(p, i + 1, 1) - p[i]);
        }

        return dp[i][isAvail] = ans;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, 0);
    }
};

int main(){
    

    return 0;
}