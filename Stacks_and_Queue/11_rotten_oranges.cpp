#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> qu;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    qu.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int time = 0;
        while (!qu.empty())
        {
            bool flag = false;
            for (int i = qu.size(); i > 0; i--)
            {
                auto curr = qu.front();
                qu.pop();
                int r = curr.first;
                int c = curr.second;

                for (int d = 0; d < 4; d++)
                {
                    int nr = r + dx[d];
                    int nc = c + dy[d];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] != 1)
                    {
                        continue;
                    }
                    flag = true;
                    qu.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
            if (flag){
                time++;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};

int main(){
    

    return 0;
}