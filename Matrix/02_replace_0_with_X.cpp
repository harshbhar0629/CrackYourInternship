#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

class Solution
{
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    void dfs(int r, int c, vector<vector<char>>& m, char replaceChar){
        m[r][c] = replaceChar;
        for (int d = 0; d < 4; d++){
            int nr = r + dx[d];
            int nc = c + dy[d];
            if(nr<0 || nc<0 || nr>=m.size() || nc>=m[0].size() || m[nr][nc] != '-'){
                continue;
            }
            dfs(nr, nc, m, replaceChar);
        }
    }

public:
    vector<vector<char>>
    replaceSurrounded(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i<n; i++){
            for (int j = 0; j < m; j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = '-';
                }
            }
        }

        // top-to-bottom starting
        for (int i = 0; i < n; i++){
            if (mat[i][0] == '-') {
                dfs(i, 0, mat, 'O');
            }
        }

        // top-to-bottom ending
        for (int i = 0; i < n; i++){
            if (mat[i][m-1] == '-'){
                dfs(i, m - 1, mat, 'O');
            }
        }

        // left-to-right starting
        for (int j = 0; j < m; j++){
            if (mat[0][j] == '-'){
                dfs(0, j, mat, 'O');
            }
        }

        // left-to-right ending
        for (int j = 0; j < m; j++){
            if (mat[0][j] == '-'){
                dfs(n - 1, j, mat, 'O');
            }
        }

        // make all '-' set to X remaining are surrounding by 'X'
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(mat[i][j] == '-'){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main(){
    

    return 0;
}