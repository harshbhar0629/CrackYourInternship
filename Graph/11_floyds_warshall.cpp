#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == -1)
                {
                    mat[i][j] = 1e7;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] >= 1e7)
                {
                    mat[i][j] = -1;
                }
            }
        }
    }
};

int main(){
    

    return 0;
}