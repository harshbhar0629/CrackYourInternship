#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution
{
    int maxi = 0;
    int dp[305][305];
    int f(int i, int j, vector<vector<int>> &mat)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = f(i + 1, j, mat);
        int right = f(i, j + 1, mat);
        int dia = f(i + 1, j + 1, mat);

        if (mat[i][j] == 1)
        {
            dp[i][j] = 1 + min({right, down, dia});
            maxi += dp[i][j];
            return dp[i][j];
        }

        return dp[i][j] = 0;
    }

public:
    int countSquares(vector<vector<int>> &matrix)
    {
        memset(dp, -1, sizeof dp);
        maxi = 0;
        f(0, 0, matrix);
        return maxi;
    }
};

int main(){
    

    return 0;
}