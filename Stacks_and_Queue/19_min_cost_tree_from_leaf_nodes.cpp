#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution
{
    int mp[45][45];
    int dp[45][45];

    int f(int left, int right, const vector<int> &arr)
    {
        if (left == right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        int ans = 1e9;
        for (int i = left; i < right; i++)
        {
            ans = min(ans, mp[left][i] * mp[i + 1][right] + f(left, i, arr) + f(i + 1, right, arr));
        }

        return dp[left][right] = ans;
    }

public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        memset(mp, 0, sizeof mp);
        for (int i = 0; i < n; i++)
        {
            mp[i][i] = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                mp[i][j] = max(mp[i][j - 1], arr[j]);
            }
        }

        memset(dp, -1, sizeof dp);
        return f(0, n - 1, arr);
    }
};

int main(){
    

    return 0;
}