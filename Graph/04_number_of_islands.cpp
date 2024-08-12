#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/number-of-islands/

class Solution
{
    int n, m;
    // vector<vector<int>> vis;

    void dfs(int r, int c, vector<vector<char>> &g)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || g[r][c] != '1')
        {
            return;
        }
        // vis[r][c] = 1;
        g[r][c] = '#';
        dfs(r + 1, c, g);
        dfs(r - 1, c, g);
        dfs(r, c + 1, g);
        dfs(r, c - 1, g);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        this->n = grid.size();
        this->m = grid[0].size();
        // vis.resize(n, vector<int>(m, 0));

        int island = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    island++;
                }
            }
        }

        return island;
    }
};

int main(){
    

    return 0;
}