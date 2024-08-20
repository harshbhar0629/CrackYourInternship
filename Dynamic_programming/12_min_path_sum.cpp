#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
    int dp[205][205];
    int f(int i, int j, vector<vector<int>> &grid)
    {
        if (i == grid.size() || j == grid[i].size())
        {
            return 1e7;
        }
        if (i == grid.size() - 1 and j == grid[i].size() - 1)
        {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = grid[i][j] + min(f(i + 1, j, grid), f(i, j + 1, grid));
        return dp[i][j] = ans;
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof dp);
        return f(0, 0, grid);
    }
};

int main(){
    

    return 0;
}