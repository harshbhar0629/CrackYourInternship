#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sudoku-solver/

class Solution
{

    bool isPossible(vector<vector<char>> &board, int r, int c, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == ch || board[i][c] == ch)
            {
                return false;
            }
        }
        // fetch curr row and curr col
        int row = (r / 3) * 3;
        int col = (c / 3) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] == ch)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board, int r = 0, int c = 0)
    {
        if (r == 9)
        {
            return true;
        }
        // curr row fill jump to next row
        if (c == 9)
        {
            return solve(board, r + 1, 0);
        }
        // curr character having any digit you can't update curr digit
        if (board[r][c] != '.')
        {
            return solve(board, r, c + 1);
        }

        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (isPossible(board, r, c, ch))
            {
                board[r][c] = ch;
                if (solve(board, r, c + 1))
                {
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main(){
    

    return 0;
}