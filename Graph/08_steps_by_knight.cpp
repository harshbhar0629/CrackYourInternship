#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1

#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define f first
#define s second
class Solution
{
    vector<pi> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        queue<ppi> qu;
        vector<vector<int>> vis(n + 2, vector<int>(n + 2, 1));
        qu.push({{KnightPos[0], KnightPos[1]}, 0});
        vis[KnightPos[0]][KnightPos[1]] = 0;

        while (!qu.empty())
        {
            auto curr = qu.front();
            qu.pop();
            int steps = curr.s;
            int r = curr.f.f;
            int c = curr.f.s;
            if (r == TargetPos[0] and c == TargetPos[1])
            {
                return steps;
            }

            for (int d = 0; d < 8; d++)
            {
                int nr = r + dir[d].f;
                int nc = c + dir[d].s;
                if (nr < 0 || nc < 0 || nr > n || nc > n || vis[nr][nc] != 1)
                {
                    continue;
                }

                qu.push({{nr, nc}, steps + 1});
                vis[nr][nc] = 0;
                if (nr == TargetPos[0] and nc == TargetPos[1])
                {
                    return steps + 1;
                }
            }
        }

        return -1;
    }
};

int main(){
    

    return 0;
}