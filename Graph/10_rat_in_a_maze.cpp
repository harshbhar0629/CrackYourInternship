#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{

    vector<string> ans;
    void f(vector<vector<int>> &mat, string &s, int i, int j, vector<vector<int>> &vis)
    {
        if (i == mat.size() - 1 and j == mat[0].size() - 1)
        {
            ans.push_back(s);
            return;
        }

        vis[i][j] = 1;
        if (i > 0 and vis[i - 1][j] == 0 and mat[i - 1][j] == 1)
        {
            s += 'U';
            f(mat, s, i - 1, j, vis);
            s.pop_back();
        }
        if (j > 0 and vis[i][j - 1] == 0 and mat[i][j - 1] == 1)
        {
            s += 'L';
            f(mat, s, i, j - 1, vis);
            s.pop_back();
        }
        if (i + 1 < mat.size() and vis[i + 1][j] == 0 and mat[i + 1][j] == 1)
        {
            s += 'D';
            f(mat, s, i + 1, j, vis);
            s.pop_back();
        }
        if (j + 1 < mat[0].size() and vis[i][j + 1] == 0 and mat[i][j + 1] == 1)
        {
            s += 'R';
            f(mat, s, i, j + 1, vis);
            s.pop_back();
        }
        vis[i][j] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        ans = {};
        if (mat[mat.size() - 1][mat[0].size() - 1] == 0 || mat[0][0] == 0)
        {
            return {};
        }
        string s = "";
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size()));
        f(mat, s, 0, 0, vis);
        return ans;
    }
};

int main(){
    

    return 0;
}