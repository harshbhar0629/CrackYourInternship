#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        vector<int> dp(n + 2, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main(){
    

    return 0;
}