#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int min_val = prices[0];

        for (int i = 0; i < n; i++)
        {
            min_val = min(prices[i], min_val);
            profit = max(profit, prices[i] - min_val);
        }

        return profit;
    }
};

int main(){
    

    return 0;
}