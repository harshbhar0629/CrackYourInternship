#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix
{
public:
    vector<vector<int>> ans;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] += matrix[i - 1][j];
            }
        }
        ans = vector<vector<int>>(matrix.size());
        // ans[0]=vector<vector<int>>(matrix[0].size());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i].push_back(matrix[i][j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int topsum = 0, leftsum = 0, topleftsum = 0;
        if (row1 != 0)
            topsum = ans[row1 - 1][col2];
        if (col1 != 0)
            leftsum = ans[row2][col1 - 1];
        if (row1 != 0 && col1 != 0)
            topleftsum = ans[row1 - 1][col1 - 1];
        return (ans[row2][col2] - topsum - leftsum + topleftsum);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    

    return 0;
}