#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/snakes-and-ladders/description/

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size(), lvl = 1;
        vector<pair<int, int>> cells(n * n + 1);
        vector<int> cols(n);
        iota(cols.begin(), cols.end(), 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int col : cols)
            {
                cells[lvl++] = {i, col};
            }
            reverse(cols.begin(), cols.end());
        }

        vector<int> dis(n * n + 1, -1);
        dis[1] = 0;
        queue<int> qu;
        qu.push(1);

        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();

            for (int next = curr + 1; next <= min(curr + 6, n * n); next++)
            {
                auto [row, col] = cells[next];
                int dest = board[row][col] == -1 ? next : board[row][col];
                if (dis[dest] == -1)
                {
                    dis[dest] = dis[curr] + 1;
                    qu.push(dest);
                }
            }
        }

        return dis[n * n];
    }
};

int main(){
    

    return 0;
}