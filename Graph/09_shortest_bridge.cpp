#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/shortest-bridge/description/

#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define f first
#define s second
class Solution
{
    vector<pi> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    queue<ppi> qu;

    void dfs(int i, int j, vector<vector<int>> &g)
    {
        if (i < 0 || j < 0 || j >= g[0].size() || i >= g.size() || g[i][j] != 1)
        {
            return;
        }

        g[i][j] = 2;
        qu.push({{i, j}, 0});

        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d].f;
            int nj = j + dir[d].s;
            dfs(ni, nj, g);
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        // cout<<"done";

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            int r = curr.f.f;
            int c = curr.f.s;
            int steps = curr.s;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dir[d].f;
                int nc = c + dir[d].s;
                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] == 2)
                {
                    continue;
                }

                qu.push({{nr, nc}, steps + 1});
                if (grid[nr][nc] == 1)
                {
                    return steps;
                }
                grid[nr][nc] = 2;
            }
        }

        return 0;
    }
};

int main(){
    

    return 0;
}