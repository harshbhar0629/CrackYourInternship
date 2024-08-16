#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution
{
    int dp[205][205];
    const vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int f(int r, int c, vector<vector<int>> &mat)
    {
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int ans = 1;
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if (nr < 0 || nc < 0 || nr >= mat.size() || nc >= mat[0].size() || mat[nr][nc] <= mat[r][c])
            {
                continue;
            }
            ans = max(ans, 1 + f(nr, nc, mat));
        }

        return dp[r][c] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        memset(dp, -1, sizeof dp);
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxi = max(maxi, f(i, j, matrix));
            }
        }

        return maxi;
    }
};

int main(){
    

    return 0;
}