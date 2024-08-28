#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};
    int f(int r, int c, pair<int, int> &dest, vector<vector<int>> &g, int steps)
    {
        if (steps == -1 and dest == make_pair(r, c))
        {
            return 1;
        }

        g[r][c] = -1; // mark as visited!
        int ans = 0;
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr < 0 || nc < 0 || nr >= g.size() || nc >= g[0].size() || g[nr][nc] == -1)
            {
                continue;
            }
            ans += f(nr, nc, dest, g, steps - 1);
        }

        g[r][c] = 0; // mark as unvisited!
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        pair<int, int> src, dest;
        int steps = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    src = {i, j};
                }
                else if (grid[i][j] == 2)
                {
                    dest = {i, j};
                }
                else if (grid[i][j] == 0)
                {
                    steps++;
                }
            }
        }

        return f(src.first, src.second, dest, grid, steps);
    }
};

int main(){
    

    return 0;
}