#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1

class Solution
{
    vector<vector<int>> dp;
    int f(int i, int mask, vector<vector<int>> &cost, int n)
    {
        if (mask == (1 << n) - 1)
        {
            return cost[i][0];
        }
        if (dp[i][mask] != -1)
        {
            return dp[i][mask];
        }

        int ans = 1e9;
        for (int j = 0; j < n; j++)
        {
            if (((1 << j) & mask) == 0)
            {
                ans = min(ans, cost[i][j] + f(j, mask | (1 << j), cost, n));
            }
        }

        return dp[i][mask] = ans;
    }

public:
    int total_cost(vector<vector<int>> cost)
    {
        int n = cost.size();
        dp.resize(n, vector<int>((1 << n) + 1, -1));
        return f(0, 1, cost, n);
    }
};

int main(){
    

    return 0;
}