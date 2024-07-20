#include <bits/stdc++.h>
using namespace std;
// https : // leetcode.com/problems/game-of-life/description/

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int c = 0;
                for (int k = max(0, i - 1); k <= min(n - 1, i + 1); k++)
                {
                    for (int l = max(0, j - 1); l <= min(m - 1, j + 1); l++)
                    {
                        c += (board[k][l] & 1);
                    }
                }
                if (c == 3 || c - board[i][j] == 3)
                {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] /= 2;
            }
        }
    }
};

int main()
{

    return 0;
}