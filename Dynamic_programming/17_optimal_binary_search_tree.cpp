#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1

#define ll long long int
class Solution
{
    vector<ll> prefix;
    int dp[105][105];
    ll f(int i, int j, int k[], int fr[])
    {
        if (i > j)
        {
            return 0;
        }
        if (j == i)
        {
            return fr[i];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        ll cost = 1e9;
        ll reqCost = prefix[j + 1] - prefix[i];
        for (int m = i; m <= j; m++)
        {
            cost = min(cost, f(i, m - 1, k, fr) + f(m + 1, j, k, fr));
        }

        return dp[i][j] = cost + reqCost;
    }

public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + freq[i];
        }
        memset(dp, -1, sizeof dp);

        return f(0, n - 1, keys, freq);
    }
};

int main(){
    

    return 0;
}