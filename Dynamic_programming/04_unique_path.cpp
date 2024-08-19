#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-paths/

class Solution
{

    int dp[105][105];
    int f(int m, int n)
    {
        if (m == 1 and n == 1)
        {
            return 1;
        }
        if (m < 1 || n < 1)
        {
            return 0;
        }
        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }
        int down = f(m - 1, n);
        int right = f(m, n - 1);

        return dp[m][n] = down + right;
    }

public:
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof dp);
        return f(m, n);
    }
};

int main(){
    

    return 0;
}