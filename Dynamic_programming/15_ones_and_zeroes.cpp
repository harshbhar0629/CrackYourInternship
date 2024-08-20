#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/ones-and-zeroes/

class Solution
{
    // at most m - 0's
    // at most n - 1's

    vector<int> zeroes;
    int dp[605][105][105];

    int f(int i, int m, int n, vector<string> &strs)
    {
        if (m == 0 and n == 0)
        {
            return 0;
        }
        if (m < 0 || n < 0 || i == strs.size())
        {
            return 0;
        }
        if (dp[i][m][n] != -1)
        {
            return dp[i][m][n];
        }

        int skip = f(i + 1, m, n, strs);
        int take = 0;
        int cntOne = strs[i].size() - zeroes[i];

        if (cntOne <= n and zeroes[i] <= m)
        {
            take = 1 + f(i + 1, m - zeroes[i], n - cntOne, strs);
        }

        return dp[i][m][n] = max(take, skip);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        for (int i = 0; i < strs.size(); i++)
        {
            int cnt = count(strs[i].begin(), strs[i].end(), '0');
            zeroes.push_back(cnt);
            // cout<<cnt<<" ";
        }
        memset(dp, -1, sizeof dp);

        return f(0, m, n, strs);
    }
};

int main(){
    

    return 0;
}