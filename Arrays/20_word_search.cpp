#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/word-search/description/

class Solution
{
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

    bool f(vector<vector<char>> &board, string &word, int i, int r, int c)
    {
        if (i == word.size())
        {
            return true;
        }

        bool ans = false;
        char ch = board[r][c];
        board[r][c] = '.';
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size() || board[nr][nc] != word[i])
            {
                continue;
            }
            ans = ans | f(board, word, i + 1, nr, nc);
        }

        board[r][c] = ch;
        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word[0] == board[i][j])
                {
                    if (f(board, word, 1, i, j))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main(){
    

    return 0;
}