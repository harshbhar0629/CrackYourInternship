#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1

class Solution
{
public:
    int minSteps(int m, int n, int d)
    {
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == d || y == d)
                {
                    return ans;
                }

                if (vis[0][y] == 0)
                {
                    vis[0][y] = 1;
                    q.push({0, y});
                }
                if (vis[x][0] == 0)
                {
                    vis[x][0] = 1;
                    q.push({x, 0});
                }
                if (vis[m][y] == 0)
                {
                    vis[m][y] = 1;
                    q.push({m, y});
                }
                if (vis[x][n] == 0)
                {
                    vis[x][n] = 1;
                    q.push({x, n});
                }

                // x ch tak y madhe
                if (n - y >= x)
                {
                    if (vis[0][x + y] == 0)
                    {
                        vis[0][x + y] = 1;
                        q.push({0, x + y});
                    }
                }
                else
                {
                    if (vis[x - n + y][n] == 0)
                    {
                        vis[x - n + y][n] = 1;
                        q.push({x - n + y, n});
                    }
                }

                // y ch tak x madhe
                if (y >= m - x)
                {
                    if (vis[m][y - m + x] == 0)
                    {
                        vis[m][y - m + x] = 1;
                        q.push({m, y - m + x});
                    }
                }
                else
                {
                    if (vis[x + y][0] == 0)
                    {
                        vis[x + y][0] = 1;
                        q.push({x + y, 0});
                    }
                }
            }
            if (q.empty())
                return -1;
            ans++;
        }
        return -1;
    }
};

int main(){
    

    return 0;
}