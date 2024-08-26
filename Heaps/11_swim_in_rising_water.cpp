#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/swim-in-rising-water/description/

#define ppi pair<int, pair<int, int>>
#define f first
#define s second
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        const vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        pq.push({grid[0][0], {0, 0}});
        dis[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int time = curr.f;
            int r = curr.s.f;
            int c = curr.s.s;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dir[d].f;
                int nc = c + dir[d].s;
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nr] > dis[nr][nc])
                {
                    continue;
                }

                if (time < grid[nr][nc])
                {
                    dis[nr][nc] = grid[nr][nc];
                    pq.push({dis[nr][nc], {nr, nc}});
                }
                else if (time < dis[nr][nc])
                {
                    dis[nr][nc] = time;
                    pq.push({dis[nr][nc], {nr, nc}});
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};

int main(){
    

    return 0;
}