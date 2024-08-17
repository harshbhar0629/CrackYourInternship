#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> qu;
        vector<vector<int>> vis = grid;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1)
                {
                    qu.push({i, j});
                }
            }
        }

        const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int maxi = -1;
        while (!qu.empty())
        {
            for (int sz = qu.size(); sz > 0; sz--)
            {
                auto curr = qu.front();
                qu.pop();
                int r = curr.first;
                int c = curr.second;

                for (int d = 0; d < 4; d++)
                {
                    int nr = r + dir[d].first;
                    int nc = c + dir[d].second;
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    {
                        continue;
                    }
                    if (vis[nr][nc] != 1)
                    {
                        qu.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            maxi++;
        }

        return maxi <= 0 ? -1 : maxi;
    }
};

int main(){
    

    return 0;
}