#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution
{
    int dp[1005][1005];
    int ans = 0;
    int f(int i, int j, vector<int> &a, vector<int> &b)
    {
        if (i == a.size() || j == b.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // dealing with subarray not subsequence that's why we can't take skip case
        int opt1 = f(i + 1, j, a, b); // skip case
        int opt2 = f(i, j + 1, a, b); // skip case
        int opt3 = 0;

        if (a[i] == b[j])
        {
            opt3 = 1 + f(i + 1, j + 1, a, b);
        }
        ans = max(ans, opt3);
        return dp[i][j] = opt3;
    }

public:
    int findLength(vector<int> &a, vector<int> &b)
    {
        memset(dp, -1, sizeof dp);
        f(0, 0, a, b);
        return ans;
    }
};

int main(){
    

    return 0;
}