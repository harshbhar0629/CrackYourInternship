#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-cost-to-merge-stones/

class Solution
{
    vector<int> pre;
    int dp[35][35];
    int f(int s, int e, vector<int> &st, int k)
    {
        if (s >= e)
        {
            return 0;
        }
        if (dp[s][e] != -1)
        {
            return dp[s][e];
        }

        int ans = 1e9;
        for (int i = s; i < e; i += k - 1)
        {
            ans = min(ans, f(s, i, st, k) + f(i + 1, e, st, k));
        }

        // both are inclusive so total element is (j-i+1) but  if we take j-i then takes modulo (k-1)
        if ((e - s) % (k - 1) == 0)
        {
            ans += pre[e + 1] - pre[s];
        }

        return dp[s][e] = ans;
    }

public:
    // MCM pattern
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1))
        {
            return -1;
        }

        pre.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + stones[i];
        }

        memset(dp, -1, sizeof dp);
        return f(0, n - 1, stones, k);
    }
};

int main(){
    

    return 0;
}