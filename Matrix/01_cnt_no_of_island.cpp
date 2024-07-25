#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/

class Solution
{
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int dfs(int r, int c, vector<vector<int>>& mat){
        mat[r][c] = -1;
        for (int d = 0; d < 8; d++){
            int nr = r + dx[d];
            int nc = c + dy[d];
            if(nr<0 || nc<0 || nr>=mat.size() || nc>=mat[0].size() || mat[nr][nc] != 1){
                continue;
            }
            dfs(nr, nc, mat);
        }
    }

public:
    int
    cntIsland(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1){
                    cnt++;
                   
                    dfs(i, j, mat);
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}